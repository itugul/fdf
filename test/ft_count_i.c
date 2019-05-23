
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

char			ft_count_i(char **str, const char *delim, int *i)
{
	char	*d;
	char	ret;
	char	a;
	int 	b;

	ret = 0;
	b = 0;
	ret = ft_strnew(2);
	d = ft_strnew(100);
	ret = 126;
	if (!*str)
		return (NULL);
	printf("str = %c\n", *str);
	printf("delim = (%s)\n", delim);
	a = ft_strchr(delim, **str);
	printf("!!![%d]\n", a);
	while (*str && (a = ft_strchr(delim, **str)) != -1)
	{
		*str += 1;
		printf("1)SOSAT ! [%d]\n", a);
		ret = a < ret ? a : ret;
		printf("2)SOSAT ! [%d]\n", ret);
	}
	if (!*str)
		return (NULL);
	// b = *i;
	while (*str && ft_strchr(delim, **str) == -1 && ++*str)
	{
		printf("%s\n","KRIVORUKIE GOVNOEDI");
		b++;
	}
	printf("i = %d\n", b);
	*i = b;
	return(ret);
}
