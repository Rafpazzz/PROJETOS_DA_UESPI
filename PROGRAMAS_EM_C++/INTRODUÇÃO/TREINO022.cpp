#include <iostream>
using namespace std;

//typedef int (*funcpont)(int, int);

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
    if(num2 == 0){
        cout<<"O peração invalida.";
        return 0;
    }
    return num1 / num2;
}

int operacao(int num1, int num2, int (*pont)(int, int)){
    return pont(num1, num2);
}

int main(){

    char escolha;
    int num1 = 7;
    int num2 = 4;

    cout<<"Escolha: ";
    cin>>escolha;

    switch(escolha){
        case '+':
            cout<< operacao(num1, num2, soma);
            break;

        case '-':
            cout<< operacao(num1, num2, subitracao);
            break;

        case '*':
            cout<< operacao(num1, num2, multiplicacao);
            break;
        
        case '/':
            cout<< operacao(num1, num2, divisao);
    }

    return 0;
}