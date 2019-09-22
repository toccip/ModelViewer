#include "window.h"
namespace quetzal {

	static void window_resize(GLFWwindow *window, int width, int height);
	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(const char *title, int width, int height) {
		m_Title = title;
		m_Width = width;
		m_Height = height;
		for (int i = 0; i < GLFW_KEY_LAST; i++) {
			m_Keys[i] = false;
		}
		for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) {
			m_Mbs[i] = false;
		}

	}
	bool Window::init() {
		
		if (!glfwInit()) {
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			glfwDestroyWindow(m_Window);
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		//glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glViewport(0, 0, m_Width, m_Height);
		if (glewInit() != GLEW_OK) {
			glfwDestroyWindow(m_Window);
			glfwTerminate();
			return false;
		}
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		return true;
	}

	Window::~Window() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	bool Window::should_close() {
		return glfwWindowShouldClose(m_Window);
	}
	bool Window::isKeyPressed(unsigned int key) const {
		if (key <= GLFW_KEY_LAST) {
			return m_Keys[key];
		}
		else {
			//LOG ERROR
			return false;
		}
	}
	bool Window::isButtonPressed(unsigned int button) const {
		if (button <= GLFW_MOUSE_BUTTON_LAST) {
			return m_Mbs[button];
		}
		else {
			//LOG ERROR
			return false;
		}
	}

	void Window::getMousePosition(double &x, double &y) const {
		x = m_x;
		y = m_y;
	}

	void Window::update(){
		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL error: " << error << std::endl;
		}
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
		
	}

	
	static void window_resize(GLFWwindow *window, int width, int height) {
		Window *win_pointer = (Window*)glfwGetWindowUserPointer(window);
		glfwGetFramebufferSize(window, &(win_pointer->m_Width), &(win_pointer->m_Height));
		glViewport(0, 0, width, height);
	}

	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		Window *win_pointer = (Window*)glfwGetWindowUserPointer(window);
		win_pointer->m_Keys[key] = action != GLFW_RELEASE;
	}

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		Window *win_pointer = (Window*)glfwGetWindowUserPointer(window);
		win_pointer->m_Mbs[button] = action != GLFW_RELEASE;
	}

	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window *win_pointer = (Window*)glfwGetWindowUserPointer(window);
		win_pointer->m_x = xpos;
		win_pointer->m_y = ypos;
	}
}