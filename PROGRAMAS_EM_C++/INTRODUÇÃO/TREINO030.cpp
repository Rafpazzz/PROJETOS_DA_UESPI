#include <iostream>

class No{
    public:

    int valor;
    No* prox;
    No* ant;
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

    void buscaValor(int num){
        No* buscar;
        buscar = primNo;
        while(buscar->valor != num){
            buscar = buscar->prox;
            if(buscar->valor == num){
                std::cout<<"O valor "<<num<< " foi encontrado na lista.";
                break;
            }else{
                std::cout<<"O valor"<<num<< " nao foi encontrado.";
            }
        }
        
    }

    void percorreLista(){
        No* percorreLista;
        percorreLista = primNo;
        while(percorreLista != nullptr){
            std::cout<<percorreLista->valor<<std::endl;
                percorreLista = percorreLista->prox;
        }
    }
};

int main(){
    listaEnc4 numero;

    numero.inserirFinal(20);
    numero.inserirFinal(30);
    numero.inserirFinal(40);

    numero.percorreLista();

    numero.buscaValor(30);

    return 0;
}