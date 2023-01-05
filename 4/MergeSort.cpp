
/* Q2:
 * File: MergeSort.cpp
 * -------------------
 * This file implements the merge sort algorithm using arrays rather
 * than vectors.
 */

#include <iostream>
#include "csc300222fall/assignment4/MergeSort.h"    // for OJ
using namespace std;

/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of the vector into increasing order using
 * the merge sort algorithm, which consists of the following steps:
 *
 * 1. Copy the array into an array allocated on the stack.
 * 2. Divide the new array into two halves by manipulating the indices.
 * 3. Sort each half of the array recursively
 * 4. Merge the two halves back into the original one.
 */
void merge(int array[], int left_array[], int right_array[], int n, int left_size, int right_size);

void sort(int array[], int n) { 
   if (n <= 1) return;
   int left_size = n/2;
   int right_size = n - left_size;
   const int MAX_CAPACITY = 10;
   int capacity = MAX_CAPACITY;
   while (right_size > capacity) capacity *= 2;
   int left_array[capacity];
   int right_array[capacity];
   int left = 0;
   int right = 0;
   for (int i = 0; i < n; i++){
      if (i < n/2) left_array[left++] = array[i];
      else right_array[right++] = array[i];
   }
   sort(left_array, left_size);
   sort(right_array, right_size);
   //p = 0;
   merge(array, left_array, right_array, n, left_size, right_size);
}

void merge(int array[], int left_array[], int right_array[], int n, int left_size, int right_size){
   int p1 = 0;
   int p2 = 0;
   int p = 0;
   while (p1 < left_size && p2 < right_size){
      if (left_array[p1] < right_array[p2]) array[p++] = left_array[p1++];
      else array[p++] = right_array[p2++];
   }
   while (p1 < left_size) array[p++] = left_array[p1++];
   while (p2 < right_size) array[p++] = right_array[p2++];
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the elements of the array on a single line with the elements
 * enclosed in braces and separated by commas.
 */

void printArray(int array[], int n) {
   cout << "{ ";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << " }" << endl;
}

/* DO NOT modify the main() part */
int main() {
   int n;
   cin>>n;
   int array[200010];
   for(int i=0;i<n;i++) cin>>array[i];
   sort(array, n);
   printArray(array, n);
   return 0;
}
