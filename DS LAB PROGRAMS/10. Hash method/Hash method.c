#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int key;
    int isOccupied;
} HashTable;

void initializeHashTable(HashTable ht[], int m) {
    for (int i = 0; i < m; i++) {
        ht[i].key = -1;
        ht[i].isOccupied = 0;
    }
}

int hashFunction(int key, int m) {
    return key % m;
}

void insert(HashTable ht[], int m, int key) {
    int index = hashFunction(key, m);
    int originalIndex = index;

    while (ht[index].isOccupied) {
        index = (index + 1) % m;
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert key: %d\n", key);
            return;
        }
    }

    ht[index].key = key;
    ht[index].isOccupied = 1;
    printf("Key %d inserted at index %d\n", key, index);
}

void display(HashTable ht[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (ht[i].isOccupied) {
            printf("Index %d: Key %d\n", i, ht[i].key);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int search(HashTable ht[], int m, int key) {
    int index = hashFunction(key, m);
    int originalIndex = index;

    while (ht[index].isOccupied) {
        if (ht[index].key == key) {
            return index;
        }
        index = (index + 1) % m;
        if (index == originalIndex) {
            break;
        }
    }

    return -1;
}

int main() {
    int m, n, choice, key, index;
    HashTable ht[MAX];

    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    initializeHashTable(ht, m);

    printf("Enter the number of employee records (n): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(ht, m, key);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a new key\n");
        printf("2. Search for a key\n");
        printf("3. Display hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(ht, m, key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                index = search(ht, m, key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found in the hash table\n", key);
                }
                break;
            case 3:
                display(ht, m);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
