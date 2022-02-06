#include<cstdio>


using namespace std;
//기억상으로 소수의 경우에는 그 수의 제곱근까지 검사하면 된다. 
//첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
//일단 이 경우는 시간복잡도가 N*N^(1/2)인데도 잘 안되네. 
/* 
1. 소수인 경우는 스택에 넣고, 스택에 존재하지 않는 경우에는 안넣는 방법 => 사실 스택을 순회해야 하니까 별 다를게 없어보임
2. 아예 다른 방법으로 고안하는거. 시간복잡도가 작은 방법으로 => 에라토스테네스의 체 

*/

int mat[1000001];

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    for(int i = 2; i < N + 1; i++)
    {
       mat[i] = i;
    }
    for(int i = 2; i < N + 1; i++)
    {
        if(mat[i] == 0)
            continue;
        for(int j = i + i; j < N + 1; j += i)
            mat[j] = 0;
    }

    for(int i = M; i < N + 1; i++)
    {
        if(i == 1)
            continue;
        if(mat[i] != 0)
            printf("%d\n", mat[i]);
    }

    return 0;
}