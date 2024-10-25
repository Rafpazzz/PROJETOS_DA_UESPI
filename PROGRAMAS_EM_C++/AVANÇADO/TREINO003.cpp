#include <iostream>
#include <string>

constexpr int MAX = 1000;

bool areMatching(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int perfomancOperacao(char operador, int operando1, int operando2){
    switch(operador){
        case '+':
            return operando1 + operando2;
        case '-':
            return operando1 - operando2;
        case '*':
            return operando1 * operando2;
        case '/':
            if(operando2!=0)return operando1 / operando2;
            std::cout<<"operacao invalida"<<std::endl;
            exit(1);
        default:
            std::cout<<"Operação invalida."<<std::endl;
            exit(1);

    }
}

class Pilhasec1{
    public:
            int N;
            char elements[MAX];
            int erro;
            
            void criar(){
                this->N = 0;
            }

            void libera(){

            }

            void push(char data){
                erro = 0;
                if(N<MAX){
                    this->elements[N] = data;
                    N++;
                }else{
                    erro = 1;
                    return;
                }
            }

            char pop(){
                erro = 0;
                if(N == 0){
                    erro = 1;
                    return '\0';
                }else{
                    char unstack = elements[N-1];
                    N--;
                    return unstack;
                }
            }

            bool Isempyt(Pilhasec1 pilha){
                if(pilha.top()==NULL){
                    return true;
                }else{
                    return false;
                }
            }

            char top(){
                erro =0;
                if(N==0){
                    erro = 1;
                    return '\0';
                }else
                return this->elements[this->N-1];
            }

            int lengh(){
                return N;
            }

 void invetSting(Pilhasec1* pilha){
                erro = 0;
                if(N == 0){
                    erro = 1;
                    return;
                }else{
                    Pilhasec1 nova;
                    nova.criar();
                    Pilhasec1 invertida;
                    invertida.criar();
                    int j = N;
                    for(int i = 0; i<j; i++){
                        nova.push(pilha->pop());
                    }
                    for(int i =0; i<j;i++){
                        invertida.push(nova.pop());
                    }
                    for(int i=0;i<j;i++){
                        pilha->push(invertida.pop());
                    }
                    
                }
            }

            bool Balanceamento(const std::string& expressao){
                erro = 0;
                if(N==0){
                    erro = 1;
                    return false;
                }
                
                Pilhasec1 pilha;
                pilha.criar();

                for(int i =0; i<expressao.length(); i++){
                    char c = expressao[i];

                    if(c =='(' || c == '[' || c == '{'){
                        pilha.push(c);
                    }else if(c == ')' || c == '}' || c == ']'){
                        if(pilha.Isempyt(pilha) || !areMatching(pilha.top(), c)){
                            return false;
                        }

                        pilha.pop();
                    }

                }

                return pilha.Isempyt(pilha);

            }

            std::string infixa(std::string& infix){
                erro = 0;
                if(N==0){
                    erro = 1;
                    return '\0';
                }
                Pilhasec1 pilha;
                pilha.criar();
                std::string posfix = "";
                for(int i = 0; i<infix.length(); i++){
                    char c = infix[i];
                    if(isalnum(c)){
                        posfix += c;   
                    }else if(c == '('){
                        pilha.push(c);
                    }else if(c == ')'){
                        while (!pilha.Isempyt(pilha) && pilha.top() != '(') {
                            posfix += pilha.top();
                            pilha.pop();
                        }
                    }else{
                        while (!pilha.Isempyt(pilha) &&isOperator(pilha.top()) >=isOperator(c)) {
                            posfix += pilha.top();
                            pilha.pop();
                        }
                        pilha.push(c);  
        
                    }
                        posfix += pilha.top();
                        pilha.pop();
                    }

                    return posfix;
                }
                

            int avalia(std::string& posfix){
                erro =0;
                Pilhasec1 stack;
                stack.criar();
                for(int i = 0; i<posfix.length(); i++){
                    char c = posfix[i];
                    if(isalnum(c)){
                        stack.push(c - '0');
                    }else if(c =='+' || c == '-' || c == '*' || c == '/'){
                        if(stack.lengh()< 2){
                            erro = 1;
                            return '\0';
                        }
                        int operando1 = stack.pop(); stack.pop();
                        int operando2 = stack.pop(); stack.pop();
                        int resultado = perfomancOperacao(c,operando1,operando2);
                        stack.push(resultado);
                    }
                }

                return stack.top();
            }

            char infixa(Pilhasec1* pilha){
                erro = 0;

                if (pilha->Isempyt(*pilha)){  
                    erro = 1;
                    return '\0';
                }

                int j = pilha->lengh();  
                Pilhasec1 caracteres;
                caracteres.criar();
                Pilhasec1 separadores;
                separadores.criar();

                while (!pilha->Isempyt(*pilha)){
                    char elem = pilha->pop();  

                    switch (elem){
                        case '(':
                        case ')':
                        case '{':
                        case '}':
                        case '[':
                        case ']':
                            separadores.push(elem);  
                            break;
                        default:
                            caracteres.push(elem);  
                    }
                }

                std::cout << "Caracteres: ";
                while (!caracteres.Isempyt(caracteres)){
                    std::cout << caracteres.pop(); 
                }
                std::cout << std::endl;

    
                std::cout << "Separadores: ";
                while (!separadores.Isempyt(separadores)){
                    std::cout << separadores.pop();  
                }
                std::cout << std::endl;

                return '\0';  
            }


            char print(){
                for(int i = N-1; i>=0; i--){
                    std::cout<<elements[i];
                }
            }


};

 std::string invetSting(std::string str){
                    Pilhasec1 original;
                    original.criar();
                    Pilhasec1 reverse;
                    std::string invertida = "";
                    reverse.criar();
                    for(int i =0; i<str.length();i++){
                        original.push(str[i]);
                    }
                    for(int i =0; i<str.length();i++){
                        str[i] = original.pop();
                    }
                    
                    std::cout<<"Invertida: "<<str;

                    return str;
                    
            }

int main(){
    Pilhasec1 p;
    p.criar();
    p.push('A');
    p.push('+');
    p.push('C');
    
    

    return 0;
}