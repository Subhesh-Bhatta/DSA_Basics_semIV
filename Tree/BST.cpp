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

    // to track if the BST is a mirrored BST or not
    // doesn't change any of the function implementation currently, so be
    // careful when using it
    bool mirrored = false;

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

    Node* searchElementinBST(Node* node, const T& value){
        if(node == nullptr || node->data == value){
            return node;
        }
        if (node->data < value){
            return searchElementinBST(node->left, value);
        }
        else{
            return searchElementinBST(node->right, value);
        }
    }

    int heightOfBST(Node* node){
        if(node == nullptr){
            return -1;
        }
        return 1 + std::max(heightOfBST(node->left), heightOfBST(node->right));
    }

    int numberOfNodes(Node* node){
        if(node == nullptr){
            return 0;
        }
        return 1 + numberOfNodes(node->left) + numberOfNodes(node->right);
    }

    void mirrorBSTHelper(Node* newTreeNode, Node* nonMirroredTreeNode){
        
        if(nonMirroredTreeNode == nullptr){
            return;
        }
        if(nonMirroredTreeNode->right != nullptr){
            newTreeNode->left = new Node(nonMirroredTreeNode->right->data);
        }
        if(nonMirroredTreeNode->left != nullptr){
            newTreeNode->right= new Node(nonMirroredTreeNode->left->data);
        }


        mirrorBSTHelper(newTreeNode->left, nonMirroredTreeNode->right);
        mirrorBSTHelper(newTreeNode->right, nonMirroredTreeNode->left);

    }

    public:

    
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
    

    enum class TraversalType{
        InOrder,
        PreOrder,
        PostOrder
    };

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

    bool searchElementinBST(T data){
        
        if(searchElementinBST(root, data) != nullptr){
            std::cout << "Element is in BST";
            return true;
        }
        std::cout << "Element is not in BST";
        return false;
        
    }

    int heightOfBST(){
        return heightOfBST(root);
    }

    int numberOfNodes(){
        return numberOfNodes(root);
    }

    BST<T>* createMirrorBST(){
        BST<T>* newTree = new BST<T>();

        if(root==nullptr){
            return newTree;
        }

        newTree->root = new Node(root->data);
        newTree->mirrored = true;

        mirrorBSTHelper(newTree->root, root);

        return newTree;
    }

    bool isMirror() const{
        return mirrored;
    }

};