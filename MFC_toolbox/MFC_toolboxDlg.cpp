
// MFC_toolboxDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFC_toolbox.h"
#include "MFC_toolboxDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_toolboxDlg 對話方塊



CMFC_toolboxDlg::CMFC_toolboxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_TOOLBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_toolboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE_show, m_img_show);
}

BEGIN_MESSAGE_MAP(CMFC_toolboxDlg, CDialogEx)
		ON_BN_CLICKED(IDC_BUTTON1, &CMFC_toolboxDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC_toolboxDlg 訊息處理常式

BOOL CMFC_toolboxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}


void CMFC_toolboxDlg::OnBnClickedButton1()
{
	MyToolBox TB;
	IplImage* img_load = nullptr;
	cv::Mat img_loadMat;
	img_loadMat = cvLoadImage("C:\\FIRE.jpg",0);

	while(1)
	TB.ShowImage(img_loadMat,GetDlgItem(IDC_IMAGE_show),cvSize(img_loadMat.cols, img_loadMat.rows));
	//TB.ShowImage(img_load, GetDlgItem(IDC_IMAGE_show));

	//TB.lzShowCam(0,GetDlgItem(IDC_IMAGE_show), cvSize(640, 480));

	char a[20] = {"abcdefghijklmnopqrs"};
	TB.toCString(a);
                              
}
