
#include "process_packet.h"



void print_ethernet(struct ethhdr *ethh)
{
    char colors[] = "[34m"; 

    printf("\t\e[36m[ETHERNET]\e[0m\n");
    printf("\t\e[36m==>\e[0m\tfrom :\t\e[35m%.2X:%.2X:%.2X:%.2X:%.2X:%.2X\e[0m\n", 
        ethh->h_source[0], 
        ethh->h_source[1], 
        ethh->h_source[2], 
        ethh->h_source[3], 
        ethh->h_source[4], 
        ethh->h_source[5]
        );
    printf("\t\e[36m==>\e[0m\tto :\t\e[35m%.2X:%.2X:%.2X:%.2X:%.2X:%.2X\e[0m\n", 
        ethh->h_dest[0], 
        ethh->h_dest[1], 
        ethh->h_dest[2], 
        ethh->h_dest[3], 
        ethh->h_dest[4], 
        ethh->h_dest[5]
    );
    printf("\t\e[36m==>\e[0m\tProtocol :\t\e[35m%u\e[0m\n", ethh->h_proto);

    putchar('\n');
}