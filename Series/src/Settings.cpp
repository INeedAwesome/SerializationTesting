#include "stdsrs.h"
#include "Settings.h"

#include "glm/glm.hpp"

namespace Options {

	Options::Options(const std::string& filepath)
	{
		m_Filepath = filepath;
		std::cout << sizeof(m_UserPrefrerences.Language) << std::endl;
		this->OpenFile(m_Filepath);
		this->ReadFile();
		this->ValidateOptions();

	}

	Options::~Options()
	{
		WriteFile();
		fclose(m_fileRefToPath);
	}

	void Options::OpenFile(const std::string& filepath)
	{
		m_fileRefToPath = nullptr;

		fopen_s(&m_fileRefToPath, m_Filepath.c_str(), "r+");

		if (m_fileRefToPath == nullptr)
		{
			std::cout << "File: " << m_Filepath << " was not found!" << std::endl;
		}
	}

	void Options::ReadFile()
	{
		fseek(m_fileRefToPath, 0, SEEK_SET);
		fscanf_s(m_fileRefToPath, WINSET_FORMAT_IN,
			&m_WindowSettings.WindowWidth, &m_WindowSettings.WindowHeight, &m_WindowSettings.WindowTitle, 64, &m_WindowSettings.IsFullscreen,
			&m_UserPrefrerences.MSAA, &m_UserPrefrerences.VSync, &m_UserPrefrerences.Language, 2
		);
	}

	std::string Options::ReadValue(const std::string& name)
	{
		return "";

	}

	void Options::WriteFile()
	{
		fseek(m_fileRefToPath, 0, SEEK_SET);
		fprintf_s(m_fileRefToPath, WINSET_FORMAT_OUT,
			m_WindowSettings.WindowWidth, m_WindowSettings.WindowHeight, m_WindowSettings.WindowTitle, m_WindowSettings.IsFullscreen,
			m_UserPrefrerences.MSAA, m_UserPrefrerences.VSync, m_UserPrefrerences.Language
		);
	}

	void Options::ValidateOptions()
	{
		if (m_WindowSettings.WindowWidth < 30 || m_WindowSettings.WindowWidth > 4096)
			m_WindowSettings.WindowWidth = 720;
		if (m_WindowSettings.WindowHeight < 30 || m_WindowSettings.WindowHeight > 2160)
			m_WindowSettings.WindowHeight = 1280;
		if (m_WindowSettings.IsFullscreen > 1 || m_WindowSettings.IsFullscreen < 0)
			m_WindowSettings.IsFullscreen = 0;
		
		if (m_UserPrefrerences.MSAA > 16 || m_UserPrefrerences.MSAA < 1)
			m_UserPrefrerences.MSAA = 2;
		if (m_UserPrefrerences.VSync > 1 || m_UserPrefrerences.VSync < 0)
			m_UserPrefrerences.VSync = 1;
		if (m_UserPrefrerences.Language != "en" || m_UserPrefrerences.Language != "sv")
			m_UserPrefrerences.Language[0] = 'e'; m_UserPrefrerences.Language[1] = 'n';
		
	}

}