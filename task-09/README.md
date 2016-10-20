[previous task](../task-08)

# Task 9: RIOT and RPL

This task will demonstrate basic routing functionalities in RIOT provided by the [RPL](https://tools.ietf.org/html/rfc6550) (IPv6 Routing Protocol for Low-Power and Lossy Networks) routing protocol and multihop communication.

It uses an adapted version of the default [`gnrc_networking`](https://github.com/RIOT-OS/RIOT/tree/master/examples/gnrc_networking) example in the RIOT repository.

## Prerequisites

* Compile the application and run on your `BOARD`
* For this task you need at least three boards (you can form groups with your neighbors)
* Each "group" should change to an individual RF channel. It can be changed by e.g.

```
ifconfig <if_id> set chan 11

```

Use the `ifconfig` command to obtain the `<id_id>`.

* Check if this worked by looking at the output of `ifconfig` again. Also have a look at the preconfigured IPv6 addresses that all have a local scope.


## Task 9.1: Initialize RPL

* In order to use RPL we have to choose **one** RPL root node and configure a global IPv6 address for it. This is simply done by adding the address to the network interface (`<if_id>`) via `ifconfig`:

```
ifconfig <if_id> add 2001:db8::1
```

* To start the routing process and the generation of a RPL DODAG (Destination Oriented Directed Acyclic Graph), we need to start the root node with an Instance ID (here `1`) and a DODAG ID (here its global IPv6 address) 

```
rpl root 1 2001:db8::1
```

## Analyse the topology

* On not-root nodes, look at the output of `ifconfig` again. You should see that a global unicast IPv6 address has been set automatically.

* Typing `rpl` gives you some information about the nodes position in the DODAG. Check the local IPv6 address of the selected parent node. Look for value `R:` which describes the "rank" or more general, the position in the DODAG according to the metric. What is the increment for one hop?

* RPL fills the FIB (Forwarding Information Base) table which is consulted when forwarding packets. Check the entries on the root node and see the relation between the destination and next hop addresses.


## Pinging "distant" nodes

* Use the ping6 command to ping global address of a "distant" node.
* Most likely, in this setup the root node will be the only intermediate hop. It should print some rough information about forwarding IPv6 packets
* Additionally you can try to transmit UDP packets (explore the `udp` commandset)
