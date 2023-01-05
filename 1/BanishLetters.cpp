/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
//#include <fstream> 
//#include <string>
#include "csc300222fall/assignment1/lib.h" //for local version
using namespace std;

int banishLetters() {
       //ifstream infile;
       //ofstream outfile;
       string inputfile;
       string outputfile;
       string text;
       string lettersToBanish;
       string line;
       /*
       cout << "Input file name: ";
       cin >> inputfile;
       cout << "Output file: ";
       cin >> outputfile;
       */

       //cout << "Letters to banish: ";
       //cin >> lettersToBanish;
       getline(cin, lettersToBanish);
       

       while (getline(cin, line, '\0')){
              text.append(line);
       }
       //cout << "Input text: ";
       //getline(cin, text, '\0');

       string toBanish;
       toBanish = "";
       for (int i = 0; i < lettersToBanish.length(); i++){
              toBanish += lettersToBanish[i];
              if (islower(lettersToBanish[i])){
                     toBanish += toupper(lettersToBanish[i]);
              }
              else{
                     toBanish += tolower(lettersToBanish[i]);
              }
       }

       for (int i = 0; i < text.length(); i++){
              if (toBanish.find(text[i]) == string::npos){
                     cout.put(line[i]);
              }
       }
       /*
       infile.open(inputfile.c_str());
       outfile.open(outputfile.c_str());
       while (getline(infile, line)){
              for (int i = 0; i < line.length(); i++){
                     if (toBanish.find(line[i]) == string::npos){
                            cout.put(line[i]);
                            outfile << line[i];
                     }
              }
       if (!infile.eof()){
              cout << endl;
              outfile << endl;
       }
       }
       infile.close();
       outfile.close();
       */
       return 0;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
