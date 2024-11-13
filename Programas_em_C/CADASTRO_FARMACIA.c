#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

int i = 0; // Inicializa i contador para quantidade de clientes inseridos
int cont = 0; // Inicializa contador para controle do número máximo de clientes
int iProd = 0;
int contProd = 0;
int iPedido = 0;
int contPedido = 0;
int iFideli = 0;
int contFideli = 0;

// Declara a STRUCT (estrutura heterogênea) para guardar cliente
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
} pedido;

typedef struct {
    int verificacao; // Quantas vezes já comprou determinado produto.
    int inadimplente; // Caso a inadimplência passe de 1, travar a próxima compra.
    char primeira_compra[5]; // Verificar primeira compra para habilitar o desconto de 5%.
} fidelidade;

// Funções de cadastro de fidelidade
fidelidade cadastroFidelidade() {
    fidelidade f;
    printf("Informe se é a sua primeira compra [sim/nao]: ");
    scanf(" %5[^\n]", f.primeira_compra);
    printf("Informe quantas vezes foi comprado o produto referente ao pedido cadastrado anteriormente: ");
    scanf("%d", &f.verificacao);
    printf("Informe se esse cliente foi inadimplente alguma vez (0 para não, 1 para sim): ");
    scanf("%d", &f.inadimplente);
    
    contFideli++;
    return f;
}

fidelidade exibirFidelidade(fidelidade cadFideli[50]) {
    printf("\nExibir fidelidade dos clientes:\n");
    for (int i = 0; i < contFideli; i++) {
        printf("\nCODIGO:   %d", i + 1); 
        printf("\nPrimeira compra: %s", cadFideli[i].primeira_compra);
        printf("\nQuantidade de vezes que comprou o mesmo produto: %d", cadFideli[i].verificacao);
        printf("\nQuantas vezes foi inadimplente: %d\n", cadFideli[i].inadimplente);
    }
}

// Funções de cadastro de pedido
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
    
    contPedido++;
    return r;
}

void exibirPedido(pedido cadPe[50]) {
    printf("\nExibir pedidos:\n");
    for (int i = 0; i < contPedido; i++) {
        printf("\nCODIGO:   %d", i + 1);
        printf("\nNome do profissional: %s", cadPe[i].nome_proficional);
        printf("\nNome do produto: %s", cadPe[i].nome_produto);
        printf("\nForma de pagamento: %s", cadPe[i].forma_pagamento);
        printf("\nQuantidade de produtos comprados: %d", cadPe[i].quantidade_comprar);
        printf("\nValor final da compra: %.2f\n", cadPe[i].valor_final);
    }
}

// Funções de cadastro de produto
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
    printf("Informe se o remédio precisa de receita [sim/não]: ");
    scanf(" %5[^\n]", a.receita);
    printf("Informe se o produto está dentro da validade [sim/nao]: ");
    scanf(" %5[^\n]", a.validade);
    printf("Informe o código do produto: ");
    scanf("%d", &a.codigo);
    contProd++;

    return a;
}

void exibirProduto(produto cadP[50]) {
    printf("\nExibir cadastro de produto:\n");
    for (int i = 0; i < contProd; i++) {
        printf("\nCODIGO:   %d", i + 1);
        printf("\nNome do produto: %s", cadP[i].nome_produto);
        printf("\nCódigo do produto: %d", cadP[i].codigo);
        printf("\nDosagem: %.2f", cadP[i].dosagem);
        printf("\nComposição: %s", cadP[i].composicao);
        printf("\nTipo do produto: %s", cadP[i].tipo_produto);
        printf("\nQuantidade em estoque: %d", cadP[i].quantidade_produto);
        printf("\nFabricante: %s", cadP[i].fabricante);
        printf("\nValor: %.2f", cadP[i].valor);
        printf("\nTarja: %s", cadP[i].tarja);
        printf("\nReceita: %s", cadP[i].receita);
        printf("\nDentro da validade: %s\n", cadP[i].validade);
    }
}

