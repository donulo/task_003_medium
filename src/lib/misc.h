#ifndef MISC_H
#define MISC_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_PATH "./data/database.txt"

char* getPath(int argc, char* argv[]);
void menu(char* path);
void exception(char* msg);
char* getDatetime();
char* readPurchase(FILE* stream);

#endif