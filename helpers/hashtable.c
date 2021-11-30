#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

unsigned int hash(const char* key) {
    unsigned long int value = 0;
    for (unsigned int i = 0; i < strlen(key); i++) {
        value = value * 37 + key[i];
    }

    return value % TABLE_SIZE;;
}

entry_t* ht_pair(const char* key, const char* value) {
    entry_t* entry = malloc(sizeof(entry_t) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    strcpy(entry->key, key);
    strcpy(entry->value, value);

    entry->next = NULL;

    return entry;
}

ht_t* ht_init(void) {
    ht_t* hashtable = malloc(sizeof(ht_t) * 1);

    hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

    for(size_t i = 0; i < TABLE_SIZE; ++i) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

void ht_put(ht_t *hashtable, const char *key, const char *value) {
    unsigned int slot = hash(key);

    entry_t *entry = hashtable->entries[slot];

    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t *prev;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        prev = entry;
        entry = prev->next;
    }

    prev->next = ht_pair(key, value);
}

char *ht_get(ht_t *hashtable, const char *key) {
    unsigned int slot = hash(key);

    entry_t *entry = hashtable->entries[slot];

    if (entry == NULL) {
        return NULL;
    }

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }

        entry = entry->next;
    }

    return NULL;
}

void ht_del(ht_t *hashtable, const char *key) {
    unsigned int bucket = hash(key);

    entry_t *entry = hashtable->entries[bucket];

    if (entry == NULL) {
        return;
    }

    entry_t *prev;
    int index = 0;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (entry->next == NULL && index == 0) {
                hashtable->entries[bucket] = NULL;
            }

            if (entry->next != NULL && index == 0) {
                hashtable->entries[bucket] = entry->next;
            }

            if (entry->next == NULL && index != 0) {
                prev->next = NULL;
            }

            if (entry->next != NULL && index != 0) {
                prev->next = entry->next;
            }

            free(entry->key);
            free(entry->value);
            free(entry);

            return;
        }

        prev = entry;
        entry = prev->next;

        ++index;
    }
}

void ht_deallocate(ht_t *hashtable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue;
        }

        for(;;) {

            if (entry->next == NULL) {
                break;
            }

            entry = entry->next;
        }
    }
}
// int main() {
//     ht_t *ht = ht_init();

//     ht_put(ht, "name1", "em");
//     ht_put(ht, "name2", "russian");
//     ht_put(ht, "name3", "pizza");
//     ht_put(ht, "name4", "doge");
//     ht_put(ht, "name5", "pyro");
//     ht_put(ht, "name6", "joost");
//     ht_put(ht, "name7", "kalix");

//     ht_deallocate(ht);

//     return 0;
// }