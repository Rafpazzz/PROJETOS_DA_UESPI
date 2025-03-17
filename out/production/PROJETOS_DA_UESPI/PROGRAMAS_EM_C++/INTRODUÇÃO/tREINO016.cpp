#include <iostream>

using namespace std;

int  main(){
    int n= 5;
    int* pont[n];

    for(int i =0; i<n;i++){
        pont[i] = new int;
    }
    

    for(int i =0; i<n;i++){
        cout<<"Informe o valor para a posicao "<<i+1<<":";
        cin>> *pont[i];
    }


    for (int i = 0; i < n; i++){
        cout<<*pont[i]<<" ";
    }
    
    for(int i =0; i<n;i++){
        delete pont[i];
    }

    return 0;
}