A template application which builds on top of webassembly-framework.

How to use this?

1. Emscripten

Copy the build_emscripten_cmake.bat over to root directory of this project. \
Launch Emscripten command line. Yes, it generates a build with all the funny symbols, I know. \
Launch the said script. \
Go to the build_cmake directory once it's done crunching. \
Run python -m http.server \
Point your browser to http://localhost:8000. \
Yay.


2. Windows (Visual Studio 2019)

Copy the build_vs16_cmake.bat over to root directory of this project. \
Launch the said script. Yes, it's a debug build, I know. \
Go to build/debug. \
Launch webassembly.exe. \
Yay.
