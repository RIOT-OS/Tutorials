# name of your application
APPLICATION = Task05

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../RIOT

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Modules to include:
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps
USEMODULE += gnrc_pktdump
USEMODULE += gnrc_txtsnd
USEMODULE += gnrc_netdev_default
USEMODULE += auto_init_gnrc_netif

include $(RIOTBASE)/Makefile.include
