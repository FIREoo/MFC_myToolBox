
// MFC_toolbox.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFC_toolboxApp: 
// �аѾ\��@�����O�� MFC_toolbox.cpp
//

class CMFC_toolboxApp : public CWinApp
{
public:
	CMFC_toolboxApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFC_toolboxApp theApp;