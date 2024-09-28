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

       void insereNo(int num, int idx){
            No* busca = primNo;
            No* insere = new No();
            insere->valor = num;

            if(primNo == nullptr && ultiNo == nullptr){
                primNo = insere;
                ultiNo = insere;
                return;
            }

            while(busca != nullptr && busca->valor != idx){
                busca = busca->prox;
            }

           if(busca == nullptr){
                std::cout<<"Posicao invalida.";
                delete insere;
                return;
           }
           
           insere->prox = busca;
           insere->ant = busca->ant;
           
           if(busca->ant != nullptr){
                busca->ant->prox = insere;
           }else{
                primNo = insere;
           }

           busca->ant = insere;
           
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

    numero.insereNo(50, 20);

    numero.imprimir();
}