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
#include "client.h"
#include "bank.h"


//Funtions:

void print_menu();


//Main code:

int main() {
	//https://www.guru99.com/c-file-input-output.html
	// necessario variavel para guardar dados do banco
    int opcao = 0;
    do {
        opcao = 0;
        print_menu();

        opcao = request_integer();

        printf("\n\tVoce escolheu %d\n", opcao);

        switch(opcao){
            case 0:
                printf("Saindo da app");
                break;
            case 1:
                printf("voce vai abrir conta");
                break;
            case 2:
                printf("voce quer listar contas");
                break;
            case 3:
                printf("Voce vai  Consultar a Conta  ");
                break;
            case 10:
                printf("Voce vai criar um Novo Cliente ");
                break;
            case 97: //TODO remove at end DEVELOPMENT ONLY
                test_bank();
                break;
            case 98: //TODO remove at end DEVELOPMENT ONLY
                printf("QUal o teu nome? ");
                char nome[20];
                gets(nome);
                if(verify_name(nome))printf("Nome valido!\n");
                else printf("Nome invalido!\n");
                break;
            case 99: //TODO remove at end DEVELOPMENT ONLY
                printf("Introduza um numero para testar se nif valido: ");
                long nif_teste = request_long();
                printf("Numero a testar: %li\n", nif_teste);
                int resultado = verify_nif(nif_teste);
                printf("o restultado e: %d\n", resultado);
                break;
            default:
                printf("Introduza uma operacao valida!");

        }

    } while (opcao != 0);

    return 0;
}

//Functions code:



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
    printf("\t10. Criar Novo Cliente\n\n");
    // outras opçoes
    printf("\t0. Sair\n");
    printf("\t<Digite opcao>:");

    
}