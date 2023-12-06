# Gerenciador de Projetos
Trabalho pratico de PDS2 turma TM1 UFMG

# Descrição do Projeto:
O Gerenciador de Projetos em C++ é uma aplicação de linha de comando, desenvolvida para simplificar o gerenciamento de projetos e tarefas de forma eficaz. Esta ferramenta permite aos usuários criar, editar, priorizar, visualizar e pesquisar projetos e tarefas com metas e prioridades.

## Forma de Implementaçao:
O Gerenciador de Projetos é implementado em C++ usando a versão de 2011 da linguagem. Ele utiliza uma estrutura de pastas para organizar os projetos e tarefas de cada usuário. Cada projeto é detalhado em um arquivo de texto que contém informações como nome, descrição, categoria e status de conclusão. As tarefas associadas a cada projeto também são armazenadas em arquivos separados, permitindo o acompanhamento das metas e prazos. O tratamento de exceções é realizado dentro do corpo da função, de acordo com o estilo adotado no projeto.

## Classes:
### Class `Usuarios`:
Responsável pela criação e manipulação de usuários, projetos e tarefas, permitindo a adição de projetos, alteração de nomes de usuários e a listagem de projetos de acordo com diferentes critérios de ordenação.
- Classe Usuario representa um usuário do sistema. Quando um objeto Usuário é criado, um diretório com o nome do usuário é criado no sistema de arquivos.
- Métodos da classe:
    - AdicionaProjeto(Projeto p): Adiciona um projeto à lista de projetos do usuário.
    - MudarNome(std::string novoNome): Altera o nome do usuário e atualiza o nome do usuário em todos os projetos associados.
    - ListarProjetos(int forma) const: Lista os projetos do usuário de acordo com a forma especificada. Os projetos são listados ordenados de acordo com o critério especificado.
- Funções auxiliares:
    - OrdenaNomes1(std::vector<Projeto> projetos): Função auxiliar para ordenar os nomes dos projetos de acordo com o critério 1.
    - OrdenaNomes2(std::vector<Projeto> projetos): Função auxiliar para ordenar os nomes dos projetos de acordo com o critério 2.
#### Colaborações:
- `string projetos`
- `string nome`

#### Construtor:
`Usuario(string nome)`
// Cria um usuário

#### Métodos:
- `string nomeUsuario() const`
	// Retorno de membros privados da classe
- `void AdicionaProjeto(Projeto p)` 
	//Adiciona um projeto a lista
- `void MudarNome(std::string novoNome)` 
	//Modifica o nome do Usuario para o novo passado
- `void ListarProjetos(int forma) const` 
	//Imprime os Nomes dos Projetos de acordo com o parametro passado
 privadas 
- `std::list<std::string> OrdenaNomes1(const std::list<Projeto>& Projetos)` 
	// Recebe uma lista de Projetos e retorna uma lista dos nomes em ordem
- `std::list<std::string> OrdenaNomes2(const std::list<Projeto>& Projetos)`
	// Recebe uma lista de Projetos e retorna uma lista dos Nomes ordenada de acordo com as categorias



### Class `Projetos`:
Responsável pela criação, manipulação e descrição dos projetos, incluindo a capacidade de manipular diretório, aqruivos de descrição e outras operações relacionadas.
- Os construtores inicializam os membros da classe com os valores fornecidos e chamam o método CriaDiretorioProjeto para criar o diretório do projeto.
- Método CriaDiretorioProjeto cria um diretório para o projeto, utilizando o nome do usuário e o nome do projeto.
- Métodos de retorno:
    - NomeProjeto(), UsuárioDoProjeto(), CaminhoDescrição(), CategoriaProjeto() e ConclusãoProjeto() retornam os membros privados da classe.
- Métodos de manipulação:
    - MudarNomeDoUsuario, MudarNome, MudarCategoria, ConcluirProjeto, Descrever, MudarDescricao e ExibiDescrizo realizam operações como mudar o nome do usuário associado ao projeto, mudar o nome do projeto, marcar o projeto como concluído, descrever o projeto, manipular a descrição do projeto e exibir a descrição.
