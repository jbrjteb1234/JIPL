#include <stdlib.h>
#include <stdio.h>

#include "ast.h"
#include "../../utility/safe_memory.h"


void assign_ast_node_type(ASTNode* node, token** current_lookahead){

    if(node->type != NONE_AST_TYPE){
        return;
    }

    if(current_lookahead == NULL || *current_lookahead == NULL){
        perror("Tried to assign type to AST node without token\n");
        return;
    }

    switch( (*current_lookahead)->token_type ){
        case RESERVED_WORD:
            printf("Reserved word in assign_ast_node_type\n");
            break;
        case OPERATOR:



            break;
        case DELIMITER:

            printf("Delimiter in assign_ast_node_type\n");

            break;
        case STRING_LITERAL:

            node->type = LEAF_NODE;
            node->value.leaf_node_value = STR_NODE;

            break;
        case INT_VALUE:

            node->type = LEAF_NODE;
            node->value.leaf_node_value = INT_NODE;

            break;
        case IDENTIFIER:

            node->type = LEAF_NODE;
            node->value.leaf_node_value = ID_NODE;

            break;
    }
}
