
#include "process_packet.h"


void print_udp(const unsigned char *packet, int size_iphh)
{
    struct udphdr *udphh;

    udphh = (struct udphdr*)(packet + size_iphh + sizeof(struct ethhdr));

    printf("\t\e[93m[UDP]\e[0m\n");
    printf("\t\e[93m==>\e[0m\tSource Port :\t\e[35m%d\e[0m\n", ntohs(udphh->source) );
    printf("\t\e[93m==>\e[0m\tDestination Port :\t\e[35m%u\e[0m\n",ntohs(udphh->dest) );
    printf("\t\e[93m==>\e[0m\tLenght Header :\t\e[35m%u\e[0m\n",ntohs(udphh->len) );
    printf("\t\e[93m==>\e[0m\tChecksum :\t\e[35m%u\e[0m\n",ntohs(udphh->check) );

    putchar('\n');
}