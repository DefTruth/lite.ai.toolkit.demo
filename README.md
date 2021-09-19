# Lite.AI.ToolKit.Demo
Demos for how to use the shared libs of [Lite.AI.ToolKit](https://github.com/DefTruth/lite.ai.toolkit). Star 🌟👆🏻 this repo if it does any helps to you ~ 🙃🤪🍀

## 1. MacOS. 

* Clone this repo and run *build.sh*.
```shell
git clone --depth=1 https://github.com/DefTruth/lite.ai.toolkit.demo.git
```
```shell
cd lite.ai.toolkit/macos 
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

* CMakeLists.txt configuration details.  

```cmake
cmake_minimum_required(VERSION 3.17)
project(lite.ai.toolkit.demo.macos)

message(">>>> Current project is: ${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11)

# link opencv.
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/opencv/lib/cmake/opencv4)
find_package(OpenCV 4 REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    set(OpenCV_LIBS opencv_highgui opencv_core opencv_imgcodecs opencv_imgproc) # need only
    message("=================================================================================")
    message(STATUS "    OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
    message("=================================================================================")
else ()
    message(FATAL_ERROR "OpenCV library not found")
endif()

# link onnxruntime.
set(ONNXRUNTIME_DIR ${CMAKE_SOURCE_DIR}/onnxruntime/)
set(ONNXRUNTIME_INCLUDE_DIR ${ONNXRUNTIME_DIR}/include)
set(ONNXRUNTIME_LIBRARY_DIR ${ONNXRUNTIME_DIR}/lib)
include_directories(${ONNXRUNTIME_INCLUDE_DIR})
link_directories(${ONNXRUNTIME_LIBRARY_DIR})

# link lite.ai.toolkit
set(LITEHUB_DIR ${CMAKE_SOURCE_DIR}/lite.ai.toolkit)
set(LITEHUB_INCLUDE_DIR ${LITEHUB_DIR}/include)
set(LITEHUB_LIBRARY_DIR ${LITEHUB_DIR}/lib)
include_directories(${LITEHUB_INCLUDE_DIR})
link_directories(${LITEHUB_LIBRARY_DIR})

# add your executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/examples/build)
add_executable(lite_yolov5 examples/test_lite_yolov5.cpp)
target_link_libraries(lite_yolov5 lite.ai.toolkit onnxruntime ${OpenCV_LIBS})  # link lite.ai.toolkit
```

* Building logs:  
```shell
 macos git:(main) ✗ sh ./build.sh      
>>>> Current project is: /Users/xxx/Desktop/xxx/lite.ai.toolkit.demo/macos
-- Found OpenCV: /Users/xxx/Desktop/xxx/lite.ai.toolkit.demo/macos/opencv (found suitable version "4.5.2", minimum required is "4") 
=================================================================================
--     OpenCV library status:
--     version: 4.5.2
--     libraries: opencv_highgui;opencv_core;opencv_imgcodecs;opencv_imgproc
--     include path: /Users/xxx/Desktop/xxx/lite.ai.toolkit.demo/macos/opencv/include/opencv4
=================================================================================
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/xxx/Desktop/xxx/lite.ai.toolkit.demo/macos/examples/build
[ 50%] Building CXX object CMakeFiles/lite_yolov5.dir/examples/test_lite_yolov5.cpp.o
[100%] Linking CXX executable lite_yolov5
[100%] Built target lite_yolov5
Testing Start ...
LITEORT_DEBUG LogId: ../hub/onnx/cv/yolov5s.onnx
=============== Input-Dims ==============
input_node_dims: 1
input_node_dims: 3
input_node_dims: 640
input_node_dims: 640
=============== Output-Dims ==============
Output: 0 Name: pred Dim: 0 :1
Output: 0 Name: pred Dim: 1 :25200
Output: 0 Name: pred Dim: 2 :85
Output: 1 Name: output2 Dim: 0 :1
Output: 1 Name: output2 Dim: 1 :3
Output: 1 Name: output2 Dim: 2 :80
Output: 1 Name: output2 Dim: 3 :80
Output: 1 Name: output2 Dim: 4 :85
Output: 2 Name: output3 Dim: 0 :1
Output: 2 Name: output3 Dim: 1 :3
Output: 2 Name: output3 Dim: 2 :40
Output: 2 Name: output3 Dim: 3 :40
Output: 2 Name: output3 Dim: 4 :85
Output: 3 Name: output4 Dim: 0 :1
Output: 3 Name: output4 Dim: 1 :3
Output: 3 Name: output4 Dim: 2 :20
Output: 3 Name: output4 Dim: 3 :20
Output: 3 Name: output4 Dim: 4 :85
detected num_anchors: 25200
generate_bboxes num: 66
YoloV5 Detected Boxes Num: 5
Testing Successful !
```

* Then the output can be found at *examples/logs* dir:   
<div align='center'>
  <img src='macos/examples/logs/test_lite_yolov5_1.jpg' height="400px"  width="600px">
</div>  
  
