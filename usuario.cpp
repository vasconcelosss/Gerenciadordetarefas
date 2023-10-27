#include "usuario.h"


// Construtores:
Usuario::Usuario(std::string name){
    nome_ = name;
    mkdir(nome_.c_str(), 0777);
}

std::string Usuario::nomeUsuario(){
    return nome_;
}
