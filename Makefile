

# Make file for compile programme Sniffing Packet
# By JD

NAME = sniffingPacket
SRC = \
	./src/dump.c \
	./src/print_ethernet.c \
	./src/print_icmp.c \
	./src/print_iphdr.c \
	./src/print_tcp.c \
	./src/print_udp.c \
	./src/process_packet.c

OBJECT_O = \
	dump.o \
	print_ethernet.o \
	print_icmp.o \
	print_iphdr.o \
	print_tcp.o \
	print_udp.o \
	process_packet.o




$(NAME): all

all : compile install

compile : 
	gcc $(NAME).c $(SRC) -c

install : 
	gcc $(NAME).o $(OBJECT_O) -o $(NAME)  -lpcap

clean : 
	/usr/bin/rm -f $(OBJECT_O) $(NAME).o

fclean : clean
	/usr/bin/rm -f $(NAME)


reinstall : fclean all


