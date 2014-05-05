#include "utils.h"

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList_struct* ArrayList;

typedef struct ArrayList_struct {
    Object *elements;
    int array_size;
    int size;
} ArrayList_struct;

ArrayList ArrayList_Create();

void ArrayList_add(ArrayList this, Object a);

#endif
