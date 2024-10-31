//Codigo de filas sequencial

#include <iostream>

constexpr int MAX = 10;

class Fila_sequencial1 {
    public:
        int N;
        int erro;
        int elements[MAX];

        void criar(){
            N = 0;
            erro = 0;
        }

        void libera() {

        }

        bool IsEmpty() {
            if(N == 0) {
                return true;
            }
            return false;
        }

        void enqueue(int data) {
            erro = 0;
            if(N >= MAX) {
                erro = 0;
                return;
            }
            elements[N] = data;
            N++;
        }

        int dequeue() {
            erro = 0;
            if(IsEmpty()) {
                erro = 0;
                std::cout<<"Fila ja vazia";
                return -1;
            }
            int temp = elements[N];
            N--;
            return temp;
        }

        int first() {
            erro = 0;
            if(IsEmpty()){
                erro = 1;
                return -1;
            }
            return this->elements[0];
        }


};

int main() {
    Fila_sequencial1 a;

    return 0;
}