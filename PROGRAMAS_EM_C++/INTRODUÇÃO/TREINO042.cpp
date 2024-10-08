#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;

};

class listaEnc9{
    private:
        No* primNo = nullptr;

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
            }
        }

        void inserirValor(int num){
            No* valorNovo = new No();
            valorNovo->valor = num;

            if(primNo == nullptr){
                primNo = valorNovo;
            }

            if(valorNovo->valor < primNo->valor){
                valorNovo->prox = primNo;
                primNo = valorNovo;
            }
            No* percorre = primNo;

            while(percorre->prox != nullptr && percorre->prox->valor < num){
                percorre = percorre->prox;
            }

            if(percorre->prox == nullptr){
               percorre->prox = valorNovo;
            }else{
                No* seguinte = percorre->prox;
                percorre->prox = valorNovo;
                valorNovo->prox = seguinte;
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
    

    numero.inseriLista(1);
    numero.inseriLista(3);
    numero.inseriLista(40);

    numero.inserirValor(2);

    numero.imprimir();
}