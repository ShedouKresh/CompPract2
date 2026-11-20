#include <stdio.h>
#include <string.h>
#include "io.h"

void input_str(char *s, int n) {
    fgets(s, n, stdin);
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void output_str(char *s) {
    printf("%s\n", s);
}