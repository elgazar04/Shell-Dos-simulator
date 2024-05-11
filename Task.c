#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char* argv[]) {
    int reverse = 0;
    const char *file = NULL;
    int k;

    for (k = 0; k < argc; k++) {
        if (strcmp(argv[k], "-h") == 0 || strcmp(argv[k], "--h") == 0 || strcmp(argv[k], "-help") == 0) {
            reverse = 1;
        } else {
            file = argv[k];
        }
    }

    if (reverse == 1) {
        system("cat Desc.txt");
    } else {
        FILE *CommandsFile;
        char InputCommand[50], command[150] = "";
        char *temp1, *temp2;
        char line[50], InputCommandTemp[50];
        int flag = 1;

        while (flag != 0) {
            printf("\nEnter your DOS Command \nTo Exit Enter 0\n");
            fgets(InputCommand, 50, stdin);

            if (InputCommand[0] != '0') {
                strcpy(InputCommandTemp, InputCommand);
                temp1 = strtok(InputCommand, " ");

                if ((CommandsFile = fopen("mapping", "r")) == NULL) {
                    printf("The File is Empty\n");
                } else {
                    while (fgets(line, 50, CommandsFile) != NULL) {
                        if ((strstr(line, temp1)) != NULL) {
                            temp2 = strtok(line, "=");
                            strcpy(command, temp2);
                            strcat(command, " ");
                            break;
                        }
                    }
                    temp1 = strtok(InputCommandTemp, " ");
                    temp1 = strtok(NULL, " ");
                }

                while (temp1 != NULL) {
                    strcat(command, temp1);
                    strcat(command, " ");
                    temp1 = strtok(NULL, " ");
                }

                printf("%s", command);
                system(command);
            } else {
                printf("Program Closed");
                flag = 0;
            }
        }
    }
}
