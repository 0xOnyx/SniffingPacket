

#include "process_packet.h"

//   printf("\t\e[36m==>\e[0m\tProtocol :\t\e[35m%u\e[0m\n", ethh->h_proto);

void print_iphdr(struct iphdr *iphh)
{
    struct sockaddr_in from_addr;
    struct sockaddr_in to_addr;
    
    memset(&from_addr, 0,sizeof(from_addr));
    memset(&to_addr, 0, sizeof(to_addr));

    from_addr.sin_addr.s_addr = iphh->saddr;
    to_addr.sin_addr.s_addr = iphh->daddr;

    printf("\t\e[92m[IP]\e[0m\n");
    printf("\t\e[92m==>\e[0m\tfrom :\t\e[35m%s\e[0m\n", inet_ntoa(from_addr.sin_addr));
    printf("\t\e[92m==>\e[0m\tfrom :\t\e[35m%s\e[0m\n", inet_ntoa(to_addr.sin_addr));
    printf("\t\e[92m==>\e[0m\tVersion IP :\t\e[35m%u\e[0m\n", iphh->version  );
    printf("\t\e[92m==>\e[0m\tHeader length DWORD:\t\e[35m%u\e[0m \
                            \tHeader length Bytes:\t\e[35m%u\e[0m\n",
            iphh->ihl,  iphh->ihl *4);
    printf("\t\e[92m==>\e[0m\tTotale Length :\t\e[35m%u\e[0m\n",  ntohs(iphh->tot_len) );
    printf("\t\e[92m==>\e[0m\tType of service  :\t\e[35m%u\e[0m\n",  iphh->tos);
    printf("\t\e[92m==>\e[0m\tIdentification  :\t\e[35m%u\e[0m\n",  iphh->id);
    printf("\t\e[92m==>\e[0m\tTTL  :\t\e[35m%u\e[0m\n",  iphh->ttl);
    printf("\t\e[92m==>\e[0m\tProtocol  :\t\e[35m%u\e[0m\n",  iphh->protocol);
    printf("\t\e[92m==>\e[0m\tChecksum  :\t\e[35m%u\e[0m\n",  ntohs(iphh->check) );
    
    putchar('\n');

}