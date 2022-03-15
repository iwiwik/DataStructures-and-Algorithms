
#include<vector>
#include <cassert>

#include "Binarysearchtree.h"

template<typename T>
bst<T>::bst(){
    tree = nullptr;
    count = 0;
}

template<typename T>
bst<T>::~bst(){
    clear();
}

template<typename T>
int bst<T>::bst_comparison_fun(const T bst_a,const T bst_b){

    if(bst_a < bst_b){
        return -1;
    }else if(bst_a > bst_b){
        return 1;
    }else{
        return 0;
    }
}

template<typename T>
T bst<T>::bst_find(T item){

    bst_node<T> *p;

    for( p = tree;p != nullptr;){
        int cmp = bst_comparison_fun(item,p->value);

        if(cmp > 0){
            p = p->bst_link[1];
        }else if(cmp < 0){
            p = p->bst_link[0];
        }else{
            return p->value;
        }
    }
    return 0;
}

template<typename T>
bst_node<T>* bst<T>::minmum(bst_node<T> *x){

    bst_node<T> *node = x;
    while(node->bst_link[0] != nullptr){
        node = node->bst_link[0];
    }
    return node;

}
template<typename T>
bst_node<T>* bst<T>::maxmum(bst_node<T> *x){
    bst_node<T> *node = x;
    while( node->bst_link[1] != nullptr){
        node = node->bst_link[1];
    }
    return node;
}

template<typename T>
T bst<T>::max() const{
    bst_node<T> *node =  maxmum(tree);
    return node->value;
}

template<typename T>
T bst<T>::min()const{
    bst_node<T> *node = minmum(tree);
    return node->value;
}


template<typename T>
void bst<T>::insert(T item){


    bst_node<T> *p,*q;
    int dir;
    bst_node<T> *n;
    
    for(q = nullptr,p = tree;p != nullptr;q = p,p = p->bst_link[dir]){
         
         int cmp = bst_comparison_fun(item,p->value);
         if(cmp == 0){
             return;
         }
         dir = cmp > 0;
    }
    n = new bst_node<T>;

    count++;
    n->value = item;
    if(q != nullptr){
        q->bst_link[dir] = n;
    }else{
        tree = n;
    }    
    return;

}

template<typename T>
bool bst<T>::bst_delete(const T item){


    if(remove_node(tree,item)){
        count--;
        return true;
    }else{
        return false;
    }

}

template<typename T>
bst_node<T>* bst<T>::remove_node(bst_node<T> *root,T item){
    if(root == nullptr){
        return nullptr;
    }

    if(root->value < item){
        root->bst_link[1] = remove_node(root->bst_link[1],item);
    }else if(root->value > item){
        root->bst_link[0] = remove_node(root->bst_link[0],item);
    }else{
        if(root->bst_link[0] == nullptr && root->bst_link[1] == nullptr){
            delete root;
            return nullptr;
        }else if(root->bst_link[0] == nullptr){
            bst_node<T> *temp = root->bst_link[1];
            delete root;
            return temp;
        }else if(root->bst_link[1] == nullptr){
            bst_node<T> *temp = root->bst_link[0];
            delete root;
            return temp;

        }else{
            bst_node<T>* rightmin = minmum(root->bst_link[1]);
            root->value = rightmin->value;
            root->bst_link[1] = remove_node(root->bst_link[1],rightmin->value);
        }
       

    }
     return root;

}

template<typename T>
void bst<T>::clear(bst_node<T> *ptr){

    if(ptr != nullptr){
        clear(ptr->bst_link[0]);
        clear(ptr->bst_link[1]);
        delete ptr;
    }

}

template<typename T>
void bst<T>::clear(){
    clear(tree);
    tree = nullptr;
    count = 0;

}

template<typename T>
void bst<T>::print(bst_node<T> *root){
    if(root != nullptr){
        cout << root->value << " ";
        print(root->bst_link[0]);
        print(root->bst_link[1]);
    }
    
}

template<typename T>
void bst<T>::print(){
    print(tree);
}

template<typename T>
int bst<T>::size(){
    return count;
}

int main(){

    bst<int> s1;
    vector<int> per{15,6,3,2,4,7,13,18,17,20};

    for(int i = 0;i < per.size();i++){
        s1.insert(per[i]);
    }
    s1.bst_delete(per[0]);
    s1.bst_delete(per[2]);
     cout << "size:" <<s1.size() << endl;; 

     s1.bst_delete(per[7]);
     cout << "size:" <<s1.size() << endl; 
     cout <<"find:" << s1.bst_find(20) << endl;

    cout << "前序遍历" << endl;
    s1.print();
    s1.clear();
    cout << "size:" <<s1.size() << endl; 

}


