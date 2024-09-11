#include <iostream>

using namespace std;

int main() {
    
    double num , valor;
    valor = 50;

    cout<< "Adivinhe o valor: ";
    cin >> num;

    while (num != valor){
        if (num < valor){
            cout << "insira um valor maior: ";
            cin >> num;
        }else{
            cout << "Insira um valor menor: ";
            cin >> num;
        }
        
    }

    cout <<"Voce acertou o valor!";

    return 0;
}
