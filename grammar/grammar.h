#ifndef GRAMMAR
#define GRAMMAR

//different types of operator commands
typedef enum{
    ADDITION        =0,
    SUBTRACTION     =1,
    MULTIPLICATION  =2,
    DIVISION        =3,
    ASSIGNMENT      =4,
    EQUIVALENT      =5,
    NOT_EQUIVALENT  =6,
    LESS_THAN       =7,
    GREATER_THAN    =8,
    GREATER_OR_EQUAL=9,
    LESS_OR_EQUAL   =10,
} operator_token;

//different types of reserved word commands
typedef enum{
    IF,
    ELSE,
    WHILE,
    RETURN
} reserved_word_token;

typedef enum{
    EOS,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_CBRACKET,
    CLOSE_CBRACKET,
} delimiter_token;

//The token value - could be an enum for operators or reserved words, or a variable value
typedef union{
    operator_token          operator_token_value;
    reserved_word_token     reserved_word_token_value;
    delimiter_token         delimiter_token_value;
    int                     identifier_token_value;
    void*                   variable_value;               
} token_values;

//describes the type of commands
typedef enum {
    RESERVED_WORD,
    OPERATOR,
    DELIMITER,
    STRING_LITERAL,
    INT_VALUE,
    IDENTIFIER
} token_types;

#define DELIMITER_SYMBOL ";"

//  LEXEME              TOKEN VALUE         TOKEN TYPE 
#define DEFINE_TOKENS \
    X("=",              ASSIGNMENT,         operator_token_value, OPERATOR) \
    X("==",             EQUIVALENT,         operator_token_value, OPERATOR)  \
    X("<",              LESS_THAN,          operator_token_value, OPERATOR)  \
    X(">",              GREATER_THAN,       operator_token_value, OPERATOR)  \
    X("=<",             LESS_OR_EQUAL,      operator_token_value, OPERATOR)  \
    X(">=",             GREATER_OR_EQUAL,   operator_token_value, OPERATOR)  \
    X("+",              ADDITION,           operator_token_value, OPERATOR)  \
    X("-",              SUBTRACTION,        operator_token_value, OPERATOR)  \
    X("*",              MULTIPLICATION,     operator_token_value, OPERATOR)  \
    X("/",              DIVISION,           operator_token_value, OPERATOR)  \
    X("{",              OPEN_CBRACKET,      delimiter_token_value, DELIMITER)  \
    X("}",              CLOSE_CBRACKET,     delimiter_token_value, DELIMITER)  \
    X("(",              OPEN_BRACKET,       delimiter_token_value, DELIMITER)  \
    X(")",              CLOSE_BRACKET,      delimiter_token_value, DELIMITER)  \
    X(DELIMITER_SYMBOL, EOS,                delimiter_token_value, DELIMITER)  \
    X("if",             IF,                 reserved_word_token_value, RESERVED_WORD)  \
    X("else",           ELSE,               reserved_word_token_value, RESERVED_WORD)  \
    X("while",          WHILE,              reserved_word_token_value, RESERVED_WORD)  \
    X("return",         RETURN,             reserved_word_token_value, RESERVED_WORD)

#endif