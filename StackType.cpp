//
//  StackType.cpp
//  Lab04
//
//  Modified by Jeman Park on 2025/04/15.
//

#include "StackType.h"


StackType::StackType()
{
    topPtr = nullptr;
}

StackType::~StackType()
{
    /* Implement the function here */
    // This destructor function iteratively deletes all nodes in the stack.
    // All "NodeType" should be "deallocated" properly.
    // It returns nothing

    NodeType* tempPtr = topPtr;

    while (tempPtr != nullptr)
    {
        topPtr = topPtr->next;
        delete tempPtr;
        tempPtr = topPtr;

    }
}


void StackType::clear() {
    this->~StackType();
}

bool StackType::isEmpty() const
{

    return (topPtr == nullptr);

}


bool StackType::isFull() const
{
    NodeType* newNode;
    try {
        newNode = new NodeType;
        delete newNode;
        return false;
    }
    catch (std::bad_alloc exception) {
        return true;
    }
}

int StackType::size() const
{
    /* Implement the function here */
    // This function counts the number of nodes in the stack and returns it.

    NodeType* tempPtr = topPtr;
    int length = 0;

    while (tempPtr != nullptr)
    {
        length++;
        tempPtr = tempPtr->next;
        // 스택의 끝에서 결국 널 포인터를 가리키게 될 것임
    }

    return length;
}

void StackType::push(ItemType newItem)
{
    /* Implement the function here */
    // This function pushes "newItem" into the stack, and returns NOTHING.
    // If the stack is already full, do nothing.

    try
    {
        isFull();
    }
    catch (exception)
    {
        cout << "   EXCEPTION   " << endl;
    };

    NodeType* newNode;
    newNode = new NodeType;

    newNode->value = newItem;

    newNode->next = topPtr; // 그 전의 top 요소로 만든다.

    topPtr = newNode; // topPtr은 이제 막 스택에 넣은 newNode를 가리키게 한다.    
}

ItemType StackType::pop()
{
    /* Implement the function here */
    // This function pops the item at the top of the stack, and returns it.
    // It should deallocate the popped node.
    // If the stack is EMPTY, it returns -1.



    NodeType* tempPtr;
    tempPtr = topPtr;

    topPtr = topPtr->next; // 가장 위에 있는 노드 다음의 노드를 가리키게 (pop이후엔 얘가 이제 top이니까)

    NodeType* ResultNode = tempPtr;

    ItemType Result = ResultNode->value;

    delete(tempPtr); // tempPtr이 가리키는 노드를 제거한다. + 메모리 해제까지



    if (isEmpty())
    {
        return -1;
    }


    return Result;
}


void StackType::Print() {
    if (isEmpty()) {
        cout << "[EMPTY STACK]" << endl;
        return;
    }

    cout << "(top)\t";
    NodeType* tempPtr = topPtr;

    while (tempPtr != nullptr) {
        cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }

    cout << " ] " << endl;

}
