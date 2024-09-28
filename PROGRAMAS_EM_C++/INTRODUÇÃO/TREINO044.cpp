#include <iostream>

class No{
    public:
        int valor;
        No* prox;
        No* ant;
};

class listaDupEnc1{
    private:
        No* primNo = nullptr;
        No* ultiNo = nullptr;

    public:

        void inserirFinal(int num){
            No* novoNo = new No();
            novoNo->valor = num;

            if(primNo == nullptr){
                primNo = novoNo;
                ultiNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;

                while(bloco->prox != nullptr){
                    bloco = bloco->prox;
                }

                bloco->prox = novoNo;
                bloco->prox->ant = bloco;
                ultiNo = novoNo;

            }
        }

       void removNo(){
            No* busca = primNo;

            if(primNo == nullptr && ultiNo == nullptr){
                std::cout<<"Lista sem valores.";
            }

            
            primNo = busca->prox;
            busca->prox->ant = nullptr;
            delete busca;
            busca = nullptr;
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
    listaDupEnc1 numero;

    numero.inserirFinal(10);
    numero.inserirFinal(20);
    numero.inserirFinal(30);
    numero.inserirFinal(40);

    numero.removNo();

    numero.imprimir();
}