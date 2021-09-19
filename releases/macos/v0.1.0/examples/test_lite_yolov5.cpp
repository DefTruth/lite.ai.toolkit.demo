//
// Created by DefTruth on 2021/6/29.
//

#include "lite/lite.h"

static void test_lite()
{
  std::string onnx_path = "../hub/onnx/cv/yolov5s.onnx";
  std::string test_img_path = "../resources/test_lite_yolov5_1.jpg";
  std::string save_img_path = "../logs/test_lite_yolov5_1.jpg";

  auto *yolov5 = new lite::cv::detection::YoloV5(onnx_path);

  std::vector<lite::cv::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolov5->detect(img_bgr, detected_boxes);

  lite::cv::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "YoloV5 Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete yolov5;

}


int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}