#!/bin/bash
sudo clang++ -std=c++14 -I /usr/local/boost-1.60.0/include \
      -L /usr/local/boost-1.60.0/lib \
      1 -o $2 -lboost_system -lboost_filesystem
