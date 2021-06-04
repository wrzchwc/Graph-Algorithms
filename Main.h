//
// Created by kubaw on 01.06.2021.
//

#ifndef PDBFK_MAIN_H
#define PDBFK_MAIN_H
#include <iostream>

using namespace std;
//interprets line stored in the txt file
int* interpret(string line, const string& delimiter, int number);
//returns random number
int random_number(int minimum, int maximum);
#endif //PDBFK_MAIN_H
