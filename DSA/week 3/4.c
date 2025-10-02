#include <stdio.h>
#include <string.h>

#define N 100
#define L 100

char back[N][L], fwd[N][L];
int bt = -1, ft = -1;

void push(char s[][L], int *t, const char *url) {
    if (*t < N - 1) 
    strcpy(s[++(*t)], url);
}

char* pop(char s[][L], int *t) {
    if (*t >= 0) 
    return s[(*t)--];
}

int main() {
    char cur[L] = "homepage.com";
    int c;

    printf("Current: %s\n", cur);

    while (1) {
        printf("\n(1.new 2.b=back 3.forward, q=quit): ");
        scanf(" %c", &c);

        switch (c) {
            case 'n':
                ft = -1;
                push(back, &bt, cur);
                printf("Enter URL: ");
                scanf("%s", cur);
                printf("Current: %s\n", cur);
                break;

            case 'b':
                if (bt >= 0) {
                    push(fwd, &ft, cur);
                    strcpy(cur, pop(back, &bt));
                    printf("Current: %s\n", cur);
                } else printf("No back!\n");
                break;

            case 'f':
                if (ft >= 0) {
                    push(back, &bt, cur);
                    strcpy(cur, pop(fwd, &ft));
                    printf("Current: %s\n", cur);
                } else printf("No fwd!\n");
                break;

            case 'q':
                return 0;
        }
    }
}
