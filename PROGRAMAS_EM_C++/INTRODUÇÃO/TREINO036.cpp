#include <iostream>
using namespace std;

class No{
    public:
        int valor;
        No* prox;
};

class listaEnc6{
    private:
        No* primNo = nullptr;
    
    public:
    listaEnc6(){}

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
            }
        }

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
            }
            
       }

        void ordena(){
            No *atual = primNo;
            No *anterior = nullptr;
            No *proximo = atual->prox;
            No *temp = atual->prox; //variavel de percorrer

            if(primNo == nullptr || atual->prox != nullptr){
                 cout << "" << endl;
                return;
            }

            while(proximo->prox != nullptr){
                if(atual->valor > proximo->valor){
                    anterior = proximo->prox;
                    atual->prox = anterior;
                    proximo->prox = atual;
                    No *novoPrimeiro = proximo;
                    primNo = novoPrimeiro;
                }
                
                proximo = proximo->prox;
            }

            while(temp->prox != nullptr){
                temp = temp->prox;
                while(atual->prox != nullptr){
                    atual = atual->prox;

                    if(atual->valor > temp->valor){
                        anterior = temp->prox;
                        temp->prox = atual;
                        atual->prox = anterior;
                        atual = anterior;
                    }
                
                }
                 
            }
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
    listaEnc6 lista1;
    listaEnc6 lista2;
    listaEnc6 junta;

    lista1.inseriFinal1(2);
    lista1.inseriFinal1(4);
    lista1.inseriFinal1(3);
    lista1.inseriFinal1(1);

   // lista2.inseriFinal1(80);
    //lista2.inseriFinal1(20);
   // lista2.inseriFinal1(60);
    //lista2.inseriFinal1(70);

    //junta.fusaoLista(lista1,lista2);

    lista1.ordena();

    lista1.imprimir();

    return 0;
}

