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

    Node* deleteHelper(Node* node, T value){
        
        if(node == nullptr){
            return nullptr;
        }

        if(value > node->data){
            node->right = deleteHelper(node->right, value);
        }
        else if(value < node->data ){
            node->left = deleteHelper(node->left, value);
        }
        else{

            if(node->left == nullptr){
                Node* successor = node->right;
                delete node;
                return successor;
                
            }

            else if(node->right == nullptr){
                Node* successor = node->left;
                delete node;
                return successor;
            }

            else{
                Node* inOrderSuccessor = node->right;
                while(inOrderSuccessor->left!=nullptr){
                    inOrderSuccessor = inOrderSuccessor->left;
                }

                node->data = inOrderSuccessor->data;
                
                node->right = deleteHelper(node->right, inOrderSuccessor->data);

                return node;

            }

        }
        return node;

    }

    
    //Just a naive and brute force approach for deleting node, explains 
    //what needs to be done better however, so keeping this as a comment

    // void deleteHelper(Node*& rootNode, const T& value) {

    //     Node* behindTraversal = nullptr;
    //     Node* currentTraversal = rootNode;
    //     bool isLeft = false;

    //     while (currentTraversal != nullptr) {

    //         if (value < currentTraversal->data) {

    //             behindTraversal = currentTraversal;
    //             currentTraversal = currentTraversal->left;
    //             isLeft = true;
    //         }

    //         else if (value > currentTraversal->data) {

    //             behindTraversal = currentTraversal;
    //             currentTraversal = currentTraversal->right;
    //             isLeft = false;
    //         }

    //         //Node found
    //         else {

    //             if (currentTraversal->left == nullptr &&
    //                 currentTraversal->right == nullptr) {

    //                 if (behindTraversal == nullptr) {
    //                     rootNode = nullptr;
    //                 }
    //                 else if (isLeft) {
    //                     behindTraversal->left = nullptr;
    //                 }
    //                 else {
    //                     behindTraversal->right = nullptr;
    //                 }

    //                 delete currentTraversal;
    //                 return;
    //             }

    //             else if (currentTraversal->left != nullptr &&
    //                     currentTraversal->right == nullptr) {

    //                 if (behindTraversal == nullptr) {
    //                     rootNode = currentTraversal->left;
    //                 }
    //                 else if (isLeft) {
    //                     behindTraversal->left = currentTraversal->left;
    //                 }
    //                 else {
    //                     behindTraversal->right = currentTraversal->left;
    //                 }

    //                 delete currentTraversal;
    //                 return;
    //             }

    //             else if (currentTraversal->left == nullptr &&
    //                     currentTraversal->right != nullptr) {

    //                 if (behindTraversal == nullptr) {
    //                     rootNode = currentTraversal->right;
    //                 }
    //                 else if (isLeft) {
    //                     behindTraversal->left = currentTraversal->right;
    //                 }
    //                 else {
    //                     behindTraversal->right = currentTraversal->right;
    //                 }

    //                 delete currentTraversal;
    //                 return;
    //             }

    //             else {

    //                 Node* successor = currentTraversal->right;

    //                 while (successor->left != nullptr) {
    //                     successor = successor->left;
    //                 }

    //                 currentTraversal->data = successor->data;

    //                 Node* successorParent = currentTraversal;
    //                 Node* successorTraversal = currentTraversal->right;

    //                 while (successorTraversal != successor) {
    //                     successorParent = successorTraversal;
    //                     successorTraversal = successorTraversal->left;
    //                 }

    //                 if (successorParent->left == successor) {
    //                     successorParent->left = successor->right;
    //                 }
    //                 else {
    //                     successorParent->right = successor->right;
    //                 }

    //                 delete successor;
    //                 return;
    //             }
    //         }
    //     }

    //     std::cout << "Value doesn't exist\n";
    // }
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
            
            else if (value > traversalNode->data)
            {
                if(traversalNode->right == nullptr){
                    traversalNode->right = newNode;
                    return;
                }

                traversalNode = traversalNode->right;
            }
            else{
                std::cout << "Duplicate value";
                return;
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

    // can also be used to print a sorted array
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

    void deleteValue(const T& value) {
        Node* root = deleteHelper(root, value);
    }



};

int main() {



    return 0;
}