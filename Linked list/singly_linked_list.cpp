
#include"singly_linked_list.h"

template<typename T>
singly_linked_list<T>::singly_linked_list():count(0),head(nullptr){}

template<typename T>
singly_linked_list<T>::~singly_linked_list(){
    delete_all();
}


template<typename T>
bool singly_linked_list<T>::add_first(list_node<T> * new_node){
    if(new_node == nullptr){
        return false;
    }

    if(head == nullptr){
        new_node->next = nullptr;
        head = new_node;
    }else{
        new_node->next = head;
        head = new_node;
    }
    return true;

}

template<typename T>
bool singly_linked_list<T>::add_last(list_node<T>* new_node){
    if(new_node == nullptr){
        return false;
    }

    if(head == nullptr){
        head = new_node;
    }else{
        list_node<T> *ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return true;

}

template<typename T>
void singly_linked_list<T>::add_first(T item){

    list_node<T> *ptr = new list_node<T>(item);
    if(add_first(ptr)){
        count++;
    }else{
        return;
    }
}

template<typename T>
void singly_linked_list<T>::add_last(T item){

    list_node<T> *ptr = new list_node<T>(item);
    if(add_last(ptr)){
        count++;
    }else{
        return;
    }

}

template<typename T>
void singly_linked_list<T>::delete_node(T item){

    list_node<T> *temp;

    if(head->value == item){
        temp = head;
        head = head->next;
        delete temp;
        count--;
    }else{
        list_node<T> *ptr = head;
        while(ptr->next != nullptr){
            if(ptr->next->value == item){
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
                count--;
                break;
            }else{
                ptr = ptr->next;
            }

        }
    }
}

template<typename T>
void singly_linked_list<T>::delete_all(){

    list_node<T> *temp;
    while(head){
        temp = head;
        head = head->next;
        count--;
        delete temp;
    }
}

template<typename T>
int singly_linked_list<T>::search(T item){
    list_node<T> *temp = head;

    while(temp != nullptr){
        if(temp->value == item){
            return 1;
        }
        temp = temp->next;
    }
    return -1;

}

template<typename T>
int singly_linked_list<T>::size() const{
    return count;

}


template<typename T>
void singly_linked_list<T>::print(){
    list_node<T> *current = head;
    while(current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }
}

int main(){
    singly_linked_list<int> s1;

    for(int i = 0;i < 5;i++){
        s1.add_first(i);
    }
    for(int i = 5;i < 10;i++){
        s1.add_last(i);
    }
    if(s1.search(0) == 1){
        cout << "search yes" << endl;
    }else{
        cout << "search erro" << endl;
    }
    s1.print();
    cout << "size:" << s1.size() << endl;
    s1.delete_node(0);
    s1.print();
    s1.delete_all();
    s1.print();
    cout << "size:" << s1.size() << endl;
    
    
}