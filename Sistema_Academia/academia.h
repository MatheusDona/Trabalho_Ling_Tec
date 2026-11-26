#ifndef ACADEMIA_H
#define ACADEMIA_H

#define MAX_ALUNOS 100
#define ARQUIVO "dados/alunos.dat"

#define VALOR_BASICO 80.00
#define VALOR_INTERMEDIARIO 100.00
#define VALOR_PREMIUM 130.00

/* Vetores paralelos: o aluno na posicao i tem seus dados na posicao i de cada vetor */
extern char nomes[MAX_ALUNOS][100];
extern char cpfs[MAX_ALUNOS][15];
extern char telefones[MAX_ALUNOS][20];
extern int idades[MAX_ALUNOS];
extern int planos[MAX_ALUNOS];          /* 1 = Basico, 2 = Intermediario, 3 = Premium */
extern float mensalidades[MAX_ALUNOS];
extern int pagos[MAX_ALUNOS];           /* 0 = Pendente, 1 = Pago */
extern int totalAlunos;

/* Funcoes auxiliares */
void limparBuffer();
void lerTexto(char texto[], int tamanho);
int lerInteiro();

/* Validacoes */
int validarCPF(char cpf[]);
int validarTelefone(char telefone[]);
int validarIdade(int idade);

/* Arquivo */
void carregarDados();
int salvarDados();

/* Apoio */
int buscarPorCpf(char cpf[]);
float valorDoPlano(int plano);
char *nomeDoPlano(int plano);
char *nomeDaSituacao(int pago);
int escolherPlano();
void exibirAluno(int pos);
int confirmar(char mensagem[]);

/* Funcionalidades do menu */
void cadastrarAluno();
void listarAlunos();
void buscarAluno();
void alterarCadastro();
void excluirAluno();
void registrarPagamento();
void listarPendentes();
void iniciarNovoMes();
void relatorioAcademia();

#endif
