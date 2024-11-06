#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>


int i=0;//inicializa i contador para quantidade de clientes inseridos
int cont=0; //inicializa contador para controle do numero maximo de clientes
int iProd = 0;
int contProd = 0;
int iPedido = 0;
int contPedido = 0;
int iFideli = 0;
int contFideli = 0;


//declara a STRUCT(estrutura heterogenea) para guardar cliente
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
} produto;

typedef struct{
    char nome_proficional[40];
    char forma_pagamento[30];
    int quantidade_comprar;
    float valor_final;
    char cpf_cliente[40];
    char nome_produto[40];
} pedido;

typedef struct {
    int verificacao; //quantas vezes ja comprou determinado produto.
    int inadimplente; //caso a inadimplencia passe de 1, travar a proxima compra.
    char primeira_compra[5]; // verificar primeira compra para abilitar o desconto de 5%.
} fidelidade;

cliente cadastrarcliente()
{
	cliente c;
	printf ("\n Sistema Cadastrar Clientes ");
	printf ("\n Informe o nome: ");
	scanf(" %30[^\n]", c.nome); //ler atC) 30 caracteres separados por espaC'o
	printf ("Informe o CPF: ");
	scanf(" %11[^\n]", c.cpf);
	cont++;

	return c;
}




cliente exibircliente (cliente cad[])
{
	printf("\n ExibiC'C#o de Cadastro Cliente   \n");
	for (int j=0; j<cont; j++) {
		printf("\n     CODIGO:   %d", j+1);
		printf("\nNome ...........: %s", cad[j].nome);
		printf("\nCPF ..........: %s", cad[j].cpf);

	}
}


pedido cadastroPedido() {
    pedido r;
    
    printf("Infrome o proficinal que vendeu o produto: ");
    scanf(" %40[^\n]", r.nome_proficional);
    printf("Informe a forma de pagamento: ");
    scanf(" %30[^\n]", r.forma_pagamento);
    printf("Informe a quantidade deprodutos comprados: ");
    scanf(" %d", &r.quantidade_comprar);
    printf("informe o valor finalç da compra: ");
    scanf("%f", &r.valor_final);
    printf("\n Informe o CPF do cliente: ");
    scanf(" %40[^\n]", r.cpf_cliente);
    printf("\n Informe o nome do produto: ");
    scanf(" %40[^\n]", r.nome_produto);
    
    contPedido++;
    return r;
}

pedido exibiPedido(pedido cadPe[50]){
    printf("\nExibir pedido do cliente");
    for(int i = 0; i<contPedido; i++){
        printf("\n     CODIGO:   %d", i+1);
        printf("Informações do produto: \n");
		printf("\nNome do pdoficional ...........: %s", cadPe[i].nome_proficional);
		printf("\nCPF do cliente ...........: %s", cadPe[i].cpf_cliente);
		printf("\nNome do produto ...........: %s", cadPe[i].nome_produto);
		printf("\nCPF ..........: %s", cadPe[i].forma_pagamento);
		printf("\nCPF ..........: %d", cadPe[i].quantidade_comprar);
		printf("\nCPF ..........: %f", cadPe[i].valor_final);
        
    }
    
}

produto cadastroProduto() {
	produto a;
	printf("\n Sistema de cadastro de produto ");
	printf("\n Informe o nome do produto: ");
	scanf(" %30[^\n]", a.nome_produto);
	printf("\n Informe o dosagem do produto: ");
	scanf(" %f", &a.dosagem);
	printf("\n Informe a composicao do produto: ");
	scanf(" %50[^\n]", a.composicao);
	printf("\n Informe o tipo do produto[comprimido/dosador/gotas/]: ");
	scanf(" %30[^\n]", a.tipo_produto);
	printf("\n informe a quantidade de produtos: ");
	scanf(" %d", &a.quantidade_produto);
	printf("\n Informe o fabricante do produto: ");
	scanf(" %30[^\n]", a.fabricante);
	printf("\n Informe o valor do produto: ");
	scanf("%f", &a.valor);
	printf("\n Informe a tarja do remedio: ");
	scanf(" %20[^\n]", a.tarja);
	printf("\n informe se o remedio precisa de receita[sim/não]: ");
	scanf(" %5[^\n]", a.receita);
	contProd++;

	return a;
}

