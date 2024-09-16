#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){

    if(argc > 1){
        if (!strcmp(argv[1], "sol")){
            cout<<"Vou ao club.";
        }else if(!strcmp(argv[1], "nublado")){
            cout<<"Vou ao cinema.";
        }else{
            cout<<"FIcar em casa.";
        }
        
    }
    
    return 0;
}