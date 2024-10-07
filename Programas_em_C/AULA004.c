/*#include <stdlib.h>
#include <stdio.h>
int main()
{ int numero[10];
int cont;

for(cont=0;cont<=9;cont++)
{
printf("Digite um numero:");
scanf("%d",&numero[cont]);
printf("nro digitado: %d\n",numero[cont]);
}
system("PAUSE");
return 0;
}*/

/*#include <stdlib.h>
#include <stdio.h>
int main(){
int numero[2][3];
int i,j;
for(i=0;i<=1;i++) //for para a linha
{
for(j=0;j<=2;j++) //for para a coluna
{
printf("Digite um numero:");
scanf("%d",&numero[i][j]);
//printf("nro digitado:%d\n",numero[i][j]);
}
}

for(i=0;i<=1;i++) //for para a linha
{
for(j=0;j<=2;j++) //for para a coluna
{
//printf("Digite um numero:");
//scanf("%d",&numero[i][j]);
printf("nro digitado:%d\n",numero[i][j]);
}
}
system("PAUSE");
return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float nota[3];
    float notaFinal;

    for(int i = 0; i<3; i++){
        printf("Informe sua nota %d : ",i+1);
        scanf("%f", &nota[i]);    
    }

    notaFinal = (nota[0]*2 + nota[1]*3 + nota[2]*5)/10;

    if(notaFinal>=7){
        printf("Aaprovado");
    }else if(notaFinal<7 && notaFinal>=4){
        printf("Recuperacao");
    }else{
        printf("reprovado");
    }

    return 0;

}