#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1, *f2, *f3, *out;
    int numbers[100];  
    int count = 0;     

    f1 = fopen("file1.txt", "r");
    while (fscanf(f1, "%d", &numbers[count]) == 1) {
        count++;
    }
    fclose(f1);

    f2 = fopen("file2.txt", "r");
    while (fscanf(f2, "%d", &numbers[count]) == 1) {
        count++;
    }
    fclose(f2);

    
    f3 = fopen("file3.txt", "r");
    while (fscanf(f3, "%d", &numbers[count]) == 1) {
        count++;
    }
    fclose(f3);

    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    
    out = fopen("output.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(out, "%d ", numbers[i]);
    }
    fclose(out);

    printf("Numbers are sorted.\n");

    return 0;
}