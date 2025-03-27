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

#endif