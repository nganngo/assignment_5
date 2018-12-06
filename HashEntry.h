/* Ngan Campbell
 * Assignment 5
 * CS300 
 */

#include <iostream>
#include <string>

using namespace std;

template <class T, class U>
class HashEntry{
    T key;
    U value;
    HashEntry<T, U> * next;
    public:
        HashEntry();
        HashEntry(T, U);
        T getKey();
        U getValue();
        HashEntry<T,U>* getNext();
        void setNext(HashEntry<T, U> *);
        void setKey(T);
        void setValue(U&);

};

template <class T, class U>
HashEntry<T, U>::HashEntry(T k, U v){
    key = k;
    value = v;
    next = NULL;
}

template <class T, class U>
T HashEntry<T, U>::getKey(){
    return key;
}

template <class T, class U>
U HashEntry<T, U>::getValue(){
    return value;
}

template <class T, class U>
void HashEntry<T, U>::setKey(T k){
    key = k;
}

template <class T, class U>
void HashEntry<T, U>::setValue(U& v){
    value = v;
}

template <class T, class U>
HashEntry<T, U>* HashEntry<T, U>::getNext(){
    return next;
}
 
template <class T, class U>
void HashEntry<T, U>::setNext(HashEntry<T, U> * n){
    next = n;
}
