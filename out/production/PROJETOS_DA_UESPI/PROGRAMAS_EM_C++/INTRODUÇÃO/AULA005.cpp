#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int num1, num2, pot;
    string escolha;
   
   
    do
    {
      cout << "Informe unumero que deseja calcualr a potencia: ";
        cin >> num1;
        cout << "informe o numero que vai na casa da potencia do seu numero: ";
        cin >> num2;

        pot = 1;

        for (int i=0; i < num2 ; i++)
        {
            pot *= num1;
        }
        

        cout << "O valor final é: "<< pot<< endl;
        cout << "deseja calcular outra potencia?[SIM/NÃO]"<< endl;
        cin >> escolha;

    }
    while (escolha == "sim" || escolha == "s");
    
    return 0;
}