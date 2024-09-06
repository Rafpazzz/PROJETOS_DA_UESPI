#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float quantidadeDeSalarios, salarioMinimo, salarioPessoal, desconto, slarioFinal;

    cout << std:: fixed << std::setprecision(2);

    cout << "Informe seu salario: ";
    cin >>  salarioPessoal;
    cout << "informe o valor do salrio minimo: ";
    cin >> salarioMinimo;

    quantidadeDeSalarios = salarioPessoal/ salarioMinimo;
    desconto = salarioMinimo * 0.08;
    slarioFinal = salarioPessoal - desconto;

    cout << "Aquantidade de salrios minimos referente ao seu salario e: "<< quantidadeDeSalarios<< endl;
    cout << "Seu salario descontado o valo do desconto e: "<<slarioFinal<<endl;

    return 0;
}