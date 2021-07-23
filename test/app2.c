#include <arpa/inet>
#include <stdio.h>
#include <string.h>
#include <pcap.h>
#include <stdlib.h>
#include "dump.h"

#define PACKET_SIZE 4096

void fail_libcap(const char *err, const char *errLibcap)
{
  char buffererror[250];
  strcpy(buffererror, "[FAIL]\t fail to ");
  strncat(buffererror, err, 50);
  strncat(bufererror, errLibcap, 100);
  
  puts(buffereerror)
  putchar('\n');

  exit(1);
}


void print_ether(struct ethhdr *ethh)
{
  putchar('\n');
  puts("[ETHERNET] =>");
  printf("\t\tfrom : %s ", ethh->h_source);
  printf("\t\tto : %s", ethh->h_dest);
  printf("\t\tpacket ID : %d", ethh->h_proto);
}

void usage(char *current_directory)
{
  printf("Usage => \n\t$: %s <Nbr packet to capture use -1 ton unlimited>", current_directory);
  exit(1);
}

void print_iphdr(struct iphdr *iph)
{
  struct sockaddr_in ip_addr;
  memset(&ip_addr, 0, sizeof(struct ip_addr));
  ip_addr.sin_addr.s_addr = iph->saddr;

  putchar('\n');
  puts("[IP] =>");
  printf("\t\tfrom : %s\n", inet_ntoa(ip_addr.sin_addr) );
  ip_addr.sin_addr.s_addr = iph->saddr;
  printf("\t\tto: %s\n", inet(ip_addr.sin_addr));
  printf("\t\tIP version: %d\n", iph->version);
  printf("\t\tIP length Header: %d\n", iph->ihl);
  printf("\t\tIP length Dword: %d\n", iph->ihl * 4);
  printf("\t\tIP TTL: %d\n", iph-> ttl);
  printf("\t\tIP Protocol: %d\n", iph->protocol);
}

void print_icmp_packet(const u_char *buffer, int size)
{
  struct icmphdr *icmp;
  icmp = (struct icmphdr*)(buffer + sizeof(struct ethh) + size);
  putchar('\n');
  puts("[ICMP PACKET] => ");
  printf();

}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
  int packet_size = header->len;
  int size;

  struct ethhdr *ethh;
  struct iphdr *iph;

  ethh = (struct ethhdr *) buffer;
  iph = (struct iphdr*)(buffer + sizeof(struct ethhdr) );
  
  print_ether(ethh);
  print_iphdr(iph);
  
  size = iph->ihl * 4;

  switch(iph->protocol)
  {
    case 1:
        print_icmp_packet(buffer, size);  
      break;

    case 6:
        print_tcp_packet(buffer, size);
      break;

    case 17:
        print_udp_packet(buffer, size);
      break;
  }
}

int main(int argc, char **argv)
{
  struct pcap_pkthdr header;
  const unsigned char *packet; 
  int nbr_packet;

  pcap_if_t *devices;
  char *device;

  char errbuff[PCAP_ERRBUF_SIZE];

  if(argc < 2)
    usage(argv[0]);

  nbr_packet = atoi(argv[1]);

  
  if( pcap_findalldevs(&devices, errbuff) != 0)
    fail_libcap("found device to capture", errbuff);
  
  device = device->name;

  if(device == NULL)
    fail_libcap("device is not name", errbuff);

  pcap_handle = pcap_open_live(device, PACKET_SIZE, 1, 0, errbuff)

  if(pcap_handle == NULL)
     fail("open device", errrbuff);
}
