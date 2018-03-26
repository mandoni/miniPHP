Analizador de léxico: miniPHP
Proyecto 1: Lenguajes formales y autómatas
1235615: Andoni Zamora Hernández 

El analizador de léxico miniPHP funciona de la siguiente manera:
Al ser una analizador de léxico y no el intérprete del lenguaje PHP como tal, se crearon ciertas 
etiquetas especificadas en el archivo makefilepara acceder a cada corrección del analizador. Estas
se deben anteponer a cada una de las once estructuras solicitadas en el enunciado del proyecto.
Se coloca ':' para dar paso a la expresión a ser evaluada. 
Internamente se analiza la etiqueta la cual otorga determinado token a la expresión que se 
solicitó y luego se analiza esa expresión con las expresiones regulares especificadas en el archivo
MyRegEx.txt.
Al encontrar un error en el léxico del programa se procede a escribir el punto en donde el token 
deja de ser válido y se especifican los carácteres no válidos. 
Si la expresión no tiene ningun valo válido o le hace falta un caracter para ser válida, no se 
especificará y se escribirá un mensaje de error en el archivo de salida. 
Todas estas especificaciones mencionadas se almacenaran en un archivo con extención .out.

Es robusto pues utiliza etiquetas para enviar a validar los tokens. Esto fue implementado de esta 
manera pues no estamos leyendo un archivo de php sino estamos analizando el léxico de ese lenguaje.
