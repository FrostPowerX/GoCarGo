#pragma once

#include <string>

#include <SFML/Audio.hpp>

#include "base/Singleton.h"

using namespace std;
using namespace sf;

namespace game
{
	struct SoundBox
	{
		Sound sound;
		string name;

		bool loop = false;
	};

	struct MusicBox
	{
		Music music;
		string name;

		bool loop = false;
	};

	class SoundManager : public Singleton<SoundManager>
	{
	private:

		float soundVolume;
		float musicVolume;

		vector<SoundBox*> sounds;
		vector<MusicBox*> musics;

		Music* currentMusic;

		void LoadSounds();

		void AddSound(string name, string path, bool loop = false);
		void AddMusic(string name, string path, bool loop = false);

	public:

		SoundManager();
		~SoundManager();

		void Update();

		void PlayS(string name);
		void StopS(string name);

		void PlayM(string name);
		void StopM(string name);

		void AddSoundVolume();
		void RemoveSoundVolume();

		void AddMusicVolume();
		void RemoveMusicVolume();

		int GetSoundVolume();
		int GetMusicVolume();

		void SetSoundVolume(int volume);
		void SetMusicVolume(int volume);
	};
}
