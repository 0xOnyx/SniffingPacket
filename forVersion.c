
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dump.h"

#define PACKET_SIZE 4096
void fail(const char *err, const char *errLibcap)
{
  char bufferror[250];
  strcpy(bufferror, "[ERROR]\t fail to ");
  strncat(bufferror, err, 50);
  strcat(bufferror, ": ");
  strncat(bufferror, errLibcap, 100);
  
  puts(bufferror);
  putchar('\n');

  exit(1);
}

void usage(char *current_directory)
{
  printf("Usage => \n\t$: %s <Nbr packet to capture>\n", current_directory);
  exit(1);
}

int main(int argc, char **argv)
{
  int nbr_packet;

  if(argc < 2)
    usage(argv[0]);
  
  nbr_packet = atoi(argv[1]);

  struct pcap_pkthdr header;
   const unsigned char *packet;
  char errbuff[PCAP_ERRBUF_SIZE];

  pcap_if_t *devices;
  char *device;

  pcap_t *pcap_handle;

  if( pcap_findalldevs(&devices, errbuff) != 0)
    fail("found device to capture", errbuff);

  device = devices->name;

  if(device == NULL)
    fail("found device is empty", errbuff);

  pcap_handle = pcap_open_live(device, PACKET_SIZE, 1, 0, errbuff);

  if(pcap_handle == NULL)
    fail("open device", errbuff);
  
  int i;
  i = 0;

  printf("[INFO]\tstart Sniffing on device %s \n", device); 

  while(i < nbr_packet)
  {
    packet = pcap_next(pcap_handle, &header);
    printf("[INFO]\treceive new packet size => %d \n", header.len);
    dump(packet, header.len);

    i++;
  }
  
  pcap_close(pcap_handle);
  pcap_freealldevs(devices);

  printf("[INFO]\tcapture finish\n");
  return 0;
}
