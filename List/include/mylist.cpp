/*#ifndef MYLIST_H
#define MYLIST_H
#include<stdexcept>
#include<iostream>
#include<memory>
using std::unique_ptr;


template<class T>
class MyList {
    protected:
    class Node {
        public:
        T data;
        std::unique_ptr<Node>  next;
        Node(): data(0), next(nullptr) {}
        Node(const T& d) : data(d), next(nullptr) {}
    };

protected:

        std::unique_ptr<Node> head;
        int _size;

    public:
        using value_type = T;
        MyList(int size = 0): _size{size}, head{nullptr}{}
        int size() const {return _size; };

    class Iterator:  public std::iterator<std::forward_iterator_tag, T>{
    private:
        Node *actual;

    public:
        using value_type = T;
        Iterator() noexcept :
                actual(nullptr) {}

        Iterator(std::unique_ptr<Node> const &node) noexcept :
                actual(node.get()) {};


        Iterator& operator=(Node* pNode) {
            this->actual = pNode;
            return *this;
        }
        T& operator*() const {
            return actual->data;
        }

        Node *getNode(){ return actual;};

        Iterator operator++(int) {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
        Iterator operator++() {
            if(actual == nullptr) throw std::out_of_range("list is empty");
            Iterator tmp = *this;
            actual = actual->next.get();
            return tmp;
        }

        bool operator!=(const Iterator& itr) const {
            return actual != itr.actual;
        }

        bool operator==(const Iterator& itr){
            return this->actual == itr.actual;
        }
    };
    Iterator begin() const{return Iterator(head);}

    Iterator end() const { return Iterator(); }


void push_front(const T& data);

        T pop_front();

        T front();


        void remove(T element);

         friend std::ostream& operator<<(std::ostream& out, MyList<T> &l){
        for( auto element: l){
            out<<element;
        }
        return out;
    }



};


template<class T>
void MyList<T> :: push_front(const T& data){
    std::unique_ptr<Node> tmp = std::make_unique<Node>(data);
    tmp.get()->next = std::move(head);
    head = std::move(tmp);
    _size++;
}

template<class T>
T MyList<T> :: pop_front(){
    if(head == nullptr){
        throw std::out_of_range("list is empty");
    }
    else{
        T element = head -> data;
        head = std::move(head->next);
        _size--;
        return element;
    }
}


template<class T>
T MyList<T> :: front(){
    if(head == nullptr){
        throw std::out_of_range("list is empty");
    }
    return head -> data;
}
template<class T>
void MyList<T> :: remove(T element){
    if(head == nullptr){
        throw std::out_of_range("list is empty");
    }
    Node *prev = nullptr;
    Iterator itr = MyList :: begin();
    Node *actual =  itr.getNode();
    while(itr != MyList::end()){
        if(actual -> data == element){
            if(prev == nullptr){
                head = std::move(head->next);
                actual =  prev;
                _size--;
            }
            else{
                prev -> next = std::move(actual-> next);
                actual = prev;
                _size--;
            }
        }
        itr++;
        prev = actual;
        actual=itr.getNode();
    }

}
#endif*/
