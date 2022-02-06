#include<iostream>


using namespace std;
//기억상으로 소수의 경우에는 그 수의 제곱근까지 검사하면 된다. 
//첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다
int main()
{
    int N;
    cin >> N;
    int sum = 0; 
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        int flag = 1; 
        if(a == 1) flag = 0;
        for(int j = 2; j * j <= a; j++)
        {
            if(a % j == 0)
            {
                flag = 0;
                break;
            }
        } 
        sum += flag; 
    }
    cout << sum;

    return 0;
}