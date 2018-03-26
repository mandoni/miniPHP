myscanner: myscanner.c myscanner.h lex.yy.c
	cc myscanner.c lex.yy.c -ll -o myscanner 
	./miniPHP <config.ini

lex.yy.c: myscanner.l
	lex myscanner.l

clean:
	rm myscanner
	rm lex.yy.c

php_reserved : __HALT_COMPILER()
php_reserved : ABSTRACT
php_oarithmetic : *
php_logico : AND
php_types : $a = -3/43;
php_types : $hola = 'sds3234_32';
php_identify : $mes_2015;
php_variable : $fd = 'hola';
php_constant : define("constante", "hola");
php_constant : Const nombre = 'constante';
php_pre_variable : $GLOBALS
php_comment : //Comentario uno
php_comment : #console comentario
php_db : $recordset['AES_ES']
	
"php_reserved"		return RESERVED;
"php_oarithmetic"	return OARITH;
"php_logico"		return LOGICOP;
"php_types"			return TYPES;
"php_identify"		return IDENTIFY; 
"php_variable"		return VARIABLE;
"php_constant"		return CONSTANT;
"php_structure"		return STRUCTURE;
"php_pre_variable"	return PREVARIABLE;
"php_comment"		return COMMENT;
"php_db"			return DB;
"php_function"		return FUNCTION;