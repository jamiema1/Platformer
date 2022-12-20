#include <GLFW/glfw3.h>
#pragma once


void cursorPositonCallback(GLFWwindow* window, double xPos, double yPos);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursorEnterCallback(GLFWwindow* window, int entered);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

