# 🏋️ Sistema de Academia

Sistema desenvolvido em **linguagem C** para auxiliar no gerenciamento
de alunos, mensalidades e pagamentos de uma academia.

O projeto foi desenvolvido como atividade acadêmica da disciplina de
**Linguagem e Técnicas de Programação**, com foco na utilização de
estruturas de dados, funções, arquivos e modularização em C.

## 📌 Sobre o projeto

Uma academia necessita de uma forma organizada de controlar seus alunos,
mensalidades e pagamentos.

O **Sistema de Academia** tem como objetivo facilitar esse
gerenciamento, permitindo cadastrar e administrar alunos, controlar a
situação das mensalidades e gerar relatórios para auxiliar a
administração.

## ⚙️ Funcionalidades

-   **Cadastrar aluno**
    -   Nome, CPF, telefone, idade e plano.
    -   Valor da mensalidade.
    -   Situação da mensalidade.
-   **Listar alunos**
    -   Exibe todos os alunos cadastrados e suas informações.
-   **Buscar aluno**
    -   Permite localizar um aluno através do CPF.
-   **Alterar cadastro**
    -   Permite alterar nome, telefone, idade e plano.
    -   O valor da mensalidade é atualizado caso o plano seja alterado.
-   **Excluir aluno**
    -   Permite excluir um aluno através do CPF.
-   **Registrar pagamento**
    -   Localiza o aluno pelo CPF.
    -   Altera a situação da mensalidade para **Pago**.
-   **Listar pendentes**
    -   Exibe somente os alunos que possuem mensalidade **Pendente**.
-   **Iniciar novo mês**
    -   Solicita confirmação antes da operação.
    -   Altera a situação de todos os alunos para **Pendente**.
-   **Relatório da academia**
    -   Quantidade total de alunos.
    -   Quantidade de alunos pagos.
    -   Quantidade de alunos pendentes.
    -   Quantidade de alunos por plano.
    -   Renda recebida com base nas mensalidades pagas.

## 🧱 Estrutura do projeto

``` text
Sistema_Academia/
│
├── main.c
├── academia.h
├── academia.c
│
└── dados/
    └── alunos.dat
```

### `main.c`

Responsável pelo funcionamento principal do programa, incluindo o menu,
a leitura da opção escolhida, a estrutura `switch/case` e a chamada das
funções.

### `academia.h`

Contém a declaração da `struct Aluno` e os protótipos das funções
utilizadas pelo sistema.

### `academia.c`

Contém a implementação das funcionalidades, validações e manipulação dos
dados.

### `dados/alunos.dat`

Arquivo utilizado para armazenar permanentemente os dados dos alunos
cadastrados.

## 🗃️ Estrutura de dados

Cada aluno será representado por uma estrutura `Aluno` contendo:

``` c
struct Aluno {
    char nome[100];
    int idade;
    char cpf[15];
    char telefone[20];
    char plano[30];
    float valorMensalidade;
    char situacao[15];
};
```

## 📋 Menu do sistema

``` text
========== ACADEMIA ==========

1 - Cadastrar aluno
2 - Listar alunos
3 - Buscar aluno
4 - Alterar cadastro
5 - Excluir aluno
6 - Registrar pagamento
7 - Listar pendentes
8 - Iniciar novo mês
9 - Relatório da academia
0 - Sair
```

## 💾 Armazenamento dos dados

O sistema utilizará arquivos para armazenar os registros dos alunos.

Os dados serão gravados no arquivo:

``` text
dados/alunos.dat
```

Isso permitirá que os registros continuem disponíveis mesmo após o
encerramento do programa.

## 🔄 Controle das mensalidades

Ao cadastrar um aluno, sua mensalidade será iniciada automaticamente
como **Pendente**.

Quando o pagamento for registrado, sua situação será alterada para
**Pago**.

Ao iniciar um novo mês, o sistema alterará todos os alunos novamente
para **Pendente**.

Na versão inicial do projeto, não será armazenado um histórico mensal
dos pagamentos.

## 📊 Relatório

O relatório da academia utilizará os dados armazenados no arquivo para
apresentar:

-   Total de alunos;
-   Total de alunos pagos;
-   Total de alunos pendentes;
-   Quantidade de alunos por plano;
-   Valor total recebido dos alunos com situação **Pago**.

## 🧠 Organização e lógica

O sistema será desenvolvido de forma modular, separando o menu principal
da implementação das funcionalidades.

A lógica planejada para cada funcionalidade está documentada junto aos
fluxogramas do projeto.

## 🛠️ Tecnologias

-   **Linguagem:** C
-   **Armazenamento:** Arquivo `.dat`
-   **Versionamento:** Git
-   **Repositório:** GitHub

## 🎯 Objetivo acadêmico

O projeto tem como objetivo colocar em prática conceitos da linguagem C,
incluindo:

-   Entrada e saída de dados;
-   Estruturas condicionais;
-   Estruturas de repetição;
-   Funções;
-   Modularização;
-   `struct`;
-   Strings;
-   Manipulação de arquivos;
-   Leitura e escrita de dados;
-   Organização de projetos;
-   Versionamento utilizando Git e GitHub.

## 👥 Projeto

Projeto desenvolvido como atividade acadêmica de **Engenharia de
Software / Linguagem e Técnicas de Programação**.

**Sistema de Academia --- 2026**
