/* expose mkstemp and other POSIX APIs */
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
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

static int count_progs(void) {
    int i = 0;
    while (progs[i].name) ++i;
    return i;
}

static int compile_program(const char *src_path, char *out_path, size_t out_sz) {
    char tmpl[] = "/tmp/selected_prog_XXXXXX";
    int fd = mkstemp(tmpl);
    if (fd < 0) {
        perror("mkstemp");
        return -1;
    }
    close(fd);

    if (strlen(tmpl) + 1 > out_sz) {
        fprintf(stderr, "output path buffer too small\n");
        unlink(tmpl);
        return -1;
    }
    strncpy(out_path, tmpl, out_sz);
    out_path[out_sz - 1] = '\0';

    pid_t pid = fork();
    if (pid == 0) {
        execlp("gcc", "gcc", "-std=c11", "-Wall", "-Wextra", "-O2", "-o", out_path, src_path, (char *)NULL);
        perror("execlp gcc");
        _exit(127);
    } else if (pid < 0) {
        perror("fork");
        unlink(out_path);
        return -1;
    }

    int status;
    if (waitpid(pid, &status, 0) < 0) {
        perror("waitpid");
        unlink(out_path);
        return -1;
    }
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        return 0;
    }
    unlink(out_path);
    return -1;
}

static int run_program(const char *path) {
    pid_t pid = fork();
    if (pid == 0) {
        execl(path, path, (char *)NULL);
        perror("execl");
        _exit(127);
    } else if (pid < 0) {
        perror("fork");
        return -1;
    }
    int status;
    if (waitpid(pid, &status, 0) < 0) {
        perror("waitpid");
        return -1;
    }
    if (WIFEXITED(status)) return WEXITSTATUS(status);
    return -1;
}

#define MAX_PATH_LEN 4096

int main(void) {
    const int n = count_progs();
    char line[128];

    /* Show the menu once */
    puts("\n=== C Programs Menu ===");
    for (int i = 0; i < n; ++i) {
        printf("%2d) %s\n", i + 1, progs[i].name);
    }
    puts(" 0) Exit");
    printf("Select a program to compile & run: ");

    if (!fgets(line, sizeof line, stdin)) {
        puts("Input error or EOF. Exiting.");
        return 1;
    }

    char *endptr;
    long choice = strtol(line, &endptr, 10);
    if (endptr == line) {
        puts("Please enter a valid number.");
        return 1;
    }
    if (choice == 0) {
        puts("Goodbye.");
        return 0;
    }
    if (choice < 1 || choice > n) {
        puts("Invalid choice.");
        return 1;
    }

    int idx = (int)choice - 1;
    char src_path[MAX_PATH_LEN];
    if (snprintf(src_path, sizeof src_path, "programs/%s", progs[idx].file) >= (int)sizeof src_path) {
        fprintf(stderr, "source path too long\n");
        return 1;
    }

    char out_path[MAX_PATH_LEN];
    printf("Compiling %s...\n", progs[idx].name);
    if (compile_program(src_path, out_path, sizeof out_path) != 0) {
        fprintf(stderr, "Compilation failed for %s\n", progs[idx].file);
        return 1;
    }

    printf("Running %s:\n", progs[idx].name);
    int rc = run_program(out_path);
    if (rc >= 0) {
        printf("Program exited with status %d\n", rc);
    } else {
        printf("Failed to run program\n");
    }
    /* remove the temporary executable */
    unlink(out_path);

    puts("Goodbye.");
    return rc >= 0 ? rc : 1;
}
