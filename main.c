#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Simple runner/menu that compiles and runs a selected program from programs/ */

struct prog { const char *name; const char *file; };

static struct prog progs[] = {
    {"Temperature conversion", "tempConversion.c"},
    {"Vowel or consonant check", "vowelOrConsonant.c"},
    {"Number sign (positive/negative/zero)", "numberSign.c"},
    {"Sum of digits (5-digit)", "sumDigits.c"},
    {"Triangle angle validator", "triangleAngles.c"},
    {"Absolute value", "absoluteValue.c"},
    {"Calculator", "calculator.c"},
    {"Factorial", "factorial.c"},
    {"Rectangle area & perimeter", "rectangle.c"},
    {"Compound interest", "compoundInterest.c"},
    {"Hello world", "helloWorld.c"},
    {NULL, NULL}
};

int main(void) {
    int choice = -1;
    while (1) {
        puts("\n=== C Programs Menu ===");
        for (int i = 0; progs[i].name; ++i) {
            printf("%2d) %s\n", i+1, progs[i].name);
        }
        puts(" 0) Exit");
        printf("Select a program to compile & run: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }
        if (choice == 0) break;
        int idx = choice - 1;
        if (idx < 0 || progs[idx].name == NULL) {
            printf("Invalid choice.\n");
            continue;
        }
        char cmd[512];
        snprintf(cmd, sizeof cmd, "gcc -std=c11 -Wall -Wextra -o /tmp/selected_prog programs/%s && /tmp/selected_prog", progs[idx].file);
        printf("Running: %s\n", progs[idx].name);
        int rc = system(cmd);
        if (rc != 0) {
            printf("Program exited with status %d\n", rc);
        }
    }
    puts("Goodbye.");
    return 0;
}
