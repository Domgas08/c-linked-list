#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "list.h"

void testInsertEnd()
{
    Node* first = NULL;
    //check if: insertEnd works
    insertEnd(&first, 1);
    insertEnd(&first, 2);
    assert(first->val == 1);
    assert(first->next->val == 2);
}

void testClear()
{
    Node* first = NULL;
    //check if: clearList works
    insertEnd(&first, 5);
    clearList(&first);
    assert(first == NULL);

}

void testInsertNew()
{
    Node* first = NULL;
    //check if: insertNew works
    insertEnd(&first, 1);
    insertEnd(&first, 3);
    insertNew(first, 3, 2);
    assert(first->val == 1);
    assert(first->next->val == 2);
    assert(first->next->next->val == 3);

}

void testInsertNew2()
{
    Node* first = NULL;
    //check if: insertNew works if we want to insert before `first`
    insertEnd(&first, 1);
    insertNew(first, 1, 5);
    assert(first->val == 1);
    assert(first->next->val == 5);
}

void testNoInsert()
{
    Node* first = NULL;
    //check if: insertNew does NOT insert if no "before value" has been found
    insertEnd(&first, 1);
    insertEnd(&first, 5);
    insertNew(first, 100, 1000);
    assert(first->val == 1);
    assert(first->next->val == 5);
    assert(first->next->next->val == 1);
}





int main()
{
    testInsertEnd();
    testInsertNew();
    testInsertNew2();
    testClear();
    testNoInsert();
    printf("all good");
    
    return 0;
}