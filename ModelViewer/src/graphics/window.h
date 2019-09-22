#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <windows.h>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace quetzal {

	class Window {
	private:
		friend struct GLFWwindow;
		int m_Width, m_Height;
		const char *m_Title;
		GLFWwindow *m_Window;
		bool m_Keys[GLFW_KEY_LAST];
		bool m_Mbs[GLFW_MOUSE_BUTTON_LAST];
		double m_x, m_y;
		friend static void window_resize(GLFWwindow *window, int width, int height);
		friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	public:
		Window(const char *title, int width, int height);
		~Window();
		void update();
		bool init();
		bool should_close();
		inline GLFWwindow* getGLFWWindow() const { return m_Window; }
		inline int get_width() const { return m_Width; }
		inline int get_height() const { return m_Height; }
		bool isKeyPressed(unsigned int key) const;
		bool isButtonPressed(unsigned int button) const;
		void getMousePosition(double &x, double &y) const;
	};


}