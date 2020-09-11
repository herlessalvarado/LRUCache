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
    Node<T>* begin(){
        return head;
    }
    Node<T>* end(){
        return tail;
    }
    T front(){
        return head->data;
    }
    T back(){
        return tail->data;
    }
    void push_front(T data){
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
    void pop_back(){
        if(tail == nullptr) return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        else head = nullptr;
        free(temp);
        return;
    }
    void erase(Node<T>* elem){
        if(head == nullptr) return;
        if(head == elem) head = elem->next;
        if(elem->next != nullptr) elem->next->prev = elem->prev;
        if(elem->prev != nullptr) elem->prev->next = elem->next;
        free(elem);
        return;
    }
};

#endif