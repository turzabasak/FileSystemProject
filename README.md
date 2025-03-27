Student File System:
A simple console-based file system simulation in C. This project provides basic file system operations such as creating directories, creating files, listing the structure, searching for files/directories, renaming, moving, and deleting items.

Overview:
This repository contains three primary files:

main.c:
Has the main function and an interactive menu that allows you to use the file system features.
Demonstrates how to create, search, list, rename, and delete files/directories using the data structures and functions defined in filesystem.h and implemented in filesystem.c.

filesystem.h:
Declares the data structures and function prototypes needed for managing directories and files.

Defines two key structures:
FileNode: Represents an individual file.
DirNode: Represents a directory, which can contain both files and subdirectories.

filesystem.c:
Implements the functions declared in filesystem.h.
Includes functionality to create and remove directories, create and remove files, search by name, rename items, and move files between directories.
The directory structure is represented as a tree of DirNode structures, each containing a linked list of FileNode structures to represent the files within that directory. The program starts with a root directory and allows you to interact with it via text-based commands.

Features:
Create Directory.
Create a new directory under a specified parent directory.
Create File.
Create a file within a specified directory.
List Directories and Files.
Recursively list all directories and files in the system starting from the root.

Search:
Find a directory or file by name and display its path if found.

Delete File:
Delete a specific file from a directory.

Delete Directory:
Delete a specified directory (and all its contents).

Rename Item:
Rename either a file or a directory.

Move File:
Move a file from one directory to another.

Exit:
Exit the program, automatically freeing up any dynamically allocated memory.


Getting Started:
Prerequisites:
A C Language compiler (e.g., gcc).
A terminal or command prompt to compile and run the program.

Building and Running:
Clone this repository or download the files (main.c, filesystem.c, filesystem.h) to your local machine.

Compile the program using a command like:
bash
Copy
Edit
gcc main.c filesystem.c -o student_fs

Run the resulting executable:
bash
Copy
Edit
./student_fs
You will be presented with a text menu with various options. Enter the number of the option you want to perform.

Usage:
After running the program:

Create Directory:
Select option 1.
Enter the name of the parent directory. If you wish to create a directory directly under root, type root.
Enter the new directory's name.
The directory is created if the parent is found.

Create File:
Select option 2.
Enter the directory in which the new file should be created.
Enter the file name.
The file is created if the directory is found.

List Directories and Files:
Select option 3.
This will print the directory structure in a hierarchical format, starting at root.

Search:
Select option 4.
Enter the name of the file or directory you want to search for.
The console will display where it was found if it exists.

Delete File:
Select option 5.
Enter the name of the directory that contains the file to delete.
Enter the file name.
The file will be removed if it is found in that directory.

Delete Directory:
Select option 6.
Enter the parent directory name.
Enter the directory name to delete.
The directory and all its subdirectories/files will be removed if it is found.

Rename Item:
Select option 7.
Enter the directory containing the item to rename.
Enter the old name and then the new name.
If the item is found, its name will be updated.

Move File:
Select option 8.
Enter the source directory name.
Enter the file name to move.
Enter the destination directory name.
The file will be moved if both the source file and destination directory are found.

Exit:
Select option 9.
The program will free all dynamically allocated memory and then terminate.

Project Structure:
less
Copy
Edit
├── main.c          // Contains the main function and user-interface logic
├── filesystem.h    // Header file with data structures and function prototypes
└── filesystem.c    // Implementation of file system operations

Memory Management:
The freeMemory function in filesystem.c recursively frees all directories and files.
When you choose the "Exit" option, this function is called to ensure there are no memory leaks.