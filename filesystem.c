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



