#pragma once

typedef struct vector vector;

//métodos de criação e remoção do vetor
vector *vector_create(void);
void vector_delete(vector *);

//método de pesquisa
int vector_get(vector *, int);

//métodos de inserção e deleção
void vector_push(vector *, int);
void vector_pop(vector *);