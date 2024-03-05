#include "lib_file.h"

#include <errno.h>

#include "misc.h"

void showFile(char* path) {
    FILE* file;
    file = fopen(path, "a+");
    if (file != NULL) {
        char ch;
        while ((int)(ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    }
}

void addFile(char* path, char* string) {
    FILE* file;
    file = fopen(path, "a+");
    if (file != NULL) {
        fprintf(file, "%s\n", string);
        fclose(file);
    }
}
