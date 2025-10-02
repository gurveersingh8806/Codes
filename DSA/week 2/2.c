#include <stdio.h>
#include <string.h>

struct Contact {
    char name[100];
    long long mobile;
} contacts[10];

int n = 0;

void printContacts() {
    if (n == 0) {
        printf("No contacts.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d. %s - %lld\n", i + 1, contacts[i].name, contacts[i].mobile);
}

void sortContacts() {
    for (int i = 1; i < n; i++) {
        struct Contact key = contacts[i];
        int j = i - 1;
        while (j >= 0 && strcmp(contacts[j].name, key.name) > 0) {
            contacts[j + 1] = contacts[j];
            j--;
        }
        contacts[j + 1] = key;
    }
    printf("Contacts sorted by name.\n");
}

void insertContact(int pos, char *name, long long mobile) {
    if (n >= 10) {
        printf("List full.\n");
        return;
    }
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = n; i >= pos; i--)
        contacts[i] = contacts[i - 1];
    strcpy(contacts[pos - 1].name, name);
    contacts[pos - 1].mobile = mobile;
    n++;
    printf("Contact inserted.\n");
}

void deleteContact(int pos) {
    if (n == 0) {
        printf("List empty.\n");
        return;
    }
    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
        contacts[i] = contacts[i + 1];
    n--;
    printf("Contact deleted.\n");
}

int main() {
    printf("How many contacts (max 10)? ");
    scanf("%d", &n);
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf(" %[^\n]", contacts[i].name);
        printf("Enter mobile: ");
        scanf("%lld", &contacts[i].mobile);
    }

    int choice, pos;
    char name[100];
    long long mobile;

    do {
        printf("\n1.Insert  2.Delete  3.Print  4.Sort  5.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Position: "); scanf("%d", &pos);
                printf("Name: "); scanf(" %[^\n]", name);
                printf("Mobile: "); scanf("%lld", &mobile);
                insertContact(pos, name, mobile);
                break;
            case 2:
                printf("Position: "); scanf("%d", &pos);
                deleteContact(pos);
                break;
            case 3: printContacts(); break;
            case 4: sortContacts(); printContacts(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
