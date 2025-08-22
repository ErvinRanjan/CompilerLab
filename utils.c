#include "utils.h"
#include <string.h>

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