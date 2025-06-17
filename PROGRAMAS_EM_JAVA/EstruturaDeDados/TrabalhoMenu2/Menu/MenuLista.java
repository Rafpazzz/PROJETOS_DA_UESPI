package PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.Menu;

import PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.BinaryTree.Tree;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.DetectCiclo.DetectaCiclo;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.Graph.Graph;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.Ordenacao.OrdenacaoTopologica;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.PontoDeArticulação.EncontrarPonto;
import PROGRAMAS_EM_JAVA.EstruturaDeDados.TrabalhoMenu2.VerificacaoConecxao.IsConect;

import java.util.Scanner;

public class MenuLista {
    public static void main(String[] args) {
        Tree arvoreBinaria = criaArvore();
        int[][] graph = Graph();
        int size = graph.length;
        int escolha1;
        Scanner r = new Scanner(System.in);

        do {
            System.out.println(" ");
            System.out.println("========================");
            System.out.println("Escolha uma das opções abaixo:");
            System.out.println("[1].Detecção de ciclos");
            System.out.println("[2].Ordenação topologica de Digrafos");
            System.out.println("[3].Verificação de grafos Disconexo");
            System.out.println("[4].Detecção de pontos de Articulação");
            System.out.println("[5].Mostrar Arvore PreOrdem");
            System.out.println("[6].Mostrar Arvore PosOrdem");
            System.out.println("[7].Mostrar Arvore EmOrdem");
            System.out.println("[8].Remover nó da Arvore ");
            System.out.println("[9].Inserir nó da Arvore ");
            System.out.println("[10].Escolher novo grafo");
            System.out.println("[11].Sair do menu");
            System.out.print("Escolha: ");
            escolha1 = r.nextInt();

            switch (escolha1) {
                case 1:
                    DetectaCiclo detectaCiclo = new DetectaCiclo();
                    System.out.println(detectaCiclo.isCyclic(graph,size));

                    break;

                case 2:
                    OrdenacaoTopologica ordenacaoTopologica = new OrdenacaoTopologica();
                    System.out.println(ordenacaoTopologica.ordemTop(graph,size));
                    break;

                case 3:
                    IsConect conect = new IsConect();
                    System.out.println(conect.isConexo(graph, size));
                    break;

                case 4:
                    EncontrarPonto encontrarPontoArticulacao = new EncontrarPonto();
                    encontrarPontoArticulacao.encontrarPontos(graph);
                    break;

                case 5:
                    arvoreBinaria.preOrdem();
                    break;

                case 6:
                    arvoreBinaria.posOrdem();
                    break;

                case 7:
                    arvoreBinaria.emOrdem();
                    break;

                case 8:
                    System.out.println("Digite qual nó deseja remover: ");
                    int valor = r.nextInt();
                    r.nextLine();
                    arvoreBinaria.remover(valor);
                    break;

                case 9:
                    System.out.print("Digite o nó que deseja inserir: ");
                    int valorInserir = r.nextInt();
                    r.nextLine();
                    arvoreBinaria.inserir(valorInserir);
                    break;

                case 10:
                    graph = Graph();
                    size = graph.length;
                    break;

                case 11:
                    System.out.println("Obrigado pela participação!");
                    System.exit(-1);
                default:
                    System.out.println("Escolha um das opções validas");
            }

        } while (escolha1 != 11);

    }

    public static int[][] Graph() {
        int escolha1;
        Scanner r = new Scanner(System.in);
        Graph graph = new Graph(9);
        System.out.println("Adicionando os vertices:");

        graph.addVertice("A", 0);
        graph.addVertice("B", 1);
        graph.addVertice("C", 2);
        graph.addVertice("D", 3);
        graph.addVertice("E", 4);
        graph.addVertice("F", 5);
        graph.addVertice("G", 6);
        graph.addVertice("H", 7);
        graph.addVertice("I", 8);

        System.out.println("Informe qual grafo deseja trabalhar");
        System.out.println("[1].Direcionado");
        System.out.println("[2].Não Direcionado");
        System.out.print("Escolha: ");
        escolha1 = r.nextInt();


        switch (escolha1) {
            case 1:
                System.out.println("Adicionando as ligações");
                graph.graphDirecionado(0,1);
                graph.graphDirecionado(0,8);
                graph.graphDirecionado(1,2);
                graph.graphDirecionado(1,3);
                graph.graphDirecionado(2,0);
                graph.graphDirecionado(2,7);
                graph.graphDirecionado(3,4);
                graph.graphDirecionado(4,5);
                graph.graphDirecionado(4,6);
                graph.graphDirecionado(7,4);
                graph.graphDirecionado(8,2);

                break;

            case 2:
                System.out.println("Adicionando as ligações");
                graph.graphNaoDirecionado(0,1);
                graph.graphNaoDirecionado(0,8);
                graph.graphNaoDirecionado(1,2);
                graph.graphNaoDirecionado(1,3);
                graph.graphNaoDirecionado(2,8);
                graph.graphNaoDirecionado(2,7);
                graph.graphNaoDirecionado(3,4);
                graph.graphNaoDirecionado(4,5);
                graph.graphNaoDirecionado(4,6);
                graph.graphNaoDirecionado(4,7);

                break;

            default:
                System.out.println("Escolha errada, ate mais");
                break;
        }
        return graph.getMatrisAdj();
    }

    public static Tree criaArvore() {
        Tree arvore = new Tree();

        arvore.inserir(10);
        arvore.inserir(3);
        arvore.inserir(6);
        arvore.inserir(2);
        arvore.inserir(12);
        arvore.inserir(11);
        arvore.inserir(13);

        return arvore;
    }

}



