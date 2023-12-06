#ifndef PROJETO_H_
#define PROJETO_H_

#include "tarefa.h"

#include <list>
#include <string>
#include <fstream> // Para manipulação de arquivos
#include <sys/stat.h>  
#include <stdio.h>


class Projeto {

public:

    std::list<Tarefa> Tarefas;

    // Construtores:
    Projeto(std::string nome, std::string diretorio); // Cria um Projeto com o nome
                                                      //e no diretório (usuário) passado

    Projeto(std::string nome, std::string categoria, std::string diretorio); // Cria um Projeto com o nome, a categoria
                                                                             //e no diretório (usuário) passado
    // Retorno de membros privados da classe
    std::string NomeProjeto() const ; // Retorna o nome do Projeto

    std::string UsuarioDoProjeto() const ; // Retorna o Usuário ao qual o projeto está vinculado

    std::string CaminhoDescricao() const ; //Retorna o caminho para o arquivo de texto de descrição

    std::string CategoriaProjeto() const ; // Retorna a categoria do Projeto

    bool ConclusaoProjeto() const ; // Retorna o status de conclusão do Projeto



    // Métodos de manipulação da classe
    void MudarNomeDoUsuario(std::string novoUsuario); //Modifica o nome do Usuario que contem o Projeto

    void MudarNome(std::string novoNome); //Modifica o nome do Projeto para o novo passado
    
    void MudarCategoria(std::string NovaCategoria); //Modifica a categoria do Projeto para a nova passada
    
    void ConcluirProjeto(); // Muda o status de conclusão para valor Verdadeiro

    void Descrever(std::string textoDescrica);  // Cria um arquivo descricao.txt na pasta da tarefa com a  
                                                //descrição da mesma pedida na função

    // Pré-condição: Arquivo de descrição já existe
    void MudarDescricao(std::string NovaDescricao); // Apaga o conteúdo da descrição e substitui por um outro pedido na função
    void ExibiDescricao() const ;



private:
    std::string nome_;
    std::string usuario_;
    std::string descricao_;
    std::string categoria_;
    bool conclusao_;

    void CriaDiretorioProjeto();

};

#endif  // PROJETO_H_
