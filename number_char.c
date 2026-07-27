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
        if (format[i] == 's')
        {
            char *str;
            int j;

            str = va_arg(args, char *);
            
            for (j = 0; str[j] != '\0'; j++)
            {       
                lenght++;       
            }       
        }
        else
        {
            lenght++;
        }
    }
    else
    {
        lenght++;
    }
}


va_end(args);
return (lenght);
}
