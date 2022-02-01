#include<iostream>
#include<string>

using namespace std;
//한 줄로 된 에디터를 구현 
//커서는 기본적으로 맨 뒤에 문장의 맨 뒤에 존재
//원래는 링크드 리스트를 이용해서 해야하는건가? 문제의 의도는? 
int main()
{
    string str;
    cin >> str;
    int pos = str.size(); //커서의 위치를 나타내는 변수 
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        string temp;
        string temp_ch;
        cin >> temp;

        if(temp == "P")
        {
            cin >> temp_ch;
            str.insert(pos, temp_ch);
            pos++;
        }
        else if(temp == "L")
        {
            if(pos != 0)
                pos--;
        }
        else if(temp == "B")
        {   
            if(pos == 0)
                continue;
            str.erase(pos-1, pos); //일부 문자를 지운다. 
            pos--;
        }
        else if(temp == "D")
        {
            if(pos != str.size())
                pos++;
        }
    }
    cout << str << '\n';

    return 0;

}