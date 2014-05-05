#ifndef COLLECTION_H
#define COLLECTION_H

#include "utils.h"

#include "HashMap.h"
#include "ArrayList.h"

typedef struct Collection_struct* Collection;

typedef struct Collection_struct {
    char name[40];
    ArrayList children;
} Collection_struct;

HashMap Collection_Collections;
boolean Collection_exists(String key);
Collection Collection_restoreCollection(String stringRepresentation);

Collection Collection_Create(String name);

#include "Book.h"

void Collection_addToCollection(Collection this, Book book);
boolean Collection_fulltreeContains(Collection this, Book book);
String Collection_getStringRepresentation(Collection this);

#endif
