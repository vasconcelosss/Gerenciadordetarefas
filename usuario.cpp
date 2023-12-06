#include "usuario.h"


// Construtores:
Usuario::Usuario(std::string name){
    nome_ = name;
    mkdir(nome_.c_str(), 0777);
}

// Retorno de membros privados da classe
std::string Usuario::nomeUsuario() const {
    return nome_;
}

// Métodos de manipulação da classe
void Usuario::AdicionaProjeto(Projeto p){
    Projetos.push_back(p);
}


void Usuario::MudarNome(std::string novoNome){
    nome_ = novoNome;

    for(auto& projeto : Projetos){
        projeto.MudarNomeDoUsuario(novoNome);
    }
}

void Usuario::ListarProjetos(int forma) const {

    if((forma < 1) || (forma > 3)){
        std::cout << "Forma não existente!" << std::endl;
    }

    std::list<std::string> Nome_Dos_Projetos;


    if(forma == 1){
        Nome_Dos_Projetos = OrdenaNomes1(Projetos);
    }
    if(forma == 2){
        Nome_Dos_Projetos = OrdenaNomes2(Projetos);
    }
    if(forma == 3){
        std::cout << "-------- Começo --------" << std::endl;
        std::cout << "Projetos do Usuário " << nomeUsuario() << " :" << std::endl;
        for(const auto& projeto : Projetos){
            std::cout << projeto.NomeProjeto() << " - ";
            if(projeto.CategoriaProjeto() == ""){
                std::cout << "Sem Categoria!" << std::endl;
            }
            else{
                std::cout << projeto.CategoriaProjeto() << std::endl;
            }
        }
        std::cout << "--------- Fim ---------" << std::endl;

        return;
    }

    std::cout << "-------- Começo --------" << std::endl;
    std::cout << "Projetos do Usuário " << nomeUsuario() << " :" << std::endl;
    for(const auto& nome : Nome_Dos_Projetos){
        std::cout << " " << nome << std::endl;
    }
    std::cout << "--------- Fim ---------" << std::endl;


}
