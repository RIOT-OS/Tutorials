# Tutorials for RIOT

## Preparations

For links go to [https://github.com/RIOT-OS/Tutorials](https://github.com/RIOT-OS/Tutorials)

**Quick Setup** (Using a Virtual Machine)

* Install and set up [git](https://help.github.com/articles/set-up-git/)
* Install [VirtualBox 5.0](https://www.virtualbox.org/wiki/Download_Old_Builds_5_0) & [VirtualBox Extension Pack](https://www.virtualbox.org/wiki/Downloads)
* Install [Vagrant](https://www.vagrantup.com/downloads.html)
* `git clone --recursive https://github.com/RIOT-OS/Tutorials`
* Move to teh RIOT directory: `cd Tutorials/RIOT/`
* Run the [Vagrant RIOT Setup](https://github.com/RIOT-OS/RIOT/blob/master/dist/tools/vagrant/README.md)

**Recommended Setup** (Without Using a VM)

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

## Tasks
* [Task 1: Starting the RIOT](task-01/)
* [Task 2: Custom shell handlers](task-02/)
* [Task 3: Multithreading](task-03/)
* [Task 4: Timers](task-04/)
* [Task 5: Using network devices](task-05/)
* [Task 6: Sending and receiving UDP packets](task-06/)
* [Task 7: The GNRC network stack](task-07/)

## License
This work and all its related code and documents are licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-sa/4.0/)
