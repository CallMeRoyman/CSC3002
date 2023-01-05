
/* Q2:
 * File: ReverseQueue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
#include "csc300222fall/assignment2/reversequeue.h"
#include <stack>
using namespace std;

/* TODO PART:
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(queue<string> & queue) {
    stack<string> mystack;
    while (!queue.empty()){
        mystack.push(queue.front());
        queue.pop();
    }
    while (!mystack.empty()){
        queue.push(mystack.top());
        mystack.pop();
    }  
}

/* TODO PART:
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(queue<string> & queue) {
    std::queue<std::string> myqueue;
    cout << "The queue contains:";
    while (!queue.empty())
    {
        cout << " " << queue.front();
        myqueue.push(queue.front());
        queue.pop();
    }
    cout << endl;
    while (!myqueue.empty())
    {
        queue.push(myqueue.front());
        myqueue.pop();
    }
}

/* DO NOT modify this main() part*/

int main() {
    string str;
    queue<string> line;

    while(cin>>str){
        line.push(str);
    }
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}
