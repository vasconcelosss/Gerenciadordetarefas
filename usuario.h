#ifndef USUARIO_H_
#define USUARIO_H_

#include "projeto.h"

#include <iostream>
#include <string>
#include <list>
#include <fstream> // Para manipulação de arquivos
#include <sys/stat.h>  
#include <stdio.h>


class Usuario {

public:

    std::list<Projeto> Projetos;

    // Construtores:
    Usuario(std::string name);

    // Retorno de membros privados da classe
    std::string nomeUsuario();

    // Métodos de manipulação da classe
    void MudarNome(std::string novoNome); //Modifica o nome do Usuario para o novo passado

private:
    std::string nome_;


};

#endif  // USUARIO_H_
