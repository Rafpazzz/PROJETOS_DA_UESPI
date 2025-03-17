#include <iostream>

void mediaNota(float notas[], float tam){
   float media = 0.0;


   for(int i = 0; i < tam; i++){
    media += notas[i];

   }
   media = media/tam;

   std::cout<<"A media das notas: "<< media<<std::endl;
   std::cout<<"O numero de notas: "<< tam;
}

using namespace std;

int main(){
    float notas[]={7,7,7};
    float tam = sizeof(notas)/sizeof(float);

    mediaNota(notas, tam);
}