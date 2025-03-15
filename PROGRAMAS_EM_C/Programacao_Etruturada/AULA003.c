#include <stdio.h>
int main(){
    float imc, peso, altura;
    printf("Informe seu peso: ");
    scanf("%f", &peso);
    printf("Infrome sua altura: ");
    scanf("%f", &altura);
    imc = peso/(altura*altura);
    printf("Seu imc: %f \n", imc);

    if(imc <20){
        printf("Abaixo do peso");
    }else if(imc<=25){
        printf("peso normal");
    }else if(imc <= 30){
        printf("Sobre peso");
    }else if(imc <= 40){
        printf("Obeso");
    }else{
        printf("obeso morbido");
    }

    return 0;
}