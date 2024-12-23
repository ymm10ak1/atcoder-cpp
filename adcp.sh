#!/bin/bash

if [ $# -ne 1 ]; then
  echo "usage: adcp <hierarchy-up-number>"
  echo "実行するには1個の引数が必要です"
elif [ "$1" -eq 0 ]; then
  acc add --template cpp
elif [ "$1" -eq 1 ]; then
  cd .. && acc add --template cpp
elif [ "$1" -eq 2 ]; then
  cd ../.. && acc add --template cpp
fi
