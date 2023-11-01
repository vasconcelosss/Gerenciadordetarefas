#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "usuario.h"
#include "projeto.h"
#include "tarefa.h"

void Inicio(std::vector<Usuario>& users){  
bool fim= false;
    while(!fim){
        std::cout << std::endl << "O que deseja fazer?" << std::endl;
        std::cout << "Digite 1: Para criar um Usuário." << std::endl;  
        if(users.size()){
            std::cout << "Digite 2: Para entrar em um Usuário." << std::endl;
        }
        else{
            std::cout << "Após criar um Usuário, digite 2: Para entrar em um Usuário." << std::endl;
        }
        std::cout << "Digite 3: Para encerrar o programa." << std::endl;

        int num;
        std::cin >> num;

        if(num == 1){
            std::string nome_usuario;
            std::cout << "Digite o nome do Usuário a ser criado (Não mutável): ";
            std::cin >> nome_usuario;
            users.push_back(Usuario(nome_usuario));

            std::cout << "Usuário " << nome_usuario << " criado!" << std::endl;
            std::cout << "Entrando em " << nome_usuario << "!" << std::endl;

            FuncoesUsuario(users,nome_usuario);
        }
        else { 
            if(num == 2){
                std::string nome_usuario;
                std::cout << "Digite o nome do Usuário que deseja entrar: ";
                std::cin >> nome_usuario;
                FuncoesUsuario(users,nome_usuario);
            }
            else {
                if(num == 3){
                    std::cout << "Até mais!" << std::endl;
                    fim = true;
                }
            }
        }
    }
}

int main(){

    std::vector<Usuario> users;

	std::cout<< "---- Bem vindo ao Gerenciador de Projetos! ----" << std::endl;
	std::cout<< "Esta aplicação foi desenvolvida visando ser rodada em sistemas Unix!" << std::endl << std::endl;
	
    Inicio(users);

    return 0;
}
