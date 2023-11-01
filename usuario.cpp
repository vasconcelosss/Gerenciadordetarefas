#include "usuario.h"


// Construtores:
Usuario::Usuario(std::string name){
    nome_ = name;
    mkdir(nome_.c_str(), 0777);
}

// Retorno de membros privados da classe
std::string Usuario::nomeUsuario(){
    return nome_;
}

// Métodos de manipulação da classe
void Usuario::MudarNome(std::string novoNome){
    nome_ = novoNome;
}
