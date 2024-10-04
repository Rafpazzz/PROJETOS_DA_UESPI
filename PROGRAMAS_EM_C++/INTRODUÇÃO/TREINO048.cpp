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

        No* getPrimeiroNo(){
            return primNo;
        }

        No* getUltimoNo(){
            return ultmNo;
        }

        void junstaLiasta(listaCir1 list1, listaCir1 list2){
            No* perocorre = list1.getUltimoNo();
            perocorre->prox = nullptr;
            No* primieroList1 = list1.getPrimeiroNo();

            No* perocorreLIST2 = list2.getUltimoNo();
            perocorreLIST2->prox = nullptr;
            No* primeiroList2 = list2.getPrimeiroNo();

            perocorre->prox = primeiroList2;
            perocorreLIST2->prox = primieroList1;

            primNo = primieroList1;
            ultmNo = perocorreLIST2;
        }

        void imprimir(){
            No* percorre = primNo;

            do{
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->prox;
            }while(percorre!=primNo);
        }


};

int main(){
    listaCir1 lista1;
    listaCir1 lista2;
    listaCir1 junta;

    lista1.inserirFinal(10);
    lista1.inserirFinal(20);
    lista1.inserirFinal(30);
    lista1.inserirFinal(40);
    lista1.inserirFinal(50);

    lista2.inserirFinal(60);
    lista2.inserirFinal(70);
    lista2.inserirFinal(80);
    lista2.inserirFinal(90);
    lista2.inserirFinal(100);

    junta.junstaLiasta(lista1, lista2);

    junta.imprimir();

    return 0;
}