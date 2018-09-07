//
//  menu.cpp
//  Coder
//
//  Created by Дмитрий on 07.09.2018.
//  Copyright © 2018 Дмитрий. All rights reserved.
//

#include "menu.hpp"
#include <iostream>
#include <fstream>
#include <string>

bool default_in = true;

int menu(int &argc, const char * argv[]){
    std::string
    input_file_name,
    output_file_name;
    
    size_t i;
    for (i = 1; i < argc; ++i) {
        if ( (!strcmp(argv[i], "-p")) && (i+1 < argc) ) {
            input_file_name = argv[i+1];
            default_in = false; // Если false, то получено занчение
        }
    }
    
    std::ifstream fin;
    if (!default_in) {
        fin.open(input_file_name.c_str(), std::ios::binary);
        if ( !fin ) {
            std::cout << "Файл открыт" << std::endl;
        } else {
            std::cout << "Ошибка открытия" << std::endl;
        }
    }
}
