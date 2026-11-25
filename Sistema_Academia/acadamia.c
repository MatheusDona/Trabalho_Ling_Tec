#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "academia.h"

char nomes[MAX_ALUNOS][100];
char cpfs[MAX_ALUNOS][15];
char telefones[MAX_ALUNOS][20];
int idades[MAX_ALUNOS];
int planos[MAX_ALUNOS];
float mensalidades[MAX_ALUNOS];
int pagos[MAX_ALUNOS];
int totalAlunos = 0;


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void lerTexto(char texto[], int tamanho) {
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

int lerInteiro() {
    int numero = -1;
    scanf("%d", &numero);
    limparBuffer();
    return numero;
}


static int soDigitos(char texto[], int min, int max) {
    int i;
    int tamanho = strlen(texto);

    if (tamanho < min || tamanho > max) {
        return 0;
    }
    for (i = 0; i < tamanho; i++) {
        if (!isdigit(texto[i])) {
            return 0;
        }
    }
    return 1;
}

int validarCPF(char cpf[]) {
    return soDigitos(cpf, 11, 11);
}

int validarTelefone(char telefone[]) {
    return soDigitos(telefone, 10, 11);
}

int validarIdade(int idade) {
    return (idade >= 12 && idade <= 100);
}

void carregarDados() {
    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        totalAlunos = 0;
        return;
    }
    fread(&totalAlunos, sizeof(int), 1, arquivo);
    fread(nomes, sizeof(nomes), 1, arquivo);
    fread(cpfs, sizeof(cpfs), 1, arquivo);
    fread(telefones, sizeof(telefones), 1, arquivo);
    fread(idades, sizeof(idades), 1, arquivo);
    fread(planos, sizeof(planos), 1, arquivo);
    fread(mensalidades, sizeof(mensalidades), 1, arquivo);
    fread(pagos, sizeof(pagos), 1, arquivo);
    fclose(arquivo);
}

int salvarDados() {
    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("\nERRO: nao foi possivel abrir o arquivo %s\n", ARQUIVO);
        printf("Verifique se a pasta 'dados' existe.\n");
        return 0;
    }
    fwrite(&totalAlunos, sizeof(int), 1, arquivo);
    fwrite(nomes, sizeof(nomes), 1, arquivo);
    fwrite(cpfs, sizeof(cpfs), 1, arquivo);
    fwrite(telefones, sizeof(telefones), 1, arquivo);
    fwrite(idades, sizeof(idades), 1, arquivo);
    fwrite(planos, sizeof(planos), 1, arquivo);
    fwrite(mensalidades, sizeof(mensalidades), 1, arquivo);
    fwrite(pagos, sizeof(pagos), 1, arquivo);
    fclose(arquivo);
    return 1;
}

int buscarPorCpf(char cpf[]) {
    int i;
    for (i = 0; i < totalAlunos; i++) {
        if (strcmp(cpfs[i], cpf) == 0) {
            return i;
        }
    }
    return -1;
}

float valorDoPlano(int plano) {
    switch (plano) {
        case 1: return VALOR_BASICO;
        case 2: return VALOR_INTERMEDIARIO;
        default: return VALOR_PREMIUM;
    }
}

char *nomeDoPlano(int plano) {
    switch (plano) {
        case 1: return "Basico";
        case 2: return "Intermediario";
        default: return "Premium";
    }
}

char *nomeDaSituacao(int pago) {
    if (pago == 1) {
        return "Pago";
    }
    return "Pendente";
}

int escolherPlano() {
    int opcao;

    do {
        printf("Plano:\n");
        printf("  1 - Basico (R$ %.2f)\n", VALOR_BASICO);
        printf("  2 - Intermediario (R$ %.2f)\n", VALOR_INTERMEDIARIO);
        printf("  3 - Premium (R$ %.2f)\n", VALOR_PREMIUM);
        printf("Escolha: ");
        opcao = lerInteiro();
        if (opcao < 1 || opcao > 3) {
            printf("Plano invalido! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 3);

    return opcao;
}

void exibirAluno(int pos) {
    printf("----------------------------------\n");
    printf("Nome: %s\n", nomes[pos]);
    printf("CPF: %s\n", cpfs[pos]);
    printf("Telefone: %s\n", telefones[pos]);
    printf("Idade: %d\n", idades[pos]);
    printf("Plano: %s\n", nomeDoPlano(planos[pos]));
    printf("Mensalidade: R$ %.2f\n", mensalidades[pos]);
    printf("Situacao: %s\n", nomeDaSituacao(pagos[pos]));
}

int confirmar(char mensagem[]) {
    char resposta[10];

    printf("%s (S/N): ", mensagem);
    lerTexto(resposta, 10);
    return (toupper(resposta[0]) == 'S');
}

void cadastrarAluno() {
    int pos = totalAlunos;

    if (totalAlunos >= MAX_ALUNOS) {
        printf("\nLimite de alunos atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR ALUNO ---\n");

    do {
        printf("Nome: ");
        lerTexto(nomes[pos], 100);
        if (strlen(nomes[pos]) == 0) {
            printf("Nome invalido! O nome nao pode ficar vazio.\n");
        }
    } while (strlen(nomes[pos]) == 0);

    do {
        printf("CPF (11 numeros): ");
        lerTexto(cpfs[pos], 15);
        if (!validarCPF(cpfs[pos])) {
            printf("CPF invalido! Digite apenas 11 numeros.\n");
        }
    } while (!validarCPF(cpfs[pos]));

    if (buscarPorCpf(cpfs[pos]) != -1) {
        printf("\nERRO: ja existe um aluno com este CPF!\n");
        return;
    }

    do {
        printf("Telefone (DDD + numero): ");
        lerTexto(telefones[pos], 20);
        if (!validarTelefone(telefones[pos])) {
            printf("Telefone invalido! Digite 10 ou 11 numeros.\n");
        }
    } while (!validarTelefone(telefones[pos]));

    do {
        printf("Idade: ");
        idades[pos] = lerInteiro();
        if (!validarIdade(idades[pos])) {
            printf("Idade invalida! Digite um valor entre 12 e 100.\n");
        }
    } while (!validarIdade(idades[pos]));

    planos[pos] = escolherPlano();
    mensalidades[pos] = valorDoPlano(planos[pos]);
    pagos[pos] = 0;

    totalAlunos++;
    if (salvarDados()) {
        printf("\nAluno cadastrado com sucesso!\n");
    }
}
