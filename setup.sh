#!/bin/bash

sudo rm -rf /usr/bin/cexec $PWD/cexec/cexec
gcc $PWD/cexec/main.c -o $PWD/cexec/cexec
sudo ln -s $PWD/cexec/cexec /usr/bin/cexec
