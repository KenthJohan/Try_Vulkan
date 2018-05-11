glslangValidator.exe -V src/shader.vert -o bin/vert.spv
glslangValidator.exe -V src/shader.frag -o bin/frag.spv

g++ src/main.cpp -obin/main.exe -Ilib/glfw-3.2.1.bin.WIN64/include -IC:/VulkanSDK/1.1.73.0/Include -LC:/VulkanSDK/1.1.73.0/Lib -lvulkan-1 -Llib/glfw-3.2.1.bin.WIN64/lib-mingw-w64 -lglu32 -lopengl32 -lglfw3 -mwindows
::gprbuild

cd bin
main.exe
cd ..
