#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

typedef struct{
  int day;
  int month;
  int year;
}Date;

void get_date(Date *date);



#endif