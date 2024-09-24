#include<iostream>

class No{
    public:
        int valor;
        No* prox;
        No* ant;
};

class listaEnc3{
    private:
      No* primNo = nullptr;

    public:
        listaEnc3(){}

        void inserirInicio(int num){
            No* noAtual = new No();
            noAtual->valor = num;
            if(primNo == nullptr){
                primNo = noAtual;
            }else{
                primNo->ant = noAtual;
                noAtual->prox = primNo;
                primNo=noAtual;
            }
        }

        void listadelete(int num){
            No* novoNo;
            novoNo = primNo;
            if(novoNo == nullptr){
                std::cout<<"Lista sem valores";
            } 
            while(novoNo->valor != num){
                novoNo = novoNo->prox;            
            }
            novoNo->ant->prox=novoNo->prox;
            novoNo->prox->ant=novoNo->ant;
            delete novoNo;
            novoNo = nullptr;

        }

        void imprimir(){
            No* blocopercorre;
            blocopercorre = primNo;
            while(blocopercorre != nullptr){
                std::cout<<blocopercorre->valor<<std::endl;
                blocopercorre = blocopercorre->prox;
            }
        }
};

int main(){
    listaEnc3 numero;

    numero.inserirInicio(10);
    numero.inserirInicio(20);
    numero.inserirInicio(30);
    numero.inserirInicio(40);

    numero.listadelete(20);

    numero.imprimir();


    return 0;
}