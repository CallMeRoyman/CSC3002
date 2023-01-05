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

int getRow(int row, int dir, int situ){
   if (situ = 0){
      switch (dir){
         case 0: return row+1;
         case 1: return row-1;
         case 2: return row-2;
         case 3: return row-2;
         case 4: return row-1;
         case 5: return row+1;
         case 6: return row+2;
         case 7: return row+2;
         default: return row;
      }
   }else{
      switch (dir){
         case 0: return row+2;
         case 1: return row+1;
         case 2: return row-1;
         case 3: return row-2;
         case 4: return row-2;
         case 5: return row-1;
         case 6: return row+1;
         case 7: return row+2;
         default: return row;
      }
   }

      /*
      case 0: return row+2;
      case 1: return row+1;
      case 2: return row-1;
      case 3: return row-2;
      case 4: return row-2;
      case 5: return row-1;
      case 6: return row+1;
      case 7: return row+2;
      default: return row;
      */
}

int getCol(int col, int dir, int situ){
   if (situ = 0){
      switch (dir){
         case 0: return col+2;
         case 1: return col+2;
         case 2: return col+1;
         case 3: return col-1;
         case 4: return col-2;
         case 5: return col-2;
         case 6: return col-1;
         case 7: return col+1;
         default: return col;
      }
   }else{
      switch (dir){
         case 0: return col+1;
         case 1: return col+2;
         case 2: return col+2;
         case 3: return col+1;
         case 4: return col-1;
         case 5: return col-2;
         case 6: return col-2;
         case 7: return col-1;
         default: return col;
      }
   }
      
      /*
      case 0: return col+1;
      case 1: return col+2;
      case 2: return col+2;
      case 3: return col+1;
      case 4: return col-1;
      case 5: return col-2;
      case 6: return col-2;
      case 7: return col-1;
      default: return col;
      */
}


bool findKnightsTour(Grid<int> & board, int row, int col, int seq) {
   if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0) return false;
   if (board[row][col] != 0) return false;
   board[row][col] = seq;
   if (board.size() * board[0].size() == seq) return true;
   int situ = 1;
   if (board.size() < board[0].size()) {
      situ = 0;
   }else{
      situ = 1;
   }
   ++seq;
   for (int i = 0; i < 8; i++){
      if (findKnightsTour(board, getRow(row, i, situ), getCol(col, i, situ), seq)) {
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