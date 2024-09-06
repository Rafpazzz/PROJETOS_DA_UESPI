#include <iostream>
#include <cstddef>

using namespace std;

int main(){
    int var1;
    int* pont1;

    var1 = 5;
    pont1 = &var1;

    cout << "O valor da variavel puxada pelo seu nome: "<< var1<< endl;
    cout << "O valor que esta armazenado no pontyeiro: "<< pont1<< endl;
    cout << "Valor da variavel, atravez do ponteiro: "<< *pont1<< endl;

    //int var2;
    //var2 = var1;
    //var2 = *pont1; o var2 recebe o valor de var1
    //cout << var2;
    //var2 = 50;
    //pont1 = &var2;
    
    //cout << *pont1;

    //int* pont2;
    //pont2 = NULL;
    //cout << pont2;

    int* pont3 = new int;
    *pont3 = 35;
    cout << *pont3<< endl;

    //*pont3 = *pont1; pegando o valor do outro ponteiro
    //delete pont3; deletar  o enderreço do ponteiro para nao ocorrer o vazamento de memoria.
    //pont3=pont1; //pegando a endereço(referencia) do outro ponteiro
    cout << *pont3;

    return 0;
}