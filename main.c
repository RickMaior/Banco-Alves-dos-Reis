/*  @name:Banco Alves dos Reis
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 08/11/2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "bank.h"





// Funtions:

void print_menu();

// Main code:

int main(){
    Bank bank = get_bank();


  

    int opcao = 0;  
    do{
        opcao = 0;
        print_menu();

        opcao = request_integer();

        //printf("\n\tVoce escolheu %d\n", opcao); //TODO change?

        switch (opcao){
        case 0:
            update_file(bank);
            printf(" A Sair da app");
            break;
        case 1:
            new_account(&bank);
            break;
        case 2: 
            find_account_from_nif(bank);
            break;
        case 3: 
            find_account_from_id(bank);
            break;
        case 4: 
            deposit_money(&bank);
            break;
        case 5: 
            withdraw_money(&bank);
            break;
        case 6: 
            transfer_money(&bank);
            break;

        case 7:
            edit_account(&bank);
            break;
        case 8: 
            delete_account(&bank);
            break;
        case 9: 
            account_to_file(bank);
            break;

        case 98: // TODO remove at end DEVELOPMENT ONLY
            printf("bank accounts = %d\n", bank.active_accounts);
            break;
        
        default:
            printf("Introduza uma operacao valida!");
        }

    } while (opcao != 0);

    return 0;
}

// Functions code:

void print_menu(){

    printf("\n\n\t+++ OPERACAO PRETENDIDA +++\n");
    printf("\t1. Abrir conta\n");
    printf("\t2. Listar contas\n");
    printf("\t3. Consultar contas\n");
    printf("\t4. Depositar dinheiro\n");
    printf("\t5. Levantar dinheiro\n");
    printf("\t6. Transferir dinheiro\n");
    printf("\t7. Editar conta\n");
    printf("\t8. Eliminar conta\n");
    printf("\t9. Gravar listagem de conta em ficheiro\n");
    // outras opçoes
    printf("\t0. Sair\n");
    printf("\t<Digite opcao>:");
}
