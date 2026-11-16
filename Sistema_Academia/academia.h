#ifndef ACADEMIA_H
#define ACADEMIA_H

#define ARQUIVO_ALUNOS "dados/alunos.dat"

typedef struct {
    char nome[100];
    int idade;
    char cpf[15];
    char telefone[20];
    char plano[30];
    float valorMensalidade;
    char situacao[15];
} Aluno;


void lerTexto(const char mensagem[], char destino[], int tamanho);
int lerInteiro(const char mensagem[]);
int lerInteiroPositivo(const char mensagem[]);


void cadastrarAluno(void);
void listarAlunos(void);
void buscarAluno(void);
void alterarAluno(void);
void excluirAluno(void);
void registrarPagamento(void);
void listarPendentes(void);
void iniciarNovoMes(void);
void gerarRelatorio(void);

#endif
