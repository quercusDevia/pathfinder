#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int wordCount = 0;
    int isWord = 0;

    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == c) {
            i++;
        }

        while (str[i] != '\0' && str[i] != c) {
            isWord = 1;
            i++;
        }

        if (isWord) {
            wordCount++;
            isWord = 0;
        }
    }

    return wordCount;
}