produto exibirProduto(produto cadP[50]) {
	printf("\n ExibiC'C#o do cadastro do Produto ");
	for(int i = 0; i<contProd; i++) {
		printf("\n     CODIGO:   %d", i+1);
		printf("\nNome do produto ...........: %s", cadP[i].nome_produto);
		printf("\nDosagem ..........: %f", cadP[i].dosagem);
		printf("\nComposição ..........: %s", cadP[i].composicao);
		printf("\nTopo do produto ..........: %s", cadP[i].tipo_produto);
		printf("\nQuantidade em estoque ..........: %d", cadP[i].quantidade_produto);
		printf("\nFabricante ..........: %s", cadP[i].fabricante);
		printf("\nValor ..........: %f", cadP[i].valor);
		printf("\nTarja ..........: %s", cadP[i].tarja);
		printf("\nReceita ..........: %s", cadP[i].receita);
		
	}
}

fidelidade cadastroFidelidade() {
    fidelidade f;
    printf("Informe se é a sua primeira compra[sim/nao]");
    scanf(" %5[^\n]", f.primeira_compra);
    printf("Informe quantas vez foi comprado o produto referente ao pedido cadastrado anteriormente: ");
    scanf("%d", &f.verificacao);
    printf("Informe se esse liente foi inadimplente alguma vez: ");
    scanf("%d", &f.inadimplente);
    
    contFideli++;
    return f;
}

fidelidade exibirFidelidade(fidelidade cadFideli[50]) {
    printf("\nExibir fidelidade do cliente");
    for(int i = 0; i<contFideli; i++) {
        printf("\n CODIGO:   %d", i+1); 
            printf("\nPrimera compra........: %s", cadFideli[i].primeira_compra);
            printf("\nQuantidade de vezes que foi comprado o mesmo produto........: %d", cadFideli[i].verificacao);
            printf("\nQuantas vezes foi inadimplente........: %d", cadFideli[i].inadimplente);
        
    }
    
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	int opc;
	cliente cad[50]; //cria lista (vetor- estrutura homogenea) para armazenamento de 50 cliente
	produto cadP[50];
	pedido cadPe[50];
	fidelidade cadFideli[50];

	do {
		printf ("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE\n 3 p/ CADASTRAR PRODUTO\n 4 p/ EXIBIR PRODUTO\n  5 p/ CADASTRAR PRODUTO\n 6 p/ EXIBIR PRODUTO\n 7 p/ CADASTRAR FIDELIDADE\n 8 P/ EXIBIR FIDELIDADE     **** 9 SAIR");
		printf ("\n\n Digite a opC'C#o:     ");
		scanf ("%d", &opc);
		switch(opc) {
		case 1 :
			cad [i]=cadastrarcliente();
			i++;
			break;
		case 2 :
			exibircliente(cad);
			break;
		case 3 :
			cadP [iProd] = cadastroProduto();
			iProd++;
			break;
		case 4 :
			exibirProduto(cadP);
			break;
		case 5 :
		    cadPe [i] = cadastroPedido();
		    iPedido++;
		    break;
		case 6 : 
		    exibiPedido(cadPe);
		    break;
		case 7 :
		    cadFideli[iFideli] = cadastroFidelidade();
		    iFideli++;
		    break;
		case 8 : 
		    exibirFidelidade(cadFideli);
		    break;
			printf ("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE 3 p/ CADASTRAR PRODUTO\N 4 p/ EXIBIR PRODUTO 5 p/ CADASTRAR PRODUTO\N 6 p/ EXIBIR PRODUTO\n 7 p/ CADASTRAR FIDELIDADE\n 8 P/ EXIBIR FIDELIDADE     **** 9 SAIR");
		};
	}
	while(opc != 9);
}


