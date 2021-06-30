#!/bin/bash
rm -rf examples/build
cd examples && mkdir build && cd build  && cmake ../.. && make -j1
echo "Testing Start ..."
./lite_yolov5
echo "Testing Successful !"