#include <stdio.h>
#include "miniPHP.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "php_reserved", "php_oarithmetic", "php_logico", "php_types", "php_identify",
"php_structure"};

int main(void) 
{
	FILE * myFile;
	myFile = fopen("config.out", "a");
	if(myFile == NULL)return -1;

	//fprintf(myFile, "Salida");

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken) {
		printf("%d\n", ntoken);
		if(yylex() != COLON) {
			fprintf(myFile, "Syntax error in line %d, Expected a ':' but found %s\n", yylineno, yytext);
			return 1;
		}
		vtoken = yylex();

		//Switch 
		switch (ntoken) {
		case RESERVED: 
			if(vtoken != WORD_RESERVED){
				fprintf(myFile, "Syntax error in line %d, Expected a reserved word but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s includes the reserved word %s\n", names[ntoken], yytext);
			break;
		case OARITH: 
			if(vtoken != ARITHMETIC_OPERATOR){
				fprintf(myFile, "Syntax error in line %d, Expected an operator but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is an arithmetic operator\n", yytext);
			break;
		case LOGICOP: 
			if(vtoken != LOGIC_OPERATOR){
				fprintf(myFile, "Syntax error in line %d, Expected a logic operator but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a logic operator\n", yytext);
			break;
		case TYPES: 
			if(vtoken != TYPES_EXPRES){
				fprintf(myFile, "Syntax error in line %d, Expected a type definition but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a type definition\n", yytext);
			break;
		case IDENTIFY: 
			if(vtoken != IDENTIFY_EXPRESS){
				fprintf(myFile, "Syntax error in line %d, Expected an identify definition but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is an identify\n", yytext);
			break;
		case VARIABLE: 
			if(vtoken != TYPES_EXPRES){
				fprintf(myFile, "Syntax error in line %d, Expected a variable definition but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct variable\n", yytext);
			break;
		case CONSTANT: 
			if(vtoken != CONSTANT_EXPRESS){
				fprintf(myFile, "Syntax error in line %d, Expected a constant definition but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct constant\n", yytext);
			break;
		case STRUCTURE: 
			if(vtoken != STRUCTURE_EXPRESS){
				fprintf(myFile, "Syntax error in line %d, Expected a structure definition but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct structure definition\n", yytext);
			break;
			case PREVARIABLE: 
			if(vtoken != PREDETERMINATE_VARIABLE){
				fprintf(myFile, "Syntax error in line %d, Expected a predeterminate variable but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct variable\n", yytext);
			break;
			case COMMENT: 
			if(vtoken != COMMENT_EXPRESS){
				fprintf(myFile, "Syntax error in line %d, Expected a predeterminate comment but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct comment expression\n", yytext);
			break;
			case DB: 
			if(vtoken != DB_ACCESS){
				fprintf(myFile, "Syntax error in line %d, Expected a db access but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct db access expression\n", yytext);
			break;
			case FUNCTION: 
			if(vtoken != FUNCTION_DEFINITION){
				fprintf(myFile, "Syntax error in line %d, Expected a function definition but found %s\n", yylineno, yytext);
				return 1;
			}
			fprintf(myFile, "%s is a correct function definition\n", yytext);
			break;
		default:
			fprintf(myFile, "Syntax error in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	fclose(myFile);
	return 0;
}
