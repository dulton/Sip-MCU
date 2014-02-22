
// VideoConfClientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CVideoConfClientDlg �Ի���
class CVideoConfClientDlg : public CDialog
{
// ����
public:
	CVideoConfClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VIDEOCONFCLIENT_DIALOG };

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
	CStatic mStatus;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	CEdit mVideoView;
	CEdit mHost;
	CEdit mPassword;
	CEdit mUsername;
	afx_msg void OnBnClickedButtonReg();
	afx_msg void OnBnClickedButtonUnreg();
	CComboBox mMicphone;
	CComboBox mSpeaker;
	CComboBox mCamera;
	afx_msg void OnCbnSelchangeComboInput();
	afx_msg void OnCbnSelchangeComboOutput();
	afx_msg void OnCbnSelchangeComboCamera();
	afx_msg void OnBnClickedCheckAec();
	afx_msg void OnBnClickedCheckAgc2();
	CButton mEchoCancel;
	CButton mAutomicGainControl;
	CEdit mDialStr;
	afx_msg void OnBnClickedButtonDial();
	CButton mURImode;
	afx_msg void OnBnClickedButtonHangup();
	afx_msg void OnBnClickedCheckSelfView();
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CButton mSelfView;
	CSliderCtrl mInputValue;
	CSliderCtrl mOutputValue;
	afx_msg void OnBnClickedButtonCaptureImage();
	afx_msg void OnBnClickedButtonUdt();
	CComboBox mBandWidth;
	afx_msg void OnCbnSelchangeComboBandwith();
	CButton mVideoViewMode;
	afx_msg void OnBnClickedCheckVideoMode();
	afx_msg void OnBnClickedCheckVideoPreview();
	CButton mVideoPreViewChk;
	afx_msg void OnBnClickedButtonVideoRecord();
	CButton mRtmpPublishChk;
	CButton mRecrodBnt;
	CEdit mRTMP_URL;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButtonFastUpdate();
};
