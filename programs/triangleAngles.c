#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

static int read_float(const char *prompt, float *out) {
    char buf[128];
    char *endptr;
    printf("%s", prompt);
    if (!fgets(buf, sizeof buf, stdin)) return 0;
    /* strip newline */
    buf[strcspn(buf, "\n")] = '\0';
    if (buf[0] == '\0') return 0;
    errno = 0;
    float v = strtof(buf, &endptr);
    if (endptr == buf || errno == ERANGE) return 0;
    *out = v;
    return 1;
}

int main(void) {
    float angle1, angle2, angle3;
    if (!read_float("Enter the 1st value for Angle1: ", &angle1)) {
        fprintf(stderr, "Invalid input for angle1\n");
        return 1;
    }
    if (!read_float("Enter the 2nd value for Angle2: ", &angle2)) {
        fprintf(stderr, "Invalid input for angle2\n");
        return 1;
    }
    if (!read_float("Enter the 3rd value for Angle3: ", &angle3)) {
        fprintf(stderr, "Invalid input for angle3\n");
        return 1;
    }

    /* Use a small epsilon to compare floats */
    const float EPS = 1e-4f;
    float sum = angle1 + angle2 + angle3;
    if (fabsf(sum - 180.0f) <= EPS) {
        printf("The triangle has valid angles\n");
    } else {
        printf("The triangle has invalid angles (sum = %.4f)\n", sum);
    }
    return 0;
}
