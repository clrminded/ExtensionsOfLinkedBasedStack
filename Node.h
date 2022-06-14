#ifndef HEADER_NODE
#define HEADER_NODE

template <class T>
class Node {
private:
    T item;
    Node<T>* next;

public:
    Node();
    Node(const T&);
    Node(const T&, Node<T>*);
    void setItem(const T&);
    T getItem() const;
    void setNext(Node<T>*);
    Node<T>* getNext() const;

};

/* default constructor of Node 
*/
template <class T>
Node<T>::Node() :next(nullptr) {}

/* constructor of item
* initilzing item
*/
template <class T>
Node<T>::Node(const T& _item) : item(_item), next(nullptr) {}

/* constructor with pram _item and _next  
* initilize next and item
*/
template <class T>
Node<T>::Node(const T& _item, Node<T>* _next) : item(_item), next(_next) {}

/* setter method
* sets the item to _item 
*/
template <class T>
void Node<T>::setItem(const T& _item) {
    item = _item;
}

/*setter method 
* sets the value for next* to _next 
*/
template <class T>
void Node<T>::setNext(Node<T>* _next) {
    next = _next;
}

/* getter method 
* return item 
*/
template <class T>
T Node<T>::getItem() const {
    return item;
}

/* getter method  
* returns next with the value type of node<T> 
*/
template <class T>
Node<T>* Node<T>::getNext() const {
    return next;
}

#endif