#include"Array_stack.h"


template<typename T>
array_stack<T>::array_stack():t(-1),array(new T[array_size]),count(0){}

template<typename T>
array_stack<T>:: ~array_stack(){
    delete[] array;
}

template<typename T>
void array_stack<T>::push(T item){
    if(count == array_size){
        cout << "erro overflow" << endl;
        exit(EXIT_FAILURE);
    }

    array[++t] = item;
    count++;
}

template<typename T>
void array_stack<T>::pop(){
    if(empty()){
        cout << "erro not data" << endl;
        exit(EXIT_FAILURE);
    }

    t--;
    count--;
}

template<typename T>
T array_stack<T>::top(){
    if(empty()){
        cout << "erro not data" << endl;
        exit(EXIT_FAILURE);
    }
    return array[t];

}

template<typename T>
bool array_stack<T>::empty(){
    return count == 0;
}

int main(){

    array_stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
}