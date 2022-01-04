/*  @name:
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 00/00/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "date.h"

void get_date (Date *date){

   time_t t = time(NULL);

    struct tm tm = *localtime(&t);

    (*date).day= tm.tm_mday;

    (*date).month= tm.tm_mon+1;

    (*date).year= tm.tm_year+1900;
    
}