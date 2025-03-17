#include <iostream>


using namespace std;

double areaCir(double raio, double pi){
    return pi*raio*raio;
}

double areaQuad(double l1, double l2){
    return l1*l2;
}

double opera(double num1, double num2, double (*apontaFuncao)(double, double)){
        return apontaFuncao(num1, num2);
}

int main(){
    double pi, raio, lado1, lado2;
    string objeto;

    cout<<"O que deseja calcular: area Circulo ou area Quadrado."<<endl;
    cin>> objeto;

    if(objeto == "circulo" || objeto == "Circulo"){
        cout<<"informe o valor do raio: "<<endl;
        cin>>raio;
        pi = 3.14;
        cout<<"Area: "<< opera(raio, pi, areaCir);
    }else{
        cout<<"Informe o lado do seu quadrado: "<<endl;
        cin>>lado1;
        lado2 = lado1;
        cout<<"Area: "<< opera(lado1,lado2,areaQuad);
    }

}
