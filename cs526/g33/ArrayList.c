#include "ArrayList.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ArrayList ArrayList_Create() {
    ArrayList list = (ArrayList)malloc(sizeof(ArrayList_struct));
    list->elements = malloc(sizeof(Object) * 10); // Start with 10 element array
    list->array_size = 10;
    list->size = 0;

    return list;
}

void ArrayList_add(ArrayList this, Object a) {
    // Expand size of list if necessary
    if (this->array_size == this->size) {
        this->array_size = this->array_size * 2;    // Double size of internal array
        Object* tmp = malloc(sizeof(Object) * this->array_size);
        memcpy(tmp, this->elements, this->size);
        free(this->elements);
        this->elements = tmp;
    }
    this->elements[this->size] = a;
    this->size++;
}
