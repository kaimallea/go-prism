# -*- mode: ruby -*-
# vi: set ft=ruby :

# Vagrantfile API/syntax version. Don't touch unless you know what you're doing!
VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

  config.vm.box = "ubuntu/trusty64"

$script = <<SCRIPT
sudo apt-get update -qq && apt-get install -qq -y \
    git \
    build-essential \
    gcc-multilib \
    g++-multilib
SCRIPT

  config.vm.provision "shell", inline: $script

end
