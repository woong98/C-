#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;


int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    //이 경우는 그냥 3단위로 분할해서 넣어버리면
    string str2; 
    stack<char> S;
    stack<int> IS; 
    cin >> str2;
    for(int i = 0; i < str2.size(); i++)
    {
        S.push(str2[i]);
    }
    int temp = 1; 
    int sum = 0; 
    
    for(int i = 0; i < str2.size(); i++)
    {
        if(S.top() == '1')
            sum += temp;
        temp *= 2;
        if(i % 3 == 2)
        {
            temp = 1;
            IS.push(sum);
            sum = 0;
        }
        S.pop();
    }
    //중간에 나오는 경우도 처리를 해줘야한다. 
    if(sum != 0)
        IS.push(sum);
    int loopnum = IS.size();
    for(int i = 0; i < loopnum; i++)
    {
        cout << IS.top();
        IS.pop();
    }
    return 0;
}
