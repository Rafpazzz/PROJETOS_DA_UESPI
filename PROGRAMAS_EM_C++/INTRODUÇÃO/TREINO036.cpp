#include <iostream>

class No{
    public:
        int valor;
        No* prox;
        No* ant;
};

class listaEnc6{
    private:
        No* primNo = nullptr;
    
    public:

        void inseriFinal1(int num){
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
                noAtual->ant = bloco;
            }
        }

<<<<<<< HEAD
       listaEnc6 fusaoLista(listaEnc6 list1, listaEnc6 list2){
            No* blocoAtual;
            blocoAtual = list1.primNo;
=======
        No* getPrimeiro(){
            return primNo;
        }

       void fusaoLista(listaEnc6 &list1, listaEnc6 &list2){
            No* junta = list1.getPrimeiro();

            if(junta == nullptr){
                primNo = list2.getPrimeiro();
            }else{
                while(junta->prox != nullptr){
                    junta = junta->prox;
                }

                junta->prox = list2.getPrimeiro();

                if (list2.getPrimeiro() != nullptr) {
                    list2.getPrimeiro()->ant = junta;
                }
            }
            
       }

       void ordenaLista(listaEnc6 list1, listaEnc6 list2, void (*pont)(listaEnc6,listaEnc6)){
            if (primNo == nullptr || primNo->prox == nullptr) {
                std::cout << "Lista vazia ou com apenas um nó.\n";
                return;
            }

            No* comparar = primNo;
            No* segunte = comparar->prox;
            while(comparar != nullptr && segunte!=nullptr){
                if(comparar->valor > comparar->prox->valor){
                    segunte= comparar;
                    segunte->ant = comparar->prox;
                    comparar->prox->ant = nullptr;
                }
            
            }


>>>>>>> c58b38e52fd1e2146888a91f56516a2055096d36
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
<<<<<<< HEAD
    listaEnc6 numero;
    listaEnc6 lisOrdenada;

    numero.inseriFinal1(20);
    
    lisOrdenada.inseriFinal1(10);
=======
    listaEnc6 lista1;
    listaEnc6 lista2;
    listaEnc6 junta;

    lista1.inseriFinal1(10);
    lista1.inseriFinal1(50);
    lista1.inseriFinal1(40);
    lista1.inseriFinal1(30);

    lista2.inseriFinal1(80);
    lista2.inseriFinal1(20);
    lista2.inseriFinal1(60);
    lista2.inseriFinal1(70);

    junta.fusaoLista(lista1,lista2);
>>>>>>> c58b38e52fd1e2146888a91f56516a2055096d36

    junta.ordenaLista(lista1, lista2, junta.ordenaLista);

    junta.imprimir();

    return 0;
}