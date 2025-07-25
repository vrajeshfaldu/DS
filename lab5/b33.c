// Allow a user to enter N words and store it in an array. 
// • Generate a random number between 0 to N-1. 
// • Based on the random number generated display the word stored at that 
// index of an array and allow user to enter its anagram. 
// • Check whether the word entered by the user is an anagram of displayed 
// number or not and display an appropriate message. 
// • Given a word A and word B. B is said to be an anagram of A if and only if 
// the characters present in B is same as characters present in A, 
// irrespective of their sequence. For ex: “LISTEN” == “SILENT”
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void sortString(char *str){
    int length = strlen(str);
    for(int i=0; i< length - 1; i++){
        for(int j=i+1; j < length; j++){
            if(str[i]>str[j]){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
void main(){
    srand(time(0));
    int n=0;
    printf("Enter Number of Words (N) : ");
    scanf("%d",&n);

    char word[n][30];
    
    for(int i=0;i<n;i++){
        printf("Enter word here : ");
        scanf("%s",word[i]);
    }

    int randIndex = rand()%n;

    printf("Your anagram is : %s\n",word[randIndex]);

    char userWord[30];
    printf("Enter User word here : ");
    scanf("%s",userWord);

    char originalWordSorted[30], userWordSorted[30];
    strcpy(originalWordSorted, word[randIndex]);
    strcpy(userWordSorted, userWord);

    sortString(originalWordSorted);
    sortString(userWordSorted);

    puts(originalWordSorted);
    puts(userWordSorted);
    
    if(strcmp(originalWordSorted,userWordSorted) == 0){
        printf("Anagram");
    }else{
        printf("Not Anagram");
}

}
