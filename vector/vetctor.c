#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

//implementação de uma pilha através de um vetor dinâmico
struct vector
{
    //buffer interno do vetor
    int *buffer;

    //numero de item da pilha
    int size;

    //capacidade total do vetor
    int cap;
};

vector *vector_create(void)
{
    //aloca um novo vetor
    vector *newvec = malloc(sizeof(struct vector));

    //define um numero inicial de intens para o vetor
    const int initial = 8;

    //aloca espacço para um int * a capacidade do vetor
    newvec->buffer = malloc(sizeof(int) * initial);
    //define número de itens na pilha
    newvec->size = 0;
    //define capacidade do vetor
    newvec->cap = initial;
    return newvec;
}

void vector_delete(vector *vector)
{
    free(vector->buffer);
    free(vector);
}

int vector_get(vector *vector, int pos)
{
    return vector->buffer[pos];
}


void vector_push(vector *vector,int num)
{
    vector->buffer[vector->size]=num;
    vector->size++;

    if (vector->size>vector->cap)
    {
        realloc(vector->buffer,vector->cap*2);
    }
    
}

void vector_pop(vector *vector)
{
    if(vector->size>0)
    {
        vector->size--;
    }
}