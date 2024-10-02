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

        void junstaLiasta(listaCir1 list1, listaCir1 list2){
            No* perocorre = list1.getPrimeiroNo();


            do{
                std::cout<<perocorre->valor<<std::endl;
                perocorre = perocorre->prox;
            }while(perocorre!=list1.getPrimeiroNo());

             No* perocorreLIST2 = list2.getPrimeiroNo();
            do{
                std::cout<<perocorreLIST2->valor<<std::endl;
                perocorreLIST2 = perocorreLIST2->prox;
            }while(perocorreLIST2!= list2.getPrimeiroNo());
            
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

    return 0;
}