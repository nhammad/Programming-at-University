/*JTSK- 320112
a6_p4.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct combo
{
    char* key;
    int element;
} combo;
//struct combo will allow us to store indexes of all
//passwords & user names

typedef struct ListNode
{
    combo* info;
    struct ListNode* next;
} ListNode;
//temporarily storing all data in a linked list

void empty(ListNode* head)
{
    if(head == NULL)
        return;
    ListNode* lst = head->next;
    free(head->info->key);
    free(head->info);
    free(head);
    empty(lst);
}

ListNode* insert(char* key, int element, ListNode* head)
{
    combo* el = (combo*) malloc(sizeof(combo));
    el->key = key;
    el->element = element;
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->info = el;
    node->next = head;
    return node;
}
//the function above is to insert new elements into the linked list

int search(char* key, ListNode* head)
{
    if(head == NULL)
        return -1;
    if(strcmp(head->info->key, key) == 0)
        return head->info->element;
    return search(key, head->next);
}
//the function above searches searches the key within
//the entire list and returns the exact position of that file

void printing(ListNode* head)
{
    if(head == NULL)
    {
        return;
    }
    printf("name: %s\n", head->info->key);
    printing(head->next);
}

char* reading(FILE* fp)
{
    char* line = (char*) malloc(sizeof(char) * MAX_LEN);
    if(fgets(line, MAX_LEN * sizeof(char), fp))
    {
        //replacing newline w end of line
        line[strlen(line)-1] = '\0';
        return line;
    }
    return NULL;
}

int main(int argc, char** argv)
{
    char* line1, *line2, *line3;
    int offset_pos;
    FILE* fp;
    char filename[50];
    ListNode* head = NULL;
    //reading word by word
    fgets(filename, sizeof(filename), stdin);
    //replacing newline w end of line
    filename[strlen(filename)-1] = '\0';
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    while((line1 = reading(fp)))
    {
        head = insert(line1, ftell(fp), head);
        free(reading(fp));
    }
    printing(head);
    while(1)
    {
        line1 = reading(stdin);
        if(strcmp(line1, "exit") == 0)
        {
            free(line1);
            break;
        }
        line2 = reading(stdin);
        offset_pos = search(line1, head);
        if(offset_pos != -1)
        {
            fseek(fp, offset_pos, SEEK_SET);
            line3 = reading(fp);
            if(strcmp(line2, line3) == 0)
            {
                printf("Access to user %s is granted.\n", line1);
            }
            else
            {
                printf("Access to user %s is denied.\n", line1);
            }
        }
        else
        {
            printf("Access to user %s is denied.\n", line1);
        }
        free(line1);
        free(line2);
        free(line3);
    }
    empty(head);
    fclose(fp);
}

//fseek(fp, pos, SEEK_SET);
//fp is a file pointer, points to file via fopen()
//offset (pos) is how far to move (in bytes) from the reference point
//SEEK_SET specifies the reference point (end of file)

//ftell() returns current position of file pointer as a long value
