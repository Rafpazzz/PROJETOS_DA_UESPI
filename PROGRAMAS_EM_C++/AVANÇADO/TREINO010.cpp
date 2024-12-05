#include <iostream>

constexpr int MAX = 10;

class Node {
    public: 
        char key;
        Node *left;
        Node *right;

        Node(char value) {
            key = value;
            left = nullptr;
            right = nullptr;
        }
};


    Node *insert(Node *root, char value) {
        if(root == nullptr) {
            return new Node(value);
        }

        if(root->left == nullptr) {
            root->left = insert(root->left, value);
        }else {
            root->right = insert(root->right, value);
        }

        return root;
    }

    void preOrdem(Node *no) {
        if(no) {
            std::cout<<no->key<<std::endl;
            preOrdem(no->left);
            preOrdem(no->right);
        }
    }



int main() {
    Node *raiz = nullptr;

    raiz=insert(raiz, 'A');
    raiz=insert(raiz, 'B');
    raiz=insert(raiz, 'C');
    raiz=insert(raiz, 'D');
    raiz=insert(raiz, 'E');
    raiz=insert(raiz, 'F');

    preOrdem(raiz);
    
    //r.preOrdem();
}