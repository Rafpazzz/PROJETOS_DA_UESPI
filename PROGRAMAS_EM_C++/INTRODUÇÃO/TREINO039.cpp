#include <iostream>

class No{
    public: 
        int valor;
        No* prox = nullptr;
        No* ant = nullptr;
};

class listaEnc8{
    private:
        No* primNo = nullptr;
        No* ultimo = nullptr;
    public:
        void inseriFinal(int num){
            No* novoNo = new No();
            novoNo->valor = num;
            if(primNo == nullptr){
                primNo = novoNo;
                ultimo = novoNo;
            }else{
                No* bloco = primNo;
                while(bloco->prox != nullptr){
                    bloco = bloco->prox;
                }
               bloco->prox = novoNo;
               ultimo = novoNo;
                //ultimo->prox = novoNo;
               // novoNo->prox = primNo;
                //ultimo = novoNo;
            }

        }


        void verificaCiclo(){
            No* lebre = primNo;
            No* tartaruga = primNo;

            if(primNo == nullptr){
                std::cout<<"Lista sem valor";
                return;
            }

            if(primNo->prox==nullptr){
                std::cout<<"Lista unitaria.";
                return;
            }

            while(lebre != nullptr && lebre->prox != nullptr){
                tartaruga = tartaruga->prox;
                lebre = lebre->prox->prox;

                if(lebre == tartaruga){
                    std::cout<<"Lista ciclica."<<std::endl;
                    return;
                }
            }

            std::cout<<"Lista nao ciclica.";
        }

        void imprime(){
            No* percorre;
            percorre = primNo;
            do {
            std::cout << percorre->valor << std::endl;
            percorre = percorre->prox;
        } while (percorre != nullptr && percorre != primNo);  
    }
        
};

int main(){
    listaEnc8 numero;

    numero.inseriFinal(20);
    numero.inseriFinal(30);
    numero.inseriFinal(40);
    numero.inseriFinal(50);
    numero.inseriFinal(60);

    numero.imprime();

    numero.verificaCiclo();

    return 0;

}
