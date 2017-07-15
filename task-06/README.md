[previous task](../task-05)

# 6. UDP Client / Server

The transport layer (UDP, TCP, etc) is accessed through [`sock`](https://doc.riot-os.org/group__net__sock.html) driver API

![Networking overview](../overview-net.png)

Look at the new modules in the [`Makefile`](Makefile)
```
USEMODULE += gnrc_sock_udp
```

[`udp.c`](udp.c) utilizes `sock_udp_send()` and `sock_udp_recv()` to exchange UDP packets

## Task 6.1: Use UDP for messaging
1.  Compile and run on two `native` instances
2.  We have two new shell commands: `udps` to start a server and `udp` to send a message.
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
   ncache               manage neighbor cache by hand
   routers              IPv6 default router list
   >
   ```

3.   Start a UDP server on port 8888 with `udps 8888`.
   Look at the output of `ps`
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

4.  Get your IPv6 address using `ifconfig`
    ```
    > ifconfig
    ifconfig
    Iface  5   HWaddr: 22:7e:b9:04:9f:f0

               MTU:1500  HL:64
               Source address length: 6
               Link type: wired
               inet6 addr: ff02::1/128  scope: local [multicast]
               inet6 addr: fe80::207e:b9ff:fe04:9ff0/64  scope: local
               inet6 addr: ff02::1:ff04:9ff0/128  scope: local [multicast]
    ```

5.  From the second instance, send a udp packet with the `udp` command.
    ```
    > udp fe80::207e:b9ff:fe04:9fef 8888 hello
    udp fe80::207e:b9ff:fe04:9fef 8888 hello
    Success: send 5 byte to fe80::207e:b9ff:fe04:9fef
    ```

## Task 6.2: Communicate with Linux
1.  Compile and run on two `native` instances
2.  Start a UDP server on port 8888 with `udps 8888`.
3.  Send a packet to RIOT from Linux using `netcat`
    ```sh
    echo "hello" | nc -6u <RIOT-IPv6-addr>%tapbr0 8888
    ```
    Note: on MAC use `bridge0` instead of `tapbr0`.

4.  Start a UDP server on the host machine with `netcat`.
    ```
    nc -6lu 8888
    ```
    And in RIOT ...
    ```
    udp <tap0-IPv6-addr> 8888 hello
    ```
[Read the Doc](https://doc.riot-os.org/group__net__sock.html)

## Task 6.3 -- Exchange UDP packets with your neighbors
* Compile, flash and run on the board `BOARD=samr21-xpro make all flash term`
* Send and receive UDP messages to and from your neighbors using `udp` and `udps`

[next task](../task-07)
