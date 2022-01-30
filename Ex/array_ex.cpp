#include<string>
#include<algorithm>
#include<iostream>

//std::array의 기능 원리! 

template <typename T> //타입에 따른 클래스를 만들어주는 템플릿 
class dynamic_array
{
    T* data; //T형 포인터를 가지는 data
    size_t n; //size_t형 n을 멤버로 
public:
    dynamic_array(int n) //T의 타입 배열을 인수 n만큼의 크기로 생성하는 "생성자"
    {
        this->n = n;
        data = new T[n];
    }

    dynamic_array(const dynmaic_array<T>& other) //복사생성자. 깊은 복사를 해야할 필요가 있음.
    {
        //other의 사이즈를 알아서 그것을 바탕으로 새로 메모리 할당(이 경우에는 같은 클래스기때문에 접근이 가능한건가)
        n = other.n;
        data = new T[n];
        for(int i = 0; i < n; i++)
            data[i] = other[i];
    }

    T& operator[](int index) //이 경우는 왜 레퍼런스를 리턴해주는거지? 
    { //레퍼런스를 리턴하는게 아니라, return 뒤에 오는 값의 주소를 참고해서 그 안에 있는 것을 리턴하겠다는것! 
        return data[index];
    }

    //구조체 변수 자체를 리턴하면 그 값을 모두 복사하느라 오랜 시간이 걸리지만,
    //레퍼런스로 리턴하면 빠르게 전달을 끝낼 수 있다. 

    const T& operator[](int index) const //상수 함수의 형태. 이 경우에는 함수가 읽기만하고 변경 X인 경우에 대해서
    {
        return data[index];
    }

    T& at(int index)
    {
        if(index < n)
            return data[index];
        throw "index out of range";
    }

    size_t size() 
    {
        return n; //사이즈를 리턴 
    }

    ~dynamic_array()
    {
        delete [] data; //배열 데이터를 삭제 
    }

    T* begin() { return data;}
    const T* begin() const {return data;}
    T* end() {return data + n;}
    const T* end() const { return data + n;}
};