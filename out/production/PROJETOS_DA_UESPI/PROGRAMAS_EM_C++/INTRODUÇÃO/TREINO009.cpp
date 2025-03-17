#include <iostream>
#include <math.h>

class Ponto{
    public:
    double x;
    double y;

    double eucl(Ponto p2){
        return sqrt(pow(x-p2.x, 2)+ pow(y-p2.y, 2));
    }
};

int main(){
    Ponto p2;
    Ponto p1;
    p1.x = 0;
    p1.y = 1;
    p2.x = 9;
    p2.y = 99;

    std:: cout<<p1.eucl(p2);

    return 0;
}