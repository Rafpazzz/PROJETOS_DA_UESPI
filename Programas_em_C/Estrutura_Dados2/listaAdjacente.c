#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aux{
    int dado;
    struct aux *prox;
}ElemLista, *PONT;

typedef struct {
    int QuantVertice;
    int QuantAerestas;
    ElemLista** A; //array de ponteiros de ElemLista, onde cada elemento representa um vertice e aponta para uma lista de vertice adjacente(ao lado)
}Grafo;

bool incializaGrafo(Grafo* g, int veritices) {
    if(g== NULL || veritices <0 ) return false;
    g->QuantVertice = veritices;
    g->QuantAerestas = 0;
    g->A = (ElemLista**)malloc(sizeof(ElemLista*)*veritices);
    int x;
    for(x=0; x<veritices; x++) {
        g->A[x] = NULL;
    }
    return true;
}

void exibiGrafo(Grafo* g) {
    if(!g) return;
    printf("\nExbindo grafo (vertices: %d; arestas: %d)\n", g->QuantVertice, g->QuantAerestas);
    ElemLista* atual;
    int x;
    for(x= 0; x<g->QuantVertice; x++) {
        printf("[%2i]", x);
        atual = g->A[x];
        while(atual) {
            printf(" ->%3d", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool inserirArestaAux(Grafo* g, int v1, int v2) {
    ElemLista *novo, *ant = NULL;
    ElemLista* atual = g->A[v1];
    while(atual && atual->dado<v2) {
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual && atual->dado == v2) return false;
    novo = (ElemLista*)malloc(sizeof(ElemLista));
    novo->dado = v2;
    novo->prox =atual;
    if(ant) ant->prox = novo;
    else g->A[v1] = novo;
    return true;

}

bool inserirAresta(Grafo* g, int val1, int val2) {
    if(!g || val1<0 || val2<0 || val1 >= g->QuantVertice || val2 >= g->QuantVertice || val1 == val2) return false;
    if(inserirArestaAux(g,val1,val2)) {
        inserirArestaAux(g,val2,val1);
        g->QuantAerestas++;
    }
    return true;
}

bool removeArestaAux(Grafo* g, int v1, int v2){
    ElemLista* ant = NULL;
    ElemLista* atual = g->A[v1];

    while (atual && atual->dado<v2){
        ant = atual;
        atual = atual->prox;
    }
        if (atual && atual->dado==v2){
        if (ant) ant->prox = atual->prox;
        else g->A[v1] = atual->prox;
        free(atual);
        return true;
    }
        return false;
}

bool removeAresta(Grafo* g, int v1, int v2) {
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->QuantVertice || v2 >= g->QuantVertice) return false;
        if(removeArestaAux(g, v1, v2)){
            removeArestaAux(g, v2, v1);
            g->QuantAerestas--;
            return true;
        }
        return false;
        
}



bool arestaExiste(Grafo* g, int v1, int v2){
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->QuantVertice || v2 >= g->QuantVertice) return false;
    ElemLista* atual = g->A[v1];
    while (atual && atual->dado < v2) atual = atual->prox;
    if (atual && atual->dado == v2) return true;
    return false;
}

int numeroDeVertices(Grafo* g){
    if (g!=NULL) return g->QuantVertice;
    else return -1;
}

int numeroDeArestas(Grafo* g){
    if (g!=NULL) return g->QuantAerestas;
    else return -1;
}

    int numeroDeArestas2(Grafo* g){
    if (g==NULL) return -1;
    ElemLista *atual;
    int x, arestas = 0;
    for (x=0; x<g->QuantVertice; x++){
        atual = g->A[x];
        while (atual){
            arestas++;
            atual = atual->prox;
        }
    }
    return arestas/2;
}

bool possuiVizinhos(Grafo* g, int v){
    if (!g || v < 0 || v >= g->QuantVertice || !(g->A[v]))
    return false;
    return true;
}
    
int retornaGrauDoVertice(Grafo* g, int v){
    if (!g || v < 0 || v >= g->QuantVertice) return -1;
    int grau = 0;
    ElemLista* atual = g->A[v];
    while (atual){
        grau++;
        atual = atual->prox;
    }
    return grau;
}

bool liberaGrafo(Grafo* g) {
    if(g==NULL) return false;
    ElemLista* atual, *apagar;
    int x;
    for(x=0; x<g->QuantVertice; x++) {
        atual = g->A[x];
        while(atual) {
            apagar = atual;
            atual = atual->prox;
            free(apagar);
        }
    }

    free(g->A);
    g->QuantAerestas = 0;
    g->QuantVertice = 0;
    g->A = NULL;
    return true;
}

int main() {
    Grafo *a;

    incializaGrafo(a,5);
    inserirAresta(a,0,2);
    inserirAresta(a,0,1);
    inserirAresta(a,1,2);
    inserirAresta(a,1,3);
    inserirAresta(a,3,4);
    inserirAresta(a,4,2);
    exibiGrafo(a);
    
}