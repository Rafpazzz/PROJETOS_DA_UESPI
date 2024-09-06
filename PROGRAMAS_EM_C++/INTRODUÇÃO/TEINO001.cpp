#include <iostream>

using namespace std;

int main(){
    int vet[] = {1, 2, -3, 4, -5, 6, -7};
    const int n = 7;
    int pri , ult;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (vet[i]<0)
        {
            if (c == 0)
            {
            c++;
            pri = i;
            ult = pri;
            }else{
            ult = i;
            
             }
        }
         
    }

   cout << "primeiro: "<< pri<< " ultimo: "<<ult;
    
}