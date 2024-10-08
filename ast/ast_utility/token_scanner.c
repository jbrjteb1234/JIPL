#include <stdio.h>
#include <stdlib.h>
#include "token_scanner.h"
#include "ast.h"

/** Move to next token in tokenstream
 * 
 */
void advance_token(token** scan_token){
    if((*scan_token)->next != NULL){
        (*scan_token) = (*scan_token)->next;
    }else{
        //perror("Tried to advance past end of tokenstream\n");
    }
}

/** converts token directly from tokenstream into an AST node
 *  adds AST node to the stack for reduction
 */
void push_token_into_ast_node(table_iterator* iterator, token** current_lookahead, bool auto_assign){
    if (current_lookahead == NULL){
        return;
    }

    ASTNode* new_ast_node = acquire_from_pool(iterator->node_pool);

    if(auto_assign){
        assign_ast_node_type(new_ast_node, current_lookahead);
    }else{
        new_ast_node->type = NONE_AST_TYPE;
    }


    push(iterator->node_stack, new_ast_node, false);
}