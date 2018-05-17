#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>
#include <stdio.h>
#include "debug.h"

#define APP_SHORT_NAME "Short app name"
#define APP_WINDOWPOS_X SDL_WINDOWPOS_UNDEFINED
#define APP_WINDOWPOS_Y SDL_WINDOWPOS_UNDEFINED
#define APP_WINDOW_HEIGHT 640
#define APP_WINDOW_WIDTH 480



int main(int argc, char* argv[]) {

	SDL_Window * window;
	SDL_Init (SDL_INIT_VIDEO | SDL_WINDOW_VULKAN);
	window = SDL_CreateWindow 
	(
		APP_SHORT_NAME, 
		APP_WINDOWPOS_X, 
		APP_WINDOWPOS_Y, 
		APP_WINDOW_HEIGHT, 
		APP_WINDOW_WIDTH, 
		SDL_WINDOW_SHOWN
	);

	ASSERTF (window != NULL, "SDL window is null!");
	
	// Check that the window was successfully created
	if (window == NULL) {
	// In the case that the window could not be made...
	printf("Could not create window: %s\n", SDL_GetError());
	return 1;
	}

	struct VkApplicationInfo applicationInfo;
	struct VkInstanceCreateInfo instanceInfo;
	VkInstance instance;


	// Filling out application description:
	// sType is mandatory
	applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	// pNext is mandatory
	applicationInfo.pNext = NULL;
	// The name of our application
	applicationInfo.pApplicationName = "Tutorial 1";
	// The name of the engine (e.g: Game engine name)
	applicationInfo.pEngineName = NULL;
	// The version of the engine
	applicationInfo.engineVersion = 1;
	// The version of Vulkan we're using for this application
	applicationInfo.apiVersion = VK_API_VERSION_1_0;

	// Filling out instance description:
	// sType is mandatory
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	// pNext is mandatory
	instanceInfo.pNext = NULL;
	// flags is mandatory
	instanceInfo.flags = 0;
	// The application info structure is then passed through the instance
	instanceInfo.pApplicationInfo = &applicationInfo;
	// Don't enable and layer
	instanceInfo.enabledLayerCount = 0;
	instanceInfo.ppEnabledLayerNames = NULL;
	// Don't enable any extensions
	instanceInfo.enabledExtensionCount = 0;
	instanceInfo.ppEnabledExtensionNames = NULL;

	// Now create the desired instance
	VkResult result = vkCreateInstance(&instanceInfo, NULL, &instance);
	if (result != VK_SUCCESS) {
	fprintf(stderr, "Failed to create instance: %d\n", result);
	abort();
	}

	// The window is open: could enter program loop here (see SDL_PollEvent())

	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}
