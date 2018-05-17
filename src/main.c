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

	ASSERTF (window != NULL, "Could not create window: %s", SDL_GetError());
	
	struct VkApplicationInfo applicationInfo;
	applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	applicationInfo.pNext = NULL;
	applicationInfo.pApplicationName = APP_SHORT_NAME;
	applicationInfo.pEngineName = NULL;
	applicationInfo.engineVersion = 1;
	applicationInfo.apiVersion = VK_API_VERSION_1_0;
	
	struct VkInstanceCreateInfo instanceInfo;
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pNext = NULL;
	instanceInfo.flags = 0;
	instanceInfo.pApplicationInfo = &applicationInfo;
	instanceInfo.enabledLayerCount = 0;
	instanceInfo.ppEnabledLayerNames = NULL;
	instanceInfo.enabledExtensionCount = 0;
	instanceInfo.ppEnabledExtensionNames = NULL;
	
	VkInstance instance;
	VkResult result = vkCreateInstance (&instanceInfo, NULL, &instance);
	ASSERTF (result == VK_SUCCESS, "Failed to create instance: %d", result);

	SDL_Delay (3000);
	SDL_DestroyWindow (window);
	SDL_Quit ();
	return 0;
}
