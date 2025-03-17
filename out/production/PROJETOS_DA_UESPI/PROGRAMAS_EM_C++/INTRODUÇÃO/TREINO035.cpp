#include <iostream>

class No{
    public:
        int valor;
        No* prox;
};

class listaEnc6{
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

       void removeDuplicado(){
            if(primNo == nullptr){
                std::cout<<"Lista nao possue valores duplicados";
                return;
            }
           
            No* atual;
            atual = primNo;

            while(atual!=nullptr && atual->prox!=nullptr){
                No* proxNo = atual->prox;
                if(atual->valor == proxNo->valor){
                    atual->prox = proxNo->prox;
                    delete proxNo;
                    proxNo=nullptr;
                }else{
                    atual = atual->prox;
                }
            }

       }

        void imprimi(){
            No* percorreLista;
            percorreLista = primNo;
            while(percorreLista != nullptr){
                std::cout<<percorreLista->valor<<std::endl;
                percorreLista=percorreLista->prox;
            }
            
        }
};

int main(){
    listaEnc6 numero;

    numero.inseriFinal(20);
    numero.inseriFinal(30);
    numero.inseriFinal(40);
    numero.inseriFinal(40);

    numero.imprimi();

    std::cout<<"============================"<<std::endl;

    numero.removeDuplicado();

    numero.imprimi();

    

    return 0;
}