#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

void printMenu() {
    printf("\n--- Student File System ---\n");
    printf("1. Create Directory\n");
}

int main() {
    DirNode* rootDir = createDir(NULL, "root");
    int choice;
    char parentDirName[100], dirName[100], fileName[100], newName[100], targetDir[100];

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Parent directory (write 'root' if none): ");
                scanf("%s", parentDirName);
                DirNode* parentDir = findDir(rootDir, parentDirName);
                if (!parentDir) {
                    printf("Directory not found!\n"); break;
                }
                printf("New directory name: ");
                scanf("%s", dirName); 
                createDir(parentDir, dirName);
                printf("Directory created successfully.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}