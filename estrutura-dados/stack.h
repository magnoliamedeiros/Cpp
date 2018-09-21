#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
struct stack {

    T* S;
    int top;
    int n;

    stack(int n) {
        S = new T[n + 1];
        top = 0;
        this->n = n;
    }
    void push(T x) {
        if (stackFull())
            throw std::overflow_error(
                    "pilha cheia");
        else {
            top++;
            S[top] = x;
        }
    }
    T pop() {
        if (stackEmpty())
            throw std::underflow_error(
                    "pilha vazia");
        else {
            top--;
            return S[top + 1];
        }
    }
    bool stackEmpty() {
        if (top == 0)
            return true;
        else
            return false;
    }
    bool stackFull() {
        if (top == n)
            return true;
        else
            return false;
    }
};

#endif /* STACK_H */
