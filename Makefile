all: bubble_sort

send_arp: bubble_sort.o
	gcc -o bubble_sort bubble_sort.o -l pcap

send_arp.o: send_arp.c
	gcc -c -o bubble_sort.o bubble_sort.c

clean:
	rm bubble_sort.o bubble_sort
