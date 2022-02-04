#include<iostream>
#include<stack>
#include<queue>
#include<string>

#define STACK 0
#define QUEUE 1

using namespace std;
/*
<>로 구성되는 태그의 경우에는 그냥 출력하는 방법을 사용한다.
나머지 단어(스페이스로 구별된다)는 순서를 바꾸어 출력한다. 
담고서 한 번에 출력하는 방법은 별로임. 스택이랑 큐를 선언을 한 이후에 이것을 각각 push및 pop하는 구조로 가자 
*/
void printQueue();

int main()
{
    stack<char> S;
    queue<char> Q;

    int mode = STACK; //mode를 사용한다(0의 경우 기본모드 )

    string ip;
    getline(cin, ip); //엔터가 눌릴때까지 입력을 받는다.
    for(int i = 0; i < ip.size() + 1; i++)
    {
        if(ip[i] == '<'){ //queue를 사용한다
            if(S.empty() == 0)
            {
                while(S.empty() == 0)
                {
                    cout << S.top();
                    S.pop();
                }
            }
            mode = QUEUE;
            Q.push('<');
            continue;
        }
        else if(ip[i] == '>'){ //queue사용을 종료한다 
            mode = STACK;
            Q.push('>');
            while(Q.empty() == 0) //큐가 빌때까지 출력할거니까 
            {
                cout << Q.front();
                Q.pop();
            }
            continue;
        }
        if(mode == QUEUE)
            Q.push(ip[i]);
        else if(mode == STACK)
        {
            if(ip[i] == ' ' || ip[i] == '\0') //공백이 나오면 공백 추가해서 지금까지꺼를 비워야함 
            {
                while(S.empty() == 0)
                {
                    cout << S.top();
                    S.pop();
                }
                cout << ' ';
            }
            else
                S.push(ip[i]);
        }

    }

    return 0;
}