#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include<iostream>

using namespace std;

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

    void insert(T);  //插入元素

    T bst_min() const;  //返回最小元素
    T  bst_max() const; //返回最大元素

    T bst_find(const T itemt); //查找itemt元素并返回

    int bst_comparison_fun(const T ,const T); //元素对比

    bool bst_delete(const T item); //删除item元素

    void bst_clear();                    //销毁搜索树

    void print();                      //前序遍历

    int bst_size();                         //当前树元素的数量


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
