#include <iostream>
#define pi 3.14;

using namespace std;

void areaCir(double raio){
    double area;

    area = raio*2*pi;
    cout<<"AREA: "<< area;
}

void areaQuad(int l1, int l2){
    double area;

    area= l1*l2;
    cout<<"AREA: "<< area;
}

int main(){
    char* pont = new char[50];
    double raio, l1, l2;

    cout<<"Deseja calcular a area do circulo ou quadrado: ";
    cin>>pont;

    if(*pont ='circulo'){
        cout<<"Informe o raio do circulo: ";
        cin>>raio;
        areaCir(raio);
    }else{
        cout<<"Informe o lado 1: ";
        cin>>l1;
        cout<<"Informe o lado 2: ";
        cin>>l2;
        areaQuad(l1,l2);
    }

}
