#include <iostream>

class No{
    public:
        int valor;
        No* prox;
        No* ant;
};

class listaEnc6{
    private:
        No* primNo = nullptr;
    
    public:

        void inseriFinal1(int num){
            No* noAtual = new No();
            noAtual->valor = num;
            if(primNo == nullptr){
                primNo = noAtual;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox != nullptr){
                    bloco = bloco->prox;
                }
                bloco->prox = noAtual;
                noAtual->ant = bloco;
            }
        }

       listaEnc6 fusaoLista(listaEnc6 list1, listaEnc6 list2){
            No* blocoAtual;
            blocoAtual = list1.primNo;
       }

        void imprimi(){
            No* percorreLista;
            percorreLista = primNo;
            while(percorreLista != nullptr){
                std::cout<<percorreLista->valor<<std::endl;
                percorreLista=percorreLista->prox;
            }
            
        }
};

int main(){
    listaEnc6 numero;
    listaEnc6 lisOrdenada;

    numero.inseriFinal1(20);
    
    lisOrdenada.inseriFinal1(10);

    numero.imprimi();

    return 0;
}