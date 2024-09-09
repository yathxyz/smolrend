#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
  void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
  }

private:
  GLFWwindow* window;

  void initWindow() { // Holy shit this is so ugly. All functions act as side effects?
      glfwInit();

      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
  }



  void initVulkan() {
  /* From what I understand, Vulkan works by initialising an instance.
   *
   * The instance means the connection between the application and the library itself.
   * I'm afraid I don't quite understand if the tutorial by that means dynamic.
   *
   * I don't think it even matters if it's static or dynamic really. It's still runtime.
   *
   * We need to fill out detailed information before initialising. NB what happens.
   * */
  }

  void mainLoop() {
      while (!glfwWindowShouldClose(window)) {
          glfwPollEvents();
      }
  }

  void cleanup() {
      glfwDestroyWindow(window);

      glfwTerminate();
  }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
