// chain node
//链表

#ifndef chainNode_
#define chainNode_

template<class T>
struct chainNode {
    // data members
    //数据成员
    T data;
    chainNode<T> *next;

    // methods
    //无参构造方法，int默认为0，指针默认为NULL
    chainNode() {}

    //一个参数的构造方法，int为入参，指针默认为NULL
    chainNode(const T &element) { this->data = element; }

    chainNode(const T &element, chainNode<T> *next) {
        this->data = element;
        this->next = next;
    }
};

#endif
