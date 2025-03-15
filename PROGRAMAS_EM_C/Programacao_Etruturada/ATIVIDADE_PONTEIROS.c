#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp {
    int dado_inteiro;
    char dado_caractere;
    struct temp *prox;
}no;

no *INICIO_A = NULL;
no *INICIO_B = NULL;
no *INICIO_C = NULL;
int QUANT_A = 0;
int QUANT_B = 0;
int QUANT_C = 0;

void CriaLista() {
    INICIO_A = NULL;
    INICIO_B = NULL;
    INICIO_C = NULL;
}

void IncerirDado_Lista_A(int data) {
    no *ptr_Novo;
    ptr_Novo = (no *) malloc(sizeof(int));

    if(ptr_Novo == NULL) {
        printf("Erro de aolcação.\n");
        return;
    }

    ptr_Novo->dado_inteiro = data;
    ptr_Novo->prox = NULL;

    if(INICIO_A == NULL) {
        INICIO_A = ptr_Novo;
    } else {
        ptr_Novo->prox = INICIO_A;
        INICIO_A = ptr_Novo;
    }
}

void IncerirDado_Lista_B(char data) {
    no *ptr;
    ptr = (no *) malloc(sizeof(char));

    if(ptr == NULL) {
        printf("Erro de alocação.\n");
        return;
    }

    ptr->dado_caractere = data;
    ptr->prox = NULL;

    if(INICIO_B == NULL) {
        INICIO_B = ptr;
    } else {
        ptr->prox = INICIO_B;
        INICIO_B = ptr;
    }
}

void IncerirDado_Lista_C(char data) {
    no *ptr_especial;
    ptr_especial = (no *) malloc(sizeof(char));

    if(ptr_especial == NULL) {
        printf("Erro de alocação.\n");
        return;
    }

    ptr_especial->dado_caractere = data;
    ptr_especial->prox = NULL;

    if(INICIO_C == NULL) {
        INICIO_C = ptr_especial;
    } else {
        ptr_especial->prox = INICIO_C;
        INICIO_C = ptr_especial;
    }
}

void imprime_Lista_Inteiro() {
    no *percorre;
    if(INICIO_A == NULL) {
        printf("Lista vazia\n\n");
        return;
    }

    percorre = INICIO_A;
    while(percorre!=NULL) {
        printf("Info = %d\n",percorre->dado_inteiro);
        percorre = percorre->prox;
    }

    printf("Fim da Lista A.\n");
}

void Imprime_Lista_Caracteres_B() {
    no *percorre;
    if(INICIO_B == NULL) {
        printf("Lista Vazia.\n\n");
        return;
    }

    percorre = INICIO_B;
    while(percorre!=NULL) {
        printf("Info = %c\n", percorre->dado_caractere);
        percorre = percorre->prox;
    }

    printf("Fim da Lista B.\n");
}

void Imprime_Lista_Caracteres_C() {
    no *percorre;
    if(INICIO_C == NULL) {
        printf("Lista Vazia.\n\n");
        return;
    }

    percorre = INICIO_C;
    while(percorre!=NULL) {
        printf("Info = %c\n", percorre->dado_caractere);
        percorre = percorre->prox;
    }

    printf("Fim da Lista C.\n");
}

int Quantidade_Elementos_A() {
    no *ptr;

    if(INICIO_A == NULL) {
        printf("Lista vazia\n\n");
        return 0;
    }

    ptr = INICIO_A;
    while(ptr!=NULL) {
        QUANT_A++;
        ptr = ptr->prox;
    }

    return QUANT_A;
}

int Quantidade_Elementos_B() {
    no *ptr;

    if(INICIO_B == NULL) {
        printf("Lista vazia\n\n");
        return 0;
    }

    ptr = INICIO_B;
    while(ptr!=NULL) {
        QUANT_B++;
        ptr = ptr->prox;
    }

    return QUANT_B;
}

int Quantidade_Elementos_C() {
    no *ptr;

    if(INICIO_C == NULL) {
        printf("Lista vazia\n\n");
        return 0;
    }

    ptr = INICIO_C;
    while(ptr!=NULL) {
        QUANT_C++;
        ptr = ptr->prox;
    }

    return QUANT_C;
}


int main() {
    CriaLista();

    IncerirDado_Lista_A(1);
    IncerirDado_Lista_A(2);
    IncerirDado_Lista_A(3);

    imprime_Lista_Inteiro();
    
    IncerirDado_Lista_B('A');
    IncerirDado_Lista_B('B');
    IncerirDado_Lista_B('C');
    
    Imprime_Lista_Caracteres_B();
    
    IncerirDado_Lista_C('-');
    IncerirDado_Lista_C('+');
    IncerirDado_Lista_C('*');
    
    Imprime_Lista_Caracteres_C();
    
    printf("Quantidade de elementos na Lista A = %d\n",Quantidade_Elementos_A());
    printf("Quantidade de elementos na Lista B = %d\n",Quantidade_Elementos_B());
    printf("Quantidade de elementos na Lista C = %d\n",Quantidade_Elementos_C());
    
    return 0;
}