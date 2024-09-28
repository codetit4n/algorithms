#!/bin/bash

sudo rm -rf /usr/bin/cexec $PWD/utils/cexec
gcc $PWD/utils/cexec.c -o $PWD/utils/cexec
sudo ln -s $PWD/utils/cexec /usr/bin/cexec
