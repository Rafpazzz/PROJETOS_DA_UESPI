#include <iostream>
#include <cmath>


bool Primo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true; 
    if (num % 2 == 0 || num % 3 == 0) return false; 
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false; 
    }
    return true;
}

int main() {
    
    for (int i = 1; i <= 50; ++i) {
        if (Primo(i)) {
            std::cout << i << " ";
        }
        if (i>20)
        {
            break;
        }
        
    }
    

    return 0;
}
