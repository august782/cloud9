#include "Collection.h"

#include <string.h>

boolean Collection_exists(String key) {
    return HashMap_containsKey(Collection_Collections, key);
}

Collection Collection_restoreCollection(String stringRepresentation) {
    if (HashMap_containsKey(Collection_Collections, stringRepresentation)) {
        return (Collection)(HashMap_get(Collection_Collections, stringRepresentation));
    }
    return NULL;
}

Collection Collection_Create(String name) {
    Collection collection = (Collection)malloc(sizeof(Collection_struct));
    strcpy(collection->name, name);
    collection->children = ArrayList_Create();

    HashMap_put(Collection_Collections, collection->name, collection);
    //rootCollections->add(rootCollections, (Object)collection);

    return collection;
}

void Collection_addToCollection(Collection this, Book book) {
    if (Book_getParentCollection(book) == NULL && !Collection_fulltreeContains(this, book)) {
        ArrayList_add(this->children, (Object)book);
        Book_setParentCollection(book, this);
    }
}

boolean Collection_fulltreeContains(Collection this, Book book) {
    int i;
    ArrayList children = this->children;

    for (i = 0; i < children->size; ++i) {
        Book child = (Book)children->elements[i];
        if (strcmp(Book_getComparativeString(child), Book_getComparativeString(book)) == 0) {
            return true;
        }
    }
    return false;
}

String Collection_getStringRepresentation(Collection this) {
    return this->name;
}
