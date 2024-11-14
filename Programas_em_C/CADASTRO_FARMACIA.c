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
	char validade[5];
	int codigo;
} produto;

typedef struct{
    char nome_proficional[40];
    char forma_pagamento[30];
    int quantidade_comprar;
    float valor_final;
    char nome_produto[40];
    char cpf[11];
    int codigoPe;
} pedido;

typedef struct {
    int verificacao; //quantas vezes ja comprou determinado produto.
    int inadimplente; //caso a inadimplencia passe de 1, travar a proxima compra.
    char primeira_compra[5]; // verificar primeira compra para abilitar o desconto de 5%.
} fidelidade;

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
            printf("\nQuantas vezes foi inadimplente........: %d\n", cadFideli[i].inadimplente);
        
    }
    
}

pedido cadastroPedido() {
    pedido r;
    
    printf("\nInfrome o proficinal que vendeu o produto: ");
    scanf(" %40[^\n]", r.nome_proficional);
    printf("Informe a forma de pagamento[cartao/dinheiro/pix]: ");
    scanf(" %30[^\n]", r.forma_pagamento);
    printf("Informe a quantidade de produtos comprados: ");
    scanf(" %d", &r.quantidade_comprar);
    printf("informe o valor final da compra: ");
    scanf("%f", &r.valor_final);
    printf("Informe o nome do produto: ");
    scanf(" %40[^\n]", r.nome_produto);
    printf("Informe o codigo do produto: ");
    scanf(" %d", &r.codigoPe);
    printf("Informe o CPF do cliente: ");
    scanf(" %11[^\n]", r.cpf);
    
    contPedido = contPedido + 1;
    return r;
}

pedido exibiPedido(pedido cadPe[50]){
    printf("\nExibir pedido do cliente");
    //for(int i = 0; i<contPedido; i++){
        
            printf("\nCODIGO.........[%d]", i+1);
		    printf("\nNome do pdoficional ...........: %s", cadPe[i].nome_proficional);
		    printf("\nNome do produto ...........: %s", cadPe[i].nome_produto);
		    printf("\nForma de pagamento ..........: %s", cadPe[i].forma_pagamento);
		    printf("\nQuantidade de produtos comprados ..........: %d", cadPe[i].quantidade_comprar);
		    printf("\nValor final da compra ..........: %.2f\n", cadPe[i].valor_final);
			printf("\n");
            
    //}
    
}

produto cadastroProduto() {
	produto a;
	printf("\n Sistema de cadastro de produto\n");
	printf(" Informe o nome do produto: ");
	scanf(" %30[^\n]", a.nome_produto);
	printf("Informe o dosagem do produto: ");
	scanf(" %f", &a.dosagem);
	printf("Informe a composicao do produto: ");
	scanf(" %50[^\n]", a.composicao);
	printf("Informe o tipo do produto[comprimido/dosador/gotas/]: ");
	scanf(" %30[^\n]", a.tipo_produto);
	printf("informe a quantidade de produtos: ");
	scanf(" %d", &a.quantidade_produto);
	printf("Informe o fabricante do produto: ");
	scanf(" %30[^\n]", a.fabricante);
	printf("Informe o valor do produto: ");
	scanf("%f", &a.valor);
	printf("Informe a tarja do remedio: ");
	scanf(" %20[^\n]", a.tarja);
	printf("informe se o remedio precisa de receita[sim/não]: ");
	scanf(" %5[^\n]", a.receita);
	printf("Infome se o produto esta dentro da validade[sim/nao]: ");
	scanf(" %5[^\n]", a.validade);
	printf("Informe o codigo: ");
	scanf("%d", &a.codigo);
	contProd++;

	return a;
}

produto exibirProduto(produto cadP[50]) {
	printf("\n ExibiC'C#o do cadastro do Produto ");
	for(int i = 0; i<contProd; i++) {
		printf("\nCODIGO...........[%d]", i+1);
		printf("\nNome do produto ...........: %s", cadP[i].nome_produto);
		printf("\nodigo do produto .........:%d", cadP[i].codigo);
		printf("\nDosagem ..........: %f", cadP[i].dosagem);
		printf("\nComposição ..........: %s", cadP[i].composicao);
		printf("\nTipo do produto ..........: %s", cadP[i].tipo_produto);
		printf("\nQuantidade em estoque ..........: %d", cadP[i].quantidade_produto);
		printf("\nFabricante ..........: %s", cadP[i].fabricante);
		printf("\nValor ..........: %.2f", cadP[i].valor);
		printf("\nTarja ..........: %s", cadP[i].tarja);
		printf("\nReceita ..........: %s", cadP[i].receita);
		printf("\nDentro da validade ..........: %s\n", cadP[i].validade);
		
	}
}

