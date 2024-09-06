#include <iostream>

using namespace std;

int main(){
    int vet[] = {1, 2, -3, 4, -5, 6, -7};
    const int n = 7;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (vet[i]<0)
        {
            idx = i;
            cout << " "<<idx;
        }
         
    }

   
    
}