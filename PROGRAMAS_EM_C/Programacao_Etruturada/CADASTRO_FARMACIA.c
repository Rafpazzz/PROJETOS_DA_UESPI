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
int numero_cliente_dinamico = 0;
FILE *arq;
FILE *arq_prod;
FILE *arq_ped;

//estrutura em ponteiros
typedef struct no {
	char descricao[50];
	struct no *ponteiro_lista_cliente;
	struct no *ponteiro_lista_pedidos;
	struct no *ponteiro_lista_produtos;
	int quantProd;
	int quantPed;
	int quantCliente;
	struct no *prox;
}descritor;

typedef struct Cliente_Dinamico{
	char nome[30];
	char cpf[11];
	struct Cliente_Dinamico *prox;
}cliente_dinamico;

cliente_dinamico *inicio_cliente;
descritor *descritor_dinamico;

void cria_cliete() {
	inicio_cliente = NULL;
}

void cria_descritor() {
	descritor_dinamico = (descritor *)malloc(sizeof(descritor));
    if (descritor_dinamico == NULL) {
        printf("Erro ao alocar memória para o descritor.\n");
		exit(1);
	}
        
	strcpy(descritor_dinamico->descricao,"Cadastro de Farmacia - Drogarias UESPI");
	descritor_dinamico->ponteiro_lista_cliente = NULL;
	descritor_dinamico->ponteiro_lista_produtos = NULL;
	descritor_dinamico->ponteiro_lista_pedidos = NULL;
	descritor_dinamico->quantCliente = 0;
	descritor_dinamico->quantPed = 0;
	descritor_dinamico->quantProd = 0;
}

void Insere_cliente(char nome[30], char cpf[11]) {
	cliente_dinamico *novo_Cliente;

	novo_Cliente = (cliente_dinamico*) malloc(sizeof(cliente_dinamico));
	
	strcpy(novo_Cliente->nome, nome);
	strcpy(novo_Cliente->cpf, cpf);
	novo_Cliente->prox = NULL;
	numero_cliente_dinamico++;
	descritor_dinamico->quantCliente = numero_cliente_dinamico;
	
	if(inicio_cliente == NULL){
		inicio_cliente = novo_Cliente;
		descritor_dinamico->ponteiro_lista_cliente = novo_Cliente;
	}else {
		novo_Cliente->prox = inicio_cliente;
		inicio_cliente = novo_Cliente;
		
	}
	
}

void imprime_descritor_clientes() {
	printf("Descrição: %s\n", descritor_dinamico->descricao);
	printf("Endereço lista Cliente: %p\n", descritor_dinamico->ponteiro_lista_cliente);
	printf("Endereço lista Pedidos: %p\n", descritor_dinamico->ponteiro_lista_pedidos);
	printf("Endereço lista Produtos: %p\n", descritor_dinamico->ponteiro_lista_produtos);
	printf("Qunatidade clientes: %d\n", descritor_dinamico->quantCliente);
	printf("Quantidade de Pedidos: %d\n", descritor_dinamico->quantPed);
	printf("Quantidade de Produtos: %d\n", descritor_dinamico->quantProd);
}

void imprime_cliente_dinamico(){
	cliente_dinamico *ptr;
	if(inicio_cliente == NULL) {
		printf("Lista vazia\n");
		return;
	}
	ptr = inicio_cliente;
	while(ptr!= NULL) {
		printf("nome: %s //// cpf: %s\n", ptr->nome, ptr->cpf);
		ptr = ptr->prox;
	}
}

