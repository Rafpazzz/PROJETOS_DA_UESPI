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

class Fila_sequncial2 {
    public:
        int erro = 0;
        int N;
        int primeiro;
        int ultimo;
        int elements[MAX];

        void criar() {
            N = 0;
            primeiro = 0;
            ultimo = 0;
        }

        void libera() {

        }

        int lenght() {
            return N;
        }

        int top() {
            erro = 0;
            if(N == 0){
                erro = 1;
                return -1;
            }

            return this->elements[primeiro];
        }

        void enqueue(int data) {
            erro = 0;
            if(N<MAX){
                elements[ultimo] = data;
                N++;
                ultimo++;
                if(ultimo == MAX){
                    ultimo = 0;
                }
            }else{
                erro = 1;
                return;
            }
        }

        int dequeue() {
            erro = 0;
            if(N>0) {
                int temp = elements[primeiro];
                primeiro++;
                if(primeiro == MAX) {
                    primeiro = 0;
                }
                N--;
                return temp;
            }

            erro = 1;
            return -1;
        }
    
    };

int main() {
    Fila_sequencial1 a;

    return 0;
}