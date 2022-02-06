#include<iostream>
//!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
//처음에는 무식하게 할라고 했는데, 생각해보니 이거는 들어가는 5와 2의 갯수를 세서 하면 되잖아 
using namespace std;

int main()
{
    int N;
    cin >> N;
    int num2 = 0; 
    int num5 = 0;
    for(int i = 0; i < N + 1; i++)
    {
        if(i == 0)
            continue;
        int temp = i;
        while(temp % 2 == 0)
        {
            temp = temp / 2;
            num2++;
        }
        while(temp % 5 == 0)
        {
            temp = temp / 5;
            num5++;
        }
        
    }
    num2 >= num5 ? (cout << num5) : (cout << num2);
    return 0;
}