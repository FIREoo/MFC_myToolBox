
// MFC_toolboxDlg.h : ���Y��
//



#pragma once
//�M�׬̩ۨ� �]�w!!
#include"..//MyToolBox/MyToolBox.h"
#include "afxwin.h"

// CMFC_toolboxDlg ��ܤ��
class CMFC_toolboxDlg : public CDialogEx
{
// �غc
public:
	CMFC_toolboxDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_TOOLBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
   	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	CStatic m_img_show;
};
