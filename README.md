# SDL2 & OpenGL in C really minimal

Yesterday I spend about an hour to find usable
SDL2 & OpenGL skelleton source code to start a project.

By usable I mean:

- not using C++ headers if it is just for some error messages
- not including SDL1.2 headers by mistake  
Including SDL/SDL_opengl.h is wrong, too!
- including SDL2s prepared OpenGL headers  
I use SDL2/SDL_opengles2.h here, but just look into the directory -  
You'll surely find what you want there.
- not mixing it up with **glfw** and alike
- generally speaking not including anything, which should be handled by SDL2 anyway  
- requiring only one file to compile since the rest is up to you
- keeping it short (as in less then 50 lines)

This is based on [cemegginson/SDL2-Demo](https://github.com/cemegginson/SDL2-Demo).

### What it does
Since this is meant to be a starting point for your own work,
it doesn't do much.  
If everything is set up correctly on your system you should see
a window filled in green for 2 seconds and there should be
a string describing which OpenGL version was used.  
If not, there should be some error message, explaining where it failed and why.

### Compile
I didn't try anything else besides Linux/x64 & gcc.

    gcc -D_REENTRANT -I/usr/include/SDL2 main.c -lSDL2 -lGL -o main