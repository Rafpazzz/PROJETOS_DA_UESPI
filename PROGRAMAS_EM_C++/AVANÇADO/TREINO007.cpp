#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

class Node {
    public:
        Node *next;
        int value;
};

class Fila {
    public:
       int N = 0;
       int erro;
       Node *ptr_preimeiro = nullptr;
       Node *ptr_ultimo = nullptr;
       
       bool filaVazia() {
           if(N==0){
               return true;
           }else{
               return false;
           }
       }
       
       void adicionar_pedido(int data) {
           Node *novoPedido = new Node();
           novoPedido->value = data;
           novoPedido->next = nullptr;
           if(N==0){
               ptr_preimeiro = novoPedido;
               ptr_ultimo = novoPedido;
               N++;
           }else {
                ptr_ultimo->next = novoPedido;
                ptr_ultimo = novoPedido;
           }
              
       }
       
       int processapedido() {
           erro = 0;
           if(!filaVazia()){
               Node *temp = new Node();
               temp = ptr_preimeiro;
               ptr_preimeiro = ptr_preimeiro->next;
               int id = temp->value;
               std::cout<<"Pedido "<<id<<" finalisado.";
               delete temp;
               return id;
           }else{
                erro =  1;
                return -1;
           }
       }

       int proximoPedido() {
        erro = 0;
        if(filaVazia()){
            erro = 1;
            return -1;
        }else{
            return ptr_preimeiro->value;
        }
       }

       int totaldePedidos() {
            return N;
       }

};

void testarFila(Fila &fila) {
    int acertos = 0;
    int operacoesTotais = 0;
    
    // Vetor para simular o estado esperado da fila
    std::vector<int> estadoEsperado;
    
    // Array de operações
    std::string operacoes[] = {"adicionar_pedido", "processapedido", "proximoPedido", "totaldePedidos", "filaVazia"};
    
    // Semente para números aleatórios
    std::srand(std::time(0));
    int conta_ensercao = 0;
    
    // Realizar 100 operações aleatórias
    for (int i = 0; i < 100; i++) {
        // Escolhe uma operação aleatória
        std::string operacao = operacoes[std::rand() % 5];
        
        if (operacao == "adicionar_pedido") {
            int cliente_id = std::rand() % 1000;  // ID de cliente aleatório
            fila.adicionar_pedido(cliente_id);
            estadoEsperado.push_back(cliente_id);  // Atualiza o estado esperado
            std::cout << "Operação: adicionar_pedido(" << cliente_id << ")\n";
            conta_ensercao++;
        
        } else if (operacao == "processapedido") {
            int resultadoFila = fila.processapedido();
            int resultadoEsperado = estadoEsperado.empty() ? -1 : estadoEsperado.front();
            
            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado) acertos++;
            if (!estadoEsperado.empty()) estadoEsperado.erase(estadoEsperado.begin());  // Remove o primeiro elemento

            std::cout << "Operação: processapedido() -> Resultado: " << resultadoFila << ", Esperado: " << resultadoEsperado << "\n";
        
        } else if (operacao == "proximoPedido") {
            int resultadoFila = fila.proximoPedido();
            int resultadoEsperado = estadoEsperado.empty() ? -1 : estadoEsperado.front();
            
            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado) acertos++;
            std::cout << "Operação: proximoPedido() -> Resultado: " << resultadoFila << ", Esperado: " << resultadoEsperado << "\n";
        
        } else if (operacao == "totaldePedidos") {
            int resultadoFila = fila.totaldePedidos();
            int resultadoEsperado = estadoEsperado.size();
            
            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado) acertos++;
            std::cout << "Operação: totaldePedidos() -> Resultado: " << resultadoFila << ", Esperado: " << resultadoEsperado << "\n";
        
        } else if (operacao == "filaVazia") {
            bool resultadoFila = fila.filaVazia();
            bool resultadoEsperado = estadoEsperado.empty();
            
            // Verifica se o resultado está correto
            if (resultadoFila == resultadoEsperado) acertos++;
            std::cout << "Operação: filaVazia() -> Resultado: " << (resultadoFila ? "true" : "false") << ", Esperado: " << (resultadoEsperado ? "true" : "false") << "\n";
        }

        operacoesTotais++;
    }

    // Calcula e imprime a taxa de acerto
    double taxaAcerto = (static_cast<double>(acertos) / (operacoesTotais-conta_ensercao)) * 100;
    std::cout << "\nTaxa de acerto: " << taxaAcerto << "%\n";
}

int main() {
    Fila filaSuporteTecnico;
    Fila filaPedidosLanchonete;

    std::cout << "Teste: Sistema de Atendimento de Suporte Técnico\n";
    testarFila(filaSuporteTecnico);

    std::cout << "\nTeste: Sistema de Fila de Pedidos em uma Lanchonete\n";
    testarFila(filaPedidosLanchonete);

    return 0;
}
