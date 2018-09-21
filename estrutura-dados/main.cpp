#include <cstdlib>
#include <iostream>
// #include "stack.h"
// #include "queue.h"
#include "list.h"

using namespace std;

int main(){

     // stack<int> S(3);
     // S.push(10);
     // S.push(5);
     // S.push(7);
     // cout << S.pop() << " ";
     // cout << S.pop() << " ";
     // cout << S.pop() << " ";

     // queue<int> Q(3);
     // Q.enqueue(10);
     // Q.enqueue(5);
     // Q.enqueue(0);

     // cout << Q.dequeue() << " ";
     // cout << Q.dequeue() << " ";
     // cout << Q.dequeue() << " ";

     list<int> L;
     L.insert(new l<int>(10));
     L.insert(new l<int>(5));
     L.insert(new l<int>(2));

     // cout << "Tamanho da lista: " << L.size << endl;
     // cout << L.search(2) << endl;
     // cout << L.search(2)->key << endl;

     L.print();
     L.remove(5);
     L.print();

     return 0;
}
