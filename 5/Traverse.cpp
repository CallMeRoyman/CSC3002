/*
 * File: Traverse.cpp
 * ------------------
 * This program reimplements the breadth-first search using an
 * explicit queue, and depth-first search algorithm using an explicit stack
 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include "csc300222fall/assignment5/simplegraph.h"
using namespace std;

bool isInSet(set<Node *> mySet, Node* node) {
   if (mySet.find(node) != mySet.end()) return true;
   return false;
}

void bfs(Node *start) {
   set<Node *> visited;
   queue<Node *> myQueue;
   myQueue.push(start);
   while (!myQueue.empty()) {
      start = myQueue.front();
      myQueue.pop();
      if (!isInSet(visited, start)) {
         cout << start->name << endl;
         visited.insert(start);
         for (Arc *arc : start->arcs) {
            myQueue.push(arc->finish);
         }
      }
   }    
}

void dfs(Node *start) {
   stack<Node *> nextMove;
   set<Node *> visited;
   Node *tovisit;
   nextMove.push(start);
   while (!nextMove.empty()) {
      tovisit = nextMove.top();
      nextMove.pop();
      if (!isInSet(visited, tovisit)) cout << tovisit->name << endl;
      visited.insert(tovisit);
      for (Arc *arc : tovisit->arcs) {
         if (!isInSet(visited, arc->finish)) nextMove.push(arc->finish);
      }
   }
}

int main(){
   SimpleGraph airline;
   readGraph(airline, cin);
   cout << "DFS at Portland ...." << endl;
   dfs(airline.nodeMap.at("Portland"));
   cout << "BFS at Portland ...." << endl;
   bfs(airline.nodeMap.at("Portland"));
   return 0;
}
