#include <iostream>
#include <vector>


template <typename T>
class linkedList{
private:

    // struct of node which contains the data to be stores, and the next pointer
    struct Node{
        T data;
        Node* next;

        Node(const T& dataElement){
            this->data = dataElement;
            next = nullptr;
        }
    };

    Node* head;

    // It stores the size of the linked list, not in most Linked List implementations
    int size = 0;

    
    //Allows you to search using index, first node is indexed 1
    Node* getNodeAtIndex(const index){
        
        if(index<=0){
            std::cout << "Index can't be negative or zero, index starts at one" << "\n";
            return nullptr;
        }

        if(index>size){
            std::cout << "Index is more than the size of the linked list " << "( " << size " > " << index << " )" << "\n";
            return nullptr;
        }
        
        Node* temp = nullptr;

        for(int i = 1; i < index; i++){
            // We are dereferncing temp, which is a pointer to a Node, then taking its address after
            // temp = (*temp).next;
            // Below code snippet, is the shorthand for the code above:
            temp = temp->next;
        }

        return temp;
    }


    Node* findOneNodeUsingKeyElement(const T keyDataToTraverseTo){
        Node* temp = head;
        for(int i = 1; i <= size; i++){
            if(temp->data == keyDataToTraverseTo){
                return temp;
            }
            temp = temp->next;
        }
        
        std::cout << "No element in the Linked List matches the key " << keyDataToTraverseTo << "\n";
        return nullptr;
    }

    std::vector<Node*> findAllNodesUsingKeyElement(const T keyDataToTraverseTo){
        
        std::vector<Node*> matches;

        Node* temp = head;
        for(int i = 1; i <=size; i++){
            if(temp->data == keyDataToTraverseTo){
                matches.push_back(temp);
            }
            temp = temp->next;
        }
        return matches;
    
    }


    

public:
    linkedList(){
        head = nullptr;
    };

    void insertEnd(T dataElement){ 
        Node* pointerToNewNode = new Node(dataElement); 
        
        if (head == nullptr){
            head = pointerToNewNode;
        }
        else{
            Node.next = pointerToNewNode;
        }

    } 


    ~linkedList(){

    };
};
