#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

typedef struct{
    char name[51];
    long nif;
} Client;

Client new_client(char *name,long nif);

void print_client(Client client);

int verify_nif( long number_to_verify);

int verify_name(char *name);

#endif