#include <iostream>

class No{
    public:
        int valor;
        No* prox;
        
};

class listaEnc1{
    private: 
        No* primNo = nullptr;

    public:
        

        void inserirFinal(int num){
                No* novoNo = new No();
                novoNo -> valor = num;
                if (primNo==nullptr){
                    primNo = novoNo;
                }else{
                    No* bloco;
                    bloco = primNo;
                    while(bloco -> prox != nullptr){
                        bloco = bloco -> prox;
                    }
                    bloco -> prox = novoNo;
                }
        }

        void imprimirLista(){
            No* blocopercorre;
            blocopercorre = primNo;
            while(blocopercorre != nullptr){
                std::cout<<blocopercorre -> valor<<std::endl;
                blocopercorre = blocopercorre->prox;
            }
        }
        
};

    using namespace std;

int main(){

    listaEnc1 numero;
   
    numero.inserirFinal(20);
    numero.inserirFinal(30);
    numero.inserirFinal(40);
    numero.inserirFinal(50);
    numero.inserirFinal(60);
    numero.inserirFinal(70);


    numero.imprimirLista();


    return 0;
}

