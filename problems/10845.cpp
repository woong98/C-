#include<iostream>
#include<string>

using namespace std;

/*
C++ 기반으로 queue를 구현하는 방법. stack의 경우에는 현재것만 알려주면 되지만, queue의 경우에는.. 
일단 배열로 선언하면 40KB를 기본적으로 먹고 가야하는 단점이 존재한다. 
*/

class queue
{
private : 
    int arr[10000] = {0, };
    int fpoint = -1;
    int bpoint = -1;
public :
    void queue_push(int a);
    void queue_pop();
    void queue_empty() {(bpoint == fpoint) ?(cout << 1 << '\n') : (cout << 0 << '\n'); }
    void queue_size() { cout << bpoint - fpoint << '\n';}
    void queue_front() {(bpoint != fpoint) ? (cout << arr[fpoint + 1] << '\n') : (cout << -1 << '\n');}
    void queue_back() {(bpoint != fpoint) ? (cout << arr[bpoint] << '\n') : (cout << -1 << '\n');}
};

void queue::queue_push(int a)
{
    bpoint++;
    arr[bpoint] = a;
}

void queue::queue_pop()
{
    if(bpoint == fpoint)
    {
        cout << -1 << '\n';
        return;
    }
    fpoint++;
    cout << arr[fpoint] << '\n';
    arr[fpoint] = 0;
    return; 
}

int main()
{
    int n;
    queue Q; 
    cin >> n;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(str == "push")
        {
            int temp;
            cin >> temp;
            Q.queue_push(temp);   
        }
        else if(str == "pop")
            Q.queue_pop();
        else if(str == "empty")
            Q.queue_empty();
        else if(str == "front")
            Q.queue_front();
        else if(str == "back")
            Q.queue_back();
        else if(str == "size")
            Q.queue_size();
    }
    
    return 0; 
}