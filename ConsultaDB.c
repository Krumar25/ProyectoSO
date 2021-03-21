#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	int id;
	char user[20]; 
	char password[20]; 
	char email[40];
	char idss[3];
	int i;
	char consulta [80];
	
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "gamedb",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	

	for (i=0; i<4; i++) {
		printf ("Escribe tu id, usuario, contraseña y email separados por un blanco para crear una cuenta\n");
		err = scanf ("%d %s %s %s", &id, user, password, email);
		if (err!=4) {
			printf ("Error al introducir los datos \n");
			exit (1);
		}
		
		strcpy (consulta, "INSERT INTO players VALUES ('");
		
		sprintf(idss, "%d", id);
		strcat (consulta, idss);
		strcat (consulta, "','");
		
		strcat (consulta, user); 
		strcat (consulta, "','");
		
		strcat (consulta, password); 
		strcat (consulta, "','");
		
		strcat (consulta, email); 
		strcat (consulta, "');");
		
		printf("consulta = %s\n", consulta);
		
		err = mysql_query(conn, consulta);
		if (err!=0) {
			printf ("Error al introducir datos la base %u %s\n", 
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
	}
	
	mysql_close (conn);
	exit(0);
}
