#include "Penguine.hxx"
#include "mathematics/Vec.hxx"
#include "rendering/Mesh.hxx"

class SoulsLike : public Penguine::Application
{
  public:
	Penguine::Rendering::Shader shader;
	Penguine::Rendering::Mesh	mesh;
	SoulsLike()
		: Penguine::Application(
			  {
				  {
					  {
						  1280,
						  720,
					  },
				  },
				  false,
				  "Hello",
			  },
			  60),
		  shader("../assets/shaders/Basic.vert", "../assets/shaders/Basic.frag"),
		  mesh(
			  {
				  {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
				  {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
				  {{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.5f, 1.0f}},
			  },
			  {
				  {{0, 1, 2}},
			  })
	{
	}

	void Update(double deltaTime) override
	{
	}

	void Render() override
	{
		shader.Use();
		shader.SetVec("ourColor", Penguine::Math::Vec<float, 3>({0.3f, 0.4f, 0.5f}));
		mesh.Draw(shader);
	}
};

int main()
{
	auto app = new SoulsLike();
	app->Run();
	return 0;
}