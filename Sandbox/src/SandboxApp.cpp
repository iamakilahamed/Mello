#include <Mello.h>

class Sandbox : public Mello::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Mello::Application* Mello::CreateApplication()
{
	return new Sandbox();
}