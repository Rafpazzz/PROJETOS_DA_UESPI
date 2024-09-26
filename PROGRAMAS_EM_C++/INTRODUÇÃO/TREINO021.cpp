#include <iostream>

int soma(int num1, int num2){
    return num1 + num2;
}

int multiplica(int num1, int num2){
    return num1*num2;
}

using namespace std;

int main(){
    int (*ponteiroParaFuncao)(int,int);

    ponteiroParaFuncao = soma;
    cout<<"Resultado soma = "<< ponteiroParaFuncao(5,4)<<endl;

    ponteiroParaFuncao = multiplica;
    cout<<"Resultado multiplicaocao = "<< ponteiroParaFuncao(5,4)<<endl;

    return 0;
}