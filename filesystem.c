#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

// Created by Turza Basak (3746400)
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

// Created by Shahdous Prohor (3746335)
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

// Created by Shahdous Prohor (3746335)
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

// Created by Shahdous Prohor (3746335)
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

// Created by Agnila Hasnat Atma (3745926)
void freeMemory(DirNode* current) {
    if (!current) return;

    FileNode* file = current->fileList;
    while (file) {
        FileNode* tempFile = file;
        file = file->nextFile;
        free(tempFile);
    }

    DirNode* subdir = current->childDirs;
    while (subdir) {
        DirNode* tempDir = subdir;
        subdir = subdir->nextDir;
        freeMemory(tempDir);
    }

    free(current);
}

// Created by Agnila Hasnat Atma (3745926)
DirNode* findDir(DirNode* current, const char* name) {
    if (!current) return NULL;
    if (strcmp(current->dirName, name) == 0) return current;

    DirNode* subdir = current->childDirs;
    while (subdir) {
        DirNode* found = findDir(subdir, name);
        if (found) return found;
        subdir = subdir->nextDir;
    }
    return NULL;
}

// Created by Agnila Hasnat Atma (3745926)
void deleteFile(DirNode* current, const char* fileName) {
    FileNode *file = current->fileList, *prev = NULL;

    while (file && strcmp(file->fileName, fileName)) {
        prev = file;
        file = file->nextFile;
    }
    if (!file) { printf("File not found.\n"); return; }

    if (!prev) current->fileList = file->nextFile;
    else prev->nextFile = file->nextFile;

    free(file);
    printf("File deleted.\n");
}

// Created by Turza Basak (3746400)
void deleteDir(DirNode* parent, const char* dirName) {
    DirNode *dir = parent->childDirs, *prev = NULL;

    while (dir && strcmp(dir->dirName, dirName)) {
        prev = dir;
        dir = dir->nextDir;
    }
    if (!dir) { printf("Dir not found.\n"); return; }

    if (!prev) parent->childDirs = dir->nextDir;
    else prev->nextDir = dir->nextDir;

    freeMemory(dir);
    printf("Dir deleted.\n");
}

// Created by Turza Basak (3746400)
void renameItem(DirNode* current, const char* oldName, const char* newName) {
    DirNode* dir = current->childDirs;
    while (dir) {
        if (!strcmp(dir->dirName, oldName)) {
            strcpy(dir->dirName, newName);
            printf("Dir renamed.\n");
            return;
        }
        dir = dir->nextDir;
    }

    FileNode* file = current->fileList;
    while (file) {
        if (!strcmp(file->fileName, oldName)) {
            strcpy(file->fileName, newName);
            printf("File renamed.\n");
            return;
        }
        file = file->nextFile;
    }

    printf("Item not found.\n");
}

// Created by Md Ataullah Bahari (3746539)
void moveFile(DirNode* source, const char* fileName, DirNode* destination) {
    FileNode *file = source->fileList, *prev = NULL;

    while (file && strcmp(file->fileName, fileName)) {
        prev = file;
        file = file->nextFile;
    }
    if (!file) { printf("File not found.\n"); return; }

    if (!prev) source->fileList = file->nextFile;
    else prev->nextFile = file->nextFile;

    file->nextFile = NULL;

    if (!destination->fileList) destination->fileList = file;
    else {
        FileNode* temp = destination->fileList;
        while (temp->nextFile) temp = temp->nextFile;
        temp->nextFile = file;
    }

    printf("File moved.\n");
}