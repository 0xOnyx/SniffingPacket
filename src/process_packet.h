#ifndef PROCESS_PACKET_H
#   define PROCESS_PACKET_H

//raw scoket
#   include <pcap.h>

//ethernet Struct 
#   include <linux/if_ether.h>

//IP struct
#   include <netinet/ip.h>

//convert ip addr
#   include <arpa/inet.h>


//protocol 
#   include <netinet/ip_icmp.h>
#   include <netinet/udp.h>
#   include <netinet/tcp.h>

#   include <stdio.h>
#   include <string.h>

//dump data
#   include "dump.h"

void process_packet(unsigned char *args, const struct pcap_pkthdr *cap_header, \
                     const unsigned char *packet);

void print_ethernet(struct ethhdr *ethh);
void print_iphdr(struct iphdr *iphh);


//protocol
void print_icmp(const unsigned char *packet, int size_iphh);
void print_tcp(const unsigned char *packet, int size_iphh);
void print_udp(const unsigned char *packet, int size_iphh);

#endif