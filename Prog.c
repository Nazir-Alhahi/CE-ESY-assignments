#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;   
    int size;       
    int head;       
    int tail;       
    int count;      
} CircularBuffer;


void init(CircularBuffer *cb, int size) {
    cb->buffer = (char *)malloc(size * sizeof(char));
    cb->size = size;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == cb->size;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow: cannot write '%c'\n", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % cb->size; 
    cb->count++;
}

int read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return EOF;
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % cb->size; 
    cb->count--;
    return data;
}

void destroy(CircularBuffer *cb) {
    free(cb->buffer);
    cb->buffer = NULL;
}

int main() {
    char name[100];
    char suffix_offset[] = "CE-ESY";
    int buffer_size;
    char choice;


    do {
        printf("Please enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; 
        
        char *full_name = malloc(strlen(name) + strlen(suffix_offset) + 1);
        strcpy(full_name, name);
        strcat(full_name, suffix_offset);
        printf("Full text to store: \"%s\" (length: %zu characters)\n", full_name, strlen(full_name));

        printf("Enter buffer size: ");
        scanf("%d", &buffer_size);
        getchar(); 

        CircularBuffer cb;
        init(&cb, buffer_size);

        
        printf("\n--- Writing to buffer ---\n");
        for (int i = 0; full_name[i] != '\0'; i++) {
            write(&cb, full_name[i]);
        }

        printf("\n--- Reading from buffer ---\n");
        printf("Retrieved data: ");
        while (!isEmpty(&cb)) {
            int ch = read(&cb);
            if (ch != EOF) {
                printf("%c", ch);
            }
        }
        printf("\n");

        
        if (isEmpty(&cb)) {
            printf("Buffer emptied successfully.\n");
        }

        
        free(full_name);
        destroy(&cb);

        
        printf("\nWould you like to try another buffer size? (y/n): ");
        scanf(" %c", &choice);
        getchar(); 

    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");
    return 0;
}
