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

        int initializate() {
            N = 0;
            ptr_first = nullptr;
            ptr_lest = nullptr;
        }

        bool IsEmpty() {
            this->N==0;
        }

        int lenght() {
            return this->N;
        }

        int top() {
            erro == 0;
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
            if(IsEmpty()) {
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
            if(IsEmpty) {
                erro = 1;
                return -1;
            }
            Node *aux = ptr_first;
            int temp = aux->value;
            ptr_first = ptr_first->next;
            delete aux;
            N--;
            return temp;

        }
};