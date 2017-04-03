
// MFC_toolboxDlg.cpp : ��@��
//

#include "stdafx.h"
#include "MFC_toolbox.h"
#include "MFC_toolboxDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_toolboxDlg ��ܤ��



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


// CMFC_toolboxDlg �T���B�z�`��

BOOL CMFC_toolboxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO: �b���[�J�B�~����l�]�w

	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
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
