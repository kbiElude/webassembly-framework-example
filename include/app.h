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
#if !defined(APP_H)
#define APP_H

#include "framework.h"
#include "program.h"
#include "shader.h"


class App : public IFrameworkApp
{
public:
    /* Public functions */
    static FrameworkAppUniquePtr create();

    ~App();

    void configure_imgui          ()                                       final;
    void on_file_dropped_callback(const std::string&   in_filename,
                                  Uint8VectorUniquePtr in_data_u8_vec_ptr) final;
    void render_frame            (const int&           in_width,
                                  const int&           in_height)          final;

private:
    /* Private functions */
    App();

    bool init_program();

    /* Private variables */
    Framework::ShaderUniquePtr  m_fs_ptr;
    GLint                       m_program_height_uniform_location = -1;
    GLint                       m_program_t_uniform_location      = -1;
    GLint                       m_program_width_uniform_location  = -1;
    Framework::ProgramUniquePtr m_program_ptr;
    Framework::ShaderUniquePtr  m_vs_ptr;
};

FrameworkAppUniquePtr create_app();

#endif /* APP_H */