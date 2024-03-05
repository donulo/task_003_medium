#include "misc.h"

#include <time.h>

#include "lib_file.h"
#include "lib_string.h"

char* getPath(int argc, char* argv[]) {
    char* path = copyString(DEFAULT_PATH);
    if (argc > 1) {
        path = copyString(argv[1]);
    }

    FILE* file;
    file = fopen(path, "a+");
    if (file != NULL) {
        fclose(file);
    }

    return path;
}

void menu(char* path) {
    char* itemMenu;
    while (strcmp(itemMenu = readString(stdin), "EXIT") != 0) {
        if (strcmp(itemMenu, "SHOW") == 0)
            showFile(path);
        else if (strcmp(itemMenu, "ADD") == 0)
            addFile(path, readPurchase(stdin));
        else
            exception("Puck you, Verter!");
    }
    exit(EXIT_SUCCESS);
}

void exception(char* msg) {
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}
char* getDatetime() {
    char* result = calloc(20, sizeof(char));
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    strftime(result, 20, "%d.%m.%Y %H:%M:%S", u);
    return result;
}

char* readPurchase(FILE* stream) {
    char* datetime = getDatetime();
    char* name = readString(stream);
    char* value = readString(stream);

    char* purchase = calloc(strlen(datetime) + strlen(name) + strlen(value) + 4, sizeof(char));
    strcat(purchase, datetime);
    strcat(purchase, " ");
    strcat(purchase, name);
    strcat(purchase, " ");
    strcat(purchase, value);
    return purchase;
}