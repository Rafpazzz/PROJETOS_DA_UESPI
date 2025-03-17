#include <iostream>

using namespace std;

int main(){
    int gasto[5];
    double media;

    for (int i = 0; i < 5; i++)
    {   
        cout << "Informe o gasto mensal da sua familia: ";
        cin >> gasto[i];
    }

    for (int i = 0; i < 5; i++)
    {   
        cout <<  "Familia" <<i+1<<" :"<< gasto[i]<< endl;
        
    }

    for (int i = 0; i < 5; i++)
    {
        media += gasto[i];
    }
    
    media = media / 5;

    for (int i = 0; i < 5; i++)
    {
        if (gasto[i] < media){
            cout << "O gasto da familia "<< i+1<< " esta abaixo da media"<<endl;
        }else if (gasto[i] == media)
        {
            cout << "O gastoda familia "<< i+1<< " encontra-se na media de gastos"<<endl;
        }else{
             cout << "O gastoda familia "<< i+1<< " encontra-se acima da media de gastos"<<endl;
        }
        
    }
    
    
}