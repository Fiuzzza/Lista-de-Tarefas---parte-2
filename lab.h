#ifndef LAB_H
#define LAB_H

struct Task {
    int priority;                   // Prioridade da tarefa (de 0 a 10)
    char description[300];          // Descrição da tarefa (até 300 caracteres)
    char category[100];             // Categoria da tarefa (até 100 caracteres)
    char state[20];                 // Estado da tarefa (completo, em andamento, não iniciado)
};

// Função para cadastrar uma nova tarefa
void cadastrarTarefa(struct Task tasks[], int *numTasks);

// Função para listar as tarefas cadastradas
void listarTarefas(struct Task tasks[], int numTasks);

// Função para deletar uma tarefa pelo índice
void deletarTarefa(struct Task tasks[], int *numTasks, int index);

// Função para alterar os detalhes de uma tarefa
void alterarTarefa(struct Task tasks[], int numTasks);

// Função para filtrar tarefas por prioridade
void filtrarTarefasPorPrioridade(struct Task tasks[], int numTasks);

// Função para filtrar tarefas por estado
void filtrarTarefasPorEstado(struct Task tasks[], int numTasks);

// Função para filtrar tarefas por categoria
void filtrarTarefasPorCategoria(struct Task tasks[], int numTasks);

// Função para filtrar tarefas por prioridade e categoria
void filtrarTarefasPorPrioridadeECategoria(struct Task tasks[], int numTasks);

// Função para exportar tarefas por prioridade para um arquivo
void exportarTarefasPorPrioridade(struct Task tasks[], int numTasks);

// Função para exportar tarefas por categoria para um arquivo
void exportarTarefasPorCategoria(struct Task tasks[], int numTasks);

// Função para exportar tarefas por prioridade e categoria para um arquivo
void exportarTarefasPorPrioridadeECategoria(struct Task tasks[], int numTasks);

#endif
