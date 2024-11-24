#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
This program takes two words and determines if they are anagrams (where a word can be rearranged to another)
1. Ask for user input for words
2. Make the strings in their lower case format
3. Check if the two strings are anagrams
4. Display to the user if they are anagrams or not
*/
void lowerWords(char firstWord[20], char secondWord[20], char firstWordLower[20], char secondWordLower[20], int length) {
/*
This function turns the strings into their lower case formats
@firstWord[20]: The string for the first word
@secondWord[20]: The string for the second word
@firstWordLower[20]: The string for the first word in its lowercase format
@secondWordLower[20]: The string for the second word in its lowercase format
*/
    for (int i = 0; i < length; i++) {
        firstWordLower[i] = tolower(firstWord[i]);
        secondWordLower[i] = tolower(secondWord[i]);
    }
}

void checkAnagram(char firstWord[20], char secondWord[20], char firstWordLower[20], char secondWordLower[20], int length) {
/*
This function checks if the two words are anagrams, and then displays to the user if they are or aren't
@firstWord[20]: The string for the first word
@secondWord[20]: The string for the second word
@firstWordLower[20]: The string for the first word in its lowercase format
@secondWordLower[20]: The string for the second word in its lowercase format
@length: The length of the strings
*/

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if ((firstWordLower[i] == secondWordLower[j]) && (firstWordLower[i] != '%') && (secondWordLower[j] != '%')) {
                //printf("%c %c\n", firstWordLower[i], secondWordLower[j]);
                firstWordLower[i] = '%';
                secondWordLower[j] = '%';
            }
        }
    }

    if (strcmp(firstWordLower, secondWordLower) == 0) {
        printf("%s is an anagram of %s\n", firstWord, secondWord);
    } else {
        printf("%s is NOT an anagram of %s\n", firstWord, secondWord);
        //printf("%s %s", firstWordLower, secondWordLower);
    }
}

int main() {
    char firstWord[20], secondWord[20];
    char firstWordLower[20], secondWordLower[20];
/*
This function organizes the program
1. Ask for user input
2. Determine the length of the strings
3. Turn the words to their lowercase formats
4. Check if the words are anagrams and display the result to the user
@firstWord[20]: string for the first word
@secondWord[20]: string for the second word
@firstWordLower[20]: string for the first word in its lowercase format
@secondWordLower[20]: string for the second word in its lowercase format
@length: maximum length of the strings
*/

    /* Ask for user input */
    printf("Please enter the first word: ");
    scanf("%20s", firstWord);
    printf("Please enter the second word: ");
    scanf("%20s", secondWord);

    /* Determine the maximum length of the strings */
    int length = strlen(firstWord);
    if (length != (int)strlen(secondWord)) {
        printf("%s is NOT an anagram of %s\n", firstWord, secondWord);
        exit(0);
    }

    /* Turn the words to their lowercase formats */
    lowerWords(firstWord, secondWord, firstWordLower, secondWordLower, length);

    /* Check if the words are anagrams and display the result to the user*/
    checkAnagram(firstWord, secondWord, firstWordLower, secondWordLower, length);

    return 0;
}