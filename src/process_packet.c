
#include "process_packet.h"


//printf("\e[34m[INFO]\e[0m\tstrart sniffing on device => %s \n", device);


void process_packet(unsigned char *args, const struct pcap_pkthdr *cap_header, \
                     const unsigned char *packet)
{
    struct ethhdr *ethh;
    struct iphdr *iphh;
    int size_iphh;

    ethh = (struct ethhdr *) packet;
    iphh = (struct iphdr *) (packet + sizeof(struct ethhdr) );
    size_iphh = iphh->ihl * 4;

    printf("\e[34m[INFO]\e[0m\tNew packet sniffing size => %d  \n", cap_header->len);

    print_ethernet(ethh);
    print_iphdr(iphh);

    //show RFC790 to show equivalent
    switch(iphh->protocol)
    {
        case 1: //ICMP
            print_icmp(packet, size_iphh);
            break;
        case 6: //TCP
            print_tcp(packet, size_iphh);
            break;
    

        case 17: //UDP
            print_udp(packet, size_iphh);
            break;
/*
        default: //other 
            printf("");
            //print_Other();
            break;
            */
    }

    dump(packet, cap_header->len);
    putchar('\n');
}