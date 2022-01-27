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
#include "history.h"


// ACCOUNT



void new_account(Bank *bank){ // Creates a new client with the parameters as data (where nif was already validated) //! TODO THINGS TO FINISH
    
    if( (*bank).active_accounts >= 100){
        printf("O banco chegou ao limite de contas.\n");
        return;
    }

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
    
    update_history( &(*bank).accounts[new_id].history, new_transaction("Account Creation", (*bank).accounts[new_id].balance) );

    // Saving the new account
    printf("Conta criada com sucesso com ID: %d\n", (*bank).accounts[new_id].id);
    (*bank).funds += (*bank).accounts[new_id].balance;
    (*bank).active_accounts++;
}

void print_account(Account account){ //! TODO things to finish
    
    printf("ID: %d\n", account.id);
    printf("Titulares da conta: \n");
    for(int i = 0; i < account.total_owners; i++){
        print_client(account.owner[i]);
        printf("\n");
    }
    
    //TODO Print account type
    printf("Balance: %d,%.2d euros\n", account.balance/100, account.balance%100);
    printf("History: \n");
    print_history(account.history); 
    printf("\nCreation date: \n\tday: %d\n\tmonth: %d\n\tyear: %d \n", account.creation_date.day, account.creation_date.month, account.creation_date.year);
 
}

void find_account_from_id(Bank bank){

    if(bank.active_accounts == 0) {
        printf("Nao foi encontrada nenhuma conta no banco!\n");
        return;
    }


    int account_check = -1;
    
    do{
        printf("Qual conta quer consultar? ");
        account_check = request_integer();
        if(account_check <= 0 || account_check > bank.active_accounts) printf("Introduza um ID valido! \n");
    }while(account_check <= 0 || account_check > bank.active_accounts);
    printf("\n");
    print_account(bank.accounts[account_check -1]);
}

void find_account_from_nif(Bank bank){

    if(bank.active_accounts == 0) {
        printf("Nao foi encontrada nenhuma conta no banco!\n");
        return;
    }

    int user_option;
    long user_nif = -1;

    do{
        printf("Quer ver todas as contas (1) ou pesquisar por NIF (2) ?\n");
        user_option = request_integer();
        if(user_option != 1 && user_option != 2 ) printf("Introduza uma opcao valida!\n");
    }while(user_option != 1 && user_option != 2 );
    
    if(user_option == 2){
        
        printf("Qual o NIF do utilizador pelo qual quer pesquisar?\n");
        user_nif = request_long();
         
    }
    int accounts_found = 0;   

    for(int account = 0; account < bank.active_accounts ;account++){ // loop por todas as contas
       // printf("\nVendo conta n: %d\n", account +1);
        for(int owner = 0; owner < bank.accounts[account].total_owners; owner++){ // loop por todos os utilizadores
            if(bank.accounts[account].owner[owner].nif == user_nif || user_option == 1) {
                printf("\n-----------------------------\n");
                print_account(bank.accounts[account]);
                accounts_found++;
                
                break;
            }
            
        }
    }

    if(accounts_found == 0) printf("Nao foi encontrada nenhuma conta!\n");

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
        printf("Qual o seu nome?\n\t");
        gets(name);
        if(!verify_name(name)) printf("Esse nome nao e valido!\n");
    }while(!verify_name(name));
    
    strcpy((*client).name, name);
}

void deposit_money(Bank *bank){ // TODO function to be finished

    if( (*bank).active_accounts == 0) {
        printf("Nao foi encontrada nenhuma conta no banco!\n");
        return;
    }

    int account;
    do{
        printf("Qual conta quer depositar dinheiro? ");
        account = request_integer();
        if(account <= 0 || account > (*bank).active_accounts) printf("Introduza um ID valido! \n");
    }while(account <= 0 || account > (*bank).active_accounts);
    account--;

    //TODO add action cost

    float user_money = 0;
    do{
        printf("Quanto dinheiro vai depositar na conta? ");
        user_money = request_float(); 
        if(user_money <=0) printf("Introduza uma quantia valida de dinheiro!\n");
    }while(user_money <= 0 );
    
    (*bank).accounts[account].balance += (user_money*100);
    update_history( &(*bank).accounts[account].history, new_transaction("Deposit Money", (user_money*100) ) );


    printf("Seu novo saldo e: %d,%.2d euros.\n", (*bank).accounts[account].balance/100, (*bank).accounts[account].balance%100);



}

