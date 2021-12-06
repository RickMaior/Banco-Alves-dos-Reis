/*  @name:Banco Alves dos Reis
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 08/11/2021
*/

// Teste de update
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funtions:

int request_integer(); //gets an integer from user
float request_float(); //gets a float from user


//Main code:

int main() {
	//https://www.guru99.com/c-file-input-output.html
	// necessario variavel para guardar dados do banco
    int opcao = 0;
    do {
        opcao = 0;
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
            case 99: // remove at end DEVELOPMENT ONLY
                
                break;
            default:
                printf("Introduza uma operacao valida!");

        }

    } while (opcao != 0);
    return 0;
}

//Functions code:

int request_integer(){
    // Request the user a integer number, and only leaves when a valid number is inserted
  
    int user_number;
    int scan_return;
   
    do{
        scan_return = scanf("%d",&user_number);
        fflush(stdin);
        if(!scan_return){
            // in case user doesnt put a valid number!
            printf("\033[0;31m"); //Set the text to the color red
            printf(" Por favor introduza um numero valido ! "); //Prints error  in red
            printf("\033[0m"); // resets color
        }
    }while(!scan_return);

    return user_number;
}

float request_float(){
    // Request the user a  float number, and only leaves when a valid number is inserted
    
    float user_number;
    int scan_return;
   
    do{
        scan_return = scanf("%f",&user_number);
        fflush(stdin);
        if(!scan_return){
            // in case user doesnt put a valid number!
            printf("\033[0;31m"); //Set the text to the color red
            printf(" Por favor introduza um numero valido ! "); //Prints error  in red
            printf("\033[0m"); // resets color
        }
    }while(!scan_return);

    return user_number;
}