#include "utils.h"

#ifndef HASHMAP_H
#define HASHMAP_H

#define NUM_BUCKETS 50

typedef struct HashMap_struct* HashMap;

typedef struct HashMap_struct {
    Object buckets[NUM_BUCKETS];
} HashMap_struct;

HashMap HashMap_Create();

void HashMap_put(HashMap this, String key, Object obj);
Object HashMap_get(HashMap this, String key);
boolean HashMap_containsKey(HashMap this, String key);

#endif
