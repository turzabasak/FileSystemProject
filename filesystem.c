#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

DirNode* createDir(DirNode* parent, const char* name) {
    DirNode* newDir = (DirNode*)malloc(sizeof(DirNode));
    strcpy(newDir->dirName, name);
    newDir->parentDir = parent;
    newDir->childDirs = NULL;
    newDir->fileList = NULL;
    newDir->nextDir = NULL;

    if (parent != NULL) {
        if (parent->childDirs == NULL)
            parent->childDirs = newDir;
        else {
            DirNode* temp = parent->childDirs;
            while (temp->nextDir != NULL)
                temp = temp->nextDir;
            temp->nextDir = newDir;
        }
    }

    return newDir;
}


void createFile(DirNode* parent, const char* fileName) {
    FileNode* newFile = (FileNode*)malloc(sizeof(FileNode));
    strcpy(newFile->fileName, fileName);
    newFile->nextFile = NULL;

    if (parent->fileList == NULL)
        parent->fileList = newFile;
    else {
        FileNode* temp = parent->fileList;
        while (temp->nextFile != NULL)
            temp = temp->nextFile;
        temp->nextFile = newFile;
    }
}

void listAll(DirNode* current, int level) {
    if (!current) return;

    for (int i = 0; i < level; i++) printf("  ");
    printf("[DIR] %s\n", current->dirName);

    FileNode* file = current->fileList;
    while (file) {
        for (int i = 0; i <= level; i++) printf("  ");
        printf("- %s\n", file->fileName);
        file = file->nextFile;
    }

    DirNode* subdir = current->childDirs;
    while (subdir) {
        listAll(subdir, level + 1);
        subdir = subdir->nextDir;
    }
}

void search(DirNode* current, const char* searchName, char path[]) {
    if (!current) return;

    char newPath[1024];
    sprintf(newPath, "%s/%s", path, current->dirName);

    if (strcmp(current->dirName, searchName) == 0)
        printf("[Found Dir] %s\n", newPath);

    FileNode* file = current->fileList;
    while (file) {
        if (strcmp(file->fileName, searchName) == 0)
            printf("[Found File] %s/%s\n", newPath, file->fileName);
        file = file->nextFile;
    }

    DirNode* subdir = current->childDirs;
    while (subdir) {
        search(subdir, searchName, newPath);
        subdir = subdir->nextDir;
    }
}

