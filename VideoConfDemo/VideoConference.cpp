
// VideoConference.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "VideoConference.h"
#include "VideoConferenceDlg.h"
/*
#include "SkinMagicLib.h"
#pragma comment(lib, "SkinMagic.lib")*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef WIN32
#include "mdump.h"
#define szAppName "VideoConference"
MiniDumper gDumper(szAppName);
#endif

// CVideoConferenceApp

BEGIN_MESSAGE_MAP(CVideoConferenceApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CVideoConferenceApp ����

CVideoConferenceApp::CVideoConferenceApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CVideoConferenceApp ����

CVideoConferenceApp theApp;


// CVideoConferenceApp ��ʼ��

BOOL CVideoConferenceApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();
/*
	VERIFY( 1 == InitSkinMagicLib( AfxGetInstanceHandle(), _T("ReadUI") ,NULL,NULL ) );
	//VERIFY( 1 == LoadSkinFile("vistayellow.smf"));
	VERIFY( 1 == LoadSkinFromResource( AfxGetInstanceHandle()  ,MAKEINTRESOURCE(IDR_SMF) ,"SMF") ); 
	VERIFY( 1 == SetDialogSkin("Dialog")); 
*/
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CVideoConferenceDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
