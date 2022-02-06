#include<iostream>

using namespace std;
//4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
/*
n이 주어지는 경우, (n/2보다 작은 홀수) + (n/2보다 큰 홀수) 로 이루어진다. => n보다 작은 홀수 중 만족하는거만 고르면댐
여기서 left와 right가 모두 소수를 만족해야 한다. 
1. 1000000보다 작은 홀수 소수를 모두 배열에 담는다. 
2. 배열에서 가장 작은 수부터 담고, 
 
*/
int mat[1000001];

int main()
{
    
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

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while(n != 0)
    {
        cin >> n;
        if(n == 0)
            break;
        int flag = 0; 
        //1. left 탐색 및 그를 바탕으로 right 탐색 
        for(left = 3; left <= n/2; left += 2)
        {
            if(mat[left] != 0)
            {
                right = n - left;
                if(mat[right] != 0)
                {
                    cout << n << " = " << left << " + " << right << '\n';
                    flag = 1;
                    break;
                }
            }
        }   
        //2. 이 경우는 못찾은거임 
        if(flag == 0)
            cout << "Goldbach's conjecture is wrong.\n"; 
    }
    return 0;
}