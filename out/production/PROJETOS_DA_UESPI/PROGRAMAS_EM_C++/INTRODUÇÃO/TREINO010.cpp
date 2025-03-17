#include <iostream>


using namespace std;

class Pessoa{
    public:
    string nome;
    int idade;
    char sexo;

    void imprime(){
        std::cout<<"Nome: "<<nome<<endl;
        std::cout<<"Idade: "<<idade<<endl;
        std::cout<<"Sexo: "<<sexo<<endl;
    }
};


int main(){
    Pessoa estudante;

    estudante.nome = "Rafael";
    estudante.idade = 20;
    estudante.sexo = 'M';

    estudante.imprime();

    return 0;

}