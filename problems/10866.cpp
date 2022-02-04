#include<iostream>
#include<string>

using namespace std;
//덱을 구현하는 문제. 시간제한이 적기 때문에, 배열 형태로 Deque를 구현해야 한다.
//일단 queue 구현한거처럼 ㄱㄱ 
//명령이 최대 10000개이므로, 양쪽으로 확장해야 하기 때문에 20000개 이상의 공간이 필요 
class deque
{
private:
    int arr[20002] = {0, };
    int front;
    int back;
public:
    deque() { front = 10001; back = 10001;}
    void push_front(int a){ front--; arr[front] = a;}
    int pop_front(){ 
        if(size() == 0)
            return -1;
        int temp; 
        temp = arr[front];
        arr[front] = 0;
        front++;
        return temp;
    }
    void push_back(int a){arr[back] = a; back++; }
    int pop_back(){
        if(size() == 0)
            return -1;
        int temp;
        back--;
        temp = arr[back];
        arr[back] = 0;
        return temp;
    }
    int size(){ return back - front;}
    int empty(){ 
        if(size() == 0) return 1; 
        return 0;
    }
    int get_front(){ 
            if(size() == 0)
                return -1;
            return arr[front];}
    int get_back(){ if(size() == 0)
                    return -1;
            return arr[back -1];
            }
};
int main()
{
    int n;
    cin >> n;
    deque Dq;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int temp;
        if(str == "push_front"){ 
            cin >> temp;
            Dq.push_front(temp);
         }
        else if(str == "push_back"){
            cin >> temp;
            Dq.push_back(temp);}
        else if(str == "pop_front"){cout << Dq.pop_front() << '\n';}
        else if(str == "pop_back"){cout << Dq.pop_back() << '\n';}
        else if(str == "size"){ cout << Dq.size() << '\n';}
        else if(str == "empty"){ cout << Dq.empty() << '\n';}
        else if(str == "front"){ cout << Dq.get_front() << '\n';}
        else if(str == "back"){ cout << Dq.get_back() << '\n';}
    }
    return 0;
}