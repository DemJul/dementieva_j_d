#include <opencv2/opencv.hpp>
#include <ctime>

using namespace cv;

int main()
{
	Mat image(Mat::zeros(60, 768, CV_8U));

	for (int i = 0; i < 256; i++) {
		line(image, Point2f(i * 3, 0), Point2f(i * 3, 60), Scalar(i, i, i));
		line(image, Point2f(i * 3 + 1, 0), Point2f(i * 3 + 1, 60), Scalar(i, i, i));
		line(image, Point2f(i * 3 + 2, 0), Point2f(i * 3 + 2, 60), Scalar(i, i, i));
	}

	//Гамма
	float gamma = 2.2;
	Mat image1(Mat::zeros(60, 768, CV_8U));
	unsigned int start_time = clock();
	for (int i = 0; i < image1.cols/3; i += 1) {
		float p = pow((i / 255.0), gamma) * 255;
		line(image1, Point2f(i * 3, 0), Point2f(i * 3, 60), Scalar(p, p, p));
		line(image1, Point2f(i * 3 + 1, 0), Point2f(i * 3 + 1, 60), Scalar(p, p, p));
		line(image1, Point2f(i * 3 + 2, 0), Point2f(i * 3 + 2, 60), Scalar(p, p, p));
	}
	unsigned int end_time = clock();
	std::cout << "Time 1:" << end_time - start_time << std::endl;

	//3 пункт
	Mat image2(Mat::zeros(60, 768, CV_8U));
	start_time = clock();
	for (int i = 0; i < image2.cols / 3; i++) {
		for (int j = 0; j < image2.rows; j++) {
			image2.at<uchar>(j, i * 3) = pow(image.at<uchar>(j, i * 3) / 255.0, gamma) * 255.0;
			image2.at<uchar>(j, i * 3 + 1) = pow(image.at<uchar>(j, i * 3 + 1) / 255.0, gamma) * 255.0;
			image2.at<uchar>(j, i * 3 + 2) = pow(image.at<uchar>(j, i * 3 + 2) / 255.0, gamma) * 255.0;
		}
	}
	end_time = clock();
	std::cout << "Time 2:" << end_time - start_time << std::endl;
	
	//Объединение картинок
	Mat image3 = Mat::zeros(180,768,CV_8U);
	//Mat last_image = Mat::zeros(180, 768, CV_8U);

	/*vconcat(image, image1, image2, image3)*/;
	//vconcat(image3, image2, last_image);
	


	imshow("Window", image); 
	imshow("Window1", image1);
	imshow("Window2", image2);
	waitKey(0);
	return 0;
}