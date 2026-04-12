/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int table[SIZE];
int occupied[SIZE]; // 0 = empty, 1 = occupied

// Hash function
int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (occupied[index] == 0) {
            table[index] = key;
            occupied[index] = 1;
            return;
        }
    }
}


int search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (occupied[index] == 0) {
            return 0; 
        }

        if (table[index] == key) {
            return 1; 
        }
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);  // table size
    scanf("%d", &q);  // number of operations

    
    for (int i = 0; i < m; i++) {
        occupied[i] = 0;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}