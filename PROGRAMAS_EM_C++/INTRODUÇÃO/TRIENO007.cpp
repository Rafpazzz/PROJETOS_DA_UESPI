#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    public:
    int X[2];
    int Y[2];

    double distancia(int x1, int y1, int x2, int y2){
        double dist;

        dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

        return dist;
    }
};

int main(){
    Ponto* pot1 = new Ponto;
    Ponto* pot2 = new Ponto;
    double distancia;

    pot1 -> X[0] = 4;
    pot1 ->X[1] = 3;
    pot2 -> Y[0] = 5;
    pot2 ->Y[1] = 8;

    distancia(X[0], Y[0], X[1], Y[1]);
}