#include "HashMap.h"

#include <stdlib.h>
#include <string.h>

unsigned default_hash(String key) {
    int len = strlen(key);
    unsigned hash = 0;
    unsigned i = 0;

    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

HashMap HashMap_Create() {
    HashMap map = (HashMap)malloc(sizeof(HashMap_struct));
    int i;
    for (i = 0; i < NUM_BUCKETS; ++i) {
        map->buckets[i] = 0;    // Zero out all elements in buckets, make empty
    }
    return map;
}

void HashMap_put(HashMap this, String key, Object obj) {
    unsigned hash = default_hash(key);
    unsigned index = hash % NUM_BUCKETS;

    // For now, don't check for collision...
    this->buckets[index] = obj;
}

Object HashMap_get(HashMap this, String key) {
    unsigned hash = default_hash(key);
    unsigned index = hash % NUM_BUCKETS;

    return this->buckets[index];
}

boolean HashMap_containsKey(HashMap this, String key) {
    unsigned hash = default_hash(key);
    unsigned index = hash % NUM_BUCKETS;

    // Contains if the element at the index is non-zero
    if (this->buckets[index]) {
        return true;
    }
    else {
        return false;
    }
}
