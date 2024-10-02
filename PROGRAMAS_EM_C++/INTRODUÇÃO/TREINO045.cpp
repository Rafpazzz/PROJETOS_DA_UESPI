#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;
        No* ant = nullptr;
};

class listaDuplaEnc2{
    private:
        No* primNo = nullptr;
        No* ultiNo = nullptr;

    public:

        void inseriFinal(int num){
            No* novoNo = new No();
            novoNo->valor = num;

            if(primNo == nullptr){
                primNo = novoNo;
                ultiNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox!=nullptr){
                    bloco= bloco->prox;
                }
                bloco->prox=novoNo;
                bloco->prox->ant = bloco;
                ultiNo = bloco->prox;
            }
        }

        void palindormo(){
            No* checagemCima = primNo;
            No* checagemBaixo = ultiNo;
            bool verifica = true;

            
            while(checagemCima != nullptr && checagemBaixo != nullptr && checagemCima != checagemBaixo && checagemCima->ant != checagemBaixo){
                 if (checagemCima->valor != checagemBaixo->valor) {
                    verifica = false;
                    break;
                }

                checagemCima = checagemCima->prox;
                checagemBaixo = checagemBaixo->prox;
            }
            
            if(verifica){
                std::cout<<"Lisca com palindromo.";
            }else{
                std::cout<<"Lista sem palindromo.";
            }
        }

        void imprimir(){
            No* percorre = ultiNo;

            while(percorre != nullptr){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->ant;
            }
        }
};

int main(){
    listaDuplaEnc2 numero;

    numero.inseriFinal(1);
    numero.inseriFinal(2);
    numero.inseriFinal(3);
    numero.inseriFinal(2);
    numero.inseriFinal(4);

    numero.palindormo();
}