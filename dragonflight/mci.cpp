#include<Windows.h>
#include<mmsystem.h>
#include<Digitalv.h>
#include<string>
#pragma comment(lib, "winmm.lib")
#include "mci.h"

UINT Bgmid;
UINT Effectid;

void mci::PlayBgm(LPCWSTR _soundname, int _volume,PlayType type)
{
	mciSendCommand(Bgmid, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
	// OPEN
	MCI_OPEN_PARMS openBgm;
	// mp3: mpegvideo, wav: waveaudio, avi: avivideo
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	openBgm.lpstrElementName = _soundname;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	Bgmid = openBgm.wDeviceID;

	std::wstring msg = L"setaudio " + std::wstring(_soundname) +
		L" volume to " + std::to_wstring(_volume);
	mciSendString(msg.c_str(), NULL, NULL, NULL);
	
	// PLAY
	MCI_PLAY_PARMS playBgm;

	switch (type)
	{
	case PlayType::PLAY:
		mciSendCommand(Bgmid, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
		break;
	case PlayType::PAUSE:
		mciSendCommand(Bgmid, MCI_PAUSE, MCI_NOTIFY, (DWORD_PTR)&playBgm);
		break;
	case PlayType::RESTART:
		mciSendCommand(Bgmid, MCI_RESUME, NULL, NULL);
		break;
	case PlayType::CLOSE:
		mciSendCommand(Bgmid, MCI_CLOSE, NULL, NULL);
		break;
	}
}

void mci::PlayEffect(LPCWSTR _soundname)
{
	// OPEN
	MCI_OPEN_PARMS openEffect;
	// mp3: mpegvideo, wav: waveaudio, avi: avivideo
	openEffect.lpstrDeviceType = TEXT("mpegvideo");
	openEffect.lpstrElementName = _soundname;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
	Effectid = openEffect.wDeviceID;

	// PLAY
	MCI_PLAY_PARMS playEffect;
	mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
	mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
	mciSendCommand(Effectid, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
}
