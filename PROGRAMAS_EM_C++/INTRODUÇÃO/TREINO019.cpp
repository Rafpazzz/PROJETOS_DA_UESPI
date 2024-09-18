#include <iostream>

using namespace std;

void invereso(int arr[], int length){
    for(int i = length - 1; i >= 0; --i){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int array[]={1,2,3,4};
    int tam = 4;

    invereso(array, tam);
}