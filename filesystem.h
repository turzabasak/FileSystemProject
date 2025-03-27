#ifndef FILESYSTEM_H
#define FILESYSTEM_H


typedef struct FileNode {
    char fileName[100];
    struct FileNode *nextFile;
} FileNode;


typedef struct DirNode {
    char dirName[100];
    struct DirNode *parentDir;
    struct DirNode *childDirs;
    struct DirNode *nextDir;
    FileNode *fileList;
} DirNode;


DirNode* createDir(DirNode* parent, const char* name);
void createFile(DirNode* parent, const char* fileName);
void listAll(DirNode* current, int level);
void search(DirNode* current, const char* searchName, char path[]);
void freeMemory(DirNode* current);
DirNode* findDir(DirNode* current, const char* name);
void deleteFile(DirNode* current, const char* fileName);
void deleteDir(DirNode* parent, const char* dirName);
void renameItem(DirNode* current, const char* oldName, const char* newName);
void moveFile(DirNode* source, const char* fileName, DirNode* destination);

#endif