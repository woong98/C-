#include<iostream>
#include<string>
#include<stack>

using namespace std;
// 괄호 문자열. 
// (()))( 와 같은 형식이면, VPS인거임 
// 규칙 : 먼저 나온 ( 의 갯수만큼 )가 존재해야한다.
// 1. 들어가있는 "("의 수는 항상 ")"보다 많거나 같아야 한다. 
// 2. 최종적으로 "("와 ")"의 수는 항상 같아야한다. 
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++)
    {
       string str;
       getline(cin, str);
       int lcount = 0; int rcount = 0; int count = 0;
       bool is_true = 0;
       while(1)
       {
           if(str[count] == '(')
                lcount++;
           else if(str[count] == ')')
                rcount++;
           //일단 이것을 비교를 먼저 해주고
           if(rcount > lcount)
                break;
           count++;
           if(count == str.size() + 1)
           {
                if(rcount == lcount)
                    is_true = 1;
                break;
           }
       }
       is_true == 1 ? (cout << "YES" << '\n') : (cout << "NO" << '\n');
    }
   
    return 0;
}
//맞았는데 다른 풀이들을 봐야할듯 