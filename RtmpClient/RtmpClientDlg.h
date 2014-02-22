
// RtmpClientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CRtmpClientDlg �Ի���
class CRtmpClientDlg : public CDialog
{
// ����
public:
	CRtmpClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RTMPCLIENT_DIALOG };

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
	CEdit mServerIP;
	CButton mChkAppend;
	CButton mChkRecord;
	CEdit mPubPasswd;
	CEdit mPubUser;
	CEdit mStreamName;
	CButton mChkLive;
	CEdit mEditLogOutput;
	CEdit mVideoView;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox mCamera;
	CComboBox mMicphone;
	CComboBox mBandWidth;
	afx_msg void OnCbnSelchangeComboSizeBw();
	afx_msg void OnBnClickedCheckVideoPreview();
	CButton mChkPreView;
	afx_msg void OnBnClickedButtonPublish();
	bool in_pulishing;
	CButton mBntPublish;
	int PublishVideoStream(void);
	void UnPublishStream(void);
	CSliderCtrl mInputValue;
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	bool m_bInitDialog;
	bool m_bAutoLineScroll;
	void CRtmpClientDlg::Log(CString szText,COLORREF color);
	CString CRtmpClientDlg::GetTime();
	CRichEditCtrl m_RichEdit;
	afx_msg void OnCbnSelchangeComboCamera();
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LRESULT OnLogMsgHandler(WPARAM,LPARAM);
	afx_msg void OnDestroy();
	void SaveConfigs(void);
	void LoadConfigs(void);
	CComboBox mFpsList;
};
