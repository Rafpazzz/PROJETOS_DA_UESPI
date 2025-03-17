#include <iostream>

/*void contador(int num, int cont = 0);

using namespace std;

int main(){
    contador(20);

    return 0;

}

void contador(int num, int cont){
    cout<<cont<<endl;
    if(num > cont){
        contador(num, ++cont);
    }

}*/

using namespace std;

class indentidade{
 private: 
    
    char sexo;
    int idade;
    string nome;

public:
    void setnome(string n){
        this->nome = n;
    }

    string getnome(){
        return nome;
    }

};

int main(){
    indentidade aluno;
    string nome;
    int idade;
    char sexo;

    

    cout<<"Nome: ";
    cin>>nome;

    aluno.setnome(nome);
   
}