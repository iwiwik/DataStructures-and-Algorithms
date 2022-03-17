#ifndef ARRAY_STACK
#define ARRAY_STACK
#include<iostream>

using namespace std;

size_t array_size = 10;  //数组的空间大小

template<typename T>
class array_stack{

public:

    array_stack();

    ~array_stack();

    void push(T item);  //入栈

    void pop();      //删除栈顶

    bool empty();   //判断是否为空

    T top();        //返回栈顶元素


private:
    T *array;  //存储元素数组
    int t;     //指向栈顶
    int count; //栈的当前大小



};







#endif