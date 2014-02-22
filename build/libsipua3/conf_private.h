#ifndef _CONF_PRIVATE_H
#define _CONF_PRIVATE_H

#include "private.h"
#include "conf_itc.h"
#include "file_writer.h"

struct _LinphoneConferenceStream{
	int max_ports;
	int sample_rate;
	bool_t ptt_mode;
	bool_t has_video;
	MSTicker *audio_ticker;/*��Ƶ�߳�*/
	MSFilter *audio_mixer;/*������*/
	MSFilter *audio_filerecorder;/*¼�ƻ���*/
	MSFilter *audio_fileplayer;/*����¼��*/
	MSList *audio_ports;

	bool_t video_monitor; /* ���ؼ���*/
	bool_t auto_layout; /* �Զ����ֻ�̶�����*/
	char *display_name;
	char *static_image_path;
	MSVideoSize sent_vsize; /*��������ߴ�*/
	float fps;
	unsigned long video_window_id;/*��Ƶ�������*/
	MSList *video_ports;
	MSTicker *video_ticker; /*��Ƶ�߳�*/
	MSFilter *video_output;/*������Ƶ���*/
	MSFilter *video_mixer;/*��Ƶ����*/
	MSFilter *video_static_image;/*��Ա���ź�ʱ�����̬ͼƬռλ*/
	MSFilter *video_static_image_tee;/* ��̬ͼƬ������*/

	/*¼��*/
	VideoRecoder *os;
	int record_count;
	MSFilter *audio_record_sink;
	MSFilter *video_record_sink;
};

struct _LinphoneConference
{
	char *name;
	struct _LinphoneCore *core;
	MSList *members; /* �����Ա�б� */
	time_t start_time; /*���鿪ʼʱ��*/
	int max_users;   /*�����������*/

	int layout_index; /*��������*/
	int bit_rate;
	float fps;
	MSVideoSize vsize; /*��������ߴ�*/
	unsigned long video_window_id;/*��Ƶ�������*/
	bool_t video_enabled; /* ��Ƶ������Ƶ */
	bool_t video_monitor; /* ���ؼ���*/
	bool_t auto_layout; /* �Զ����ֻ�̶�����*/
	bool_t ptt_mode; /* PTTģʽ .*/
	bool_t hd_audio; /* 8K �� 16K ������Ƶģʽ*/
	bool_t local_mode; /*��������˵�ģʽ*/
	struct _LinphoneConferenceStream *conf_stream;/*����ý�����*/
	ConfSoundCard *local_sndcard;
	MSList *local_webcams; /*��������ͷ*/
	LinphoneConferenceStateCb conf_state_cb;
	LinphoneConferenceMemberStateCb conf_member_state_cb;
};



struct _LinphoneConferenceMember{
	const char *name;
	struct _LinphoneConference *conf; /* ����ָ��*/
	struct _LinphoneCall *call; /*�������ĺ���*/
	bool_t has_video; /* �Ƿ�����Ƶ */
	bool_t muted; /*�Ƿ���*/
	bool_t conf_admin;/*�Ƿ�Ϊ����������*/
	float mic_volume; /*����*/
	float spk_volume;
	int audio_port_index;
	int video_port_index;/*�ڻ����е�λ��*/
};

struct _ConfAudioPort{
	int index;
	bool_t muted;
	ConfSlotQueue slotq_in;
	ConfSlotQueue slotq_out;
	bool_t sink_connected;
	bool_t source_connected;
	MSFilter *audio_itc_sink;
	MSFilter *audio_itc_source;
};

//��������ͷ
struct _ConfWebCam{
	int video_port_index;/*ConfVideoPort ��Ӧ�˿ں�*/
	MSTicker *ticker;
	MSFilter *webcam;/*����ͷ*/
	MSFilter *sizeconv;/*����ͷ�ߴ�ת��*/
	MSFilter *pixconv;/*����ͷ��ʽת��*/
	MSFilter *itc_sink;
};


//��������
struct _ConfSoundCard{
	int audio_port_index;/*ConfAudioPort ��Ӧ�˿ں�*/
	MSTicker *ticker;
	MSFilter *capture_card;/*��˷�*/
	MSFilter *playback_card;/*/�������*/
	MSFilter *itc_sink;
	MSFilter *itc_source;
};


struct _ConfVideoPort{
	int index;
	bool_t muted;
	ConfSlotQueue slotq_in;
	ConfSlotQueue slotq_out;
	bool_t sink_connected;
	bool_t source_connected;
	MSFilter *video_itc_sink;
	MSFilter *video_itc_source;
	MSFilter *video_input_join;
};

#endif