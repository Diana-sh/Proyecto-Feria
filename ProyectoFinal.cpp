/*
Animación:
Sesión 1:
Simple o básica:Por banderas y condicionales (más de 1 transformación geométrica se ve modificada
Sesión 2
Compleja: Por medio de funciones y algoritmos.
Textura Animada
*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"

const float toRadians = 3.14159265f / 180.0f;

//variables para animación
// movimiento de bus de bob esponja 
float movBus;
float movOffset;
float llanta;
float llantaOffset;
bool recorre = true;
// movimiento de carrusel 
float movCa;
float offset;
float caballo;
float caballoff;
bool circulo;
// juego  boliche 
float movesferas;
float set;
float esfera;
float esferaoff;
bool chuza = true;
bool llegaBola;
float posX;
int caida;
int ultimaPOSx;

// ciclo de dia y noiche 
bool Dia = true; // Variable estática para alternar entre día y noche
float TiempoT = 0.0f; // Tiempo del último cambio
float Intervalo = 12.0f; // Intervalo de 12 segundos

// movimeinto de goku 
bool Bola = true; // Variable estática para alternar entre hacer la animacion y no hcaerla 
float Espera = 0.0f; // Tiempo del último cambio
float Inter = 12.0f; // Intervalo de 12 segundos

float rotManosGOffset;
bool movManosGOK;
float rotManosGOK;
//TOPO
float contTIME3;
bool IniciaTopo = true;
bool posFaro = true;
bool golpeTOPO;
int numeroGolpes;

bool ganadorTopo;
float posXFARO;
float posYFARO;
float posZFARO;
//PARA FARO
float movFaro;
float movOffsetFaro;
float rotaFaro;
float rotaFaroOffset;
bool giraFaro = true;
bool mueveFaro = true;

// Movimiento de broly
float movBro;
float movBroOffset;
float Piernas;
float PiernasOffset;
bool CAMINA = true;
bool Aleteo = true;
// Movimineto para Giren
float movGi;
float movGiOffset;
float Brazos;
float BrazosOffset;
bool Walk = true;
bool Lento = true;


//Para LANZAMIENTO DE HACHA
float movimiHACH;
float movOffsetHACH;
float rotaHACH;
float rotaHACHOffset;
bool giraHACH = true;
bool mueveHACH = true;

bool tache1;
bool tache2;
bool tache3;

float contadorTIME;
int posTIRO = 0;
float posTIROx;
float posTIROy;

//PARA LANZAMIENTO DE DARDO
float moveDardo;
float movOffsetDARD;
float rotadardo;
float rotadardo1;
float rotadardo2;
float rotadardo3;
float dardooff;

bool mueveDARD = true;

float contTIME2;
int posTIROglobo = 0;
float posDardoX;
float posDardoY;

bool bajaGLOBO = true;
float bajaGlob1;
float bajaGlob2;
float bajaGlob3;

float movDardo1;
float movDardo2;
float movDardo3;
float movDardo4;

//Movimiento de cabeza calamardo
float rotHeadCALAM;
float rotaHeadCAOffset;
bool dirHeadC = true;
//movimiento piernas de calamardo
float movimCALAM;
float movOffsetCALAM;
float rotaPierna;
float rotaPiernOffset;
bool doblaPiern = true;

// rueda de la fortuna 
float movimFortu;
float movOffsetFortun;

float rotaFortuna;
float rotaFortunaOffset;
bool For = true;
// karen movimiento 
float moviKar;
float movOffsetKar;
bool robot = true;


//MOVIMIENTO PATRICIO ESTRELLA
float contTIMEP;
float rotaBraPAT;
float rotaBraPATOffset;
bool giraBrazoPAT = true;
float rotaHeadPAT;
float rotaHeadPATOffset;
bool giraHeadPAT = true;
float movHelaZ;
float movHelado;
float movOffsetHel;
bool caeHelado = true;
// movieminto para el juego del dado 
//float movimCALAM;
//float movOffsetCALAM;

//MOVIMIENTO JUEGO DE DADO
float rotaVa;
float rotaVaOffset;

float movDado;
float movOffsetDado;
float rotaraD;
float rotaraDz;
float ContTimer4;
bool GameDA = true;
bool BajaDa = true;



//MOVIMIENTO JUEGO DE BATEO pelota
bool muevePELOTA = true;
float movPelota; //Posicion en Z
float movPelota2; //Posicion en Y
float movOffsetPelota;
float rotaPelota;
float rotaPeOffset;
int numPELOTA = 0;
float posPelotaX;
float posPelotaX1;
float posPelotaX2;
float posPelotaX3;
float posPelotaY;
// movimiento de las tres pelotas 
float movP1;
float movP11;
float rotaP1;

float movP2;
float movP22;
float rotaP2;

float movP3;
float movP33;
float rotaP3;

bool mueveBAT = true;
float rotaBAT;
float rotaBATOffset;




// vuelo de bardock 
float moviBar;
float movOffsetBar;
//float rotaPierna;
//float rotaPiernOffset;
bool BarVuela = true;

// movimeinto del pendulo 
float rotaPendu;
float rotaPenduOffset;
float movP;
float movOffsetP;
bool Pen;
// movimiento del juego de los patos 
float rotaPatos;
float rotaPatosOffset;
float movpato;
float movOffsetPato;
bool Pat;

// movimeinto de globo 

float Guantos;
float GuaOffset;
bool Guant = true;
bool Baile = true;

// movimiento de goku el personaje principal 

float velocidad = 2.0f;          // velocidad de oscilación
bool animarBrazo = false;
float an = 0.0f;    // angulo 
float angulovaria = 0.0f;



bool camaraFija = false;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

Camera camera;


// textura del piso 
Texture plainTexture;
Texture pisoTexture;
Texture H;
Texture G;
// Textura juego golpea al topo
Texture golpTopTexture;
Texture ganaTopTexture;
//Textura juego Hacha
Texture tache;
Texture Ki;


// Todos los modelos de la feria
// Cuerpo de goku 
Model BrazoD;
Model BrazoI;
Model goku;
Model PiernaDGO;
Model PiernaIZGO;
// Esferas del dragon 
Model Esfera1;
Model Esfera2;
Model Esfera3;
Model Esfera4;
Model Esfera5;
Model Esfera6;
Model Esfera7;
// Modelo juego de puestos de comida  
Model Cbrochetas;
Model CarritoE;
Model CarritoT;
Model CTamales;
Model CarritoA;
// modelo de lampara fonde de bikini 
Model Lampara;
// modelos del universo de bob esponja 

// modelo de plankton
Model Plank;
Model brazoPlankD;
Model brazoPlankI;
// modelo de calamardo 
Model CabezaCALAM;
Model CuerpoCALAM;
Model piernDcalam;
Model piernIcalam;
// casa de calamardo 
Model Cal;
// autobus bob esponja 
Model Bus;
Model Aleta;
Model LlantaI1;
Model LlantaI2;
Model LlantaI3;
Model LlantaD1;
Model LlantaD2;
Model LlantaD3;

// modelo del valde de carnada 
Model val;
// carrusel 
Model Techo;
Model Base;
Model Ca1;
Model Ca2;
Model Ca3;
Model Ca4;
// banca 
Model Banc;
Model BancaG;
Model BancaB;
// soba 
Model Soba;
// modelos del juego de golpea al topo  version fondo de bikini 
Model Faro;
Model Medu;
Model Game;
//MODELOS PARA JUEGO LANZAMIENTO DE HACHA
Model Gamehacha;
Model Hacha;
Model CabinaHacha;


// juego de boliche 
Model Bol;
Model Pin;
// Kame house 
Model Kame;
//MODELOS PARA JUEGO GLOBOS
Model Globo;
Model globo1;
Model globo2;
Model globo3;
Model Dar;
// rueda de la fortunan 
Model cuerpoR;
Model BaseR;
// Nave de trunks 
Model Nave;
// Karin 
Model KA;
// modelo de agua 
Model botes;

// Giren 
Model BOB;
Model PiernaIz;
Model Piernad;
Model BrazoIz;
Model Brazod;

// bROLY 
Model CUB;
Model Brazoiz;
Model BarzodB;
Model PiernaizB;
Model PiernadB;

// Don kangrejo
Model KanIZ;
Model KanD;
Model KanCuerpo;
// gary 
Model Ga;
// Karen 
Model Karen;
// puf 
Model Puff;
// Calamardo Guapo
Model Guapo;
// patrullero de bob
Model Patru;
// Picolo 
Model Pic;
//vegetta 
Model Vege;
// Glorio 
Model Glo;
//MODELO PATRICIO
Model bodyPAT;
Model headPAT;
Model heladoPAT;
Model brazoPAT;
// lamara del kustaceo 
Model lampKrusty_M;
// casa de bob 
Model casaBOB;
// Modelos de bob esponja 
Model BobSir;
Model BobConejo;
Model BobVigi;
Model BobGlobo;
Model BobEle;
// Heladeria 
Model Helados;
// Mesas de bbob esponja 
Model Mesa;
// Mini brochetas 
Model Brocheta;
// personaje bardock 
Model CuBar;
Model BrazoDBar;
Model BrazoIZBar;
// Juego de bateo 
Model Jaula;
Model Bat;
Model Pelota;



// Juego del dado
Model Dado1;
Model Dado2;
Model MesaGame;
Model VasoGame;
// Modelo de larry la langosta 
Model CuerpoLa;
Model BrazoLarry;
// tartufinos
Model Tar;
// Elotes
Model Elotes;
Model Echile;
// Tamales 
Model Tamal;
//Cartel  
Model Cartel;
// juego del pendulo 
Model Pendulo;
// juego de los patos
Model aropatos;
Model BasePatos;
Model pato1;
Model pato2;
Model pato3;
Model pato4;
Model pato5;
Model pato6;
// globo 
Model Guante;
Model PiernaIZG;
Model PiernaDG;
// chico perseve
Model perseve;
// modelo de sirenoman 
Model Sireno;
Model Cuerp;
Model bra;
//medusa reina 
Model MedusaR;
Skybox skybox;

//materiales
Material Material_brillante;
Material Material_opaco;


//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

// luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight
PointLight pointLights[MAX_POINT_LIGHTS];
PointLight top2[MAX_POINT_LIGHTS];
PointLight Hacha3[MAX_POINT_LIGHTS];
PointLight boliche4[MAX_POINT_LIGHTS];
PointLight Flor[MAX_POINT_LIGHTS];
PointLight Poste[MAX_POINT_LIGHTS];
PointLight D[MAX_POINT_LIGHTS];
PointLight Glob[MAX_POINT_LIGHTS];
PointLight Hbob[MAX_POINT_LIGHTS];
PointLight JBateo[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];
SpotLight spotLightsCOMIDA[MAX_SPOT_LIGHTS];
SpotLight Hac[MAX_SPOT_LIGHTS];
SpotLight RuedaF[MAX_SPOT_LIGHTS];
SpotLight CaminoF[MAX_SPOT_LIGHTS];
SpotLight GlobosG[MAX_SPOT_LIGHTS];
SpotLight Food[MAX_SPOT_LIGHTS];
SpotLight Boli[MAX_SPOT_LIGHTS];
SpotLight GTopo[MAX_SPOT_LIGHTS];
SpotLight Da[MAX_SPOT_LIGHTS];
SpotLight T[MAX_SPOT_LIGHTS];


// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";



//cálculo del promedio de las normales para sombreado de Phong
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}


void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};
	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,


	};


	unsigned int flechaIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	};

	GLfloat flechaVertices[] = {
		-0.5f, 0.0f, 0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, 0.5f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,

	};

	unsigned int scoreIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	};

	GLfloat scoreVertices[] = {
		-0.5f, 0.0f, 0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, 0.5f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,

	};

	unsigned int numeroIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	};

	GLfloat numeroVertices[] = {
		-0.5f, 0.0f, 0.5f,		0.0f, 0.67f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, 0.5f,		0.25f, 0.67f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		0.25f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,

	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);


	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj4);

	Mesh* obj5 = new Mesh();
	obj5->CreateMesh(flechaVertices, flechaIndices, 32, 6);
	meshList.push_back(obj5);

	Mesh* obj6 = new Mesh();
	obj6->CreateMesh(scoreVertices, scoreIndices, 32, 6);
	meshList.push_back(obj6);

	Mesh* obj7 = new Mesh();
	obj7->CreateMesh(numeroVertices, numeroIndices, 32, 6);
	meshList.push_back(obj7);

}


void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}


glm::vec3 CAMJuegoTOPO = glm::vec3(-65.0f, 1.5f, 130.0);
glm::vec3 CAMJuegoBOLICHE = glm::vec3(85.0f, 10.0f, -56.0f);
glm::vec3 CAMJuegoHACHA = glm::vec3(-15.0f, 4.5f, -58.0f);
glm::vec3 CAMJuegoGLOBO = glm::vec3(-100.0f, 4.0f, 90.0);
glm::vec3 CAMJuegoDADO = glm::vec3(-85.0f, 9.0f, -78);
glm::vec3 CAMJuegoBATEO = glm::vec3(-130.0f, 1.5f, -105);
glm::vec3 CAMJuegoFoods = glm::vec3(-100.0f, 15.0f, 30);



int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();


	std::vector<Camera> cameras(3);  // Arreglo de camaras
	int activaCamNUM = 0;  //Variable para el numero de arreglo

	// Cámara 1: Primera persona - Recorrido
	cameras[0] = Camera(glm::vec3(10.0f, 2.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f, 0.5f, 0.5f);
	// Cámara 2: Vista de arriba
	cameras[1] = Camera(glm::vec3(0.0f, 50.0f, 0.01f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, -89.0f, 0.5f, 0.0f);
	// Cámara 3: Camara para atracciones
	glm::vec3 atracPos; //VARIABLE DE POSICION PARA TERCER CAMARA
	atracPos = (glm::vec3(0.0f, 0.0f, 0.0f));


	// Craga de las texturas 


	// textura del piso 
	/*plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();*/
	pisoTexture = Texture("Textures/arena3.png");   //piso.tga")
	pisoTexture.LoadTextureA();
	H = Texture("Textures/Humo.png");
	H.LoadTextureA();
	G = Texture("Textures/Energia.png");
	G.LoadTextureA();


	golpTopTexture = Texture("Textures/golpeTopo.jpg");
	golpTopTexture.LoadTextureA();
	ganaTopTexture = Texture("Textures/ganaTopo.jpg");
	ganaTopTexture.LoadTextureA();
	Ki = Texture("Textures/KI1.png");
	Ki.LoadTextureA();

	//Juego hacha
	tache = Texture("Textures/tache.png");
	tache.LoadTextureA();

	// carga de los modelos 
	// modelos de las esferas del dragon 
	Esfera1 = Model();
	Esfera1.LoadModel("Models/Esfera1.obj");
	Esfera2 = Model();
	Esfera2.LoadModel("Models/Esfera2.obj");
	Esfera3 = Model();
	Esfera3.LoadModel("Models/Esfera3.obj");
	Esfera4 = Model();
	Esfera4.LoadModel("Models/Esfera4.obj");
	Esfera5 = Model();
	Esfera5.LoadModel("Models/Esfera5.obj");
	Esfera6 = Model();
	Esfera6.LoadModel("Models/Esfera6.obj");
	Esfera7 = Model();
	Esfera7.LoadModel("Models/Esfera7.obj");
	// Cuerpo de goku 
	goku = Model();
	goku.LoadModel("Models/GO.obj");
	BrazoD = Model();
	BrazoD.LoadModel("Models/BrazoD.obj");
	BrazoI = Model();
	BrazoI.LoadModel("Models/BrazoI.obj");
	PiernaDGO = Model();
	PiernaDGO.LoadModel("Models/PiernaDGO.obj");
	PiernaIZGO = Model();
	PiernaIZGO.LoadModel("Models/PiernaIZGO.obj");
	// personajes universo de bob esponja 
	// Cuerpo de plankton
	Plank = Model();
	Plank.LoadModel("Models/cuerpoPLANK.obj");
	brazoPlankD = Model();
	brazoPlankD.LoadModel("Models/brazoDePlank.obj");
	brazoPlankI = Model();
	brazoPlankI.LoadModel("Models/brazoIPlank.obj");
	// Calamardo
	CabezaCALAM = Model();
	CabezaCALAM.LoadModel("Models/cabezaCALAM.obj");
	CuerpoCALAM = Model();
	CuerpoCALAM.LoadModel("Models/cuerpoCALAM.obj");
	piernDcalam = Model();
	piernDcalam.LoadModel("Models/piernDERcalam.obj");
	piernIcalam = Model();
	piernIcalam.LoadModel("Models/piernIZQcalam.obj");
	// casa de calamarod 
	Cal = Model();
	Cal.LoadModel("Models/casaCALAMI.obj");
	// autobus bob esponja 
	Bus = Model();
	Bus.LoadModel("Models/cuerpoBUS.obj");
	Aleta = Model();
	Aleta.LoadModel("Models/aletaBUS.obj");
	LlantaI1 = Model();
	LlantaI1.LoadModel("Models/llantaI1.obj");
	LlantaI2 = Model();
	LlantaI2.LoadModel("Models/llantaI2.obj");
	LlantaI3 = Model();
	LlantaI3.LoadModel("Models/llantaI3.obj");

	LlantaD1 = Model();
	LlantaD1.LoadModel("Models/llantaD1.obj");
	LlantaD2 = Model();
	LlantaD2.LoadModel("Models/llantaD2.obj");
	LlantaD3 = Model();
	LlantaD3.LoadModel("Models/llantaD3.obj");
	// puestos de comida 
	Cbrochetas = Model();
	Cbrochetas.LoadModel("Models/Cbrochetas.obj");
	CarritoE = Model();
	CarritoE.LoadModel("Models/CarritoE.obj");
	CarritoT = Model();
	CarritoT.LoadModel("Models/CarritoT.obj");
	CTamales = Model();
	CTamales.LoadModel("Models/CarritoTa.obj");
	CarritoA = Model();
	CarritoA.LoadModel("Models/CarritoA.obj");

	// iluminacion lamparas 
	Lampara = Model();
	Lampara.LoadModel("Models/Flor1.obj");
	// modelo del valde de carnada 
	val = Model();
	val.LoadModel("Models/Valde.obj");
	// Carrusel 
	Base = Model();
	Base.LoadModel("Models/BaseCa.obj");
	Techo = Model();
	Techo.LoadModel("Models/Arriba.obj");
	Ca1 = Model();
	Ca1.LoadModel("Models/Cafren.obj");
	Ca2 = Model();
	Ca2.LoadModel("Models/CaIzFake.obj");
	Ca3 = Model();
	Ca3.LoadModel("Models/CaAtras.obj");
	Ca4 = Model();
	Ca4.LoadModel("Models/CaDer.obj");
	/*Lampara = Model();
	Lampara.LoadModel("Models/Flor1.obj");*/
	// banca 
	Banc = Model();
	Banc.LoadModel("Models/Banca.obj");
	BancaG = Model();
	BancaG.LoadModel("Models/BancaG.obj");
	BancaB = Model();
	BancaB.LoadModel("Models/BancaB.obj");
	// Soba 
	Soba = Model();
	Soba.LoadModel("Models/Soba.obj");
	// juego de golpea al topo version universo de bob esponja 
	Faro = Model();
	Faro.LoadModel("Models/FARO.obj");
	Medu = Model();
	Medu.LoadModel("Models/medu.obj");
	Game = Model();
	Game.LoadModel("Models/gameTOPO.obj");
	//Juego Hacha
	Hacha = Model();
	Hacha.LoadModel("Models/Hacha2.obj");
	CabinaHacha = Model();
	CabinaHacha.LoadModel("Models/cabinaHacha.obj");
	Gamehacha = Model();
	Gamehacha.LoadModel("Models/gameHacha.obj");
	// juego de boliche 
	Bol = Model();
	Bol.LoadModel("Models/Boli.obj");
	Pin = Model();
	Pin.LoadModel("Models/Pino.obj");
	// kame house 
	Kame = Model();
	Kame.LoadModel("Models/Kame.obj");
	// juego de revienta el globo 
	Globo = Model();
	Globo.LoadModel("Models/GlobosG.obj");
	globo1 = Model();
	globo1.LoadModel("Models/Globo1.obj");
	globo2 = Model();
	globo2.LoadModel("Models/Globo2.obj");
	globo3 = Model();
	globo3.LoadModel("Models/Golobo3.obj");
	Dar = Model();
	Dar.LoadModel("Models/Dardo.obj");
	// RUEDA DE LA FORTUNA 
	cuerpoR = Model();
	cuerpoR.LoadModel("Models/CuerpoR.obj");
	BaseR = Model();
	BaseR.LoadModel("Models/BaseRueda.obj");
	// nave de trunks 
	Nave = Model();
	Nave.LoadModel("Models/NaveT.obj");
	//kARIN 
	KA = Model();
	KA.LoadModel("Models/Karin.obj");
	// mode de aguas 
	botes = Model();
	botes.LoadModel("Models/refres.obj");
	// giren 
	BOB = Model();
	BOB.LoadModel("Models/BGiren.obj");
	BrazoIz = Model();
	BrazoIz.LoadModel("Models/BrazoIZG.obj");
	Brazod = Model();
	Brazod.LoadModel("Models/BrazoDG.obj");
	PiernaIz = Model();
	PiernaIz.LoadModel("Models/PiernaIZG.obj");
	Piernad = Model();
	Piernad.LoadModel("Models/PiernaDG.obj");
	// Broly
	CUB = Model();
	CUB.LoadModel("Models/BODYBro.obj");
	Brazoiz = Model();
	Brazoiz.LoadModel("Models/BrazoIZBroR.obj");
	BarzodB = Model();
	BarzodB.LoadModel("Models/BrazoIZBro.obj");
	PiernaizB = Model();
	PiernaizB.LoadModel("Models/PiernaIZBro.obj");
	PiernadB = Model();
	PiernadB.LoadModel("Models/PiernaDBro.obj");
	// don kangrejo
	KanCuerpo = Model();
	KanCuerpo.LoadModel("Models/CuerpoKan.obj");
	KanIZ = Model();
	KanIZ.LoadModel("Models/BrazoIZKan.obj");
	KanD = Model();
	KanD.LoadModel("Models/BrazoDKan.obj");
	// Gary 
	Ga = Model();
	Ga.LoadModel("Models/Gary.obj");
	// Karen
	Karen = Model();
	Karen.LoadModel("Models/Karen.obj");
	// Karen
	Puff = Model();
	Puff.LoadModel("Models/Puff.obj");
	// Calamardo guapo 
	Guapo = Model();
	Guapo.LoadModel("Models/CalaGuapo.obj");
	// Polis
	Patru = Model();
	Patru.LoadModel("Models/Patrullero.obj");
	// Picolo
	Pic = Model();
	Pic.LoadModel("Models/Picolo.obj");
	// Vegetta 
	Vege = Model();
	Vege.LoadModel("Models/Vegetta.obj");
	// Glorio
	Glo = Model();
	Glo.LoadModel("Models/Glorio.obj");
	//Cuerpo de PATRICIO
	bodyPAT = Model();
	bodyPAT.LoadModel("Models/bodyPAT.obj");
	headPAT = Model();
	headPAT.LoadModel("Models/headPatrik.obj");
	heladoPAT = Model();
	heladoPAT.LoadModel("Models/heladoPAT.obj");
	brazoPAT = Model();
	brazoPAT.LoadModel("Models/brazoPAT.obj");
	// lampara de custaceo 
	lampKrusty_M = Model();
	lampKrusty_M.LoadModel("Models/lampKrusty.obj");
	// casa de bob esponja 
	casaBOB = Model();
	casaBOB.LoadModel("Models/casaBob.obj");
	// Modelos de los bob trabjadores
	BobVigi = Model();
	BobVigi.LoadModel("Models/BobVigi.obj");
	BobSir = Model();
	BobSir.LoadModel("Models/BobSirviente.obj");
	BobGlobo = Model();
	BobGlobo.LoadModel("Models/BobGlobo.obj");
	BobEle = Model();
	BobEle.LoadModel("Models/BobElegante.obj");
	BobConejo = Model();
	BobConejo.LoadModel("Models/BobConejo.obj");

	// Modelo de la heladeria 
	Helados = Model();
	Helados.LoadModel("Models/Helados.obj");
	// Modelo de las mesas de bob esponja  
	Mesa = Model();
	Mesa.LoadModel("Models/MesaBob.obj");
	// Modelo de las brochetas para los puestosd e comida   
	Brocheta = Model();
	Brocheta.LoadModel("Models/Brochetas.obj");
	// Modelo de bardock dragon ball 
	CuBar = Model();
	CuBar.LoadModel("Models/CuerpoBar.obj");
	BrazoDBar = Model();
	BrazoDBar.LoadModel("Models/BrazoDBar.obj");
	BrazoIZBar = Model();
	BrazoIZBar.LoadModel("Models/BrazoIZBar.obj");
	// juego de la jaula de bateo 
	Jaula = Model();
	Jaula.LoadModel("Models/JaulaBATEO.obj");
	Bat = Model();
	Bat.LoadModel("Models/BAT.obj");
	Pelota = Model();
	Pelota.LoadModel("Models/pelotaBAT.obj");


	// juego de los dados

	MesaGame = Model();
	MesaGame.LoadModel("Models/mesaGameD.obj");
	Dado1 = Model();
	Dado1.LoadModel("Models/dado1.obj");
	Dado2 = Model();
	Dado2.LoadModel("Models/dado2.obj");
	VasoGame = Model();
	VasoGame.LoadModel("Models/vasoGameD.obj");
	// larry la alngosta
	CuerpoLa = Model();
	CuerpoLa.LoadModel("Models/LarryBody.obj");
	BrazoLarry = Model();
	BrazoLarry.LoadModel("Models/BrazoLarry.obj");

	// Tartufinos 
	Tar = Model();
	Tar.LoadModel("Models/Tartufinos.obj");
	// elotes 
	Elotes = Model();
	Elotes.LoadModel("Models/Elotesqueso.obj");
	Echile = Model();
	Echile.LoadModel("Models/EloteChile.obj");
	// Tamales 
	Tamal = Model();
	Tamal.LoadModel("Models/Tamalito.obj");
	//cartel 
	Cartel = Model();
	Cartel.LoadModel("Models/Cartel.obj");
	// juego del pendulo 
	Pendulo = Model();
	Pendulo.LoadModel("Models/Pendulo.obj");
	// juego de patos 
	aropatos = Model();
	aropatos.LoadModel("Models/aroPATOS.obj");
	BasePatos = Model();
	BasePatos.LoadModel("Models/basePATOS.obj");
	pato1 = Model();
	pato1.LoadModel("Models/pato1.obj");
	pato2 = Model();
	pato2.LoadModel("Models/pato2.obj");
	pato3 = Model();
	pato3.LoadModel("Models/patito3.obj");
	pato4 = Model();
	pato4.LoadModel("Models/pato4.obj");
	pato5 = Model();
	pato5.LoadModel("Models/pato5.obj");
	pato6 = Model();
	pato6.LoadModel("Models/pato6.obj");

	//personajes de bob esponja 
	Guante = Model();
	Guante.LoadModel("Models/globoPERSON.obj");
	perseve = Model();
	perseve.LoadModel("Models/chicoPerse.obj");
	Sireno = Model();
	Sireno.LoadModel("Models/sirenoMAN.obj");
	Cuerp = Model();
	Cuerp.LoadModel("Models/Cuerpogo.obj");
	bra = Model();
	bra.LoadModel("Models/Derechogo.obj");
	PiernaIZG = Model();
	PiernaIZG.LoadModel("Models/PizqGLOBO.obj");
	PiernaDG = Model();
	PiernaDG.LoadModel("Models/piernDerGLOB.obj");
	//medusa reina 
	MedusaR = Model();
	MedusaR.LoadModel("Models/MeduCorona.obj");

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cielo26.jpg");
	skyboxFaces.push_back("Textures/Skybox/cielo26.jpg");
	skyboxFaces.push_back("Textures/Skybox/arena.jpg"); //ABAJO
	skyboxFaces.push_back("Textures/Skybox/cielo27.jpg"); //ARRIBA
	skyboxFaces.push_back("Textures/Skybox/cielo25.jpg");
	skyboxFaces.push_back("Textures/Skybox/cielo25.jpg");
	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);


	//luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		0.3f, 0.3f,
		0.0f, 0.0f, -1.0f);

	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	unsigned int pointLightCount2 = 0;
	unsigned int pointLightCount3 = 0;
	unsigned int pointLightCount4 = 0;
	unsigned int pointLightCount5 = 0;
	unsigned int pointLightCount6 = 0;
	unsigned int pointLightCount7 = 0;
	unsigned int pointLightCount8 = 0;
	unsigned int pointLighT = 0;
	//Declaración de primer luz puntual

	//Declaración de primer luz puntual
	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
		1.0f, 1.0f,
		-129.0f, 12.0f, 124.0,
		0.6f, 0.4f, 0.1f);
	pointLightCount++;

	//Declaración de primer luz puntual
	pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,
		50.0f, 3.0f, -15.0,
		0.6f, 0.4f, 0.1f);
	pointLightCount++;
	///arreglo2
	top2[0] = PointLight(0.5f, 0.5f, 0.5f,
		0.0f, 1.0f,
		0.0f, 1.0f, 25.0f,
		0.3f, 0.2f, 0.1f);
	pointLightCount4++;
	top2[1] = PointLight(0.5f, 1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, -1.1f, 35.0,
		0.3f, 0.2f, 0.1f);
	pointLightCount4++;

	//lUCES para el juego del hacha  

	Hacha3[0] = PointLight(1.0f, 0.5f, 1.0,  // color  lila 
		0.0f, 1.0f,
		-25.0f, -1.0f, 135.0f,
		0.3f, 0.2f, 0.1f);
	pointLightCount3++;
	//juego de boliche 
	boliche4[0] = PointLight(1.0f, 1.0f, 0.5,  // color   amarillo
		0.0f, 1.0f,
		85.0f, -1.0f, -56.0,
		0.3f, 0.2f, 0.1f);
	pointLightCount2++;

	boliche4[1] = PointLight(1.0f, 0.0f, 0.0,     // color  roja 
		0.0f, 1.0f,
		-25.0f, -1.0f, 135.0,
		0.3f, 0.2f, 0.1f);
	pointLightCount2++;

	// D 
	D[0] = PointLight(1.0f, 1.0f, 0.5,  // color   
		0.0f, 1.0f,
		-850.0f, -1.0f, -360.0,
		0.3f, 0.2f, 0.1f);
	pointLighT++;


	// comida luz 
	Poste[0] = PointLight(0.5f, 1.0f, 1.0f,  // color   cian
		0.8f, 1.0f,
		-132.0f, 21.0f, -39.0,
		0.1f, 0.1f, 0.1f);
	pointLightCount5++;

	Poste[1] = PointLight(0.5f, 1.0f, 1.0f,  // color   cian
		0.8f, 1.0f,
		250.0f, 21.0f, -39.0,
		0.1f, 0.1f, 0.1f);
	pointLightCount5++;


	// GLOBOS 
	Glob[0] = PointLight(0.0, 1.0, 1.0,  // color   cian 
		0.8f, 1.0f,
		-88.0f, 3.0f, 75.0,
		0.1f, 0.1f, 0.1f);
	pointLightCount6++;


	//casa de bob esponja 
 //Declaración de primer luz puntual
	Hbob[0] = PointLight(1.0f, 1.0f, 0.0f, // color blanco
		0.8f, 1.0f,
		25.0f, 5.0f, -70.0,
		0.6f, 0.4f, 0.2f);
	pointLightCount7++;
	Hbob[1] = PointLight(2.0f, 1.0f, 0.0f,
		0.5f, 1.0f,
		250.0f, 3.0f, 0.0f,
		0.3f, 0.2f, 0.1f);
	pointLightCount7++;
	// Jaula de bateo 
	JBateo[0] = PointLight(0.5f, 1.0f, 1.0f, //Color cian  
		0.5f, 1.0f,
		-130.0f, 1.5f, -135,
		0.3f, 0.2f, 0.1f);
	pointLightCount8++;
	JBateo[1] = PointLight(1.0f, 1.0f, 0.0f, //
		0.5f, 1.0f,
		-130.0f, 4.2f, -116,
		0.3f, 0.2f, 0.1f);
	pointLightCount8++;



	unsigned int spotLightCount = 0;
	unsigned int spotLightCount1 = 0;
	unsigned int spotLightCount2 = 0;
	unsigned int spotLightCount3 = 0;
	unsigned int spotLightCount4 = 0;
	unsigned int spotLightCount5 = 0;
	unsigned int spotLightCount6 = 0;
	unsigned int spotLightCount7 = 0;
	unsigned int spotLightCount8 = 0;
	unsigned int spotLighT = 0;

	//linterna
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);
	spotLightCount++;

	//luz fija
	spotLights[1] = SpotLight(0.0f, 0.0f, 1.0f,
		1.0f, 2.0f,
		5.0f, 10.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		15.0f);
	spotLightCount++;
	//Juego de lanzamiento de hacha 
	//linterna
	Hac[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);


	spotLightCount1++;

	Hac[1] = SpotLight(0.75f, 0.5f, 0.75f,           //  color plateado    
		1.0f, 2.0f,
		-14.0f, -3.0f, -87.0,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		45.0f);
	spotLightCount1++;

	Hac[2] = SpotLight(1.0f, 0.0f, 0.0f,           // roja 
		1.0f, 2.0f,
		-14.0f, -2.0f, -66.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		45.0f);
	spotLightCount1++;
	// rueda de la fortuna 
	//linterna
	RuedaF[0] = SpotLight(1.0f, 0.0f, 0.0f,
		1.0f, 2.0f,
		-180.0f, 10.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		25.0f);


	spotLightCount2++;

	RuedaF[1] = SpotLight(0.0f, 0.0f, 1.0f,           //  color azul    
		1.0f, 1.0f,
		180.0f, 10.0f, -180.0,
		-1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		25.0f);
	spotLightCount2++;

	RuedaF[2] = SpotLight(1.0f, 0.84f, 0.0f,           // oro
		1.0f, 2.0f,
		180.0f, 10.0f, 180.0,
		-1.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		25.0f);
	spotLightCount2++;
	// Camino de flores 
	CaminoF[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);


	spotLightCount3++;
	CaminoF[1] = SpotLight(1.0f, 0.0f, 0.0f,           //  ROJA 
		1.0f, 1.0f,
		0.0f, 25.0f, -20.0,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		45.0f);
	spotLightCount3++;

	CaminoF[2] = SpotLight(1.0f, 0.0f, 0.0f,           // ROJA
		1.0f, 1.0f,
		-25.0f, 25.0f, -20.0,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		45.0f);
	spotLightCount3++;



	// juego de globos
	GlobosG[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);


	spotLightCount4++;
	GlobosG[1] = SpotLight(0.3f, 0.3f, 0.3f,           //  blanca
		1.0f, 1.0f,
		-100.0f, 25.0f, 70.0,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		30.0f);
	spotLightCount4++;
	// area de comida 
	Food[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);


	spotLightCount5++;
	Food[1] = SpotLight(0.0f, 0.0f, 1.0f,           //  
		1.0f, 1.0f,
		-80.0f, 35.0f, -45,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		30.0f);
	spotLightCount5++;

	Food[2] = SpotLight(0.0f, 0.65f, 0.4f,           // 
		1.0f, 1.0f,
		-120.0f, 35.0f, -45,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		30.0f);
	spotLightCount5++;

	//T

	spotLighT++;
	T[0] = SpotLight(0.0f, 0.0f, 1.0f,           //  
		1.0f, 1.0f,
		-250.0f, 2.0f, -250,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);
	spotLighT++;
	//Juegode boliche 
	Boli[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);


	spotLightCount6++;

	Boli[1] = SpotLight(0.75f, 0.5f, 0.75f,           //  color plateado    
		1.0f, 2.0f,
		90.0f, 50.0f, -105.0,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		25.0f);
	spotLightCount6++;
	// juego de topo 
	GTopo[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);
	spotLightCount7++;

	GTopo[1] = SpotLight(1.0f, 0.4f, 0.7f,           // rosa
		1.0f, 1.0f,
		-65.0f, 20.0f, 120.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		25.0f);
	spotLightCount7++;

	// juego de Dado
	Da[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);
	spotLightCount8++;

	Da[1] = SpotLight(0.55f, 0.41f, 0.66f,           // rosa
		1.0f, 1.0f,
		-85.0f, 18.0f, -100.0,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		30.0f);
	spotLightCount8++;





	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0, uniformTextureOffset = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
	// bus de bob esponja 
	movBus = 0.0f;
	movOffset = 0.15f;
	llanta = 0.0f;
	llantaOffset = 3.0f;
	// carrusel movimento 
	movCa = 0.0f;
	offset = 0.10f;
	caballo = 0.0f;
	caballoff = 1.0;

	// esferas en movimeinto 
	movesferas = 0.0;
	set = 0.50;
	esfera = 0.0;
	esferaoff = 1.0;
	//diana creo esta
	posX = 0.0;
	//MOVIENTO MANOS GOKU
	rotManosGOK = 0.0;
	rotManosGOffset = 2.0;
	// movimienot broly 
	 // Movimiento de broly
	movBro = 0.0f;
	movBroOffset = 0.05;
	Piernas = 0.0f;
	PiernasOffset = 2.0;
	// movimeinto de giren 
	movGi = 0.0f;
	movGiOffset = 0.05f;
	Brazos = 0.0f;
	BrazosOffset = 2.0;
	//MOVIMIENTO FARO:
	movFaro = 0.0f;
	movOffsetFaro = 0.01f;
	rotaFaro = 0.0f;
	rotaFaroOffset = 2.0f;
	const float anguMaxFARO = 20.0f;
	const float anguMinFARO = -60.0f;

	//Movimiento HACHA
	movimiHACH = 0.0f;
	movOffsetHACH = 0.5f;
	rotaHACH = 0.0f;
	rotaHACHOffset = 8.0f;

	// movimiento del dardo juego de lanza el dardo 
	moveDardo = 0.0f;
	movOffsetDARD = 0.10f;
	rotadardo = 0.0f;
	rotadardo1 = 0.0f;
	rotadardo2 = 0.0f;
	rotadardo3 = 0.0f;
	dardooff = 0.5;

	//CALAMARDO
	rotHeadCALAM = 0.0f;
	rotaHeadCAOffset = 2.0f;

	movimCALAM = 0.0f;
	movOffsetCALAM = 0.05f;
	rotaPierna = 0.0f;
	rotaPiernOffset = 2.0f;


	//PATRICIO
	rotaBraPAT = 0.0f;
	rotaBraPATOffset = 0.5f;
	rotaHeadPAT = 0.0f;
	rotaHeadPATOffset = 0.5f;
	movHelado = 0.0;
	movOffsetHel = 0.01;
	// rueda de la fortuna 
	movimFortu = 0.0f;
	movOffsetFortun = 0.05f;
	rotaFortuna = 0.0f;
	rotaFortunaOffset = 1.0f;
	// movimiento de karen 
	moviKar = 0.0f;
	movOffsetKar = 0.05f;
	// movimeinto del juego del dado
	rotaVa = 0.0f;
	rotaVaOffset = 2.3f;
	const float Amaximo = 30.0f;
	const float Aminimo = -30.0f;
	movDado = 0.0f;
	movOffsetDado = 0.05f;
	rotaraD = 0.0f;
	rotaraDz = 0.0f;

	// vuelo de bardock 
	moviBar = 0.0f;
	movOffsetBar = 0.5f;
	// movimeinto para el juego de bateo 
	movPelota = 0.0f;
	movOffsetPelota = 0.2f;
	rotaPelota = 0.0f;
	rotaPeOffset = 5.0;
	posPelotaX = 0.0;
	//posPelotaY;
	float totalDistance = 22.0f;
	float halfDistance = totalDistance / 2.0f;
	float t;
	//movPelota2 = -4.0f * (t - 0.5f) * (t - 0.5f) + 4.0f;  // Parabola con altura máxima en Y=4
	//float contTIMEbat;
	rotaBAT = 0.0;
	rotaBATOffset = 6.0f;
	const float anguMaxBAT = 90.0f;
	const float anguMinBAT = -45.0f;
	// juego del pendulo 
	movP = 0.0f;
	movOffsetP = 0.2f;
	rotaPendu = 0.0f;
	rotaPenduOffset = 1.5f;
	// movimiento del juego de los patos 
	rotaPatos = 0.0;
	rotaPatosOffset = 2.0;
	movpato = 0.0;
	movOffsetPato = 0.5;

	//movimiento de guante 
	Guantos = 0.0f;
	GuaOffset = 0.5f;

	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		angulovaria += 0.5f * deltaTime;


		// movimiento del bus de bob esponja 
		if (recorre) {
			if (movBus > -40.0f)
			{
				movBus -= movOffset * deltaTime;
				llanta += llantaOffset * deltaTime;
			}

			else {
				recorre = false;
			}
		}
		else {
			if (movBus < 135.0f)
			{
				movBus += movOffset * deltaTime;
				llanta -= llantaOffset * deltaTime;
			}
			else {
				recorre = true;

			}
		}

		// movimeinto de carrusel 
		if (circulo) {
			if (movCa > -120.0f)
			{
				movCa -= offset * deltaTime;
				caballo += caballoff * deltaTime;
			}

			else {
				circulo = false;
			}
		}
		else {
			if (movCa < 150.0f)
			{
				movCa += offset * deltaTime;
				caballo -= caballoff * deltaTime;
			}
			else {
				circulo = true;

			}
		}


		// movimiento de esferas del dragon 
		llegaBola = true;
		if (chuza) {
			if (movesferas > 1.0f)
			{
				llegaBola = true;
				movesferas -= set * deltaTime;
				esfera += esferaoff * deltaTime;
			}

			else {
				if (mainWindow.getMONEDA() == 2) {
					chuza = false;
				}
			}
		}
		else {
			if (movesferas < 62.0f)
			{
				llegaBola = false;
				movesferas += set * deltaTime;
				esfera -= esferaoff * deltaTime;
			}
			else {
				chuza = true;
			}
		}


		// MOVIMIENTO DE BROLY 
		if (CAMINA) {
			if (movBro > -50.0f)
			{
				movBro -= movOffset * deltaTime;
				// Piernas+= PiernasOffset * deltaTime;
			}

			else {
				CAMINA = false;

			}
		}
		else {
			if (movBro < 50.0f)
			{
				movBro += movOffset * deltaTime;
				// Piernas -= PiernasOffset * deltaTime;

			}
			else {
				CAMINA = true;

			}
		}
		// Movimiento de giren 
		if (Walk) {
			if (movGi > -120.0f)
			{
				movGi -= movOffset * deltaTime;
				// Piernas+= PiernasOffset * deltaTime;
			}

			else {
				Walk = false;

			}
		}
		else {
			if (movGi < 120.0f)
			{
				movGi += movOffset * deltaTime;
				// Piernas -= PiernasOffset * deltaTime;

			}
			else {
				Walk = true;

			}
		}


		//rueda de la fortuna 
		if (For) {
			if (movimFortu > -120.0f)
			{
				movimFortu += movOffsetFortun * deltaTime;
				rotaFortuna -= rotaFortunaOffset * deltaTime;
			}

			else {
				For = false;
			}
		}
		else {
			if (movimFortu < 0.0f)
			{
				movimFortu -= movOffsetFortun * deltaTime;
				rotaFortuna += rotaFortunaOffset * deltaTime;
			}
			else {
				For = true;

			}
		}
		// movimiento de karen 

		if (robot) {
			if (moviKar > -40.0f)
			{
				moviKar -= movOffsetKar * deltaTime;
				//llanta += llantaOffset * deltaTime;
			}

			else {
				robot = false;
			}
		}
		else {
			if (moviKar < 135.0f)
			{
				moviKar += movOffsetKar * deltaTime;
				//llanta -= llantaOffset * deltaTime;
			}
			else {
				robot = true;

			}
		}
		// vuelo de bardock 
		if (BarVuela) {
			if (moviBar > -40.0f)
			{
				moviBar -= movOffsetBar * deltaTime;
				//llanta += llantaOffset * deltaTime;
			}

			else {
				BarVuela = false;
			}
		}
		else {
			if (moviBar < 50.0f)
			{
				moviBar += movOffsetBar * deltaTime;
				//llanta -= llantaOffset * deltaTime;
			}
			else {
				BarVuela = true;

			}
		}

		//MOVIMIENTO DE PRATRICIO 
		contTIMEP += 0.1 * deltaTime; // variable que cuenta el tiempo
		if (contTIMEP < 60.0f) {
			movHelaZ = 0.0;
			if (giraBrazoPAT) {
				rotaBraPAT += rotaBraPATOffset * deltaTime;
				if (rotaBraPAT >= 25.0) {
					rotaBraPAT = 25.0;
					giraBrazoPAT = false;
				}
			}
			else {
				rotaBraPAT -= rotaBraPATOffset * deltaTime;
				if (rotaBraPAT <= -5.0) {
					rotaBraPAT = -5.0;
					giraBrazoPAT = true;
				}
			}
		}

		else {
			movHelaZ = 0.2;
			rotaBraPAT = 0.0;
			if (movHelado < 0.96f)
			{
				movHelado += movOffsetHel * deltaTime;
			}
			else {
				if (giraHeadPAT) {
					rotaHeadPAT += rotaHeadPATOffset * deltaTime;
					if (rotaHeadPAT >= 40.0) {
						rotaHeadPAT = 40.0;
						giraHeadPAT = false;
					}
				}
				else {
					if (contTIMEP > 90.0f) {
						rotaHeadPAT -= rotaHeadPATOffset * deltaTime;
						if (rotaHeadPAT <= -2.0) {
							rotaHeadPAT = -2.0;
							giraHeadPAT = true;
							contTIMEP = 0.0;
							movHelado = 0.0;
						}
					}
				}
			}
		}




		// movimeinto de  de pendulo 
		if (Pen) {
			if (movP > -360.0f)
			{
				movP -= movOffsetP * deltaTime;
				rotaPendu += rotaPenduOffset * deltaTime;
			}

			else {
				Pen = false;
			}
		}
		else {
			if (movP < 0.0f)
			{
				movP += movOffsetP * deltaTime;
				rotaPendu -= rotaPenduOffset * deltaTime;
			}
			else {
				Pen = true;

			}
		}
		// movimeinto de los patos 
		if (Pat) {
			if (movpato > 0.0)
			{
				movpato += movOffsetPato * deltaTime;
				rotaPatos -= rotaPatosOffset * deltaTime;
			}

			else {
				Pat = false;
			}
		}
		else {
			if (movpato < 300.0f)
			{
				movpato -= movOffsetPato * deltaTime;
				rotaPatos += rotaPatosOffset * deltaTime;
			}
			else {
				Pat = true;

			}
		}

		srand(std::time(0));

		// Rango deseado: de 10 a 20
		int minimo = 1;
		int maximo = 3;
		int rango = maximo - minimo + 1;

		// Generar un número aleatorio en el rango
		int randomboli = minimo + (rand() % rango);
		int randompino = minimo + (rand() % rango);
		//TECLA DE NUMERO 1
		if (mainWindow.getTipoCAMARA() == 5.0) {
			activaCamNUM = 0;
		}
		//TECLA NUMERO 2
		if (mainWindow.getTipoCAMARA() == 6.0) {
			activaCamNUM = 1;
		}
		//TECLA NUMERO 3
		if (mainWindow.getTipoCAMARA() == 7.0) {
			activaCamNUM = 2;
		}

		if (activaCamNUM == 2) {
			if (mainWindow.getTipoGAME() == 1.0) {
				atracPos = CAMJuegoBOLICHE; // posición de la atracción
			}
			if (mainWindow.getTipoGAME() == 2.0) {
				atracPos = CAMJuegoTOPO; // posición de la atracción
			}
			if (mainWindow.getTipoGAME() == 3.0) {
				atracPos = CAMJuegoHACHA; // posición de la atracción
			}
			if (mainWindow.getTipoGAME() == 4.0) {
				atracPos = CAMJuegoGLOBO; // posición de la atracción
			}
			if (mainWindow.getTipoGAME() == 5.0) {
				atracPos = CAMJuegoDADO; // posición de la atracción
			}
			if (mainWindow.getTipoGAME() == 6.0) {
				atracPos = CAMJuegoBATEO; // posición de la atracción
			}
			if (mainWindow.getTipoGAME() == 7.0) {
				atracPos = CAMJuegoFoods; // posición de la atracción
			}
			cameras[2] = Camera(atracPos, glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.0f, 0.0f);
		}

		//Para indicar que posicion del arreglo utiliza, es decir que camara
		Camera& camera = cameras[activaCamNUM];


		//Recibir eventos del usuario
		glfwPollEvents();
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();
		uniformTextureOffset = shaderList[0].getOffsetLocation();

		//información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		float currentTime = glfwGetTime();
		if (currentTime - TiempoT >= Intervalo) {
			Dia = !Dia; // Cambiar entre día y noche
			TiempoT = currentTime; // Actualizar el tiempo del último cambio
		}

		// Configurar luz según el estado (día o noche)
		if (Dia == true) {
			// Luz del día (intensidad alta, dirección hacia arriba)
			mainLight = DirectionalLight(
				1.0f, 1.0f, 1.0f, // Color blanco
				0.6f, 0.6f,       // Componentes ambiente y difusa
				0.0f, 1.0f, 0.0f // Dirección hacia arriba (sol en el cielo)
			);

		}
		if (Dia == false) {
			// Luz de la noche (intensidad baja, dirección hacia abajo o apagada)
			mainLight = DirectionalLight(
				0.3f, 0.3f, 0.3f, // Color tenue
				0.1f, 0.1f,       // Componentes ambiente y difusa bajas
				0.0f, -1.0f, 0.0f  // Dirección hacia abajo (simulando ausencia de sol)
			);
		}

		//Pasar la luz al shader
		shaderList[0].SetDirectionalLight(&mainLight);





		// luz ligada a la cámara de tipo flash
		glm::vec3 lowerLight = camera.getCameraPosition();
		lowerLight.y -= 0.3f;
		spotLights[0].SetFlash(lowerLight, camera.getCameraDirection());

		//información al shader de fuentes de iluminación
		//shaderList[0].SetDirectionalLight(&mainLight);
		/*shaderList[0].SetPointLights(pointLights, pointLightCount);*/
		//shaderList[0].SetSpotLights(spotLights, spotLightCount);


		//LUCES PARA CAMARA PRIMERA PERSONA/RECORRIDO - tecla numero 1
		if (mainWindow.getTipoCAMARA() == 5.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(pointLights, pointLightCount);
			//SPOTLights de ese juego 
			shaderList[0].SetSpotLights(RuedaF, spotLightCount2);
		}

		//LUCES PARA CAMARA VISTA DE ARRIBA - tecla numero 2
		if (mainWindow.getTipoCAMARA() == 6.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(pointLights, pointLightCount);
			//SPOTLights de ese juego 
			shaderList[0].SetSpotLights(RuedaF, spotLightCount2);
		}

		//LUCES PARA CAMARA DE CADA ATRACCION - tecla numero 3

		//Si esta en CAMARA DE Juego DE BOLICHE prender sus respectivas luces
		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 1.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(boliche4, pointLightCount2);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(Boli, spotLightCount6);
		}
		//Si esta en CAMARA DE Juego DE TOPO prender sus respectivas luces
		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 2.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(top2, pointLightCount4);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(GTopo, spotLightCount7);
		}
		//Si esta en CAMARA DE Juego DE HACHA prender sus respectivas luces
		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 3.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(boliche4, pointLightCount2);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(Hac, spotLightCount1);
		}
		//Si esta en CAMARA DE Juego DE GLOBOS prender sus respectivas luces
		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 4.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(Glob, pointLightCount6);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(GlobosG, spotLightCount4);
		}

		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 5.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(Glob, pointLightCount6);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(Da, spotLightCount8);
		}

		//Si esta en CAMARA DE Juego DE GLOBOS prender sus respectivas luces
		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 6.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(JBateo, pointLightCount8);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(GlobosG, spotLightCount4);
		}

		// puestos de comida 

		if (mainWindow.getTipoCAMARA() == 7.0 && mainWindow.getTipoGAME() == 7.0) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(D, pointLightCount5);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(Food, spotLightCount5);
		}


		if (Dia == true) {
			//POINTLights de ese juego
			shaderList[0].SetPointLights(D, pointLighT);
			//SPOTLights de ese juego
			shaderList[0].SetSpotLights(T, spotLighT);
		}
		// condicionales para prender y apgar luces de la lcasa de bob esponja 

		if (mainWindow.getlamp() == 1.0) {
			shaderList[0].SetPointLights(Hbob, pointLightCount); // condicion para que prenda la lampara 
		}

		if (mainWindow.getlamp() == 0.0) {
			shaderList[0].SetPointLights(Hbob, pointLightCount - 1);   // condicion para que apague la lampara 
		}
		// lampara del area de comida 
		if (mainWindow.getFood() == 1.0) {
			shaderList[0].SetPointLights(Poste, pointLightCount); // condicion para que prenda la lampara 
		}

		if (mainWindow.getFood() == 0.0) {
			shaderList[0].SetPointLights(Poste, pointLightCount - 1);   // condicion para que apague la lampara 
		}



		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::mat4 auxGtopo(1.0);
		glm::mat4 Busbob(1.0);
		glm::mat4 Hachag(1.0);
		glm::mat4 Boliche(1.0);
		glm::mat4 Globos(1.0);
		glm::mat4 Rueda(1.0);
		glm::mat4 carritoB(1.0);
		glm::mat4 Gokuns(1.0);
		glm::mat4 Giren(1.0);
		glm::mat4 Broly(1.0);
		glm::mat4 Dinero(1.0);
		glm::mat4 auxPlank(1.0);
		glm::mat4 auxCalam(1.0);
		glm::mat4 auxPATRIK(1.0);
		glm::mat4 auxHacha(1.0);
		glm::mat4 auxGlobos(1.0);
		glm::mat4 auxGlobos1(1.0);
		glm::mat4 Bardock(1.0);
		glm::mat4 Jaulas(1.0);
		glm::mat4 GameDado(1.0);
		glm::mat4 LarryBra(1.0);
		glm::mat4 patitos(1.0);
		glm::mat4 GokuB(1.0);
		glm::mat4 Guantes(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::vec2 toffset = glm::vec2(0.0f, 0.0f);



		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
		model = glm::scale(model, glm::vec3(18.0f, 1.0f, 18.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[2]->RenderMesh();





		// puesto de comida de borcehtas 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-100.0f, 4.3f, -45.0));
		carritoB = model;
		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cbrochetas.RenderModel();

		// Carrito de elotes 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-120.0f, 4.4f, -45));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CarritoE.RenderModel();
		// carrito de tortas 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-80.0f, 4.5f, -45));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CarritoT.RenderModel();
		// carrito de tamales 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-142.0f, 4.5f, -28));
		model = glm::rotate(model, 65 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CTamales.RenderModel();
		// carrito de Aguas 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, -1.9f, -35.0f));
		model = glm::rotate(model, -65 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CarritoA.RenderModel();

		/*if (mainWindow.getTipoCAMARA() == 5.0) {*/
			// goku 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 40.0));
		model = glm::translate(model, glm::vec3(camera.getCameraPosition()));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		Gokuns = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		goku.RenderModel();
		//brazo izquierdo  de goku
		model = Gokuns;
		model = glm::translate(model, glm::vec3(-0.683f, 0.545f, 0.118));
		model = glm::rotate(model, glm::radians(an), glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BrazoD.RenderModel();
		float tiempoActual = glfwGetTime();


		animarBrazo = false; // Por defecto, no animar

		if (mainWindow.getsKeys()[GLFW_KEY_W] ||
			mainWindow.getsKeys()[GLFW_KEY_S] ||
			mainWindow.getsKeys()[GLFW_KEY_D] ||
			mainWindow.getsKeys()[GLFW_KEY_A]) {
			animarBrazo = true; // Animar si alguna tecla está presionada
		}
		//if (mainWindow.getsKeys()[GLFW_KEY_S]) {
		//	animarBrazo = false; // Se detiene la oscilación
		//}
		if (animarBrazo) {
			angulovaria += velocidad;
			if (angulovaria >= 360.0f) angulovaria -= 360.0f; // 
			an = 30.0f * sin(glm::radians(angulovaria)); // oscila entre -30 y 30
		}
		else {
			an = 0.0f; // brazo vuelve a posición neutra
		}

		// brazo derecho de goku 
		model = Gokuns;
		model = glm::translate(model, glm::vec3(0.515f, 0.531f, 0.083));
		model = glm::rotate(model, glm::radians(an), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BrazoI.RenderModel();


		// Pierna Derecha de goku  
		model = Gokuns;
		model = glm::translate(model, glm::vec3(-0.214f, -0.287f, 0.166));
		model = glm::rotate(model, glm::radians(an), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernaDGO.RenderModel();

		// Pierna izquierda de goku 
		model = Gokuns;
		model = glm::translate(model, glm::vec3(0.251f, -0.23f, 0.023));
		model = glm::rotate(model, glm::radians(an), glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernaIZGO.RenderModel();

		//}

		// Lamparas cerca de la ajula de bateo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.6f, -45.0));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara.RenderModel();

		// Lamparas cerca de la ajula de bateo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.6f, -20.0));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara.RenderModel();
		// Lamparas cerca de la ajula de bateo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.3f, 5.0));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara.RenderModel();
		// Lamparas cerca de la ajula de bateo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 0.3f, -45.0));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara.RenderModel();
		// Lamparas cerca de la ajula de bateo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 0.3f, -20.0));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara.RenderModel();
		// Lamparas cerca de la ajula de bateo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 0.3f, 5.0));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara.RenderModel();




		// valde de carnada  en area de comida
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-98.0f, -0.1f, -20));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		val.RenderModel();
		// casa de calamardo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(55.0f, -1.5f, 75.0));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cal.RenderModel();

		//// valde de carnada  cerac de la jaula de bateo  
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-45.0f, -0.1f, 50.5));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		val.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-110.0f, -1.5f, 95.0));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cal.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-45.0f, -1.5f, 135.0));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cal.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(50.0f, -1.5f, -90.0));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cal.RenderModel();






		// Carrusel 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-130.0f, 2.4f, 125.0));
		modelaux = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Base.RenderModel();

		// techo del carrusel 
		model = modelaux;
		model = glm::translate(model, glm::vec3(1.599f, 12.455f, -2.812));
		model = glm::rotate(model, caballo * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Techo.RenderModel();



		// caballo 1
		model = modelaux;
		model = glm::translate(model, glm::vec3(1.575f, 2.905f + sin(glm::radians(angulovaria)), -10.536));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ca1.RenderModel();


		// caballo 2
		model = modelaux;
		model = glm::translate(model, glm::vec3(-6.04f, 2.702f + sin(glm::radians(angulovaria)), -2.7));


		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ca2.RenderModel();


		// caballo 3
		model = modelaux;
		model = glm::translate(model, glm::vec3(1.794f, 2.894f + sin(glm::radians(angulovaria)), 4.913));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ca3.RenderModel();

		// caballo 4
		model = modelaux;
		model = glm::translate(model, glm::vec3(9.409f, 2.905f + sin(glm::radians(angulovaria)), -2.922));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ca4.RenderModel();

		// banca a lado de los puertos de comida 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-70.0f, 1.2f, 3.0));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BancaG.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 1.2f, 3.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BancaG.RenderModel();

		// banca a lado del juego de golepa al topo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-10.0f, 2.2f, 30.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BancaB.RenderModel();
		//Bnaca de dragon ball  en frente de rueda de la fortuna 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, 0.94f, 125.0));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BancaG.RenderModel();

		// Banca DE BOB ESPONJA 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-100.0f, 1.0f, 120.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BancaB.RenderModel();
		// autobus de bob esponja 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(145.0f, 0.0f, 130.0 - movBus));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		if (recorre == false) {
			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		}
		Busbob = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bus.RenderModel();
		// Aleta del bus 
		model = Busbob;
		model = glm::translate(model, glm::vec3(11.56f, 4.854f, 0.0));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Aleta.RenderModel();
		// Llanta izquierda 1  
		model = Busbob;
		model = glm::translate(model, glm::vec3(-4.855f, 0.047f, 4.001));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LlantaI1.RenderModel();
		// Llanta Izquierda 2 
		model = Busbob;
		model = glm::translate(model, glm::vec3(4.7f, 0.047f, 4.001));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LlantaI2.RenderModel();
		// Llanta Izquierda 3
		model = Busbob;
		model = glm::translate(model, glm::vec3(7.998f, 0.047f, 4.001));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LlantaI3.RenderModel();
		// Llanta Derecha 1 
		model = Busbob;
		model = glm::translate(model, glm::vec3(-4.855f, 0.047f, -4.001));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LlantaD1.RenderModel();
		// Llanta Derecha 2
		model = Busbob;
		model = glm::translate(model, glm::vec3(4.7f, 0.047f, -4.001));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LlantaD2.RenderModel();
		// Llanta Derecha 3
		model = Busbob;
		model = glm::translate(model, glm::vec3(7.998f, 0.047f, -4.001));
		model = glm::rotate(model, llanta * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LlantaD3.RenderModel();




		// Juego de boliche 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(90.0f, -1.1f, -90.0));
		Boliche = model;

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bol.RenderModel();

		// Esferas del dragon 
		// esfera 1  que es la que conlleva movimiento 
		model = Boliche;
		model = glm::translate(model, glm::vec3(0.0f + posX, 0.3f, 35.0 - movesferas));
		ultimaPOSx = caida;
		if (randomboli == 1 && llegaBola == true) {
			posX = -4.8;
			caida = 1;
		}
		if (randomboli == 2 && llegaBola == true) {

			posX = -4.0;
			caida = 2;
		}
		if (randomboli == 3 && llegaBola == true) {

			posX = -3.2;
			caida = 3;
		}
		if (chuza == true) {

			posX = 0.0;
			caida = ultimaPOSx;
		}
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, esfera * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera1.RenderModel();




		// pinos de lado izquierdo del juego 
		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.033f, -0.058f, -20.237));
		if (chuza == true && caida == 2) {

			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));

		}

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();


		model = Boliche;
		model = glm::translate(model, glm::vec3(-3.489f, -0.005f, -21.224));
		//TODOS LOS PINOS:
		if (chuza == true && caida == 2) {

			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));

		}
		//FIN TODOS LOS PINOS
		if (chuza == true && caida == 3) {

			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));

		}

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();
		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.593f, -0.005f, -21.224));

		if (chuza == true && caida == 1) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(-2.898f, -0.024f, -22.219));
		if (chuza == true && caida == 3) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.033f, 0.106f, -22.219));
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(-5.16f, 0.054f, -22.219));
		if (chuza == true && caida == 1) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(-5.704f, 0.065f, -23.206));
		if (chuza == true && caida == 1) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.593f, 0.047f, -23.206));
		if (chuza == true && caida == 1) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(-3.481f, 0.047f, -23.206));
		if (chuza == true && caida == 3) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		//PINO 10
		model = Boliche;
		model = glm::translate(model, glm::vec3(-2.362f, 0.005f, -23.206));
		if (chuza == true && caida == 3) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (chuza == true && caida == 2) {
			model = glm::rotate(model, 90 * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();






		// pinos de lado Derecho del juego 
		model = Boliche;
		model = glm::translate(model, glm::vec3(3.936f, -0.058f, -20.237));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(4.8f, -0.005f, -21.224));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(5.071f, -0.024f, -22.219));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(5.607f, 0.005f, -23.206));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(3.376f, -0.005f, -21.224));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(2.809f, 0.054f, -22.219));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(2.265f, 0.065f, -23.206));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(3.936f, 0.106f, -22.219));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(4.488f, 0.047f, -23.206));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();

		model = Boliche;
		model = glm::translate(model, glm::vec3(3.376f, 0.047f, -23.206));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pin.RenderModel();
		// Esferas del dragon 
		// Esfera 2
		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.0f, 0.5f, 35.5));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera2.RenderModel();
		// Esfera 3
		model = Boliche;
		model = glm::translate(model, glm::vec3(-5.0f, 0.5f, 35.2));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera3.RenderModel();
		// Esfera 4
		model = Boliche;
		model = glm::translate(model, glm::vec3(-5.0f, 0.5f, 35.7));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera4.RenderModel();
		// Esfera 5
		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.0f, 0.5f, 35.7));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera5.RenderModel();
		// Esfera 6
		model = Boliche;
		model = glm::translate(model, glm::vec3(-4.0f, 0.5f, 35.2));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera6.RenderModel();
		// Esfera 7
		model = Boliche;
		model = glm::translate(model, glm::vec3(-5.0f, 0.5f, 35.2));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Esfera7.RenderModel();

		// kame house 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-2.0f, -3.5f, 75.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Kame.RenderModel();

		// botes de refreescos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 3.5f, -35.0));
		model = glm::rotate(model, -65 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		botes.RenderModel();

		// base de la rueda de la fortuna 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(90.0f, 5.0f, 65.0));
		Rueda = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BaseR.RenderModel();

		// rueda de la fortuna 
		model = Rueda;
		model = glm::translate(model, glm::vec3(0.0f, 32.205f, 6.247));
		model = glm::rotate(model, rotaFortuna * toRadians, glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cuerpoR.RenderModel();

		// Nave de trunks 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(50.0f, -1.5f, -15.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Nave.RenderModel();
		// Karin 

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, -1.5f, 134.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		KA.RenderModel();

		//giren
		// Cuerpo de Giren
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f + movGi, 4.5f, 25));
		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		if (Walk == false) {
			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		}
		Giren = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BOB.RenderModel();
		// movimiento de broly rotacinde las piernas 
		if (Lento) {
			Brazos += 2 * deltaTime;
			if (Brazos >= 30) {
				Brazos = 30;
				Lento = false;
			}
		}
		else {
			Brazos -= 2 * deltaTime;
			if (Brazos <= 0.0) {
				Brazos = -30;
				Lento = true;
			}
		}

		// Pierna derecha de Giren  
		model = Giren;
		model = glm::translate(model, glm::vec3(-0.939f, -0.713f, 0.842));
		model = glm::rotate(model, Brazos * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Piernad.RenderModel();
		// Pierna Izquierda de Giren 
		model = Giren;
		model = glm::translate(model, glm::vec3(1.12f, -0.617f, 0.378));
		model = glm::rotate(model, Brazos * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernaIz.RenderModel();
		// Brazo Izquierdo de Giren 
		model = Giren;
		model = glm::translate(model, glm::vec3(2.795f, 5.267f, 0.06));
		model = glm::rotate(model, Brazos * toRadians, glm::vec3(0.0f, -1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BrazoIz.RenderModel();
		// Brazo Derecho Giren 
		model = Giren;
		model = glm::translate(model, glm::vec3(-3.436f, 5.267f, 0.957));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Brazod.RenderModel();


		//broly
	   // Cuerpo de broly
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(37.0f, 4.5f, 30 + movBro));
		if (CAMINA == true) {
			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		}
		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		Broly = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CUB.RenderModel();




		// movimiento de broly rotacinde las piernas 
		if (Aleteo) {
			Piernas += 2 * deltaTime;
			if (Piernas >= 30) {
				Piernas = 30;
				Aleteo = false;
			}
		}
		else {
			Piernas -= 2 * deltaTime;
			if (Piernas <= 0.0) {
				Piernas = -30;
				Aleteo = true;
			}
		}

		// Pierna derecha de broly  
		model = Broly;
		model = glm::translate(model, glm::vec3(-0.641f, -0.543f, 0.403));
		model = glm::rotate(model, Piernas * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernadB.RenderModel();
		// Pierna Izquierda de broly 
		model = Broly;
		model = glm::translate(model, glm::vec3(0.949f, -0.331f, 0.666));
		model = glm::rotate(model, Piernas * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernaizB.RenderModel();
		// Brazo Izquierdo de broly 
		model = Broly;
		model = glm::translate(model, glm::vec3(2.867f, 4.863f, -0.39));
		//model = glm::rotate(model, Piernas * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Brazoiz.RenderModel();
		// Brazo Derecho broly 
		model = Broly;
		model = glm::translate(model, glm::vec3(-3.266f, 4.857f, -0.182));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BarzodB.RenderModel();

		// cuerpo de don kangrejo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-98.0f, 1.6f, -52.0));
		Dinero = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		KanCuerpo.RenderModel();
		// Brazo Izquierdo de don kangrejo 
		model = Dinero;
		model = glm::translate(model, glm::vec3(3.799, 2.446f, 0.79));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		KanIZ.RenderModel();
		// Brazo Derecho de don kangrejo 
		model = Dinero;
		model = glm::translate(model, glm::vec3(-3.493f, 2.504f, 0.532));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		KanD.RenderModel();
		float time3 = static_cast<float>(glfwGetTime());
		float a_Separacion = 0.1f;
		float anguloG = time3 * 1.0f; //5.0 es la velocidad
		float radio = a_Separacion * anguloG;
		float x = radio * cos(anguloG); //Coordenada cartesiana X
		float y = radio * sin(anguloG); //Coordenada cartesiana Y
		// Gary con mivimiento de espiral de arquimedes 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(55.0f + x, -2.0f, -55.0f + y));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ga.RenderModel();

		// karen 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(48.0f + 0.5 * sin(glm::radians(angulovaria)), -1.7f, 35.0 + moviKar));
		if (robot == true) {
			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Karen.RenderModel();
		// Puff
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, -2.2f, 80.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Puff.RenderModel();
		// calamrdo guapo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-90.0f, -2.0f, 120.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Guapo.RenderModel();
		// policias
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, -1.5f, 140.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Patru.RenderModel();
		// policia 2 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, -1.5f, 140.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Patru.RenderModel();
		// policia3
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-90.0f, -2.1f, 130.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Patru.RenderModel();

		// Picolo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, -2.0f, -65.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pic.RenderModel();
		// Vegetta
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(118.0f, 0.5f, 75.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Vege.RenderModel();
		// Glorio
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, -1.9f, -67.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Glo.RenderModel();
		//  movimiento de las medusas lemniscata
		float time = static_cast<float>(glfwGetTime());
		float anguloT = time * 5.0f; //5.0 es la velocidad
		float a_tam = 0.4f; // Tamaño de lemniscata
		float abajo = 1.0f + sin(anguloT) * sin(anguloT);
		float cord_x = (a_tam * cos(anguloT)) / abajo;
		float cord_y = (a_tam * sin(anguloT) * cos(anguloT)) / abajo;



		// cuerpo de PATRICIO
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, -2.0f, -53.0));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		auxPATRIK = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		bodyPAT.RenderModel();
		// cabeza de PATRICIO
		model = auxPATRIK;
		model = glm::translate(model, glm::vec3(0.036f, 0.871f, 0.227f));
		model = glm::rotate(model, rotaHeadPAT * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		headPAT.RenderModel();
		//BRAZO DE PATRICIO
		model = auxPATRIK;
		model = glm::translate(model, glm::vec3(0.384f, 0.784f, -0.04f));
		model = glm::rotate(model, rotaBraPAT * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		auxPATRIK = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		brazoPAT.RenderModel();
		//HELADO DE PATRICIO
		model = auxPATRIK;
		model = glm::translate(model, glm::vec3(-0.244f, 0.196f - movHelado, 0.322f + movHelaZ));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		heladoPAT.RenderModel();


		srand(std::time(0));

		// Rango deseado: de 10 a 20
		int min = 1;
		int max = 5;
		int ran = max - min + 1;

		// Generar un número aleatorio en el rango
		int randomMEDUSA = min + (rand() % ran);
		int randomFARO = min + (rand() % ran);


		// Juego de golpea al topo version universo de bob esponja 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-65.0f, -2.13f, 120.0));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		auxGtopo = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Game.RenderModel();
		// medusa 1
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(-0.483f, 4.506f, 1.29));
		if (randomMEDUSA == 1 && mainWindow.getMONEDA() == 2 && contTIME3 < 60.0f) {
			model = glm::translate(model, glm::vec3(cord_y, cord_x, 0.0));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Medu.RenderModel();
		// medusa 2
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(-0.483f, 4.506f, -0.031));
		if (randomMEDUSA == 2 && mainWindow.getMONEDA() == 2 && contTIME3 < 60.0f) {
			model = glm::translate(model, glm::vec3(cord_y, cord_x, 0.0));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Medu.RenderModel();
		// medusa 3
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(-0.483f, 4.506f, -1.332));
		if (randomMEDUSA == 3 && mainWindow.getMONEDA() == 2 && contTIME3 < 60.0f) {
			model = glm::translate(model, glm::vec3(cord_y, cord_x, 0.0));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Medu.RenderModel();
		// medusa 4
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(0.967f, 3.845f, -0.904));
		if (randomMEDUSA == 4 && mainWindow.getMONEDA() == 2 && contTIME3 < 60.0f) {
			model = glm::translate(model, glm::vec3(cord_y, cord_x, 0.0));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Medu.RenderModel();
		//medusa 5
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(0.967f, 3.845f, 0.785));
		if (randomMEDUSA == 5 && mainWindow.getMONEDA() == 2 && contTIME3 < 60.0f) {
			model = glm::translate(model, glm::vec3(cord_y, cord_x, 0.0));
		}
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Medu.RenderModel();


		//Inicio de juego
		if (mainWindow.getMONEDA() == 2)
		{
			contTIME3 += 0.1 * deltaTime; // variable que cuenta el tiempo
			//Traslacion y rotacion de FARO mientras dura el tiempo del juego (60)
			if (contTIME3 < 60.0f) {
				if (giraFaro) {
					rotaFaro += rotaFaroOffset * deltaTime;
					if (rotaFaro >= anguMaxFARO) {
						rotaFaro = anguMaxFARO;
						giraFaro = false;
					}
				}
				else {
					rotaFaro -= rotaFaroOffset * deltaTime;
					if (rotaFaro <= anguMinFARO) {
						rotaFaro = anguMinFARO;
						giraFaro = true;
					}
				}


				if (randomFARO == 1) {
					posXFARO = 0.79;
					posYFARO = 5.78;
					posZFARO = 0.5;
				}
				if (randomFARO == 2) {
					posXFARO = 0.79;
					posYFARO = 5.78;
					posZFARO = -0.78;
				}
				if (randomFARO == 3) {
					posXFARO = 0.79;
					posYFARO = 5.78;
					posZFARO = -2.0;
				}
				if (randomFARO == 4) {
					posXFARO = 2.09;
					posYFARO = 5.0;
					posZFARO = -1.7;
				}
				if (randomFARO == 5) {
					posXFARO = 2.09;
					posYFARO = 5.0;
					posZFARO = -0.16;
				}

				if (randomMEDUSA == randomFARO && giraFaro == false) {
					golpeTOPO = true;
					numeroGolpes += 1;
				}
				else {
					golpeTOPO = false;
				}
			}

			if (contTIME3 > 60.0f) {
				golpeTOPO = false; //No texturiza Winner
				rotaFaro = 0.0;
				if (numeroGolpes > 2) {
					ganadorTopo = true;  //Textura de que gano Patricio con trofeo 
				}
				else {
					ganadorTopo = false;
				}
			}
		}

		if (mainWindow.getMONEDA() == 1)
		{
			//POSICION INICIAL DEL juego antes de empezar a jugar
			contTIME3 = 0.0; //Reiniciar el contador de tiempo
			numeroGolpes = 0.0;
			golpeTOPO = false; //No texturiza Winner
			ganadorTopo = false; //Quita textura de que gano
			rotaFaro = 0.0;
		}

		// maso - FARO
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(0.0f + posXFARO, 0.0f + posYFARO, 0.0f + posZFARO));
		model = glm::rotate(model, rotaFaro * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Faro.RenderModel();
		// juegos de version al topo que estran fuera de servicio 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-70.0f, -2.13f, 120.0));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Game.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, -2.13f, 120.0));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Game.RenderModel();



		//JUEGO DE HACHA
	   // Juego del lanzamiento de hacha 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-14.0f, -2.0f, -87.0));
		auxHacha = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gamehacha.RenderModel();

		// CABINA HACHA 
		model = auxHacha;
		model = glm::translate(model, glm::vec3(0.0f, -0.2f, 10.808f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CabinaHacha.RenderModel();

		if (mainWindow.getMONEDA() == 2)
		{
			contadorTIME += 0.07 * deltaTime;

			if (mueveHACH) {
				if (movimiHACH > 0.0f)
				{
					//movimiHACH = 1.0;
					movimiHACH -= movOffsetHACH * deltaTime;
					rotaHACH = 0.0;
				}
				else {
					mueveHACH = false;
					contadorTIME = 0.0;
				}
			}

			else {

				if (movimiHACH < 25.0f)
				{
					movimiHACH += movOffsetHACH * deltaTime;
					rotaHACH -= rotaHACHOffset * deltaTime;
				}
				else {
					if (contadorTIME > 30.0f) {
						contadorTIME = 0.0;
						mueveHACH = true;
						//movimiHACH = 0.0f;
						posTIRO += 1;
					}
				}
				if (posTIRO == 0) {
					posTIROx = 1.5;
					posTIROy = 0.5;
					//tache1 = true;
				}
				if (posTIRO == 1) {
					posTIROx = -2.7;
					posTIROy = 0.7;
					tache1 = true;
				}
				if (posTIRO == 2) {
					posTIROx = 0.0;
					posTIROy = 0.6;
					tache2 = true;
				}
				if (posTIRO == 3) {
					movimiHACH = 0.0;
					rotaHACH = 0.0;
					tache3 = true;
					/*posTIROx = 0.0;
					posTIROy = 0.0;*/
					//	//posTIRO = 0;
				}
			}
		}


		//REINICIA EL JUEGO CON LETRA R
		if (mainWindow.getMONEDA() == 1)
		{
			//POSICION INICIAL DEL juego antes de empezar a jugar
			movimiHACH = 0.0;
			rotaHACH = 0.0;
			posTIRO = 0.0;
			posTIROx = 0.0;
			posTIROy = 0.0;
			contadorTIME = 0.0;
			tache1 = false;
			tache2 = false;
			tache3 = false;
		}

		// HACHA 
		model = auxHacha;
		model = glm::translate(model, glm::vec3(0.0f + posTIROx, 4.697f + posTIROy, 27.174 - movimiHACH));
		//model = glm::translate(model, glm::vec3(0.0f, 4.697f, 1.826 + movimiHACH));
		model = glm::rotate(model, rotaHACH * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Hacha.RenderModel();


		//MOVIMIENTO DE DARDO:
		if (mainWindow.getMONEDA() == 2)
		{
			contTIME2 += 0.1 * deltaTime; // variable que cuenta el tiempo
			//Lanzamiento de dardo, traslacion y rotacion
			if (moveDardo < 0.0f)
			{
				moveDardo += movOffsetDARD * deltaTime;
				rotadardo -= dardooff * deltaTime;
			}
			else {
				//Condicional para esperar un poco antes de lanzar el proximo dardo
				if (contTIME2 > 25.0f) {
					contTIME2 = 0.0;  //Reiniciar el contador de tiempo
					moveDardo = -15.0f; //Empezar a girar Dardo
					rotadardo = 0.0;
					posTIROglobo += 1; //Numero de dardo que se lanzará

				}
			}

			//Primer Lanzamiento primer dardo en Globo con cara de PUFF
			if (posTIROglobo == 1) {
				movDardo1 = moveDardo; //Traslacion del dardo
				rotadardo1 = rotadardo; //Rotacion de dardo
				if (moveDardo > -1.0f) {
					bajaGlob1 = 6.0;   //Simular globo reventado (desaparece)
				}
			}
			//Segundo Lanzamiento segundo dardo en Globo con cada de Plankton
			if (posTIROglobo == 2) {
				movDardo2 = moveDardo;
				rotadardo2 = rotadardo;
				if (moveDardo > -1.0f) {
					bajaGlob2 = 12.0;
				}
			}
			// Tercer Lanzamiento tercer dardo en Globo con cara de calamardo
			if (posTIROglobo == 3) {
				movDardo3 = moveDardo;
				rotadardo3 = rotadardo;
				if (moveDardo > 0.0f) {
					bajaGlob3 = 5.0;
				}
			}
			//POSICION INICIAL DEL juego antes de empezar a jugar
			if (posTIROglobo == 0) {
				movDardo1 = -20.0f;
				movDardo2 = -20.0f;
				movDardo3 = -20.0f;
				posTIROglobo = 0;
				bajaGlob1 = 0.0;
				bajaGlob2 = 0.0;
				bajaGlob3 = 0.0;
				movimCALAM = 0.0;
			}
		}

		//REINICIA EL JUEGO CON LETRA R
		if (mainWindow.getMONEDA() == 1)
		{
			//POSICION INICIAL DEL juego antes de empezar a jugar
			movDardo1 = -20.0f;
			movDardo2 = -20.0f;
			movDardo3 = -20.0f;
			posTIROglobo = 0;
			bajaGlob1 = 0.0;
			bajaGlob2 = 0.0;
			bajaGlob3 = 0.0;
			movimCALAM = 0.0;
		}

		// juego de revienta el globo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-100.0f, -1.5f, 70.0));
		auxGlobos = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo.RenderModel();

		// dardo 1
		model = auxGlobos;
		model = glm::translate(model, glm::vec3(1.373f, 6.975f, 0.3 - movDardo1));
		model = glm::rotate(model, rotadardo1, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dar.RenderModel();
		// dardo 2
		model = auxGlobos;
		model = glm::translate(model, glm::vec3(-4.813f, 10.338f, 0.3 - movDardo2));
		model = glm::rotate(model, rotadardo2, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dar.RenderModel();
		// dardo 3
		model = auxGlobos;
		model = glm::translate(model, glm::vec3(-2.498f, 5.215f, 0.3 - movDardo3));
		model = glm::rotate(model, rotadardo3, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dar.RenderModel();
		// globo con cara de  calamardo 
		model = auxGlobos;
		model = glm::translate(model, glm::vec3(-2.498f, 5.215f - bajaGlob3, -0.236));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo1.RenderModel();
		// globo con cara de puff
		model = auxGlobos;
		model = glm::translate(model, glm::vec3(1.33f, 6.794f - bajaGlob1, -0.238));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo2.RenderModel();
		//globo con cara de Plankton
		model = auxGlobos;
		model = glm::translate(model, glm::vec3(-4.813, 10.338f - bajaGlob2, -0.235));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo3.RenderModel();
		//juegos solo para visualizar 
		// juego de revienta el globo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-130.0f, -1.5f, 70.0));
		auxGlobos1 = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo.RenderModel();
		// globo con cara de  calamardo 
		model = auxGlobos1;
		model = glm::translate(model, glm::vec3(-2.498f, 5.215f - bajaGlob3, -0.236));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo1.RenderModel();
		// globo con cara de puff
		model = auxGlobos1;
		model = glm::translate(model, glm::vec3(1.33f, 6.794f - bajaGlob1, -0.238));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo2.RenderModel();
		//globo con cara de Plankton
		model = auxGlobos1;
		model = glm::translate(model, glm::vec3(-4.813, 10.338f - bajaGlob2, -0.235));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo3.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-115.0f, -1.5f, 70.0));
		Globos = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo.RenderModel();
		// globo con cara de  calamardo 
		model = Globos;
		model = glm::translate(model, glm::vec3(-2.498f, 5.215f - bajaGlob3, -0.236));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo1.RenderModel();
		// globo con cara de puff
		model = Globos;
		model = glm::translate(model, glm::vec3(1.33f, 6.794f - bajaGlob1, -0.238));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo2.RenderModel();
		//globo con cara de Plankton
		model = Globos;
		model = glm::translate(model, glm::vec3(-4.813, 10.338f - bajaGlob2, -0.235));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		globo3.RenderModel();
		// plankton 
		model = auxGtopo;
		model = glm::translate(model, glm::vec3(-1.0f, 5.65f, -1.6));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//model = glm::translate(model, glm::vec3(3.5f, 0.0f, 0.5));
		auxPlank = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Plank.RenderModel();
		// Brazo derecho de plankton 
		model = auxPlank;
		model = glm::translate(model, glm::vec3(-0.336f, 0.925f, -0.038));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		brazoPlankD.RenderModel();
		// Brazo Izquierdo de plankton 
		model = auxPlank;
		model = glm::translate(model, glm::vec3(0.366f, 0.925f, -0.038));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		brazoPlankI.RenderModel();

		//CALAMARDO
		//Movimiento cabeza Calamardo
		if (posTIROglobo == 1) {
			if (dirHeadC) {
				rotHeadCALAM += rotaHeadCAOffset * deltaTime;
				if (rotHeadCALAM >= 30) {
					rotHeadCALAM = 30;
					dirHeadC = false;
				}
			}
			else {
				rotHeadCALAM -= rotaHeadCAOffset * deltaTime;
				if (rotHeadCALAM <= -30) {
					rotHeadCALAM = -30;
					dirHeadC = true;
				}
			}
		}
		//AVANZA CALAMARDO
		//Rotacion de piernas
		if (posTIROglobo == 2 || posTIROglobo == 3) {
			movimCALAM -= movOffsetCALAM * deltaTime;
			if (doblaPiern) {
				rotaPierna += rotaPiernOffset * deltaTime;
				if (rotaPierna >= 30) {
					rotaPierna = 30;
					doblaPiern = false;
				}
			}
			else {
				rotaPierna -= rotaPiernOffset * deltaTime;
				if (rotaPierna <= -30) {
					rotaPierna = -30;
					doblaPiern = true;
				}
			}
		}
		// cuerpo de calamardo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-88.0f, -1.5f, 70.0 - movimCALAM));
		auxCalam = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoCALAM.RenderModel();
		// cabeza de calmardo 
		model = auxCalam;
		model = glm::translate(model, glm::vec3(0.019f, 5.529f, -0.023f));
		model = glm::rotate(model, rotHeadCALAM * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CabezaCALAM.RenderModel();

		model = auxCalam;
		model = glm::translate(model, glm::vec3(-0.1f, 3.2f, 0.0f));
		model = glm::rotate(model, rotaPierna * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		piernDcalam.RenderModel();

		model = auxCalam;
		model = glm::translate(model, glm::vec3(0.1f, 3.2f, 0.0f));
		model = glm::rotate(model, rotaPierna * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		piernIcalam.RenderModel();
		//LAMPARA DE CRUSTACEO 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-132.0f, 13.0f, -36.0));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		lampKrusty_M.RenderModel();
		// lampara a lado de los puestos de globos 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-122.0f, 13.0f, 75.0));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		lampKrusty_M.RenderModel();

		//CASA BOB SPONJA
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, -3.8f, -70.0));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		model = glm::rotate(model, 210 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casaBOB.RenderModel();




		// Despues de la entrega de laboratorio 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-120.0f, 6.4f, -52.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BobVigi.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-80.0f, 4.7f, -52.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BobSir.RenderModel();


		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-147.0f, 4.7f, -35.0));
		model = glm::rotate(model, 65 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BobGlobo.RenderModel();


		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-51.0f, 4.8f, -38.0));
		model = glm::rotate(model, -65 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BobEle.RenderModel();


		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-165.0f, 4.8f, 3.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BobConejo.RenderModel();

		// heladeria 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-145.0f, -1.8f, 3.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Helados.RenderModel();


		// Mesa1
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-120.0f, 0.0f, 7.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mesa.RenderModel();



		// Mesa 2 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-85.0f, 0.0f, -28.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mesa.RenderModel();



		// Mesa 3  
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-110.0f, 0.0f, -28.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mesa.RenderModel();

		// Mesa 4 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-95.0f, 0.0f, 3.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mesa.RenderModel();


		// brochetas para el puesto de comida 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-95.0f, 4.0f, -45.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Brocheta.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-98.0f, 4.0f, -45.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Brocheta.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-101.0f, 4.0f, -45.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Brocheta.RenderModel();




		// Cuerpo de bardock  
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f + moviBar, 25.4f, 0.0));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		if (BarVuela == true) {
			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		}
		Bardock = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CuBar.RenderModel();

		// Brazo Derecho de bardock 
		model = Bardock;
		model = glm::translate(model, glm::vec3(-1.663f, 1.851f, -0.083));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BrazoDBar.RenderModel();
		// Brazo Izquierdo de bardock 
		model = Bardock;
		model = glm::translate(model, glm::vec3(0.908f, 2.194f, -0.11));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BrazoIZBar.RenderModel();





		//MOVIMIENTO DE pelota de  beisbol 
		if (mainWindow.getMONEDA() == 2)
		{
			if (muevePELOTA) {
				//posPelotaX += posDardoX;
				if (movPelota > 0.0f)
				{
					if (numPELOTA < 4) {
						rotaBAT -= rotaBATOffset * deltaTime;
						if (rotaBAT <= anguMinBAT) {
							rotaBAT = anguMinBAT;
							mueveBAT = true;
						}
					}
					posPelotaX += (0.02 * deltaTime) * numPELOTA; // Movimiento en X
					movPelota -= movOffsetPelota * deltaTime; //Movmiento en Z
					rotaPelota += rotaPeOffset * deltaTime;
					t = movPelota / totalDistance;
					movPelota2 = -32.0f * (t - 0.5f) * (t - 0.5f) + 4.0f;  // Parabola, traslado en Y
				}
				else {
					muevePELOTA = false;
					numPELOTA += 1; //Numero de dardo que se lanzará
					rotaBAT = 0.0;

				}
			}
			else {
				if (movPelota < 22.0f)
				{
					movPelota += movOffsetPelota * deltaTime;
					rotaPelota -= rotaPeOffset * deltaTime;
					movPelota2 = 0.0f;
					posPelotaX = 0.0f;

					if (movPelota > 18.0f && numPELOTA < 4)
					{
						rotaBAT += rotaBATOffset * deltaTime;
					}


				}
				else {


					if (mueveBAT && numPELOTA < 4) {
						rotaBAT += rotaBATOffset * deltaTime;
						if (rotaBAT >= anguMaxBAT) {
							rotaBAT = anguMaxBAT;
							mueveBAT = false;
						}
					}
					else {
						muevePELOTA = true;
					}

					/*muevePELOTA = true;
					posPelotaX += 1;*/

				}
			}


			if (numPELOTA == 1) {
				movP1 = movPelota; //Traslacion del dardo
				movP11 = movPelota2; //Traslacion del dardo
				rotaP1 = rotaPelota; //Rotacion de dardo
				posPelotaX1 = posPelotaX;
				//if (movPelota > -1.0f) {
				//	bajaGlob1 = 6.0;   //Simular globo reventado (desaparece)
				//}
			}
			/*else
			{
				movP11 = 0.0;
			}*/
			//Segundo Lanzamiento segundo dardo en Globo con cada de Plankton
			if (numPELOTA == 2) {
				movP2 = movPelota; //Traslacion del dardo
				movP22 = movPelota2; //Traslacion del dardo
				rotaP2 = rotaPelota; //Rotacion de 
				posPelotaX2 = posPelotaX;
				/*if (movP2 <= 2.0f)
				{
					movP11 -= movOffsetPelota * deltaTime;
				}*/
				//if (movPelota > -1.0f) {
				//	bajaGlob1 = 6.0;   //Simular globo reventado (desaparece)
				//}
			}
			// Tercer Lanzamiento tercer dardo en Globo con cara de calamardo
			if (numPELOTA == 3) {
				movP3 = movPelota; //Traslacion del dardo
				movP33 = movPelota2; //Traslacion del dardo
				rotaP3 = rotaPelota; //Rotacion de dardo
				posPelotaX3 = posPelotaX;
				//if (movPelota > -1.0f) {
				//	bajaGlob1 = 6.0;   //Simular globo reventado (desaparece)
				//}
			}
		}
		////REINICIA EL JUEGO CON LETRA R
		if (mainWindow.getMONEDA() == 1)
		{
			//POSICION INICIAL DEL juego antes de empezar a jugar
			numPELOTA = 0;
			movPelota = 0.0;
			movPelota2 = 0.0;
			posPelotaX = 0.0;
			posPelotaX1 = 0.0;
			posPelotaX2 = 0.0;
			posPelotaX3 = 0.0;
			rotaPelota = 0.0;
			rotaBAT = 0.0;

			movP3 = 0.0f; //Traslacion del dardo
			movP33 = 0.0f; //Traslacion del dardo
			rotaP3 = 0.0f; //Rotacion de dardo
			movP2 = 0.0f; //Traslacion del dardo
			movP22 = 0.0f; //Traslacion del dardo
			rotaP2 = 0.0f; //Rotacion de dardo
			movP1 = 0.0f; //Traslacion del dardo
			movP11 = 0.0f; //Traslacion del dardo
			rotaP1 = 0.0f; //Rotacion de dardo
		}








		// juego del bat 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-130.0f, -0.5f, -115));
		Jaulas = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Jaula.RenderModel();

		// Pelota 1 
		model = Jaulas;
		model = glm::translate(model, glm::vec3(-0.202f + posPelotaX3, 4.51f + movP33, -23.0 + movP3));
		model = glm::rotate(model, rotaP3 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pelota.RenderModel();

		// Pelota 2
		model = Jaulas;
		model = glm::translate(model, glm::vec3(-0.202f + posPelotaX2, 4.51f + movP22, -22.3 + movP2));
		model = glm::rotate(model, rotaP2 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pelota.RenderModel();

		// Pelota  3
		model = Jaulas;
		model = glm::translate(model, glm::vec3(-0.202f + posPelotaX1, 4.51f + movP11, -21.5 + movP1));
		model = glm::rotate(model, rotaP1 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pelota.RenderModel();

		//INSTANCIA DE GOKU
		//HEREDA LA POSICION DE LA JAULA
		model = Jaulas;
		model = glm::translate(model, glm::vec3(-2.7f, 0.5f, -0.083));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		GokuB = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cuerp.RenderModel();

		//Brazo derecho de goku 
		model = GokuB;
		model = glm::translate(model, glm::vec3(0.518f, 1.592f, -0.142));
		model = glm::rotate(model, rotaBAT * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		bra.RenderModel();


		// Bat 
		//model = Jaulas;
		model = GokuB;
		model = glm::translate(model, glm::vec3(1.0f, 1.592f, -0.142));
		model = glm::rotate(model, rotaBAT * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bat.RenderModel();




		// juego de los dados  
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-85.0f, -2.0f, -100.0));
		GameDado = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MesaGame.RenderModel();

		srand(std::time(0));

		// Rango deseado: de 10 a 20
		int minimoD = 1;
		int maximoD = 6;
		int rangoDAD = maximoD - minimoD + 1;

		// Generar un número aleatorio en el rango
		int randomDADO = minimo + (rand() % rangoDAD);

		if (mainWindow.getMONEDA() == 2) {
			ContTimer4 += 0.1 * deltaTime; // variable que cuenta el tiempo
			if (ContTimer4 < 30.0f) {
				if (GameDA) {
					rotaVa += rotaVaOffset * deltaTime;
					if (rotaVa >= Amaximo) {
						rotaVa = Amaximo;
						GameDA = false;
					}
				}
				else {
					rotaVa -= rotaVaOffset * deltaTime;
					if (rotaVa <= Aminimo) {
						rotaVa = Aminimo;
						GameDA = true;
					}
				}

			}
			else {
				rotaVa = 90.0f;
			}
			if (rotaVa == 90.0f) {
				if (movDado <= 2.8f)
				{
					movDado += movOffsetDado * deltaTime;
					if (randomDADO == 1) {
						rotaraD = 90.0f;
						rotaraDz = 0.0f;
					}
					if (randomDADO == 2) {
						rotaraD = -90;
						rotaraDz = 0.0f;
					}
					if (randomDADO == 3) {
						rotaraD = 180.0f;
						rotaraDz = 0.0f;
					}
					if (randomDADO == 4) {
						rotaraD = 0.0f;
						rotaraDz = 0.0f;
					}
					if (randomDADO == 5) {
						rotaraDz = 90.0f;
						rotaraD = 0.0f;
					}
					if (randomDADO == 6) {
						rotaraDz = -90.0f;
						rotaraD = 0.0f;
					}
				}
			}
		}


		//REINICIA EL JUEGO CON LETRA R
		if (mainWindow.getMONEDA() == 1)
		{
			ContTimer4 = 0.0;
			rotaVa = 0.0;
			movDado = 0.0;
			rotaraD = 0.0f;
			rotaraDz = 0.0f;
		}







		//Cuerpo de larry 
		model = GameDado;
		model = glm::translate(model, glm::vec3(1.2f, 0.2f, -6.0));
		LarryBra = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoLa.RenderModel();
		// brazo de larry 
		model = LarryBra;
		model = glm::translate(model, glm::vec3(3.333f, 8.734f, -0.592));
		model = glm::rotate(model, rotaVa * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		LarryBra = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BrazoLarry.RenderModel();

		// vaso del juego 
		model = LarryBra;
		model = glm::translate(model, glm::vec3(-1.2f, 1.0f, 6.5));
		LarryBra = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		VasoGame.RenderModel();
		// Dado 1 
		model = LarryBra;
		//model = glm::translate(model, glm::vec3(-1.642f, 4.928f, 0.058));
		model = glm::translate(model, glm::vec3(0.0f - movDado, -0.2f + movDado, 0.0));
		model = glm::rotate(model, rotaraD * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, rotaraDz * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dado1.RenderModel();
		// Dado 2 
		model = LarryBra;
		model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0));
		model = glm::translate(model, glm::vec3(0.0f - movDado, 0.0f + movDado, 0.0));
		model = glm::rotate(model, rotaraD * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, rotaraDz * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dado2.RenderModel();

		// tortas 

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-78.0f, 2.2f, -55));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tar.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-82.0f, 2.2f, -55));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tar.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-85.0f, 2.2f, -55));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tar.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-75.0f, 2.2f, -55));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tar.RenderModel();
		// elotes 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-122.0f, 2.8f, -55));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Elotes.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-125.0f, 3.1f, -52));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Echile.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-118.0f, 3.1f, -52));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Echile.RenderModel();
		//tamales
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-141.0f, 4.0f, -29));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tamal.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-143.0f, 4.0f, -27));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tamal.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-144.0f, 4.0f, -23));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tamal.RenderModel();

		//Cartel

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(1.0f, -2.1f, -10.0));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cartel.RenderModel();


		// juego del pendulo 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 6.0f, -120.0));
		//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, rotaPendu * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pendulo.RenderModel();


		// juego de los patos


		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(95.0f, -0.5f, 3.0));
		patitos = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BasePatos.RenderModel();

		model = patitos;
		model = glm::translate(model, glm::vec3(0.0f, 6.502f + sin(glm::radians(angulovaria)), 0.0));
		model = glm::rotate(model, rotaPatos * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		patitos = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		aropatos.RenderModel();


		model = patitos;
		model = glm::translate(model, glm::vec3(1.613f, -0.133f, 2.827));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pato1.RenderModel();

		model = patitos;
		model = glm::translate(model, glm::vec3(3.184f, -0.133f, 0.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pato2.RenderModel();

		model = patitos;
		model = glm::translate(model, glm::vec3(1.608f, -0.133f, -2.771));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pato3.RenderModel();

		model = patitos;
		model = glm::translate(model, glm::vec3(-1.613f, -0.133f, -2.827));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pato4.RenderModel();

		model = patitos;
		model = glm::translate(model, glm::vec3(-3.184f, -0.133f, 0.0));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pato5.RenderModel();

		model = patitos;
		model = glm::translate(model, glm::vec3(-1.608f, -0.133f, 2.771));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pato6.RenderModel();

		if (Guant) {
			Guantos += 2 * deltaTime;
			if (Guantos >= 30) {
				Guantos = 30;
				Guant = false;
			}
		}
		else {
			Guantos -= 2 * deltaTime;
			if (Guantos <= 0.0) {
				Guantos = -30;
				Guant = true;
			}
		}
		// personajes de bob esponja 

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(80.0f, -1.0f + sin(glm::radians(angulovaria)), 120));
		Guantes = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Guante.RenderModel();


		model = Guantes;
		model = glm::translate(model, glm::vec3(0.874f, 2.862f, 0.022));
		model = glm::rotate(model, Guantos * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernaIZG.RenderModel();

		model = Guantes;
		model = glm::translate(model, glm::vec3(-0.874f, 2.862f, 0.022));
		model = glm::rotate(model, Guantos * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PiernaDG.RenderModel();




		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(70.0f, -2.3f, 120));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		perseve.RenderModel();


		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(60.0f, -2.3f, 120));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Sireno.RenderModel();
		float time78 = static_cast<float>(glfwGetTime());
		float anguloR = time78 * 4.0f; //5.0 es la velocidad
		float a_tam87 = 5.0f; // Tamaño de lemniscata
		float VUELAR = 1.0f + sin(anguloR) * sin(anguloR);
		float cord_R = (a_tam87 * cos(anguloR)) / VUELAR;
		float cord_H = (a_tam87 * sin(anguloR) * cos(anguloR)) / VUELAR;

		// medusa reina 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f + cord_R, 25.0f + cord_H, 70.0));
		model = glm::scale(model, glm::vec3(6.5f, 6.5f, 6.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MedusaR.RenderModel();



		// humo para el carrito de brochetas
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		model = carritoB;
		model = glm::translate(model, glm::vec3(1.7f, 1.0f, 0.5f)); // Mover las llamas hacia adelante de la cabeza    z  y x
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f)); // Escalar las llamas
		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		H.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		// Deshabilitar mezcla después del renderizado
		glDisable(GL_BLEND);
		// Deshabilitar la mezcla alfa
		glDisable(GL_BLEND);



		// El vuelo de bardock 
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		model = Bardock;
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.5f)); // Mover las llamas hacia adelante de la cabeza    z  y x
		model = glm::scale(model, glm::vec3(8.0f, 15.0f, 8.0f)); // Escalar las llamas
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ki.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		// Deshabilitar mezcla después del renderizado
		glDisable(GL_BLEND);
		// Deshabilitar la mezcla alfa
		glDisable(GL_BLEND);






		if (golpeTOPO == true)
		{
			model = glm::mat4(1.0);
			model = auxGtopo;
			model = glm::translate(model, glm::vec3(-1.3f, 7.0f, 0.0f));
			model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			color = glm::vec3(1.0f, 1.0f, 1.0f);
			glUniform3fv(uniformColor, 1, glm::value_ptr(color));
			golpTopTexture.UseTexture();
			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
			meshList[5]->RenderMesh();
		}
		if (ganadorTopo == true)
		{

			//para que no se desborde la variable


			model = glm::mat4(1.0);
			model = auxGtopo;
			model = glm::translate(model, glm::vec3(-1.3f, 8.0f, 0.0f));
			model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			//blending: transparencia o traslucidez
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			ganaTopTexture.UseTexture();
			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
			meshList[4]->RenderMesh();
		}






		if (tache1 == true)
		{
			model = glm::mat4(1.0);
			model = auxHacha;
			model = glm::translate(model, glm::vec3(1.5f, 5.197f, 0.5f));
			model = glm::rotate(model, 60 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
			//glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			//blending: transparencia o traslucidez
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			tache.UseTexture();
			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
			meshList[4]->RenderMesh();
		}
		if (tache2 == true)
		{
			model = glm::mat4(1.0);
			model = auxHacha;
			model = glm::translate(model, glm::vec3(-2.7f, 5.397f, 0.5f));
			model = glm::rotate(model, 60 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
			//glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			//blending: transparencia o traslucidez
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			tache.UseTexture();
			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
			meshList[4]->RenderMesh();
		}

		if (tache3 == true)
		{
			model = glm::mat4(1.0);
			model = auxHacha;
			model = glm::translate(model, glm::vec3(0.0f, 5.297f, 0.5f));
			model = glm::rotate(model, 60 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
			//glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			//blending: transparencia o traslucidez
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			tache.UseTexture();
			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
			meshList[4]->RenderMesh();
		}




		glDisable(GL_BLEND);


		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}




