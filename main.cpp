#include "Libs/vhundef/screen.hpp"
#include "Libs/aixlog.hpp"

void handleKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) {
  LOG(DEBUG) << "Keyboard callback \n";
  if ((key == GLFW_KEY_Q && action == GLFW_PRESS) && glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)) {
	LOG(INFO) << "Got quit command, destroying window\n";
	glfwDestroyWindow(window);
	LOG(DEBUG) << "Quiting...\n";
	glfwTerminate();
	exit(0);
  }
}


int main(int argc, char *argv[]) {
  AixLog::Log::init<AixLog::SinkCout>(AixLog::Severity::trace);
  LOG(INFO) << "Hello, World!\n";
  GLFWwindow *window = Screen::createWindow({100, 100}, {200, 200}, "Test");
  glfwSetKeyCallback(window, handleKeyboard);
  while (glfwWindowShouldClose(window) == GL_FALSE) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawCircle(0, 0, 0.5, 50, {255, 0, 0});

	glfwSwapBuffers(window);
	glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  LOG(INFO) << "Program quit\n";
  return 0;
}

