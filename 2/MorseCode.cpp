/* Q3
 * File: MorseCode.cpp
 * -------------------
 * This program translates to and from Morse Code using maps to
 * assist in the translation.
 */

#include <iostream>
#include <string>
#include <map>
#include "csc300222fall/assignment2/lib.h" 
#include "csc300222fall/assignment2/morsecode.h" 
using namespace std;


/*
 * TODO function
 * Function: translateLettersToMorse
 * Usage: string morse = translateLettersToMorse(line);
 * ----------------------------------------------------
 * Translates a string of letters into Morse Code characters separated
 * by spaces.  Characters that don't appear in the table are simply ignored.
 */

string translateLettersToMorse(string line) {
   string morse = "";
   map<string, string> morsemap = createMorseCodeMap();
   string ch;
   for (unsigned i = 0; i < line.length(); i++){
      ch = line[i];
      morse += morsemap[ch];
      morse += " ";
   }
   return morse;
}

/*
 * TODO function
 * Function: translateMorseToLetters
 * Usage: string letters = translateLettersToMorse(line);
 * ------------------------------------------------------
 * Translates a string in Morse Code into English letters.
 * Because word breaks are not represented in Morse code, the
 * letters in the output will be run together.  The characters
 * of the Morse Code input must be separated by a single space.
 * Any other character in the input is simply ignored.  If there
 * is no English equivalent for the Morse Code character, this
 * function indicates that fact by inserting a question mark (?).
 *
 * Implementation note: To eliminate the special case of the last
 * character in the line, this function begins by adding a space
 * to the end of the input string.
 */

string translateMorseToLetters(string line) {
   map<string, string> morsemap = invertMap(createMorseCodeMap());
   int begin = 0;
   int end = 0;
   string ch;
   string letters = "";
   while (end < line.length() && end >= 0){
      end = line.find(" ", begin) - 1;
      ch = line.substr(begin, end-begin+1);
      cout << ch << endl;
      if (morsemap.count(ch)) {
         letters += morsemap[ch];
      }
      else {
         letters += "?";
      }
      //letters += morsemap[ch];
      begin = end + 2;
      while (line[begin] == ' ')
      {
         begin++;
      }
      
   }
   return letters;
}

/*
 * Function: createMorseCodeMap
 * Usage: map<string> map = createMorseCodeMap();
 * ----------------------------------------------
 * Returns a map in which each uppercase letter is mapped into its
 * Morse code equivalent.
 */

map<string,string> createMorseCodeMap() {
   map<string,string> map;
   map["A"] = ".-";
   map["B"] = "-...";
   map["C"] = "-.-.";
   map["D"] = "-..";
   map["E"] = ".";
   map["F"] = "..-.";
   map["G"] = "--.";
   map["H"] = "....";
   map["I"] = "..";
   map["J"] = ".---";
   map["K"] = "-.-";
   map["L"] = ".-..";
   map["M"] = "--";
   map["N"] = "-.";
   map["O"] = "---";
   map["P"] = ".--.";
   map["Q"] = "--.-";
   map["R"] = ".-.";
   map["S"] = "...";
   map["T"] = "-";
   map["U"] = "..-";
   map["V"] = "...-";
   map["W"] = ".--";
   map["X"] = "-..-";
   map["Y"] = "-.--";
   map["Z"] = "--..";
   return map;
}

/*
 * TODO function
 * Function: invertMap
 * Usage: map<string> inverse = invertMap(map);
 * --------------------------------------------
 * Creates an inverted copy of the specified map in which the values
 * in the original become the keys of the new map and refer back to
 * their associated keys.  Thus, if "abc" is bound to "xyz" in the
 * original map, the inverted map will bind "xyz" to "abc".  If two
 * keys in the original map have the same value, this function will
 * signal an error condition.
 */

map<string,string> invertMap(const map<string,string> & m) {
   map<string, string> inMap;

   /*
   inMap[".-"] = "A";
   inMap["---"] = "O";
   inMap["..."] = "S";
   inMap[".."] = "I";
   inMap["-"] = "T";
   inMap["-.-."] = "C";
   inMap["-."] = "N";
   */
   //string oriKey = "A";
   //inMap[m[oriKey]] = oriKey;

   for (map<string, string>::const_iterator it = m.begin(); it != m.end(); ++it){
      inMap[it->second] = it->first;
   }

   return inMap;
}

int main() {
    /* A sample translator:
     *                     > SOS
     *                     ... --- ...
     *                     > ... --- ...
     *                     SOS
     */
    string line;
    
    while (getline(cin, line) && line.length() > 0) {
       line = toUpperCase(line);
       if (line[0] == '.' || line[0] == '-') {
           cout << translateMorseToLetters(line) << endl;
       } else {
           cout << translateLettersToMorse(line) << endl;
       }
    }
    return 0;
   
}

