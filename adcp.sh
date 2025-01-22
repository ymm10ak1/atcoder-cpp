#!/bin/bash

# 何個前のディレクトリに戻るか(デフォルトは0)
BACK_DIR="${1:-0}"

if [ "$BACK_DIR" -eq 0 ]; then
  acc add --template cpp
elif [ "$BACK_DIR" -eq 1 ]; then
  cd .. && acc add --template cpp
elif [ "$BACK_DIR" -eq 2 ]; then
  cd ../.. && acc add --template cpp
fi
