#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <ctime>

class Tarefas {
private:
    std::string nome_;
    // Projeto que ela está contida, o local na máquina
    std::string projeto_; 
    std::string prioridade_;
    std::string descricao_;
    // Meta para conclusao da tarefa
    // Se = "00/00/0000", entao nao foi definida uma meta
    std::string data_conclusao_;
    bool conclusao_;

public:
    Tarefas(std::string nome, std::string prioridade) {
        nome_ = nome;
        prioridade_ = prioridade;
        data_conclusao_ = "00/00/0000";
        conclusao_ = false;
    }
    Tarefas(std::string nome, std::string prioridade, std::string conlusao){
        nome_ = nome;
        prioridade_ = prioridade;
        data_conclusao_ = conclusao;
        conclusao_ = false;

    std::string NomeTarefa() {
        return nome_user;
    }

    std::string Projeto() {
        return projeto_nome;
    }

    std::string Prioridade() {
        return prioridade;
    }

    std::string CaminhoDescricao() {
        return descricao;
    }

    std::string DataMeta() {
        return data_conclusao;
    }

    bool Conclusao() {
        return status;
    }
};

std::map<int, Tarefas> listagem_tarefas;

// Função para criar uma tarefa
void criarTarefa(const std::string& nome_user, const std::string& projeto_nome, const std::string& descricao, const std::string& data_conclusao, const std::string& prioridade) {
    int id = rand(); // Gere um ID aleatório
    Tarefas tarefa(id, nome_user, projeto_nome, descricao, data_conclusao, prioridade, "Pendente");
    listagem_tarefas[id] = tarefa;
    salvarTarefas();
}

// Salvar as tarefas em um arquivo
void salvarTarefas() {
    std::ofstream arquivo("Tarefas.txt");
    for (const auto& pair : listagem_tarefas) {
        arquivo << "ID: " << pair.second.getID() << "\n";
        arquivo << "Nome do Usuário: " << pair.second.getNomeUser() << "\n";
        arquivo << "Nome do Projeto: " << pair.second.getProjetoNome() << "\n";
        arquivo << "Prioridade: " << pair.second.getPrioridade() << "\n";
        arquivo << "Descrição: " << pair.second.getDescricao() << "\n";
        arquivo << "Data de Conclusão: " << pair.second.getDataConclusao() << "\n";
        arquivo << "Status: " << pair.second.getStatus() << "\n\n";
    }
    arquivo.close();
}

// Função para listar tarefas
void listarTarefas() {
    for (const auto& pair : listagem_tarefas) {
        std::cout << "ID: " << pair.second.getID() << "\n";
        std::cout << "Nome do Usuário: " << pair.second.getNomeUser() << "\n";
        std::cout << "Nome do Projeto: " << pair.second.getProjetoNome() << "\n";
        std::cout << "Prioridade: " << pair.second.getPrioridade() << "\n";
        std::cout << "Descrição: " << pair.second.getDescricao() << "\n";
        std::cout << "Data de Conclusão: " << pair.second.getDataConclusao() << "\n";
        std::cout << "Status: " << pair.second.getStatus() << "\n\n";
    }
}

int main() {
    criarTarefa("Nome do Usuário", "Nome do Projeto", "Descrição da tarefa", "2023-10-23", "Alta");
    listarTarefas();
    return 0;
}
