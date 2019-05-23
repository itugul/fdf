# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

int main()
{
	char *line;
	char *wrd;
	int  i;
	char ret;

	line = ft_strnew(10);
	wrd = ft_strnew(50);
	wrd = "lesha";
	line = "sonia";
	printf("%s\n", line);
	wrd = ft_strsub(line, 0, 3);
	printf("%s\n", wrd);
//	i = 0;
//	printf("(%c)\n", wrd[0]);
//	line = " ,  hello , hello\0";
	//ret = ft_count_i(&line, " ,", &i);
//	ret = ft_pars(&line, " ,", &wrd);
//	printf("%d\n", i);
//	printf("(%c)\n", ret);
//	printf("(WHY GOD WHY %s)\n", wrd);
	return(0);
}

