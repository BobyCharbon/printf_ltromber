#include <stdio.h>
#include <unistd.h>

int main (void)
{
	int char c;
	c = 'c';
	ft_printf(c);
}

int ft_printf(char *str, ...)
{
	int i = 0;
	int ret = 0;

	while(str[i] != '\0')
	{
		if(str[i] != '%')
			ret += write(1, str[i], sizeof(str));
		else
			i++;
	}
	i++;
}