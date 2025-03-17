#include <iostream>
using namespace std;

int main(){

    for (int n = 1; n <= 50; n++){
        if (n <= 20){
            continue;
        }
        bool eh_primo = true;
        for (int j = 2; j < n; j++){
            if (n % j == 0){   
                 eh_primo = false; 
                 break;
            }
        }
        if (eh_primo){
            cout<< n << " é o primeiro primo maior do que 20" << endl;
            break;
        }
    }
    return 0;
}