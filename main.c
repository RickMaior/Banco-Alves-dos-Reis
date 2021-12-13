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


int request_integer( void ); //gets an integer from user
long request_long( void ); //gets an even bigger integer from user
float request_float( void ); //gets a float from user

int verify_nif(long number_to_verify); // verify if a number is a valid nif


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

 
int request_integer( void ){
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

long request_long( void ){
    // Request the user an even bigger integer number, and only leaves when a valid number is inserted
  
    long user_number;
    int scan_return;
   
    do{
        scan_return = scanf("%li",&user_number);
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

float request_float( void ){
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