
// ScreenRecorderDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CScreenRecorderDlg �Ի���
class CScreenRecorderDlg : public CDialog
{
// ����
public:
	CScreenRecorderDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SCREENRECORDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit mFileName;
	afx_msg void OnBnClickedButtonCapture();
	CEdit mWndPreView;
	CButton mRecBtn;
};
