//ESTE CODIGO É MERAMENTE UM TESTE FEITO A PARTIR DE UMA PESQUISA APROFUNDADA NO GOOGLE PARA SERVIR DE PARAMETRO PARA O CODIGO PRINCIPAL, QUE CONSTA COM O NOME "CADSTRO_FARMACIA"
//ATECIOSAMENTE RAFAEL PAZ.


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

int i = 0;           // contador para clientes
int cont = 0;        // contador para controle do numero maximo de clientes
int iProd = 0;
int contProd = 0;
int iPedido = 0;
int contPedido = 0;
int iFideli = 0;
int contFideli = 0;

// Declaração das structs
typedef struct {
    char nome[30];
    char cpf[11];
    int fidelidade;
} cliente;

typedef struct {
    char nome_produto[30];
    float dosagem;
    char composicao[50];
    char tipo_produto[30];
    int quantidade_produto;
    char fabricante[30];
    float valor;
    char tarja[20];
    char receita[5];
    char validade[5];
    int codigo;
} produto;

typedef struct {
    char nome_proficional[40];
    char forma_pagamento[30];
    int quantidade_comprar;
    float valor_final;
    char nome_produto[40];
    char cpf[11];
    int codigoPe;
} pedido;

typedef struct {
    int verificacao;        // quantidade de vezes que comprou determinado produto
    int inadimplente;       // controle de inadimplência
    char primeira_compra[5]; // verificar primeira compra para habilitar o desconto
} fidelidade;

// Funções para o cadastro de fidelidade
fidelidade cadastroFidelidade() {
    fidelidade f;
    printf("Informe se é a sua primeira compra [sim/nao]: ");
    scanf(" %5[^\n]", f.primeira_compra);
    printf("Informe quantas vezes foi comprado o produto referente ao pedido: ");
    scanf("%d", &f.verificacao);
    printf("Informe se esse cliente foi inadimplente alguma vez (1 para sim, 0 para não): ");
    scanf("%d", &f.inadimplente);
    
    contFideli++;
    return f;
}

void exibirFidelidade(fidelidade cadFideli[50]) {
    printf("\nExibir fidelidade do cliente");
    for(int i = 0; i < contFideli; i++) {
        printf("\nCODIGO:   %d", i + 1); 
        printf("\nPrimeira compra........: %s", cadFideli[i].primeira_compra);
        printf("\nQuantidade de vezes que foi comprado o mesmo produto........: %d", cadFideli[i].verificacao);
        printf("\nQuantas vezes foi inadimplente........: %d\n", cadFideli[i].inadimplente);
    }
}

// Funções para o cadastro de pedidos
pedido cadastroPedido() {
    pedido r;
    printf("\nInforme o profissional que vendeu o produto: ");
    scanf(" %40[^\n]", r.nome_proficional);
    printf("Informe a forma de pagamento: ");
    scanf(" %30[^\n]", r.forma_pagamento);
    printf("Informe a quantidade de produtos comprados: ");
    scanf("%d", &r.quantidade_comprar);
    printf("Informe o valor final da compra: ");
    scanf("%f", &r.valor_final);
    printf("Informe o nome do produto: ");
    scanf(" %40[^\n]", r.nome_produto);
    printf("Informe o código do produto: ");
    scanf("%d", &r.codigoPe);
    printf("Informe o CPF do cliente: ");
    scanf(" %11[^\n]", r.cpf);

    contPedido++;
    return r;
}

void exibirPedido(pedido cadPe[], int contPedido) {
    printf("\nExibir pedido do cliente");
    for(int i = 0; i < contPedido; i++) {
        printf("\nCODIGO.........[%d]", i + 1);
        printf("\nNome do profissional ...........: %s", cadPe[i].nome_proficional);
        printf("\nNome do produto ...........: %s", cadPe[i].nome_produto);
        printf("\nForma de pagamento ..........: %s", cadPe[i].forma_pagamento);
        printf("\nQuantidade de produtos comprados ..........: %d", cadPe[i].quantidade_comprar);
        printf("\nValor final da compra ..........: %.2f\n", cadPe[i].valor_final);
    }
}

// Funções para o cadastro de produtos
produto cadastroProduto() {
    produto a;
    printf("\nSistema de cadastro de produto\n");
    printf("Informe o nome do produto: ");
    scanf(" %30[^\n]", a.nome_produto);
    printf("Informe a dosagem do produto: ");
    scanf("%f", &a.dosagem);
    printf("Informe a composição do produto: ");
    scanf(" %50[^\n]", a.composicao);
    printf("Informe o tipo do produto [comprimido/dosador/gotas]: ");
    scanf(" %30[^\n]", a.tipo_produto);
    printf("Informe a quantidade de produtos: ");
    scanf("%d", &a.quantidade_produto);
    printf("Informe o fabricante do produto: ");
    scanf(" %30[^\n]", a.fabricante);
    printf("Informe o valor do produto: ");
    scanf("%f", &a.valor);
    printf("Informe a tarja do remédio: ");
    scanf(" %20[^\n]", a.tarja);
    printf("Informe se o remédio precisa de receita [sim/nao]: ");
    scanf(" %5[^\n]", a.receita);
    printf("Informe se o produto está dentro da validade [sim/nao]: ");
    scanf(" %5[^\n]", a.validade);
    printf("Informe o código do produto: ");
    scanf("%d", &a.codigo);

    contProd++;
    return a;
}

