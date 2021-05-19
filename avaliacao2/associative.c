#include <stdlib.h>
#include <stdbool.h>

typedef struct link
{
	int key;
	int value;
	struct link *next;
} link;

typedef struct list
{
	link *head;
} list;

void list_insert(list *l, int key, int value)
{
	link *current_link = l->head;

	while (current_link->next)
	{
		if (current_link->next == NULL)
		{
			break;
		}

		current_link = current_link->next;
	}

	link *new_link = malloc(sizeof(struct link));

	current_link->key = key;
	current_link->value = value;
	current_link->next = new_link;
}

int list_lookup(list *l, int key)
{
	link *current_link = l->head;

	while (current_link)
	{
		if (current_link->key == key)
		{
			return current_link->value;
		}
		current_link = current_link->next;
	}

	return 0;
}

int list_remove(list *l, int key)
{
	link *current_link = l->head;

	while (current_link->next)
	{
		link *before_link = current_link;
		if (current_link->key == key)
		{

			int value = current_link->value;
			before_link->next = current_link->next;

			free(current_link);

			return value;
		}
		current_link = current_link->next;
	}

	return 0;
}