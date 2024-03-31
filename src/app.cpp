/*

    MIT License

    Copyright (c) 2024 Dominik Witczak

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

/* NOTE: This template is more or less a rip-off of GL-specific bits of the ImgUI example.
 *
 * Aims to be used as a starting point for actual apps.
 */
#include "framework.h"
#include "imgui.h"
#include "program.h"
#include "shader.h"

const char* g_fs_glsl = R"(#version 300 es

precision highp float;

layout(location = 0) out vec4 result;

uniform int width;
uniform int height;

void main()
{
    result = vec4(float(gl_FragCoord.x)                  / float(width  - 1),
                  float(gl_FragCoord.y)                  / float(height - 1),
                  float(gl_FragCoord.x + gl_FragCoord.y) / float(width + height - 2),
                  1.0);
}
)";

const char* g_vs_glsl = R"(#version 300 es

void main()
{
    switch (gl_VertexID)
    {
        case 0: gl_Position = vec4(-1.0f, -1.0f, 0.0f, 1.0f); break;
        case 1: gl_Position = vec4(-1.0f,  1.0f, 0.0f, 1.0f); break;
        case 2: gl_Position = vec4( 1.0f, -1.0f, 0.0f, 1.0f); break;
        case 3: gl_Position = vec4( 1.0f,  1.0f, 0.0f, 1.0f); break;
    }
})";

ShaderUniquePtr  g_fs_ptr;
GLint            g_program_height_uniform_location = -1;
GLint            g_program_width_uniform_location  = -1;
ProgramUniquePtr g_program_ptr;
ShaderUniquePtr  g_vs_ptr;


void imgui_callback()
{
    ImGui::Begin("Hello, world!");
    {
        ImGui::Text("This is some useful text.");
    }
    ImGui::End();
}

void init_program()
{
    g_fs_ptr = Shader::create(ShaderStage::FRAGMENT, g_fs_glsl);
    g_vs_ptr = Shader::create(ShaderStage::VERTEX,   g_vs_glsl);

    g_program_ptr = Program::create(g_fs_ptr.get(),
                                    g_vs_ptr.get() );

    g_program_height_uniform_location = glGetUniformLocation(g_program_ptr->get_id(),
                                                             "height");
    g_program_width_uniform_location  = glGetUniformLocation(g_program_ptr->get_id(),
                                                             "width");

    assert(g_program_height_uniform_location != -1);
    assert(g_program_width_uniform_location  != -1);
}

void render_callback(const int& in_width, const int& in_height)
{
    static const float clear_color[4] =
    {
        0.45f,
        0.55f,
        0.60f,
        1.00f
    };

    if (g_program_ptr == nullptr)
    {
        init_program();
    }

    glViewport(0,
               0,
               in_width,
               in_height);

    glUseProgram(g_program_ptr->get_id() );
    glUniform1i (g_program_height_uniform_location,
                 in_height);
    glUniform1i (g_program_width_uniform_location,
                 in_width);
    glDrawArrays(GL_TRIANGLE_STRIP,
                 0,  /* first */
                 4); /* count */
}