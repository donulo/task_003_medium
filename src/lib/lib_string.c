#include "lib_string.h"

char* copyString(char* path) {
    char* result = calloc(strlen(path), sizeof(char));
    strcpy(result, path);
    return result;
}

char* readString(FILE* stream) {
    char* string = copyString("");
    char ch;
    int count = 0;
    while ((ch = fgetc(stream)) == '\n' || ch == ' ')
        ;
    while (ch != '\n' && ch != ' ' && ch != '\0' && (int)(ch) != EOF) {
        string = realloc(string, (++count + 1) * sizeof(char));
        if (string != NULL) {
            string[count - 1] = ch;
            ch = fgetc(stream);
        }
    }
    if (string != NULL) string[count] = '\0';
    return string;
}