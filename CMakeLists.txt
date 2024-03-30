cmake_minimum_required(VERSION 3.0)

project(webassembly-app)

add_subdirectory(deps/webassembly-framework)


file(GLOB sourceFiles "include/app.h"
                      "src/app.cpp")


include_directories(include)
include_directories(deps/webassembly-framework/include)
include_directories(deps/webassembly-framework/deps/imgui/repo)

if (NOT EMSCRIPTEN)
    include_directories(deps/webassembly-framework/deps/glad/include)
else()
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -sUSE_GLFW=3 --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/deps/webassembly-framework/deps/imgui/repo/examples/libs/emscripten/shell_minimal.html")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_executable       (webassembly-app ${sourceFiles})
target_link_libraries(webassembly-app webassembly-framework)


