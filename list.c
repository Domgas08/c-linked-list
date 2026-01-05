#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


Node *recursiveRead(FILE *file)
{
    int value;
    if (fscanf(file, "%d", &value) != 1)
        return NULL;

    Node *element = (Node *)malloc(sizeof(Node));
    element->val = value;
    element->next = recursiveRead(file);

    return element;
}

void readList(Node **first, char *Fname)
{
    FILE *file = fopen(Fname, "r");
    if (file == NULL)
    {
        printf("Error while opening file for reading.\n");
        return;
    }
    *first = recursiveRead(file);

    if (*first == NULL)
        return;


    Node *element = *first;
    while (element->next != NULL)
    {
        element = element->next;
    }
    element->next = *first;

    fclose(file);
}

void printListConsole(Node *first)
{
    if (first == NULL)
        return;
    Node *element = first;
    printf("List:\n---------------------\n");
    do
    {
        printf(">%d-", element->val);
        element = element->next;
    } while (element != first);
    printf("\n---------------------\n\n");
}

void printListFile(Node *first, char *Fname)
{
    FILE *file = fopen(Fname, "w");
    if (file == NULL)
    {
        printf("Error while opening file for reading.\n");
        return;
    }

    if (first == NULL)
        return;
    Node *element = first;
    fprintf(file, "List:\n---------------------\n");
    do
    {
        fprintf(file, ">%d-", element->val);
        element = element->next;
    } while (element != first);
    fprintf(file, "\n---------------------\n");
    fclose(file);
}

void clearList(Node **first)
{
    Node *element = *first;
    Node *next;
    if (*first == NULL)
        return;

    do
    {
        next = element->next;
        free(element);
        element = next;
    } while (element != *first);

    *first = NULL;
}

bool insertNew(Node *first, int prev_val, int val)
{
    if(first == NULL)
        return 0;

    Node *element = first, *prev_element;

    do
    {
        prev_element = element;
        element = element->next;

        if (element->val == prev_val)
        {
            Node *new_element = (Node *)malloc(sizeof(Node));
            new_element->val = val;
            prev_element->next = new_element;
            new_element->next = element;
            return 1;
        }
    } while (element != first);
    return 0;
}

void insertEnd(Node **first, int val)
{
    if ((*first) == NULL)
    {
        (*first) = (Node *)malloc(sizeof(Node));
        (*first)->val = val;
        (*first)->next = (*first);
        return;
    }

    Node* element = (*first);

    while (element->next != *first)
    {
        element = element->next;
    }

    Node *new_element = (Node *)malloc(sizeof(Node));
    element->next = new_element;
    new_element->val = val;
    new_element->next = (*first);
}