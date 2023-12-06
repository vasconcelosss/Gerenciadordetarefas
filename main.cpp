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
    
    if(ptr_tarefa_atual == nullptr){
        std::cout << "Tarefa não existente!" << std::endl;
        return;
    }

    while(!fim){

        std::cout << std::endl << "Usuário " << usuario_atual << std::endl;
        std::cout << std::endl << "O que deseja fazer?" << std::endl;
        std::cout << "Digite 1: Para renomear a Tarefa " << ptr_tarefa_atual->NomeTarefa() << "." << std::endl;
        if(ptr_tarefa_atual->CaminhoDescricao() == ""){
            std::cout << "Digite 200: Para criar uma Descrição para a Tarefa." << std::endl;
        } else{
            std::cout << "Digite 201: Para mudar a descrição (Apaga a anterior)." << std::endl;
            std::cout << "Digite 202: Para exibir a descrição da Tarefa." << std::endl;
        }
        std::cout << "Digite 3: Para concluir a Tarefa." << std::endl;
        std::cout << "Digite 4: Para ver o estatus de conclusão da Tarefa." << std::endl;
        std::cout << "Digite 50: Para ver a Data meta de Conclusão." << std::endl;
        std::cout << "Digite 51: Para mudar a data meta da Tarefa." << std::endl;
        std::cout << "Digite 6: Para ver a Prioridade da sua tarefa." << std::endl;        
        std::cout << "Digite 7: Para voltar as opções anteriores." << std::endl;

	    int num;
        std::cin >> num;

        if(num == 1){
            std::string novo_nome_tarefa;

            std::cout << "Digite o novo nome a ser atribuido para sua Tarefa: ";
            std::cin >> novo_nome_tarefa;
            
            ptr_tarefa_atual->MudarNome(novo_nome_tarefa);

            std::cout << "A Tarefa foi renomeada!" << std::endl;
        }
        else { 
            if(num == 200){
                std::string descricao_taref;
                std::cout << "Digite a descrição da Tarefa: (Digite \"fim\" para terminar) " << std::endl;
                std::string linha;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while (linha!= "fim"){
                    std::getline(std::cin, linha);
                    if(linha != "fim"){
                        descricao_taref += linha + "\n";
                    }
                }
                ptr_tarefa_atual->Descrever(descricao_taref);
                std::cout << std::endl << "Descrição adicionada" << std::endl;
            }
            else {
                if(num == 201){
                    std::string nova_descricao_taref;
                    std::cout << "Digite a nova descrição da Tarefa: (Digite \"fim\" para terminar) " << std::endl;
                    std::string linha;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    while (linha!= "fim"){
                        std::getline(std::cin, linha);
                        if(linha != "fim"){
                            nova_descricao_taref += linha + "\n";
                        }
                    }
                    ptr_tarefa_atual->MudarDescricao(nova_descricao_taref);

                    std::cout << std::endl << "Descrição adicionada" << std::endl;
                }
                if(num == 202){
                    std::cout << std::endl;
                    ptr_tarefa_atual->ExibiDescricao();
                    std::cout << std::endl << std::endl;
                }
                if(num == 3){
                    ptr_tarefa_atual->ConcluirTarefa();
                    std::cout << "Tarefa concluída!" << std::endl;
                }
                if(num == 4){
                    if(ptr_tarefa_atual->Conclusao()){
                        std::cout << "Concluido!" << std::endl;
                    } else{
                        std::cout << "Ainda não concluido." << std::endl;
                    }
                }
                if(num == 50){
                    std::cout << "A data é: " << ptr_tarefa_atual->DataMeta() << std::endl;
                }
                if(num == 51){
                    std::string novaData;

                    std::cout << "Digite a nova data da Tarefa: ";
                    std::cin >> novaData;
                        
                    ptr_tarefa_atual->MudarDataMeta(novaData);

                    std::cout << "Data modificada para " << novaData << std::endl;
                }
				if(num == 6){
					std::cout << "A prioridade da Tarefa é: " << ptr_tarefa_atual->Prioridade() << std::endl;
				}
                if(num == 7){
                        std::cout << std::endl;
                        fim = true;
                }
            }
        }
       
    }
}
void FuncoesProjeto(std::string usuario_atual, std::list<Projeto>& projetos, const std::string& projeto_atual){
    
    bool fim = false;
    Projeto* ptr_projeto_atual = nullptr;
    for(auto& proj : projetos){
        if (proj.NomeProjeto() == projeto_atual) {
            ptr_projeto_atual = &proj;
            break;
        }
    }
    
    if(ptr_projeto_atual == nullptr){
        std::cout << "Projeto não existente!" << std::endl;
        return;
    }

    while(!fim){

        std::cout << std::endl << "Usuário " << usuario_atual << std::endl;
        std::cout << std::endl << "O que deseja fazer?" << std::endl;
        std::cout << "Digite 1: Para renomear o Projeto " << ptr_projeto_atual->NomeProjeto() << "." << std::endl;
        if(ptr_projeto_atual->CaminhoDescricao() == ""){
            std::cout << "Digite 200: Para criar uma Descrição." << std::endl;
        } else{
            std::cout << "Digite 201: Para mudar a descrição (Apaga a anterior)." << std::endl;
            std::cout << "Digite 202: Para exibir a descrição." << std::endl;
        }
        std::cout << "Digite 3: Para criar uma Tarefa." << std::endl;
        if(ptr_projeto_atual->Tarefas.size()){
            std::cout << "Digite 4: Para entrar em uma Tarefa." << std::endl;
        }
        else{
            std::cout << "Após criar um Projeto você poderá entrar digitando 4" << std::endl;
        }
        std::cout << "Digite 5: Para concluir o Projeto." << std::endl;
        std::cout << "Digite 6: Para ver o estatus de conclusão do Projeto." << std::endl;
        std::cout << "Digite 70: Para ver a categoria do Projeto." << std::endl;
        std::cout << "Digite 71: Para mudar a categoria do Projeto." << std::endl;
        std::cout << "Digite 8: Para voltar as opções anteriores." << std::endl;

        int num;
        std::cin >> num;

        if(num == 1){
            std::string novo_nome_projeto;

            std::cout << "Digite o novo nome do Projeto: ";
            std::cin >> novo_nome_projeto;
            
            ptr_projeto_atual->MudarNome(novo_nome_projeto);

            std::cout << "Projeto renomeado!" << std::endl;
        }
        else { 
            if(num == 200){
                std::string descricao_proj;
                std::cout << "Digite a descrição do Projeto: (Digite \"fim\" para terminar) " << std::endl;
                std::string linha;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while (linha!= "fim"){
                    std::getline(std::cin, linha);
                    if(linha != "fim"){
                        descricao_proj += linha + "\n";
                    }
                }
                ptr_projeto_atual->Descrever(descricao_proj);
                std::cout << std::endl << "Descrição adicionada" << std::endl;
            }
            else {
                if(num == 201){
                    std::string nova_descricao_proj;
                    std::cout << "Digite a nova descrição do Projeto: (Digite \"fim\" para terminar) " << std::endl;
                    std::string linha;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    while (linha!= "fim"){
                        std::getline(std::cin, linha);
                        if(linha != "fim"){
                            nova_descricao_proj += linha + "\n";
                        }
                    }
                    ptr_projeto_atual->MudarDescricao(nova_descricao_proj);

                    std::cout << std::endl << "Descrição adicionada" << std::endl;
                }
                if(num == 202){
                    std::cout << std::endl;
                    ptr_projeto_atual->ExibiDescricao();
                    std::cout << std::endl << std::endl;
                }
                if(num == 3){
                    std::string nome_tarefa;
                    std::string prioridade_tarefa = "";
                    std::string data_meta_tarefa;
                    std::string diretorio_completo = usuario_atual + "/" + projeto_atual;

                    std::cout << "Digite o nome da Tarefa a ser criada: ";
                    std::cin >> nome_tarefa;

                    while(((prioridade_tarefa != "Baixa") && (prioridade_tarefa != "Media")) && (prioridade_tarefa != "Alta")){
                        std::cout << "Digite a Prioridade da Tarefa a ser criada (Baixa/Media/Alta): ";
                        std::cin >> prioridade_tarefa;
                    }


                    bool respostaOk = false;

                    while(!respostaOk){
                        std::string resposta;
                        std::cout << std::endl << "Deseja dar uma Data de meta para conclusão da Tarefa? [S/N]" << std::endl;
                        std::cin >> resposta;

                        if(resposta == "S"){
                            respostaOk = true;
                            std::cout << "Informe a data (dd/mm/aaaa): ";
                            std::cin >> data_meta_tarefa;
                            ptr_projeto_atual->Tarefas.push_back(Tarefa(nome_tarefa, prioridade_tarefa, data_meta_tarefa, diretorio_completo));
                        }else{
                            if(resposta == "N"){
                                respostaOk = true;
                                std::cout << "Criando sem data..." << std::endl;
                                ptr_projeto_atual->Tarefas.push_back(Tarefa(nome_tarefa, prioridade_tarefa, diretorio_completo));
                            }
                            else{
                                std::cout << "Resposta inválida! Digite S para Sim  ou  N para Não" << std::endl;
                            }
                        }   
                    }
                    std::cout << "Tarefa " << nome_tarefa << " criada!" << std::endl;
                    std::cout << "Entrando em " << nome_tarefa << "!" << std::endl;

                    FuncoesTarefa(usuario_atual, ptr_projeto_atual->Tarefas,nome_tarefa);
                }
                if(num == 4){
                    std::string nome_tarefa;
                    std::cout << "Digite o nome da Tarefa que deseja entrar: ";
                    std::cin >> nome_tarefa;
                    FuncoesTarefa(usuario_atual, ptr_projeto_atual->Tarefas,nome_tarefa);
                }
                if(num == 5){
                    ptr_projeto_atual->ConcluirProjeto();
					std::cout << "Projeto concluido!" << std::endl;
                }
                if(num == 6){
                    if(ptr_projeto_atual->ConclusaoProjeto()){
                        std::cout << "Concluido!" << std::endl;
                    } else{
                        std::cout << "Ainda não concluido." << std::endl;
                    }
                }
                if(num == 70){
					if(ptr_projeto_atual->CategoriaProjeto() != ""){
                      std::cout << "A categoria é: " << ptr_projeto_atual->CategoriaProjeto() << std::endl;
					}
                    else{
					    std::cout << "A categoria não foi definida." << std::endl;
					}
                }
                if(num == 71){
                    std::string novaCategoria;

                    std::cout << "Digite a nova categoria do Projeto: ";
                    std::cin >> novaCategoria;
                        
                    ptr_projeto_atual->MudarCategoria(novaCategoria);

                    std::cout << "Categoria modificada para " << novaCategoria << "!" << std::endl;
                }
                if(num == 8){
                        std::cout << std::endl;
                        fim = true;
                }
            }
        }
    }
}


