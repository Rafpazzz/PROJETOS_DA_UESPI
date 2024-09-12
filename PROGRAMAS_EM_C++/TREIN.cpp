#include<iostream>

using namespace std;

int main(){
    int n;

    cout << "Insira um numero: ";
    cin >> n;

    for(int i = 1; i <=n; i++){
        if(i % 3 !=0){
            cout <<"Numero: "<<i<<endl;
        }
        continue;
    }

    return 0;
}