#include <iostream>

void func(int arr[], int tam){
    for(int i=0; i < tam; i++){
        std::cout<<"["<<arr[i]<<"] ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"O tamanho do array: "<<tam;
    
}

using namespace std;

int main(){
    int tam;

    cout<<"Informe o tamanho do vetor: ";
    cin>>tam;
    
    int* pontVet = new int[tam];

    for(int i = 0; i < tam; i++){
        cout<<"Valores para o vetor: ";
        cin>>pontVet[i];
    }

    func(pontVet, tam);

    return 0;
}