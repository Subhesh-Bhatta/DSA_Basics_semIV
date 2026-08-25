#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class linkedList{
private:

    // struct of node which contains the data to be stored, and the next pointer
    struct Node{
        T data;
        Node* next;

        Node(const T& dataElement){
            this->data = dataElement;
            next = nullptr;
        }
    };

    Node* head = nullptr;

    // It stores the size of the linked list, not in most Linked List implementations
    int size = 0;
    // Most functions I've made use a for loop till size for traversal, but you can
    // always just traverse using while loop till next is not nullPtr 

    
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
        //index 1 returns the value of head, which when dereferenced is the first Node
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
    linkedList(){};

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

        Node* addressAtIndex = getNodeAtIndex(index); 
        if(addressAtIndex == nullptr){
            throw std::out_of_range("No value at this index");
        }

        return addressAtIndex->data;
    }

    bool doesElementExist(const T& Element) const{
        return findOneNodeUsingKeyElement(Element)!=nullptr;
    }

    std::vector<int> returnIndexOfKeys(const T& key){

        Node* temp = head;
        std::vector<int> indices; 
        for(int i = 1; i <= size; i++ ){
            
            if(temp->data == key){
                indices.push_back(i);
            }
            temp = temp->next;


        }
        return indices;

    }

    int getSize() const{
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
            std::cout << "End is higher than size by" << end-size << " elements" << "\n";
            return;
        }
        else{
            int count = -1;
            Node* traverseNode = getNodeAtIndex(start);
            std::cout << start-1 << " elements... " << "\n";
            while(traverseNode!=nullptr && count <= end-start){
                
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
            std::cout << "\n" << " ..." << size-end << " elements." << "\n\n";
        }
    }

    void deleteByIndex(const int index){
        
        Node* toBeDeletedNode = getNodeAtIndex(index);
        if(toBeDeletedNode == nullptr){
            return;
        }
        
       if(index == 1){ 
            head = toBeDeletedNode->next;
        }
        else{
            Node* oneNodeBehindDeleted = getNodeAtIndex(index-1);
            oneNodeBehindDeleted->next = toBeDeletedNode->next;
        }
        delete toBeDeletedNode;
        size--;

    }
    
    // We are using template so, that we don't have to pass in number of items
    // in array as well
    template <size_t N>
    void deleteByIndices(int (&indices)[N]){

        // This algorithm adds traverses and changes the indices list for each deletion,
        // It decreases all the coming indices by one 
        // which are greater than the index we just deleted 
        // for(int i = 0; i < N; i++){
        //     deleteByIndex(indices[i]);
        //     deletionCount++;
        //     for(int j = i+1; j < N; j++){
        //         if(indices[i]<indices[j]){
        //             indices[j]--;
        //         }                
        //     }
        // }




    }

    void ReverseLL(){

        if (head == nullptr || head->next == nullptr) {
            return;
    }

        Node* tempPrev = head;
        Node* tempCurrent = tempPrev->next;
        Node* tempAhead = tempCurrent->next;

        while (tempAhead != nullptr){
            tempCurrent->next = tempPrev;
            tempPrev = tempCurrent;
            tempCurrent = tempAhead;
            tempAhead = tempAhead->next;
        } 

        tempCurrent->next = tempPrev;

        head->next = nullptr;
        head = tempCurrent;

    }

    ~linkedList(){
        Node* current = head;
        Node* next = nullptr;

        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;
        }
    }


};

int main(){

    linkedList<int> a;
    a.insertEnd(1);
    a.displayLL();

    a.insertEnd(2);
    a.displayLL();

    a.insertEnd(3);
    a.displayLL();
    a.ReverseLL();
    a.displayLL();
    
    linkedList<int> b;
    b.insertEnd(1);
    b.displayLL();

    b.insertEnd(2);
    b.displayLL();
    
    b.insertEnd(3);
    b.displayLL();
    
    b.insertEnd(4);
    b.displayLL();
    
    b.insertEnd(5);
    b.displayLL();
    
    b.ReverseLL();
    b.displayLL();
    
    linkedList<int> c;
    c.insertEnd(1);
    c.displayLL();
    
    c.insertEnd(2);
    c.displayLL();
    c.ReverseLL();
    c.displayLL();

    return 0;
}