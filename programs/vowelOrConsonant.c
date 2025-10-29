#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    printf("Enter a single character: ");
    if (scanf(" %c", &ch) != 1) {
        fprintf(stderr, "No input provided.\n");
        return 1;
    }

    if (!isalpha((unsigned char)ch)) {
        printf("'%c' is not an alphabetic character.\n", ch);
        return 0;
    }
    char lower = (char)tolower((unsigned char)ch);
    if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
        printf("The character %c is a vowel.\n", ch);
    } else {
        printf("The character %c is a consonant.\n", ch);
    }

    return 0;
}
