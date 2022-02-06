#include<ctime>
#include<iostream>

using namespace std;
int mat[10000001];
int main() {
    clock_t start, finish;
    double duration;
 
    start = clock();
    
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

    for(int i = M; i < N; i++)
    {
        if(i == 1 || i == 0)
            continue;
        if(mat[i] != 0)
            printf("%d\n", mat[i]);
    }

 
    finish = clock();
 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
 
    return 0;
}
