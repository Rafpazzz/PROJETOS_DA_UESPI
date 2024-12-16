#include <iostream>

constexpr int MAX = 10;

class Heap {
    int elemrnt[MAX];
    int n;

    void criar() {
        this->n = 0;
    }

    void libera() {}

    int frente() {
        return this->elemrnt[0];
    }

    int pai(int pos) {
        return(pos-1)/2;
    }

    int filhoesq(int pos) {
        return(2*pos)+1;
    }

    int filhodir(int pos) {
        return filhoesq(pos)+1;
    }

    void sobe(int pos) {
        int m_pai = pai(pos);
        while(pos>0) {
            if(elemrnt[pos]>=elemrnt[m_pai])
            break;
            //trocar(m_pai,pos,elemrnt);
            pos = m_pai;
            m_pai = pai(pos);
        }
    }

    void deeesce(int pos) {
        int f = filhoesq(pos);
        while(f<n) {
            if((f<n-1) && elemrnt[f+1]<elemrnt[f]) {
                f = f+1;
            }
            if(elemrnt[f]>=elemrnt[pos])
            break;
            //troca(f, pos, elemrnt);
            pos=f;
            f = filhoesq(pos);
        }
    }
};

/*class Node {
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
}*/