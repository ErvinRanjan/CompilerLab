#include "utils.h"
#include <string.h>
#include <stdlib.h>

void strip(char* dest, char* src, char ch) {
    int i = 0;
    int n = strlen(src);

    while (i < n && src[i] == ch) i++;

    int j = n - 1;
    while (j > i && src[j] == ch) j--;

    for (int k = i;k <= j;k++) {
        dest[k - i] = src[k];
    }

    dest[j - i + 1] = '\0';
}

// mainly to be used for function names, max buffer size allowed is 100
char* safeStrcpy(char* src) {
    if (src == NULL) return NULL;
    char* dest = malloc(sizeof(src));
    if (strlen(src) >= 100) {
        printf("Error: while doing safe copy: src pointer len is greater than or equal to 100\n");
        exit(EXIT_FAILURE);
    }
    strcpy(dest, src);
    return dest;
}

