#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <klee/klee.h>

#include "utils.h"
#include "Book.h"
#include "Collection.h"
#include "HashMap.h"
#include "ArrayList.h"

/* Static Init */
void init() {
    Collection_Collections = HashMap_Create();
}

/* Tests */
void addBook() {
    Book test = Book_Create("Tortuga", "Captain Jack Sparrow");
    Collection testCol;
    if (!Collection_exists("Pirates")) {
        testCol = Collection_Create("Pirates");
    }
    else {
        testCol = Collection_restoreCollection("Pirates");
    }
    Book_addToCollection(test, testCol);
    assert(strcmp("Tortuga; Captain Jack Sparrow; Pirates", Book_getStringRepresentation(test)) == 0);
}

void saveCol() {
    Book test = Book_Create("Tortuga", "Captain Jack Sparrow");
    Collection testCol;
    if (!Collection_exists("Pirates")) {
        testCol = Collection_Create("Pirates");
    }
    else {
        testCol = Collection_restoreCollection("Pirates");
    }
    Book_addToCollection(test, testCol);
    Collection nullTest = Collection_restoreCollection("Pirates");
    assert(!(nullTest == NULL));
}

void recreateCol() {
    Book test = Book_Create("Tortuga", "Captain Jack Sparrow");
    Collection testCol;
    if (!Collection_exists("Pirates")) {
        testCol = Collection_Create("Pirates");
    }
    else {
        testCol = Collection_restoreCollection("Pirates");
    }
    Book_addToCollection(test, testCol);
    Collection recTest = Collection_restoreCollection("Pirates");
    assert(strcmp(Collection_getStringRepresentation(recTest), Collection_getStringRepresentation(testCol)) == 0);
}

int main(int argc, char **argv) {
    int i;
    void (*tests[3])();
    void (*sym_tests[3])();

    init();

    tests[0] = &addBook;
    tests[1] = &saveCol;
    tests[2] = &recreateCol;

    klee_make_symbolic(sym_tests, sizeof(sym_tests), "foo");
    klee_permutate(sym_tests, tests, 3, sizeof(tests[0]));

    for (i = 0; i < 3; ++i) {
        (*sym_tests[i])();
    }
}
