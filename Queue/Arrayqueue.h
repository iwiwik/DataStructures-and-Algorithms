#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
#include<iostream>
using namespace std;

size_t array_size = 100;

template<typename T>
class array_queue{
public:
    array_queue();

    ~array_queue();

    void push(T item);  //入队

    T pop();          //删除最前面并返回其元素

    T peek();      //返回队列最前面的元素

    bool empty();     //检查是否为空

    int size() const;      //检查队列大小

    bool full();    //检查队列是否已满

private:
    T *array;  //存储元素数组
    int front; //指向最前元素
    int rend; //指向最后元素
    size_t capacity; //最大容量
    int count; //队列当前大小

};






#endif