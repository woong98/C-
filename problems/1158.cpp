#include<iostream>
#include<queue>

using namespace std;
//원을 이루는 상황에서 하나씩 제거하고, 순서를 위해서 하나의 전역변수 사용
//아직 list 컨테이너 사용이 미숙해서, 구현하는 방향으로 사용. 또한 원형 리스트를 사용해서 처음과 끝이 만날 수 있도록
//원형을 이루게 된다면, n2만큼을 계속해서 전진하면서 이동이 가능하다.

class circular_list{
private:
    struct node* head;  
public:
    int size; 
    circular_list()
    {
        head->a = 0;
        head->point = NULL; //자기 자신을 가리킬 수 있도록 한다.
        size = 0; 
    }
    node * get_head(){ return head;}
    void add_node(int a);
    int delete_node(node* temp); 
    void set_circle(); 
};

void circular_list::add_node(int a)
{
    //어짜피 한 방향으로만 돌거니까 단방향 노드를 사용하는거지
    struct node* temp = new node;
    temp->a = a;
    temp->point = head->point; //원래 head가 가리키고 있는 위치를 가리키고 
    head->point = temp; //head는 이 새로운 노드를 가리키도록 한다. 
    size++;
}

int circular_list::delete_node(node* current) //current의 다음 노드를 삭제하는 함수
{
    int tn;
    struct node* temp = current->point;
    current->point = temp->point;
    temp->point = NULL;
    tn = temp->a;
    temp->a = 0;
    size--;
    delete temp;
    return tn; 
}

void circular_list::set_circle()
{
    struct node* temp = head;
    while(temp->point == NULL)
        temp = temp->point; //이 코드 종료시에 temp는 마지막 요소에 도달한다
    temp->point = head->point; //마지막 요소가 첫 요소를 가리킬 수 있도록 한다. 
}

struct node
{
    int a;
    struct node* point;
};

int main()
{
    circular_list cl;
    int n1, n2;
    cin >> n1;
    cin >> n2; //n1과 n2를 입력받을 수 있다.

    int turn = 0; 
    for(int i = n1; i > 0; i--)
        cl.add_node(i); //노드를 추가시키는 동작 
    cl.set_circle(); //원형 리스트를 완성시키고 
    
    struct node* cycle = new node; //순회를 위해서 노드를 선언
    cycle->a = 0;
    cycle->point = cl.get_head(); //cycle의 point가 head를 가리키게 된다. 
    cout << '<';
    while(cl.size != 0)
    {
        for(int i = 0; i < n2; i++)
        {
            cycle = cycle->point;
        }
        cout << cl.delete_node(cycle);
    }
    cout << '>';
    
    return 0; 
}