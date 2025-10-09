#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxTasks(int* tasks, int n, int* workers, int m, int pills, int pillStrength) {
    qsort(tasks, n, sizeof(int), cmp);
    qsort(workers, m, sizeof(int), cmp);

    int* queue = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        queue[i] = workers[i];

    int front = 0;
    int rear = m;
    int completed = 0;

    for (int i = 0; i < n; i++) {
        int assigned = 0;

        while (front < rear) {
            if (queue[front] >= tasks[i]) {
                completed++;
                front++;
                assigned = 1;
                break;
            } else if (pills > 0 && queue[front] + pillStrength >= tasks[i]) {
                completed++;
                pills--;
                front++;
                assigned = 1;
                break;
            } else {
                front++;
            }
        }

        if (!assigned) break;
    }

    free(queue);
    return completed;
}

int main() {
    int tasks[] = {3, 2, 1};
    int workers[] = {0, 3, 3};
    int n = sizeof(tasks)/sizeof(tasks[0]);
    int m = sizeof(workers)/sizeof(workers[0]);
    int pills = 1;
    int pillStrength = 1;

    int result = maxTasks(tasks, n, workers, m, pills, pillStrength);
    printf("Maximum tasks completed: %d\n", result);

    return 0;
}
