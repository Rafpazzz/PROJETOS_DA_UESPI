#include <iostream>

using namespace std;

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
        return 1;
    }

    return num1/num2;
}

int main(){
    char* pont = new char;
    int num1, num2;

    cout<<"Informe um valor: ";
    cin>> num1;
    cout<<"Informe um valor: ";
    cin>> num2;
    cout<<"==================================="<<endl;
    cout<<"===========CALCULADORA============="<<endl;
    cout<<"SOMA[+]"<<endl;
    cout<<"Subitração[-]"<<endl;
    cout<<"MULTIPLICACAO[*]"<<endl;
    cout<<"DIVISAO[/]"<<endl;
    cout<<"Qual operaçã odeeja realizar: ";
    cin>>pont;

    switch(*pont){
        case '+':
            cout<< soma(num1,num2);
            break;


        case '-':
            cout<< subitracao(num1,num2);
            break;


        case '*':
            cout<<multiplicacao(num1,num2);
            break;
       
        case '/':
            cout<<divisao(num1,num2);
            break;
    }


    return 0;

}