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
void keyGen(char* &key){
    cout << "Введите ключ (от 10 до 30 символов):" << endl;
    cin >> key;
}

const char* pathin = "/Users/howle/prog/Cpp/projects/Coder/Coder/Coder/input.txt";

int main(int argc, const char * argv[]) {
    vector<char> str;
    /*char key[key_len];
    keyGen(key);*/
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
