# litehub-release
Release the c++ shared libs of litehub.

## 1. Build LiteHub Examples at MacOS. 
```shell
git clone --depth=1 https://github.com/DefTruth/litehub-release.git
```
```shell
cd litehub-release/macos 
sh ./build.sh
```  
See [macos/CMakeLists.txt](macos/CMakeLists.txt) to figure out how to link the shared lib of LiteHub correctly. The build.sh will build and test a YoloV5 executable demo, or you can build it manually like:  
```shell
#!/bin/bash
rm -rf examples/build
cd examples && mkdir build && cd build  && cmake ../.. && make -j1
echo "Testing Start ..."
./lite_yolov5
echo "Testing Successful !"
```  
The output can be found at *examples/logs* dir:   
<div align='center'>
  <img src='macos/examples/logs/test_lite_yolov5_1.jpg' height="256px"  width="600px">
</div>  