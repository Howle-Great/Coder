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

bool necessary_length(size_t &all, size_t &block){
    if (all >= 100) {
        all-=100;
        block = 100;
        return true;
    } else {
        block = all;
        all = 0;
        return false;
    }
}

const char* pathin = "input.txt";

using namespace std;
int main(int argc, const char * argv[]) {
    vector<char> str;
    char temp;
    ifstream file;
    file.open(pathin, ios::binary | ios::in);
    if ( !file ) {
        file.seekg(0, ios::end);
        size_t size_of_file = file.tellg();
        size_t counter;
        file.seekg(0);
        bool state_counter = necessary_length(size_of_file, counter);
        char * buf = new char[counter+1];
        while (state_counter) {
            file.read(buf, counter);
            state_counter = necessary_length(size_of_file, counter);
            cout << buf << endl;
        }
    }
    for ( int i = 0; i < str.size(); i++) cout << str[i];
    file.close();
    return 0;
}
