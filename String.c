//Aim: to reverse a string in c
 
/*
Algorithm:
Step 1: Start
Step 2: Input the string STR
Step 3: Initialize two variables:
  i = 0 and j = length(STR) - 1
Step 4: Repeat while i < j
  - Swap STR[i] and STR[j]
  - Increment i by 1
  - Decrement j by 1
Step 5: Print the reversed string
Step 6: Stop
*/



#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);   // safely read input

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    i = 0;
    j = strlen(str) - 1;

    // Reverse the string
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
