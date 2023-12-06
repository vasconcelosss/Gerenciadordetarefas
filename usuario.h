#ifndef USUARIO_H_
#define USUARIO_H_

#include "projeto.h"

#include <iostream>
#include <string>
#include <list>
#include <fstream> // Para manipulação de arquivos
#include <sys/stat.h>  
#include <stdio.h>
#include <algorithm>  // Para a função std::sort

class Usuario {

public:

    std::list<Projeto> Projetos;

    // Construtores:
    Usuario(std::string name);

    // Retorno de membros privados da classe
    std::string nomeUsuario() const;

    // Métodos de manipulação da classe
    void AdicionaProjeto(Projeto p); //Adiciona um projeto a lista

    void MudarNome(std::string novoNome); //Modifica o nome do Usuario para o novo passado

    void ListarProjetos(int forma) const; //Imprime os Nomes dos Projetos de acordo com o parametro passado
    //Da Forma:
    //1 - Por nome (Ordem Alfabetica do Nome)
    //2 - Por Categoria (Ordem Alfabetica da Categoria)
    //3 - Por Ordem de Criação
    //Outro - Imprime "Forma não existente!"


private:
    
    //Funções Privadas para uso em Métodos:

    //1 - Por nome (Ordem Alfabetica do Nome)
    // Recebe uma lista de Projetos
    // Retorna uma lista dos nomes em ordem
    std::list<std::string> OrdenaNomes1(const std::list<Projeto>& Projetos) const {
        
         std::list<std::string> nomesOrdenados;

        for(const auto& projeto : Projetos){
            nomesOrdenados.push_back(projeto.NomeProjeto());
        }

        // Ordenando a lista de nomes
        nomesOrdenados.sort();

        return nomesOrdenados;
    }

    //2 - Por Categoria (Ordem Alfabetica da Categoria)
    // Recebe uma lista de Projetos
    // Retorna uma lista dos Nomes ordenada
    // de acordo com as categorias
    std::list<std::string> OrdenaNomes2(const std::list<Projeto>& Projetos) const {

        std::list<std::string> nomesOrdenados;

        // Criando uma lista de pares = (categoria, nome) para facilitar a ordenação
        std::list<std::pair<std::string, std::string>> paresCategNome;

        for (const auto& projeto : Projetos) {
            
            paresCategNome.push_back(std::make_pair(projeto.CategoriaProjeto(), projeto.NomeProjeto()));
        }

        // Ordenando a lista de pares
        paresCategNome.sort();

        for (const auto& par : paresCategNome) {
            nomesOrdenados.push_back(par.second);
        }

        return nomesOrdenados;
    }


    // Atributos da Classe
    std::string nome_;

};

#endif  // USUARIO_H_
