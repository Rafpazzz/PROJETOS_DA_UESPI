#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<locale.h>

typedef struct aux{
    int dado;
    struct aux* prox;
    int peso;
}ElemLista;

typedef struct ListaAdjacente {
    int numArestas;
    int numVertices;
    ElemLista** A;
}Grafo;

bool inicializaGrafo(Grafo *g, int vertices) {
    if(g==NULL || vertices<0) return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    g->A = (ElemLista**)malloc(sizeof(ElemLista*)*vertices);
    int x;
    for(x= 0; x<vertices; x++) {
        g->A[x] = NULL;
    }
    return true;

}

bool insereArestaAux(Grafo* g, int v1, int v2) {
    ElemLista* novo, *ant = NULL;
    ElemLista* atual = g->A[v1];
    while(atual && atual->dado < v2) {
        ant = atual;
        atual = atual->prox;
    }

    if(atual && atual->dado == v2) return false;
    novo = (ElemLista*)malloc(sizeof(ElemLista));
    novo->dado = v2;
    novo->prox = atual;
    if(ant) ant->prox = novo;
    else g->A[v1] = novo;
    return true;

}

bool inserirAresta(Grafo* g, int v1, int v2) {
    if(!g || v1<0 || v1 >= g->numVertices || v2 <0 || v2>=g->numVertices)  return false;
    if(insereArestaAux(g,v1,v2)){
        insereArestaAux(g,v2,v1);
        g->numArestas++;
        
    }
    return true;

}

bool inserirArestaPonderada(Grafo* g, int v1, int v2, int peso) {
    if(!g ||v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || peso < 0) return false;
    ElemLista *novo, *ant = NULL;
    ElemLista* atual = g->A[v1];
    while(atual && atual->dado<v2) {
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual && atual->dado == v2) return true;
    novo = (ElemLista*)malloc(sizeof(ElemLista));
    novo->dado = v2;
    novo->prox =atual;
    novo->peso = peso;
    if(ant) ant->prox = novo;
    else g->A[v1] = novo;
    g->numArestas++;
    return true;

}

bool inserirArestaDorecionada(Grafo* g, int v1, int v2) {
    if(!g ||v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
    ElemLista *novo, *ant = NULL;
    ElemLista* atual = g->A[v1];
    while(atual && atual->dado<v2) {
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual && atual->dado == v2) return true;
    novo = (ElemLista*)malloc(sizeof(ElemLista));
    novo->dado = v2;
    novo->prox =atual;
    if(ant) ant->prox = novo;
    else g->A[v1] = novo;
    g->numArestas++;
    return true;

}

bool removerArestaAux(Grafo* g, int v1, int v2) {
    ElemLista* ant = NULL;
    ElemLista* atual = g->A[v1];
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

bool removerAresta(Grafo* g, int v1, int v2) {
    if(!g || v1<0 || v1 >= g->numVertices || v2 <0 || v2>=g->numVertices)  return false;
    if(removerArestaAux(g,v1,v2)){
        removerArestaAux(g,v2,v1);
        g->numArestas--;
        return true;
    }
    return false;
    
}

bool removeArestaUnica(Grafo* g, int v1, int v2){
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices) return false;
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
        g->numArestas--;
        return true;
    }
        return false;
}

