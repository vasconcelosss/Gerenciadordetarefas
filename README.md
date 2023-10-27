# Gerenciador de Projetos
Trabalho pratico de PDS2 turma TM1 UFMG

# Descrição do Projeto:
O Gerenciador de Projetos em C++ é uma aplicação de linha de comando, desenvolvida para simplificar o gerenciamento de projetos e tarefas de forma eficaz. Esta ferramenta permite aos usuários criar, editar, priorizar, visualizar e pesquisar projetos e tarefas com metas e prioridades.

## Forma de Implementaçao:
O Gerenciador de Projetos é implementado em C++ usando a versão de 2011 da linguagem. Ele utiliza uma estrutura de pastas para organizar os projetos e tarefas de cada usuário. Cada projeto é detalhado em um arquivo de texto que contém informações como nome, descrição, categoria e status de conclusão. As tarefas associadas a cada projeto também são armazenadas em arquivos separados, permitindo o acompanhamento das metas e prazos.

## Classes:
### Class `Usuarios`:
Responsável por gerenciar informações do usuário, como seu nome e a pasta onde os projetos são armazenados.
#### Colaborações:
- `string projetos`
- `string nome`

#### Construtor:
`Usuario(string name)`
// Cria um usuário com o nome "name"

#### Métodos:
- `string nomeUsuario()`
  // Retorna o nome do Usuario
- `string pastaProjetos()`
  // Retorna o string do caminho da pasta onde estão os projetos

### Class `Projetos`:
Responsável por gerenciar informações dos projetos, incluindo nome, descrição, categoria e status de conclusão.
#### Colaborações:
- `string nome`
- `string usuario`
- `string tarefa`
- `string descricao`
- `string categoria`
- `bool conclusao`

#### Construtor:
`Projetos(string categoria, string diretorio)`
// Cria um Projeto com a categoria e no diretório (usuário) passado

#### Métodos:
- `string nomeProjeto()`
  // Retorna o nome do Projeto
- `string pastaTarefas()`
  // Retorna o caminho da pasta onde estão as tarefas
- `string categoriaProjeto()`
  // Retorna a categoria do Projeto
- `bool conclusaoProjeto()`
  // Retorna o status de conclusão do Projeto
- `string caminDescricao()`
  //Retorna o caminho para o arquivo de texto de descrição
- `void mudarNome(string novoNome)`
  //Modifica o nome do Projeto para o novo passado

### Class `Tarefas`:
Responsável por gerenciar informações das tarefas, incluindo nome, prioridade, descrição, data de conclusão e status de conclusão.
#### Colaborações:
- `string nome_`
- `string projeto_`
- `string prioridade_`
- `string descricao_`
- `string data_conclusao_`
- `bool conclusao_`

#### Construtor:
- `Tarefa(std::string nome, std::string prioridade, std::string projeto)`
//Cria uma tarefa com nome, prioridade e associação a um projeto.
- `Tarefa(std::string nome, std::string prioridade, std::string dataConcluir, std::string projeto)`
//Cria uma tarefa com nome, prioridade, data de conclusão e associação a um projeto.

#### Métodos:
- `string NomeTarefa()`
- `string Projeto()`
- `string Propriedade()`
- `string CaminhoDescricao()`
- `string DataMeta()`
- `bool Conclusao()`
- `void MudarNome(string novoNome)`
- `void ConcluirTarefa()`
- `void Descrever()`
- `void MudarDescricao()`
