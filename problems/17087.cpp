#include<iostream>

using namespace std;
/*
첫째 줄에 N(1 ≤ N ≤ 105)과 S(1 ≤ S ≤ 109)가 주어진다. 둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다. 동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.
1. 기본적으로 ull을 사용
*/

typedef unsigned long long ull;

ull GCD(ull a, ull b)
{
    if(b > a)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp; 
    }
    return a; 
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    ull N; ull S; //동생의 수와 본인의 위치를 입력받아야함
    cin >> N >> S;
    ull *mat = new ull[N]; //동생의 수 만큼 배열 할당
    ull temp; 
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        if(temp > S)
            mat[i] = temp - S;
        else
            mat[i] = S - temp;
    }
    //동생들을 찾기 위해서 최대공약수를 찾아야한다. 
    ull D; 
    D = mat[0];
    for(int i = 1; i < N; i++)
    {
            D = GCD(mat[i], D);
    }
    cout << D; 


    return 0;
}