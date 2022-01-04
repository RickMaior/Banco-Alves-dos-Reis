/*  @name:Banco Alves dos Reis
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 08/11/2021
*/

//! https://www.guru99.com/c-file-input-output.html
//!  necessario variavel para guardar dados do banco

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

        printf("\n\tVoce escolheu %d\n", opcao);

        switch (opcao){
        case 0:
            update_file(bank);
            printf(" A Sair da app");
            break;
        case 1:
            new_account(&bank);
            break;
        case 2: //! TODO THINGS TO FINISH
            printf("Voce quer listar contas");
            break;
        case 3: //TODO user gets locked if there are no accounts
            check_account(bank);
            break;
        case 4: //! TODO THINGS TO FINISH
            printf("Voce vai Depositar dinheiro");
            break;
        case 5: //! TODO THINGS TO FINISH
            printf("Voce vai Levantar dinheiro");
            break;
        case 6: //! TODO THINGS TO FINISH
            printf("Voce vai Transferir dinheiro");
            break;
        //TODO fazer ate aqui na primeira parte
        case 7: //! TODO THINGS TO FINISH
            printf("Voce vai Editar conta");
            break;
        case 8: //! TODO THINGS TO FINISH
            printf("Voce vai Eliminar conta");
            break;
        case 9: //! TODO THINGS TO FINISH
            printf("Voce vai Gravar listagem de conta em ficheiro");
            break;

        case 98: // TODO remove at end DEVELOPMENT ONLY
            printf("bank accounts = %d\n", bank.active_accounts);
            break;
        case 99: // TODO remove at end DEVELOPMENT ONLY
            print_account(bank.accounts[0]);
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