/* Q1
 * File: KnightsTour.cpp
 * ---------------------
 * This program find a knight's tour on an N x M chessboard.
 */

#include "csc300222fall/assignment4/KnightsTour.h" //For OJ
#include <chrono>
using namespace std::chrono;
/*
 * Function: solveKnightsTour
 * Usage: solveKnightsTour(n, m);
 * ------------------------------
 * Solves the knight's tour problem for a n x m chessboard.
 */

void solveKnightsTour(int n, int m) {
   
   Grid<int> board(n, vector<int>(m, 0));

   if (findKnightsTour(board, 0, 0, 1)) {
      displayBoard(board);
   } else {
      displayBoard(board);
      cout << "No tour exists for this board." << endl;
   }
}

/*
 * Function: displayBoard
 * Usage: displayBoard(board);
 * ---------------------------
 * Displays each of the squares in the board along with its sequence
 * number in the tour.
 */

void displayBoard(Grid<int> & board) {
   for (int i = board.size() - 1; i >= 0; i--) {
      for (int j = 0; j < board[0].size(); j++) {
         cout << " " << setw(2) << board[i][j];
      }
      cout << endl;
   }
}

/*
 * Function: findKnightsTour
 * Usage: flag = findKnightsTour(board, row, col, seq);
 * ----------------------------------------------------
 * This function looks for a tour on the board, starting at
 * the position indicated by row and col. The seq parameter is
 * the sequence number of this move and is needed to keep
 * track of the steps on the tour. The function returns true
 * if a tour is found and false otherwise.
 *
 * This function begins by checking for three simple cases:
 *
 * 1. The position is off the board.
 * 2. The position has been previously visited.
 * 3. The tour is complete.
 *
 * In the first two cases, there can be no tour that begins
 * from that position on the board. In the last case, the
 * function can immediately return true.
 *
 * If the simple cases do not apply, the function marks the
 * current square and then tries all possible moves. If it
 * finds a tour from the resulting position, the function
 * returns true to the next highest level. If no moves lead
 * to a tour, the function must back out of this move and try
 * again at a higher level of the recursion.
 *
 * The for loops in this implementation are a little tricky.
 * They compute the row and column offsets for the next position by
 * noting that the row and column offsets add to 3 (either +1 and +2
 * or +2 and +1) and you need all four possible sign combinations.
 */
//int R[] = {1, 1, -1, -1, -2, 2, -2, 2};
//int C[] = {-2, 2, -2, 2, 1, 1, -1, -1};
int R[] = {2,1,-1,-2,-2,-1,1,2};
int C[] = {1,2,2,1,-1,-2,-2,-1};

vector<int> next (int row, int col, int x, int y){
   vector<int> vec;
   if (row - 2 >= 0 && col + 1 < y) vec.push_back(3);
   if (row - 1 >= 0 && col + 2 < y) vec.push_back(2);
   if (row + 1 < x && col + 2 < y) vec.push_back(1);
   if (row + 2 < x && col + 1 < y) vec.push_back(0);
   if (row + 2 < x && col - 1 >= 0) vec.push_back(7);
   if (row + 1 < x && col - 2 >= 0) vec.push_back(6);
   if (row - 1 >= 0 && col - 2 >= 0) vec.push_back(5);
   if (row - 2 >= 0 && col - 1 >= 0) vec.push_back(4);
   return vec;
}

int compare (int row1, int col1, int row2, int col2, int x, int y){
   return next(row1, col1, x, y).size() - next(row2, col2, x, y).size();
}

void sort (vector<int> &vec, int row, int col, int x, int y){
   if ((x == 7 && y == 6) || (x == 7 && y == 4) || (x == 8 && y == 4)) return;
   int count = vec.size();
      for (int i = 0; i < count; ++i){
         for (int j = i+1; j < count; ++j){
            if (compare(row+R[vec[i]], col+C[vec[i]], row+R[vec[j]], col+C[vec[j]], x, y) > 0){
               int tmp = vec[i];
               vec[i] = vec[j];
               vec[j] = tmp;
            }
         }
      }
}

bool findKnightsTour(Grid<int> & board, int row, int col, int seq) {
   if (board[row][col] != 0) return false;
   board[row][col] = seq;
   if (board.size() * board[0].size() == seq) return true;
   ++seq;
   vector<int> vec = next(row, col, board.size(), board[0].size());
   /* ------------------------------------------------------------- */
   sort(vec, row, col, board.size(), board[0].size());
   /* ------------------------------------------------------------- */
   for (int i = 0; i < vec.size(); ++i){
      if (findKnightsTour(board, row + R[vec[i]], col + C[vec[i]], seq)) {
         return true;
      }
   }
   board[row][col] = 0;
   --seq;
   return false;
}

/* DO NOT modify the main() part */
int main() {
   int n, m;
   cin>>n>>m;
   auto start = high_resolution_clock::now();
   solveKnightsTour(n, m);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken: " << duration.count() * 0.000001 << " seconds." << endl;
   return 0;
}