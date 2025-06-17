#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int i = 0;

    if (!str)
        return ft_putstr("(null)");
    while (str[i])
        ft_putchar(str[i++]);
    return i;
}

int ft_putnbr(int n)
{
    int count = 0;

    if (n < 0)
    {
        count += ft_putchar('-');
        if (n == -2147483648)
        {
            count += ft_putchar('2');
            n = -147483648;
        }
        n = -n;
    }
    if (n >= 10)
        count += ft_putnbr(n / 10);
    count += ft_putchar(n % 10 + '0');
    return count;
}

int ft_puthex(unsigned int n)
{
    int count = 0;
    char *hex = "0123456789abcdef";

    if (n >= 16)
        count += ft_puthex(n / 16);
    count += ft_putchar(hex[n % 16]);
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd')
                count += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'x')
                count += ft_puthex(va_arg(args, unsigned int));
            else
                count += ft_putchar(format[i]);
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return count;
}
