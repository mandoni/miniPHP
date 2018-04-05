Analizador de l�xico: miniPHP
Proyecto 1: Lenguajes formales y aut�matas
1235615: Andoni Zamora Hern�ndez 

El analizador de l�xico miniPHP funciona de la siguiente manera:
Al ser una analizador de l�xico y no el int�rprete del lenguaje PHP como tal, se crearon ciertas 
etiquetas especificadas en el archivo makefilepara acceder a cada correcci�n del analizador. Estas
se deben anteponer a cada una de las once estructuras solicitadas en el enunciado del proyecto.
Se coloca ':' para dar paso a la expresi�n a ser evaluada. 
Internamente se analiza la etiqueta la cual otorga determinado token a la expresi�n que se 
solicit� y luego se analiza esa expresi�n con las expresiones regulares especificadas en el archivo
MyRegEx.txt.
Al encontrar un error en el l�xico del programa se procede a escribir el punto en donde el token 
deja de ser v�lido y se especifican los car�cteres no v�lidos. 
Si la expresi�n no tiene ningun valo v�lido o le hace falta un caracter para ser v�lida, no se 
especificar� y se escribir� un mensaje de error en el archivo de salida. 
Todas estas especificaciones mencionadas se almacenaran en un archivo con extenci�n .out.

Es robusto pues utiliza etiquetas para enviar a validar los tokens. Esto fue implementado de esta 
manera pues no estamos leyendo un archivo de php sino estamos analizando el l�xico de ese lenguaje.
