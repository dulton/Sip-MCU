
// VideoConfClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVideoConfClientApp:
// �йش����ʵ�֣������ VideoConfClient.cpp
//

class CVideoConfClientApp : public CWinAppEx
{
public:
	CVideoConfClientApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVideoConfClientApp theApp;