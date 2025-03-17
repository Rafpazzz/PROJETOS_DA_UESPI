//COMEÇO DO ESTUDO PAR FILAS ENCADEADAS

#include <iostream>

class Node {
    public:
        Node *next;
        int value;
};

class Fila_encadeada {
    public:
        int N;
        int erro;
        Node *ptr_first;
        Node *ptr_lest;

        void initializate() {
            N = 0;
            ptr_first = nullptr;
            ptr_lest = nullptr;
        }

        bool IsEmpty() {
            return this->N==0;
        }

        int length() {
            return this->N;
        }

        int top() {
            erro = 0;
            if(N == 0) {
                erro = 1;
                return -1;
            }

            return ptr_first->value;
        }

        void libera() {
            erro = 0;
            if(IsEmpty()) {
                erro = 1;
                return;
            }
            while(!IsEmpty()) {
                dequeue();
            }
        }

        void enqueue(int data) {
            erro = 0;
            Node *newNode = new Node();
            newNode->value = data;
            newNode->next = nullptr;
            if(N==0) {
                ptr_first = newNode;
                ptr_lest = newNode;
            }else {
                ptr_lest->next = newNode;
                ptr_lest = newNode;
            }
            N++;
        }

        int dequeue() {
            erro = 0;
            if(IsEmpty()) {
                erro = 1;
                return -1;
            }
            Node *temp = ptr_first;
            int aux = temp->value;
            ptr_first = ptr_first->next;
            delete temp;
            N--;
            return aux;

        }

        void fibonacc(int p) {  
            int p1 = 0;
            int p2 = 1;
            int prox;
            enqueue(p1);
            enqueue(p2);
            for(int i = 2; i<p; i++) {
                prox = p1+p2;
                p1 = p2;
                p2 = prox;
                enqueue(prox);

            }

        }

        void convercao_binario(int n) {
            int bi;
            while(n>0) {
                bi = n%2;
                n = n/2;
                enqueue(bi);
            }
        }
};

int main() {
    Fila_encadeada f;
    f.initializate();
    f.convercao_binario(10);
}