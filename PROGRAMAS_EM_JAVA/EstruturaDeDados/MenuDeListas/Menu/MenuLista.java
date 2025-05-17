package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.Menu;


import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.Graph.Graph;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ListAdj.ListAdjDirecionada;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ListAdj.ListAdjNaoDirecionada;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.MenorCaminho.GrafoMenorCaminhoDirecionadoPonderado;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.MenorCaminho.GrafoMenorCaminhoNãoDirecionadoPonderado;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.MenorCaminho.MenorCaminhoDirecionado;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.MenorCaminho.MenorCaminhoNãoDirecionado;

import java.util.Scanner;

public class MenuLista {
    public static void main(String[] args) {
        int[][] graph = Graph();
        int size = graph.length;
        int escolha1;
        Scanner r = new Scanner(System.in);

        do {
            System.out.println("");
            System.out.println("========================");
            System.out.println("Escolha uma das opções abaixo:");
            System.out.println("[1].Lista de adjacência de grafos direcionados");
            System.out.println("[2].Lista de adjacência de grafos não direcionados");
            System.out.println("[3].Menor caminho de grafos direcionados");
            System.out.println("[4].Menor caminho de grafos direcionados ponderados");
            System.out.println("[5].Menor caminho de grafos não direcionados ");
            System.out.println("[6].Menor caminho de grafos não direcionados ponderados ");
            System.out.println("[7].Arvore geradora mínima - kruskal");
            System.out.println("[8].Arvore geradora mínima - Prim");
            System.out.println("[9].Arvore geradora mínima - ApagaReservo");
            System.out.println("[10].Ordenação de arestas por peso (crescente e decrescente)");
            System.out.println("[11].Sair do menu");
            System.out.print("Escolha: ");
            escolha1 = r.nextInt();

            switch (escolha1) {
                case 1:
                    ListAdjDirecionada listAdjDirecionada = new ListAdjDirecionada(size);
                    listAdjDirecionada.inserirValor(graph);
                    listAdjDirecionada.exibirLista();
                    break;

                case 2:
                    ListAdjNaoDirecionada listAdjNaoDirecionada = new ListAdjNaoDirecionada(size);
                    listAdjNaoDirecionada.inserirValor(graph);
                    listAdjNaoDirecionada.exibirLista();
                    break;

                case 3:
                    MenorCaminhoDirecionado menorCaminhoDirecionado = new MenorCaminhoDirecionado(size);
                    menorCaminhoDirecionado.adicionarAresta(graph);
                    menorCaminhoDirecionado.bfs(menorCaminhoDirecionado, 0);
                    menorCaminhoDirecionado.toString();
                    break;

                case 4:
                    GrafoMenorCaminhoDirecionadoPonderado grafoMenorCaminhoDirecionadoPonderado = new GrafoMenorCaminhoDirecionadoPonderado(size, graph);
                    grafoMenorCaminhoDirecionadoPonderado.addElemento(graph);
                    int [] distancias = grafoMenorCaminhoDirecionadoPonderado.dijkitra(0);
                    for(int i = 0; i<size; i++) {
                        System.out.println("A distancia de A para " + i +" : " + distancias[i]);
                    }
                    break;

                case 5:
                    MenorCaminhoNãoDirecionado menorCaminhoNãoDirecionado = new MenorCaminhoNãoDirecionado(size);
                    menorCaminhoNãoDirecionado.adicionarAresta(graph);
                    menorCaminhoNãoDirecionado.bfs(menorCaminhoNãoDirecionado, 0);
                    break;

                case 6:
                    GrafoMenorCaminhoNãoDirecionadoPonderado grafoMenorCaminhoNãoDirecionadoPonderado = new GrafoMenorCaminhoNãoDirecionadoPonderado(size, graph);
                    grafoMenorCaminhoNãoDirecionadoPonderado.addElemento(graph);
                    int [] distances = grafoMenorCaminhoNãoDirecionadoPonderado.dijkitra(0);
                    for(int i = 0; i<size; i++) {
                        System.out.println("A distancia de A para " + i +" : " + distances[i]);
                    }
                    break;

                case 11:
                    System.out.println("Obg pela particopação");
                    System.exit(-1);
            }

        } while (escolha1 <= 11);

    }

    public static int[][] Graph() {
        int escolha1;
        String vertice, parar = "";
        int indice, tam, v1, v2;
        Scanner r = new Scanner(System.in);
        System.out.println("Contrução de um Grafo");
        System.out.print("Informe o tamanho do seu grafo: ");
        tam = r.nextInt();
        Graph graph = new Graph(tam);
        System.out.println("Adicionando os vertices:");
        for (int i = 0; i < tam; i++) {
            System.out.println("Informe o Vertice: ");
            vertice = r.next();
            System.out.println("Informe o indece desse vertice: ");
            indice = r.nextInt();
            graph.addVertice(indice, vertice);
        }
        System.out.println("Informe qual grafo ira trablhar");
        System.out.println("[1].Direcionado");
        System.out.println("[2].Não Direcionado");
        escolha1 = r.nextInt();


        switch (escolha1) {
            case 1:
                System.out.println("Adicionando as ligações: ");
                while (!parar.equals("sim")) {
                    System.out.print("Informe o vertice 1: ");
                    v1 = r.nextInt();
                    System.out.print("Informe o vertice 2: ");
                    v2 = r.nextInt();
                    r.nextLine();
                    graph.graphDirecionado(v1, v2);
                    System.out.print("Deseja parar de fazer ligações? ");
                    parar = r.nextLine();
                }
                break;

            case 2:
                System.out.println("Adicionando as ligações: ");
                while (!parar.equals("sim")) {
                    System.out.print("Informe o vertice 1: ");
                    v1 = r.nextInt();
                    System.out.print("Informe o vertice 2: ");
                    v2 = r.nextInt();
                    r.nextLine();
                    graph.graphNaoDirecionado(v1, v2);

                    System.out.print("Deseja parar de fazer ligações? ");
                    parar = r.nextLine();
                }
                break;

            default:
                System.out.println("Escolha errada, ate mais");
                System.exit(-1);
        }
        return graph.getMatrisAdj();
    }

}



