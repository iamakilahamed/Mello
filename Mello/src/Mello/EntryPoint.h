#pragma once

#ifdef MELLO_PLATFORM_WINDOWS

extern Mello::Application* Mello::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Mello::CreateApplication();
	app->Run();
	delete app;
}

#endif