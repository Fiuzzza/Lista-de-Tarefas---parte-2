#ifndef LAB_H
#define LAB_H

struct Task {
    int priority;
    char description[300];
    char category[100];
};

void cadastrarTarefa(struct Task tasks[], int *numTasks);
void listarTarefas(struct Task tasks[], int numTasks);
void deletarTarefa(struct Task tasks[], int *numTasks, int index);

#endif
