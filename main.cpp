#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace cv;
using std::string;
using namespace std;

static void help()
{
    cout << "\nThis program demonstrates circle finding with the Hough transform.\n"
            "Usage:\n"
            "./houghcircles <image_name>, Default is ../data/board.jpg\n" << endl;
}

Scalar getHSV(int h, int s, int v)
{
    return Scalar(h , s , v);
}

Mat& greenFilter1(const Mat &from, Mat &to )
{
    //medianBlur( from, from, 3);
    inRange(from, getHSV(70, 100, 100 ), getHSV(80,255, 255), to);
    return to;
}

Mat& greenFilter2(const Mat &from, Mat &to )
{
   // medianBlur( from, from, 3);
    inRange(from, getHSV(70, 100, 100 ), getHSV(100,255, 255), to);
    return to;
}

Mat& redFilter1(const Mat &from, Mat &to )
{
   // medianBlur( from, from, 3);
    inRange(from, Scalar(0, 100, 100), Scalar(20, 255, 255), to);
    return to;
}

Mat& redFilter2(const Mat &from, Mat &to )
{
   // medianBlur( from, from, 3);
    inRange(from, Scalar(165, 100, 100), Scalar(179, 255, 255), to);
    return to;
}



Point findAvrgPoint(const vector<Point> &conture)
{
    double sum_x = 0, sum_y = 0;
    for(int i = 0; i  < conture.size(); ++i)
    {
        sum_x += conture[i].x;
        sum_y += conture[i].y;
    }
    return Point(static_cast<int>(abs(sum_x )/ (conture.size())), static_cast<int>(abs(sum_y) / conture.size()));
}
Point findAvrgPoint(const Point &red, const Point &green)
{
    return Point(static_cast<int>(abs(red.x + green.x) / 2), static_cast<int>( abs(red.y + green.y) / 2));
}

double  figureHigh(const vector<Point> &conture)
{
    double min_y = conture[0].y, max_y = conture[0].y;
    for(int i = 1; i  < conture.size(); ++i)
    {
        if (conture[i].y > min_y)
            min_y = conture[i].y;
        if (conture[i].y <= max_y)
            max_y = conture[i].y;
    }
    return  fabs(static_cast<double>((max_y - min_y))/ 2);
}

double  figureWeigh(const vector<Point> &conture)
{
    double min_x = conture[0].x, max_x = conture[0].x;
    for(int i = 1; i  < conture.size(); ++i)
    {
        if (conture[i].x > min_x)
            min_x = conture[i].x;
        if (conture[i].x <= max_x)
            max_x = conture[i].x;
    }
    return  fabs(static_cast<double>((max_x - min_x))/ 2);
}

double  figureMax(const vector<Point> &conture)
{
    return max(figureHigh(conture),figureWeigh(conture));
}

Mat& contDraw(const Mat &from, Mat &to, int b = 0, int r = 0, int g = 0)
{
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( from, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );
    Scalar color = Scalar( b , r, g );
    to = Mat::zeros(from.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); ++i)
    {
        if (contours[i].size() >= 10 && contours[i].size() <= 500)
            drawContours(to, contours, i, color, 1, 4, hierarchy, 0, Point());
    }
    //cout << contours.size() << '\n';
    //cout << hierarchy.size() << '\n';
    return to;
}



double pointToPoint(const Point &red, const Point &green)
{
    return sqrt(pow(abs(red.x - green.x),2) + pow(abs(red.y - green.y),2));
}

vector<Point> compare(const Mat &red, const Mat& green)
{
    Mat red_t;
    Mat green_t;
    int eps = 100;
    vector<Point> points;
    cvtColor(red, red_t, COLOR_BGR2GRAY);
    cvtColor(green, green_t, COLOR_BGR2GRAY);
    vector<vector<Point> > contoursRed;
    vector<vector<Point> > contoursGreen;
    vector<Vec4i> hierarchyRed;
    vector<Vec4i> hierarchyGreen;
    findContours( red_t, contoursRed, hierarchyRed, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );
    findContours( green_t, contoursGreen, hierarchyGreen, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );
    for (int r = 0; r < contoursRed.size(); ++r)
    {
        Point redP = findAvrgPoint(contoursRed[r]);
        for (int g = 0; g < contoursGreen.size(); ++g)
        {
            Point greenP = findAvrgPoint(contoursGreen[g]);
            // if (abs(redP.x - greenP.x) < figureWeigh(contoursRed[r])/eps &&
            //        abs(redP.y - greenP.y) < 2 * (figureHigh(contoursRed[r]) + figureHigh(contoursGreen[g])))
            if (abs(redP.x - greenP.x) < max(figureMax(contoursRed[r]),figureMax(contoursGreen[g]))  &&
                abs(redP.y - greenP.y) < 4 * (figureMax(contoursRed[r]) + figureMax(contoursGreen[g])))
            if (min(figureMax(contoursRed[r]) ,figureMax(contoursGreen[g]) )/max(figureMax(contoursRed[r]) ,figureMax(contoursGreen[g]))>0.5)
            {
                    if (redP.y < greenP.y)
                        points.push_back(findAvrgPoint(redP, greenP));
            }
        }
    }
    return points;
}

