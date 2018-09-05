//
//  main.cpp
//  Coder
//
//  Created by Дмитрий on 02.09.2018.
//  Copyright © 2018 Дмитрий. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <ios>

#include "math.h"

#define file_in_len 100
#define key_len 31

using namespace std;

bool necessary_length(size_t &all, size_t &block){
    if (all >= file_in_len) {
        all-=file_in_len;
        block = file_in_len;
        return true;
    } else {
        block = all;
        all = 0;
        return false;
    }
}
void keyMenu(char* &key){
    cout << "Введите ключ (от 10 до 30 символов):" << endl;
    cin >> key;
    while (sizeof(key) < 10 || sizeof(key) > 30){
        cout << "Ошибка генерации ключа!!!" << endl;
        cout << "Введите ключ (от 10 до 30 символов):" << endl;
        cin >> key;
    }
}
int keyEngin(int num, int position, int keyLen){
    return (keyLen*( div((abs(position-num)), keyLen).quot + 1))-num;
}
int keyEngin1(int num, int position, int keyLen){
    return (position - div(num, keyLen).rem) > 0 ? keyLen-(position - div(num, keyLen).rem) : keyLen+(position - div(num, keyLen).rem) ;
}
int keyEngin2(int num, int position, int keyLen){
    return (position + div(num, keyLen).rem) > 12 ? (position + div(num, keyLen).rem)-keyLen : (position + div(num, keyLen).rem) ;
}
void keyGen(char* &key){
    char* ComandKey;
    int tmpKey;
    int currentPosition = 0;
    keyMenu(key);
    for (size_t i = 0; i < sizeof(key); i++) {
        for (int t = 0; t < 2; t++) {
            if (t == 0) {
                tmpKey = int(*(key + i)) >> 4;
                if ( tmpKey % 2 == 0){  //Если четный, то -, иначе +
                        // -
                        int num = tmpKey >> 1;
                        if (currentPosition - num > 0) {
                        currentPosition -= num;
                    } else {
                        
                    }
                }
            } else {
                
            }
        }
    }
    
    
}

const char* pathin = "/Users/howle/prog/Cpp/projects/Coder/Coder/Coder/input.txt";

int main(int argc, const char * argv[]) {
    vector<char> str;
    /*char key[key_len];
    keyGen(key);*/
    cout << keyEngin1(40, 2, 12) << endl;
    cout << keyEngin2(-40, 2, 12) << endl;
    ifstream file(pathin, ios::binary);
    if ( file.is_open() ) {
        cout << "Файл открыт" << endl;
    } else {
        cout << "Ошибка открытия" << endl;
    }
    file.seekg(0, ios::end);
    size_t size_of_file = file.tellg();
    size_t counter;
    size_t next_counter;
    file.seekg(0);
    bool state_counter = true;
    necessary_length(size_of_file, counter);
    next_counter = counter;
    char * buf = new char[counter+1];
    while (state_counter) {
        file.read(buf, counter);
        cout << buf << endl;
        state_counter = necessary_length(size_of_file, counter);
    }
    //for ( int i = 0; i < str.size(); i++) cout << str[i];
    cout << endl;
    for ( size_t i = 0; i < next_counter; i++){
        cout << *(buf+i) << endl;
    }
    file.close();
    return 0;
}
