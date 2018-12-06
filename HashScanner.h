/* Ngan Campbell
 * Assignment 5
 * CS300 
 */

#include "HashTable.h"
#include <iostream> 
#include <sstream> 
#include <fstream>
#include <string>

class HashScanner{
    HashTable<string, string> database;
    public:
        void putDatabaseToHashTable(){
            ifstream file("upc_corpus.txt");
            string line;
            string barcode;
            string item;
            while(getline(file, line)){
                stringstream ss(line);    
                getline(ss, barcode,','); //uses , as splitter instead of white space 
                getline(ss, item,',');
                database.insert(barcode, item);
            }
        }

        void scan (){
            string upc;
            cout << "UPC Code: ";
            cin >> upc;
            clock_t t;
            t = clock();
            cout << database.retrieve(upc) << endl;
            t = clock() - t;
            cout << "Hashing time: " << t << " miliseconds" << endl;
        }

};