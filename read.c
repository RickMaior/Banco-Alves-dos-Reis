    /*  @name: Read.c
    @description:
        This file includes the functions that allow to read data from user (Int, float and long)

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 00/00/2021
*/

#include "read.h"
#include <stdio.h>

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