int busca_codigo(produto cadP[50], int cod) {
	for(int i = 0; i<contProd; i++) {
	    if(cod == cadP[i].codigo) {
			return 1;  
	    }
		
	}

	return -1;
}


cliente cadastrarcliente() {
	cliente c;
	printf ("\n Sistema Cadastrar Clientes\n");
	printf ("Informe o nome do cliente: ");
	scanf(" %30[^\n]", c.nome); //ler atC) 30 caracteres separados por espaC'o
	printf ("Informe o CPF do cliente: ");
	scanf(" %11[^\n]", c.cpf);
	cont++;

	return c;
}




cliente exibircliente (cliente cad[50]) {
	printf("\n ExibiC'C#o de Cadastro Cliente   \n");
	for (int j=0; j<cont; j++) {
		printf("\nCODIGO..........[%d]", j+1);
		printf("\nNome ...........: %s", cad[j].nome);
		printf("\nCPF ..........: %s", cad[j].cpf);

	}
}

int busca_cpf(cliente cad[50], char cpf[11]) {
    for(int i = 0; i<cont; i++) {
            if(strcmp(cad[i].cpf, cpf) == 0) {
			return 1;
        }
        
    }
    return -1;
}

void adicionar_promocao(produto cadP[50]) {
    int codigo_prod;
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo_prod);
    for(int i = 0; i<contProd; i++){
        if(codigo_prod == cadP[i].codigo) {
            int promo;
            int data;
            printf("Informe a promoção planejada para o produto: ");
            scanf("%d", &promo);
            printf("Informe ate que dia a promoção sera valida: ");
            scanf("%d", &data);
    
            cadP[i].valor = cadP[i].valor - (cadP[i].valor*(promo/100));
    
            printf("o valor do produto depos da promoção é : %f", cadP[i].valor);
        } else {
            printf("Produto nao listado.");
        }
    }
    
    
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	int opc;
	cliente cad[50]; //cria lista de 50 cliente
	produto cadP[50];
	pedido cadPe[50];
	fidelidade cadFideli[50];

	do {
		printf ("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE\n 3 p/ CADASTRAR PRODUTO\n 4 p/ EXIBIR PRODUTO\n  5 p/ CADASTRAR PEDIDO\n 6 p/ EXIBIR PEDIDO\n 7 p/ CADASTRAR FIDELIDADE\n 8 P/ EXIBIR FIDELIDADE\n 9 P/ ADICIONAR PROMOÇÃO\n  ***** 10 SAIR");

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
		    cadPe [iPedido] = cadastroPedido();
		    iPedido++;
		    break;

		case 6 :

            for(int i = 0; i<contPedido; i++){
                busca_cpf(cad, cadPe[i].cpf);
		        if(busca_cpf(cad, cadPe[i].cpf) == 1){
		            printf("CPF do cliente %s esta cadastrado\n", cad[i].nome);
		        }else{
		            printf("CPF do cliente %s nao cadastrado \n", cad[i].nome);
		        }
           
		    
		    
			    busca_codigo(cadP, cadPe[i].codigoPe);
			    if(busca_codigo(cadP, cadPe[i].codigoPe)==1) {
				    printf("Produto consta o sistema.\n");
			    }else {
				    printf("Produto nao consta no sistema\n");
                    printf("Cadastre-o imediatamente\n");
			    }
		    exibiPedido(cadPe);
            }

			
		    break;

		case 7 :
		    cadFideli[iFideli] = cadastroFidelidade();
		    iFideli++;
		    break;

		case 8 : 
		    exibirFidelidade(cadFideli);
		    break;

		case 9: 
		    adicionar_promocao(cadP);
		    break;
		
        case 10:
            printf("saindo do sistema...\n");
			break;
        default:
            printf("Opção invalida. Tente novamente. \n");
		};
	}
	while(opc != 10);
	
	return 0;
}





