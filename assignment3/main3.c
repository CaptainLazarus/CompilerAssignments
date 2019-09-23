# include <stdio.h>
# include <stdlib.h>
// CONSTANTS
#define RESET 0x00
#define SYM_TERMINATE 	111
#define SYM_CONTEXT_ST 	112
#define SYM_CONTEXT_EN 	113
#define SYM_NUMERIC 	121
#define SYM_OPERATOR 	131
#define SYM_VARIABLE	141
#define FLAG_CATEGORY 	0b10000
#define FLAG_VALUE 	0b01000
#define FLAG_TYPE 	0b00100
#define FLAG_LEFT 	0b00010
#define FLAG_RIGHT 	0b00001

// GLOBAL VARIABLES
int g_SYM_TYPE = RESET;
char g_token;
int name_ctr = 0;
// Definition of Abstract Search Tree
typedef struct ASTree{
	char category;
	int value;
	int type;
	struct ASTree *left;
	struct ASTree *right;
	int flag;
}AST;

// Definition of Scanner
int scanner(int *val, char *ch){
	int ret_value = RESET;	
	scanf("%c", ch);
	// CHECK FOR TERMINATOR
	switch(*ch){
		case 42: case 43:  case 45:  case 47: 
			ret_value = SYM_OPERATOR;
			break;		
		case 48: case 49: case 50: case 51: case 52:
		case 53: case 54: case 55: case 56: case 57:
			*val = (*ch)-48 ; 
			ret_value = SYM_NUMERIC;
			break;
		case 40: 
			ret_value = SYM_CONTEXT_ST;
			break;	
		case 41:
			ret_value = SYM_CONTEXT_EN;
			break;			
		case 10: case 13:
			ret_value = SYM_TERMINATE;
			break;
		default: 
				return SYM_VARIABLE;
		}
	return ret_value;
}

AST *create_node(int type){
	AST *node;
	node = (AST *)malloc(sizeof(AST));
	if( node == NULL) printf("No mem left");
	else {
		node -> flag = RESET;
		node -> type = type;
		return node;
	}
	return NULL;
}

// Definition of Parser
AST *parser(AST *node, int SYM_status){
	g_SYM_TYPE = SYM_status;
	// Creating var
	int token_type, token_value;
	char token;
	SCAN:
	token_type = scanner(&token_value, &token);
	
	switch(token_type){
		case SYM_CONTEXT_ST:
			if(g_SYM_TYPE == RESET){	
				node = create_node(RESET);
				node -> type = SYM_OPERATOR;
				g_SYM_TYPE = SYM_OPERATOR;
			}
			else{
				if (!(node->flag & FLAG_LEFT)){
						node->flag = (node->flag) | FLAG_LEFT;
						//printf("HERE %d", token_type);
						node->left = parser(create_node(SYM_OPERATOR), token_type);
						g_SYM_TYPE = node->type;
				}
				else if (!(node->flag & FLAG_RIGHT)){
						node->flag = (node->flag) | FLAG_RIGHT;
						node->right = parser(create_node(SYM_OPERATOR), token_type);
						g_SYM_TYPE = node->type;
				}
			}	
		break;
		case SYM_VARIABLE:
				{				
					AST *child_Node = create_node(token_type);
					child_Node -> category = token;
					child_Node -> flag = (child_Node -> flag) | FLAG_TYPE | FLAG_CATEGORY;
					if (!(node->flag & FLAG_LEFT)){
							node->flag = (node->flag) | FLAG_LEFT;
							node->left = child_Node;
					}
					else if (!(node->flag & FLAG_RIGHT)){
							node->flag = (node->flag) | FLAG_RIGHT;
							node->right = child_Node;
					}
				}
		break;
		case SYM_NUMERIC:
				if(g_SYM_TYPE != SYM_NUMERIC){
					AST *child_Node = create_node(token_type);
					child_Node -> value = token_value;
					child_Node -> flag = (child_Node -> flag) | FLAG_TYPE | FLAG_VALUE;
					if (node == NULL){
						node = child_Node;
						g_SYM_TYPE = SYM_NUMERIC;
						goto SCAN; 
					}
					if (!(node->flag & FLAG_LEFT)){
							node->flag = (node->flag) | FLAG_LEFT;
							node->left = parser(child_Node, token_type);
					}
					else if (!(node->flag & FLAG_RIGHT)){
							node->flag = (node->flag) | FLAG_RIGHT;
							node->right = parser(child_Node, token_type);
					}
					if(g_SYM_TYPE == SYM_OPERATOR){
						g_SYM_TYPE = node ->type;
						token = g_token;
						goto sw_SYM_OPERATOR;
					}
					if(g_SYM_TYPE == SYM_CONTEXT_EN){
						g_SYM_TYPE = node ->type;
						goto sw_SYM_CONTEXT_EN;
					}
				}
				else if(token_type == SYM_NUMERIC){
					node -> value *= 10;
					node -> value += token_value;
				}
				else if(token_type == SYM_OPERATOR){
					g_token = token;
					goto END;
				}
		break;
		sw_SYM_OPERATOR:
		case SYM_OPERATOR:
				if(g_SYM_TYPE == SYM_NUMERIC){
					g_SYM_TYPE = SYM_OPERATOR;
					g_token = token;
					goto END;
				}
				node->category = token;
				node->flag = (node->flag) | FLAG_CATEGORY;
			break;
		sw_SYM_CONTEXT_EN:
		case SYM_CONTEXT_EN:	
			g_SYM_TYPE = token_type;
			goto END;
		
		//DEV PURPOSE//
		case SYM_TERMINATE:
			if( g_SYM_TYPE == SYM_NUMERIC) goto END;
	}
	goto SCAN;
	END:
	return node;
}


// Function for interpretor
int interpretor(AST *node){
	if(node == NULL) return 0;
	else{
		int left_operand, right_operand, result;
		left_operand = interpretor(node->left);
		right_operand = interpretor(node->right);
		if( node -> type == SYM_OPERATOR){
			switch(node->category){
				case '+': result = left_operand + right_operand;
		break;	case '-': result = left_operand - right_operand;
		break;	case '/': result = left_operand / right_operand;
		break;	case '*': result = left_operand * right_operand;			
			}
		}
		else if (node ->type == SYM_VARIABLE){
			printf("%c:", node->category);
			scanf("%d", &result);
		}
		else if (node ->type == SYM_NUMERIC){
			result = node -> value;
		}
		return result;
	}	
}

// Function to delete branch
void deleteAST(AST *node){
	if( node == NULL)
		return;
	else{
		deleteAST(node->left);
		deleteAST(node->right);
		free(node);
		node = NULL;
	}
}

int main(){
	// Variable Initializations
	AST *root = NULL;
	root = parser(root, RESET);
	printf("Value: %d", interpretor(root));
	deleteAST(root);
	printf("\n\n");
	return 0;
}
