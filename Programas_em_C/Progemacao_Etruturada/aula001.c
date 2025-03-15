#include <stdio.h>

int main() 
{
   float valorProduto, valorParcela;
   int formaPagamento;

    printf("Insira o valor do produto: ");
    scanf("%f", &valorProduto);
    printf("----SELECIONE A FORMA DE PAGAMENTO----\n");
    printf("Pagamento a vista[1]\n");
    printf("Pagamento em 2x [2](acrecimo de 10%% no valor do produto)\n");
    printf("Pagmento em 3x [3] (acrecimo de 20%% no valor do produto)\n");
    scanf("%d", &formaPagamento);

    switch (formaPagamento)
    {
    case 1:
        printf("Pagamento a vista do valor de %f", valorProduto);
        break;
    case 2:
        valorParcela = valorProduto + (valorProduto*0.2);
        printf("Pagamento em duas vezes com o valor de %f para cada parcela",valorParcela);
        break;
    case 3:
        valorParcela = valorProduto+ (valorProduto*0.3);
        printf("Pagamento em tres vezies com o valor de %f para cada parcela", valorParcela);
        break;

    default:
        printf("Valor invalido");
        break;
    }
   
   return 0;
}
