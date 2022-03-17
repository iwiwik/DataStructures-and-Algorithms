
#include"Arrayqueue.h"




template<typename T>
array_queue<T>::array_queue():array(new T[array_size]),
front(0),rend(-1),count(0),capacity(array_size){

}

template<typename T>
array_queue<T>::~array_queue(){
    delete[] array;
}

template<typename T>
void array_queue<T>::push(T item){
    if(full()){
        cout << "erro overflow" << endl;
        exit(EXIT_FAILURE);

    }

    rend = (rend + 1) % capacity;
    array[rend] = item;
    count++;
}

template<typename T>
T array_queue<T>::pop(){
    if(empty()){
        cout << "erro not data" << endl;
        exit(EXIT_FAILURE);
    }

    T x = array[front];
    front = (front +1)% capacity;
    count--;
    return x;
}

template<typename T>
T array_queue<T>::peek(){
    if(empty()){
        cout << "erro not data" << endl;
        exit(EXIT_FAILURE);
    }
    return array[front];
}

template<typename T>
int array_queue<T>::size() const{
    return count;
}

template<typename T>
bool array_queue<T>::empty(){

    return count == 0;
}

template<typename T>
bool array_queue<T>::full(){
    return count == capacity;
}

int main(){

    array_queue<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.peek() << endl;
    for(int i = 0;i < 3;i++){
        cout << s1.pop() << endl;

    }
    s1.peek();

}