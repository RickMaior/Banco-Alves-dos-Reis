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

    // int id;
    // Client owner[5];
    // char account_type; // N -> normal, I -> insent
    // int balance; // account ballance in cents
    // char history[3]; 
    // int creation_date; // data de criação da conta


    (*bank).accounts[new_id].id = new_id + 1;

    //TODO for all owners
    long user_nif;
    do{
        printf("Qual o seu nif?\n");
        user_nif = request_long();
        if(!verify_nif(user_nif))printf("Introduza um nif valido! \n");
    }while(!verify_nif(user_nif));
    
                                                                                                                                                                                 
    (*bank).accounts[new_id].owner[0].nif = user_nif;

    //TODO check if nif already exists
    printf("Qual o seu nome?\n");
    strcpy((*bank).accounts[new_id].owner[0].name, "Bom dia");
   
    

    //TODO ask user account type
    printf("Qual o tipo de conta pretendida?\n");
    (*bank).accounts[new_id].account_type = 'N';
    
    do{
        //TODO ask user account new balance
        printf("Qual o valor pretendido para abrir a conta?\n");
        (*bank).accounts[new_id].balance = 15000;// TODO ask user the value
        if((*bank).accounts[new_id].balance < 15000) printf("Valor insuficiente para abrir conta!\n");
    }while((*bank).accounts[new_id].balance < 15000);

    // function to get the day from when the account was created
    get_date( &(*bank).accounts[new_id].creation_date );

    //TODO ask user if user likes the new account
    // if(user_likes){
    //     save();
    // }else repeat();
    

    // Saving the new account
    printf("Conta criada com sucesso com ID: %d\n", (*bank).accounts[new_id].id);
    (*bank).funds += (*bank).accounts[new_id].balance;
    (*bank).active_accounts++;
}

void print_account(Account account){ //! TODO THINGS TO FINISH
    
    printf("ID: %d\n", account.id);
    print_client(account.owner[0]); //TODO for all owners
    printf("Balance: %d\n", account.balance);
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


