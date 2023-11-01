#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "usuario.h"
#include "projeto.h"
#include "tarefa.h"

void FuncoesTarefa(std::string usuario_atual, std::list<Tarefa>& tarefas, const std::string& tarefa_atual){

    bool fim = false;
    Tarefa* ptr_tarefa_atual = nullptr;
        for(auto& taref : tarefas){
            if (taref.NomeTarefa() == tarefa_atual) {
                ptr_tarefa_atual = &taref;
                break;
            }
        }
    while(!fim){

        std::cout << std::endl << "Usuário " << usuario_atual << std::endl;
        std::cout << std::endl << "Caso você tenha interesse em: " << std::endl;
        std::cout << "Renomear a Tarefa " << ptr_tarefa_atual->NomeTarefa() << ". Digite 1" << std::endl;
        if(ptr_tarefa_atual->CaminhoDescricao() == ""){
            std::cout << "Criar uma Descrição para a Tarefa. Digite 200" << std::endl;
        } else{
            std::cout << "Mudar a descrição (Apaga a anterior). Digite 201" << std::endl;
            std::cout << "Exibir a descrição da Tarefa. Digite 202" << std::endl;
        }
        std::cout << "Concluir a Tarefa. Digite 3" << std::endl;
        std::cout << "Ver o estatus de conclusão da Tarefa. Digite 4" << std::endl;
        std::cout << "Ver a Data meta de Conclusão. Digite 5" << std::endl;
        std::cout << "Ver a Prioridade da sua tarefa. Digite 6" << std::endl;        
        std::cout << "Voltar as opções anteriores. Digite 7" << std::endl;

       
    }
}

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
