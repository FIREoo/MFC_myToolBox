
// MFC_toolboxDlg.h : 標頭檔
//



#pragma once
//專案相依性 設定!!
#include"..//MyToolBox/MyToolBox.h"
#include "afxwin.h"

// CMFC_toolboxDlg 對話方塊
class CMFC_toolboxDlg : public CDialogEx
{
// 建構
public:
	CMFC_toolboxDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_TOOLBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
   	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	CStatic m_img_show;
};
