#include "main.h"

/**
 * 
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
        return;       
        }
        else
        {
        if (format[i] == 's')
        {
            char *str;
            int j;

            str = va_arg(args, char *);
            
            for (j = 0; str[j] != '\0'; j++)
            {       
                write(1, &str[j], 1);
                lenght++;       
            }       
        }else if (format[i] == 'c')
        {
            char c;
            c = va_arg(args, int);
            write(1, &c, 1);
            lenght++;
        }else if (format[i] == '%')
        {   
            write(1, &format[i], 1);
            lenght++;
        }else
        {
            write(1, &format[i], 1);
            lenght++;
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
