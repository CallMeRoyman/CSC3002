#include <iostream>
#include <fstream>
#include <string>
#include "csc300222fall/assignment1/lib.h" //for local version
using namespace std;

int main(){
    string str;
    char ch;
    str = "aeiou";
    for (int i = 0; i < str.length(); i++){
        ch = str[i];
        cout << ch << endl;
    }
    
}

