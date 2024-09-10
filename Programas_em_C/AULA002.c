#include <stdio.h>


int main(){
    int anosInpresa;
    float salario, salarioFinal;

    printf("Informe quantos anos trabalhou nesta empresa: ");
    scanf("%d", &anosInpresa);
    printf("Informe seu salario: ");
    scanf("%f", &salario);

    if(anosInpresa >= 5){
        salarioFinal = salario + (salario*0.2);
        printf("Seu salario pro contribuir em 5 anos com a empresa: %.2f", salarioFinal);
    }else{
        salarioFinal = salario + (salario*0.1);
        printf("Seu salario: %.2f", salarioFinal);
    }

    return 0;
}