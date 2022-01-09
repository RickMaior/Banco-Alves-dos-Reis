/*  @name:
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 00/00/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "client.h"
#include "bank.h"


// ACCOUNT



void new_account(Bank *bank){ // Creates a new client with the parameters as data (where nif was already validated) //! TODO THINGS TO FINISH
    
    int new_id = (*bank).active_accounts ;

    // // int id;
    // // Client owner[5];
    // // char account_type; // N -> normal, I -> insent
    // // int balance; // account ballance in cents
    // // char history[3]; 
    // // int creation_date; // data de criação da conta

    //Where (*bank).accounts[new_id] is a new client
    (*bank).accounts[new_id].id = new_id + 1; // Define the new account ID


    do{
        printf("Quantos titulares a conta vai ter?\n");
        (*bank).accounts[new_id].total_owners = request_integer(); 
        if((*bank).accounts[new_id].total_owners > 5 ||  (*bank).accounts[new_id].total_owners < 1) printf("Introduza um numero valido de utilizadores! (entre 1 e 5)\n");
    }while( (*bank).accounts[new_id].total_owners > 5 ||  (*bank).accounts[new_id].total_owners < 1);
    


    int counter_owner = 0;
    do{
    long user_nif;
    do{
        printf("Qual o NIF do %d titular?\n\t", counter_owner +1); // TODO verify if nif is already associated with the account if more than one owner
        user_nif = request_long();
        if(!verify_nif(user_nif))printf("Introduza um nif valido! \n");
    }while(!verify_nif(user_nif));
                                                                                                                                                                            
    (*bank).accounts[new_id].owner[counter_owner].nif = user_nif;

    get_name_from_nif( bank, &(*bank).accounts[new_id].owner[counter_owner] ); // Gets the name for the user

    counter_owner++;
    }while(counter_owner < (*bank).accounts[new_id].total_owners); // loops over all owners
   
    

    //TODO ask user account type
    printf("Qual o tipo de conta pretendida?\n");
    (*bank).accounts[new_id].account_type = 'N';
    
    float user_money;
    do{
        //TODO ask user account new balance
        printf("Qual o valor pretendido para abrir a conta?\n");
        user_money = request_float();
        (*bank).accounts[new_id].balance = user_money * 100;
        if((*bank).accounts[new_id].balance < 15000) printf("Valor insuficiente para abrir conta!\n");
    }while((*bank).accounts[new_id].balance < 15000);



    
    get_date( &(*bank).accounts[new_id].creation_date ); // function to get the day from when the account was created

    //TODO ask user if user likes the new account
    // if(user_likes){
    //     save();
    // }else repeat();
    
    //TODO add account criation to the user history
    // Saving the new account
    printf("Conta criada com sucesso com ID: %d\n", (*bank).accounts[new_id].id);
    (*bank).funds += (*bank).accounts[new_id].balance;
    (*bank).active_accounts++;
}

void print_account(Account account){ //! TODO THINGS TO FINISH
    
    printf("ID: %d\n", account.id);
    printf("Titulares da conta: \n");
    for(int i = 0; i < account.total_owners; i++){
        print_client(account.owner[i]);
        printf("\n");
    }
    
    printf("Balance: %d,%.2d euros\n", account.balance/100, account.balance%100);
    printf("history: %c\n", account.history[0]); // TODO for all history
    printf("creation date: \n\tday: %d\n\tmonth: %d\n\tyear: %d \n", account.creation_date.day, account.creation_date.month, account.creation_date.year);
 
}

void check_account(Bank bank){
    int account_check = -1;
    
    do{
        printf("Qual conta quer consultar? ");
        account_check = request_integer();
        if(account_check <= 0 || account_check > bank.active_accounts) printf("Introduza um ID valido! \n");
    }while(account_check <= 0 || account_check > bank.active_accounts);
    printf("\n");
    print_account(bank.accounts[account_check -1]);
}

void get_name_from_nif(Bank *bank, Client *client){

    int account_number = 0;
    while(account_number < (*bank).active_accounts){
        int owner_number = 0;
        while( owner_number <  (*bank).accounts[account_number].total_owners ){ //TODO fix the counting
            if( (*client).nif == (*bank).accounts[account_number].owner[owner_number].nif ) {
               // printf("\nEste Nif ja existe com o nome: %s\n", (*bank).accounts[account_number].owner[owner_number].name);
                strcpy((*client).name, (*bank).accounts[account_number].owner[owner_number].name ); // copies the first name found with that nif to thew client
                return;
            }
            
            owner_number++;
        }
        account_number++;
    }

    char name[51];
    do{
        printf("Qual o seu nome?\n\t"); // TODO verify if name is valid
        gets(name);
        if(!verify_name(name)) printf("Esse nome nao e valido!\n");
    }while(!verify_name(name));
    
    strcpy((*client).name, name);
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


