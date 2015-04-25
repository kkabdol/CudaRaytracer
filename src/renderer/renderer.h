#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "SDL.h"


#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>

#include "math/math.h"
#include "scene/scene.h"

namespace acr
{

	class Renderer
	{
	public:

		struct Args
		{
			const char *title;
			math::u32vec2 pos, dim;
		};

		Renderer(const Args &args);
		~Renderer();

		void loadScene(const Scene &scene);

		void render();
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;

		const char *title;
		math::u32vec2 dim;

		GLuint drawBuffer;
		GLuint textureId;
	};

} // namespace acr

#endif //_RENDERER_H_
