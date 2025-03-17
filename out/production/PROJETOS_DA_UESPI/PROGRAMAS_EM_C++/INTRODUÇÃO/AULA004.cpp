#include <iostream>

using namespace std;

int main(){

    int num1, a;

    cout << "Informe um valor para calcular fatorial: ";
    cin >> num1;
    a = 1;
    for (int i = 1; i <= num1; i++)
    {
      a *=i;
    }

    cout << "Fatorial: "<< a;
    
    

    return 0;
}