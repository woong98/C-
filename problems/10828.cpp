#include<iostream>
#include<stack> //STL의 stack 컨테이너를 사용가능하도록 
#include<string>

using namespace std;

int main()
{
    int a;
    cin >> a; //a에 input을 받는다
    //이 경우 a는 int형이므로, int형만 받을 수 있도록 한다.
    stack<int> stk; //stack형 stk
    string str; //string형 str

    for(int i = 0; i < a; i++)
    {   //c에서는 사용하지 않는 문자열의 직접적인 비교 또한 C++에서는 가능하다 
        cin >> str;
        if(str == "push")
        {
            int n;
            cin >> n; //cin의 경우에는 공백이 입력의 끝임. 
            stk.push(n);
        }
        else if(str == "pop")
        {
            if(stk.empty())
            {
                cout << "-1" << endl;
                continue;
            }
            cout << stk.top() << endl;
            stk.pop();
        }
        else if(str == "size")
        {
            cout << stk.size() << endl;
        }
        else if(str == "top")
        {
            if(stk.empty())
            {
                cout << "-1" << endl;
                continue;
            }
            cout << stk.top() << endl;
        }
        else if(str == "empty")
        {
            if(stk.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
    return 0;
}