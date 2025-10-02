#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][20]; 
int top = -1;

void push(char tag[]) {
    strcpy(stack[++top], tag);
}

char* pop() {
    if(top == -1) return NULL;
    return stack[top--];
}

int isValidHTML(char str[]) {
    char tag[20];
    int i=0, j;

    while(str[i] != '\0') {
        if(str[i] == '<') {
            i++;
            int closing = 0;
            if(str[i] == '/') { 
                closing = 1;
                i++;
            }

            j = 0;
            while(str[i] != '>' && str[i] != '\0') {
                tag[j++] = str[i++];
            }
            tag[j] = '\0';

            if(closing) {
                char *topTag = pop();
                if(topTag == NULL || strcmp(topTag, tag) != 0)
                    return 0; 
            } else {
                push(tag);
            }
        }
        i++;
    }

    return (top == -1);
}

int main() {
    char str1[] = "<html><body><h1>Title</h1></body></html>";
    char str2[] = "<html><body></html></body>";

    printf("Str1 valid? %s\n", isValidHTML(str1) ? "Yes" : "No");
    printf("Str2 valid? %s\n", isValidHTML(str2) ? "Yes" : "No");

    return 0;
}
