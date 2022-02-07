#include<iostream>
#include<string>

using namespace std;

int main()
{
    string S;
    cin >> S;
    if(S.size() == 1 && S[0] == '0')
    {
        cout << '0';
        return 0;
    }
    for(int i = 0; i < S.size(); i++)
    {
        if(i == 0)
        {
            if(S[i] == '0') ;
            else if(S[i] == '1') cout << "1";
            else if(S[i] == '2') cout << "10";
            else if(S[i] == '3') cout << "11";
            else if(S[i] == '4') cout << "100";
            else if(S[i] == '5') cout << "101";
            else if(S[i] == '6') cout << "110";
            else if(S[i] == '7') cout << "111";
        }
        else
        {
            if(S[i] == '0') cout << "000";
            else if(S[i] == '1') cout << "001";
            else if(S[i] == '2') cout << "010";
            else if(S[i] == '3') cout << "011";
            else if(S[i] == '4') cout << "100";
            else if(S[i] == '5') cout << "101";
            else if(S[i] == '6') cout << "110";
            else if(S[i] == '7') cout << "111";
        }
    }
}