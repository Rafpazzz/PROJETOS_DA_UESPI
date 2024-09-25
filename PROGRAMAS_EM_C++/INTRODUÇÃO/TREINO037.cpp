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

    numero.inseriFinal1(20);
    numero.inseriFinal1(30);
    numero.inseriFinal1(40);
    numero.inseriFinal1(40);

   

    numero.imprimi();

    return 0;
}