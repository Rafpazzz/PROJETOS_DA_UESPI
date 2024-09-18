#include <iostream>

int soma(int num1, int num2){
    std::cout<<num1+num2;
    return num1 + num2;
}

int multiplica(int num1, int num2){
     std::cout<<num1*num2;
    return num1*num2;
}

using namespace std;

int main(){
    char* pont = new char;
    int num1, num2;
    num1 = 2;
    num2 = 4;

    cout<<"Informe a operação[+/*]: ";
    cin>> *pont;

    switch(*pont){
        case '+':
            soma(num1,num2);
            break;
        case '*':
            multiplica(num1,num2);
            break;
    }

    return 0;
}