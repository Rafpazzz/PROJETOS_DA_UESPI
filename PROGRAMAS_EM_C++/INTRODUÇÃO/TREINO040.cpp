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

        void tornaCiclo(){
            if(primNo == nullptr){
                std::cout<<"Lista vazia.";
                return;
            }

            No*percore = primNo;

            while(percore->prox != nullptr){
                percore = percore->prox;
            }
            percore->prox = primNo;
            std::cout<<percore->prox->valor;
        }

        void imprimi(){
            No* percorreLista;
            percorreLista = primNo;
            do {
            std::cout << percorreLista->valor << std::endl;
            percorreLista = percorreLista->prox;
        } while (percorreLista != nullptr && percorreLista != primNo); 
            
        }
};

int main(){
    listaEnc9 numero;
    
    numero.inseriLista(10);
    numero.inseriLista(20);
    numero.inseriLista(30);
    numero.inseriLista(40);
    numero.inseriLista(50);

    std::cout<<"Lista antes de ser ciclica:"<<std::endl;

    numero.imprimi();

    std::cout<<"========================="<<std::endl;

    numero.tornaCiclo();

    std::cout<<"Lista ciclica:"<<std::endl;

    numero.imprimi();

}