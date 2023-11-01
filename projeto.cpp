#include "projeto.h"


void Projeto::CriaDiretorioProjeto(){
    std::string caminho_projeto = usuario_ + "/" + nome_;
    mkdir(caminho_projeto.c_str(), 0777);
}

// Construtores:
Projeto::Projeto(std::string nome, std::string diretorio){

    nome_ = nome;
    usuario_ = diretorio;
    conclusao_ = false;

    CriaDiretorioProjeto();

}

Projeto::Projeto(std::string nome, std::string categoria, std::string diretorio){
    nome_ = nome;
    usuario_ = diretorio;
    conclusao_ = false;
    categoria_ = categoria;

    CriaDiretorioProjeto();
}


// Retorno de membros privados da classe
std::string Projeto::NomeProjeto(){
    return nome_;
}

std::string Projeto::UsuarioDoProjeto(){
    return usuario_;
}

std::string Projeto::CaminhoDescricao(){
    return descricao_;
}

std::string Projeto::CategoriaProjeto(){
    return categoria_;
}

bool Projeto::ConclusaoProjeto(){
    return conclusao_;
}


// Métodos de manipulação da classe
void Projeto::MudarNome(std::string novoNome){
    std::string antigo_nome = usuario_ + "/" + nome_;
    std::string novo_nome = usuario_ + "/" + novoNome;

    rename(antigo_nome.c_str(), novo_nome.c_str());
    nome_ = novoNome;
}

void Projeto::ConcluirProjeto(){
    conclusao_ = true;
}

void Projeto::Descrever(std::string textoDescricao){
    
    Projeto::descricao_ = usuario_ + "/" + nome_ + "/" + "descricao";
    std::ofstream arquivo(Projeto::descricao_);

    if (arquivo.is_open()) {
        
        arquivo << textoDescricao;
        arquivo.close();
    } 
    else {
        std::cout << "Não foi possível criar o arquivo." << std::endl;
    }
    
}

// Pré-condição: Arquivo de descrição já existe
void Projeto::MudarDescricao(std::string NovaDescricao){

    std::ofstream arquivo(CaminhoDescricao(), std::ios::trunc);

    if (arquivo.is_open()) {
        arquivo << NovaDescricao;
        arquivo.close();
    } 
    else {
        std::cout << "Não foi possível criar o arquivo." << std::endl;
    }
}

void Projeto::ExibiDescricao(){
    
    std::ifstream arquivo(descricao_);

    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo: " << std::endl;
    }
}


