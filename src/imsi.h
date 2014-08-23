#ifndef __IMSI__H
#define __IMSI__H
/*
   fetch the IMSI from share memory.
Usage:
   char dest[15];
   getImsiValue(dest);
*/
void getImsiValue(char* dest);
/*
   Confirm whether IMSI had been fetched.
   return 1 means ok.
*/
int getImsi();
#endif
