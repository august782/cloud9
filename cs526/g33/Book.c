#include "Book.h"

#include <string.h>
#include <stdio.h>

Book Book_Create(String title, String author) {
    Book book = (Book)malloc(sizeof(Book_struct));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->parent = NULL;

    return book;
}

Collection Book_getParentCollection(Book this) {
    return this->parent;
}

void Book_setParentCollection(Book this, Collection collection) {
    this->parent = collection;
}

void Book_addToCollection(Book this, Collection collection) {
    if (collection == NULL) {
        Book_setParentCollection(this, NULL);
        return;
    }
    Collection_addToCollection(collection, this);
}

String Book_getStringRepresentation(Book this) {
    String strRep = (String)malloc(sizeof(char) * 100);
    strRep[0] = '\0';   // Just in case first character is not NULL
    strcat(strRep, this->title);
    strcat(strRep, "; ");
    strcat(strRep, this->author);

    if (Book_getParentCollection(this) != NULL) {
        Collection parent = Book_getParentCollection(this);
        strcat(strRep, "; ");
        strcat(strRep, Collection_getStringRepresentation(parent));
    }

    return strRep;
}

String Book_getComparativeString(Book this) {
    String ret = (String)malloc(sizeof(char) * 100);
    ret[0] = '\0';
    strcat(ret, this->title);
    strcat(ret, "; ");
    strcat(ret, this->author);

    return ret;
}
