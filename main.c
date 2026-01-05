#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "list.h"

#define LOWEST_MENU 0
#define HIGHEST_MENU 6

int choosingNumber(int lower_bound, int higher_bound) // returns -1 if option is invalid
{
    int option = 0;
    char char_after;
    if (scanf("%d", &option) == 1 && (char_after = getchar()) == '\n')
    {
        if (option >= lower_bound && option <= higher_bound)
            return option;
    }

    else
    {
        while (getchar() != '\n');
    }
    return -1;
}

void showMenu()
{
    printf("----------------------\n");
    printf("Menu\n");
    printf("----------------------\n");
    printf("0 - read list from file\n");
    printf("----------------------\n");
    printf("1 - clear list\n");
    printf("----------------------\n");
    printf("2 - print list (console)\n");
    printf("----------------------\n");
    printf("3 - print list (file)\n");
    printf("----------------------\n");
    printf("4 - insert new value\n");
    printf("----------------------\n");
    printf("5 - insert new value at the end\n");
    printf("----------------------\n");
    printf("6 - exit\n");
}

char *getFileName()
{
    printf("Please enter file name: ");
    char *file_name = (char *)malloc(100 * sizeof(char));
    if (scanf("%100s", file_name) != 1)
    {
        printf("Error while getting file name.\n");
        return NULL;
    }

    return file_name;
}

int main()
{
    Node *first = NULL;
    int value, value_before;
    char *file_name;

    while (true)
    {
        showMenu();
        switch (choosingNumber(LOWEST_MENU, HIGHEST_MENU))
        {
        case 0:
            printf("Are you sure you want to create / overwrite new list? (y/n) ");
            if (getchar() == 'y')
            {
                clearList(&first);
                file_name = getFileName();
                if (file_name != NULL)
                    readList(&first, file_name);
            }
            while (getchar() != '\n')
                ;
            break;

        case 1:
            printf("Are you sure you want to clear list? (y/n) ");
            if (getchar() == 'y')
            {
                clearList(&first);
            }
            while (getchar() != '\n')
                ;
            break;

        case 2:
            printListConsole(first);
            break;

        case 3:
            file_name = getFileName();
            printListFile(first, file_name);
            break;

        case 4:
            printf("Choose new value and where to insert.\nNew value: ");
            value = choosingNumber(INT_MIN, INT_MAX);
            printf("Before which value: ");
            value_before = choosingNumber(INT_MIN, INT_MAX);
            if (insertNew(first, value_before, value) == 0)
                printf("Could not insert. Did not found value before.\n");
            break;
        
        case 5:
            printf("Choose new value to insert at the end: ");
            value = choosingNumber(INT_MIN, INT_MAX);
            insertEnd(&first, value);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}
