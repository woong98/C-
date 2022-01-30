#include<array>
#include<iostream>
#include<type_traits> //타입 유형 관련되어서 확인을 진행하는 코드를 포함한 라이브러리 

template<typename ... Args> //typename 뒤에 ... 으로 오는 것은 템플릿 parameter pack


// auto 키워드는 선언된 변수의 초기화 식을 사용하여 해당 형식을 추론하도록 컴파일러에 지시
// auto의 경우에는 C++ 14버전에서는 리턴타입을 추론 가능.