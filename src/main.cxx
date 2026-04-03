#include "Penguine.hxx"
#include "mathematics/Vec.hxx"
#include "rendering/Mesh.hxx"
#include <vector>

class SoulsLike : public Penguine::Application
{
  public:
	Penguine::Rendering::Shader shader;
	Penguine::Rendering::Mesh	mesh;
	SoulsLike()
		: Penguine::Application({
			  {
				  {
					  1280,
					  720,
				  },
			  },
			  false,
			  "Hello",
		  }),
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

	void Update(float deltaTime) override
	{
		shader.Use();
		shader.SetVec("ourColor", Penguine::Math::Vec<float, 3>({1.0f, 0.5f, 0.2f}));

		mesh.Draw(shader);
	}
};

int main()
{
	auto app = new SoulsLike();
	app->Run();
	return 0;
}