#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>

using namespace std;

int Hashing(string placa){//Complejidad O(N)
    int key=0;
    for (int i = 0; i < placa.length(); i++){
        key = key + placa[i];
    }
    key = key%97;
    return key;
};

class Auto{
public:
    int key;
    string placa, marca, modelo;
    string anio;
        Auto(){

        }
};

class MyHashTable{
    Auto **arr;
    int size,count;
public:
    MyHashTable(int s){
        count = 0;
        size = s;
        arr = new Auto*[size];
        for (int i = 0; i < size; i++){
            arr[i]=nullptr;
        }
    }
    
    int hashIt(int n){//Complejidad O(1)
        return n%size;
    }

    void ins(int key, string placa, string marca, string modelo, string anio){//Complejidad O(N)
        if(count == size){
            cout << "tabla llena, imposible insertar" << endl;
            return;
        }
        int hashIndex = hashIt(key);
        while (arr[hashIndex] != nullptr){
            hashIndex = (hashIndex + 1) % size;
        }
        arr[hashIndex] = new Auto();
        arr[hashIndex]->key = key;
        arr[hashIndex]->placa = placa;
        arr[hashIndex]->marca = marca;
        arr[hashIndex]->modelo = modelo;
        arr[hashIndex]->anio = anio;
        count++;
    }

    string search(int key){//Complejidad O(1)
        if (count == 0){
            return "dato no encontrado";
        }
        int hashIndex = hashIt(key);
        int temp = hashIndex;
        while (true){
            if (arr[hashIndex] == nullptr){
                hashIndex = (hashIndex + 1) % size;
            }else if(arr[hashIndex]->key != key){
                hashIndex = (hashIndex + 1) % size;
            }else{
                break;
            }
            if (hashIndex == temp){
                temp = -1;
                break;
            }
        }
        if (temp == 1){
            return "dato no encontrado" ;
        }else{
            return arr[hashIndex]->placa + " " + arr[hashIndex]->marca + " "+ arr[hashIndex]->modelo + " "+ arr[hashIndex]->anio ;
        }
    }

    void del(int key){//Complejidad O(long N)
        if (count == 0){
            cout << "dato no encontrado" << endl;
        }
        int hashIndex = hashIt(key);
        int temp = hashIndex;
        while (true){
            if (arr[hashIndex] == nullptr){
                hashIndex = (hashIndex + 1) % size;
            }else if (arr[hashIndex]->key != key){
                hashIndex = (hashIndex +1) % size;
            }else{
                break;
            }
            if (hashIndex == temp){
                temp = -1;
                break;
            }
        }
        if (temp == -1){
			
        }else{
            delete arr[hashIndex];
            arr[hashIndex] = nullptr;
            count--;
        }
    }

    void print(){//Complejidad O(N)
        for (int i = 0; i < size; i++){
            if (arr[i] != nullptr){
                cout << i << " " << arr[i]->placa << " " << arr[i]->marca << " " << arr[i]->modelo << " " << arr[i]->anio <<endl;
            }else{
                cout << i << endl;
            }
        }
    }
    ~MyHashTable(){//Complejidad O(N)
        for (int i = 0; i < size; i++){
            if (arr[i] != nullptr){
                delete arr[i];
                arr[i] = nullptr;
            }
        }   
    }
};

int main(){
    MyHashTable mht(97);
    string placa, marca, modelo, anio, choice;
    int key, value;
    while(1){
        getline(cin, choice);
        switch(stoi(choice))
        {
        case 1:
            getline(cin, placa);
            getline(cin, marca);
            getline(cin, modelo);
            getline(cin, anio);
            stoi(anio);
            key=Hashing(placa);
			mht.ins(key, placa, marca, modelo, anio);
            break;
        case 2:
            getline(cin, placa);
            key=Hashing(placa);
            mht.del(key);
            break;
        case 3:
            mht.print();
            break;
        case 4:
            getline(cin, placa);
            key=Hashing(placa);
            cout << mht.search(key) << endl;
            break;
        case 0:
            exit(1);
       }
    }
}
