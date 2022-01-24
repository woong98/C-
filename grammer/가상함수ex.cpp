#include<stdio.h>

class A 
{
    private:
        int x;
    public:
        A(int a) { x = a;}
        void printx() {printf("%d\n", x);}
};

class B : public A
{
    private:
        int y;
    public:
        B(int b, int a) : A(a){ y = b;}
        void printy() {printf("%d\n", y);}
};

using namespace std;

int main()
{
    A a(3); //이러면 x를 3으로 초기화
    B b(5, 4);//y는 5, x는 4로 초기화 
    A *pa;
    B *pb;
    pa = &a; 
    pa->printx();
    pb = &b;
    pb->printy();
    pa = &b;
    pa->printx(); //예측 3 5 4 맞음
    //pa->printy()의 경우는 불가능하다!
    return 0;
}