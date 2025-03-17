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

        void inseriFinal(int num){
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
            }
        }

        void contador(){
            No* contar;
            int posicao = 0;
            contar = primNo;

            if(primNo == nullptr){
                std::cout<<"Lista vazia";
                return;
            }

            while(contar!= nullptr){
                contar = contar->prox;
                posicao++;
            }
            std::cout<<posicao;
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

    numero.inseriFinal(20);
    numero.inseriFinal(30);
    numero.inseriFinal(40);
    numero.inseriFinal(50);

    numero.imprimi();

    numero.contador();

    return 0;
}