#include "stdsrs.h"
#include "Settings.h"

#include "glm/glm.hpp"

namespace Options {

	Options::Options(const std::string& filepath)
	{
		m_Filepath = filepath;

		if (this->OpenFile() > 0)
		{
			this->CreateFile();
			if (this->OpenFile() > 0) 
			{
				std::cout << "Can not create file with that name!" << std::endl;
			}
		}
		this->ReadFile();
		this->ValidateOptions();
	}

	Options::~Options()
	{
		WriteFile();
		fclose(m_FileRef);
	}

	uint32_t Options::OpenFile()
	{
		m_FileRef = nullptr;

		fopen_s(&m_FileRef, m_Filepath.c_str(), "r+");

		if (m_FileRef == nullptr)
		{
			return 1;
		}
		return 0;
	}

	void Options::ReadFile()
	{
		
		fseek(m_FileRef, 0, SEEK_SET);
		fscanf_s(m_FileRef, WINSET_FORMAT_IN,
			&m_WindowSettings.WindowWidth, &m_WindowSettings.WindowHeight, &m_WindowSettings.IsFullscreen,
			&m_UserPrefererences.MSAA, &m_UserPrefererences.VSync, &m_UserPrefererences.Language, 2
		);
	}

	void Options::WriteFile()
	{
		fseek(m_FileRef, 0, SEEK_SET);
		fprintf_s(m_FileRef, WINSET_FORMAT_OUT,
			m_WindowSettings.WindowWidth, m_WindowSettings.WindowHeight, m_WindowSettings.IsFullscreen,
			m_UserPrefererences.MSAA, m_UserPrefererences.VSync, m_UserPrefererences.Language
		);
	}

	void Options::CreateFile()
	{
		std::ofstream newFile(m_Filepath.c_str());
		newFile.close();
	}

	void Options::ValidateOptions()
	{
		if (m_WindowSettings.WindowWidth < 30 || m_WindowSettings.WindowWidth > 4096)
			m_WindowSettings.WindowWidth = 720;
		if (m_WindowSettings.WindowHeight < 30 || m_WindowSettings.WindowHeight > 2160)
			m_WindowSettings.WindowHeight = 1280;
		if (m_WindowSettings.IsFullscreen > 1 || m_WindowSettings.IsFullscreen < 0)
			m_WindowSettings.IsFullscreen = 0;
		
		if (m_UserPrefererences.MSAA > 16 || m_UserPrefererences.MSAA < 1)
			m_UserPrefererences.MSAA = 2;
		if (m_UserPrefererences.VSync > 1 || m_UserPrefererences.VSync < 0)
			m_UserPrefererences.VSync = 1;
		if (m_UserPrefererences.Language > SWEDISH || m_UserPrefererences.Language < ENGLISH)
			m_UserPrefererences.Language = ENGLISH;
		
	}

}