package PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.Menu;


import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora.Delete_Reverse;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora.Kruskal;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora.OrdenaMaiorMenor;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.MenuDeListas.ArvoreGeradora.Prim;
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
        String [] names = {"A","B", "C", "D", "E", "F", "G"};
        int[][] graph = Graph();
        int size = graph.length;
        int escolha1;
        Scanner r = new Scanner(System.in);

        do {
            System.out.println(" ");
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
            System.out.println("[11].Escolhar outro grafo");
            System.out.println("[12].Sair do menu");
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
                    int[] distancias = grafoMenorCaminhoDirecionadoPonderado.dijkitra(0);
                    for (int i = 0; i < size; i++) {
                        System.out.println("A distancia de A para " + i + " : " + distancias[i]);
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
                    int[] distances = grafoMenorCaminhoNãoDirecionadoPonderado.dijkitra(0);
                    for (int i = 0; i < size; i++) {
                        System.out.println("A distancia de A para " + i + " : " + distances[i]);
                    }
                    break;

                case 7:
                    Kruskal kruskal = new Kruskal(size,names);
                    kruskal.addEdge(graph);
                    kruskal.KruskalMST();
                    break;

                case 8:
                    Prim prim = new Prim(graph,names);
                    prim.primsAlgorithm();
                    prim.toString();
                    break;

                case 9:
                    Delete_Reverse deleteReverse = new Delete_Reverse(graph, names);
                    deleteReverse.reverseDeleteMST();
                    deleteReverse.toString();
                    break;

                case 10:
                    OrdenaMaiorMenor ordenaMaiorMenor = new OrdenaMaiorMenor(graph, names);
                    ordenaMaiorMenor.sortEdgesCrescente();
                    System.out.println("======================");
                    ordenaMaiorMenor.sortEdgesDecrescente();
                    break;

                case 11:
                    graph = Graph();
                    size = graph.length;
                    break;

                case 12:
                    System.out.println("Obg pela participação");
                    System.exit(-1);

                default:
                    System.out.println("Escolha um das opções validas");
            }

        } while (escolha1 != 12);

    }

    public static int[][] Graph() {
        int escolha1;
        Scanner r = new Scanner(System.in);
        Graph graph = new Graph(7);
        System.out.println("Adicionando os vertices:");

        graph.addVertice("A", 0);
        graph.addVertice("B", 1);
        graph.addVertice("C", 2);
        graph.addVertice("D", 3);
        graph.addVertice("E", 4);
        graph.addVertice("F", 5);
        graph.addVertice("G", 6);

        System.out.println("Informe qual grafo ira trablhar");
        System.out.println("[1].Direcionado");
        System.out.println("[2].Não Direcionado");
        System.out.println("[3].Direcionado Ponderado");
        System.out.println("[4].Não Direcionado Ponderado");
        System.out.print("Escolha: ");
        escolha1 = r.nextInt();


        switch (escolha1) {
            case 1:
                System.out.println("Adicionando as ligações");
                graph.graphDirecionado(0,1);
                graph.graphDirecionado(0,3);
                graph.graphDirecionado(1,2);
                graph.graphDirecionado(1,5);
                graph.graphDirecionado(2,6);
                graph.graphDirecionado(3,1);
                graph.graphDirecionado(3,4);
                graph.graphDirecionado(4,5);
                graph.graphDirecionado(5,6);
                break;

            case 2:
                System.out.println("Adicionando as ligações");
                graph.graphNaoDirecionado(0,1);
                graph.graphNaoDirecionado(0,3);
                graph.graphNaoDirecionado(1,2);
                graph.graphNaoDirecionado(1,5);
                graph.graphNaoDirecionado(2,6);
                graph.graphNaoDirecionado(3,1);
                graph.graphNaoDirecionado(3,4);
                graph.graphNaoDirecionado(4,5);
                graph.graphNaoDirecionado(5,6);
                break;

            case 3:
                System.out.println("Adicionando as ligações");
                graph.graphDirecionadoPonderado(0,1,2);
                graph.graphDirecionadoPonderado(0,3,3);
                graph.graphDirecionadoPonderado(1,2,6);
                graph.graphDirecionadoPonderado(1,5,5);
                graph.graphDirecionadoPonderado(2,6,3);
                graph.graphDirecionadoPonderado(3,1,1);
                graph.graphDirecionadoPonderado(3,4,2);
                graph.graphDirecionadoPonderado(4,5,1);
                graph.graphDirecionadoPonderado(5,6,4);
                break;

            case 4:
                System.out.println("Adicionando as ligações");
                graph.graphNaoDirecionadoPonderado(0,1,2);
                graph.graphNaoDirecionadoPonderado(0,3,3);
                graph.graphNaoDirecionadoPonderado(1,2,6);
                graph.graphNaoDirecionadoPonderado(1,5,5);
                graph.graphNaoDirecionadoPonderado(2,6,3);
                graph.graphNaoDirecionadoPonderado(3,1,1);
                graph.graphNaoDirecionadoPonderado(3,4,2);
                graph.graphNaoDirecionadoPonderado(4,5,1);
                graph.graphNaoDirecionadoPonderado(5,6,4);
                break;
            default:
                System.out.println("Escolha errada, ate mais");
                break;
        }
        return graph.getMatrisAdj();
    }

}



