#include <iostream>
using namespace std;

typedef int (*funcpont)(int, int);

int soma(int num1, int num2){

    return num1 + num2;
}

int subitracao(int num1, int num2){

    return num1 - num2;
}

int multiplicacao(int num1, int num2){

    return num1 * num2;
}

int divisao(int num1, int num2){

    return num1 / num2;
}

int operacao(int num1, int num2, funcpont pont){
    return pont(num1,num2);
}

int main(){

    

}