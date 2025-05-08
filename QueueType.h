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

    while (tempPtr != nullptr) // ť�� empty �� �� ���� , ��������� ������ Rear�� next, �� tempPtr�� �� ���� nullptr�� �� ����.
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
        pRear = nullptr; // ������ (ť�� pFront���� ť�� ù` ���.) TempPtr�� �������ѹ����� pRear ������ ������ ����Ű�� ���� �������� �޸� ���� �߻�
        ret_value = -1;

        return;
    }



    NodeType<ItemType>* TempPtr;

    TempPtr = pFront;
    cout << endl;
    cout << "front: " << pFront->value << endl;

    pFront = pFront->next;
    // �� ��������,
    if (pFront == nullptr) //�ķ�Ʈ�� nullptr�� ���� ���� dequeue�� ���� �ϳ� ���� ��. �װ��� next �����ͺ����� ����ų �� ���.
    {
        // ���⼭ ���ؾ��ϳ�...
        // cout << "FRONT NULLPTR" << endl;

        ret_value = TempPtr->value;

        //cout << "ret:   " << ret_value << endl;

       // Print();

        return;
    }

    // cout << "�ķ�Ʈ ���� ��: " << pFront->value << endl;

    ret_value = TempPtr->value;

    delete(TempPtr); // TempPtr�� ����Ű�� ���� ���� + �޸� ���� -> ť�� pFront���� ť�� ù ���. !!!!!!!!!!!! POP !!!!!!!!!!!!!!!!!!!


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
