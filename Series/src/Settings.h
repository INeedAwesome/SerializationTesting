#pragma once

namespace Options {

	typedef struct WindowSettings
	{
		int32_t WindowWidth;
		int32_t WindowHeight;
		char WindowTitle[64];
		int32_t IsFullscreen;
	} WindowSettings;

	typedef struct UserPrefrerences
	{
		int32_t MSAA;
		int32_t VSync;
		char Language[2]; // en / sv
	} UserPrefrerences;

	class Options
	{
	public:
		Options(const std::string& filepath);
		~Options();

		std::string ReadValue(const std::string& name);
		
		void ValidateOptions();
		void ReadFile();
		void WriteFile();

		WindowSettings m_WindowSettings = { 0 };
		UserPrefrerences m_UserPrefrerences = { 0 };

	private:
		void OpenFile(const std::string& filepath);
		
		std::string m_Filepath;
		FILE* m_fileRefToPath;

		const char* WINSET_FORMAT_IN = "\
WindowWidth:%d \n\
WindowHeight:%d \n\
WindowTitle:'%[^']' \n\
IsFullscreen:%d \n\
MSAA:%d \n\
VSync:%d \n\
Language:'%[^']' \n\
";
		const char* WINSET_FORMAT_OUT = "\
WindowWidth:%d \n\
WindowHeight:%d \n\
WindowTitle:'%s' \n\
IsFullscreen:%d \n\
MSAA:%d \n\
VSync:%d \n\
Language:'%s' \n\
";
	};

}

