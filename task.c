#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// Function to read the mapping file and store it in a 2D array
int read_mapping_file(char mapping[][2][MAX_COMMAND_LENGTH]) {
    FILE *file = fopen("mapping.txt", "r");
    if (file == NULL) {
        printf("Error opening mapping file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %s", mapping[count][0], mapping[count][1]) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to map DOS command to Linux command
char* map_command(char mapping[][2][MAX_COMMAND_LENGTH], int mapping_size, char *dos_command) {
    for (int i = 0; i < mapping_size; i++) {
        if (strcmp(mapping[i][0], dos_command) == 0) {
            return mapping[i][1];
        }
    }
    return NULL;
}

int main() {
    char mapping[50][2][MAX_COMMAND_LENGTH];
    int mapping_size = read_mapping_file(mapping);

    if (mapping_size == 0) {
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];

    printf("DOS Shell\n");
    printf("Enter 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        char *linux_command = map_command(mapping, mapping_size, command);
        if (linux_command != NULL) {
            printf("Equivalent Linux command: %s\n", linux_command);
            system(linux_command);
        } else {
            printf("Command not found.\n");
        }
    }

    return 0;
}
