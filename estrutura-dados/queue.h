#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

template <typename T>
struct queue {

     T* Q; // array
     int head;
     int tail;
     int n;

     queue(int n){
          Q = new T[n+1];
          head = 1; // Vazio
          tail = 1; // Vazio
          this->n=n;
     }
     // Verificar se a fila está vazia
     bool queueEmpty(){
          if(head == tail){
               return true;
          } else {
               return false;
          }
     }
     bool queueFull(){
          if(head == tail + 1 || (head == 0 && tail == n)){
               return true;
          } else {
               return false;
          }
     }
     void enqueue(T x){
          if(queueFull()){
               throw std::overflow_error("Fila cheia.");
          }
          Q[tail] = x;
          if(tail == n){
               tail = 0;
          } else {
               tail++;
          }
     }
     T dequeue(){
          if(queueEmpty()){
               throw std::underflow_error("Fila vazia.");
          }
          T x = Q[head];
          if (head == n){
               head = 0;
          } else {
               head++;
          }
          return x;
     }
};

#endif /*QUEUE_H*/
