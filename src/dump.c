
#include "dump.h"


void dump(const unsigned char *buff, unsigned int lenght)
{
    unsigned char bytes;

    unsigned int i;
    i = 0;

    printf("\t\e[93m[DUMP DATA]\e[0m\n");
    putchar('\n');
    putchar('\t');

    while(i < lenght)
    {
        bytes = buff[i];
        printf("%02x ", bytes);
        if( (i%16) == 15  ||  i == (lenght-1) )
        {
            unsigned int j;
            j = 0;

            while(j < 15-(i%16))
            {
                printf("   ");
                j++;
            }
            putchar('|');

            j = i-(i%16);

            printf("\e[35m");
            while(j < i)
            {
                bytes = buff[j];

                if( (bytes > 31) && (bytes < 127) )
                    printf("%c", bytes);
                else
                    putchar('.');

                j++;    
            }
            printf("\e[0m");


            putchar('\n');
            putchar('\t');

        } 

        i += 1;
    }
    putchar('\n');
}
