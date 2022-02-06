#include<cstdio>

using namespace std;
unsigned long long mat[101];

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if(b > a)
    {
        unsigned long long temp = a;
        a = b;
        b = temp;
    }
    while(b != 0)
    {
        unsigned long long temp = b;
        b = a % temp;
        a = temp;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int c;
        unsigned long long sum = 0; 
        scanf("%d", &c);
        unsigned long long mat_size = (unsigned long long)c;
        for(int j = 0; j < c; j++)
        {
            int temp;
            scanf("%d", &temp);
            if(mat_size == 1)
            {
                sum += (unsigned long long)temp;
                break;
            }
            mat[j] = (unsigned long long)temp;
            for(int k = 0; k < j; k++)
            {
                sum += gcd(mat[k], mat[j]);
            } 
        } //이러면 배열 내에 요소들이 채워지고, 이 요소들을 바탕으로 GCD를 계산한다.
        printf("%llu\n", sum);
    }
    return 0;
}