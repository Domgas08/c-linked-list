#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node *next;

} Node;

Node *recursiveRead(FILE *file);
void readList(Node **first, char *Fname);
void printListConsole(Node *first);
void printListFile(Node *first, char *Fname);
void clearList(Node **first);
bool insertNew(Node *first, int prev_val, int val);
void insertEnd(Node **first, int val);


#endif
