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
    Node* getNodeAtIndex(const int index){
        
        if(index<=0){
            std::cout << "Index can't be negative or zero, index starts at one" << "\n";
            return nullptr;
        }

        if(index>size){
            std::cout << "Index is more than the size of the linked list " << "( " << size << " > " << index << " )" << "\n";
            return nullptr;
        }
        
        Node* temp = head;

        for(int i = 1; i < index; i++){
            // We are dereferncing temp, which is a pointer to a Node, then taking its address after
            // temp = (*temp).next;
            // Below code snippet, is the shorthand for the code above:
            temp = temp->next;
        }

        return temp;
    }


    Node* findOneNodeUsingKeyElement(const T& keyDataToTraverseTo){
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

    std::vector<Node*> findAllNodesUsingKeyElement(const T& keyDataToTraverseTo){
        
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

    void insertEnd(const T& dataElement){ 
        Node* pointerToNewNode = new Node(dataElement); 
        
        if (head == nullptr){
            head = pointerToNewNode;
        }
        else{
            getNodeAtIndex(size)->next = pointerToNewNode;
        }
        size++;

    } 

    void insertStart(const T& dataElement){
        Node* pointertoNewNode = new Node(dataElement);
        if(head == nullptr){
            head = pointertoNewNode;
        }
        else{
            Node* temp = head;
            head = pointertoNewNode;
            pointertoNewNode->next = temp;
        }
        size++;
    }

    T getElementAtIndex(int index){
        return getNodeAtIndex(index)->data;
    }

    bool doesElementExist(T Element){
        return findOneNodeUsingKeyElement(Element)!=nullptr;
    }

    int getSize(){
        return size;
    }

    void displayLL(int start = 1, int end = -1, int NewLine = 5){
        // we're doing this instead of making int end = size a default parameter,
        // this is because C++ compiler tries to determine what 'size' is when this
        // function is declared, which is right now, and currently it doesn't know the 
        // exact value of size, because it doesn't know which linked list object is 
        // calling it, it only knows the actual size at runtime, when a particular object
        // calls it
        if(end==-1){
            end = size;
        }
        if(size == 0){
            std::cout << "Linked list is empty" << "\n";
            return;
        }
        else if (start>size)
        {
            std::cout << "Start is higher than size by" << start-size << " elements" << "\n";
            return;
        }
        else if (end>size){
            std::cout << "Start is higher than size by" << start-size << " elements" << "\n";
            return;
        }
        else{
            int count = -1;
            Node* traverseNode = getNodeAtIndex(start);
            std::cout << start-1 << " elemnts... " << "\n";
            while(traverseNode!=nullptr && count < end-start){
                
                if(count%NewLine==0){
                    std::cout << "\n";
                    count = 0;
                }

                if(count==-1){
                    std::cout << traverseNode->data;
                    count = 1;
                    traverseNode = traverseNode->next;
                    continue;
                }

                std::cout << " -> "<< traverseNode->data;
                
                count++;
                traverseNode = traverseNode->next;


            }
            std::cout << " ..." << size-end << " elements." << "\n";
    }


    ~linkedList(){
        continue;
    };
};


int main(){


    return 0;
}