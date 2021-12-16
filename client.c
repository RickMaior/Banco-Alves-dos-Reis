/*  @name:
    @description:

    @author: Ricardo Matos
    @version: 1.0
    @date: 00/00/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

Client new_client(char *name,long nif){ // Creates a new client with the parameters as data (where nif was already validated)
    Client client;
    strcpy(client.name, name);
    client.nif = nif;
    return client;
}

void print_client(Client client){
    printf("name = %s\nNif=%ld", client.name, client.nif);
}


int verify_nif( long number_to_verify){ // verify if a number is a valid nif | 0 if false and 1 if true
    
    // get the ammount of digit number has
    if(number_to_verify <= 0) {
        //printf("Numero negativo nao valido!\n");
        return 0;
    }
    
    int number_parts[9];
    int counter;
    for(counter=0; number_to_verify > 0 && counter < 9 ; counter++){ 
        number_parts[8 - counter]=number_to_verify%10; // gets the last digit
        number_to_verify = number_to_verify/10;  // removes the last digit
    }

    //printf("\nnumber_to_verify = %li\n", number_to_verify); //debug only
    //printf("counter= %d\n", counter); // debug  only

    if (counter != 9 || number_to_verify != 0){ // if counter is different than 9, and number is not fully divided, than it means that number doesnt have 9 digits
        //printf("Numero com quantidade de digitos errado!\n"); // debug only
        return 0;
    }

    // Verify If nif is valid
    if (number_parts[0] == 1 || number_parts[0] == 2 || number_parts[0] == 5 || number_parts[0] == 6 || number_parts[0] == 8 || number_parts[0] == 9){
        int soma= number_parts[0]*9 + number_parts[1]*8 + number_parts[2]*7 + number_parts[3]*6 + number_parts[4]*5 + number_parts[5]*4 + number_parts[6]*3 + number_parts[7]*2;
        int total= soma % 11;
        //printf("O resto da divisao %d\n",total,soma); // debug only
        if ((total== 1 || total==0) && number_parts[8]==0)return 1;
        else if  (11-total == number_parts[8])return 1;
        else return 0;
    }
    

    return 0;
}