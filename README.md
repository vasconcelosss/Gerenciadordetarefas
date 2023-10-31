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
`Usuario(string nome)`
// Cria um usuário

#### Métodos:
- `string nomeUsuario()`
  // Retorna o nome do Usuario
- `string pastaProjetos()`
  // Retorna o string do caminho da pasta onde estão os projetos

### Class `Projetos`:
Responsável por gerenciar informações dos projetos, incluindo nome, descrição, categoria e status de conclusão.
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
Responsável por gerenciar informações das tarefas, incluindo nome, prioridade, descrição, data de conclusão e status de conclusão.
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
