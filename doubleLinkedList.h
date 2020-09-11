#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template<class T>
class Node{
public:
    T data;
    Node* next;
    Node* prev;
};

template<class T>
class DoubleLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Node<T>* begin();
    Node<T>* end();
    T front();
    T back();
    void push_front(T data);
    void pop_back();
    void erase(Node<T>* elem);
};

template<class T>
Node<T>* DoubleLinkedList<T>::begin(){
    return head;
}

template<class T>
Node<T>* DoubleLinkedList<T>::end(){
    return tail;
}

template<class T>
T DoubleLinkedList<T>::front(){
    return head->data;
}

template<class T>
T DoubleLinkedList<T>::back(){
    return tail->data;
}

template<class T>
void DoubleLinkedList<T>::push_front(T data){
    Node<T>* temp = new Node<T>();
    temp->data = data;
    temp->prev = nullptr;
    temp->next = head;
    if(head != nullptr){
        head->prev = temp;
    }else{
        tail = temp;
    }
    head = temp;
}

template<class T>
void DoubleLinkedList<T>::pop_back(){
    if(tail == nullptr) return;
    Node<T>* temp = tail;
    tail = tail->prev;
    if(tail) tail->next = nullptr;
    else head = nullptr;
    free(temp);
    return;
}

template<class T>
void DoubleLinkedList<T>::erase(Node<T>* elem){
    if(head == nullptr) return;
    if(head == elem) head = elem->next;
    if(elem->next != nullptr) elem->next->prev = elem->prev;
    if(elem->prev != nullptr) elem->prev->next = elem->next;
    free(elem);
    return;
}

#endif