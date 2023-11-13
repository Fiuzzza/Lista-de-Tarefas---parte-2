#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

// Declaração da estrutura Task e variável numTasks
struct Task tasks[100];
int numTasks = 0;

// Função para cadastrar uma nova tarefa
void cadastrarTarefa(struct Task tasks[], int *numTasks) {
    // Verifica se a lista de tarefas está cheia
    if (*numTasks >= 100) {
        printf("A lista de tarefas está cheia. Não é possível adicionar mais tarefas.\n");
        return;
    }

    // Cria uma nova tarefa
    struct Task newTask;
    printf("Digite a prioridade da sua tarefa (0 a 10): ");
    scanf("%d", &newTask.priority);

    printf("Digite a descrição da sua tarefa (até 300 caracteres): ");
    getchar();
    fgets(newTask.description, sizeof(newTask.description), stdin);

    printf("Digite a categoria da sua tarefa (até 100 caracteres): ");
    fgets(newTask.category, sizeof(newTask.category), stdin);

    printf("Digite o estado da sua tarefa (completo, em andamento, não iniciado): ");
    fgets(newTask.state, sizeof(newTask.state), stdin);

    // Adiciona a nova tarefa à lista
    tasks[*numTasks] = newTask;
    (*numTasks)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

// Função para listar todas as tarefas
void listarTarefas(struct Task tasks[], int numTasks) {
    // Verifica se não há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    // Lista todas as tarefas
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

// Função para deletar uma tarefa
void deletarTarefa(struct Task tasks[], int *numTasks, int index) {
    // Verifica se o índice é válido
    if (index < 0 || index >= *numTasks) {
        printf("Índice inválido.\n");
        return;
    }

    // Move as tarefas para preencher o espaço da tarefa deletada
    for (int i = index; i < *numTasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    // Atualiza o número de tarefas
    (*numTasks)--;
    printf("Tarefa deletada com sucesso! :)\n");
}

// Função para alterar uma tarefa
void alterarTarefa(struct Task tasks[], int numTasks) {
    // Verifica se não há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    int index;
    printf("Digite o índice da tarefa a ser alterada: ");
    scanf("%d", &index);

    // Verifica se o índice é válido
    if (index < 1 || index > numTasks) {
        printf("Índice inválido.\n");
        return;
    }

    // Obtém a tarefa a ser alterada
    struct Task *task = &tasks[index - 1];

    // Apresenta opções de campos a serem alterados
    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Descrição\n");
    printf("3. Categoria\n");
    printf("4. Estado\n");
    printf("Escolha uma opção: ");

    int opcao;
    scanf("%d", &opcao);

    // Switch para tratar cada opção
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

// Função para filtrar tarefas por prioridade
void filtrarTarefasPorPrioridade(struct Task tasks[], int numTasks) {
    // Verifica se não há tarefas cadastradas
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

// Função para filtrar tarefas por estado
void filtrarTarefasPorEstado(struct Task tasks[], int numTasks) {
    // Verifica se não há tarefas cadastradas
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

void filtrarTarefasPorPrioridadeECategoria(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    char categoriaFiltro[100];
    printf("Digite a categoria desejada: ");
    getchar();
    fgets(categoriaFiltro, sizeof(categoriaFiltro), stdin);

    int prioridadeFiltro;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridadeFiltro);

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

    printf("Tarefas na categoria %s e prioridade %d (ordenadas por prioridade da maior para a menor):\n", categoriaFiltro, prioridadeFiltro);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoriaFiltro) == 0 && tasks[i].priority == prioridadeFiltro) {
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
        printf("Nenhuma tarefa encontrada na categoria %s e prioridade %d.\n", categoriaFiltro, prioridadeFiltro);
    }
}

void exportarTarefasPorPrioridade(struct Task tasks[], int numTasks) {
    // Verificar se há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    // Variáveis para armazenar a prioridade e o nome do arquivo fornecidos pelo usuário
    int prioridadeFiltro;
    char nomeArquivo[50];

    // Solicitar ao usuário a prioridade desejada para exportar
    printf("Digite a prioridade desejada para exportar: ");
    scanf("%d", &prioridadeFiltro);

    // Limpar o buffer de entrada para evitar problemas com fgets
    getchar();

    // Solicitar ao usuário o nome do arquivo para exportar
    printf("Digite o nome do arquivo para exportar: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);

    // Remover a quebra de linha do final da string inserida pelo usuário
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;

    // Abrir o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    // Flag para verificar se alguma tarefa foi encontrada
    int encontrouTarefa = 0;

    // Iterar sobre as tarefas para encontrar aquelas que correspondem ao critério de prioridade
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridadeFiltro) {
            // Escrever os detalhes da tarefa no arquivo
            fprintf(arquivo, "%d, %s, %s, %s\n", tasks[i].priority, tasks[i].category, tasks[i].state, tasks[i].description);
            encontrouTarefa = 1;
        }
    }

    // Fechar o arquivo após a operação
    fclose(arquivo);

    // Exibir mensagem ao usuário com base na existência ou não de tarefas encontradas
    if (encontrouTarefa) {
        printf("Tarefas com prioridade %d exportadas para o arquivo %s com sucesso!\n", prioridadeFiltro, nomeArquivo);
    } else {
        printf("Nenhuma tarefa encontrada com prioridade %d para exportar.\n", prioridadeFiltro);
    }
}

void exportarTarefasPorCategoria(struct Task tasks[], int numTasks) {
    // Verificar se há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    // Variáveis para armazenar a categoria e o nome do arquivo fornecidos pelo usuário
    char categoriaFiltro[100];
    char nomeArquivo[50];

    // Solicitar ao usuário a categoria desejada para exportar
    printf("Digite a categoria desejada para exportar: ");
    getchar();
    fgets(categoriaFiltro, sizeof(categoriaFiltro), stdin);

    // Solicitar ao usuário o nome do arquivo para exportar
    printf("Digite o nome do arquivo para exportar: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);

    // Remover a quebra de linha do final da string inserida pelo usuário
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;
    categoriaFiltro[strcspn(categoriaFiltro, "\n")] = 0;

    // Abrir o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

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

    // Flag para verificar se alguma tarefa foi encontrada
    int encontrouTarefa = 0;

    // Escrever cabeçalho no arquivo
    fprintf(arquivo, "Prioridade, Categoria, Estado, Descrição\n");

    // Iterar sobre as tarefas para encontrar aquelas que correspondem ao critério de categoria
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].category, categoriaFiltro) == 0) {
            // Escrever os detalhes da tarefa no arquivo
            fprintf(arquivo, "%d, %s, %s, %s\n", tasks[i].priority, tasks[i].category, tasks[i].state, tasks[i].description);
            encontrouTarefa = 1;
        }
    }

    // Fechar o arquivo após a operação
    fclose(arquivo);

    // Exibir mensagem ao usuário com base na existência ou não de tarefas encontradas
    if (encontrouTarefa) {
        printf("Tarefas na categoria %s exportadas para o arquivo %s com sucesso!\n", categoriaFiltro, nomeArquivo);
    } else {
        printf("Nenhuma tarefa encontrada na categoria %s para exportar.\n", categoriaFiltro);
    }
}