void exibirProduto(produto cadP[50]) {
    printf("\nExibição do cadastro do Produto\n");
    for(int i = 0; i < contProd; i++) {
        printf("\nCODIGO.........[%d]", i + 1);
        printf("\nNome do produto ...........: %s", cadP[i].nome_produto);
        printf("\nCódigo do produto ...........: %d", cadP[i].codigo);
        printf("\nDosagem ...........: %.2f", cadP[i].dosagem);
        printf("\nComposição ...........: %s", cadP[i].composicao);
        printf("\nTipo do produto ...........: %s", cadP[i].tipo_produto);
        printf("\nQuantidade em estoque ...........: %d", cadP[i].quantidade_produto);
        printf("\nFabricante ...........: %s", cadP[i].fabricante);
        printf("\nValor ...........: %.2f", cadP[i].valor);
        printf("\nTarja ...........: %s", cadP[i].tarja);
        printf("\nReceita ...........: %s", cadP[i].receita);
        printf("\nDentro da validade ...........: %s\n", cadP[i].validade);
    }
}

// Funções auxiliares
int busca_codigo(produto cadP[50], int cod) {
    for(int i = 0; i < contProd; i++) {
        if(cod == cadP[i].codigo) {
            return 1;
        }
    }
    return -1;
}

int busca_cpf(cliente cad[50], char cpf[11]) {
    for(int i = 0; i < cont; i++) {
        if(strcmp(cad[i].cpf, cpf) == 0) {
            return 1;
        }
    }
    return -1;
}

cliente cadastrarcliente() {
    cliente c;
    printf("\nSistema Cadastrar Clientes\n");
    printf("Informe o nome do cliente: ");
    scanf(" %30[^\n]", c.nome);
    printf("Informe o CPF do cliente: ");
    scanf(" %11[^\n]", c.cpf);

    cont++;
    return c;
}

void exibircliente(cliente cad[]) {
    printf("\nExibição de Cadastro Cliente\n");
    for (int j = 0; j < cont; j++) {
        printf("\nCODIGO..........[%d]", j + 1);
        printf("\nNome ...........: %s", cad[j].nome);
        printf("\nCPF ...........: %s\n", cad[j].cpf);
    }
}

void adicionar_promocao(produto cadP[]) {
    int codigo_prod;
    printf("Informe o código do produto: ");
    scanf("%d", &codigo_prod);
    for(int i = 0; i < contProd; i++) {
        if(codigo_prod == cadP[i].codigo) {
            int promo;
            int data;
            printf("Informe a promoção planejada para o produto (percentual): ");
            scanf("%d", &promo);
            printf("Informe até que dia a promoção será válida: ");
            scanf("%d", &data);

            cadP[i].valor = cadP[i].valor - (cadP[i].valor * (promo / 100.0));
            printf("O valor do produto após a promoção é: %.2f\n", cadP[i].valor);
        } else {
            printf("O produto não está cadastrado no sistema.\n");
        }
    }
}

// Função principal
int main() {
    setlocale(LC_ALL, "portuguese");
    int opc;
    cliente cad[50];
    produto cadP[50];
    pedido cadPe[50];
    fidelidade cadFideli[50];

    do {
        printf("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE\n 3 - CADASTRAR PRODUTO\n 4 - EXIBIR PRODUTO\n 5 - CADASTRAR PEDIDO\n 6 - EXIBIR PEDIDO\n 7 - CADASTRAR FIDELIDADE\n 8 - EXIBIR FIDELIDADE\n 9 - ADICIONAR PROMOÇÃO\n 10 - SAIR");

        printf("\n\n Digite a opção: ");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                cad[i] = cadastrarcliente();
                i++;
                break;
            case 2:
                exibircliente(cad);
                break;
            case 3:
                cadP[iProd] = cadastroProduto();
                iProd++;
                break;
            case 4:
                exibirProduto(cadP);
                break;
            case 5:
                cadPe[iPedido] = cadastroPedido();
                iPedido++;
                contPedido++;
                break;
            case 6:
                for(int j = 0; j < contPedido; j++) {
                    if(busca_cpf(cad, cadPe[j].cpf) == 1) {
                        printf("CPF do cliente %s está cadastrado \n", cad[j].nome);
                    } else {
                        printf("CPF do cliente %s não está cadastrado \n", cad[j].nome);
                    }
                    if(busca_codigo(cadP, cadPe[j].codigoPe) == 1) {
                        printf("Produto consta no sistema.\n");
                    } else {
                        printf("Produto não consta no sistema\n");
                        printf("Cadastre-o imediatamente\n");
                    }
                    exibirPedido(cadPe, contPedido);
                }
                break;
            case 7:
                cadFideli[iFideli] = cadastroFidelidade();
                iFideli++;
                break;
            case 8:
                exibirFidelidade(cadFideli);
                break;
            case 9:
                adicionar_promocao(cadP);
                break;
            case 10:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opc != 10);

    return 0;
}
