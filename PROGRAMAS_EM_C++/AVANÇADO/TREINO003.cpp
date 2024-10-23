#include <iostream>

constexpr int MAX = 1000;

class Pilhasec1{
    public:
            int N;
            char elements[MAX];
            int erro;
            
            void criar(){
                this->N = 0;
            }

            void libera(){

            }

            void push(char data){
                erro = 0;
                if(N<MAX){
                    this->elements[N] = data;
                    N++;
                }else{
                    erro = 1;
                    return;
                }
            }

            char pop(){
                erro = 0;
                if(N == 0){
                    erro = 1;
                    return '\0';
                }else{
                    char unstack = elements[N-1];
                    N--;
                    return unstack;
                }
            }

            char top(){
                erro =0;
                if(N==0){
                    erro = 1;
                    return '\0';
                }else
                return this->elements[this->N-1];
            }

            int lengh(){
                return N;
            }

            void invetSting(Pilhasec1 pilha[]){
                erro = 0;
                if(N == 0){
                    erro = 1;
                    return;
                }else{
                    Pilhasec1 nova[N];
                    int j = N;
                    for(int i = 0; i<N; i++){
                        nova[i] = pilha[j-1];
                        j--;
                    }
                }
            }

           /* char *infixa(char *pilha){
                criar();
                push(pilha[0]);
                int j =0;
                for(int i = 0; pilha[i] != '\0'; i++){
                    switch(pilha[i]){
                        
                        case '(': 

                    }
                }
                
            }*/

            char print(){
                for(int i = N-1; i>=0; i--){
                    std::cout<<elements[i];
                }
            }


};

int main(){
    Pilhasec1 p;
    p.criar();
    p.push('A');
    p.push('B');
    p.push('C');
    //std::cout<<("{}\n",p.lengh());
    p.print();
    //std::cout<<("\n{}", p.top());
    //std::cout<<("\n{}", p.pop());
    //p.invetSting(&p);
}