#include "FastPCN.h"

int main()
{
    FastPCN detector("FastPCN.caffemodel");
    detector.SetMinFaceSize(48);
    detector.SetScoreThresh(0.95);
    detector.SetImagePyramidScaleFactor(1.414);
    detector.SetVideoSmooth(false);

    for (int i = 1; i <= 16; i++)
    {
        cv::Mat img = cv::imread("../imgs/" + std::to_string(i) + ".jpg");
        cv::TickMeter tm;
        tm.reset();
        tm.start();
        std::vector<Window> faces = detector.DetectFace(img);
        tm.stop();
        std::cout << "Image: " << i << std::endl;
        std::cout << "Time Cost: "<< tm.getTimeMilli() << " ms" << std::endl;
        for (int i = 0; i < faces.size(); i++)
        {
            DrawFace(img, faces[i]);
        }
        cv::imshow("PCN", img);
        cv::waitKey();
    }

    cv::destroyAllWindows();

    return 0;
}
