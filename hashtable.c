
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE !TRUE
#define SIZE_HASH_MAP 10
#define HASH_CONSTANT ((sqrt(5) - 1) / 2)

static int hashMapLinear[SIZE_HASH_MAP];                        // hash table

/* HASH FUNCTIONS */
int hash(int value);                                            /* hash function */
void linearProbingInsert(int value);                            /* inserts a value in the hash table, using linear probing */
int linearProbingSearch(int value);                             /* searches for a value in the hash table */
/* AUXILIARY FUNCTIONS */
void populateHashMap(int numbersToBeGenerated);                 /* AUX: inserts i random integer numbers in the hash table */
void printHashMap();                                            /* AUX: prints the hash table */
void searchNumbers(int numbersToBeSearched);                    /* AUX: searches some random numbers in the hash table */

/* HASH FUNCTIONS */
int hash(int value){
    return (SIZE_HASH_MAP * fmod((value * HASH_CONSTANT),1));
}

void linearProbingInsert(int value){
    int probe = hash(value);                                    // stores the hash value of the number
    while (hashMapLinear[probe]!=0){                            // if the array slot we are trying to write on is not empty
        probe = fmod((probe+1),SIZE_HASH_MAP);                  // moves to the next one
    }
    hashMapLinear[probe] = value;                               // stores the value
}

int linearProbingSearch(int value){
    int probe = hash(value);                                    // stores the hash value of the number
    int i;
    for(i=0;i<SIZE_HASH_MAP;i++){                               // loop which is potentially performed N times 
        if(hashMapLinear[probe]==value)
            return TRUE;                                        // returns true if the value in hashMapLinear[hash(value)] is equal to our value
        probe = fmod((probe+1),SIZE_HASH_MAP);                  // moves to the next element
    }
    return FALSE;                                               // returns false elsewhere
}

/* MAIN FUNCTION */
int main (int argc, char const *argv[]){
    srand(time(NULL));
    populateHashMap(SIZE_HASH_MAP);
    printf("\nsituation after insertion of random integers:\n");
    printHashMap();
    printf("\nsearch of some random integers:\n");
    searchNumbers(10);
} 

/* AUXILIARY FUNCTIONS */
void populateHashMap(int numbersToBeGenerated){                 // generates numbersToBeGenerated  random numbers
    int k = 1;
    int randomNumber;
    for(k=1;k<=numbersToBeGenerated;k++){
        randomNumber = rand() % 100 + 1; 
        linearProbingInsert(randomNumber);                      // inserts them in the hash map
    }
}

void printHashMap(){
    int i;
    for(i=0;i<SIZE_HASH_MAP;i++){                               // prints every element of the array
        printf("hashMapLinear[%d]: %d\n",i,(hashMapLinear[i]));
    }
}

void searchNumbers(int numbersToBeSearched){
    int k;
    int randomNumber;
    for(k=1;k<=numbersToBeSearched;k++){                        // searches a random number (from 1 to 100) numbersToBeSearched times
        randomNumber = rand() % 30 + 1; 
        printf("Is the value %d present? %d\n",randomNumber,linearProbingSearch(randomNumber));
    }
}