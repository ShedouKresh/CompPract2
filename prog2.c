#include <stdio.h>
#include <string.h>
#include "io.h"

int is_sep(char c) {
    if (c == ' ' || c == ',' || c == '.' || c == ':' || c == ';') {
        return 1;
    }
    return 0;
}

int has_word(char *str, char *w) {
    int i = 0;
    int wlen = strlen(w);
    while (str[i] != '\0') {
        while (str[i] != '\0' && is_sep(str[i])) {
            i++;
        }
        int start = i;
        while (str[i] != '\0' && !is_sep(str[i])) {
            i++;
        }
        int len = i - start;
        if (len == wlen && strncmp(str + start, w, wlen) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char s1[256], s2[256], res[256];
    res[0] = '\0';

    printf("Vvedite 1 stroku: ");
    input_str(s1, 256);
    printf("Vvedite 2 stroku: ");
    input_str(s2, 256);

    int i = 0;
    while (s1[i] != '\0') {
        while (s1[i] != '\0' && is_sep(s1[i])) {
            i++;
        }
        int start = i;
        while (s1[i] != '\0' && !is_sep(s1[i])) {
            i++;
        }
        int len = i - start;
        if (len > 0) {
            char w[256];
            strncpy(w, s1 + start, len);
            w[len] = '\0';

            if (has_word(s2, w) && !has_word(res, w)) {
                if (res[0] != '\0') {
                    strcat(res, " ");
                }
                strcat(res, w);
            }
        }
    }

    printf("Rezultat: ");
    output_str(res);
    return 0;
}