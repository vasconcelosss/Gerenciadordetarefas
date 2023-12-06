#ifndef TAREFA_H_
#define TAREFA_H_

#include <iostream>
#include <string>
#include <fstream> // Para manipulação de arquivos
#include <sys/stat.h>   // Para manipulação de diretórios


class Tarefa {

public:

    // Construtores:

    //Cria a Tarefa com os parametros passados e sem meta de conclusão na pasta do projeto passado
    Tarefa(std::string nome, std::string prioridade, std::string projeto);

    //Cria a Tarefa com os parametros passados na pasta do projeto passado
    Tarefa(std::string nome, std::string prioridade, std::string dataConcluir, std::string projeto);

    // Retorno de membros privados da classe
    std::string NomeTarefa() const;

    std::string Projeto() const;

    std::string Prioridade() const;

    std::string CaminhoDescricao() const;

    std::string DataMeta() const;

    bool Conclusao() const;


    // Métodos de manipulação da classe
    void MudarNomedoProjeto(std::string novoProjeto); //Modifica o nome do Projeto que contem a Tarefa

    void MudarNome(std::string novoNome); // Muda o nome da Tarefa

    void MudarDataMeta(std::string novaData); // Muda a data de meta da conclusão da Tarefa

    void ConcluirTarefa(); // Muda o status de conclusão para valor Verdadeiro

    void Descrever(std::string textoDescricao);  // Cria um arquivo descricao.txt na pasta da tarefa com a descrição da mesma pedida na função

    // Pré-condição: Arquivo de descrição já existe
    void MudarDescricao(std::string NovaDescricao); // Apaga o conteúdo da descrição e substitui por um outro pedido na função
    void ExibiDescricao() const;

private:
    std::string nome_;
    std::string projeto_; // Projeto que ela está contida, o diretório do projeto e usuário na máquina ("Usuario/Projeto")
    std::string prioridade_;  // Alta, Média ou Baixa
    std::string descricao_;
    std::string data_conclusao_; // Meta para conclusão da tarefa // Se = "00/00/0000", entao nao foi definida uma meta
    bool conclusao_; // Valor de verdade para a conlusão da tarefa

    void CriaDiretorioTarefa();

};

#endif  // TAREFA_H_
