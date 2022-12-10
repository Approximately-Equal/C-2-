#include <string>


template <typename T>
class Node {
    public:
        Node(T value_, Node parent_) {
            value = value_; 
            parent = parent_;
            left = nullptr;
            right = nullptr;
        }

        T getValue(){
            return value;
        }
        std::weak_ptr<Node> getParent(){
            return parent;
        }
        std::shared_ptr<Node> getLeft(){
            return left;
        }
        std::shared_ptr<Node> getRight(){
            return right;
        }

        void setValue(T value_){
            value = value_;
        }
        void setParent(Node parent_){
            parent = & parent_;
        }
        void setLeft(Node left_){
            left = & left_;
        }
        void setRight(Node right_){
            right = & right_;
        }
        

    private:
        std::unique_ptr<T> value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
};


class BinaryTree {
    public:
        BinaryTree() {
            root = NULL;
            elementsCount = 0;
        }
        BinaryTree(const BinaryTree & other) {
            root = other.getRoot()
        }

        Node* getRoot(){
            return root;
        }
        int getElementCount() {
            return elementCount;
        }
        void setRoot(Node node) {
            root = & node;
        }
        void setElementCount(int newCount){
            elementCount = newCount;
        }
        void incrementElementCount(){
            elementCount++;
        }

        void BinaryTreeFromList(Node array[], int arrayLength) {
            root = & array[0];
            for(int i = 1; i < arrayLength; i++) {
                Node insertionNode = array[i];
                Node comparisonNode = *root;
                while (true) {
                    if(insertionNode->value < comparisonNode->value) {
                        Node * nextNode = comparisonNode.getLeft();
                        if(nextNode == nullptr) {
                            comparisonNode.setLeft(insertionNode);
                            insertionNode.setParent(comparisonNode);
                        }
                        else {
                            comparisonNode = *nextNode;
                        }
                    }
                    else {
                        Node * nextNode = comparisonNode.getRight();
                        if(nextNode == nullptr) {
                            comparisonNode.setRight(insertionNode);
                            insertionNode.setParent(comparisonNode);
                        }
                        else {
                            comparisonNode = *nextNode;
                        }
                    }
                }
                this.incrementElementCount();
            }
        }

    private:
        Node* root;
        int elementCount;
};

