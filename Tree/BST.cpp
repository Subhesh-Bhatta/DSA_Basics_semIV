#include <iostream>
#include <vector>

template <typename T>
class BST{
    private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(const T& value){
            this->data = value;
            this->left = nullptr;
            this->right = nullptr;
        }

    };

    Node* root = nullptr; 
    
    public:

    void insert(const T& value){
        Node* newNode = new Node(value);
        Node* traversalNode = root;
        while (true)
        {
            if(root == nullptr){
                root = newNode;
                return;
            }
            if(value < traversalNode->data){
                if(traversalNode->left == nullptr){
                    traversalNode->left = newNode;
                    return;
                }
                traversalNode = traversalNode->left;
            }
            else{
                if(traversalNode->right == nullptr){
                    traversalNode->right = newNode;
                    return;
                }
                traversalNode = traversalNode->right;
            }
        }
    }

    std::vector<T>
    



};