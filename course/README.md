# RIOT online course

This project provides a learning course for [RIOT](https://riot-os.org), an
operating system for constrained IoT devices, i.e. powered by microcontrollers.

## Content of the course

The course is split in 5 sections:

- [Introduction](slides/01-introduction)
  contains generalities about the RIOT project
- [Getting started](slides/02-getting-started)
  contains the basics to start building and programming basics applications
  with RIOT
- [RIOT basics](slides/03-riot-basics)
  contains information about the internal structure of the OS (source code
  organization, build system, kernel) but also gives information about the
  hardware abstraction layer, the drivers and packages
- [Networking in RIOT](slides/04-networking-in-riot)
  provides basics on IoT protocols supported by RIOT (6LowPAN/IPv6, LoRa) and
  list the network stacks provided by the OS
- [LoRaWAN with RIOT](slides/05-lorawan-with-riot)
  gives an overview of the LoRaWAN protocol and how to use it with RIOT

The full course is designed for 2 full days of work and
[programming exercises](exercises) are
also provided to illustrate the exposed notions.

## Using the course

Simply open the html files in `slides/<section>` directories in a web browser

## Required setup

For RIOT applications developped during the practical exercises, you will need:

- A Linux operating system with all build tools installed or VirtualBox with a
  Linux VM running (preferably Ubuntu). Setup details are given in the
  [Getting started](slides/02-getting-started) section.

- An ST board for applications running on hardware: exercises are using the
  [B-L072Z-LRWAN1](http://www.st.com/en/evaluation-tools/b-l072z-lrwan1.html)
  with the
  [X-NUCLEO-IKS01A2](http://www.st.com/en/ecosystems/x-nucleo-iks01a2.html)
  extension board.

- A Microchip
  [SAMR21 Xplained Pro](http://www.microchip.com/developmenttools/productdetails.aspx?partno=atsamr21-xpro)
  evaluation board.

The use of the hardware boards is optional since the related manipulations can
be done with an account on [IoT-LAB](https://www.iot-lab.info).

## License

This course is licensed under the Creative commons license
[CC-BY-ND](https://creativecommons.org/licenses/by-nd/4.0/)

![CC-BY-ND](https://mirrors.creativecommons.org/presskit/buttons/80x15/png/by-nd.png)