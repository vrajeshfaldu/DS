// 85. In an array of 20 elements, arrange 15 different values, which are generated 
// randomly between 1,00,000 to 9,99,999. Use hash function to generate key and 
// linear probing to avoid collision. H(x) = (x mod 18) + 2. Write a program to input 
// and display the final values of array. 

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define n 20

int hashSet[n];

void init(){
    for(int i=0 ; i<n ; i++){
        hashSet[i] = -1;
    }
}

int f(int key){
    return (key % 18) + 2;
}

bool add(int key){
    int index = f(key);   
   

    if(hashSet[index] == -1){
        hashSet[index] = key;
        return true;
    }
    else if (hashSet[index] == key){
        return false;
    }
    else{
        //linear probing
        int i = (index + 1) % n;
        for(int prob = 1 ; prob < n ; prob++){
            if(hashSet[i] == -1){
                hashSet[i] = key;
                return true;
            }
            else if(hashSet[i] == key){
                return false;
            }
            else{
                i = (i + 1) % n;
            }
        }
    } 
    return false;
}
bool contains(int key){
    int index = f(key);   
   

    if(hashSet[index] == -1){
        return false;
    }
    else if (hashSet[index] == key){
        return true;
    }
    else{
        //linear probing
        int i = (index + 1) % n;
        for(int prob = 1 ; prob < n ; prob++){
            if(hashSet[i] == -1){
                return false;
            }
            else if(hashSet[i] == key){
                return true;
            }
            else{
                i = (i + 1) % n;
            }
        }
    } 
    return false;
}

void display(){
    for(int i=0 ; i<n ; i++){
        printf("%d ", hashSet[i]);
    }
    printf("\n");
}

void main(){
    init();
    int count = 0;
    while(count < 15){
        int num = (rand() % (999999 - 100000 + 1)) + 100000;
        if(add(num)){
            count++;
        }
    }
    display();
}
