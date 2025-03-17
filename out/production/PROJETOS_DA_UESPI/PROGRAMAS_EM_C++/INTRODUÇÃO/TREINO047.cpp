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

        void separaLista(){
            No* percorre = primNo;
            int tamanho = 0;
            int tamanhoMedio = 0;
            int i = 1;

            if(primNo == nullptr){
                std::cout<<"Lista sem vlores";
                return;
            }

            No* list1 = primNo;
            
           do{
            tamanho++;
            percorre = percorre->prox;
           }while(percorre!=primNo);

            if(tamanho%2==0){
                tamanhoMedio = tamanho/2;
            }else{
                tamanhoMedio = tamanho/2 + 1;
            }

            std::cout<<"Lista 1:"<<std::endl;
            while(i <= (tamanho - tamanhoMedio)){
                std::cout<<list1->valor<<std::endl;
                list1 = list1->prox;
                i++;
            }
            No* finalList1 = list1;

            No* list2 = list1;

            i = 1;

            std::cout<<"Lista 2:"<<std::endl;
            while(i <= tamanhoMedio ){
                std::cout<<list2->valor<<std::endl;
                list2 = list2->prox;
                i++;
            }

            No* finalList2 = list2;
            finalList2->prox = list1->prox;
            finalList1->prox = primNo;
            
        }

        
};

int main(){
    listaCir1 numero;

    numero.inserirFinal(10);
    numero.inserirFinal(20);
    numero.inserirFinal(30);
    numero.inserirFinal(40);
    numero.inserirFinal(50);

    numero.separaLista();

    return 0;
}