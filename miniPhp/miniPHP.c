#include <stdio.h>
#include "miniPHP.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "php_reserved", "php_oarithmetic", "php_logico", "php_types", "php_variables"};

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
		case VARIABLES: 
			if(vtoken != VARIABLES_EXPRESS){
				printf("Syntax error in line %d, Expected a variable definition but found %s\n", yylineno, yytext);
				return 1;
			}
			printf("%s is a variable definition\n", yytext);
			break;
		default:
			printf("Syntax error in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}
