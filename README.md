# lite.ai-release
Demos for how to use the shared libs of [Lite.AI](https://github.com/DefTruth/lite.ai) . 

## 1. Build Lite.AI Examples for MacOS. 
```shell
git clone --depth=1 https://github.com/DefTruth/lite.ai-release.git
```
```shell
cd lite.ai-release/macos 
sh ./build.sh
```  
See [macos/CMakeLists.txt](macos/CMakeLists.txt) to figure out how to link the shared lib of Lite.AI correctly. The build.sh will build and test a demo of YoloV5, or you can build it manually like:  
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
  <img src='macos/examples/logs/test_lite_yolov5_1.jpg' height="400px"  width="600px">
</div>  
