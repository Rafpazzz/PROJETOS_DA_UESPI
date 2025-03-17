#include <iostream>

using namespace std;

int main(){
    int32_t v[8];

    v[8] = 2;
    v[2] = 4;

    int b[] ={4, -3, 5, -7, 8};
    const int n = 5;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (b[i] < 0 )
        {
            idx = i;
            break; //vai parar o codigo , caso fosse o continue, iria voltar para o inicio do laço e iria exacutar a função, ate encontrar o ultimo valor da condição.
        }
        
    }

    cout << idx;
    

    return 0;
}