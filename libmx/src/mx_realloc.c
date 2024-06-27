#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size == 0) {
        if (ptr) {
            free(ptr);
        }

        return NULL;
    }

    if (!ptr) {
        return malloc(size);
    }

    void* smth = malloc(size);
    smth = mx_memmove(smth, ptr, (malloc_size(ptr) < size) ? malloc_size(ptr) : size);

    free(ptr);

    return smth;
}
