#pragma once

enum class PlayType {
	PLAY,PAUSE,RESTART,CLOSE
};

class mci
{
public:
	void PlayBgm(LPCWSTR _soundname, int _volume, PlayType type);
	void PlayEffect(LPCWSTR _soundname);
};

