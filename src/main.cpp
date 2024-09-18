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
  VkInstance instance;

  void initWindow() { // Holy shit this is so ugly. All functions act as side effects?
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
  }

  void createInstance() {

    /*
     * In Vulkan it's common to pass structs as arguments to functions.
     * This is uhhhhh... uuuuuhhhhhhhhhhhhh
     * */

    // Optional
    VkApplicationInfo appInfo{}; // Squiggly brackets probably denote a struct. Not an object.

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Triangle Tutorial";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine"; // Wait, there are optimisations for this?
    appInfo.apiVersion = VK_API_VERSION_1_0;
    // bunch of metadata it seems.


    // We actually need this
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    // I feel like I can really simplify this
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    // You don't need to do it like this. It's all freaking side effects anyway
    // vkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    // Start barfing
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
      throw std::runtime_error("faled to create instance.");
    }
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
   *
   * See createInstance
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
