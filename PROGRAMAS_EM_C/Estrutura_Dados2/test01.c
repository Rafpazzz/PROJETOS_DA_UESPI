#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

typedef struct aux{
    int dado;
    struct aux* prox;
}No;

typedef struct ListaAdjacente {
    int numArestas;
    int numVertices;
    No** A;
}Grafo;

bool inicializaGrafo(Grafo *g, int vertices) {
    if(g==NULL || vertices<0) return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    g->A = (No**)malloc(sizeof(No*)*vertices);
    int x;
    for(x= 0; x<g->numVertices; x++) {
        g->A[x] = NULL;
    }
    return true;

}

bool insereVerticeAux(Grafo* g, int v1, int v2) {
    No* novo, *ant = NULL;
    No* atual = g->A[v1];
    while(atual && atual->dado < v2) {
        ant = atual;
        atual = atual->prox;
    }

    if(atual && atual->dado == v2) return false;
    novo = (No*)malloc(sizeof(No));
    novo->dado = v2;
    novo->prox = atual;
    if(ant) ant->prox = atual;
    else g->A[v1] = novo;
    return true;

}

bool inserirVertice(Grafo* g, int v1, int v2) {
    if(!g || v1<0 || v1 >= g->numVertices || v2 <0 || v2>=g->numVertices)  return false;
    if(insereVerticeAux(g,v1,v2)){
        insereVerticeAux(g,v2,v1);
        g->numArestas++;
        
    }
    return true;

}

bool removerVerticeAux(Grafo* g, int v1, int v2) {
    No* ant = NULL;
    No* atual = g->A[v1];
    while(atual && atual->dado < v2){
        ant = atual;
        atual = atual->prox;
    }

    if(atual && atual->dado == v2) {
        if(ant) ant->prox = atual->prox;
        else g->A[v1] = atual->prox;
        free(atual);
        return true;
    }
    return false;

}

bool removerVertice(Grafo* g, int v1, int v2) {
    if(!g || v1<0 || v1 >= g->numVertices || v2 <0 || v2>=g->numVertices)  return false;
    if(removerVerticeAux(g,v1,v2)){
        removerVerticeAux(g,v2,v1);
        g->numArestas--;
        return true;
    }
    return false;
    
}

bool existeAresta(Grafo *g, int v1, int v2) {
    if(!g || v1<0 || v1 >= g->numVertices || v2 <0 || v2>=g->numVertices)  return false;
    No* atual = g->A[v1];
    while(atual && atual->dado < v2) {
        atual = atual->prox;
    }
    if(atual && atual->dado == v2) return true;
    return false;
}

int numeroVertices(Grafo *g) {
    if(!g) return -1;
    return g->numVertices;

}

int numeroArestas(Grafo *g) {
    if(!g) return -1;
    return g->numArestas;

}

int numeroArestas2(Grafo *g) {
    if(!g) return -1;
    No* atual;
    int i, cont = 0;
    for(i= 0; i<g->numVertices;i++) {
        atual = g->A[i];
        while(atual) {
            cont++;
            atual = atual->prox;
        }
    }
    return cont/2;

}

bool existeVizinho(Grafo *g, int v) {
    if(!g && v>0 && v <= g->numVertices && g->A[v])  return true;
    return false;

}

int ratornaGrauVertice(Grafo *g, int v) {
    if(!g || v<0 || v >= g->numVertices)  return -1;
    No* atual = g->A[v];
    int grau = 0;
    while(atual) {
        grau++;
        atual = atual->prox;
    }
    return grau;

}

bool liberaGrafo(Grafo *g) {
    if(g==NULL) return false;
    No* apagar;
    No* atual;
    int i;
    for(i = 0; i<g->numVertices; i++) {
        atual = g->A[i];
        while(atual) {
            apagar = atual;
            atual = atual->prox;
            free(apagar);
        }
    }
    free(g->A);
    g->numArestas = 0;
    g->numVertices = 0;
    g->A = NULL;
    return true;
    
}

void exibirGrafo(Grafo* g) {
    if(!g) return;
    printf("Exibindo grafo: (Vertice: %d; Aresta: %d)\n", g->numVertices, g->numArestas);
    No* atual;
    int i;
    for(i=0; i<g->numVertices; i++) {
        printf("[%2i]", i);
        atual = g->A[i];
        while(atual) {
            printf(" -> %d. ", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }

}

int main() {
    Grafo *a;
    inicializaGrafo(a,5);
    inserirVertice(a,3,2);
    inserirVertice(a,1,4);
    exibirGrafo(a);
    
}