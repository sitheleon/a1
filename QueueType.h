//
//  QueueType.h
//  Lab04
//
//  Modified by Jeman Park on 2025/04/15.
//


#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType {
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class QueueType
{

private:
    NodeType<ItemType>* pFront;
    NodeType<ItemType>* pRear;

public:

    QueueType();
    ~QueueType();

    void clear();
    void enqueue(ItemType newItem);
    void dequeue(ItemType& value);

    int size() const;
    bool isFull() const;
    bool isEmpty() const;

    int squareSum();

    void Print();

};


template <class ItemType>
QueueType<ItemType>::QueueType()
{
    pFront = nullptr;
    pRear = nullptr;
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    /* Implement the function here (Lab 04-2)*/
    // This destructor function iteratively deletes all nodes in the queue.
    // All "NodeType" should be "deallocated" properly.
    // It returns nothing

    NodeType<ItemType>* tempPtr = pFront;

    while (tempPtr != nullptr)
    {
        pFront = pFront->next;

        delete tempPtr;

        tempPtr = pFront;
    }

    pRear = nullptr;

}

template <class ItemType>
void QueueType<ItemType>::clear()
{
    this -> ~QueueType();
}

template <class ItemType>
int QueueType<ItemType>::size() const
{
    /* Implement the function here (Lab 04-2)*/
    // This function counts the number of nodes in the queue and returns it.

    NodeType<ItemType>* tempPtr = pFront;
    int length = 0;

    while (tempPtr != nullptr) // 큐가 empty 할 때 까지 , 결론적으로 마지막 Rear의 next, 즉 tempPtr에 들어간 값이 nullptr이 될 것임.
    {
        length++;
        tempPtr = tempPtr->next;
    }

    return length;
}


template <class ItemType>
bool QueueType<ItemType>::isEmpty() const
{
    return (pFront == nullptr);
}

template <class ItemType>
bool QueueType<ItemType>::isFull() const
{
    NodeType<ItemType>* newNode;
    try {
        newNode = new NodeType<ItemType>;
        delete newNode;
        return false;
    }
    catch (std::bad_alloc exception) {
        return true;
    }
}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType newItem)
{
    /* Implement the function here (Lab 04-2)*/
    // This function enqueues "newItem" into the queue, and returns NOTHING.
    // If the queue is already full, do nothing.

    if (isFull())
    {
        cout << "<< QUEUE FULL >>" << endl;
    } // exception?

    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>;

    //NodeType<ItemType>* TempNode;

        //TempNode = pRear;

    newNode->value = newItem;

    newNode->next = nullptr;

    if (!isEmpty())
    {
        pRear->next = newNode;
    }
    else if (isEmpty())
    {
        pFront = newNode;
    }
    pRear = newNode;
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType& ret_value)
{

    /* Implement the function here (Lab 04-2)*/
    // This function dequeues the most front item in the queue, and returns it through "RETURN BY REFERENCE (ret_value).
    // You need to set "ret_value" as the dequeue item's value to return.
    // If the queue is empty, set "ret_value" as -1
    if (isEmpty())
    {
        //cout << endl;
        //cout << "EMPTY QUEUE NOW" << endl;
        pRear = nullptr; // 위에서 (큐의 pFront였던 큐의 첫` 요소.) TempPtr을 해제시켜버리면 pRear 포인터 변수가 가리키는 곳이 없어져서 메모리 누수 발생
        ret_value = -1;

        return;
    }



    NodeType<ItemType>* TempPtr;

    TempPtr = pFront;
    cout << endl;
    cout << "front: " << pFront->value << endl;

    pFront = pFront->next;
    // 이 시점에서,
    if (pFront == nullptr) //후론트가 nullptr인 경우는 지금 dequeue할 놈이 하나 남은 것. 그것의 next 포인터변수가 가리킬 곳 없어서.
    {
        // 여기서 뭐해야하나...
        // cout << "FRONT NULLPTR" << endl;

        ret_value = TempPtr->value;

        //cout << "ret:   " << ret_value << endl;

       // Print();

        return;
    }

    // cout << "후론트 다음 값: " << pFront->value << endl;

    ret_value = TempPtr->value;

    delete(TempPtr); // TempPtr이 가리키는 곳을 삭제 + 메모리 해제 -> 큐의 pFront였던 큐의 첫 요소. !!!!!!!!!!!! POP !!!!!!!!!!!!!!!!!!!


    //cout << "ret:   " << ret_value << endl;

    Print();
}


template <class ItemType>
int QueueType<ItemType>::squareSum()
{

    /* Implement the function here (Lab 04-3)*/
    // This function returns "the sum of squared values" in the queue


    if (isEmpty())
    {
        return 0;
    }

    int Sum = 0;

    int temp = 0;

    while (!isEmpty())
    {
        ItemType a;

        dequeue(a);

        temp = a;

        temp *= temp;

        Sum += temp;
    }







    return Sum;

}


template <class ItemType>
void QueueType<ItemType>::Print() {
    if (isEmpty()) {
        cout << "[EMPTY QUEUE]" << endl;
        return;
    }

    cout << "(front)\t[";
    NodeType<ItemType>* tempPtr = pFront;

    while (tempPtr != nullptr) {
        cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    cout << "]\t(rear)" << endl;
}



#endif /* QUEUETYPE_H */
