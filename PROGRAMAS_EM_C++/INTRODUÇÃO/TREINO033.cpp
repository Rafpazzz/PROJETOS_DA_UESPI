#include <iostream>

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

    void invertLista(){
        if(primNo == nullptr){
            std::cout<<"Sua lista esta vazia";
            return;
        }
        No* atual = primNo;
        No* proximo = nullptr;
        No* anterior = nullptr;

        while(atual != nullptr){
            proximo = atual->prox;
            atual->prox = anterior;
            anterior = atual;
            atual = proximo;
        }

        primNo = anterior;
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

    std::cout<<"================================="<<std::endl;

    numero.invertLista();

    numero.percorreLista();

    return 0;
}