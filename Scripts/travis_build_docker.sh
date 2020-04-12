#!/usr/bin/env bash

set -e

if [ $# -eq 0 ]
  then
    docker build -t snowapril/tfat .
else
    docker build -f $1 -t snowapril/tfat:$2 .
fi
docker run snowapril/tfat