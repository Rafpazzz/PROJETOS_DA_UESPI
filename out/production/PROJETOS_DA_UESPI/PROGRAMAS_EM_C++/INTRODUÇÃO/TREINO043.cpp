#include <iostream>

class No{
    public:
        int valor;
        No* prox = nullptr;
};

class listaEnc9{
    private:
        No* primNo = nullptr;

    public:
        void inseriLista(int num){
            No* novoNo = new No();
            novoNo->valor = num;
            if(primNo == nullptr){
                primNo = novoNo;
            }else{
                No* bloco;
                bloco = primNo;
                while(bloco->prox != nullptr){
                    bloco = bloco->prox;
                }
                bloco->prox = novoNo;
            }
        }

       void ordena(){
            No* verifica = primNo;
            No* listaPar = nullptr;
            No* listaImpar = nullptr;
            No* ultimoPar = nullptr;
            No* ultimoImpar = nullptr;

            if(primNo == nullptr){
                std::cout<<"Lista sem valor";
            }

            while(verifica != nullptr){
                if(verifica->valor % 2 == 0){
                    No* novoPar = new No();
                    novoPar->valor = verifica->valor;
                    if(listaPar == nullptr){
                        listaPar = novoPar;
                        ultimoPar = novoPar;
                    }else{
                        ultimoPar->prox = novoPar;
                        ultimoPar = novoPar;
                    }
                }else{
                    No* novoImpar = new No();
                    novoImpar->valor = verifica->valor;
                    if(listaImpar == nullptr){
                        listaImpar = novoImpar;
                        ultimoImpar = novoImpar;
                    }else{
                        ultimoImpar->prox = novoImpar;
                        ultimoImpar = novoImpar;
                    }
                }

                verifica = verifica->prox;
            }
            
            std::cout<<"Lista valores pares: "<<std::endl;

            No* percorrePar = listaPar;
            while (percorrePar != nullptr) {
                std::cout << percorrePar->valor << std::endl;
                percorrePar = percorrePar->prox;
            }
            
            std::cout<<"Lista valores impares: "<<std::endl;

            No* percorreImpar = listaImpar;
            while(percorreImpar != nullptr){
                
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
    numero.inseriLista(5);
    numero.inseriLista(6);
    numero.inseriLista(7);
    numero.inseriLista(8);
    numero.inseriLista(9);
    numero.inseriLista(10);

    numero.ordena();
}