#pragma once

#include "Window.hpp"
#include "ws/Connection.hpp"

class Application {
public:
    Application();

    Graphics::Window& window() { return m_window; }
    const Graphics::Window& window() const { return m_window; }

    void invalidate_area(int x, int y, int width, int height);

private:
    WS::ClientConnection m_connection {};
    int m_server_pid;
    Graphics::Window m_window;
};