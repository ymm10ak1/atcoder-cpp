#!/bin/bash

if [ $# -ne 1 ]; then
  echo "usage: mkcp <revision-name>"
  echo "実行するには1個の引数が必要です。"
else
  touch main_"$1".cpp \
    && cp "$(acc config-dir)"/cpp/main.cpp main_"$1".cpp
fi
