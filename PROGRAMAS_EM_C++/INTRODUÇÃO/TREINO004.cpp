#include <iostream>
template <typename T>



void maior(T num1, T num2){
    T maior;
    if (num1 > num2){
        maior = num1;
       std::cout << "O valor maior: "<< maior;
    }else{
        maior = num2;
        std::cout <<"Maior valor: "<< maior;
    }
   
}

using namespace std;

int main(){
    int  n, m;

    cout << "Insira um valor: ";
    cin >> n;
    cout << "Insira um valor: ";
    cin >> m;

    maior (m, n);
}


