#include <iostream>

class No{
    public:
        int valor;
        No* prox;
        No* ant;
};

class listaDupEnc1{
    private:
        No* primNo = nullptr;
        No* ultiNo = nullptr;

    public:

        void inserirFinal(int num){
            No* novoNo = new No();
            novoNo->valor = num;

            if(primNo == nullptr){
                primNo = novoNo;
                ultiNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;

                while(bloco->prox != nullptr){
                    bloco = bloco->prox;
                }

                bloco->prox = novoNo;
                bloco->prox->ant = bloco;
                ultiNo = novoNo;

            }
        }


        void tamanhoLista(){
            No* conta = primNo;
            int n = 0;

            if(primNo == nullptr){
                std::cout<<"Lista vazia.";
                return;
            }

            while(conta != nullptr){
                conta = conta->prox;
                n++;
            }

            std::cout<<"A lista possui "<<n<<" elementos.";
        }

        void listaVazia(){
            No* verifica = primNo;

            if(primNo == nullptr){
                std::cout<<"Lista nao possui elementos.";
            }
        }

        void invereteLista(){
            No* percorre = ultiNo;

            while(percorre != primNo){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->ant;
            }
            std::cout<<primNo->valor;
        }

        No* getPrimeiroNo(){
            return primNo;
        }

        No* getUltimoNo(){
            return ultiNo;
        }

        void concatenaLista(listaDupEnc1& list1, listaDupEnc1& list2){
            No* junta = list1.getUltimoNo();

            if(junta == nullptr){
                std::cout<<"Lista vazia.";
                junta = list2.getPrimeiroNo();
            }if(junta == nullptr){
                std::cout<<"As duas listas estao vazias.";
                return;
            }

            junta->prox = list2.getPrimeiroNo();
            list2.getPrimeiroNo()->ant = junta;

            No* imprimiTudo = list1.getPrimeiroNo();

            while(imprimiTudo != nullptr){
                std::cout<<imprimiTudo->valor<<std::endl;
                imprimiTudo = imprimiTudo->prox;
            }
        }
       

        void imprimir(){
            No* percorre = ultiNo;

            while(percorre != nullptr){
                std::cout<<percorre->valor<<std::endl;
                percorre = percorre->ant;
            }
        }
};

int main(){
    listaDupEnc1 lista1;
    listaDupEnc1 lista2;
    listaDupEnc1 junta;

    lista1.inserirFinal(10);
    lista1.inserirFinal(20);
    lista1.inserirFinal(30);
    lista1.inserirFinal(40);

    lista2.inserirFinal(50);
    lista2.inserirFinal(60);
    lista2.inserirFinal(70);
    lista2.inserirFinal(80);

    junta.concatenaLista(lista1, lista2);

    
}