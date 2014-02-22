
// VideoPlayerDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VideoPlayerDemo.h"
#include "VideoPlayerDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "mediastreamer2/mediastream.h"
#include "mediastreamer2/mssndcard.h"

#include "file_stream.h"
static VideoPlayer *video_player=NULL;
static VideoState *video_in_stream=NULL;

static int mediastream_init(){
	ms_init();
	return 0;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CVideoPlayerDemoDlg �Ի���

CVideoPlayerDemoDlg::CVideoPlayerDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoPlayerDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVideoPlayerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_VIDEO_VIEW, mVideoView);
	DDX_Control(pDX, IDC_BUTTON_OPEN_FILE, mPlayBtn);
	DDX_Control(pDX, IDC_SLIDER_FILE_POS, mVideoPos);
}

BEGIN_MESSAGE_MAP(CVideoPlayerDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_OPEN_FILE, &CVideoPlayerDemoDlg::OnBnClickedButtonOpenFile)
END_MESSAGE_MAP()


// CVideoPlayerDemoDlg ��Ϣ�������

BOOL CVideoPlayerDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	mVideoPos.SetRangeMax(100,TRUE);

	mediastream_init(); /*��ʼ��ý���*/
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CVideoPlayerDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVideoPlayerDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVideoPlayerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVideoPlayerDemoDlg::OnBnClickedButtonOpenFile()
{

	MSSndCardManager *snd_manager = ms_snd_card_manager_get();
	MSSndCard *default_snd = ms_snd_card_manager_get_default_card(snd_manager);

	if(video_in_stream==NULL && video_player==NULL && default_snd)
	{

		mVideoPos.SetPos(0);
		video_in_stream = file_stream_new();

		if(video_in_stream){
			file_stream_init(video_in_stream);

		}
		video_player =  video_player_new(); /*����player*/

		if(video_player){
			video_player_set_rate(video_player,16000); //������Ƶ���������
			video_player_set_nchannels(video_player,2); //�����������
			video_player_set_video_size(video_player,file_stream_video_get_vsize(video_in_stream));
		}

		video_player_set_fps(video_player,file_stream_video_get_fps(video_in_stream));

		video_player_start(video_player,
			default_snd,
			ms_file_player_snd_new(video_in_stream),
			ms_file_player_cam_new(video_in_stream),
			(unsigned long)mVideoView.m_hWnd);

	}else{
		if(video_player!=NULL) video_player_stop(video_player); video_player=NULL;

		if(video_in_stream!=NULL)
		{
			file_stream_stop(video_in_stream);
			file_stream_destory(video_in_stream);
			video_in_stream=NULL;
		}

		mPlayBtn.SetWindowText("���ļ�");

	}

	if(video_in_stream)
	{
		if(file_stream_is_playling(video_in_stream)) 
			file_stream_stop(video_in_stream);

		CString tmp;
		CFileDialog fdlg(TRUE,NULL,NULL,NULL,"MP4 mp4(.mp4)|*.mp4|AVI avi(.avi)|*.avi|�����ļ� (*.*)|*.*||");
		if(IDOK==fdlg.DoModal())
		{
			tmp=fdlg.GetPathName();
			if(file_stream_open(video_in_stream,tmp.GetString())<0)
			{
				CString tmp;
				tmp.Format("�޷����ļ�: %s",tmp);
				MessageBox(tmp);
				return;
			}
			file_stream_start(video_in_stream);
			file_stream_output_data(video_in_stream,TRUE);

			mPlayBtn.SetWindowText("ֹͣ����");

		}
	}
}


//�������ʹ���E
void CVideoPlayerDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{

	CSliderCtrl *m_bar=(CSliderCtrl *)pScrollBar;

	if(m_bar== &mVideoPos){
		if(video_in_stream && file_stream_is_playling(video_in_stream))
			file_stream_do_seek(video_in_stream,mVideoPos.GetPos());
	}


	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}