bool existeAresta(Grafo *g, int v1, int v2) {
    if(!g || v1<0 || v1 >= g->numVertices || v2 <0 || v2>=g->numVertices)  return false;
    ElemLista* atual = g->A[v1];
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
    ElemLista* atual;
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

int numeroDeArestasUnitarias(Grafo* g){
    if (g==NULL) return -1;
    ElemLista *atual;
    int x, arestas = 0;
    for (x=0; x<g->numVertices; x++){
        atual = g->A[x];
        while (atual){
            arestas++;
            atual = atual->prox;
        }
    }
    return arestas;
}

bool existeVizinho(Grafo *g, int v) {
    if(!g && v>0 && v <= g->numVertices && g->A[v])  return true;
    return false;

}

int ratornaGrauVertice(Grafo *g, int v) {
    if(!g || v<0 || v >= g->numVertices)  return -1;
    ElemLista* atual = g->A[v];
    int grau = 0;
    while(atual) {
        grau++;
        atual = atual->prox;
    }
    return grau;

}

bool liberaGrafo(Grafo *g) {
    if(g==NULL) return false;
    ElemLista* apagar;
    ElemLista* atual;
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
    ElemLista* atual;
    int i;
    for(i=0; i<g->numVertices; i++) {
        printf("[%2i]", i);
        atual = g->A[i];
        while(atual) {
            printf(" -> %3d ", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }

}

void exibiGrafoPonderado(Grafo* g) {
    if(!g) return;
    printf("\nExbindo grafo (vertices: %d; arestas: %d)\n", g->numVertices, g->numVertices);
    ElemLista* atual;
    int x;
    for(x= 0; x<g->numVertices; x++) {
        printf("[%2i]", x);
        atual = g->A[x];
        while(atual) {
            printf(" ->%3d, Peso: %3.2d | ", atual->dado, atual->peso);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL,"portuguese");
    Grafo *a;
    int v1, v2, peso, tam, opc, opc2;

    printf("====MENU DE LISTAS====\n\n\n");

    printf("Informe o tamanho do seu grafo: ");
    scanf("%d", &tam);
    inicializaGrafo(a,tam);

    
    printf("\n\n Escolha a lista com que deseja trabalhar: \n");
    printf("[1]. Lsita Adjacente nao direcionada.\n");
    printf("[2]. Lista Adjacente Direcionada.\n");
    printf("[3]. Lista Adjacente Ponderada.\n");
    scanf("%d", &opc);

    switch(opc) {
        case 1:
            printf("Menu da lista\n");
            do{
                printf("[1].Adicionar ligaçao\n");
                printf("[2].Remover ligação\n");
                printf("[3].Numero de arestas\n");
                printf("[4].Exibir grafo\n");
                printf("[5].Limpar grafo\n");
                printf("[6].sair do programa\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opc2);

                switch(opc2) {
                    case 1:
                        printf("Informe a ligação[0 a %d]: ", tam-1);
                        scanf("%d", &v1);
                        printf("Informe a ligação[0 a %d]: ", tam-1);
                        scanf("%d", &v2);
                        inserirAresta(a,v1,v2);
                        break;
                    
                    case 2:
                        printf("Informe a ligação que deseja remover[0 a %d]: ", tam-1);
                        scanf("%d", &v1);
                        printf("Informe a ligação que deseja remover[0 a %d]: ", tam-1);
                        scanf("%d", &v2);
                        removerAresta(a,v1,v2);
                        break;
                    
                    case 3:
                        printf(numeroArestas2(a));
                        break;

                    case 4:
                        exibirGrafo(a);
                        break;

                    case 5:
                        liberaGrafo(a);
                        break;
                    case 6:
                        printf("Saindo do menu de lista.");
                        break;
                    default:
                        printf("opção errada, tente novamente");
                    
                }
            }while(opc2!=6);
            break;
        
        case 2:
        printf("Menu da lista\n");
        do{
            printf("[1].Adicionar ligaçao\n");
            printf("[2].Remover ligação\n");
            printf("[3].Numero de arestas\n");
            printf("[4].Exibir grafo\n");
            printf("[5].Limpar grafo\n");
            printf("[6].sair do programa\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opc2);

            switch(opc2) {
                case 1:
                    printf("Informe a ligação[0 a %d]: ", tam-1);
                    scanf("%d", &v1);
                    printf("Informe a ligação[0 a %d]: ", tam-1);
                    scanf("%d", &v2);
                    inserirArestaDorecionada(a,v1,v2);
                    break;
                
                case 2:
                    printf("Informe a ligação que deseja remover[0 a %d]: ", tam-1);
                    scanf("%d", &v1);
                    printf("Informe a ligação que deseja remover[0 a %d]: ", tam-1);
                    scanf("%d", &v2);
                    removeArestaUnica(a,v1,v2);
                    break;
                
                case 3:
                    printf(numeroDeArestasUnitarias(a));
                    break;

                case 4:
                    exibirGrafo(a);
                    break;

                case 5:
                    liberaGrafo(a);
                    break;
                case 6:
                    printf("Saindo do menu de lista.");
                    break;
                default:
                    printf("opção errada, tente novamente");
                
            }
        }while(opc2!=6);
        break;

        case 3:
        printf("Menu da lista\n");
        do{
            printf("[1].Adicionar ligaçao\n");
            printf("[2].Remover ligação\n");
            printf("[3].Numero de arestas\n");
            printf("[4].Exibir grafo\n");
            printf("[5].Limpar grafo\n");
            printf("[6].sair do programa\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opc2);

            switch(opc2) {
                case 1:
                    printf("Informe a ligação[0 a %d]: ", tam-1);
                    scanf("%d", &v1);
                    printf("Informe a ligação[0 a %d]: ", tam-1);
                    scanf("%d", &v2);
                    printf("Informe o peso da ligacao: ");
                    scanf("%d", &peso);
                    inserirArestaPonderada(a,v1,v2,peso);
                    break;
                
                case 2:
                    printf("Informe a ligação que deseja remover[0 a %d]: ", tam-1);
                    scanf("%d", &v1);
                    printf("Informe a ligação que deseja remover[0 a %d]: ", tam-1);
                    scanf("%d", &v2);
                    removeArestaUnica(a,v1,v2);
                    break;
                
                case 3:
                    printf(numeroDeArestasUnitarias(a));
                    break;

                case 4:
                    exibiGrafoPonderado(a);
                    break;

                case 5:
                    liberaGrafo(a);
                    break;
                case 6:
                    printf("Saindo do menu de lista.");
                    break;
                default:
                    printf("opção errada, tente novamente");
                
            }
        }while(opc2!=6);
        break;
    }
}