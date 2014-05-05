#ifndef BOOK_H
#define BOOK_H

#include "utils.h" 

#include <stdlib.h>

typedef struct Book_struct* Book;

#include "Collection.h"

typedef struct Book_struct {
    char title[40];
    char author[40];
    Collection parent;
} Book_struct;

Book Book_Create(String title, String author);

Collection Book_getParentCollection(Book this);
void Book_setParentCollection(Book this, Collection collection);
void Book_addToCollection(Book this, Collection collection);
String Book_getStringRepresentation(Book this);
String Book_getComparativeString(Book this);

#endif
