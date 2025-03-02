// OpenCVCameraFrame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0); // Open the default camera
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // Capture a frame
        if (frame.empty()) break;

        cv::imshow("Camera", frame); // Display the frame
        if (cv::waitKey(30) >= 0) break; // Exit on key press
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
