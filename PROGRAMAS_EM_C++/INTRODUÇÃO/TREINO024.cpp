#include <iostream>

using namespace std;

int arr1(int arr[], int tam){
    for(int i=0; i<tam; i++){
        cout<<"["<<arr[i]<<"]";
    }
    cout<<endl;
    return 0;
}

int arr2(int arr[], int tam){
    for(int i=tam - 1; i>= 0; --i){
        cout<<"["<<arr[i]<<"]";
    }
    return 0;
}

int escolheOrdenacao(int arr[], int tam, int (*ptrr)(int[],int)){
        return ptrr(arr, tam);
}

int main(){
    int tam = 5;
    int arr[]={1,2,3,4,5};
    string ordem; 

    cout<<"Informe o ordenacao: ";
    cin>>ordem;

    if(ordem=="crescente")
    escolheOrdenacao(arr, tam, arr1);
    if(ordem=="decrescente")
    escolheOrdenacao(arr, tam, arr2);

    return 0;
}