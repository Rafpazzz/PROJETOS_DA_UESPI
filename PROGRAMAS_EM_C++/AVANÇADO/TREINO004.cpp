#include <iostream>
#include <string>

class Prato{
    public:
        bool sujo;
};

class Node{
    public:
        Prato value;
        Node *next;
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

        void push(Prato data){
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

        Prato pop(){
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
        
        Prato top(){
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

      /*  void tornaBinario(){
            erro = 0;
            if(IsEmpty()){
                std::cout<<"pilh vazia";
                erro = 1;
            }
            Node *temp = ptr_top;
            Node *p = new Node();
            while(temp != nullptr){
                Node *transform = ptr_top;
                while(transform->value%2 != 0 && transform->value%2 != 1){
                    transform->value = transform->value/2;
                }
                p->value = transform->value;
                p = p->next;
                transform = transform->next;
                std::cout<<p->value;
                
            }
        }*/
};

std::string reveerse(std::string str){
    
}

int main(){
    Stack pilha;
    pilha.initiaalizate();
    
    
}