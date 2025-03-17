#include <iostream>

using namespace std;




class carro{

private:
    int ano;
    float valor, km;
public:

    void setano(int a){
        this -> ano = a;
    }

    int getano(){
        return ano;
    }

};





class propaganda{

private:
    

public:
    void funcao(){
    
        cout << "Se increva no canal\n";
    }
    void soma(int num1, int num2){
        int somar;

        somar = num1 + num2;
        cout << somar;
    }
};




int main(){

    propaganda outdor;
    int num1, num2;

    //cin >> num1;
    //cin >> num2;

    outdor.funcao();
    //outdor.soma(num1, num2);

    //========================================================================
    
    carro palio;
    int ano;
    ano = 1995;

    palio.setano(ano);
    cout << "Palio: \n";
    cout << "Ano: "<< palio.getano();

    return 0;
}