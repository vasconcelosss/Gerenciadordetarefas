#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include <string>
#include <fstream> // Para manipulação de arquivos
#include <filesystem> // Para manipulação de diretórios


class Usuario {

public:

    // Construtores:
    Usuario(std::string name);

    // Retorno de membros privados da classe
    std::string nomeUsuario();

    std::string CaminhoUsuario();

private:
    std::string local_usuario_; // Guarda o caminho para o usuário na máquina
    std::string nome_;

};

#endif  // USUARIO_H_
