
// VideoPlayerDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CVideoPlayerDemoDlg �Ի���
class CVideoPlayerDemoDlg : public CDialog
{
// ����
public:
	CVideoPlayerDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VIDEOPLAYERDEMO_DIALOG };

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
	afx_msg void OnBnClickedButtonOpenFile();
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CEdit mVideoView;
	CButton mPlayBtn;
	CSliderCtrl mVideoPos;
};
