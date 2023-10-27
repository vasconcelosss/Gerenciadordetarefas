#include "tarefa.h"

#include <iostream>
#include <string>
#include <fstream> // Para manipulação de arquivos
// Para manipulação de diretórios
#include <sys/stat.h>  
#include <stdio.h>


void Tarefa::CriaDiretorioTarefa(){
    std::string caminho_tarefa = projeto_ + "/" + nome_;
    mkdir(caminho_tarefa.c_str(), 0777);
}

// Construtores:
Tarefa::Tarefa(std::string nome, std::string prioridade, std::string projeto) {
    nome_ = nome;
    prioridade_ = prioridade;
    data_conclusao_ = "00/00/0000";
    conclusao_ = false;
    projeto_ = projeto;

    CriaDiretorioTarefa();
}
Tarefa::Tarefa(std::string nome, std::string prioridade, std::string dataConcluir, std::string projeto){
    nome_ = nome;
    prioridade_ = prioridade;
    data_conclusao_ = dataConcluir;
    conclusao_ = false;
    projeto_ = projeto;

    CriaDiretorioTarefa();
}

// Retorno de membros privados da classe
std::string Tarefa::NomeTarefa() {
    return Tarefa::nome_;
}

std::string Tarefa::Projeto() {
    return Tarefa::projeto_;
}

std::string Tarefa::Prioridade() {
    return Tarefa::prioridade_;
}

std::string Tarefa::CaminhoDescricao() {
    return Tarefa::descricao_;
}

std::string Tarefa::DataMeta() {
    return Tarefa::data_conclusao_;
}

bool Tarefa::Conclusao() {
    return Tarefa::conclusao_;
}


// Métodos de manipulação da classe
void Tarefa::MudarNome(std::string novoNome){

    std::string antigo_nome = projeto_ + "/" + nome_;
    std::string novo_nome = projeto_ + "/" + novoNome;

    rename(antigo_nome.c_str(), novo_nome.c_str());
    nome_ = novoNome;
}

void Tarefa::ConcluirTarefa() {
    conclusao_ = true;
}

void Tarefa::Descrever(){
    Tarefa::descricao_ = projeto_ + "/" + nome_ + "/" + "descricao";
    std::ofstream arquivo(Tarefa::descricao_);
    if (arquivo.is_open()) {
        std::string texto;

        std::cout << std::endl << "Digite o texto a ser escrito no arquivo (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):" << std::endl;

        while (std::cin >> texto) {
            arquivo << texto << ' ';
        }

        arquivo.close();
    } 
    else {
        std::cout << "Não foi possível criar o arquivo." << std::endl;
    }
}

// Pré-condição: Arquivo de descrição já existe
void Tarefa::MudarDescricao(){

    std::ofstream arquivo(CaminhoDescricao(), std::ios::trunc);


    if (arquivo.is_open()) {
        std::string texto;

        std::cout << std::endl << "Digite o texto a ser escrito no arquivo substituindo o anterior (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):" << std::endl;

        while (std::cin >> texto) {
            arquivo << texto << ' ';
        }

        arquivo.close();
    }
    else {
        std::cout << "Não foi possível criar o arquivo." << std::endl;
    }
}
