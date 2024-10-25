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
        Node *ptr_top;
        int erro = 0;
        void initiaalizate(){
            this-> ptr_top = nullptr;
        }

        bool IsEmpty(){
            return this->ptr_top == nullptr;
        }

        void push(int data){
            Node *newNode = new Node();
            newNode->value = data;
            if(newNode == nullptr){
                std::cout<<"erro de inicializaCao";
                erro = 1;
            }
                newNode->value = data;
                newNode->next = this->ptr_top;
                this->ptr_top = newNode;

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
            erro = 0;
            int tam = 0;
            if(IsEmpty()){
                erro = 1;
                return -1;
            }
            while(!IsEmpty()){
                tam++;
            }
            return tam;
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

       void tornaBinario(Stack* pilha){
            erro = 0;
            int j = pilha->length();
            if(pilha->IsEmpty()){
                std::cout<<"pilh vazia";
                erro = 1;
            }
            Stack transform;
            transform.initiaalizate();
            int rest;
            int num;

            while(!pilha->IsEmpty()){
                num = pilha->pop();
            }

            do{
                rest = num%2;
                transform.push(rest);
                num = num/2;
            }while(num>0);

            for(int i =0; i<j;i++)
            pilha->push(transform.pop());
        }

        void torcaPilha(listaEnc4 *list){
            erro = 0;
            if(IsEmpty()){
                erro = 1;
                return;
            }
            Stack pilhaNew;
            pilhaNew.initiaalizate();
            No *temp = list->getPrimNo();
            while(temp!=nullptr){
                pilhaNew.push(temp->valor);
            }
        }
};



int main(){
    Stack pilha;
    pilha.initiaalizate();
    pilha.push(25);
    pilha.print();
    
    
    
}