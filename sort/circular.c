#include "circular.h"
#include <stdlib.h>

struct circular
{
    int *buffer;
    int cap;
    int start;
    int end;
};

circular *circular_create(void)
{
    circular *newcirc = malloc(sizeof(struct circular));

    const initial = 4;

    newcirc->buffer = malloc(sizeof(int) * initial);
    newcirc->cap = initial;
    newcirc->start = 0;
    newcirc->end = 0;

    return newcirc;
}

void circular_delete(circular *c)
{
    free(c->buffer);
    free(c);
}

int circular_size(circular *c)
{
    int size = c->end - c->start;

    if (size < 0)
    {
        size += c->cap;
    }

    return size;
}

int circular_get(circular *c, int pos)
{
    if (pos < 0)
    {
        return 0;
    }
    if (pos >= circular_size(c))
    {
        return 0;
    }

    return c->buffer[(pos + c->start) % c->cap];
}

static void circular_grow(circular *c)
{
    // Os primeiros itens da lista começam em start e vão até capacity...
    int old_capacity = c->cap;
    int first_half = old_capacity - c->start;

    // Primeiro, aumentamos a capacidade e alocamos um novo vetor
    c->cap *= 2;
    int *new_buffer = malloc(sizeof(int) * c->cap);

    // Agora, copiamos os dados, porém na ordem correta
    memcpy(new_buffer, c->buffer + c->start, sizeof(int) * first_half);
    memcpy(new_buffer + first_half, c->buffer, sizeof(int) * c->start);

    // Como agora os dados estão em ordem, devemos lembrar isso
    c->start = 0;
    c->end = old_capacity;

    // Finalmente, limpamos o buffer antigo e usamos o novo
    free(c->buffer);
    c->buffer = new_buffer;
}

void circular_push_back(circular *, int)
{
}

void circular_push_front(circular *, int);
void circular_pop_back(circular *);
void circular_pop_front(circular *);