#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct l {
    T key;
    l<T>* next;

    l(T key) {
        this->key = key;
        next = nullptr;
    }
};

template <typename T>
struct list {
    l<T>* head;
    int size;

    list() {
        head = nullptr;
        size = 0;
    }
    l<T>* search(T k) {
        l<T>* x = head;
        while (x != nullptr && x->key != k) {
            x = x->next;
        }
        return x;
    }
    void insert(l<T>* x) {
        x->next = head;
        head = x;
        size++;
    }
    void remove(T k) {
        if (size == 0) {
            throw underflow_error("Lista vazia.");
        }
        if (head->key == k) {
            l<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
        } else {
            l<T>* x = head;
            while (x != nullptr) {
                if (x->next->key == k) {
                    l<T>* temp = x->next;
                    x->next = x->next->next;
                    delete temp;
                    size--;
                    return;
                }
                x = x->next;
            }
        }
    }
    void print() { // operação bonus!
        l<T>* x = head;
        while (x != nullptr) {
            cout << x->key << " ";
            x = x->next;
        }
        cout << endl;
    }
};

#endif /* LIST_H */
