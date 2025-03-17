#include <iostream>

class No{
    public: 
        int valor;
        No* prox;
        No* ant;
};

class listaEnc5{
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

        void inseriMeio(int num, int posicao){
            No* inserir = new No();
            inserir->valor = num;

            if(primNo == nullptr){
                primNo = inserir;
                return;
            }

            No* percorre;
            percorre = primNo;

            while(percorre!=nullptr && percorre->valor!=posicao){
                percorre = percorre->prox;
                
            }

            if(percorre == nullptr){
                std::cout<<"A posição noafoi encontrada";
                delete inserir;
                inserir = nullptr;
                return;
            }
            
            inserir->prox = percorre->prox;

            percorre->prox = inserir;
    }

        void imprimir(){
            No* percorreLista;
            percorreLista = primNo;
            while(percorreLista!=nullptr){
                std::cout<<percorreLista->valor<<std::endl;
                percorreLista = percorreLista->prox;
            }
        }
    
    };

    int main(){
        listaEnc5 numero;

        numero.inseriFinal(20);
        numero.inseriFinal(30);
        numero.inseriFinal(40);
        numero.inseriFinal(50);
        
        numero.inseriMeio(60, 30);

        numero.imprimir();

        return 0;
    }