#!/bin/bash

# 引数の個数が0の場合はmain.cppをコンパイルしてテストを実行
if [ $# -eq 0 ]; then
  g++ main.cpp && oj t
elif [ $# -eq 1 ]; then
  # 引数の個数が1個の場合、その引数が整数ならば実行可能
  if [[ "$1" =~ ^[0-9]+$ ]]; then
    g++ main_"$1".cpp && oj t
  else
    echo "第一引数は整数でなければ実行できません。"
  fi
else
  echo "このスクリプトには2個以上の引数は渡せません。"
fi
