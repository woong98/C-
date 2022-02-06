#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int fact = 1;
    for(int i = 0; i < N + 1; i++)
    {
        if(i == 0)
            continue;
        fact *= i; 
    }
    cout << fact;


    return 0;
}