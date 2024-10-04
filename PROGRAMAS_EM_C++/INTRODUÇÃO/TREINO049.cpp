#include <iostream>

class No{
    public:
        int valor;
        No* prox;
        No* ant;
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

       void inverteNo(){
            No* atual = primNo;
            No* proximo = nullptr;
            No* anterior = nullptr;

            do{
                proximo = atual->prox;
                atual->prox = anterior;
                anterior = atual;
                atual = proximo;
            }while(atual!=primNo);

            primNo->prox = anterior;
            primNo = anterior;  

             No* percorre = primNo;
            do{
                std::cout<<percorre->valor<<std::endl;
                percorre= percorre->prox;
            }while(percorre!=primNo);
       }

       No* getPrimeiro(){
            return primNo;
       }

       void verificaPalindromo(listaCir1 list){
        No* normal = primNo;
        No* inverso = list.getPrimeiro();
        bool pali = true;

        

        do{
            if(normal->valor != inverso->valor){
                pali = false;
                break;
            }

            normal = normal->prox;
            inverso = inverso->ant;
        }while(normal != primNo && inverso != ultmNo);

       }


};

int main(){
    listaCir1 lista1;

    lista1.inserirFinal(10);
    lista1.inserirFinal(20);
    lista1.inserirFinal(30);
    lista1.inserirFinal(40);
    lista1.inserirFinal(50);

    lista1.inverteNo();


    return 0;
}

/*eu estive aqui - Joaozinho LaserSom*/