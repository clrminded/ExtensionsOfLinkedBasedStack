#ifndef HEADER_NODE
#define HEADER_NODE

/**
 * Templatizing the class to include any type that is include into the class.
 * Private item and next, so we make some getters and setters
 * We have 3 types of constructors
 */
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

/** 
 * Default constructor of Node 
 */
template <class T>
Node<T>::Node() :next(nullptr) {}

/** 
 * Constructor of item
 * @param: const _item white is just the data element, when constructing a Node like this
 * we will assume that the next pointer is pointing to a nullptr.
 * Fast initilzation of an item
 * We would use this when we are creating a head, or a new Node in a list
 */
template <class T>
Node<T>::Node(const T& _item) : item(_item), next(nullptr) {}

/** 
 * Constructor with param _item and _next  
 * initilize next and item
 */
template <class T>
Node<T>::Node(const T& _item, Node<T>* _next) : item(_item), next(_next) {}

/** 
 * Setter method
 * Sets the item to _item 
 */
template <class T>
void Node<T>::setItem(const T& _item) {
    item = _item;
}

/**
 * Setter method 
 * Sets the value for next* to _next 
 */
template <class T>
void Node<T>::setNext(Node<T>* _next) {
    next = _next;
}

/**
 * Getter method 
 * Return item 
 */
template <class T>
T Node<T>::getItem() const {
    return item;
}

/**
 * Getter method  
 * Returns next with the value type of node<T> 
 */
template <class T>
Node<T>* Node<T>::getNext() const {
    return next;
}

#endif