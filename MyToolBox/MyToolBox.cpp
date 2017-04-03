//MyToolBox : Source
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "MyToolBox.h"
#include "afxwin2.inl"


CvSize MyToolBox::defaultSize = cvSize(320,240);

MyToolBox::MyToolBox()
{
}

MyToolBox::~MyToolBox()
{
}


//Format
int MyToolBox::toInt(CString str)
{
	return _ttoi(str);
}

int MyToolBox::toFloat(CString str)
{
	return _ttof(str);
}

CString MyToolBox::toCString(int num)
{
	CString str;
	str.Format(L"%d", num);
	return str;
}
CString MyToolBox::toCString(char * chr, int size)
{
	CString tmp;
	tmp = chr;
	return tmp;
}

void MyToolBox::CStringToChar(CString str, char* chr, int size)
{
	ASSERT(size+1 >= str.GetLength());//char array need to be larger than CString(mind the "/0")
	sprintf(chr, "%S", str);

	/*
	char chrTmp[100];
	CString returnTmp;
	USES_CONVERSION;
	strcpy_s(chrTmp, T2A(returnTmp));
	*/
}

//opencv show
int Bpp(IplImage* image) { return image ? (image->depth & 255)*image->nChannels : 0; }
void  FillBitmapInfo(BITMAPINFO* bmi, int width, int height, int bpp, int origin)
{
	assert(bmi && width >= 0 && height >= 0 && (bpp == 8 || bpp == 24 || bpp == 32));

	BITMAPINFOHEADER* bmih = &(bmi->bmiHeader);

	memset(bmih, 0, sizeof(*bmih));
	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = width;
	bmih->biHeight = origin ? abs(height) : -abs(height);
	bmih->biPlanes = 1;
	bmih->biBitCount = (unsigned short)bpp;
	bmih->biCompression = BI_RGB;
	if (bpp == 8)
	{
		RGBQUAD* palette = bmi->bmiColors;
		int i;
		for (i = 0; i < 256; i++)
		{
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}
}

void MyToolBox::ShowImage(IplImage * Image, CWnd * pWnd, CvSize oSize)
{
	CDC	*dc = pWnd->GetWindowDC();
	IplImage *img_print = NULL;
	ASSERT(Image != NULL);//Image can't be NULL

	if (Image->nChannels == 1 || Image->nChannels == 3)
	{
		img_print = cvCreateImage(oSize, IPL_DEPTH_8U, Image->nChannels);
		cvResize(Image, img_print, CV_INTER_LINEAR);
	}
	else if (Image->nChannels == 4)
	{
		ASSERT(0);//not now
		//convret to CH3
	}
	else
	{
		ASSERT(0);//Channels???
	}
	
	ASSERT(img_print != NULL);

	int x = 0; int y = 0;//offset shown picture
	int from_x = 0; int from_y = 0;//ROI left top corner

	if ( img_print->depth == IPL_DEPTH_8U)
	{
		uchar buffer[sizeof(BITMAPINFOHEADER) + 1024];
		BITMAPINFO* bmi = (BITMAPINFO*)buffer;
		int bmp_w = img_print->width, bmp_h = img_print->height;
		FillBitmapInfo(bmi, bmp_w, bmp_h, Bpp(img_print), img_print->origin);
		from_x = MIN(MAX(from_x, 0), bmp_w - 1);
		from_y = MIN(MAX(from_y, 0), bmp_h - 1);
		int sw = MAX(MIN(bmp_w - from_x, img_print->width), 0);
		int sh = MAX(MIN(bmp_h - from_y, img_print->height), 0);
		SetDIBitsToDevice(
			*dc, x, y, sw, sh, from_x, from_y, from_y, sh,
			img_print->imageData + from_y*img_print->widthStep,
			bmi, DIB_RGB_COLORS);
	}
	else
	{
		ASSERT(0);//Depth???
	}

	cvReleaseImage(&img_print);
	pWnd->ReleaseDC(dc);
	//release check
}
void MyToolBox::ShowImage(cv::Mat ImageMat, CWnd * pWnd, CvSize oSize)
{
	IplImage* Image = nullptr;
	Image = cvCloneImage(&(IplImage)ImageMat);

	CDC	*dc = pWnd->GetWindowDC();
	IplImage *img_print = NULL;
	ASSERT(Image != NULL);//Image can't be NULL

	if (Image->nChannels == 1 || Image->nChannels == 3)
	{
		img_print = cvCreateImage(oSize, IPL_DEPTH_8U, Image->nChannels);
		cvResize(Image, img_print, CV_INTER_LINEAR);
	}
	else if (Image->nChannels == 4)
	{
		ASSERT(0);//not now
				  //convret to CH3
	}
	else
	{
		ASSERT(0);//Channels???
	}

	ASSERT(img_print != NULL);

	int x = 0; int y = 0;//offset shown picture
	int from_x = 0; int from_y = 0;//ROI left top corner

	if (img_print->depth == IPL_DEPTH_8U)
	{
		uchar buffer[sizeof(BITMAPINFOHEADER) + 1024];
		BITMAPINFO* bmi = (BITMAPINFO*)buffer;
		int bmp_w = img_print->width, bmp_h = img_print->height;
		FillBitmapInfo(bmi, bmp_w, bmp_h, Bpp(img_print), img_print->origin);
		from_x = MIN(MAX(from_x, 0), bmp_w - 1);
		from_y = MIN(MAX(from_y, 0), bmp_h - 1);
		int sw = MAX(MIN(bmp_w - from_x, img_print->width), 0);
		int sh = MAX(MIN(bmp_h - from_y, img_print->height), 0);
		SetDIBitsToDevice(
			*dc, x, y, sw, sh, from_x, from_y, from_y, sh,
			img_print->imageData + from_y*img_print->widthStep,
			bmi, DIB_RGB_COLORS);
	}
	else
	{
		ASSERT(0);//Depth???
	}

	cvReleaseImage(&img_print);
	cvReleaseImage(&Image);
	pWnd->ReleaseDC(dc);
	//release check
}

void MyToolBox::lzShowCam(int index, CWnd * pWnd, CvSize oSize, bool loop)
{
	CvCapture *capture = cvCaptureFromCAM(index);
	IplImage *img_camera;
	img_camera = cvRetrieveFrame(capture);
	img_camera = cvRetrieveFrame(capture);//make shure that buffer is clean(some webcam problem)
	ShowImage(img_camera, pWnd, oSize);
	while (loop)
	{
		img_camera = cvRetrieveFrame(capture);
		ShowImage(img_camera, pWnd, oSize);
	}
}
void MyToolBox::lzShowCam(int index, CWnd * pWnd, bool loop)
{
	CvCapture *capture = cvCaptureFromCAM(index);
	IplImage *img_camera;
	img_camera = cvRetrieveFrame(capture);
	img_camera = cvRetrieveFrame(capture);//make shure that buffer is clean(some webcam problem)
	ShowImage(img_camera, pWnd, defaultSize);
	while (loop)
	{
		img_camera = cvRetrieveFrame(capture);
		ShowImage(img_camera, pWnd, defaultSize);
	}
}

//socket
void MyToolBox::lzSocketSend(CString strIP, int nPort, CString msg)
{
	AfxSocketInit();
	CSocket aSocket;

	char* cMsg;
	cMsg = new char[msg.GetLength()];

	if (!aSocket.Create())	{AfxMessageBox(L"Creat Faild");	return;}
	
	if (aSocket.Connect(strIP, nPort))
	{
		CStringToChar(msg, cMsg,sizeof(cMsg));
		aSocket.Send(cMsg, sizeof(cMsg));
	}
	else
	{AfxMessageBox(L"Creat Faild(Connect)");}

	delete[] cMsg;
	aSocket.Close();
}
void MyToolBox::lzSocketSend(CString strIP, int nPort, char * cMsg, int size)
{
	AfxSocketInit();
	CSocket aSocket;

	if (!aSocket.Create()) { AfxMessageBox(L"Creat Faild");	return; }

	if (aSocket.Connect(strIP, nPort))
	{
		aSocket.Send(cMsg, size);
	}
	else
	{
		AfxMessageBox(L"Creat Faild(Connect)");
	}
	aSocket.Close();
}

