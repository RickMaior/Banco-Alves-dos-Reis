#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

#include "date.h"

typedef struct{
    char action[51];
    int value;
    Date date;
} History;

History new_hitory(char *action, int value);

// void print_client(Client client);

// int verify_nif( long number_to_verify);

// int verify_name(char *name);

#endif