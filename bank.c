/*  @name:
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 00/00/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "bank.h"


// ACCOUNT


void print_account(Account account){
    
    printf("ID: %d\n", account.id);
    print_client(account.owner[0]); //TODO for all owners
    printf("Balance: %d\n", account.balance);
    printf("history: %c\n", account.history[0]); // TODO for all history
    printf("creation: %d\n", account.creation_date);
 
}

void new_account(Bank *bank){ // Creates a new client with the parameters as data (where nif was already validated)
    int new_id = (*bank).active_accounts ;

    // int id;
    // Client owner[5];
    // char account_type; // N -> normal, I -> insent
    // int balance; // account ballance in cents
    // char history[3]; // TODO historico da conta
    // int creation_date; // data de criação da conta


    (*bank).accounts[new_id].id = new_id;

    //TODO for all owners
    
    printf("Qual o seu nome?\n");
    strcpy((*bank).accounts[new_id].owner[0].name, "Bom dia");
    printf("Qual o seu nif?\n");
    (*bank).accounts[new_id].owner[0].nif = 123456789;
    

    //TODO ask user account type
    printf("Qual o tipo de conta pretendida?\n");
    (*bank).accounts[new_id].account_type = 'N';
    
    do{
        //TODO ask user account new balance
        printf("Qual o valor pretendido para abrir a conta?\n");
        (*bank).accounts[new_id].balance = 15000;// TODO ask user the value
        if((*bank).accounts[new_id].balance < 15000) printf("Valor insuficiente para abrir conta!\n");
    }while((*bank).accounts[new_id].balance < 15000);

    //TODO get current day


    //TODO ask user if user likes the new account
    // if(user_likes){
    //     save();
    // }else repeat();
    

    // Saving the new account
    (*bank).active_accounts++;
}

// BANK
Bank get_bank(){
    Bank bank;
    FILE *f;

    f = fopen("bank.bin", "rb");
    if(f == NULL){
        f = fopen("bank.bin", "wb"); 
        bank.active_accounts = 0;
        bank.funds = 0;
        fwrite(&bank, sizeof(Bank) , 1 , f);
    }else{
        fread(&bank, sizeof(Bank) , 1 , f);
    }

    fclose(f); 
    return bank;
}

void update_file(Bank bank){
    FILE *f;

    f = fopen("bank.bin", "wb");
    fwrite(&bank, sizeof(Bank) , 1 , f);
    fclose(f); 
}


