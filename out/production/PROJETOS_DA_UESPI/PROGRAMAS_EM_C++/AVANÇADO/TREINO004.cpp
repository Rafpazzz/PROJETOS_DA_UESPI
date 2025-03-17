#include <iostream>
#include <string>

class Node{
    public:
        int value;
        Node *next;
};

class No{
    public:

    int valor;
    No* prox;
};

class listaEnc4{
    private: 
        No* primNo = nullptr;

    public:
    void inserirFinal(int num){
        No* noAtual = new No();
        noAtual -> valor = num;
        if(primNo == nullptr){
            primNo = noAtual;
        }else{
            No* bloco;
            bloco = primNo;
            while (bloco->prox != nullptr){
                bloco = bloco->prox;
            }
            bloco->prox = noAtual;
        }

    }

    void print(){
        No *percorre = primNo;
        while(percorre!=nullptr){
            std::cout<<percorre->valor<<std::endl;
            percorre = percorre->prox;
        }
    }

    No *getPrimNo(){
        return primNo;
    }
};

class Stack{
    public:
        int N;
        Node *ptr_top;
        int erro = 0;
        void initiaalizate(){
            this-> N = 0;
            this-> ptr_top = nullptr;
        }

        bool IsEmpty(){
            return this->ptr_top == nullptr;
        }

        void push(int data){
            erro = 0;
            Node *newNode = new Node();
            newNode->value = data;
            if(newNode == nullptr){
                std::cout<<"erro de inicializaCao";
                erro = 1;
            }
                newNode->next = this->ptr_top;
                this->ptr_top = newNode;
                N++;

        }

        int pop(){
            erro = 0;
            if(IsEmpty()){
                std::cout<<"Lista vazia";
                erro = 1;
            }
                Node *exit = ptr_top;
                int popedValue = exit->value;
                ptr_top = ptr_top->next;
                delete exit;
                return popedValue;
            
        }

        int length(){
            return this->N;
        }
        
        int top(){
            erro = 0;
            if(IsEmpty()){
                std::cout<<"Pilha vazia.";
                erro = 1;
            }
            return this->ptr_top->value;
        }

        void print(){
            Node *temp = ptr_top;
            while(temp!= nullptr){
                std::cout<<temp->value<<std::endl;
                temp = temp->next;
            }
        }

         void fibonacc(int p) {  
            int p1 = 0;
            int p2 = 1;
            int prox;
            push(p1);
            push(p2);
            for(int i = 2; i<p; i++) {
                prox = p1+p2;
                p1 = p2;
                p2 = prox;
                push(prox);

            }
         }

         void convercao_binario(int n) {
            int bi;
            while(n>0) {
                bi = n%2;
                n = n/2;
                push(bi);
            }
            
            
        }
};



int main(){
    Stack pilha;
    pilha.initiaalizate();
    pilha.convercao_binario(11);
    for(int i = 0; i<pilha.length(); i++) {
        std::cout<<pilha.pop();
    }
    
    
    return 0;
}