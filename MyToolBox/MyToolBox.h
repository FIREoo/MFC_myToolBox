// MyToolBox.h : Header
//
#pragma once
#define _CRT_SECURE_NO_WARNNINGS

//#ifndef MYTOOLBOX_CLASS_DEF
//#define MYTOOLBOX_CLASS_DEF
#include "afxwin.h"
#include"cv.h"
#include"highgui.h"
#include"CvvImage.h"

#include <afxsock.h>

class MyToolBox
{
public:
	MyToolBox();
	~MyToolBox();
	//format
	int toInt(CString str);
	int toFloat(CString str);

	CString toCString(int num);
	CString toCString(char* chr, int size = 0);

	void CStringToChar(CString str, char* chr, int size = 0);


	//OpenCV
	static CvSize defaultSize;
	void ShowImage(IplImage * Image, CWnd * pWnd, CvSize oSize = defaultSize);
	void ShowImage(cv::Mat Image, CWnd * pWnd, CvSize oSize);
	void lzShowCam(int index, CWnd * pWnd, CvSize oSize = defaultSize, bool loop = 0);
	void lzShowCam(int index, CWnd * pWnd, bool loop);

	//socket
	void lzSocketSend(CString strIP, int nPort, CString msg);
	void lzSocketSend(CString strIP, int nPort, char* cMsg, int size);
};
//#endif