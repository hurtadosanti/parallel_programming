#!/bin/bash
sudo apt update && sudo apt -y upgrade
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/cuda-ubuntu1804.pin
sudo mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600
sudo apt-key adv --fetch-keys https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/7fa2af80.pub
sudo add-apt-repository "deb http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/ /"
sudo apt-get update
sudo apt-get -y install cuda
echo export PATH=/usr/local/cuda-10.2/bin:/usr/local/cuda-10.2/NsightCompute-2019.1'${PATH:+:${PATH}}' >> ~/.bashrc
echo export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64'${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}'>>~/.bashrc