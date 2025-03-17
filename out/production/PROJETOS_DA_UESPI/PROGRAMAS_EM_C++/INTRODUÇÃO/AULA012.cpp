#include <iostream>

using namespace std;

class P{
    public:
    int x;
    char y;
};

void print(P p){
    cout << p.x<< ", "<< p.y<<endl;
}

void f(P* p, int x){
    p->x = x;
}

void g(P p, int x){
    p.x =x;
}

int main(){

    P p0 = {.x=20, .y = 'Y'};
    print(p0);

    return 0;
}

