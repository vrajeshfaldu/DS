// 86. Implement a Dictionary (key, value) pair using Hash-table.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 20
#define EMPTY -1

#define HASH_SIZE 20
#define MIN 100000
#define MAX 999999
#define VALUE_MIN 1
#define VALUE_MAX 100

typedef struct {
    int key;
    int value;
} KeyValuePair;
KeyValuePair hashTable[HASH_SIZE];

int hashFunction(int key) {
    return (key % 18) + 2;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index].key != EMPTY) {
        if (hashTable[index].key == key) {
            hashTable[index].value = value; // Update value if key already exists
            return;
        }
        
        index = (index + 1) % HASH_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i].key != EMPTY) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

int main() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i].key = EMPTY;
        hashTable[i].value = EMPTY;
    }

    srand(time(0));
    int count = 0;
    while (count < 15) {
        int num = (rand() % (MAX - MIN + 1)) + MIN;
        int value = (rand() % (VALUE_MAX - VALUE_MIN + 1)) + VALUE_MIN;
        bool isDuplicate = false;
        for (int i = 0; i < HASH_SIZE; i++) {
            if (hashTable[i].key == num) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            insert(num, value);
            count++;
        }
    }

    display();
}