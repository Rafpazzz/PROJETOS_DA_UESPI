#include <iostream>

using namespace std;

int main(){
    
    //Alocação estatica.
  /*  int vet[4] = {5,10};

    for (int i = 0; i < 4; i++){
        cout << vet[i]<< endl;
    }

    int x = sizeof(vet)/sizeof(int);
    cout<< "O numeros de elementos do vetor é: "<< x;
   */
    //Alocação dinamica.
    int tamanho;
    cout << "Digite o tamanho do verto: ";
    cin >> tamanho; 
    int* vetor = new int[tamanho]; 
    for (int i = 0; i < tamanho; i++)
    {
        cout << "Informe o valor "<< i+1<< "Do vetor: ";
        cin >> vetor[i];
    }

    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i];
    }
    
    //delete [] vetor; deleta o vetor e libera o espaço de memoria para outra variavel acessar novamente.

    cout << endl;
    
    return 0;
}