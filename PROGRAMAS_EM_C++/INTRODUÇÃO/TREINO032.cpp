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
            noAtual->ant = bloco;
        }

    }

    void remove(){
        if (primNo == nullptr) {
            std::cout << "A lista está vazia, não há elementos para remover!" << std::endl;
            return;
        }
        if (primNo->prox == nullptr){
            delete primNo;
            primNo = nullptr;
            return;
        }
        No* remove = primNo;
        while(remove->prox != nullptr){
            remove = remove->prox;
        }
        remove->ant->prox = nullptr;
        delete remove;
    
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

    numero.remove();

    numero.percorreLista();

    return 0;
}