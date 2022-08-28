// linked implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
/*
 * 线性表的链表实现
 * */

#ifndef chain_
#define chain_

#include<iostream>
#include<sstream>
#include<string>
#include "../virtual/linearList.h"
#include "chainNode.h"
#include "../exceptions/myExceptions.h"

using namespace std;

class linkedDigraph;

template<class T>
class linkedWDigraph;

//类模版
template<class T>
class chain : public linearList<T> {
    friend linkedDigraph;
    friend linkedWDigraph<int>;
    friend linkedWDigraph<float>;
    friend linkedWDigraph<double>;
public:
    // constructor, copy constructor and destructor
    chain(int initialCapacity = 10);

    chain(const chain<T> &);

    ~chain();

    // ADT methods
    bool empty() const { return listSize == 0; }

    int size() const { return listSize; }

    T &get(int theIndex) const;

    int indexOf(const T &theElement) const;

    void erase(int theIndex);

    void insert(int theIndex, const T &theElement);

    void output(ostream &out) const;

protected:
    // throw illegalIndex if theIndex invalid
    void checkIndex(int theIndex) const;

    // pointer to first node in chain
    //指向链表第一个节点的指针
    chainNode<T> *firstNode;

    // number of elements in list
    //线性表的元素个数
    int listSize;
};

template<class T>
chain<T>::chain(int initialCapacity) {// Constructor.
    //构造函数
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

/*
 * 复制构造函数
 * 注意不要用头节点去遍历链表，要用临时指针sourceNode和targetNode
 * */
// Copy constructor.
template<class T>
chain<T>::chain(const chain<T> &theList) {
    listSize = theList.listSize;

    // theList is empty
    //链表为空
    if (listSize == 0) {
        firstNode = NULL;
        return;
    }

    // non-empty list
    //链表非空
    chainNode<T> *sourceNode = theList.firstNode;
    // node in theList to copy from
    //复制链表theList的节点
    firstNode = new chainNode<T>(sourceNode->data);
    // copy first data of theList
    //复制链表的首元素
    sourceNode = sourceNode->next;
    chainNode<T> *targetNode = this->firstNode;
    // current last node in *this
    //当前列表的最后一个节点
    while (sourceNode != NULL) {// copy remaining elements
        targetNode->next = new chainNode<T>(sourceNode->data);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL; // end the chain
}

template<class T>
chain<T>::~chain() {// Chain destructor. Delete all nodes in chain.
    chainNode<T> *nextNode;
    //析构函数，重点在于用临时指针保存下一个结点的位置
    // 否则删除当前结点后，就没办法继续删除下一个了
    while (firstNode != NULL) {// delete firstNode
        nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
void chain<T>::checkIndex(int theIndex) const {// Verify that theIndex is between 0 and listSize - 1.
    //检查索引是否有效
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

}

template<class T>
T &chain<T>::get(int theIndex) const {// Return data whose index is theIndex.
    // Throw illegalIndex exception if no such data.
    checkIndex(theIndex);

    // move to desired node
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->data;
}

template<class T>
int chain<T>::indexOf(const T &theElement) const {// Return index of first occurrence of theElement.
    // Return -1 if theElement not in list.

    // search the chain for theElement
    chainNode<T> *currentNode = firstNode;
    int index = 0;  // index of currentNode
    while (currentNode != NULL &&
           currentNode->data != theElement) {
        // move to next node
        currentNode = currentNode->next;
        index++;
    }

    // make sure we found matching data
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template<class T>
void chain<T>::erase(int theIndex) {// Delete the data whose index is theIndex.
    // Throw illegalIndex exception if no such data.
    checkIndex(theIndex);

    // valid index, locate node with data to delete
    chainNode<T> *deleteNode;
    if (theIndex == 0) {// remove first node from chain
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {  // use p to get to predecessor of desired node
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next; // remove deleteNode from chain
    }
    listSize--;
    delete deleteNode;
}

// Insert theElement so that its index is theIndex.
/*
 * 这个实现要求插入的索引值是在链表长度的限制中
 * 即想给一个只有5个元素的链表插入时，只能用insert(5,new chainNode)尾插元素
 * */
template<class T>
void chain<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {// invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == 0)
        // insert at front
        firstNode = new chainNode<T>(theElement, firstNode);
    else {  // find predecessor of new data
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        // insert after p
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template<class T>
void chain<T>::output(ostream &out) const {// Put the list into the stream out.
    for (chainNode<T> *currentNode = firstNode;
         currentNode != NULL;
         currentNode = currentNode->next) {
        out << currentNode->data << "  ";
    }
}

// overload <<
template<class T>
ostream &operator<<(ostream &out, const chain<T> &x) {
    x.output(out);
    return out;
}

#endif
