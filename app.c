//gcc app.c ./src/*.c -lpcap -o a.out; sudo ./a.out -1 

#include <pcap.h>
#include <string.h>
#include <stdlib.h>

#include "./src/process_packet.h"


#define PACKET_SIZE 4096

void fail_pcap(char *error, char *pcap_error)
{
    char buffer_error[255];

    strcpy(buffer_error, "\e[31m[ERROR]\e[0m\tfail to ");
    strncat(buffer_error, error, 70);
    strcat(buffer_error, " : ");
    strncat(buffer_error, pcap_error, 100);
    
    puts(buffer_error);
    putchar('\n');
    
    exit(1);
}

void usage(char *current_postion)
{
    puts("\e[92m[USAGE]\e[0m");
    printf("===>\t$: %s \e[92m<Nombre packet to capture -1 to infinity>\e[0m\t\e[93m<Optional Interface to capture default Eth0>\e[0m\n", current_postion);
    
    exit(1);
}

char * found_device(pcap_if_t **devices, char *pcap_error)
{
    char *device;

    if( pcap_findalldevs(devices, pcap_error) != 0)
        fail_pcap("load devices to sniff", pcap_error);
    
    device = (*devices)->name;

    if(device == NULL)
        fail_pcap("device as no name", "");

    printf("\e[34m[INFO]\e[0m\tNew device find to sniffing => %s \n", device);

    return device;
}



int main(int argc, char **argv)
{
    int nbr_packet;
    pcap_t *pcap_handle;
    const unsigned char *packet;

    char *device;
    pcap_if_t *devices;

    char pcap_error[PCAP_ERRBUF_SIZE];

    if(argc < 2)
        usage(argv[0]);
    
    nbr_packet = atoi(argv[1]);

    if(argc == 3)
        device = argv[2];
    else
        device = found_device(&devices, pcap_error);

    pcap_handle = pcap_open_live(device, PACKET_SIZE, 1, 0, pcap_error);
    
    if(pcap_handle == NULL)
        fail_pcap("open device to sniff", pcap_error);
    
    printf("\e[34m[INFO]\e[0m\tstart sniffing on device => %s \n", device);

    pcap_loop(pcap_handle, nbr_packet, &process_packet, NULL);    

    pcap_close(pcap_handle);
    pcap_freealldevs(devices);
}


