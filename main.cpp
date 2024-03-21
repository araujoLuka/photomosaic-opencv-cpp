#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename.jpg>" << std::endl;
        return 1;
    }

    std::cout << "Opening image: " << argv[1] << std::endl;
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Error: Image not found" << std::endl;
        return 1;
    }

    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Image", img);
    cv::waitKey(0);

    cv::destroyAllWindows();
    cv::imwrite("output.jpg", img);
    
    return 0;
}
