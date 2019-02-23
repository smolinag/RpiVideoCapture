#include "opencv2/opencv.hpp"
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	VideoCapture cap(0);

	string nameToRec = argv[1];

	if (!cap.isOpened())
		return -1;

	for (;;) {
		Mat frame;
		cap >> frame;
		imwrite("/home/pi/Documents/PeopleCounterVideos/" + nameToRec, frame);
		waitKey(45);
	}
	return 0;
}