#!/bin/bash

if [[ $CC == "gcc" ]] ; then
	sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
	sudo apt-get update -qq
	sudo apt-get install gcc-4.8 -y
fi

sudo add-apt-repository -y ppa:george-edison55/precise-backports
sudo apt-get update -qq
sudo apt-get install -y libgtest-dev
sudo mkdir /usr/src/gtest/build
cd /usr/src/gtest/build
sudo cmake .. -DBUILD_SHARED_LIBS=1
sudo make -j2
sudo ln -s /usr/src/gtest/build/libgtest.so /usr/lib/libgtest.so
sudo ln -s /usr/src/gtest/build/libgtest_main.so /usr/lib/libgtest_main.so
cd -
