#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

void printMenu() {
    printf("\n--- Student File System ---\n");
    printf("1. Create Directory\n");
    printf("2. Create File\n");
    printf("3. List Directories and Files\n");
    printf("4. Search\n");
    printf("5. Delete File\n");
    printf("6. Delete Directory\n");
    printf("7. Rename Item\n");
    printf("8. Move File\n");
    printf("9. Exit\n");
    printf("---------------------------\n");
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

            case 2:
                printf("Directory to create file in: ");
                scanf("%s", parentDirName);
                DirNode* target = findDir(rootDir, parentDirName);
                if (!target) {
                    printf("Directory not found!\n"); break;
                }
                printf("File name: ");
                scanf("%s", fileName);
                createFile(target, fileName);
                printf("File created successfully.\n");
                break;

            case 3:
                listAll(rootDir, 0);
                break;

            case 4:
                printf("Name to search: ");
                scanf("%s", dirName);
                search(rootDir, dirName, "");
                break;

            case 5:
                printf("Directory containing file: ");
                scanf("%s", parentDirName);
                DirNode* delFileDir = findDir(rootDir, parentDirName);
                if (!delFileDir) {
                    printf("Directory not found!\n"); break;
                }
                printf("File name to delete: ");
                scanf("%s", fileName);
                deleteFile(delFileDir, fileName);
                break;

            case 6:
                printf("Parent directory: ");
                scanf("%s", parentDirName);
                DirNode* delDirParent = findDir(rootDir, parentDirName);
                if (!delDirParent) {
                    printf("Directory not found!\n"); break;
                }
                printf("Directory to delete: ");
                scanf("%s", dirName);
                deleteDir(delDirParent, dirName);
                break;

            case 7:
                printf("Directory containing item: ");
                scanf("%s", parentDirName);
                DirNode* renameDir = findDir(rootDir, parentDirName);
                if (!renameDir) {
                    printf("Directory not found!\n"); break;
                }
                printf("Old name: ");
                scanf("%s", dirName);
                printf("New name: ");
                scanf("%s", newName);
                renameItem(renameDir, dirName, newName);
                break;

            case 8:
                printf("Source directory: ");
                scanf("%s", parentDirName);
                DirNode* srcDir = findDir(rootDir, parentDirName);
                if (!srcDir) {
                    printf("Source not found!\n"); break;
                }
                printf("File to move: ");
                scanf("%s", fileName);
                printf("Destination directory: ");
                scanf("%s", targetDir);
                DirNode* destDir = findDir(rootDir, targetDir);
                if (!destDir) {
                    printf("Destination not found!\n"); break;
                }
                moveFile(srcDir, fileName, destDir);
                break;

            case 9:
                freeMemory(rootDir);
                printf("Exiting. Memory cleaned up!\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}