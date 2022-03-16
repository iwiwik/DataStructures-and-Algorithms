#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include<iostream>

using namespace std;


typedef int bst_comparison(const void *bst_a ,const void *bst_b);

template<typename T>
struct bst_node{
    T value;
    bst_node *bst_link[2];
    bst_node(){
        bst_link[0] = nullptr;
        bst_link[1] = nullptr;
    }
};

template<typename T> 
class bst{

public:
    bst();

    ~bst();

    void insert(T);

    T bst_min() const;  //返回最小data
    T  bst_max() const; //返回最大data

    T bst_find(const T itemt); //查找itemt,成功返回值，失败返回nullptr

    int bst_comparison_fun(const T ,const T); //对比data函数

    bool bst_delete(const T item); //删除item,成功true,失败false

    void bst_clear();                    //销毁搜索树

    void print();                      //前序遍历

    int bst_size();                         //data的数量


private:
    int count;
    bst_node<T> *tree;

    void clear(bst_node<T> *);  //递归销毁

    bst_node<T>* minmum(bst_node<T>* ); //返回最小节点

    bst_node<T>* maxmum(bst_node<T>*); //返回最大节点

    bst_node<T>* remove_node(bst_node<T>* ,T item); //删除item data

    void print(bst_node<T> *root); //前序遍历


};






#endif