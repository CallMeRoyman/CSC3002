/* Q2:
 * File: intarray.cpp
 * ------------------
 * This file inplements the intarray.h interface.
 */
#include <iostream>
#include "csc300222fall/assignment3/intarray.h"  

using namespace std;
/*
 * Implementation notes: IntArray constructor and destructor
 * ---------------------------------------------------------
 * The constructor allocates an array to hold the values and initializes
 * each element to 0; the constructor must also store the effective size
 * in the variable nElements.  The destructor must take responsibility
 * for freeing the dynamic array.
 */
 
void test(string str, int value, int expected) {
   cout << str << " -> " << value;
   if (value != expected) cout << " (should be " << expected << ")";
   cout << endl;
}

IntArray::IntArray(int n) {
   array = new int[n];
   for (int i = 0; i < n; i++){
      array[i] = 0;
   }
   nElements = n;
}

IntArray::~IntArray() {
   delete[] array;
}

/*
 * Implementation notes: size, get, and set
 * ----------------------------------------
 * Given the data structure, each of these methods is straightforward.
 */

int IntArray::size() {
   return nElements;
}

int IntArray::get(int index) {
   if (index >= nElements) error("get: Attempting to get an element out of scope.");
   return array[index];
}

void IntArray::put(int index, int value) {
   if (index >= nElements) error("put: Attempting to put an element out of scope.");
   else array[index] = value;
}

/*
 * Implementation notes: operator []
 * ---------------------------------
 * The selction operator is identical to get except for the fact that it
 * returns its result by reference.
 */

int & IntArray::operator[](int index) {
   if (index >= nElements) error("operator[]: Attempting to access an element out of scope.");
   return array[index];
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods make it possible to pass a IntArray by value or
 * assign one IntArray to another.
 */

IntArray::IntArray(const IntArray & src) {
   deepCopy(src);
}

IntArray & IntArray::operator=(const IntArray & src) {
   if (this != &src){
      delete[] array;
      deepCopy(src);      
   }
   return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object.
 * All dynamic memory is reallocated to create a "deep copy" in
 * which the current object and the source object are independent.
 */

void IntArray::deepCopy(const IntArray & src) {
   array = new int[src.nElements];
   for (int i = 0; i < src.nElements; i++){
      array[i] = src.array[i];
   }
   nElements = src.nElements;
}

/* DO NOT modify this part*/
int main() {
   int id;
   int size_num;
   cin>>id;
   cin>>size_num;

   if(id==1){
       IntArray array(size_num);
       test("array.size()", array.size(), 5);
       for (int i = 0; i < 5; i++) {
          test("array.get(" + integerToString(i) + ")", array.get(i), 0);
          cout << "array.put(" << i << ", " << i << ");" << endl;
          array.put(i, i);
          test("array.get(" + integerToString(i) + ")", array.get(i), i);
       }
   }
   if(id == 2){
       IntArray array(size_num);
       test("array.size()", array.size(), 5);
       for (int i = 0; i < 5; i++) {
          test("array[" + integerToString(i) + "]", array[i], 0);
          cout << "array[" << i << "] = " << i << ";" << endl;
          array[i] = i;
          test("array[" + integerToString(i) + "]", array[i], i);
       }
   }
   if(id == 3){
       IntArray v1(size_num);
       test("v1.size()", v1.size(), 5);
       for (int i = 0; i < 5; i++) {
          test("v1[" + integerToString(i) + "]", v1[i], 0);
          cout << "v1[" << i << "] = " << i << ";" << endl;
          v1[i] = i;
          test("v1[" + integerToString(i) + "]", v1[i], i);
       }
       IntArray v2;
       v2 = v1;
       test("v2.size()", v2.size(), 5);
       for (int i = 0; i < 5; i++) {
          test("v2[" + integerToString(i) + "]", v2[i], i);
       }
   }
   return 0;
}

