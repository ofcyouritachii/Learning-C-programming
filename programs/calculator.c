#include <stdio.h>
#include <errno.h>

#define LINEBUF 128

/* Read a line into buf (strip newline). Returns 1 on success, 0 on EOF. */
static int read_line(char *buf, size_t size) {
	if (!fgets(buf, (int)size, stdin)) return 0;
	size_t len = strlen(buf);
	if (len && buf[len-1] == '\n') buf[len-1] = '\0';
	return 1;
}

/* Trim leading and trailing whitespace in-place */
static void trim(char *s) {
	char *p = s;
	while (isspace((unsigned char)*p)) p++;
	if (p != s) memmove(s, p, strlen(p)+1);
	size_t len = strlen(s);
	while (len && isspace((unsigned char)s[len-1])) s[--len] = '\0';
}

/* Try to parse a double from input string. Returns 1 on success, 0 on failure. */
static int parse_double(const char *s, double *out) {
	char *endptr;
	errno = 0;
	double val = strtod(s, &endptr);
	if (s == endptr) return 0; /* no conversion */
	/* allow trailing whitespace only */
	while (*endptr) {
		if (!isspace((unsigned char)*endptr)) return 0;
		endptr++;
	}
	if (errno == ERANGE) return 0;
	*out = val;
	return 1;
}

int main(void) {
	char line[LINEBUF];
	double a, b, result;

	printf("Simple calculator. Enter 'x' at any prompt to quit.\n");

	while (1) {
		/* Read first number */
		while (1) {
			printf("Enter first number (or x to quit): ");
			if (!read_line(line, sizeof line)) return 0; /* EOF */
			trim(line);
			if (strlen(line) == 1 && (line[0] == 'x' || line[0] == 'X')) return 0;
			if (parse_double(line, &a)) break;
			printf("Invalid number, try again.\n");
		}

		/* Read second number */
		while (1) {
			printf("Enter second number (or x to quit): ");
			if (!read_line(line, sizeof line)) return 0;
			trim(line);
			if (strlen(line) == 1 && (line[0] == 'x' || line[0] == 'X')) return 0;
			if (parse_double(line, &b)) break;
			printf("Invalid number, try again.\n");
		}

		/* Read operator */
		char op = 0;
		while (1) {
			printf("Enter operator (+ - * / ^) or x to quit: ");
			if (!read_line(line, sizeof line)) return 0;
			trim(line);
			if (strlen(line) == 1 && (line[0] == 'x' || line[0] == 'X')) return 0;
			if (strlen(line) >= 1) {
				op = line[0];
				if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') break;
			}
			printf("Invalid operator, try again.\n");
		}

		/* Compute */
		int ok = 1;
		switch (op) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/':
				if (b == 0.0) { printf("Error: division by zero.\n"); ok = 0; }
				else result = a / b;
				break;
			case '^': result = pow(a, b); break;
			default:
				ok = 0; /* should not happen */
				break;
		}

		if (ok) printf("Result: %.10g\n", result);
		/* Loop continues automatically */
	}

	return 0;
}
