#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int N, K;
    queue<int> Q; //큐를 사용
    scanf("%d %d", &N, &K);
    //입력을 여러번 받는게 아니므로 상대적으로 빠른 scanf를 사용한다
    
    for(int i = 0; i < N; i++)
        Q.push(i + 1); //큐에 N까지의 데이터를 삽입한다
    
    printf("<");
    while(Q.size() != 0)
    {
        for(int i = 1; i <= K; i++)
        {
            int temp = Q.front(); //큐의 맨 앞 요소를 저장
            Q.pop();
            if(i != K)
                Q.push(temp); //해당 숫자가 아닌 경우에는 꺼내서 바로 넣어버릴 수 있도록
            else
                printf("%d", temp);
        }
        if(Q.size() != 0)
            printf(", ");
    }
    printf(">\n");   
    
    return 0;
}