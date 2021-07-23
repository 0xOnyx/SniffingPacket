
#include "process_packet.h"


void print_tcp(const unsigned char *packet, int size_iphh)
{
    struct tcphdr *tcphh;

    tcphh = (struct tcphdr*)(packet + size_iphh + sizeof(struct ethhdr));

    printf("\t\e[93m[TCP]\e[0m\n");
    printf("\t\e[93m==>\e[0m\tSource Port :\t\e[35m%d\e[0m\n", ntohs(tcphh->source) );
    printf("\t\e[93m==>\e[0m\tDestination Port :\t\e[35m%u\e[0m\n",ntohs(tcphh->dest) );
    printf("\t\e[93m==>\e[0m\tSequence :\t\e[35m%u\e[0m\n",ntohl(tcphh->seq) );
    printf("\t\e[93m==>\e[0m\tAcknowledgement :\t\e[35m%u\e[0m\n",ntohl(tcphh->ack_seq) );
    printf("\t\e[93m==>\e[0m\tHeader length DWORD:\t\e[35m%u\e[0m \
                        \tHeader length Bytes:\t\e[35m%u\e[0m\n",
        tcphh->doff,  tcphh->doff *4);
    printf("\t\e[93m==>\e[0m\tURG Flag :\t\e[35m%d\e[0m\n", tcphh->urg );
    printf("\t\e[93m==>\e[0m\tURG Flag :\t\e[35m%d\e[0m\n", tcphh->ack );
    printf("\t\e[93m==>\e[0m\tPUSH Flag :\t\e[35m%d\e[0m\n", tcphh->psh );
    printf("\t\e[93m==>\e[0m\tRST Flag :\t\e[35m%d\e[0m\n", tcphh->rst );
    printf("\t\e[93m==>\e[0m\tSYNC Flag :\t\e[35m%d\e[0m\n", tcphh->syn );
    printf("\t\e[93m==>\e[0m\tFIN Flag :\t\e[35m%d\e[0m\n", tcphh->fin );
    printf("\t\e[93m==>\e[0m\tWindows Flag :\t\e[35m%d\e[0m\n",ntohs(tcphh->window) );
    printf("\t\e[93m==>\e[0m\tChecksum Flag :\t\e[35m%d\e[0m\n",ntohs(tcphh->check) );
    printf("\t\e[93m==>\e[0m\tUrgent Pointer :\t\e[35m%d\e[0m\n", tcphh->urg_ptr );

    putchar('\n');
}