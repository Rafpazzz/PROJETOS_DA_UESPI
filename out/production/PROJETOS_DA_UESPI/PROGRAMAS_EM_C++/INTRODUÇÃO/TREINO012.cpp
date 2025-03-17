#include <iostream>

int somaInteiros( int* arr,int tam){
    int soma= 0;
    
    
    for (int i = 0; i < tam; i++){
        
        soma += arr[i];
    }
    
    return soma;
}

using namespace std;

int main(){
    int n;
    int arr[]={1,2,3,4,5,6,7,8,9};
    n =9;

    cout << "a soma dos valores: "<<somaInteiros(arr, n);
}