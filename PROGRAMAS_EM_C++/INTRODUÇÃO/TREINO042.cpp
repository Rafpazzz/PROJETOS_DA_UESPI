#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;
        No* ant = nullptr;
};

class listaEnc9{
    private:
        No* primNo = nullptr;
        No* ultimo = nullptr;

    public:
        void inseriLista(int num){
            No* novoNo = new No();
            novoNo->valor = num;
            if(primNo == nullptr){
                primNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox !=nullptr){
                    bloco = bloco->prox;
                }
                bloco->prox = novoNo;
                ultimo = novoNo;
            }
        }

        void inserirValor(int num){
            No* valorNovo = new No();
            valorNovo->valor = num;

            if(primNo == nullptr){
                primNo = valorNovo;
                ultimo = valorNovo;
            }

            if(valorNovo->valor < primNo->valor){
                valorNovo->prox = primNo;
                primNo->ant = valorNovo;
                primNo = valorNovo;
            }
            No* percorre = primNo;

            while(percorre->prox != nullptr && percorre->prox->valor < num){
                percorre = percorre->prox;
            }

            if(percorre->prox == nullptr){
               percorre->prox = valorNovo;
               valorNovo->ant = percorre;
               ultimo = valorNovo;
            }else{
                No* seguinte = percorre->prox;
                percorre->prox = valorNovo;
                valorNovo->prox = seguinte;
                valorNovo->ant = percorre;
                seguinte->ant = valorNovo;
            }

        }

        void imprimir(){
            No* percorre;
             percorre = primNo;
             while(percorre != nullptr){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->prox;
             }
        }

};

int main(){
    listaEnc9 numero;
    

    numero.inseriLista(10);
    numero.inseriLista(20);
    numero.inseriLista(40);

    numero.inserirValor(9);

    numero.imprimir();
}