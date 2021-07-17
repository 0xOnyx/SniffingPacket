

#ifndef HEADER_TCP
#   define HEADER_TCP

#   define ETHER_ADDR_LEN 6
#   define ETHER_HDR_LEN 14

struct ether_hdr
{
  unsigned char ether_dest_addr[ETHER_ADDR_LEN];
  unsigned char ether_src_addr[ETHER_ADDR_LEN];
  unsigned short ether_type;
}
:


#endif
