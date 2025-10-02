#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char* songName) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, songName);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addSong(struct Node** head,struct Node** tail,char* songName) {
    struct Node* newnode = createNode(songName);

    if(*head == NULL){
        *head = newnode;
        *tail = newnode;
    }else{
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

struct Node* playNext(struct Node* curr) {
    if (curr->next != NULL) {
        curr = curr->next;
        printf("Playing Next Song: %s\n", curr->song);
    } else {
        printf("End of Playlist.\n");
    }
    return curr;
}

struct Node* playPrev(struct Node* curr) {
    if (curr->prev != NULL) {
        curr = curr->prev;
        printf("Playing Previous Song: %s\n", curr->song);
    } else {
        printf("Start of Playlist.\n");
    }
    return curr;
}

int main() {
    struct Node* playlist = NULL;
    struct Node* tail = NULL;

    addSong(&playlist,&tail, "Song 1");
    addSong(&playlist,&tail, "Song 2");
    addSong(&playlist,&tail, "Song 3");
    addSong(&playlist,&tail, "Song 4");
    addSong(&playlist,&tail, "Song 5");

    struct Node* curr = playlist;
    printf("Currently Playing: %s\n", curr->song);

    curr = playNext(curr);  
    curr = playNext(curr);    
    curr = playNext(curr);  
    curr = playPrev(curr);
    curr = playNext(curr);  
    curr = playNext(curr);  
    curr = playNext(curr);  


}
