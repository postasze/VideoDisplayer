#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <iostream>

using namespace std;

int main()
{
    cv::VideoCapture videoCapture;
    cv::Mat videoFrame;
    int frameNumber = 0;
    cv::String VideoFileName, secondVideoFileName, destinationVideoFileName;
    VideoFileName = "video.mp4";
    videoCapture.open(VideoFileName);
    double timestamp, previousTimestamp = 0, duration, fps;

    int VideoWidth = videoCapture.get(cv::CAP_PROP_FRAME_WIDTH);
    int VideoHeight = videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT);

    double _video_fourcc_codec_info = videoCapture.get(cv::CAP_PROP_FOURCC);

    while(videoCapture.isOpened())
    {
        videoCapture >> videoFrame;
        if(videoFrame.empty())
            break;
        frameNumber++;

        timestamp = videoCapture.get(cv::CAP_PROP_POS_MSEC);
        duration = timestamp - previousTimestamp;

        cout << "Frame Number: " << frameNumber << " duration: " << duration << " timestamp: " << timestamp << endl;

        previousTimestamp = timestamp;

        cv::resize(videoFrame, videoFrame, cvSize(800, 600));
        cv::imshow("Video display", videoFrame);

        if(cv::waitKey(0) == 27)
            break;
    }
    fps = frameNumber / timestamp * 1000;
    cout << "fps: " << fps << endl;

    videoCapture.release();

    return 0;
}
