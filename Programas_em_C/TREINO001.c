#include <stdio.h>
#include <stdlib.h>

struct registro_Aluno
{
    char nome[30];
    char materia[50];
    float nota1;
    float nota2;
    float nota3;
    float media;

};

float media(float not1, float not2, float not3);

int main(){
    int n = 3;
    struct registro_Aluno aluno[n];


    printf("===========REGISTRO ESCOLAR===========\n");

    for(int i = 0; i < n; i++){

        printf("Informe seu nome: ");
        fflush(stdin);
        fgets(aluno[i].nome, 30, stdin);

        printf("Informe a meteria que deseja calcular a sua media: ");
        fflush(stdin);
        fgets(aluno[i].materia, 50, stdin);


        printf("Informe a primeira nota: ");
        scanf("%f", &aluno[i].nota1);

        printf("Informe a segunda nota: ");
        scanf("%f", &aluno[i].nota2);

        printf("Informe a terceira nota: ");
        scanf("%f", &aluno[i].nota3);

        aluno[i].media = media(aluno[i].nota1,aluno[i].nota2,aluno[i].nota3);

    }

    system("cls");

    printf("========INFORMACOES FINAIS==========\n");

    for(int i = 0; i<n; i++){
        printf("Aluno: %s",aluno[i].nome);
        printf("Materia: %s", aluno[i].materia);
        printf("Media: %2.1f\n", aluno[i].media);
        if(aluno[i].media>=7){
            printf("Aluno aprovado!\n\n");
        }else if(aluno[i].media<7 && aluno[i].media>=4){
            printf("Alnuno de recuperacao!\n\n");
        }else{
            printf("Aluno reprovado!\n\n");
        }
    }
}

float media(float not1, float not2, float not3){
    float mediana = 0;

    mediana = (not1+not2+not3)/3;

    return mediana;
}

