#include "SoundManager.h"

#include <vector>

namespace game 
{

	void SoundManager::AddSound(std::string name, std::string path, bool loop) 
	{
		SoundBuffer buffer;
		buffer.loadFromFile(path);

		SoundBox* NewS = new SoundBox();
		NewS->name = name;
		NewS->sound.setBuffer(buffer);
		NewS->loop = loop;

		sounds.push_back(NewS);
	}

	void SoundManager::AddMusic(string name, string path, bool loop)
	{
		MusicBox* NewM = new MusicBox();
		NewM->name = name;
		NewM->music.openFromFile(path);
		NewM->loop = loop;

		musics.push_back(NewM);
	}

	SoundManager::SoundManager()
	{
		soundVolume = 1.f;
		musicVolume = 0.5f;

		currentMusic = nullptr;
	}

	SoundManager::~SoundManager()
	{
		for (int i = 0; i < sounds.size(); i++)
		{
			delete sounds[i];
		}

		for (int i = 0; i < musics.size(); i++)
		{
			delete musics[i];
		}
	}

	void SoundManager::Update()
	{
		currentMusic->setVolume(musicVolume);
	}

	void SoundManager::PlayS(string name)
	{
		if (sounds.size() <= 0)
			return;

		Sound Sound{};

		for (int i = 0; i < static_cast<int>(sounds.size()); i++) {
			if (sounds[i] != nullptr)
				if (name == sounds[i]->name)
					Sound = sounds[i]->sound;
		}

		Sound.play();
		Sound.setVolume(soundVolume);
	}

	void SoundManager::StopS(string name)
	{
		if (sounds.size() <= 0)
			return;

		Sound sound{};

		for (int i = 0; i < static_cast<int>(sounds.size()); i++) {
			if (sounds[i] != nullptr)
				if (name == sounds[i]->name)
					sound = sounds[i]->sound;
		}

		sound.stop();
	}

	void SoundManager::PlayM(string name)
	{
		if (musics.size() <= 0)
			return;

		Music newMusic;

		for (int i = 0; i < static_cast<int>(musics.size()); i++) {
			if (musics[i] != nullptr)
				if (name == musics[i]->name)
					currentMusic = &musics[i]->music;
		}

		currentMusic->play();
	}

	void SoundManager::StopM(string name)
	{
		if (musics.size() <= 0)
			return;

		Music sound{};

		for (int i = 0; i < static_cast<int>(musics.size()); i++) {
			if (musics[i] != nullptr)
				if (name == musics[i]->name)
					currentMusic = &musics[i]->music;
		}

		currentMusic->stop();
	}

	void SoundManager::AddSoundVolume()
	{

		soundVolume = (soundVolume < 1.f) ? soundVolume + 0.1f : 1.f;
	}

	void SoundManager::RemoveSoundVolume()
	{

		soundVolume = (soundVolume > 0.f) ? soundVolume - 0.1f : 0.f;
	}

	void SoundManager::AddMusicVolume()
	{

		musicVolume = (musicVolume < 1.f) ? musicVolume + 0.1f : 1.f;
	}

	void SoundManager::RemoveMusicVolume()
	{

		musicVolume = (musicVolume > 0.f) ? musicVolume - 0.1f : 0.f;
	}

	int SoundManager::GetSoundVolume()
	{

		return static_cast<int>(soundVolume * 100);
	}

	int SoundManager::GetMusicVolume()
	{

		return static_cast<int>(musicVolume * 100);
	}

	void SoundManager::SetSoundVolume(int volume)
	{

		soundVolume = volume / 100.f;
	}

	void SoundManager::SetMusicVolume(int volume)
	{

		musicVolume = volume / 100.f;
	}

	void SoundManager::LoadSounds()
	{
		
	}
}