void withdraw_money(Bank *bank){ // TODO function to be finished
// User gets locked if the account has 0 balance

    if( (*bank).active_accounts == 0) {
        printf("Nao foi encontrada nenhuma conta no banco!\n");
        return;
    }



    int account;
    do{
        printf("Qual conta quer levantar dinheiro? ");
        account = request_integer();
        if(account <= 0 || account > (*bank).active_accounts) printf("Introduza um ID valido! \n");
    }while(account <= 0 || account > (*bank).active_accounts);
    account--;

    //TODO add action cost

    float user_money = 0;
    do{
        printf("Quanto dinheiro vai levantar da conta? ");
        user_money = request_float(); 
        if(user_money <=0 || user_money*100 > (*bank).accounts[account].balance ) printf("Voce nao pode levantar essa quantia!\n");
    }while(user_money <=0 || user_money*100 > (*bank).accounts[account].balance  );
    
    (*bank).accounts[account].balance -= (user_money*100);
    update_history( &(*bank).accounts[account].history, new_transaction("Withdraw Money", -(user_money*100) ) );

    printf("Seu novo saldo e: %d,%.2d euros.\n", (*bank).accounts[account].balance/100, (*bank).accounts[account].balance%100);

}

void transfer_money(Bank *bank){ // TODO function to be done
// User gets locked if the account has 0 balance

    if( (*bank).active_accounts == 0 || (*bank).active_accounts == 1 ) {
        printf("Nao foram encontradas contas suficientes para efetuar uma transferencia!\n");
        return;
    }

    int account_sender;
    do{
        printf("De qual conta que enviar dinheiro? ");
        account_sender = request_integer();
        if(account_sender <= 0 || account_sender > (*bank).active_accounts) printf("Introduza um ID valido! \n");
    }while(account_sender <= 0 || account_sender > (*bank).active_accounts);
    account_sender--;

    int account_receiver;
    do{
        printf("Para qual conta quer enviar dinheiro? ");
        account_receiver = request_integer();
        if(account_receiver <= 0 || account_receiver > (*bank).active_accounts) printf("Introduza um ID valido! \n");
        if(account_receiver == (account_sender+1)) printf("Voce nao pode enviar dinheiro para a mesma conta\n");
    }while(account_receiver <= 0 || account_receiver > (*bank).active_accounts || account_receiver == (account_sender+1) );
    account_receiver--;

    //TODO add action cost

    float user_money = 0;
    do{
        printf("Quanto dinheiro quer enviar? ");
        user_money = request_float(); 
        if(user_money <=0 || user_money*100 > (*bank).accounts[account_sender].balance ) printf("Voce nao pode transferir essa quantia!\n");
    }while(user_money <=0 || user_money*100 > (*bank).accounts[account_sender].balance  );
    
    (*bank).accounts[account_sender].balance -= (user_money*100);
    (*bank).accounts[account_receiver].balance += (user_money*100);

    printf("Seu novo saldo e: %d,%.2d euros.\n", (*bank).accounts[account_sender].balance/100, (*bank).accounts[account_sender].balance%100);
    printf("O saldo da outra conta e: %d,%.2d euros.\n", (*bank).accounts[account_receiver].balance/100, (*bank).accounts[account_receiver].balance%100); 

    update_history( &(*bank).accounts[account_sender].history, new_transaction("Transfer Money - Sending", -(user_money*100) ) );
    update_history( &(*bank).accounts[account_receiver].history, new_transaction("Transfer Money - Receiving", (user_money*100) ) );
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


