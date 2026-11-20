#include <stdio.h>
#include "io.h"

int is_sep(char c) {
    if (c == ' ' || c == ',' || c == '.' || c == ':' || c == ';') {
        return 1;
    }
    return 0;
}

int main() {
    char s[256], w[256];
    printf("Vvedite stroku: ");
    input_str(s, 256);

    int i = 0;
    while (s[i] != '\0') {
        while (s[i] != '\0' && is_sep(s[i])) {
            i++;
        }
        int k = 0;
        while (s[i] != '\0' && !is_sep(s[i])) {
            w[k] = s[i];
            k++;
            i++;
        }
        if (k > 0) {
            w[k] = '\0';
            output_str(w);
        }
    }

    return 0;
}