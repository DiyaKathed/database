#include <stdio.h>
#include <string.h>

#define size 5
#define MAX_LENGTH 100 // Maximum length for each song name

char queue[size][MAX_LENGTH];
int front = -1, rear = -1;

// Enqueue = add new song
void enqueue(char song[]) {
    if ((rear + 1) % size == front) {
        printf("Playlist is full\n");
    } else if (rear == -1 && front == -1) {
        front = 0, rear = 0;
        strcpy(queue[rear], song);
    } else {
        rear = (rear + 1) % size;
        strcpy(queue[rear], song);
    }
}

// Dequeue = delete song
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Playlist is empty\n");
    } else if (front == rear) {
        printf("Song \"%s\" is deleted\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Song \"%s\" is deleted\n", queue[front]);
        front = (front + 1) % size;
    }
}

// Display current song
void current() {
    if (front == -1) {
        printf("No song is playing currently.\n");
    } else {
        printf("Current song is: \"%s\"\n", queue[front]);
    }
}

// Next song operation
void next() {
    front = (front + 1) % size;
    printf("Next song is \"%s\"\n", queue[front]);
}

// Display all songs in the playlist
void display() {
    if (front == -1 && rear == -1) {
        printf("Playlist is empty\n");
    } else {
        printf("Songs playlist is: ");
        int i = front;
        while (1) {
            printf("\"%s\" ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;
    char song[MAX_LENGTH];

    while (1) {
        printf("\nSong queue menu.\n");
        printf("1. Add a song\n2. Delete a song\n3. Display song queue\n4. Current song\n5. Next song\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline left in the buffer

        switch (choice) {
            case 1:
                {
                    printf("Enter song to insert (up to 100 characters): ");
                    fgets(song, MAX_LENGTH, stdin);  // Reads input from user, including spaces
                    song[strcspn(song, "\n")] = 0;  // Remove the newline character
                    enqueue(song);
                    break;
                }
            case 2:
                {
                    dequeue();
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            case 4:
                {
                    current();
                    break;
                }
            case 5:
                { 
                    next();
                    break;
                }
            case 6:
                {
                    return 0;
                }
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

