#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

struct Task tasks[100];
int numTasks = 0;

void cadastrarTarefa(struct Task tasks[], int *numTasks) {
    struct Task newTask;
    
    if (*numTasks >= 100) {
        printf("A lista de tarefas está cheia. Não é possível adicionar mais tarefas.\n");
        return;
    }

    printf("Digite a prioridade da sua tarefa (0 a 10): ");
    scanf("%d", &newTask.priority);

    printf("Digite a descrição da sua tarefa (até 300 caracteres): ");
    getchar();
    fgets(newTask.description, sizeof(newTask.description), stdin);

    printf("Digite a categoria da sua tarefa (até 100 caracteres): ");
    fgets(newTask.category, sizeof(newTask.category), stdin);

    printf("Digite o estado da sua tarefa (completo/em andamento/não iniciado): ");
    fgets(newTask.state, sizeof(newTask.state), stdin);

    tasks[*numTasks] = newTask;
    (*numTasks)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    printf("Lista de tarefas:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tasks[i].priority);
        printf("Descrição: %s", tasks[i].description);
        printf("Categoria: %s", tasks[i].category);
        printf("Estado: %s", tasks[i].state);
        printf("--------------------\n");
    }
}

void deletarTarefa(struct Task tasks[], int *numTasks, int index) {
    if (index < 0 || index >= *numTasks) {
        printf("Índice inválido.\n");
        return;
    }

    for (int i = index; i < *numTasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*numTasks)--;
    printf("Tarefa deletada com sucesso! :)\n");
}

void alterarTarefa(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    int index;
    printf("Digite o índice da tarefa a ser alterada: ");
    scanf("%d", &index);

    if (index < 1 || index > numTasks) {
        printf("Índice inválido.\n");
        return;
    }

    struct Task *task = &tasks[index - 1];

    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Descrição\n");
    printf("3. Categoria\n");
    printf("4. Estado\n");
    printf("Escolha uma opção: ");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a nova prioridade: ");
            scanf("%d", &task->priority);
            break;
        case 2:
            printf("Digite a nova descrição: ");
            getchar(); // Consumir o caractere de nova linha residual
            fgets(task->description, sizeof(task->description), stdin);
            break;
        case 3:
            printf("Digite a nova categoria: ");
            getchar();
            fgets(task->category, sizeof(task->category), stdin);
            break;
        case 4:
            printf("Digite o novo estado (completo/em andamento/não iniciado): ");
            getchar();
            fgets(task->state, sizeof(task->state), stdin);
            break;
        default:
            printf("Opção inválida.\n");
            return;
    }

    printf("Tarefa alterada com sucesso!\n");
}

void filtrarTarefasPorPrioridade(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    int prioridadeFiltro;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridadeFiltro);

    int encontrouTarefa = 0;

    printf("Tarefas com prioridade %d:\n", prioridadeFiltro);
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridadeFiltro) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tasks[i].priority);
            printf("Descrição: %s", tasks[i].description);
            printf("Categoria: %s", tasks[i].category);
            printf("Estado: %s", tasks[i].state);
            printf("--------------------\n");
            encontrouTarefa = 1;
        }
    }

    if (!encontrouTarefa) {
        printf("Nenhuma tarefa encontrada com prioridade %d.\n", prioridadeFiltro);
    }
}

void filtrarTarefasPorEstado(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    char estadoFiltro[20];
    printf("Digite o estado desejado (completo/em andamento/não iniciado): ");
    getchar();
    fgets(estadoFiltro, sizeof(estadoFiltro), stdin);

    int encontrouTarefa = 0;

    printf("Tarefas com estado %s:\n", estadoFiltro);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].state, estadoFiltro) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tasks[i].priority);
            printf("Descrição: %s", tasks[i].description);
            printf("Categoria: %s", tasks[i].category);
            printf("Estado: %s", tasks[i].state);
            printf("--------------------\n");
            encontrouTarefa = 1;
        }
    }

    if (!encontrouTarefa) {
        printf("Nenhuma tarefa encontrada com estado %s.\n", estadoFiltro);
    }
}

void filtrarTarefasPorCategoria(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    char categoriaFiltro[100];
    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoriaFiltro, sizeof(categoriaFiltro), stdin);

    // Ordenar as tarefas por prioridade da maior para a menor
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                // Troca as tarefas de lugar se a prioridade for menor
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    int encontrouTarefa = 0;

    printf("Tarefas na categoria %s (ordenadas por prioridade da maior para a menor):\n", categoriaFiltro);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoriaFiltro) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tasks[i].priority);
            printf("Descrição: %s", tasks[i].description);
            printf("Categoria: %s", tasks[i].category);
            printf("Estado: %s", tasks[i].state);
            printf("--------------------\n");
            encontrouTarefa = 1;
        }
    }

    if (!encontrouTarefa) {
        printf("Nenhuma tarefa encontrada na categoria %s.\n", categoriaFiltro);
    }
}

int main() {
    int opcao;
    do {
        printf("==(¬‿¬)== Gerenciador de Tarefas ==(¬‿¬)==\n");
        printf("1. Cadastrar Tarefa :)\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa :(\n");
        printf("4. Alterar Tarefa\n");
        printf("5. Filtrar Tarefas por Prioridade\n");
        printf("6. Filtrar Tarefas por Estado\n");
        printf("7. Filtrar Tarefas por Categoria\n");
        printf("0. Sair ;(\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tasks, &numTasks);
                break;
            case 2:
                listarTarefas(tasks, numTasks);
                break;
            case 3: {
                int index;
                printf("Digite o índice da tarefa a ser deletada: ");
                scanf("%d", &index);
                deletarTarefa(tasks, &numTasks, index - 1);
                break;
            }
            case 4:
                alterarTarefa(tasks, numTasks);
                break;
            case 5:
                filtrarTarefasPorPrioridade(tasks, numTasks);
                break;
            case 6:
                filtrarTarefasPorEstado(tasks, numTasks);
                break;
            case 7:
                filtrarTarefasPorCategoria(tasks, numTasks);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        
        while (getchar() != '\n');
        
    } while (opcao != 0);

    return 0;
}