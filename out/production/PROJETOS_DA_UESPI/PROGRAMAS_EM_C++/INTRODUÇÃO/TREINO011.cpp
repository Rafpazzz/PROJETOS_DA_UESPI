#include <iostream>

int somaInteiros( int tam){
    int soma= 0;
    int arr[tam];
    
    for (int i = 0; i < tam; i++){
        std::cout<<"Informe o valor para a casa "<< i+1<<" do vetor: ";
        std::cin>> arr[i];
        soma += arr[i];
    }
    
    return soma;
}

using namespace std;

int main(){
    int n;
    
    cout<<"Informe  otamanhro do seu conjunto numerico: ";
    cin>>n;

    cout << "a soma dos valores: "<<somaInteiros(n);
}