#pragma once

namespace Options {
	
	enum Languages
	{
		ENGLISH, SWEDISH
	};
	
#pragma region Structs
	typedef struct WindowSettings
	{
		int32_t WindowWidth; // 30 - 4096 
		int32_t WindowHeight; // 30 - 2160 
		int32_t IsFullscreen; // 0(false) / 1(true)
	} WindowSettings;

	typedef struct UserPrefererences
	{
		int32_t MSAA; // 1-16
		int32_t VSync; // 0(false) / 1(true) 
		int32_t Language; // en(0) / sv(1)
	} UserPrefererences;
#pragma endregion

	class Options
	{
	public:
		Options(const std::string& filepath);
		~Options();

#pragma region WindowSettings
	public: 
		uint32_t GetWindowWidth() { return m_WindowSettings.WindowWidth; }
		void SetWindowWidth(int value) { m_WindowSettings.WindowWidth= value; }

		uint32_t GetWindowHeight() { return m_WindowSettings.WindowHeight; }
		void SetWindowHeight(int value) { m_WindowSettings.WindowHeight = value; }

		uint32_t GetFullscreen() { return m_WindowSettings.IsFullscreen; }
		void SetFullscreen(bool value) { value ? m_WindowSettings.IsFullscreen = 1 : 0; }
#pragma endregion

#pragma region UserPrefererences
	public: 
		uint32_t GetMSAA() { return m_UserPrefererences.MSAA; }
		void SetMSAA(int value) { m_UserPrefererences.MSAA = value; }

		uint32_t GetVSync() { return m_UserPrefererences.VSync; }
		void SetVSync(bool value) { value ? m_UserPrefererences.VSync = 1 : 0; }

		uint32_t GetLanguage() { return m_UserPrefererences.MSAA; }
		void SetLanguage(int value) { m_UserPrefererences.MSAA = value; }
#pragma endregion

	private:
		uint32_t OpenFile();
		void ValidateOptions();
		void ReadFile();
		void WriteFile();
		void CreateFile();
	
	private:
		std::string m_Filepath;
		FILE* m_FileRef;

		WindowSettings m_WindowSettings = { 0 };
		UserPrefererences m_UserPrefererences = { 0 };

#pragma region FORMAT
		const char* WINSET_FORMAT_IN = "\
WindowWidth:%d \n\
WindowHeight:%d \n\
IsFullscreen:%d \n\
MSAA:%d \n\
VSync:%d \n\
Language:%d \n\
";
		const char* WINSET_FORMAT_OUT = "\
WindowWidth:%d \n\
WindowHeight:%d \n\
IsFullscreen:%d \n\
MSAA:%d \n\
VSync:%d \n\
Language:%d \n\
";
#pragma endregion

	};

}

