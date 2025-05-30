#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	//for (size_t i = 0; i < 1024; i++)
	//{
	//	keys[i] = 0;
	//}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	muevex = 2.0f;


	articulacion1 = 0.0f;
	articulacion2 = 0.0f;
	lamp = 0.0f;

	articulacion3 = 0.0f;
	articulacion4 = 0.0f;
	articulacion5 = 0.0f;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}




	//articulacion1 = 0.0f;
	//articulacion2 = 0.0f;
	//lamp = 0.0f;

	//articulacion3 = 0.0f;
	//articulacion4 = 0.0f;
	//articulacion5 = 0.0f;
}
int Window::Initialise()
{
	//Inicializaci�n de GLFW
	if (!glfwInit())
	{
		printf("Fall� inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "PracticaXX:Nombre de la practica", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tama�o de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fall� inicializaci�n de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
	// Asignar valores de la ventana y coordenadas

	//Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se est� usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
	glfwSetCursorPosCallback(mainWindow, ManejaMouse);
}
GLfloat Window::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat Window::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}




void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}


	if (key == GLFW_KEY_G)
	{
		theWindow->articulacion2 += 10.0;
	}
	//ACTIVAR JUEGO
	if (key == GLFW_KEY_M)
	{
		theWindow->moneda = 2.0;
	}
	//REINICIA JUEGO
	if (key == GLFW_KEY_R)
	{
		theWindow->moneda -= 1.0;
	}

	//TIPO DE JUEGO
	//JUEGO DE BOLICHE
	if (key == GLFW_KEY_B)
	{
		theWindow->typeJUEGO = 1.0;
	}
	//JUEGO DE TOPO
	if (key == GLFW_KEY_T)
	{
		theWindow->typeJUEGO = 2.0;
	}
	// JUEGO DE HACHA
	if (key == GLFW_KEY_H)
	{
		theWindow->typeJUEGO = 3.0;
	}
	//JUEGO REVENTAR GLOBOS
	if (key == GLFW_KEY_G)
	{
		theWindow->typeJUEGO = 4.0;
	}
	//JUEGO DE MESA DE DADOS
	if (key == GLFW_KEY_K)
	{
		theWindow->typeJUEGO = 5.0;
	}
	//JUEGO JAULA DE BATEO
	if (key == GLFW_KEY_J)
	{
		theWindow->typeJUEGO = 6.0;
	}
	if (key == GLFW_KEY_F)
	{
		theWindow->typeJUEGO = 7.0;
	}


	//CAMARAS
	//CAMARA PRIMERA PERSONA
	if (key == GLFW_KEY_1)
	{
		theWindow->typeCAMARA = 5.0;
	}
	//CAMARA VISTA DESDE ARRIBA
	if (key == GLFW_KEY_2)
	{
		theWindow->typeCAMARA = 6.0;
	}
	//CAMARA PARA VER ATRACCIONES
	if (key == GLFW_KEY_3)
	{
		theWindow->typeCAMARA = 7.0;
	}




	if (key == GLFW_KEY_I)
	{
		theWindow->articulacion3 += 10.0;
	}
	if (key == GLFW_KEY_P)
	{
		theWindow->articulacion4 += 10.0;
	}
	if (key == GLFW_KEY_X)
	{
		theWindow->articulacion5 += 10.0;
	}
	// apagar y prender lamparas 
	// lampara 
	if (key == GLFW_KEY_O)
	{
		theWindow->lamp = 1.0;  // para que encienda la lampara 
	}
	if (key == GLFW_KEY_L)
	{
		theWindow->lamp -= 1.0;   // para que  se apague la lampara 

	}

	if (key == GLFW_KEY_Z)
	{
		theWindow->Food = 1.0;  // para que encienda la lampara 
	}
	if (key == GLFW_KEY_N)
	{
		theWindow->Food -= 1.0;   // para que  se apague la lampara 

	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			//printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			//printf("se solto la tecla %d'\n", key);
		}
	}
}

void Window::ManejaMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved)
	{
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;

	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
}




Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}

