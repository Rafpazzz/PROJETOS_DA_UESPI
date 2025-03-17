#include <iostream>

using namespace std;

class carro{
    public:
    string marca, modelo;
    int ano;
};

int main(){
    carro* palio = new carro;
    carro* corola = new carro;

    cout<<"Informacoes do Palio"<<endl;
    cout <<"Informe o modelo do carro: ";
    cin >> palio->modelo;
    cout <<"Informe o marca do carro: ";
    cin >> palio->marca;
    cout <<"Informe o ano do carro: ";
    cin >> palio->ano;

    cout<<"Informacoes do corola"<<endl;
    cout <<"Informe o modelo do carro: ";
    cin >> corola->modelo;
    cout <<"Informe o marca do carro: ";
    cin >> corola->marca;
    cout <<"Informe o ano do carro: ";
    cin >> corola->ano;

    if (corola->ano > palio->ano)   
    {
        cout<<"O corola e o carro mas novo";
    }else{
        cout<<"O palio e o carro mas novo";
    }

    return 0;
    
}