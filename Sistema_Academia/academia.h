#ifndef ACADEMIA_H
#define ACADEMIA_H

#define MAX_ALUNOS 100
#define ARQUIVO "dados/alunos.dat"

#define VALOR_BASICO 80.00
#define VALOR_INTERMEDIARIO 100.00
#define VALOR_PREMIUM 130.00


extern char nomes[MAX_ALUNOS][100];
extern char cpfs[MAX_ALUNOS][15];
extern char telefones[MAX_ALUNOS][20];
extern int idades[MAX_ALUNOS];
extern int planos[MAX_ALUNOS];          
extern float mensalidades[MAX_ALUNOS];
extern int pagos[MAX_ALUNOS];           
extern int totalAlunos;


void limparBuffer();
void lerTexto(char texto[], int tamanho);
int lerInteiro();


int validarCPF(char cpf[]);
int validarTelefone(char telefone[]);
int validarIdade(int idade);


void carregarDados();
int salvarDados();


int buscarPorCpf(char cpf[]);
float valorDoPlano(int plano);
char *nomeDoPlano(int plano);
char *nomeDaSituacao(int pago);
int escolherPlano();
void exibirAluno(int pos);
int confirmar(char mensagem[]);


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
