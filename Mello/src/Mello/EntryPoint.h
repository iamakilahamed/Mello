#pragma once

#ifdef MELLO_PLATFORM_WINDOWS

extern Mello::Application* Mello::CreateApplication();

int main(int argc, char** argv)
{
	Mello::Log::Init();
	MELLO_CORE_WARN("Initialized Log!");
	int a = 5;
	MELLO_INFO("Hello! Var={0}", a);

	auto app = Mello::CreateApplication();
	app->Run();
	delete app;
}

#endif