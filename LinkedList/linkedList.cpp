#include <iostream>


template <typename T>
class linkedList{
private:
    struct Node{
        T data;
        Node* next;

        Node(const T& value){
            this->data = value;
            this->next = nullptr;
        };
    };

    Node* head;

public:
    linkedList(){
        head = nullptr;
    };

    void insertEnd(T dataElement){
        Node* newNode = new Node(dataElement);
    }


    ~linkedList();
};
