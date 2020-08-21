#include <stdlib.h>

typedef struct link
{
    int value;
    struct link *next;
} link;

typedef struct list
{
    link *head;
} list;

list *list_create(void)
{
    list *newlist = malloc(sizeof(struct list));
    newlist->head = malloc(sizeof(struct link));
    return newlist;
}

void list_delete(list *l)
{
    link *current_link = l->head;

    while (current_link->next != NULL)
    {
        current_link = current_link->next;
        free(current_link);
    }

    free(l);
}

void list_push_front(list *l, int x)
{
    link *old_head = l->head;
    link *new_head = malloc(sizeof(struct link));

    new_head->value = x;
    new_head->next = old_head;

    l->head = new_head;
}

void list_push_back(list *l, int x)
{
    link *current_link = l->head;

    while (current_link->next != NULL)
    {
        if (current_link->next == NULL)
        {
            break;
        }

        current_link = current_link->next;
    }

    link *new_link = malloc(sizeof(struct link));
    new_link->value = x;

    current_link->next = new_link;
}

int list_pop_front(list *l)
{
    link *new_head = l->head->next;
    free(l->head);
    l->head = new_head;
}

int list_pop_back(list *l)
{
    link *current_link = l->head;

    while (current_link->next != NULL)
    {
        if (current_link->next == NULL)
        {
            break;
        }

        current_link = current_link->next;
    }

    free(current_link);
}

int list_size(list *l)
{
    link *current_link = l->head;
    int size = 0;

    while (current_link->next != NULL)
    {
        current_link = current_link->next;
    }

    return size;
}

int list_find(list *l, int x)
{
    link *current_link = l->head;

    while (current_link->next != NULL)
    {
        if (current_link->value == x)
        {
            return 1;
        }
        current_link = current_link->next;
    }

    return 0;
}