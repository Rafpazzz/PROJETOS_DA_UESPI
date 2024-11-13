#include <iostream>

class Node {
    public:
        Node *next;
        int value;
};

class Queue {
    public:
        int N;
        int erro;
        Node *ptr_top;
        Node *ptr_lest;

        void initilizate() {
            this->N = 0;
            this->ptr_top = nullptr;
            this->ptr_lest = nullptr;
            this->erro = 0;
        }

        bool IsEmpty() {
            return this->N == 0;
        }

        void Enqueue(int data) {
            Node *newData = new Node();
            newData->value = data;
            newData->next = nullptr;

            if(IsEmpty()) {
                ptr_top = newData;
                ptr_lest = newData;
            }

            ptr_lest->next = newData;
            ptr_lest = newData;
            N++;
        }

        int Dequeue() {
            erro = 0;
            if(!IsEmpty()) {
                Node *temp = ptr_top;
                int aux = temp->value;
                ptr_top = ptr_top->next;
                delete temp;
                return aux;
                N--;
            }

            erro = 1;
            return -1;
        }

        int top() {
            return this->ptr_top->value;
        }

        int Length() {
            return this->N;
        }
};

int main() {
    Queue p;
    p.initilizate();
    p.Enqueue(1);
    p.Enqueue(2);
    p.Enqueue(3);

    std::cout<<p.Length()<<std::endl;;
    std::cout<<p.top()<<std::endl;;
    std::cout<<p.Dequeue()<<std::endl;

    p.Enqueue(6);
    std::cout<<p.Length()<<std::endl;
    std::cout<<p.Dequeue()<<std::endl;

    return 0;
}