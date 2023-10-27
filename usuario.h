#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include <string>
#include <fstream> // Para manipulação de arquivos
#include <sys/stat.h>  
#include <stdio.h>


class Usuario {

public:

    // Construtores:
    Usuario(std::string name);

    // Retorno de membros privados da classe
    std::string nomeUsuario();

private:
    std::string nome_;

};

#endif  // USUARIO_H_
