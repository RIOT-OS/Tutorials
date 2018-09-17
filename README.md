# Tutorials for RIOT

## Preparations

For links go to [https://github.com/RIOT-OS/Tutorials](https://github.com/RIOT-OS/Tutorials)

**Quick Setup using a Virtual Machine (recommended for this Tutorial)**

* Install and set up [git](https://help.github.com/articles/set-up-git/)
* Install latest [VirtualBox](https://www.virtualbox.org/wiki/Downloads) & [VirtualBox Extension Pack](https://www.virtualbox.org/wiki/Downloads) for **your system**
* Install [Vagrant](https://www.vagrantup.com/downloads.html)
* Linux, OSX:
    ```Shell
    git clone --recursive https://github.com/RIOT-OS/Tutorials
    cd Tutorials
    ```
* Windows:
    * set
      ```Shell
      git config --global core.autocrlf input
      ```
      before cloning
    * clone the `Tutorials` and the `RIOT` submodule as follows:
    ```Shell
    git clone https://github.com/RIOT-OS/Tutorials
    cd Tutorials
    git submodule update --init --recursive
    ```
* In case a virtual machine is disseminated locally, adapt the path for the vagrant box `vagrant box add RIOT/ubuntu1604 <path to box>`
* Run `vagrant up` and `vagrant ssh` afterwards. See the [Vagrant RIOT Setup](https://github.com/RIOT-OS/RIOT/blob/master/dist/tools/vagrant/README.md) for a more general explanation.

**Regular Setup without using a VM (recommended for RIOT developement)**

* Install and set up [git](https://help.github.com/articles/set-up-git/)
* Install the build-essential packet (make, gcc etc.). This varies based on the operating system in use.
* Install [Native dependencies](https://github.com/RIOT-OS/RIOT/wiki/Family:-native#dependencies)
* Install [OpenOCD](https://github.com/RIOT-OS/RIOT/wiki/OpenOCD)
* Install [GCC Arm Embedded Toolchain](https://launchpad.net/gcc-arm-embedded)
* On OS X: install [Tuntap for OS X](http://tuntaposx.sourceforge.net/)
* [additional tweaks](https://github.com/RIOT-OS/RIOT/wiki/Board:-Samr21-xpro) necessary to work with the targeted hardware (ATSAMR21)
* Install `netcat` with IPv6 support (if necessary)

  ```bash
  sudo apt-get install netcat-openbsd
  ```

* `git clone --recursive https://github.com/RIOT-OS/Tutorials`
* Go to the Tutorials directory: `cd Tutorials`

## Tasks
* [Task 1: Starting the RIOT](task-01/)
* [Task 2: Custom shell handlers](task-02/)
* [Task 3: Multithreading](task-03/)
* [Task 4: Timers](task-04/)
* [Task 5: Using network devices](task-05/)
* [Task 6: Sending and receiving UDP packets](task-06/)
* [Task 7: The GNRC network stack](task-07/)
* [Task 8: CCN-Lite on RIOT](task-08/)
* [Task 9: RIOT and RPL](task-09/)

## Troubleshooting

### If you get the following error after running `vagrant up`

> The guest machine entered an invalid state while waiting for it to boot. Valid states are 'starting, running'. The machine is in the 'poweroff' state.

Make sure you have the [Extension Pack](https://www.virtualbox.org/wiki/Downloads) installed.

### If you cannot flash a connected board (`/dev/ttyXXXX` does not exist)

Make sure your user is a member of the usergroup `vboxusers`. On Linux you can add the current user with

`usermod -a -G vboxusers $USER`.

You can check the groups of your user with

`groups`.

Note that you need to log out once to reload a Linux user's group assignments

## License
This work and all its related code and documents are licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-sa/4.0/)
