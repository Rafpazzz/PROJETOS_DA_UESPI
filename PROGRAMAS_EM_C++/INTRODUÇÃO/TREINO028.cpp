#include <iostream>

class No{
  public:
    int valor;
    No* prox;
    No* ant;
};

class listaEnc2{
    private:
        No* primNo = nullptr;
    
    public:
        listaEnc2(){}
        void inseriInicio(int num){
            No* novoNo = new No();
            novoNo->valor = num;
            if(primNo==nullptr){
                primNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                if(bloco->ant == nullptr){
                    bloco->ant = novoNo;
                    novoNo->prox = bloco;
                    primNo = novoNo;
                }
            } 
            
        }

        void imprimirLista(){
            No* blocopercorre;
            blocopercorre = primNo;
            while(blocopercorre != nullptr){
                std::cout<<blocopercorre->valor<<std::endl;
                blocopercorre = blocopercorre->prox;
            }

        }

};

int main(){
    listaEnc2 numero;

    numero.inseriInicio(10);
    numero.inseriInicio(20);
    numero.inseriInicio(30);

    numero.imprimirLista();

    return 0;
}