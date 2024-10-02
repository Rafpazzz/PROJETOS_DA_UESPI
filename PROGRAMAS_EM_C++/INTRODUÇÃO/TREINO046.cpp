#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;
        No* ant = nullptr;
};

class listaDuplaEnc2{
    private:
        No* primNo = nullptr;
        No* ultiNo = nullptr;

    public:

        void inseriFinal(int num){
            No* novoNo = new No();
            novoNo->valor = num;

            if(primNo == nullptr){
                primNo = novoNo;
                ultiNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox!=nullptr){
                    bloco= bloco->prox;
                }
                bloco->prox=novoNo;
                bloco->prox->ant = bloco;
                ultiNo = bloco->prox;
            }
        }

       void separaLista(int num){
            No* recebe = primNo;

            if(primNo == nullptr && ultiNo == nullptr){
                std::cout<<"Lista sem valor";
                return;
            }

            No* list1 = primNo;
            
            std::cout<<"lista 1:"<<std::endl;

            while(recebe->valor < num){
                recebe = recebe->prox;
                std::cout<<list1->valor<<std::endl;
                list1 = recebe;
            }

            No* list2 = recebe;

            std::cout<<"lista 2: "<<std::endl;

            while(recebe!=nullptr){
                recebe = recebe->prox;
                std::cout<<list2->valor<<std::endl;
                list2 = recebe;
            }

       }

        void imprimir(){
            No* percorre = primNo;

            while(percorre != nullptr){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->prox;
            }
        }
};

int main(){
    listaDuplaEnc2 numero;

    numero.inseriFinal(1);
    numero.inseriFinal(2);
    numero.inseriFinal(3);
    numero.inseriFinal(4);
    numero.inseriFinal(5);
    numero.inseriFinal(6);
    numero.inseriFinal(7);
    numero.inseriFinal(8);
    numero.inseriFinal(9);
    numero.inseriFinal(10);

    numero.separaLista(6);

    //numero.imprimir();
}