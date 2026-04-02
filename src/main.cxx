#include "Penguine.hxx"

class SoulsLike : public Penguine::Application
{
  public:
	SoulsLike() : Penguine::Application({{{1280, 720}}, false, "Hello"})
	{
	}
};

int main()
{
	auto app = new SoulsLike();
	app->Run();
	return 0;
}