#include "tables.h"

#define ENTRYA 1;

state_table* get_reserved_table(void){
        //ID    NUM     STR     DEL
    static state_table reserved_table = {
        {N,     N,      N,      A,      N,      N,      N,      N},//0 - DECL
        {N,     J(0,2), N,      N,      N,      N,      N,      N},//1 - DECL =    
        {N,     N,      N,      R(0,0), N,      N,      N,      N},//2 - DECL = VAR
    };
    return &reserved_table;
}