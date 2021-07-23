
#include "process_packet.h"


void print_icmp(const unsigned char *packet, int size_iphh)
{

    struct icmphdr *icmphh;

    icmphh = (struct icmphdr *)(
        packet
        + sizeof(struct ethhdr)
        + size_iphh
        );
    
    
    char type_icmp[255];
    
    switch(icmphh->type)
    {
        case ICMP_ECHOREPLY:
            strcpy(type_icmp, "ECHO REPLY");
            break;
        case ICMP_ECHO:
            strcpy(type_icmp, "ECHO REQUEST");
            break;
        
        case ICMP_TIME_EXCEEDED:
            strcpy(type_icmp, "TIME EXCEEDED");
            break;
        default:
            strcpy(type_icmp, "ECHO");
            break;
    }
    
    
    printf("\t\e[93m[ICMP]\e[0m\n");
    printf("\t\e[93m==>\e[0m\ttype :\t\e[35m%d\e[0m\t||\t\e[35m%s\e[0m\n", \
        icmphh->type,
        type_icmp
    );
    printf("\t\e[93m==>\e[0m\tCode :\t\e[35m%d\e[0m\n",icmphh->code);
    printf("\t\e[93m==>\e[0m\tChecksum :\t\e[35m%d\e[0m\n",ntohs(icmphh->code) );

    putchar('\n');

}