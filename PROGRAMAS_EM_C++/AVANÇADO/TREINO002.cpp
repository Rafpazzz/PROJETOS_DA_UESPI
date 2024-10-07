#include <iostream>

class Arr{
    public:
        int N;
        int *arr;
        static const int TAM = 5;
        bool erro;

        void contrutor(){
            arr = new int[TAM];
            N = 0;
            erro = false;
        }

        void Adiciona(int dado){
            erro = false;
            if(N >= TAM){
                erro = true;
                return;
            }

            arr[N] = dado;
            N++; 
        }
};