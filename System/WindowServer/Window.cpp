#include "Window.hpp"

#include <Libsystem/Syscalls.hpp>

#include <Libgraphics/Bitmap.hpp>
#include <Libgraphics/Color.hpp>

#include <Wisterialib/extras.hpp>

static uint32_t window_id = 0;
uint32_t next_window_id()
{
    return window_id++;
}

Window::Window(uint32_t width, uint32_t height, Graphics::Bitmap&& buffer, uint32_t buffer_id, int pid, int x, int y)
    : m_width(width)
    , m_height(height)
    , m_buffer(move(buffer))
    , m_buffer_id(buffer_id)
    , m_x(x)
    , m_y(y)
    , m_pid(pid)
    , id(next_window_id())
{
    m_frame_buffer = Graphics::Bitmap((Graphics::Color*)malloc(4 * width * frame_height), width, frame_height);

    for (int y = 0; y < frame_height; y++) {
        for (int x = 0; x < width; x++) {
            m_frame_buffer[y][x] = Graphics::Color(255, 255, 255);
        }
    }
}