#include <stdio.h>
#include <stdbool.h>

struct Event {
    int id;
    int start;
    int duration;
    int waiting;
    bool done;
};

int main() {
    int n;
    printf("Enter number of events: ");
    scanf("%d", &n);

    struct Event e[n];

    printf("Enter event id, start time, duration:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &e[i].id, &e[i].start, &e[i].duration);
        e[i].done = false;
        e[i].waiting = 0;
    }

    int completed = 0;
    int currentTime = 0;
    int totalWaiting = 0;

    printf("\nExecution Order:\n");

    while (completed < n) {

        int idx = -1;
        int minDuration = 1e9;

        for (int i = 0; i < n; i++) {
            if (!e[i].done && e[i].start <= currentTime) {
                if (e[i].duration < minDuration) {
                    minDuration = e[i].duration;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            currentTime++;
            continue;
        }

        e[idx].waiting = currentTime - e[idx].start;
        totalWaiting += e[idx].waiting;

        printf("Event %d | Waiting Time: %d\n",
               e[idx].id, e[idx].waiting);

        currentTime += e[idx].duration;
        e[idx].done = true;
        completed++;
    }

    printf("\nAverage Waiting Time: %.2f\n",
           (float)totalWaiting / n);

    return 0;
}
