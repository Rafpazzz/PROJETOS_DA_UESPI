#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;
        No* ant = nullptr;
};

class listaEnc9{
    private:
        No* primNo = nullptr;
        No* ultimo = nullptr;

    public:
        void inseriLista(int num){
            No* novoNo = new No();
            novoNo->valor = num;
            if(primNo == nullptr){
                primNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox !=nullptr){
                    bloco = bloco->prox;
                }
                bloco->prox = novoNo;
                ultimo = novoNo;
            }
        }

        No* recebePrimeiroNo(){
            return primNo;
        }

        void concatenaLista(listaEnc9& list1, listaEnc9& list2){
            No* junta;
            junta = list1.recebePrimeiroNo();
            
            while(junta->prox != nullptr){
                junta = junta->prox;
            }

            junta->prox = list2.recebePrimeiroNo();
            primNo = list1.recebePrimeiroNo();
        }

        void imprimir(){
            No* percorre;
             percorre = primNo;
             while(percorre != nullptr){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->prox;
             }
        }

};

int main(){
    listaEnc9 lista1;
    listaEnc9 lista2;
    listaEnc9 junta;

    lista1.inseriLista(10);
    lista1.inseriLista(20);
    lista1.inseriLista(30);
    lista1.inseriLista(40);

    lista2.inseriLista(50);
    lista2.inseriLista(60);
    lista2.inseriLista(70);
    lista2.inseriLista(80);

    junta.concatenaLista(lista1, lista2);

    junta.imprimir();
}