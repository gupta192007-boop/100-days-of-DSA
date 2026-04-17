/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100003  // large prime for better distribution

// Hash node
typedef struct Node {
    int key;        // prefix sum
    int value;      // index
    struct Node* next;
} Node;

// Hash table
Node* hashTable[TABLE_SIZE];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

// Insert only if key not present
void insert(int key, int value) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp != NULL) {
        if (temp->key == key)
            return;  // already exists (we store first occurrence only)
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

// Search key
int search(int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp != NULL) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }

    return -1; // not found
}

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            max_length = i + 1;

        int prev_index = search(sum);

        if (prev_index != -1) {
            int length = i - prev_index;
            if (length > max_length)
                max_length = length;
        } else {
            insert(sum, i);
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 5;
}