#include <iostream>

using namespace std;

class Pessoa{
    public: 
    string nome;
    int idade;
    double altura;
};



int main(){
    Pessoa* pessoa = new Pessoa();

    cout <<"Insira seu nome: ";
    cin >> pessoa->nome;
    cout <<"Insira sua idade: ";
    cin >> pessoa->idade;
    cout <<"Insira sua altura: ";
    cin >> pessoa->altura;

    cout <<"Nome: "<<pessoa->nome<<" "<<"Idade: "<<pessoa->idade<<" "<<"Altura: "<<pessoa->altura;
    
    return 0;
}
