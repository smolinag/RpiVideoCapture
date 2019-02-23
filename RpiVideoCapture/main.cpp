#include "opencv2/opencv.hpp"
#include <string>

#if __cplusplus < 201703L // If the version of C++ is less than 17
#include <experimental/filesystem>
// It was still in the experimental:: namespace
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap(0);
	string nameToRec;

	cout << "Ingrese el Nombre para el video"<< endl;
	cin >> nameToRec;

	if (!cap.isOpened())
		return -1;

	int fIdx = 0;
	string fIdxStr;
	int zeroPad = 5;
	string imgExt = ".jpg";
	fs::create_directory(nameToRec);

	for (;;) {
		Mat frame;
		cap >> frame;
		fIdxStr = to_string(fIdx);
		//imshow("test", frame);
		fIdxStr = string(zeroPad - fIdxStr.length(), '0') + fIdxStr;
		imwrite(nameToRec + "/" + nameToRec + fIdxStr + imgExt, frame);
		waitKey(70);
		fIdx++;
	}
	return 0;
}
