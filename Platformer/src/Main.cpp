#include "Main.h"
#include "Alphabet.h"
#include "Shape.h"
#include "Player.h"
#include "Map.h"

const int windowwidth = 1365;
const int windowheight = 768 - 23;

bool enter{};

double xPos{}, yPos{};
Player* p;
Map* m;


int main()
{

    m = new Map(windowwidth, windowheight);

    double xVel = 0.35;
    double yVel = 0.6;
    p = new Player(100, 100, 0, 0, xVel, yVel, new Rectangle(0,0,0,0,0,127,0,0), m);

    int thickness = 25;
    m->addShape(new Rectangle(0, 0, 0, windowwidth, thickness, 0, 0, 127));
    m->addShape(new Rectangle(0, 0, 0, thickness, windowheight, 0, 0, 127));
    m->addShape(new Rectangle(windowwidth - thickness, 0, 0, thickness, windowheight, 0, 0, 127));
    m->addShape(new Rectangle(0, windowheight - thickness, 0, windowwidth, thickness, 0, 0, 127));
    m->addShape(new Rectangle(400, 100, 0, 100, 100, 0, 0, 127));
    m->addShape(new Rectangle(500, 250, 0, 100, 100, 0, 0, 127));
    m->addShape(new Rectangle(600, 400, 0, 100, 100, 0, 0, 127));
    m->addShape(new Rectangle(700, 550, 0, 100, 100, 0, 0, 127));
    GLFWwindow* window;

 
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowwidth, windowheight, "Platformer", NULL, NULL);

    glfwSetCursorPosCallback(window, cursorPositonCallback);
    glfwSetCursorEnterCallback(window, cursorEnterCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, 1);

    glfwSetKeyCallback(window, KeyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glOrtho(0, windowwidth, 0, windowheight, 0, 1);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        /*if (enter) {
            glfwGetCursorPos(window, &xPos, &yPos);
        }
		*/

        m->draw();
        p->updatePlayer();
        p->drawPlayer();

        
        /*int y{ 10};
        for (int i = 1; i < 12; i++) {
            y += 14 * i;
            text(10, y, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,./", i, Setting::print, 127, 0, 0);
        }*/
       

        /* Swap front and back buffers */
        glfwSwapBuffers(window);


        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		switch (key) {
        case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, 1);
			break;
        case GLFW_KEY_A:
            p->moveHorizontal(false);
            break;
        case GLFW_KEY_D:
            p->moveHorizontal(true);
            break;
        case GLFW_KEY_W:
            p->moveVertical();
            break;
		}
    }
    if (action == GLFW_RELEASE && (key == GLFW_KEY_A || key == GLFW_KEY_D)) {
        p->stopHorizontal();
    }
}






void cursorEnterCallback(GLFWwindow* window, int entered) {
    if (entered) {
        enter = true;
        std::cout << "entered window" << "\n";
    }
    else {
        std::cout << "left window" << "\n";
        enter = false;
    }
}

void cursorPositonCallback(GLFWwindow* window, double xPos, double yPos) {
    static_cast<int>(xPos);
    static_cast<int>(yPos);
    std::cout << xPos << ":" << yPos << "\n";
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if ((action == GLFW_PRESS) && 
		(button == GLFW_MOUSE_BUTTON_LEFT)){
	}
}
