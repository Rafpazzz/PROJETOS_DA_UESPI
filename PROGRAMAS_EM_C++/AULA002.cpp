#include <iostream>
#define pi 3.14;
#define curtir "Curta esse video\n";
//int t;


using namespace std;

void inscrever(){
    cout << "Se inscreva no canal do XXXXXXXXXXX"<< endl;

}

int somar (int &num1, int num2){
    int soma;
    int t;    
    t = 1;
    soma = num1 + num2;
    num1 = 30;
    num2 = 4;
    cout<<t<<endl;
    return soma;
}

int main(){
    
    int n, m;
    int t;
    t = 0;

    cout<<"Insira um numero= ";
    cin>> n;
    cout<<"Insira um numero= ";
    cin>> m;

    cout<< somar(n, m)<< endl;
    cout<< "valor de n="<< n<<endl;
    cout <<"valor t do main: "<<t<<endl;
    //o programa roda mas se mudar algo na proxima linha na parte somar da merda.
    //cout<<"valor de t somar: "<<somar<<endl;
    cout << pi;
    cout<<" "<<endl;
    cout << curtir;

    inscrever();

    return 0;
}