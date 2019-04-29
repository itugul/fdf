#include <stdio.h>
#include "libft/libft.h"
 
char * mystrchr(const char * s, const char c) {
    while ( *s && *s != c )
        ++s;
    return ( *s ) ? (char*) s : NULL;
}

char * mystrtok(char * str, const char * delim) {
    static char * next;
    
    if ( str ) {
        next = str;
        while ( *next && mystrchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! mystrchr(delim, *next) )
        ++next;
    while ( *next && mystrchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}
 
#define DELIM " \t\n"
 
int main(void) {
    char buf[BUFSIZ], * p;
	int	i;


    while ( printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n' && printf("By words:\n") )
	{
		p = ft_strtok(buf, DELIM);
		while (p != NULL)
		{
			printf("%s\n", p);
			p = ft_strtok(NULL, DELIM);
		}
        // for ( p = mystrtok(buf, DELIM); p; p = mystrtok(NULL, DELIM) )
        // // for ( p = mystrtok(buf, DELIM); p; p = ' ' )
        //     printf("%s\n", p);
	}
    return 0;
}
