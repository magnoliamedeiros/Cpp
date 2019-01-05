#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct l {
    l<T>* previous;
    T key;
    l<T>* next;

    l(T key) {
        previous = nullptr;
        this->key = key;
        next = nullptr;
    }
};

template <typename T>
struct doublelist {
    l<T>* head;
    int size;

    doublelist() {
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
        if (head != nullptr)
            head->previous = x;
        head = x;
        size++;
    }
    void orderedInsert(l<T>* x) {
        l<T>* z = head;
        if (z == nullptr) {
            insert(x);
        } else
            while (z != nullptr) {
                if (z->key > x->key) {
                    x->next = z;
                    if (z == head) {
                        z->previous = x;
                        head = x;
                    } else {
                        x->previous = z->previous;
                        x->previous->next = x;
                        z->previous = x;
                    }
                    size++;
                    return;
                }
                if (z->next == nullptr) {
                    x->previous = z;
                    z->next = x;
                    size++;
                    return;
                }
                z = z->next;
            }

    }
    void remove(T k) {
        if (size == 0) {
            throw underflow_error("Lista vazia.");
        }
        l<T>* x = search(k);
        if (x != nullptr) {
            if (x->previous != nullptr) {
                x->previous->next = x->next;
            } else {
                head = x->next;
            }
            if (x->next != nullptr) {
                x->next->previous = x->previous;
            }
            delete x;
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

#endif /* DOUBLELIST_H */
