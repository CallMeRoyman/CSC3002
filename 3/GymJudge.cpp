/* Q1:
 * File: GymJudge.cpp
 * ------------------
 * This program averages a set of gymnastic scores after eliminating
 * the lowest and highest scores.
 */
#include "csc300222fall/assignment3/GymnasticsJudge.h"
using namespace std;

/* Function prototypes */

double sumArray(double array[], int n);
double findLargest(double scores[], int n);
double findSmallest(double scores[], int n);
int readScores(double scores[], int max);

/*
 * Function: sumArray
 * Usage: double sum = sumArray(array, n);
 * ---------------------------------------
 * This function returns the sum of the first n elements in array.
 */

double sumArray(double array[], int n) {
   int i = 0;
   double rst = 0;
   while (i < n){
      //rst += array[i++];
      rst += *array++;
      i++;
   }
   return rst;
}

/*
 * Function: findLargest
 * Usage: double largest = findLargest(array, n);
 * ----------------------------------------------
 * This function returns the largest value in the first n elements in array.
 */

double findLargest(double array[], int n) {
   int i = 0;
   double max = array[i];
   while (i < (n-1)){
      if (max < array[++i]){
         max = array[i];
      }
   }
   return max;
}

/*
 * Function: findSmallest
 * Usage: double smallest = findSmallest(array, n);
 * ------------------------------------------------
 * This function returns the smallest value in the first n elements in array.
 */

double findSmallest(double array[], int n) {
   int i = 0;
   double min = array[i];
   while (i < (n-1)){
      if (min > array[++i]){
         min = array[i];
      }
   }
   return min;
}

/* DO NOT modify this part*/
/*
 * Function: readScores
 * Usage: int nJudges = readScores(scores, max);
 * ---------------------------------------------
 * This function reads in scores for each of the judges.  The array
 * scores must be declared by the caller and must have an allocated
 * size of max.  The return value is the number of scores.  From the
 * user's perspective, the numbering of the judges begins with 1
 * because that style of numbering is more familiar; internally,
 * the array index values begin with 0.
 */

int readScores(double scores[], int max) {
   cerr << "Enter a score for each judge in the range " << MIN_SCORE;
   cerr << " to " << MAX_SCORE << "." << endl;
   cerr << "Enter a blank line to signal the end of the list." << endl;
   int n = 0;
   string line;
   while (n < max) {
      cerr<<"Judge #" + integerToString(n + 1) + ": " ;
      getline(cin,line);
      if (line == "") return n;
      double score = stringToReal(line);
      if (MIN_SCORE <= score && score <= MAX_SCORE) {
         scores[n++] = score;
      } else {
         cout << "That score is out of range." << endl;
      }
   }
   return max;
}


/* DO NOT modify the main() part*/

int main() {
   double scores[MAX_JUDGES];
   int nJudges = readScores(scores, MAX_JUDGES);
   if (nJudges < 3) {
      cout << "You must enter scores for at least three judges." << endl;
   } else {
      double total = sumArray(scores, nJudges);
      double smallest = findSmallest(scores, nJudges);
      double largest = findLargest(scores, nJudges);
      double average = (total - smallest - largest) / (nJudges - 2);
      cout << "The average after eliminating "
           << fixed << setprecision(2) << smallest << " and "
           << setprecision(2) << largest << " is "
           << setprecision(2) << average << "." << endl;
   }
   return 0;
}
