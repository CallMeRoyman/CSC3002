#include <iostream>
//#include <cctype>
//#include <cstring>
using namespace std;

int permutations(int n, int k) {
   int result = 1;
   for (int count = n; count > (n-k); count--){
      result = result * count;
   }
   return result;
}

void swap(int &x, int &y){
   int tmp = x;
   x = y;
   y = tmp;
}
string matchingStrand(string strand);

int findDNAMatch(string s1, string s2, int start=0) {
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

//bugs on TAACGGTACGTCAACGGAACGGAACGG, fixed after add addline_1
void findAllMatches(string s1, string s2) {
   int starter = 0;
   int pos = findDNAMatch(s1, s2);
   while (pos != -1){
      cout << s1 << " matches " << s2 << " at position " << pos << endl;
      starter = pos;       //addline_1
      starter += s1.length();
      pos = findDNAMatch(s1, s2, starter);
   }
}

int main(){
   findAllMatches("TTGCC", "TAACGGTACGTCAACGGAACGGAACGG");
   //cout << result << endl;
}
