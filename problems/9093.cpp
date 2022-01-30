//문장이 주어지고, 주어진 단어를 뒤집어서 출력해야함
#include<iostream>
#include<string>
#include<stack>
#include<cstring>
//스택을 이용하면 수월하지

using namespace std;

int main()
{
    stack<char> stk;
    int n;
    cin >> n; //정수를 입력받고
    cin.ignore(); //앞에 cin으로 인해서 버퍼에 \n이 남아있기 때문에, 이것을 제거한다. getline은 이런 작업이 스스로 불가능하므로 해줘야함 
    for (int i = 0; i < n; i++)
    {
        string str;

        getline(cin, str);

        string temp = ""; //임시로 초기화를 시킨다. 

        int find_idx = 0;
        int loopon = 0;
        int flag = 0;
        loopon = str.find(' ', find_idx);
        if (loopon < 0 && flag == 0)
        {
            flag = 1;
            loopon = str.size();
        }
        while (loopon >= 0) //찾는 경우에 대해서 루프에 들어감 
        {
            for (int j = find_idx; j < loopon; j++)
                stk.push(str[j]);
            //stack.pop를 통해서 리턴되는 값을 넣어주려 했는데, pop는 아무것도 리턴하지 않음. stack.top를 써야한다. 
            for (int j = find_idx; j < loopon; j++)
            {
                temp += stk.top();
                stk.pop();
            }
            temp += ' '; //문자열에 공백을 추가 
            find_idx = loopon + 1;
            loopon = str.find(' ', find_idx);
            if (loopon < 0 && flag == 0)
            {
                flag = 1;
                loopon = str.size();
            }
        }
        if (i != n - 1)
            cout << temp << '\n';
        else
            cout << temp;
    }

    return 0;
}

//한 단어 형태로 주어지는 경우에 대한 처리가 안되있어서, 이 부분에서 계속 틀렸다고 나온거였음