void FuncoesUsuario(std::vector<Usuario>& users, std::string usuario_atual){


    bool fim = false;
    int num_usuario_atual = 0;
    for(bool achado = false; !achado; num_usuario_atual++){
        if(users[num_usuario_atual].nomeUsuario() == usuario_atual){
            achado = true;
        }
        if((num_usuario_atual-2) > users.size()){
            std::cout << "Usuario inexistente!" << std::endl;
        }
    }
    num_usuario_atual--;

    while(!fim){

        std::cout << std::endl << "Usuário " << users[num_usuario_atual].nomeUsuario() << std::endl;
        std::cout << std::endl << "O que deseja fazer?" << std::endl;

        std::cout << "Digite 1: Para criar um Projeto." << std::endl;  
        if(users[num_usuario_atual].Projetos.size()){
            std::cout << "Digite 2: Para entrar em um Projeto." << std::endl;
        }
        else{
            std::cout << "Após criar um Projeto você poderá entrar digitando 2." << std::endl;
        }
        std::cout << "Digite 3: Listar os Projetos deste Usuário." << std::endl;
        std::cout << "Digite 4: Mudar o Nome do Usuário." << std::endl;
        std::cout << "Digite 5: Para voltar as opções anteriores." << std::endl;

        int num;
        std::cin >> num;

        if(num == 1){
            std::string nome_projeto;
            std::string categoria_projeto;

            std::cout << "Digite o nome do Projeto a ser criado: ";
            std::cin >> nome_projeto;

            bool respostaOk = false;

            while(!respostaOk){
                std::string resposta;
                std::cout << std::endl << "Deseja dar uma categoria ao projeto? [S/N]" << std::endl;
                std::cin >> resposta;

                if(resposta == "S"){
                    respostaOk = true;
                    std::cout << "Informe a categoria: ";
                    std::cin >> categoria_projeto;
                    users[num_usuario_atual].AdicionaProjeto(Projeto(nome_projeto, categoria_projeto, usuario_atual));
                }else{
                    if(resposta == "N"){
                        respostaOk = true;
                        std::cout << "Criando sem categoria..." << std::endl;
                        users[num_usuario_atual].Projetos.push_back(Projeto(nome_projeto, usuario_atual));
                    }
                    else{
                        std::cout << "Resposta inválida! Digite S para Sim  ou  N para Não" << std::endl;
                    }
                }
            }
            
            std::cout << "Projeto " << nome_projeto << " criado!" << std::endl;
            std::cout << "Entrando em " << nome_projeto << "!" << std::endl;

            FuncoesProjeto(usuario_atual, users[num_usuario_atual].Projetos,nome_projeto);
        }
        else { 
            if(num == 2){
                std::string nome_projeto;
                std::cout << "Digite o nome do Projeto que deseja entrar: ";
                std::cin >> nome_projeto;
                FuncoesProjeto(usuario_atual, users[num_usuario_atual].Projetos,nome_projeto);
            }
            else {
                if(num == 3){
                    std::cout << "Informe o número da maneira que gostaria de listar:" << std::endl;
                    std::cout << "1 - Por Nome" << std::endl;
                    std::cout << "2 - Por Categoria"  << std::endl;
                    std::cout << "3 - Por Ordem de Criação" << std::endl;

                    int resposta;
                    std::cin >> resposta;

                    users[num_usuario_atual].ListarProjetos(resposta);
                }
                else{
                    if(num == 4){
                        std::string novo_nome_usuario;

                        std::cout << "Digite o novo nome do Usuario: ";
                        std::cin >> novo_nome_usuario;
                        
                        users[num_usuario_atual].MudarNome(novo_nome_usuario);

                        std::cout << "Usuario renomeado!" << std::endl;
                    }
                    else{
                        if(num == 5){
                            std::cout << std::endl << std::endl;
                            fim = true;
                        }
                    }
                }
            }
        }
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
            std::cout << "Digite o nome do Usuário a ser criado: ";
            std::cin >> nome_usuario;
            Usuario usuarioParaAdicionar(nome_usuario);
            users.push_back(usuarioParaAdicionar);

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
                    fim = true;
                }
            }
        }
    }
}



int main(){

    std::vector<Usuario> users;

    std::cout << "\033[1;34m";
    std::cout << "---- Bem vindo ao Gerenciador de Projetos! ----" <<  "\033[0m" << std::endl;

    std::cout << "\033[1;37m";
    std::cout<< "Esta aplicação foi desenvolvida visando ser rodada em sistemas Unix!" << std::endl;


    Inicio(users);


    std::cout << std::endl << std::endl << "\033[1;37m";
    std::cout << "Agradecemos por utilizar o Gerenciador de Projetos!" <<  "\033[0m" << std::endl;

    std::cout << "\033[1;37m"; 
    std::cout << "Para visualizar o código do projeto, visite o repositório no GitHub:" <<  "\033[0m" <<std::endl;

    std::cout << "\033[1;32m"; 
    std::cout << "https://github.com/vasconcelosss/Gerenciadordetarefas.git" << "\033[0m" << std::endl;
    
    std::cout << std::endl << std::endl;

    return 0;
}
