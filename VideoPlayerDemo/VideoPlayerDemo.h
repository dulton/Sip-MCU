
// VideoPlayerDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVideoPlayerDemoApp:
// �йش����ʵ�֣������ VideoPlayerDemo.cpp
//

class CVideoPlayerDemoApp : public CWinAppEx
{
public:
	CVideoPlayerDemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVideoPlayerDemoApp theApp;