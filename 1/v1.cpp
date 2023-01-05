/* Q2: 
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
// header file for OJ system
// #include <iostream>
// #include <string>

// using namespace std;

#include <iostream>
#include <string>
#include "csc300222fall/assignment1/FindDNAMatch.h" //for OJ
using namespace std;


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {
   string matching = matchingStrand(s1);
   if (matching == "invalid strand"){
      return -1;
   }
   size_t found = s2.find(matching, start);
   if (found != string::npos){
      return found;
   }
   return -1;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
   string match = "";
   for (int i = 0; i < strand.length(); i++){
      switch (strand[i])
      {
      case 'A': match+="T"; break;
      case 'T': match+="A"; break;
      case 'C': match+="G"; break;
      case 'G': match+="C"; break;
      default: return "invalid strand";
      }
   }
   return match;
}
/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
   int starter = 0;
   int pos = findDNAMatch(s1, s2);
   while (pos != -1){
      cout << s1 << " matches " << s2 << " at position " << pos << endl;
      starter = pos;       //addline_1
      starter += s1.length();
      pos = findDNAMatch(s1, s2, starter);
   }
   if (pos == -1){
      cout << s1 << " has no matches in " << s2 << endl;
   }
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/
int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 
    findAllMatches(s1, s2);
    return 0;
}
