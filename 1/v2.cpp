/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
using namespace std;

#pragma GCC diagnostic ignored "-Wcomment"
/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {
    string line, prgm;
    char ch;
    prgm = "";
    while (is.get(ch)){
        prgm+=ch;
    }
    
    int n = prgm.length();
	string res;

	// Flags to indicate that single line and multiple line comments
	// have started or not.
	bool s_cmt = false;
	bool m_cmt = false;

	os << prgm;

	// Traverse the given program
	for (int i=0; i<n; i++){
		// If single line comment flag is on, then check for end of it
		if (s_cmt == true && prgm[i] == '\n')
			s_cmt = false;

		// If multiple line comment is on, then check for end of it
		else if (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/')
			m_cmt = false, i++;

		// If this character is in a comment, ignore it
		else if ((s_cmt || m_cmt) && prgm[i] != '\n')
			continue;

		// Check for beginning of comments and set the appropriate flags
		else if (prgm[i] == '/' && prgm[i+1] == '/' && prgm[i-1] == '\n')
			s_cmt = true, i++;
		else if (prgm[i] == '/' && prgm[i+1] == '/')
			s_cmt = true, i++, res += '\n';
		else if (prgm[i] == '/' && prgm[i+1] == '*')
			m_cmt = true, i++;

		else if (m_cmt == true && prgm[i] == '\n')
			prgm[i] = '\0';

		// If current character is a non-comment character, append it to res
		else res += prgm[i];
	}
	if (res[res.length()-1] = '\n') res[res.length()-1] = '\0';
    os << "-----------------------------------------------------" << endl;
    os << res;
}

void TestRemoveComments(){
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}
