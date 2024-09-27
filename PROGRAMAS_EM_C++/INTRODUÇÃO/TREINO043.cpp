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

       void ordena(listaEnc9 &list){
            No* verifica = primNo;
            No* listaPar;
            No* listaImpar;

            if(primNo == nullptr){
                std::cout<<"Lista sem valor";
            }

            if(primNo!=nullptr){
                if(primNo->valor % 2 == 0){
                     listaPar = primNo;
                }else{
                     listaImpar = primNo;
                }
            }

            while(verifica->prox != nullptr){
                verifica = verifica->prox;
                if(verifica->valor %2 == 0 ){
                    listaPar->prox = verifica; 
                }else{
                    listaImpar->prox = verifica;
                }
            }
            
            std::cout<<"Lista valores pares: "<<std::endl;

            while(listaPar != nullptr){
                
                std::cout<<listaPar->valor<<std::endl;
                listaPar = listaPar->prox;
            }
            
            std::cout<<"Lista valores impares: "<<std::endl;

            while(listaImpar != nullptr){
                
                std::cout<<listaImpar->valor<<std::endl;
                listaImpar = listaImpar->prox;
            }
       }

};

int main(){
    listaEnc9 numero;
    

    numero.inseriLista(1);
    numero.inseriLista(2);
    numero.inseriLista(3);
    numero.inseriLista(4);

    numero.ordena(numero);
}