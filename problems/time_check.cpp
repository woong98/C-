#include<ctime>
#include<iostream>

using namespace std;
int mat[10000001];
int main() {
    clock_t start, finish;
    double duration;
 
    start = clock();
    
    cin.tie(NULL); ios_base::sync_with_stdio(0);

    int n = 1;
    int left, right;
    for(int i = 2; i < 1000001; i++)
    {
       mat[i] = i;
    }
    for(int i = 2; i < 1000001; i++)
    {
        if(mat[i] == 0)
            continue;
        for(int j = i + i; j < 1000001; j += i)
            mat[j] = 0;
    }
    //에라토스테네스의 채를 통해서 홀수를 쭉 구한다. 
 
    finish = clock();
 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
 
    return 0;
}
