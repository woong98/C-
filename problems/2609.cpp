#include<iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int temp1 = a;
    int temp2 = b;
    if(temp2 > temp1)
    {
        int temp = temp2;
        temp2 = temp1;
        temp1 = temp;
    }
    while(temp2 != 0)
    {
        int temp = temp2;
        temp2 = temp1 % temp2 ;
        temp1 = temp; 
    } //이거 쭉 나가면 temp2가 

    cout << temp1 << '\n';
    cout << a * b / temp1 << '\n';
    return 0;
}