#include <iostream>
#include <string>

void intvertepalavra(std::string palavra){
    std::string invertida;
    for(int i = palavra.length() - 1; i >= 0; --i){
        invertida += palavra[i];
    }
    std::cout<<"Palavra: "<<invertida;
}

using namespace std;

int main(){
    string texto;
    cout<<"Escreva uma palavra: ";
    cin>>texto;

    intvertepalavra(texto);

    return 0;
}