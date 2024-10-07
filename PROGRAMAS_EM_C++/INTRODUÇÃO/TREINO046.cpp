#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;
        No* ant = nullptr;
};

class listaDuplaEnc2{
    private:
        No* primNo = nullptr;
        No* ultiNo = nullptr;

    public:

        void inseriFinal(int num){
            No* novoNo = new No();
            novoNo->valor = num;

            if(primNo == nullptr){
                primNo = novoNo;
                ultiNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox!=nullptr){
                    bloco= bloco->prox;
                }
                bloco->prox=novoNo;
                bloco->prox->ant = bloco;
                ultiNo = bloco->prox;
            }
        }

        No* getPrimeiroNo(){
            return primNo;
        }

       void separaLista(int num, listaDuplaEnc2 &list){
            No* recebe = list.getPrimeiroNo();
            int n = 1;

            if(list.getPrimeiroNo() == nullptr){
                std::cout<<"Lista sem valor";
                return;
            }

            std::cout<<"lista 1:"<<std::endl;

            while(n <= num){
                std::cout<<recebe->valor<<std::endl;
                recebe = recebe->prox;
                n++;
            }
            
            No* list2 = recebe;
            list2->ant= nullptr;

            std::cout<<"lista 2: "<<std::endl;

            while(list2!=nullptr){
                std::cout<<list2->valor<<std::endl;
                list2 = list2->prox;
            }

            recebe->prox = nullptr;

       }

        void imprimir(){
            No* percorre = primNo;

            while(percorre != nullptr){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->prox;
            }
        }
};

int main(){
    listaDuplaEnc2 numero;
    listaDuplaEnc2 separa;

    numero.inseriFinal(1);
    numero.inseriFinal(2);
    numero.inseriFinal(3);
    numero.inseriFinal(4);
    numero.inseriFinal(5);
    numero.inseriFinal(6);
    numero.inseriFinal(7);
    numero.inseriFinal(8);
    numero.inseriFinal(9);
    numero.inseriFinal(10);

    separa.separaLista(6, numero);

    //numero.imprimir();
}