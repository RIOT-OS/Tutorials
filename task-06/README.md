# 4. UDP Client / Server

## 4.1. Modules necessary in addition to Task-02
Look at the new modules in the `Makefile`.
```
USEMODULE += gnrc_conn_udp
```

## 4.2. Look into the Code
Familiarize yourself with the code in `main.c` and `udp.c`.

## 4.3. UDP in Native
1.  We have two new shell commands: `udps` to start a server and `udp` to send a message.
	```
	> help
	help
	Command              Description
	---------------------------------------
	udp                  send udp packets
	udps                 start udp server
	reboot               Reboot the node
	ps                   Prints information about running threads.
	ping6                Ping via ICMPv6
	random_init          initializes the PRNG
	random_get           returns 32 bit of pseudo randomness
	ifconfig             Configure network interfaces
	txtsnd               Sends a custom string as is over the link layer
	ncache               manage neighbor cache by hand
	routers              IPv6 default router list
	>
	```

2.	Start a UDP server on port 8888 with `udps 8888`.
	Look at the output of ps
	```
	> ps
	ps
			pid | name                 | state    Q | pri | stack ( used) | location
			  1 | idle                 | pending  Q |  15 |  8192 ( 6240) | 0x806eb80
			  2 | main                 | running  Q |   7 | 12288 ( 9312) | 0x806bb80
			  3 | ipv6                 | bl rx    _ |   4 |  8192 ( 6240) | 0x807bce0
			  4 | udp                  | bl rx    _ |   5 |  8192 ( 6240) | 0x807f760
			  5 | gnrc_netdev2_tap     | bl rx    _ |   4 |  8192 ( 6240) | 0x8079ca0
			  6 | UDP Server           | bl rx    _ |   6 |  8192 ( 6240) | 0x8077c60
				| SUM                  |            |     | 53248 (40512)
	>
	```
	The new thread for the UDP server has the PID 6 in this example.

3.	From your host computer, send a udp packet with `netcat`.
	```
	nc -6u <RIOT-IPv6-addr>%tap0 8888
	> hello
	```

4. Start a UDP server on the host machine with `netcat`.
	```
	nc -6lu 8888
	```
	And in RIOT ...
	```
	udp <tap0-IPv6-addr> 8888 hello
	```

## 4.4 UDP on real hardware
1.  Flash the application on the `samr21-xpro`
2.  Send and receive UDP messages from your neighbors
