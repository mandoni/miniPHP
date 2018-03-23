#include <stdio.h>
#include "miniPHP.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "php_reserved", "php_oarithmetic", "php_logico", "php_types", "php_identify",
"php_structure"};

int main(void) 
{

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken) {
		printf("%d\n", ntoken);
		if(yylex() != COLON) {
			printf("Syntax error in line %d, Expected a ':' but found %s\n", yylineno, yytext);
			return 1;
		}
		vtoken = yylex();

		//Switch 
		switch (ntoken) {
		case RESERVED: 
			if(vtoken != WORD_RESERVED){
				printf("Syntax error in line %d, Expected a reserved word but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s includes the reserved word %s\n", names[ntoken], yytext);
			break;
		case OARITH: 
			if(vtoken != ARITHMETIC_OPERATOR){
				printf("Syntax error in line %d, Expected an operator but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is an arithmetic operator\n", yytext);
			break;
		case LOGICOP: 
			if(vtoken != LOGIC_OPERATOR){
				printf("Syntax error in line %d, Expected a logic operator but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is a logic operator\n", yytext);
			break;
		case TYPES: 
			if(vtoken != TYPES_EXPRES){
				printf("Syntax error in line %d, Expected a type definition but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is a type definition\n", yytext);
			break;
		case IDENTIFY: 
			if(vtoken != IDENTIFY_EXPRESS){
				printf("Syntax error in line %d, Expected an identify definition but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is an identify\n", yytext);
			break;
		case VARIABLE: 
			if(vtoken != TYPES_EXPRES){
				printf("Syntax error in line %d, Expected a variable definition but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is a correct variable\n", yytext);
			break;
		case CONSTANT: 
			if(vtoken != CONSTANT_EXPRESS){
				printf("Syntax error in line %d, Expected a constant definition but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is a correct constant\n", yytext);
			break;
		case STRUCTURE: 
			if(vtoken != STRUCTURE_EXPRESS){
				printf("Syntax error in line %d, Expected a structure definition but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is a correct structure definition\n", yytext);
			break;
		default:
			printf("Syntax error in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}
