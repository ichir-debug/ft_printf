#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list ap;
    int count;
    
    count = 0;
    if(!check_format(format))
        return count;
    va_start(ap, format);
    while(*format)
    {
        if(*format == '%')
            ft_conv_type(ap, *format)
        else
            ft_print_char(*format);
        count++;
        format++;
    }
    va_end(ap);
}

int check_format(char* s)
{
    char *conversions = "cspdiuxX\%";
    int i;

    while(*s)
    {
        if(*s++ == '%')
        {
            i = 0;
            while(conversions[i] && *s != conversions[i])
                i++;
            if(conversions[i] == '\0')
                return 0;
        }
        s++;
    }
    return 1;
}
void ft_conv_type(va_list *ap, char c)
{
    if(c == '\%')
        ft_print_char('\%');
    else if(c == 'c')
        ft_print_char(va_arg(*ap, int));
    else if(c == 's')
        ft_print_str(va_arg(*ap, char*));
    else if(c == 'p')
        ft_print_mem(va_arg(*ap, void*));
    else if(c == 'd' || c == 'i')
        ft_print_nbr(va_arg(*ap, int));
    else if(c == 'u')
        ft_print_unsigned(va_arg(*ap, unsigned int));
    else if(c == 'x' || c == 'X')
        ft_print_hex(va_arg(*ap, int));
}

ft_print_char(int c);// for %c and %%
ft_print_str(char *s);// for %s
ft_print_ptr(void *ptr);// for %p
ft_print_nbr(int n);// for %d and %i
ft_print_unsigned(unsigned int n);// for %u
ft_print_hex(int n);// for %x and %X



static size_t	ft_count_digit(long n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
	}
}

void	ft_print_nbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_print_nbr((nb / 10));
	ft_print_char((nb % 10) + '0');
}

int main()
{
    // int count = ft_printf("test %d, %d, %d\n", 1, 2, 3);
    // ft_printf("test %d, %d, %d\n", 1, 2, 3);
    printf("hello%");
}