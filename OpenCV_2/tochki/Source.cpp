#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <string>
#include <cstring>
using namespace std;
using namespace cv;
Mat image() {
	Mat Image = imread("Goblin.jpg");
	return Image;
}
void file(char* dt)
{
	ofstream file;
	file.open("test.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << " = " << dt << endl;
	file.close();
}
void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		vector<Vec6d> ellipses;
		Mat* pImage = (Mat*)param;
		Mat image = *pImage;
		ellipse(image, Point(x, y),
			Size(10, 10), 0, 0,
			360, Scalar(0, 0, 256),
			-1, LINE_AA);
	}
	if (event == EVENT_RBUTTONDOWN)
	{
		vector<Vec6d> ellipses;
		Mat* pImage = (Mat*)param;
		Mat image = *pImage;
		ellipse(image, Point(x, y),
			Size(10, 10), 0, 0,
			360, Scalar(0, 256, 0),
			-1, LINE_AA);
	}
}

char* data() {
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	return dt;
}

int main() {
	char* dt = data();
	file(dt);
	cout << "The local date and time is: " << endl;
	Mat mg = image();
	namedWindow("Кликанье мыши");
	setMouseCallback("Кликанье мыши", my_mouse_callback, &mg);
	while (true)
	{
		imshow("Кликанье мыши", mg);
		waitKey(30);
	}
	return 0;
}
