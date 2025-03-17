#include <iostream>

int num_digits(int number){
   
    if(number == 0){
        return 1;
    }
    
    int cont = 0;
    int n = abs(number);

    while(n>0){
        n /= 10;
        cont++;
    }

    std::cout<<cont;

    return cont;
}

using namespace std;

int main(){
    int num;

    cout<<"Informe numero: ";
    cin>>num;

    num_digits(num);

    return 0;
}