#include <cstdlib>
#include <iostream>
// #include "stack.h"
#include "queue.h"

using namespace std;
int main(){

     // stack<int> S(3);
     // S.push(10);
     // S.push(5);
     // S.push(7);
     // cout << S.pop() << " ";
     // cout << S.pop() << " ";
     // cout << S.pop() << " ";

     queue<int> Q(3);
     Q.enqueue(10);
     Q.enqueue(5);
     Q.enqueue(0);

     cout << Q.dequeue() << " ";
     cout << Q.dequeue() << " ";
     cout << Q.dequeue() << " ";
     return 0;
}
