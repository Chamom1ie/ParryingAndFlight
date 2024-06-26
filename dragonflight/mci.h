#pragma once
#include<Windows.h>
#include<mmsystem.h>
#include<Digitalv.h>
#include<string>
enum class PlayType {
	PLAY = 0, PAUSE, RESTART, CLOSE
};
class mci
{
public:
	void PlayBgm(LPCWSTR _soundname, int _volume,PlayType type);
};

