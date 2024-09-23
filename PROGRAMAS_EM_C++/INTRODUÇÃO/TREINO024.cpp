#include <iostream>

using namespace std;

void arr1(int arr[], int tam){
    for(int i=0; i<tam; i++){
        cout<<"["<<arr[i]<<"]";
    }
    cout<<endl;
}

void arr2(int arr[], int tam){
    for(int i=tam - 1; i>= 0; --i){
        cout<<"["<<arr[i]<<"]";
    }
}

int main(){
    int tam = 5;
    int* pont = new int[tam];
    int arr[] = {1,2,3,4,5};

    for(int i = 0; i < tam; i++){
        pont[i]= arr[i];
    }

    arr1(pont, tam);
    arr2(pont, tam);

     delete[] pont;

    return 0;
}