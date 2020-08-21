#pragma once

typedef struct circular circular;

circular *circular_create(void);
void circular_delete(circular *);

int circular_size(circular *);

int circular_get(circular *, int);

void circular_push_back(circular *, int);
void circular_push_front(circular *, int);
void circular_pop_back(circular *);
void circular_pop_front(circular *);