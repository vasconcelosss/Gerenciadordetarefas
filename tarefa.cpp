#include "tarefa.h"

#include <iostream>
#include <string>
#include <fstream> // Para manipulação de arquivos
#include <filesystem> // Para manipulação de diretórios
#include <ctime>

void Tarefa::CriaDiretorioTarefa(){
    std::filesystem::create_directory(projeto_+"/"+nome_);
}

// Construtores:
Tarefa::Tarefas(std::string nome, std::string prioridade, std::string projeto) {
    nome_ = nome;
    prioridade_ = prioridade;
    data_conclusao_ = "00/00/0000";
    conclusao_ = false;
    projeto_ = projeto;

    CriaDiretorioTarefa();
}
Tarefa::Tarefas(std::string nome, std::string prioridade, std::string dataConcluir, std::string projeto){
    nome_ = nome;
    prioridade_ = prioridade;
    data_conclusao_ = dataConcluir;
    conclusao_ = false;
    projeto_ = projeto;

    CriaDiretorioTarefa();
}

// Retorno de membros privados da classe
std::string Tarefa::NomeTarefa() {
    return nome_;
}

std::string Tarefa::Projeto() {
    return projeto_;
}

std::string Tarefa::Prioridade() {
    return prioridade_;
}

std::string Tarefa::CaminhoDescricao() {
    return descricao_;
}

std::string Tarefa::DataMeta() {
    return data_conclusao_;
}

bool Tarefa::Conclusao() {
    return conclusao_;
}


// Métodos de manipulação da classe
void Tarefa::MudarNome(string novoNome){
    std::filesystem::rename(projeto_+"/"+nome_, projeto_+"/"+novoNome);
    nome_ = novoNome;
}

void Tarefa::ConcluirTarefa() {
    conclusao_ = true;
}

void Tarefa::Descrever(){
    descricao_ = projeto_ + "/" + nome_ + "/" + "descricao";
    std::ofstream arquivo(descricao_);
    if (arquivo.is_open()) {
        std::string texto;

        std::cout << std::endl << "Digite o texto a ser escrito no arquivo (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):" << std::endl;

        while (std::cin >> texto) {
            arquivo << texto << ' ';
        }

        arquivo.close();
    } 
    else {
        std::cerr << "Não foi possível criar o arquivo." << std::endl;
    }
}

// Pré-condição: Arquivo de descrição já existe
void MudarDescricao(){

    std::ofstream arquivo(descricao_, std::ios::trunc);


    if (arquivo.is_open()) {
        std::string texto;

        std::cout << std::endl << "Digite o texto a ser escrito no arquivo (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):" << std::endl;

        while (std::cin >> texto) {
            arquivo << texto << ' ';
        }

        arquivo.close();
    }
    else {
        std::cerr << "Não foi possível criar o arquivo." << std::endl;
    }
}
