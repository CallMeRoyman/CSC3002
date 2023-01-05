#include <iostream>
#include <vector>
using namespace std;

vector<int> next (int row, int col, int x, int y){
   vector<int> vec;
   if (row - 2 >= 0 && col + 1 < y) vec.push_back(0);
   if (row - 1 >= 0 && col + 2 < y) vec.push_back(1);
   if (row + 1 < x && col + 2 < y) vec.push_back(2);
   if (row + 2 < x && col + 1 < y) vec.push_back(3);
   if (row + 2 < x && col - 1 >= 0) vec.push_back(4);
   if (row + 1 < x && col - 2 >= 0) vec.push_back(5);
   if (row - 1 >= 0 && col - 2 >= 0) vec.push_back(6);
   if (row - 2 >= 0 && col - 1 >= 0) vec.push_back(7);
   return vec;
}

int main(){
    vector<int> vec = next(1,1,8,8);
    int count = vec.size();
    for (int i = 0; i < count; ++i){
        for (int j = i+1; j < count; ++j){
            cout << i << ' ' << j << endl;
            if (vec[i] > vec[j]){
                int tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
        }
    }
    for (int i = 0; i < count; ++i){
        cout << vec[i] << ' ';
    }
}
    