#### Colaborações:
- `string nome_`
- `string usuario_`
- `string descricao_`
- `string categoria_`
- `bool conclusao_`

#### Responsabilidades:
##### Construtor:
`Projetos(string categoria, string diretorio)`
// Cria um Projeto com a categoria e no diretório (usuário) passado
`Projeto(std::string nome, std::string categoria, std::string diretorio)` 
// Cria um Projeto com o nome, a categoria e no diretório (usuário) passado

##### Métodos:
- `string NomeProjeto()`
  // Retorna o nome do Projeto
- `string UsuarioDoProjeto()`
  // Retorna o Usuário ao qual o projeto está vinculado
- `string CaminhoDescricao()`
  // Retorna o caminho para o arquivo de texto de descrição
- `string CategoriaProjeto()`
  // Retorna a categoria do Projeto
- `bool ConclusaoProjeto()`
  // Retorna o status de conclusão do Projeto
- `void MudarNome(string novoNome)`
  // Modifica o nome do Projeto para o novo passado
- `void ConcluirProjeto()`
  // Muda o status de conclusão para valor Verdadeiro
- `void Descrever(string textoDescrica)`
  // Cria um arquivo descricao.txt na pasta da tarefa com a descrição da mesma pedida na função
- `void MudarDescricao(std::string NovaDescricao)`
  // Apaga o conteúdo da descrição e substitui por um outro pedido na função
- `void ExibiDescricao()`
  // Exibe o conteúdo da descrição
  

### Class `Tarefas`:
Responsável pela criação, manipulação e visualização de tarefas em um sistema de gerenciador de tarefas. Ele utiliza, operações de manipulação de arquivos e diretórios para realizar essas tarefas.
- A função CriaDiretorioTarefa cria um diretório para a tarefa, utilizando o nome do projeto e o nome da tarefa.
- Os construtores inicializam os membros da classe com os valores fornecidos e chamam a função CriaDiretorioTarefa para criar o diretório da tarefa
- Os métodos NomeTarefa, Projeto, Prioridade, CaminhoDescrição, DataMeta e Conclusão retornam os valores dos membros privados da classe
- Os métodos MudarNomedoProjeto, MudarNome, MudarDataMeta, ConcluirTarefa, Descrever, MudarDescricao e ExibiDescrizo realizam operações como mudar o nome do projeto, mudar o nome da tarefa, mudar a data de conclusão, marcar a tarefa como concluída, descrever a tarefa, mudar a descrição e exibir a descrição, respectivamente.
#### Colaborações:
- `string nome_`
- `string projeto_`
- `string prioridade_`
- `string descricao_`
- `string data_conclusao_`
- `bool conclusao_`


#### Responsabilidades:
##### Construtor:
- `Tarefa(std::string nome, std::string prioridade, std::string projeto)`
//Cria uma tarefa com nome, prioridade e associação a um projeto.
- `Tarefa(std::string nome, std::string prioridade, std::string dataConcluir, std::string projeto)`
//Cria uma tarefa com nome, prioridade, data de conclusão e associação a um projeto.

##### Métodos:
- `string NomeTarefa()` // Retorna o nome da Tarefa
- `string Projeto()` // Retorna o o diretório do projeto e usuário de Tarefa ("Usuario/Projeto")
- `string Propriedade()` // Retorna a prioridade da Tarefa
- `string CaminhoDescricao()` // Retorna o caminho para o arquivo descricao da Tarefa
- `string DataMeta()` // Retorna a data de meta de conclusão da Tarefa
- `bool Conclusao()` // Retorna o estado de conclusão da Tarefa
- `void MudarNome(string novoNome)`// Muda o nome da Tarefa
- `void ConcluirTarefa()` // Muda o status de conclusão para valor Verdadeiro
- `void Descrever()` // Cria um arquivo descricao.txt na pasta da tarefa com a descrição da mesma pedida na função
- `void MudarDescricao()` // Apaga o conteúdo da descrição e substitui por um outro pedido na função
- `void ExibirDescrição()`
