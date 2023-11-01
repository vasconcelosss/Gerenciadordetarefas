#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

class Tarefas {
private:
    int id;
    std::string nome_user;
    std::string projeto_nome;
    std::string prioridade;
    std::string descricao;
    std::string data_conclusao;
    std::string status;

public:
    Tarefas(int id, std::string nome_user, std::string projeto_nome, std::string descricao, std::string data_conclusao, std::string prioridade, std::string status) {
        this->id = id;
        this->nome_user = nome_user;
        this->projeto_nome = projeto_nome;
        this->descricao = descricao;
        this->data_conclusao = data_conclusao;
        this->prioridade = prioridade;
        this->status = status;
    }

    int getID() {
        return id;
    }

    std::string getNomeUser() {
        return nome_user;
    }

    std::string getProjetoNome() {
        return projeto_nome;
    }

    std::string getPrioridade() {
        return prioridade;
    }

    std::string getDescricao() {
        return descricao;
    }

    std::string getDataConclusao() {
        return data_conclusao;
    }

    std::string getStatus() {
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
