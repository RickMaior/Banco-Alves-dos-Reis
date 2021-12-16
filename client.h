#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

typedef struct{
    char name[51];
    int nif;
} Client;

Client new_client(char *name,long nif);

void print_client(Client client);

int verify_nif( long number_to_verify);

#endif