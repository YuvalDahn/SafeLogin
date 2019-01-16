#include "webcam.h"

// taken from https://stackoverflow.com/questions/851679/saving-an-image-in-opencv
void capture(const std::string &path)
{
	cv::VideoCapture cap(0); // Capture the Image from the webcam
	cv::Mat save_img;
	cap >> save_img;	  // Get the frame
	if (save_img.empty()) // Check for empty image
	{
		std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
	}
	imwrite(path, save_img); // Save the frame into a file
}

std::string generate_file_name()
{
	//Format: YY-MM-DD-HH-MM_Capture_N.jpg
	static int count = 0;
	std::time_t t = std::time(0);
	std::tm now;
	localtime_s(&now, &t);
	std::stringstream out;
	out << (now.tm_year + 1900) << '-'
		<< (now.tm_mon + 1) << '-'
		<< now.tm_mday << '-'
		<< now.tm_hour << '-'
		<< now.tm_min << '_'
		<< "Capture_" << ++count << ".jpg";
	return out.str();
}