Mat conturingGreen(Mat &temp, Mat &hsv)
{

    cvtColor(temp, hsv, COLOR_BGR2HSV);

    Mat green1;
    green1 =    greenFilter1(hsv, green1);

    Mat green2;
    green2 =    greenFilter2(hsv, green2);

    Mat green1F;
    green1F =   contDraw(green1, green1F, 0, 255);

    Mat green2F;
    green2F =   contDraw(green2, green2F, 0, 255);

    return green1F + green2F;
}

Mat conturingRed(Mat &temp, Mat &hsv)
{

    cvtColor(temp, hsv, COLOR_BGR2HSV);

    Mat red1;
    red1 =      redFilter1(hsv, red1);

    Mat red2;
    red2 =      redFilter1(hsv, red1);

    Mat red1F;
    red1F =     contDraw(red1, red1F, 0, 0, 255);

    Mat red2F;
    red2F =     contDraw(red2, red2F, 0, 0, 255);
    return red1F + red2F;
}

int main(int argc, char** argv) {
    VideoCapture capture("/Users/Gleb/Desktop/proc/first5.avi");
    if (!capture.isOpened()) {
        cout << "capture read fail" << '\n';
        return -2;
    }

    Mat hsv;
    Mat hsv1;
    Mat hsv2;
    Mat hsv3;

    Mat temp;
    Mat temp1;
    Mat temp2;
    Mat temp3;
    /*
    Mat nottemp = Mat::zeros(temp.size(), CV_8UC3);
    Mat nottemp1 = Mat::zeros(temp.size(), CV_8UC3);
    */
    namedWindow("Normal", CV_WINDOW_AUTOSIZE);
    namedWindow("Filtered", CV_WINDOW_AUTOSIZE);
    int frameNumber = 0;
    int pointPrecision = 10;
    int frameIteration = 0;
    while (true) {

        capture >> temp;
        capture >> temp1;
        capture >> temp2;
        capture >> temp3;
        if (temp3.rows == 0)
            break;
        cvtColor(temp, hsv, COLOR_BGR2HSV);
        cvtColor(temp1, hsv1, COLOR_BGR2HSV);
        cvtColor(temp2, hsv2, COLOR_BGR2HSV);
        cvtColor(temp3, hsv3, COLOR_BGR2HSV);

        Mat imgFilter1;
        Mat imgFilter2;
        Mat pureGreen =     conturingGreen(temp1,hsv1);
        Mat pureRed =       conturingRed(temp,hsv);
        //imshow( "green", pureGreen);
        vector<Point> trafficLight = compare(pureRed, pureGreen);
        imgFilter1 = (pureRed + pureGreen);

        Mat pureGreen1 =     conturingGreen(temp3,hsv3);
        Mat pureRed1 =       conturingRed(temp2,hsv2);

        vector<Point> trafficLight1 = compare(pureRed1, pureGreen1);
        imgFilter2 = pureRed1 + pureGreen1;
        vector<Point> trafficLightFinal = compare(pureRed1, pureGreen1);
        for (int i(0); i < trafficLight.size(); ++i) {
            trafficLightFinal.push_back(trafficLight[i]);
            circle(imgFilter1, trafficLight[i], 1, Scalar(255, 0, 0));
        }
        for (int i(0); i < trafficLight1.size(); ++i) {
            trafficLightFinal.push_back(trafficLight1[i]);
            circle(imgFilter1, trafficLight1[i], 1, Scalar(255, 0, 0));
        }
        double prec = 1;
        for (int i(0); i < trafficLightFinal.size(); ++i)
            for (int j(i); j < trafficLightFinal.size(); ++j)
                if (pointToPoint(trafficLightFinal[i], trafficLightFinal[j]) < prec)
                    circle(imgFilter1, trafficLightFinal[i], 3, Scalar(255, 0, 0));
         cout << '\n' << "Amooutn of points: " << trafficLightFinal.size() << '\n';
        frameIteration += 4;
        frameNumber = frameIteration - 2;
        int am = trafficLightFinal.size();
        imshow("Filtered", imgFilter1);
        cvtColor(hsv, hsv, cv::COLOR_HSV2BGR);
        imshow("Normal", hsv);
            if (am > pointPrecision ) {

               cout << frameNumber << '\n';
          }
        char c = cvWaitKey(33);
        if (c == 27) break;
    }
    cout << "Frame amount" << frameIteration;
    cvDestroyWindow("Normal");
    cvDestroyWindow("Filtered");
    waitKey();
    return 0;
}

