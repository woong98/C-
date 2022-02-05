#include<iostream>
#include<cstdio>

using namespace std;
/*
각 인덱스에 대해서, 그 인덱스에 해당하는 수 보다 큰 수를 최대한 가까히에서 찾아야함
끝까지 갔는데 없는 경우에는 0을 넣어줘야 한다. 
이 문제의 경우에는 시간을 단축시키는게 필요하다. 추가적인 조건을 사용해야한다.
- 예를들어, 8 2 4 6 9 
*/
int main()
{
    int N;
    scanf("%d", &N);
    int max = -1; 
    int *arrN = new int[N]; //N개의 요소를 가지는 배열을 동적으로 생성한다.
    int i; int j; int temp; 
    for(i = 0; i < N; i++)
        scanf("%d", &arrN[i]);
    for(i = 0; i < N; i++) //이중으로 for문을 사용한다 
    {
        if(i == N - 1)
        {
            printf("-1 ");
            break;
        }
        //두 가지 케이스로 분리할 수 있다. 
        // case1 옆에있는게 자기보다 큰 경우 - 이 경우 바로 옆에꺼가 정답 
        if(arrN[i] < arrN[i + 1])
            printf("%d ", arrN[i + 1]);
        else //case2 그 외의 경우 - for문 진입해서 찾아야지뭐 
        {
            temp = arrN[i];
            for(j = i + 2; j < N; j++)
            {
                if(temp < arrN[j])
                {
                    printf("%d ", arrN[j]);
                    goto EXIT;
                }
            }
            printf("-1 ");
        }
        EXIT:;

    }
    return 0;
}