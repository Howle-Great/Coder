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

const char* pathin = "/Users/howle/prog/Cpp/projects/Coder/Coder/Coder/input.txt";

using namespace std;

bool necessary_length(size_t &all, size_t &block){  // Unused!!!
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
int keyEngin1(int &num, int &position, int &keyLen){ //-
    return (position - div(num, keyLen).rem) > 0 ? keyLen-(position - div(num, keyLen).rem) : keyLen+(position - div(num, keyLen).rem) ;
}
int keyEngin2(int &num, int &position, int &keyLen){ //+
    return (position + div(num, keyLen).rem) > 12 ? (position + div(num, keyLen).rem)-keyLen : (position + div(num, keyLen).rem) ;
}
void keyGen(vector<char> &code){
    char* key;
    int tmpKey = 0;
    int currentPosition = 0;
    keyMenu(key);
    int size = sizeof(key);
    for (size_t i = 0; i < size; i++) {
        for (int t = 0; t < 2; t++) {
            if (t == 0) {
                tmpKey = int(*(key + i)) >> 4;
                if ( tmpKey % 2 == 0){  //Если четный, то -, иначе +
                    // -
                    int num = tmpKey >> 1;
                    currentPosition = keyEngin1(num, currentPosition, size);
                    code.push_back(*(key+currentPosition)-255);
                } else {
                    // +
                    int num = tmpKey >> 1;
                    currentPosition = keyEngin2(num, currentPosition, size);
                    code.push_back(*(key+currentPosition));
                }
            } else {
                tmpKey = int(*(key + i)) & 15;
                if ( tmpKey % 2 == 0){  //Если четный, то -, иначе +
                    // -
                    int num = tmpKey >> 1;
                    currentPosition = keyEngin1(num, currentPosition, size);
                    code.push_back(*(key+currentPosition)-255);
                } else {
                    // +
                    int num = tmpKey >> 1;
                    currentPosition = keyEngin2(num, currentPosition, size);
                    code.push_back(*(key+currentPosition));
                }
            }
        }
    }
}
void Encryption(char* &dateFile){
    vector<char> code; // for key
    keyGen(code);
    for (int i = 0; i < sizeof(dateFile); i++) {
        *(dateFile + i) += code[i];
    }
    
}
void InitFile(){
    ifstream file(pathin, ios::binary);
    if ( file.is_open() ) {
        cout << "Файл открыт" << endl;
    } else {
        cout << "Ошибка открытия" << endl;
    }
    size_t size_of_file = file.seekg(0, ios::end).tellg();
    file.seekg(0);
    char * buf = new char[size_of_file+1];
    file.read(buf, size_of_file);
    cout << buf << endl;
    
    Encryption(buf);
    
    file.close();
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
