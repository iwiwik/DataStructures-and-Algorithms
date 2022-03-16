#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
#include<iostream>

using namespace std;


template<typename T> 
class list_node{
public:
    list_node():next(nullptr){}
    list_node(T x):value(x),next(nullptr){}

    T value;
    list_node<T>* next;


};

template<typename T>
class singly_linked_list{

public:
    singly_linked_list();

    ~singly_linked_list();

    void add_first(T item);     //头插入

    void add_last(T item);      //尾插入

    void delete_node(T item);  //删除指定数据

    void delete_all();   //销毁

    int search(T item); //搜索,存在返回1，不存在返回-1；

    int size() const;  //链表的大小

    void print();   //遍历

    






private:
    list_node<T>* head;

    int count;

    bool add_first(list_node<T> *);

    bool add_last(list_node<T> *);


};






#endif