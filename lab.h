#ifndef LAB_H
#define LAB_H

struct Task {
    int priority;
    char description[300];
    char category[100];
    char state[20]; 
};

void cadastrarTarefa(struct Task tasks[], int *numTasks);
void listarTarefas(struct Task tasks[], int numTasks);
void deletarTarefa(struct Task tasks[], int *numTasks, int index);
void alterarTarefa(struct Task tasks[], int numTasks);
void filtrarTarefasPorPrioridade(struct Task tasks[], int numTasks);
void filtrarTarefasPorEstado(struct Task tasks[], int numTasks);
void filtrarTarefasPorCategoria(struct Task tasks[], int numTasks);

#endif
