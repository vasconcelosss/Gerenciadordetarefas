#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "usuario.h"
#include "projeto.h"
#include "tarefa.h"

void Inicio(std::vector<Usuario>& users){  

}

int main(){

    std::vector<Usuario> users;

	std::cout<< "---- Bem vindo ao Gerenciador de Projetos! ----" << std::endl;
	std::cout<< "Esta aplicação foi desenvolvida visando ser rodada em sistemas Unix!" << std::endl << std::endl;
	
    Inicio(users);

    return 0;
}
