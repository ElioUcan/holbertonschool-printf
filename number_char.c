#include "main.h"

/**
 * p_numbers - Calculates the number
 * @num: int
 * Return: int
 */

int p_numbers(int num)
{
int len;
unsigned int n;
char c;


len = 0;
if (num < 0)
{
write(1, "-", 1);
len++;
n = -num;
}
else
{
n = num;
}
if (n > 9)
{
len += p_numbers(n / 10);
}
c = (n % 10) + '0';
write(1, &c, 1);
len++;
return (len);
}



/**
 * _printf - Returns the lenght
 * @format: char
 * Return: int
 */


int _printf(const char *format, ...)
{
va_list args;
int i = 0;
int lenght = 0;

va_start(args, format);


for (i = 0; format[i] != '\0'; i++)
{
    if (format[i] == '%')
    {
        i++;
        if (format[i] == '\0')
        {
        return (-1);       
        }
        else
        {
        if (format[i] == 's')
        {
            char *str;
            int j;

            str = va_arg(args, char *);
            if (str == NULL)
            {
            str = "(null)";
            }
            for (j = 0; str[j] != '\0'; j++)
            {       
                write(1, &str[j], 1);
                lenght++;       
            }
           
        }
        else if (format[i] == 'c')
        {
            char c;
            c = va_arg(args, int);
            write(1, &c, 1);
            lenght++;

        }
        else if (format[i] == '%')
        {   
            write(1, &format[i], 1);
            lenght++;
        }
        else if (format[i] == 'd' || format[i] == 'i')
        {
            int num;
            num = va_arg(args, int);
            lenght += p_numbers(num);
        }
        else
        {
            write(1, "%", 1);
            write(1, &format[i], 1);
            lenght+=2;
        }
        }
    }
    else
    {
        write(1, &format[i], 1);
        lenght++;
    }
}


va_end(args);
return (lenght);
}
