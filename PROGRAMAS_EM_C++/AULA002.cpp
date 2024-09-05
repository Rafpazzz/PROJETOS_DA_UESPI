#include <iostream>

using namespace std;

void inscrever(){
    cout << "Se inscreva no canal do XXXXXXXXXXX"<< endl;

}

int somar (int num1, int num2){
    int soma;
    num1 = 3;
    num2 = 4;
    soma = num1 + num2;
    return soma;
}

int main(){
    
    int num1, num2;

    cout<<"Insira um numero= ";
    cin>> num1;
    cout<<"Insira um numero= ";
    cin>> num2;

    cout<< somar(num1, num2)<< endl;
    

    inscrever();

    return 0;
}