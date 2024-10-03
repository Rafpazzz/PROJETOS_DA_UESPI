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

        void noMedio(){
           No* percorre = primNo;
           int tamanho = 0;
           int meio = 1;
           No* valorMeio = primNo;

           do{
                percorre = percorre->prox;
                tamanho++;
           }while(percorre != primNo);

           tamanho = tamanho/2;

           do{
                valorMeio = valorMeio->prox;
                meio++;
           }while(meio <= tamanho);

           std::cout<<"Valor meio: "<<valorMeio->valor;

        }

        void transformar(){
            No* atual = ultmNo;
            atual->prox = nullptr;
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

    numero.transformar();

    numero.imprimi();

}