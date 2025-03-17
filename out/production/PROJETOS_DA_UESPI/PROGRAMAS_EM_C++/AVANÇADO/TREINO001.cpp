#include <iostream>

class ArrayList{
    public:
        static const int MAX = 10;
        int N;
        int* list;
        bool erro;
        

        void contrutor(){
            this->list = new int[MAX];
            this->N = 0;
            this->erro = false;
        }

        void libera(){
            delete[] list;
            N=0;
        }

        void AdicionaInicio(int dado){
            erro = false;
            if(N >= MAX){
                erro = true;
                return;
            }

            for(int i = N; i>0; i--){
                list[i] = list[i-1];
            } 

            list[0] = dado;
            N++;

        }

        void AdicionaFinal(int dado){
            erro = false;

            if(N>=MAX){
                erro = true;
                return;
            }

            list[N] = dado;
            N++;
        }

        void adiciona_em(int idx, int dado){
            erro = false;
            if(N >= MAX || idx < 0 || idx > N){
                erro = true;
                return;
            }

            for(int i = 0; i > idx; i++){
                list[i] = list[i + 1];
            }

            list[idx] = dado;
        }

        void remove_inicio() {
            erro = false;

            if (N == 0) {
                erro = true;
                return;
            }

            for (int i = 0; i < N - 1; i++) {
                list[i] = list[i + 1];
            }

            N--;
        }

        void remove_fim(){
            erro = false;

            if(N==0){
                erro = true;
                return;
            }

            N--;
        }

        int remove_posicao(int idx){
            erro = false;

            if(N == 0 ||( idx < 0 || idx > N)){
                erro = true;
                return 0;
            }

            int dado = list[idx];

            for(int i = idx; i < N; i++){
                list[i]= list[i+1];
            }
            
            N--;
            return dado;
        }

        int buscar(int chave){
            for(int i = 0; i < N; i++){
                if(list[i] == chave){
                    return i;
                }
            }

            return -1;
        }


        int* concatenaList(int* list1, int* list2, int tamanho1, int tamanho2){
            erro = false;

            int novoTamanho = tamanho1 + tamanho2;

            int* novoArry = new int[novoTamanho];

            for(int i = 0; i < tamanho1; i++){
                novoArry[i] = list1[i];
            }

            for(int i = 0; i<tamanho2; i++){
                novoArry[tamanho1 + 1] = list2[i];
            }
            
            return novoArry;
        }

        int* copiaArray(int* list, int tamanho){
            erro = false;

            if(tamanho >= MAX){
                erro = true;
                return 0;
            }

            int* novoArray = new int[tamanho];

            for(int i = 0; i < tamanho; i++){
                novoArray[i] = list[i];
            }

            return novoArray;
        }
};

int main(){
    ArrayList list;
    ArrayList list2;
    ArrayList junta;

    list.contrutor();

    list.AdicionaFinal(1);
    list.AdicionaFinal(2);
    list.AdicionaFinal(3);
    list.AdicionaFinal(4);
    list.AdicionaFinal(5);
    list.AdicionaFinal(6);
    list.AdicionaFinal(7);
    list.AdicionaFinal(8);
    list.AdicionaFinal(9);
    list.AdicionaFinal(10);

    list2.contrutor();
    
    list2.AdicionaFinal(11);
    list2.AdicionaFinal(12);
    list2.AdicionaFinal(13);
    list2.AdicionaFinal(14);
    list2.AdicionaFinal(15);
    list2.AdicionaFinal(16);
    list2.AdicionaFinal(17);
    list2.AdicionaFinal(18);
    list2.AdicionaFinal(19);
    list2.AdicionaFinal(20);

    int* concatenado = junta.concatenaList(list.list, list2.list, list.N, list2.N);

    int* copia = new int[list.N];
    copia = list.copiaArray(list.list, list.N);
    
}

