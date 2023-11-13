#include <stdio.h>
#include "lab.h"

// Função principal que controla o menu do gerenciador de tarefas
int main() {
    struct Task tasks[100];  // Array para armazenar as tarefas
    int numTasks = 0;        // Número atual de tarefas cadastradas

    int opcao;
    do {
        // Exibe o menu principal
        printf("==(¬‿¬)== Gerenciador de Tarefas ==(¬‿¬)==\n");
        printf("1. Cadastrar Tarefa :)\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa :(\n");
        printf("0. Sair ;(\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Realiza ações com base na opção escolhida
        switch (opcao) {
            case 1:
                // Chama a função para cadastrar uma nova tarefa
                cadastrarTarefa(tasks, &numTasks);
                break;
            case 2:
                // Chama a função para listar as tarefas
                listarTarefas(tasks, numTasks);
                break;
            case 3: {
                // Solicita o índice da tarefa a ser deletada e chama a função correspondente
                int index;
                printf("Digite o índice da tarefa a ser deletada: ");
                scanf("%d", &index);
                deletarTarefa(tasks, &numTasks, index - 1);
                break;
            }
            case 0:
                // Exibe mensagem de encerramento
                printf("Encerrando o programa.\n");
                break;
            default:
                // Exibe mensagem de opção inválida
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);  // Continua o loop enquanto a opção não for 0 (Sair)

    return 0;  // Retorna 0 para indicar encerramento bem-sucedido
}
