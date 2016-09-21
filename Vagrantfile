# -*- mode: ruby -*-
# vi: set ft=ruby :

require 'fileutils'

riot_vagrantfile = File.expand_path('RIOT/Vagrantfile')
RIOTBASE ||= "RIOT/"

if File.exists?(riot_vagrantfile)
    load riot_vagrantfile
else
    abort "No Vagrantfile found in the RIOT directory. ABORTING!"
end

Vagrant.configure(2) do |config|
  config.vm.provider "virtualbox" do |vb|
    vb.name = "RIOT VM - Tutorials"
  end
  config.vm.synced_folder ".", "/home/vagrant/Tutorials"
end
