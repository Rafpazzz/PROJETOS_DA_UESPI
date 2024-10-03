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
                No* bloco;
                bloco = noAtual;
                bloco->prox = primNo;
                primNo = bloco;
            }
        }

        No* getPrimeiroNo(){
            return primNo;
        }

        void listadelete(int num){
            No* atual = primNo;
            No* anterior = nullptr;
            
            if(atual == nullptr){
                std::cout<<"LIsta vazia";
                return;
            }
            
            while(atual->prox != nullptr && atual->valor != num){
                anterior = atual;
                atual = atual->prox;
            }

            if(atual == nullptr){
                std::cout<<"Valor nao encontrado";
                return;
            }

            if(anterior == nullptr){
                primNo = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }

            delete atual;
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