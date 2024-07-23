#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generateAnagrams(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&str[start], &str[i]);
        generateAnagrams(str, start + 1, end);
        swap(&str[start], &str[i]); // Backtrack
    }
}

int main() {
    char numStr[10];

    printf("Enter a 9-digit number: ");
    scanf("%s", numStr);

    int len = strlen(numStr);

    if (len != 9) {
        printf("Invalid input. Please enter a 9-digit number.\n");
        return 1;
    }

    printf("Anagrams of %s are:\n", numStr);
    generateAnagrams(numStr, 0, len - 1);

    return 0;
}
