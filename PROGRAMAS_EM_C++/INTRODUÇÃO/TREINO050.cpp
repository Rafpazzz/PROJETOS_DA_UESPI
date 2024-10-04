#include <iostream>

class No{
    public:
        int valor;
        No* prox;
};

class ListCir4{
    private:
        No* primNo = nullptr;
        No* ultmNo =nullptr;
    
    public:

        ListCir4(){}

        void inserir(int num){
            No* novoNo = new No();
            novoNo->valor = num;

            if(primNo == nullptr && ultmNo == nullptr){
                primNo = novoNo;
                ultmNo = novoNo;
            }else{
                ultmNo->prox = novoNo;
                ultmNo = novoNo;
                ultmNo->prox = primNo;
            }
        }

        void removeNo(int num){
           No* atual = primNo;
           No* anterior = nullptr;

           if(primNo->valor == num){
                if(primNo == ultmNo){
                    delete primNo;
                    primNo= ultmNo = nullptr;
                }else{
                    ultmNo->prox = primNo->prox;
                    No* temp = primNo;
                    primNo= primNo->prox;
                    delete temp;
                }

                return;
           }

           do{
                anterior = atual;
                atual = atual->prox;
           }while(atual->valor != num && atual != primNo);

           if(atual->valor = num){
            anterior->prox = atual->prox;

            if(atual == ultmNo){
                ultmNo = anterior;
            }

            delete atual;
           }

        }

        void imprimi(){
            No* percorre = primNo;

            do{
                std::cout<<percorre->valor<<std::endl;
                percorre=percorre->prox;
            }while(percorre!=primNo);
        }
};

int main(){
    ListCir4 numero;

    numero.inserir(1);
    numero.inserir(2);
    numero.inserir(3);
    numero.inserir(4);
    numero.inserir(5);

    numero.removeNo(3);

    numero.imprimi();

}