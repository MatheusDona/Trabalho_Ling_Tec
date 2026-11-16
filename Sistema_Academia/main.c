#include <stdio.h>
#include <stdlib.h>
#include "academia.h"

int main(void) {
    int opcao;

    do {
        printf("\n========== ACADEMIA ==========\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("4 - Alterar cadastro\n");
        printf("5 - Excluir aluno\n");
        printf("6 - Registrar pagamento\n");
        printf("7 - Listar pendentes\n");
        printf("8 - Iniciar novo mes\n");
        printf("9 - Relatorio da academia\n");
        printf("0 - Sair\n");
        printf("==============================\n");

        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1: cadastrarAluno(); break;
            case 2: listarAlunos(); break;
            case 3: buscarAluno(); break;
            case 4: alterarAluno(); break;
            case 5: excluirAluno(); break;
            case 6: registrarPagamento(); break;
            case 7: listarPendentes(); break;
            case 8: iniciarNovoMes(); break;
            case 9: gerarRelatorio(); break;
            case 0: printf("\nSistema encerrado.\n"); break;
            default: printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