//declara a STRUCT(estrutura heterogenea) para guardar cliente
typedef struct {
	char nome[30];
	char cpf[11];
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
    //char cpf[11];
    //int codigoPe;
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

void exibirFidelidade(fidelidade cadFideli[50]) {
    printf("\nExibir fidelidade do cliente");
    int i;
    for(i=0;i<contFideli; i++){
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
    //printf("Informe o codigo do produto: ");
    //scanf(" %d", &r.codigoPe);
   // printf("Informe o CPF do cliente: ");
    //scanf(" %11[^\n]", r.cpf);
    
    contPedido = contPedido + 1;
    return r;
}

void exibiPedido(pedido cadPe[50]){
    printf("\nExibir pedido do cliente");
    int i;
    for(i=0;i<contPedido; i++){
        
            printf("\nCODIGO.........[%d]", i+1);
		    printf("\nNome do pdoficional ...........: %s", cadPe[i].nome_proficional);
		    printf("\nNome do produto ...........: %s", cadPe[i].nome_produto);
		    printf("\nForma de pagamento ..........: %s", cadPe[i].forma_pagamento);
		    printf("\nQuantidade de produtos comprados ..........: %d", cadPe[i].quantidade_comprar);
		    printf("\nValor final da compra ..........: %.2f\n", cadPe[i].valor_final);
			printf("\n");
            
    }
    
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

void exibirProduto(produto cadP[50]) {
	printf("\n ExibiC'C#o do cadastro do Produto ");
	int i;
	for(i=0;i<contProd; i++) {
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
	int i = 0;
	for(i=0;i<contProd; i++) {
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
	scanf(" %30[^\n]", c.nome);
	
	//FILE *fp;
	//if((fp=fopen("Armazenamento_clientes.txt","a"))==NULL)
	//{ printf("O arquivo nao pode ser aberto");
	//system("Pause");
	//exit(1);
	//}
	//strcat(c.nome, "\n");
	//fputs(c.nome, fp);
	
	printf ("Informe o CPF do cliente: ");
	scanf(" %11[^\n]", c.cpf);
	cont++;

	return c;
}

void Armazena_arquivo(cliente cad[50]) {
	if((arq=fopen("Armazenamento_clientes.txt","r+"))==NULL)
	{ printf("O arquivo nao pode ser aberto");
	system("Pause");
	exit(1);
	}
	int i;
	for(i = 0; i<cont; i++){
		strcat(cad[i].nome, "\n");
		fputs(cad[i].nome, arq);
		strcat(cad[i].cpf, "\n");
		fputs(cad[i].cpf, arq);
	} 
}

void Armazena_arquivo_Produto(produto cadP[50]) {
	if((arq_prod=fopen("Armazenamento_produtos.txt","r+"))==NULL)
	{ printf("O arquivo nao pode ser aberto");
	system("Pause");
	exit(1);
	}
	int i;
	for(i = 0; i<contProd; i++){
		fprintf(arq_prod,"%s\n" ,cadP[i].nome_produto);
		fprintf(arq_prod, "%.2f\n",cadP[i].dosagem);
		fprintf(arq_prod, "%s\n",cadP[i].composicao);
		fprintf(arq_prod, "%s\n",cadP[i].tipo_produto);
		fprintf(arq_prod, "%.2d\n",cadP[i].quantidade_produto);
		fprintf(arq_prod, "%s\n",cadP[i].fabricante);
		fprintf(arq_prod, "%.2f\n",cadP[i].valor);
		fprintf(arq_prod, "%s\n",cadP[i].tarja);
		fprintf(arq_prod, "%s\n",cadP[i].receita);
		fprintf(arq_prod, "%s\n",cadP[i].validade);
		fprintf(arq_prod, "%d\n",cadP[i].codigo);
	/*	strcat(cadP[i].nome_produto, "\n");
		fputs(cadP[i].nome_produto, arq_prod);
		
		//if(fwrite(&pi, sizeof(float), 1,pf) != 1)
		fwrite(&cadP[i].dosagem, sizeof(float), 1, arq_prod);
		strcat(cadP[i].composicao, "\n");
		fputs(cadP[i].composicao, arq_prod);
		strcat(cadP[i].tipo_produto, "\n");
		fputs(cadP[i].tipo_produto, arq_prod);
		//strcat(cadP[i].quantidade_produto, "\n");
		strcat(cadP[i].fabricante, "\n");
		fputs(cadP[i].fabricante, arq_prod);
		//strcat(cadP[i].valor, "\n");
		strcat(cadP[i].tarja, "\n");
		fputs(cadP[i].tarja, arq_prod);
		strcat(cadP[i].receita, "\n");
		fputs(cadP[i].receita, arq_prod);
		strcat(cadP[i].validade, "\n");
		fputs(cadP[i].validade, arq_prod);
		//strcat(cadP[i].codigo, "\n");*/
		
	} 
}

void Armazena_arquivo_Pedido(pedido cadPe[50]) {
	if((arq_ped=fopen("Armazenamento_pedidos.txt","r+"))==NULL)
	{ printf("O arquivo nao pode ser aberto");
	system("Pause");
	exit(1);
	}
	int i;
	for(i = 0; i<contPedido; i++){
		fprintf(arq_ped,"%s\n" ,cadPe[i].nome_proficional);
		fprintf(arq_ped, "%s\n", cadPe[i].forma_pagamento);
		fprintf(arq_ped, "%d\n", cadPe[i].quantidade_comprar);
		fprintf(arq_ped, "%f\n", cadPe[i].valor_final);
		fprintf(arq_ped, "%s\n", cadPe[i].nome_produto);
	} 
}


void exibircliente (cliente cad[50]) {
	printf("\n ExibiC'C#o de Cadastro Cliente   \n");
	int j;
	for (j=0;j<cont; j++) {
		printf("\nCODIGO..........[%d]", j+1);
		printf("\nNome ...........: %s", cad[j].nome);
		printf("\nCPF ..........: %s", cad[j].cpf);

	}
}

int busca_cpf(cliente cad[50], char cpf[11]) {
	int i;
    for(i=0;i<cont; i++) {
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
    int i;
    for(i=0;i<contProd; i++){
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
	char cpf_cliente[11];
	cria_cliete();
	cria_descritor();
	
	fopen("Armazenamento_clientes.txt","r+");
	fopen("Armazenamento_produtos.txt","r+");
	fopen("Armazenamento_pedidos.txt", "r+");

	do {
		printf ("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE\n 3 p/ CADASTRAR PRODUTO\n 4 p/ EXIBIR PRODUTO\n  5 p/ CADASTRAR PEDIDO\n 6 p/ EXIBIR PEDIDO\n 7 p/ CADASTRAR FIDELIDADE\n 8 P/ EXIBIR FIDELIDADE\n 9 P/ ADICIONAR PROMOÇÃO\n  10 P/ ARMAZENAR NO ARQUIVO DE CLIENTES\n 11 P/ ARMAZENAR NO ARQUIVO DE PRODUTOS\n 12 P/ ARMAZENAR NO ARQUIVO DE PEDIDOS\n 13 P/ ARMAZENAR CLIENTE DINAMICO\n 14 P/ IMPRIMIR CLIENTE DINAMICO\n 15 P/ IMPRIMIR DESCRITOR CLIENTE ***** 16 SAIR");

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
		    
            printf("Infome o CPF do cliente: ");
            scanf(" %11[^\n]", cpf_cliente);
            busca_cpf(cad, cpf_cliente);
		    if(busca_cpf(cad, cpf_cliente) == 1){
		            //printf("CPF do cliente %s esta cadastrado\n", cad[i].nome);
		            int codigo_produto;
		            printf("Infome o codigo do produto: ");
		            scanf("%d", &codigo_produto);
			        busca_codigo(cadP, codigo_produto);
			        if(busca_codigo(cadP, codigo_produto)==1) {
				        //printf("Produto consta o sistema.\n");
				        cadPe [iPedido] = cadastroPedido();
		                iPedido++;
				        break;
			        }else {
				        printf("Produto nao consta no sistema. Processamento do pedido finalizado\n");
                        break;
			        }
		        }else{
		            printf("CPF do cliente nao cadastrado. Processamento do pedido finalizado\n");
		            break;
		        }
		   

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

		case 9: 
		    adicionar_promocao(cadP);
		    break;
		
		case 10:
			Armazena_arquivo(cad);
			break;
		
		case 11:
			Armazena_arquivo_Produto(cadP);
			break;
		
		case 12:
			Armazena_arquivo_Pedido(cadPe);
			break;
		
		case 13:{
			char nome[30];
			char cpf[11];
			printf("Informe o nome Cliente: ");
			scanf(" %30[^\n]", nome);
			printf("Informe o cpf Cliente: ");
			scanf(" %11[^\n]", cpf);
			Insere_cliente(nome, cpf);
		}
			break;
		
		case 14:
			imprime_cliente_dinamico();
			break;
		
		case 15:
			imprime_descritor_clientes();
			break;
		
        case 16:
            printf("saindo do sistema...\n");
            fclose(arq);
            fclose(arq_prod);
			break;
			
        default:
            printf("Opção invalida. Tente novamente. \n");
		};
	}
	while(opc != 16);
	
	return 0;
}

