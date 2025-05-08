

#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
using namespace std;

typedef int ItemType;

struct NodeType {
    ItemType value;
    NodeType* next;
};

class StackType {

private:
    NodeType* topPtr;

public:
    StackType();
    ~StackType();
    void push(ItemType newItem);
    ItemType pop();
    void clear();

    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    void Print();
};




#endif