int busca_codigo(int codigo, produto cadP[50]) {
    for (int i = 0; i < contProd; i++) {
        if (codigo == cadP[i].codigo) {
            return 1;
        }
    }
    return -1;
}

cliente cadastrarCliente() {
    cliente c;
    printf("\nSistema de Cadastro de Clientes\n");
    printf("Informe o nome do cliente: ");
    scanf(" %30[^\n]", c.nome);
    printf("Informe o CPF do cliente: ");
    scanf(" %11[^\n]", c.cpf);
    cont++;

    return c;
}

void exibirCliente(cliente cad[]) {
    printf("\nExibir cadastro de clientes:\n");
    for (int j = 0; j < cont; j++) {
        printf("\nCODIGO:   %d", j + 1);
        printf("\nNome: %s", cad[j].nome);
        printf("\nCPF: %s\n", cad[j].cpf);
    }
}

int busca_cpf(char client[], cliente cad[50]) {
    for (int i = 0; i < cont; i++) {
        if (strcmp(client, cad[i].cpf) == 0) {
            return 1;
        }
    }
    return -1;
}

void adicionar_promocao(produto cadP[]) {
    int codigo_prod;
    printf("Informe o código do produto: ");
    scanf("%d", &codigo_prod);
    for (int i = 0; i < contProd; i++) {
        if (codigo_prod == cadP[i].codigo) {
            int promo;
            printf("Informe a porcentagem da promoção: ");
            scanf("%d", &promo);
            cadP[i].valor = cadP[i].valor - (cadP[i].valor * (promo / 100.0));
            printf("O valor do produto após a promoção é: %.2f\n", cadP[i].valor);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int opc;
    cliente cad[50];  // Lista de 50 clientes
    produto cadP[50];
    pedido cadPe[50];
    fidelidade cadFideli[50];

    do {
        printf("\nSISTEMA CADASTRO\n");
        printf("1 - CADASTRAR CLIENTE\n");
        printf("2 - EXIBIR CLIENTE\n");
        printf("3 - CADASTRAR PRODUTO\n");
        printf("4 - EXIBIR PRODUTO\n");
        printf("5 - CADASTRAR PEDIDO\n");
        printf("6 - EXIBIR PEDIDO\n");
        printf("7 - CADASTRAR FIDELIDADE\n");
        printf("8 - EXIBIR FIDELIDADE\n");
        printf("9 - BUSCAR CPF\n");
        printf("10 - ADICIONAR PROMOÇÃO\n");
        printf("11 - BUSCAR CÓDIGO PRODUTO\n");
        printf("12 - SAIR\n");
        printf("\nDigite a opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cad[i] = cadastrarCliente();
                i++;
                break;
            case 2:
                exibirCliente(cad);
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
                break;
            case 6:
                exibirPedido(cadPe);
                break;
            case 7:
                cadFideli[iFideli] = cadastroFidelidade();
                iFideli++;
                break;
            case 8:
                exibirFidelidade(cadFideli);
                break;
            case 9:
                {
                    char cpf[11];
                    printf("Informe o CPF que deseja buscar: ");
                    scanf(" %11[^\n]", cpf);
                    if (busca_cpf(cpf, cad) == 1) {
                        printf("CPF cadastrado.\n");
                    } else {
                        printf("CPF não cadastrado.\n");
                    }
                }
                break;
            case 10:
                adicionar_promocao(cadP);
                break;
            case 11:
                {
                    int codigo_prod;
                    printf("Informe o código do produto: ");
                    scanf("%d", &codigo_prod);
                    if (busca_codigo(codigo_prod, cadP) == 1) {
                        printf("Produto encontrado.\n");
                    } else {
                        printf("Produto não encontrado.\n");
                    }
                }
                break;
            case 12:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opc != 12);

    return 0;
}
