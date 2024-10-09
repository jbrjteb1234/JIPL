#include "tables.h"
//TODO IMPLEMENT COMMA
state_table* get_expr_table(void){
    //  R(0) = reduce binary operator (like 1+1 or 2*1)
    //  0 expr      1 +-    2 */    3 eos   4 .     6 =
    static state_table expr_table = {
        {N,         1,      2,      A,      5,      7},                         //STATE 0: expr
        {3,         N,      N,      N,      N,      N},                         //STATE 1: expr +-
        {4,         N,      N,      N,      N,      N},                         //STATE 2: expr */

        {N,         R(0,0), S(2),   R(0,0), S(5),   N},                         //STATE 3: expr +- expr
        {N,         R(0,0), R(0,0), R(0,0), S(5),   N},                         //STATE 4: expr */ expr

        {6,         N,      N,      N,      N,      N},                         //STATE 5: expr .
        {N,         R(0,0), R(0,0), R(0,0), N,      N},                         //STATE 6: expr . expr

        {8,         N,      N,      N,      N,      N},                         //STATE 7: expr =
        {N,         R(0,0), R(0,0), R(0,0), N,      N},                         //STATE 8: expr = expr
    };
    return &expr_table;
}