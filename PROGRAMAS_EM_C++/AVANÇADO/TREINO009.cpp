//TREINO PARA A PROVA DE ESTRUTURA DE DADOS QUE OCORRE NO DIA 08/11/2024

#include <iostream>

constexpr int MAX = 100;

class fila {
    int N;
    int erro;
    int elements[MAX];
    int primeiro;
    int ultimo;

    void criar() {
        N = 0;
        primeiro = 0;
        ultimo = 0;
    }

    bool isEmpty() {
        return N==0;
    }

    void enqueue(int dado) {
        erro = 0;
        if(N<MAX) {
            elements[ultimo] = dado;
            ultimo++;
            N++;
            if(ultimo == MAX) {
                ultimo = 0;
            }
        }else {
            erro = 1;
            return;
        }
    }

    int dequeue() {
        erro = 0;
        if(!isEmpty()) {
            int aux = elements[primeiro];
            primeiro++;
            N--;
            return aux;
        }else {
            erro = 1;
            return -1;
        }
    }

    int front() {
        return elements[primeiro];
    }
};