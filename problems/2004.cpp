#include<iostream>

using namespace std;
// 조합에서 끝자리 0의 갯수를 출력하는 프로그램 
// (분자에서 10의 갯수) / (분모에서 10의 갯수)
// 시간 초과로 틀렸는데, 이를 위해서 조금 더 2와 5의 갯수를 간단하게 구할 수 있는 알고리즘을 구글링해보았다.
// 결과적으로 원하는 수 k가 몇 개 존재하는지는 예시로 다음과 같다
// 25/2 = 12 
// 25/4 = 6
// 위와 같은 식으로 하다보면 총 2의 갯수를 구할 수 있다. 

int main()
{
    unsigned long long N, M;
    cin >> N >> M;
 
    unsigned long long num2 = 0;
    unsigned long long num5 = 0;
    
    //2의 지수가 최대 어디까지 존재할 수 있는가 
    for (unsigned long long i = 2; i <= N; i *= 2) {
        num2 += N / i;
    }
    for (unsigned long long i = 2; i <= (N - M); i *= 2) {
        num2 -= (N - M) / i;
    }
 
    for (unsigned long long i = 2; i <= M; i *= 2) {
        num2 -= M / i;
    }
 
    
    for (unsigned long long i = 5; i <= N; i *= 5) {
        num5 += N / i;
    }
    for (unsigned long long i = 5; i <= (N - M); i *= 5) {
        num5 -= (N - M) / i;
    }
    for (unsigned long long i = 5; i <= M; i *= 5) {
        num5 -= M / i;
    }
 
    num2 >= num5 ? (cout << num5) : (cout << num2);
    return 0;
}