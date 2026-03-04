class Pessoa {
    late String nome; //a ? serve para uma question mark, pois o dart nao aceita tipos nulos e com essa ? avisa ao dart que essa variavel pode ser nula             
    late String sobrenome;
    late int? _age;

    

    get age => this._age;
    set age(n) => this._age;
    
    get nomeCompleto => this.nome + ' ' +this.sobrenome; 

    Pessoa(nome, sobrenome, age) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this._age = age;
    }
    /*
    Pessoa({required this.nome, required this.sobrenome}); 
    
    */
}