void exportarTarefasPorPrioridadeECategoria(struct Task tasks[], int numTasks) {
    // Verificar se há tarefas cadastradas
    if (numTasks == 0) {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    // Variáveis para armazenar a prioridade, categoria e nome do arquivo fornecidos pelo usuário
    int prioridadeFiltro;
    char categoriaFiltro[100];

    // Solicitar ao usuário a prioridade desejada para exportar
    printf("Digite a prioridade desejada para exportar: ");
    scanf("%d", &prioridadeFiltro);

    // Limpar o buffer de entrada para evitar problemas com fgets
    getchar();

    // Solicitar ao usuário a categoria desejada para exportar
    printf("Digite a categoria desejada para exportar: ");
    fgets(categoriaFiltro, sizeof(categoriaFiltro), stdin);

    // Remover a quebra de linha do final da string inserida pelo usuário
    categoriaFiltro[strcspn(categoriaFiltro, "\n")] = 0;

    // Variável para armazenar o nome do arquivo fornecido pelo usuário
    char nomeArquivo[50];
    printf("Digite o nome do arquivo para exportar: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);

    // Remover a quebra de linha do final da string inserida pelo usuário
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;

    // Abrir o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    // Flag para verificar se alguma tarefa foi encontrada
    int encontrouTarefa = 0;

    // Escrever cabeçalho no arquivo
    fprintf(arquivo, "Prioridade, Categoria, Estado, Descrição\n");

    // Iterar sobre as tarefas para encontrar aquelas que correspondem aos critérios de prioridade e categoria
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == prioridadeFiltro && strcmp(tasks[i].category, categoriaFiltro) == 0) {
            // Escrever os detalhes da tarefa no arquivo
            fprintf(arquivo, "%d, %s, %s, %s\n", tasks[i].priority, tasks[i].category, tasks[i].state, tasks[i].description);
            encontrouTarefa = 1;
        }
    }

    // Fechar o arquivo após a operação
    fclose(arquivo);

    // Exibir mensagem ao usuário com base na existência ou não de tarefas encontradas
    if (encontrouTarefa) {
        printf("Tarefas com prioridade %d e na categoria %s exportadas para o arquivo %s com sucesso!\n", prioridadeFiltro, categoriaFiltro, nomeArquivo);
    } else {
        printf("Nenhuma tarefa encontrada com prioridade %d e na categoria %s para exportar.\n", prioridadeFiltro, categoriaFiltro);
    }
}

// O restante do código permanece inalterado.


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
        printf("8. Filtrar Tarefas por Prioridade e Categoria\n");
        printf("9. Exportar Tarefas por Prioridade\n");
        printf("10. Exportar Tarefas por Categoria\n");
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
            case 8:
                filtrarTarefasPorPrioridadeECategoria(tasks, numTasks);
                break;
            case 9:
                exportarTarefasPorPrioridade(tasks, numTasks);
                break;
            case 10:
                exportarTarefasPorCategoria(tasks, numTasks);
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