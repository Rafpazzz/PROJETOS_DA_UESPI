#include <iostream>

using namespace std;

void func(int num){
    int cont = 0;

    int n = abs(num);

    while(n>0){
        n /= 10;
        cont++;
    }

    int *array = new int[cont];
    
    for(int i = 0; i < cont; i++){
        array[i] = num % 10;
        num /= 10;
    }

    for(int i = cont-1; i>=0; --i){
        std::cout<<"["<<array[i]<<"], ";
    }

    std::cout<<"{"<<cont<<"}";

    delete[] array;
}

int main(){
    int num;

    cout<<"Informe o numero: ";
    cin>>num;

    func(num);

    return 0;
}