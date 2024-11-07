#include <iostream>

int main() {
    int s = 5;
    int a;
    int n = 10;


    while(s>0) {
        a = s%2;
        s= s/2;
        std::cout<<a;
    }

    std::cout<<s/2;
    
    return 0;

}