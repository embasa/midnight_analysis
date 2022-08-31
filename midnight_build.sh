#!/usr/bin/env bash
# This script builds Midnight binary using cmake

set -e

[ -d build ] && rm -rf build
mkdir build
pushd build
cmake ..
make
popd
ls -lart build/Midnight
