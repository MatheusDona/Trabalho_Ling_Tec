#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academia.h"

#define PRECO_BASICO 79.90f
#define PRECO_INTERMEDIARIO 109.90f
#define PRECO_PREMIUM 139.90f

void lerTexto(const char mensagem[], char destino[], int tamanho) {
    size_t tamanhoTexto;

    printf("%s", mensagem);
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    tamanhoTexto = strlen(destino);
    if (tamanhoTexto > 0 && destino[tamanhoTexto - 1] == '\n') {
        destino[tamanhoTexto - 1] = '\0';
    } else {
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
    }
}

int lerInteiro(const char mensagem[]) {
    char entrada[50];
    char *fim;
    long valor;

    while (1) {
        lerTexto(mensagem, entrada, sizeof(entrada));
        valor = strtol(entrada, &fim, 10);

        while (*fim == ' ') fim++;

        if (entrada[0] != '\0' && *fim == '\0') {
            return (int)valor;
        }
        printf("Valor invalido. Digite um numero inteiro.\n");
    }
}

int lerInteiroPositivo(const char mensagem[]) {
    int valor;
    do {
        valor = lerInteiro(mensagem);
        if (valor <= 0) {
            printf("Digite um valor maior que zero.\n");
        }
    } while (valor <= 0);
    return valor;
}

static int cpfValido(const char cpf[]) {
    int i, digitos = 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            digitos++;
        } else if (cpf[i] != '.' && cpf[i] != '-' && cpf[i] != ' ') {
            return 0;
        }
    }
    return digitos == 11;
}

static int abrirArquivo(FILE **arquivo, const char modo[]) {
    *arquivo = fopen(ARQUIVO_ALUNOS, modo);
    if (*arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO_ALUNOS);
        printf("Verifique se a pasta 'dados' existe.\n");
        return 0;
    }
    return 1;
}

static int buscarPorCPF(const char cpf[], Aluno *encontrado) {
    FILE *arquivo;
    Aluno aluno;

    if (!abrirArquivo(&arquivo, "rb")) return 0;

    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (strcmp(aluno.cpf, cpf) == 0) {
            if (encontrado != NULL) *encontrado = aluno;
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

static int escolherPlano(char plano[], float *valor) {
    int opcao;

    printf("\nPlanos disponiveis:\n");
    printf("1 - Basico         R$ %.2f\n", PRECO_BASICO);
    printf("2 - Intermediario  R$ %.2f\n", PRECO_INTERMEDIARIO);
    printf("3 - Premium        R$ %.2f\n", PRECO_PREMIUM);
    opcao = lerInteiro("Escolha o plano: ");

    switch (opcao) {
        case 1:
            strcpy(plano, "Basico");
            *valor = PRECO_BASICO;
            return 1;
        case 2:
            strcpy(plano, "Intermediario");
            *valor = PRECO_INTERMEDIARIO;
            return 1;
        case 3:
            strcpy(plano, "Premium");
            *valor = PRECO_PREMIUM;
            return 1;
        default:
            printf("Plano invalido.\n");
            return 0;
    }
}

static void mostrarAluno(const Aluno *aluno) {
    printf("\n---------- DADOS DO ALUNO ----------\n");
    printf("Nome: %s\n", aluno->nome);
    printf("CPF: %s\n", aluno->cpf);
    printf("Telefone: %s\n", aluno->telefone);
    printf("Idade: %d\n", aluno->idade);
    printf("Plano: %s\n", aluno->plano);
    printf("Mensalidade: R$ %.2f\n", aluno->valorMensalidade);
    printf("Situacao: %s\n", aluno->situacao);
    printf("------------------------------------\n");
}

void cadastrarAluno(void) {
    FILE *arquivo;
    Aluno aluno, existente;

    printf("\n===== CADASTRO DE ALUNO =====\n");
    lerTexto("Nome: ", aluno.nome, sizeof(aluno.nome));
    if (strlen(aluno.nome) == 0) {
        printf("O nome nao pode ficar vazio.\n");
        return;
    }

    lerTexto("CPF (11 digitos): ", aluno.cpf, sizeof(aluno.cpf));
    if (!cpfValido(aluno.cpf)) {
        printf("CPF invalido. Informe 11 digitos.\n");
        return;
    }
    if (buscarPorCPF(aluno.cpf, &existente)) {
        printf("Ja existe um aluno cadastrado com esse CPF.\n");
        return;
    }

    lerTexto("Telefone: ", aluno.telefone, sizeof(aluno.telefone));
    aluno.idade = lerInteiroPositivo("Idade: ");

    if (!escolherPlano(aluno.plano, &aluno.valorMensalidade)) {
        printf("Cadastro cancelado.\n");
        return;
    }

    strcpy(aluno.situacao, "Pendente");

    if (!abrirArquivo(&arquivo, "ab")) return;
    if (fwrite(&aluno, sizeof(Aluno), 1, arquivo) != 1) {
        printf("Erro ao salvar o aluno.\n");
    } else {
        printf("\nAluno cadastrado com sucesso! Mensalidade: R$ %.2f\n",
               aluno.valorMensalidade);
    }
    fclose(arquivo);
}

void listarAlunos(void) {
    FILE *arquivo;
    Aluno aluno;
    int quantidade = 0;

    if (!abrirArquivo(&arquivo, "rb")) return;

    printf("\n===== ALUNOS CADASTRADOS =====\n");
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        mostrarAluno(&aluno);
        quantidade++;
    }

    if (quantidade == 0) printf("Nenhum aluno cadastrado.\n");
    printf("Total de alunos: %d\n", quantidade);
    fclose(arquivo);
}

void buscarAluno(void) {
    char cpf[15];
    Aluno aluno;

    lerTexto("Informe o CPF do aluno: ", cpf, sizeof(cpf));
    if (buscarPorCPF(cpf, &aluno)) {
        mostrarAluno(&aluno);
    } else {
        printf("Aluno nao encontrado.\n");
    }
}

void alterarAluno(void) {
    FILE *arquivo, *temporario;
    Aluno aluno;
    char cpf[15], texto[100];
    int encontrado = 0, idade;

    lerTexto("CPF do aluno que deseja alterar: ", cpf, sizeof(cpf));
    if (!abrirArquivo(&arquivo, "rb")) return;

    temporario = fopen("dados/temporario.dat", "wb");
    if (temporario == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arquivo);
        return;
    }
