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

void imgui_callback()
{
    ImGui::Begin("Hello, world!");
    {
        ImGui::Text("This is some useful text.");
    }
    ImGui::End();
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

    glViewport(0,
               0,
               in_width,
               in_height);

    glClearColor(clear_color[0] * clear_color[3],
                 clear_color[1] * clear_color[3],
                 clear_color[2] * clear_color[3],
                 clear_color[3]);
    glClear     (GL_COLOR_BUFFER_BIT);
}