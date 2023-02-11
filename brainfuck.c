#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
    int memory_size = 30000;
    char *memory = calloc(memory_size, sizeof(char));
    int cell = 0;
    char ptr;

    if(argc == 1) {
        printf("No file input was detected. \nTerminating...\n");
        exit(EXIT_FAILURE);
    }

    FILE * file; 
    char ch;

    file = fopen(argv[1], "rb");

    if(file == NULL) {
        printf("File doesn't exist or couldn't be opened.");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long code_size = ftell(file);
    rewind(file);
    char *code = malloc(code_size);

    for(int i = 0; i < code_size; i++) {
        code[i] = fgetc(file);
    }

    for(int i = 0; i < code_size; i++) {
        int ptr;
        if(cell == -1) {
            cell = memory_size-1;
        }
        if(cell == memory_size) {
            cell = 0;
        }
        switch(code[i]) {
        case ',': {
            char input = getchar();
            memory[cell] = input;
            break;
        }
        case '.':
            printf("%c", memory[cell]);
            break;
        case '+': 
            memory[cell]++;
            break;
        case '-':
            memory[cell]--;
            break;
        case '>':
            cell++;
            break;
        case '<':
            cell--;
            break;
        case '[':
            ptr = i;
            break;
        case ']':
            if(memory[cell] != 0) {
                i = ptr;
            }
            break;
        }
    }
    fclose(file);
    free(code);
    free(memory);
    return 0;
}
