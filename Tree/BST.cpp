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

    void inOrderTraversal(Node* node, std::vector<T>& traversalVector){
        if(node == nullptr){
            return;
        }

        inOrderTraversal(node->left, traversalVector);
        traversalVector.push_back(node->data);
        inOrderTraversal(node->right, traversalVector);
    }

    void preOrderTraversal(Node* node, std::vector<T>& traversalVector){
        if(node == nullptr){
            return;
        }

        traversalVector.push_back(node->data);
        preOrderTraversal(node->left, traversalVector);
        preOrderTraversal(node->right, traversalVector);
    }

    void postOrderTraversal(Node* node, std::vector<T>& traversalVector){
        if(node == nullptr){
            return;
        }

        postOrderTraversal(node->left, traversalVector);
        postOrderTraversal(node->right, traversalVector);
        traversalVector.push_back(node->data);
    }

    void printTraversal(const std::vector<T>& traversalVector) {
        for (const T& value : traversalVector) {
            std::cout << value << '\n';
        }
    }

    public:

    enum class TraversalType{
        InOrder,
        PreOrder,
        PostOrder
    };

    void insert(const T& value){
        Node* newNode = new Node(value);
        Node* traversalNode = root;

        if(root == nullptr){
            root = newNode;
            return;
        }

        while (true)
        {
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

    std::vector<T> traverseBST(TraversalType type, bool print = false){
        switch (type)
        {
        case TraversalType::InOrder:
            return inOrderTraversal(print);

        case TraversalType::PreOrder:
            return preOrderTraversal(print);

        case TraversalType::PostOrder:
            return postOrderTraversal(print);

        default:
            std::cout << "\n" << "Invalid Traversal Type" << "\n";
            return {};
        }
    }

    std::vector<T> inOrderTraversal(bool print = false){
        std::vector<T> traversalVector;

        inOrderTraversal(root, traversalVector);

        if(print == true){
            printTraversal(traversalVector);
        }

        return traversalVector;
    }

    std::vector<T> preOrderTraversal(bool print = false){
        std::vector<T> traversalVector;

        preOrderTraversal(root, traversalVector);

        if(print == true){
            printTraversal(traversalVector);
        }

        return traversalVector;
    }

    std::vector<T> postOrderTraversal(bool print = false){
        std::vector<T> traversalVector;

        postOrderTraversal(root, traversalVector);

        if(print == true){
            printTraversal(traversalVector);
        }

        return traversalVector;
    }
};