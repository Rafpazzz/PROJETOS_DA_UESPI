//TREINO PARA A PROVA DE ESTRUTURA DE DADOS QUE OCORRE NO DIA 08/11/2024

#include <iostream>

constexpr int MAX = 100;

class fila {
public:
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

    int lenght() {
        return N;
    }
};

class Stack {
public:
    int N;
    int erro;
    int elemnts[MAX];

    void criar() {
        N = 0;
    }

    int tamanho() {
        return N;
    }

    bool isEmpty() {
        return N == 0;
    }

    void push(int dado) {
        erro = 0;
        if(isEmpty()) {
            elemnts[N] = dado;
            N++;
        }else {
             erro = 1;
             return;
        }
    }

    int pop() {
        erro = 0;
        if(!isEmpty()) {
            int aux = elemnts[N-1];
            N--;
            return aux;
        }else {
            erro = 1;
            return -1;
        }
    }

    int top() {
        return elemnts[N-1];
    }

    std::string invert(std::string str) {
        Stack inverte;
        inverte.criar();
        for(int i = 0; i<str.length();i++) {
            inverte.push(str[i]);
        }
        for(int i = 0; i<str.length(); i++) {
            str[i] = inverte.pop();
        }

        return str;
    }

    bool verifica(std::string expressao) {
        Stack verifica;
        verifica.criar();
        for(int i = 0; i<expressao.length(); i++) {
            verifica.push(expressao[i]);
        }
        int verifica_parentese = 0;
        for(int i = 0; i<expressao.length(); i++) {
            switch(verifica.pop()) {
                case '(':
                    verifica_parentese++;
                    break;
                case ')':
                    verifica_parentese++;
                    break;
                case '[':
                    verifica_parentese++;
                    break;
                case ']':
                    verifica_parentese++;
                    break;
                case '{':
                    verifica_parentese++;
                    break;
                case '}':
                    verifica_parentese++;
                    break;
            }
        }

        if(verifica_parentese%2 == 0) {
            return true;
        }else {
            return false;
        }
    }

    bool verifica_balanceamento(std::string expressao) {
        Stack verifica;
        verifica.criar();
        for(int i = 0; i<expressao.length(); i++) {
            char ch = expressao[i];

            if(ch == '(' || ch == '[' || ch == '{') {
                verifica.push(ch);
            }else if(ch == ')' || ch == ']' || ch == '}') { 
                if(verifica.isEmpty()){
                    return false;
                }
            

                char topo = verifica.pop();

                if(ch == '(' && topo == ')' || ch == '[' && topo == ']' || ch == '{' && topo == '}') {
                    return false;
                }
            }
        }

        return verifica.isEmpty();
    }

    void invete_fila(fila &fila) {
        Stack inverte;
        inverte.criar();
        int tam = fila.lenght();
        for(int i = 0; i<tam; i++) {
            inverte.push(fila.dequeue());
        }
        for(int i = 0; i<tam; i++) {
            fila.enqueue(inverte.pop());
        }

        for(int i = 0; i<tam;  i++) {
            int elemento = fila.dequeue();
            std::cout<<elemento<<std::endl;
            fila.enqueue(elemento);
        }

    }
};

int main() {
    Stack p;
    fila a;

    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);

    p.invete_fila(a);
}

