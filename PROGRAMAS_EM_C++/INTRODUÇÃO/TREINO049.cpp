#include <iostream>

class No{
    public:
        int valor;
        No* prox;
};

class listaCir1{
    private:
        No* primNo = nullptr;
        No* ultmNo = nullptr;
    
    public:

        void inserirFinal(int num){
            No* novoValor = new No();
            novoValor->valor = num;

            if(primNo == nullptr){
                primNo = novoValor;
                ultmNo = novoValor;
                novoValor = primNo;
            }else{
               ultmNo->prox = novoValor; 
               ultmNo = novoValor;       
               ultmNo->prox = primNo;
            }
        }

       

        void imprimi(){
            No* percorre = primNo;
            do{
                std::cout<<percorre->valor<<std::endl;
                percorre= percorre->prox;
            }while(percorre!=primNo);
        }


};

int main(){
    listaCir1 lista1;

    lista1.inserirFinal(10);
    lista1.inserirFinal(20);
    lista1.inserirFinal(30);
    lista1.inserirFinal(40);
    lista1.inserirFinal(50);

    lista1.inverter();

    lista1.imprimi();

    return 0;
}