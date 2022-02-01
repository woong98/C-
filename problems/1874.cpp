#include<iostream>
#include<string>
#include<stack>

using namespace std;
//수열을 준다면, 그 수열이 스택을 통해서 만들 수 있는 수열인지 판단 
//다음 수가 크다 => push가 필요
//다음 수가 작다 => pop이 필요 
int main()
{
    bool flg = 0; 
    stack<int> stk;
    int n;
    cin >> n;
    int temp = 1;
    string str = "";
    for(int i = 0; i < n; i++)
    {
        int x;  //temp의 경우에는 현재까지 push한 수를 기억할 수 있도록 한다. 
        cin >> x; //수열의 각 자리에 해당되는 입력을 받는다.
        if(x >= temp) //다음 수가 큰 경우. push 이후 pop이 필요하다.  
        {
            for(int i = temp; i < x + 1; i++)
            {
                stk.push(i);
                str += "+\n";
            }
            temp = x + 1;
            stk.pop(); 
            str += "-\n";
        }
        else //temp보다 작은 수는 반드시 pop을 통해서만 얻을 수 있다. 
        {
            if(x == stk.top())
            {
                stk.pop(); 
                str += "-\n";
            }
            else
                flg = 1;
        }  
    }
    if(flg == 1)
    {
        cout << "NO" << '\n';
        return 0;
    }
    cout << str; 
    return 0;
}

//이거도 다른 답안을 참고해보자 