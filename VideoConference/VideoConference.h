
// VideoConference.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVideoConferenceApp:
// �йش����ʵ�֣������ VideoConference.cpp
//

class CVideoConferenceApp : public CWinAppEx
{
public:
	CVideoConferenceApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVideoConferenceApp theApp;