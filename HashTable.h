/* Ngan Campbell
 * Assignment 5
 * CS300 
 */

#include "HashEntry.h"
#include <iostream>
#include <string>
#include <climits>


using namespace std;

const int tableSize = 1000;

template <class T, class U>
class HashTable{
    HashEntry<T, U> **table;
    public:
        HashTable();
        U retrieve(T&);
        void insert(T&, U&);
        int getHash(T& key);
        ~ HashTable();
};

template <class T, class U>
HashTable<T, U>::HashTable(){
    table = new HashEntry<T, U>*[tableSize];
    for(int i = 0; i < tableSize; i++){
        table[i] = NULL;
    }
}

template <class T, class U>
int HashTable<T, U>::getHash(T &key){
    unsigned long hash = 0;
    int result;
    int c;
    const char *str;
    str = key.c_str();
    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash;
    int count = 0;
    while (hash > tableSize && count < 1000) {
        count++;
        hash /= 10;
    }
    result = hash & INT_MAX;
    // cout << "hash: " << result << endl;
    return result;
}

template <class T, class U>
U HashTable<T, U>::retrieve(T &key){
    int hash = getHash(key);
    if(table[hash] == NULL){
        cout << "Barcode was not found." << endl;
    } else{
        HashEntry<T, U> *entry = table[hash];
        while(entry != NULL && entry -> getKey() != key){
            entry = entry -> getNext();
        }
        if(entry == NULL){
            cout << "Barcode was not found." << endl;
        }else{
            return entry -> getValue();
        }
    }
}

template <class T, class U>
void HashTable<T, U>::insert(T &key, U &value){
    int hash = getHash(key);
    // cout << hash << endl;
    if(table[hash] == NULL){
        table[hash] = new HashEntry<T, U>(key,value);
    }else{
        HashEntry<T, U> * entry = table[hash];
        while (entry->getNext() != NULL){
            entry = entry->getNext();
        }
        if (entry->getKey() == key){
            entry->setValue(value);
        }else{
            entry->setNext(new HashEntry<T, U>(key, value));
        }
    }
}

template <class T, class U>
HashTable<T, U>::~HashTable(){
    for(int i = 0; i < tableSize; i++){
        if(table[i] != NULL){
            delete table[i];
        }
        delete [] table;
    }
}
