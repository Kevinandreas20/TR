#include <windows.h>
#include <stdlib.h>
#include <glut.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void idle();
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
bool mouseDown = false;
int is_depth;
int x,y,z;
int i;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

float xpos = 0.0f;
float ypos = 0.0f;
float zpos = 0.0f;
GLuint _textureId;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 720);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("TUGAS RANCANG - GRAFIKA KOMPUTER(672018042)");
	init();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(tampil);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}


void init(void)
{

glClearColor(217/255.f,217/255.f,217/255.f,0.0);
//glClearColor(1.0, 1.0, 1.0, 0.0);
glEnable(GL_DEPTH_TEST);
//pencahayaan
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
//set cahaya
GLfloat qaAmbientLight[] = { 0.2,0.2,0.2,1.0 };
GLfloat qaDiffuseLight[] = { 1,1,1,1 };
GLfloat qaSpecularLight[] = { 1,1,1,1 };
glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
//posisi cahaya
GLfloat posisilampu[] = { 0,160,200,1 };
glLightfv(GL_LIGHT0, GL_POSITION, posisilampu);
glEnable(GL_COLOR_MATERIAL);
glShadeModel(GL_SMOOTH);
glMatrixMode(GL_MODELVIEW);
glOrtho(-1, 1, -1, 1, -1, 1);
glPointSize(2.0);
	
}
	

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);
	glRotatef(xrot + 20, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot - 20, 0.0f, 1.0f, 0.0f);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glColor3f(10.0f, 10.0f, 10.0f);

	glBegin(GL_QUADS);
	
	//alas1
	glColor3f(0,0,0);
	glVertex3f(-210,-130,60);
	glVertex3f(-210,-130,-210);
	glVertex3f(210,-130,-210);
	glVertex3f(210,-130,60);
	
	//alas1 depan
	glVertex3f(-210,-130,60);
	glVertex3f(-210,-120,60);
	glVertex3f(210,-120,60);
	glVertex3f(210,-130,60);

	//alas1 belakang
	glVertex3f(-210,-130,-210);
	glVertex3f(-210,-120,-210);
	glVertex3f(210,-120,-210);
	glVertex3f(210,-130,-210);

	//alas1 kanan
	glVertex3f(210,-130,60);
	glVertex3f(210,-120,60);
	glVertex3f(210,-120,-210);
	glVertex3f(210,-130,-210);

	//alas1 kiri
	glVertex3f(-210,-130,60);
	glVertex3f(-210,-120,60);
	glVertex3f(-210,-120,-210);
	glVertex3f(-210,-130,-210);
	
	//alas2
	glVertex3f(-210,-120,60);
	glVertex3f(-210,-120,-210);
	glVertex3f(210,-120,-210);
	glVertex3f(210,-120,60);
	
	//alas 2 depan
	glVertex3f(-210,-120,60);
	glVertex3f(-200,-110,50);
	glVertex3f(200,-110,50);
	glVertex3f(210,-120,60);
	//alas2 belakang
	glVertex3f(-210,-120,-210);
	glVertex3f(-200,-110,-200);
	glVertex3f(200,-110,-200);
	glVertex3f(210,-120,-210);
	//alas2 kanan
	glVertex3f(210,-120,60);
	glVertex3f(200,-110,50);
	glVertex3f(200,-110,-200);
	glVertex3f(210,-120,-210);
	//alas2 kiri
	glVertex3f(-210,-120,60);
	glVertex3f(-200,-110,50);
	glVertex3f(-200,-110,-200);
	glVertex3f(-210,-120,-210);

	//alas3
	glBegin(GL_QUADS);
	glColor3f(131/255.f, 131/255.f, 131/255.f);
	glVertex3f(-200,-110,50);
	glVertex3f(-200,-110,-200);
	glVertex3f(200,-110,-200);
	glVertex3f(200,-110,50);
	glEnd();
	
	//garis alas3
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(-180,-110,-200);
	glVertex3f(-180,-110,50);
	glVertex3f(-160,-110,-200);
	glVertex3f(-160,-110,50);
	glVertex3f(-140,-110,-200);
	glVertex3f(-140,-110,50);
	glVertex3f(-120,-110,-200);
	glVertex3f(-120,-110,50);
	glVertex3f(-100,-110,-200);
	glVertex3f(-100,-110,50);
	glVertex3f(-80,-110,-200);
	glVertex3f(-80,-110,50);
	glVertex3f(-60,-110,-200);
	glVertex3f(-60,-110,50);
	glVertex3f(-40,-110,-200);
	glVertex3f(-40,-110,50);
	glVertex3f(-20,-110,-200);
	glVertex3f(-20,-110,50);
	glVertex3f( 0,-110,-200);
	glVertex3f( 0,-110,50);
	glVertex3f( 20,-110,-200);
	glVertex3f( 20,-110,50);
	glVertex3f( 40,-110,-200);
	glVertex3f( 40,-110,50);
	glVertex3f( 60,-110,-200);
	glVertex3f( 60,-110,50);
	glVertex3f( 80,-110,-200);
	glVertex3f( 80,-110,50);
	glVertex3f( 100,-110,-200);
	glVertex3f( 100,-110,50);
	glVertex3f( 120,-110,-200);
	glVertex3f( 120,-110,50);
	glVertex3f( 140,-110,-200);
	glVertex3f( 140,-110,50);
	glVertex3f( 160,-110,-200);
	glVertex3f( 160,-110,50);
	glVertex3f( 180,-110,-200);
	glVertex3f( 180,-110,50);
	//mendatar
	glVertex3f(-200,-110,-180);
	glVertex3f( 200,-110,-180);
	glVertex3f(-200,-110,-160);
	glVertex3f( 200,-110,-160);
	glVertex3f(-200,-110,-140);
	glVertex3f( 200,-110,-140);
	glVertex3f(-200,-110,-120);
	glVertex3f( 200,-110,-120);
	glVertex3f(-200,-110,-100);
	glVertex3f( 200,-110,-100);
	glVertex3f(-200,-110,-80);
	glVertex3f( 200,-110,-80);
	glVertex3f(-200,-110,-60);
	glVertex3f( 200,-110,-60);
	glVertex3f(-200,-110,-40);
	glVertex3f( 200,-110,-40);
	glVertex3f(-200,-110,-20);
	glVertex3f( 200,-110,-20);
	glVertex3f(-200,-110, 0);
	glVertex3f( 200,-110, 0);
	glVertex3f(-200,-110, 20);
	glVertex3f( 200,-110, 20);
	glVertex3f(-200,-110, 40);
	glVertex3f( 200,-110, 40);
	
	glEnd();

	//gedung1 depan
	glBegin(GL_QUADS);
	glColor3f(39/255.f, 116/255.f, 87/255.f);
	glVertex3f(-50,-110,-5);
	glVertex3f(-50,-50,-5);
	glVertex3f(75,-50,-5);
	glVertex3f(75,-110,-5);
	glEnd();

	//pintu gedung1 depan
	glBegin(GL_POLYGON);
	glColor3f(111/255.f,111/255.f,0);
	glVertex3f(-24,-110,-4);
	glVertex3f(-24,-60,-4);
	glVertex3f( 41,-60,-4);
	glVertex3f( 41,-110,-4);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex3f(-24, -80, -3);
	glVertex3f(-24,-110,-3);
	glVertex3f(-20, -110, -3);
	glVertex3f(-20, -86, -3);
	glVertex3f(-24,-80,-3);
	glVertex3f(-20,-80,-3);
	glVertex3f(-20,-80,-3);
	glVertex3f(-20,-75,-3);
	glVertex3f(-20, -86, -3);
	glVertex3f(-16, -86, -3);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-16, -86, -3);
	glVertex3f(-16, -80, -3);
	glVertex3f(-20,-75,-3);
	glVertex3f(-10,-75,-3);
	glVertex3f(-16, -80, -3);
	glVertex3f(-10,-80,-3);
	glVertex3f(-10,-80,-3);
	glVertex3f( 8,-66,-3);
	glVertex3f(-10,-75,-3);
	glVertex3f( 8,-60,-3);
	//atas
	glVertex3f( 8,-60,-3);
	glVertex3f( 27,-75,-3);
	//bawah
	glVertex3f( 8,-66,-3);
	glVertex3f( 25,-80,-3);
	//atas
	glVertex3f( 27,-75,-3);
	glVertex3f( 37,-75,-3);
	//bawah
	glVertex3f( 25,-80,-3);
	glVertex3f( 32,-80,-3);
	//atas
	glVertex3f( 37,-75,-3);
	glVertex3f( 37,-80,-3);
	//atas
	glVertex3f( 37,-80,-3);
	glVertex3f( 41,-80,-3);
	//atas
	glVertex3f( 41,-80,-3);
	glVertex3f( 41,-110,-3);
	//bwah
	glVertex3f( 32,-80,-3);
	glVertex3f( 32,-86,-3);
	//bwah
	glVertex3f( 32,-86,-3);
	glVertex3f( 37,-86,-3);
	//bawah
	glVertex3f( 37,-86,-3);
	glVertex3f( 37,-110,-3);
	glEnd();

	//gedung1 atas
	glBegin(GL_QUADS);
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-65,-50,-20);
	glVertex3f(-65,-50,-80);
	glVertex3f(90,-50,-80);
	glVertex3f(90,-50,-20);

	glVertex3f(-50,-50,-5);
	glVertex3f(-65,-50,-20);
	glVertex3f(90,-50,-20);
	glVertex3f(75,-50,-5);
	

	//gedung1 blakang
	glVertex3f(-65,-50,-80);
	glVertex3f(-65,-110,-80);
	glVertex3f(90,-110,-80);
	glVertex3f(90,-50,-80);
	
	//gedung1 kiri
	glVertex3f(-50,-50,-5);
	glVertex3f(-50,-110,-5);
	glVertex3f(-65,-110,-25);
	glVertex3f(-65,-50,-25);

	glVertex3f(-65,-50,-25);
	glVertex3f(-65,-110,-25);
	glVertex3f(-65,-110,-80);
	glVertex3f(-65,-50,-80);
	
	//gedung1 kanan
	glVertex3f(75,-50,-5);
	glVertex3f(75,-110,-5);
	glVertex3f(90,-110,-25);
	glVertex3f(90,-50,-25);

	glVertex3f(90,-50,-25);
	glVertex3f(90,-110,-25);
	glVertex3f(90,-110,-80);
	glVertex3f(90,-50,-80);
	
	//interior gedung1
	//tembok dasar lift
	glColor3f(0,0,0);
	glVertex3f(-65,-50,-79);
	glVertex3f(90,-50,-79);
	glVertex3f(90,-110,-79);
	glVertex3f(-65,-110,-79);
	
	//tembok2 lift sisi kiri
	glColor3f(100/255.f,100/255.f,100/255.f);
	glVertex3f(-65,-50,-69);
	glVertex3f(-9,-50,-69);
	glVertex3f(-9,-110,-69);
	glVertex3f(-65,-110,-69);
	
	//penutup tembok2 lift sisi kiri
	glVertex3f(-9,-70,-69);
	glVertex3f(-9,-70,-79);
	glVertex3f(-9,-110,-79);
	glVertex3f(-9,-110,-69);

	//tembok2 lift sisi kanan
	glVertex3f( 26,-50,-69);
	glVertex3f( 90,-50,-69);
	glVertex3f( 90,-110,-69);
	glVertex3f( 26,-110,-69);

	//penutup tembok2 lift sisi kanan
	glVertex3f(26,-70,-69);
	glVertex3f(26,-70,-79);
	glVertex3f(26,-110,-79);
	glVertex3f(26,-110,-69);


	//tembok2 lift sisi atas
	glVertex3f( -9,-50,-69);
	glVertex3f( 26,-50,-69);
	glVertex3f( 26,-70,-69);
	glVertex3f( -9,-70,-69);

	//penutup tembok2 lift sisi atas
	glVertex3f(-9,-70,-69);
	glVertex3f(-9,-70,-79);
	glVertex3f(26,-70,-79);
	glVertex3f(26,-70,-69);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(100/255.f,100/255.f,100/255.f);
	glVertex3f(8,-70,-79);
	glVertex3f(8,-110,-79);
	glEnd();

	//gedung2 depan
	glBegin(GL_QUADS);
	glColor3f(39/255.f, 116/255.f, 87/255.f);
	glVertex3f(-130,-110,-5);
	glVertex3f(-130,101,-5);
	glVertex3f(-95, 101,-5);
	glVertex3f(-95,-110,-5);
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-95,-110,-5);
	glVertex3f(-95, 101,-5);
	glVertex3f(-75, 101,-25);
	glVertex3f(-75,-110,-25);

	//gedung2 kiri
	glVertex3f(-130,-110,-5);
	glVertex3f(-130, 101,-5);
	glVertex3f(-145, 101,-25);
	glVertex3f(-145,-110,-25);
	
	glVertex3f(-145,-110,-25);
	glVertex3f(-145, 101,-25);
	glVertex3f(-145, 101,-80);
	glVertex3f(-145,-110,-80);

	//kursi sendehan belakang 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-143, -98, -40);
	glVertex3f(-143, -105, -40);
	glVertex3f(-143, -105, -70);
	glVertex3f(-143, -98, -70);
	//kursi sendehan depan
	glVertex3f(-141, -98, -40);
	glVertex3f(-141, -105, -40);
	glVertex3f(-141, -105, -70);
	glVertex3f(-141, -98, -70);
	//kursi sendehan kanan
	glVertex3f(-143, -98, -70);
	glVertex3f(-143, -105, -70);
	glVertex3f(-141, -105, -70);
	glVertex3f(-141, -98, -70);
	//kursi sendehan kiri
	glVertex3f(-143, -98, -40);
	glVertex3f(-143, -105, -40);
	glVertex3f(-141, -105, -40);
	glVertex3f(-141, -98, -40);
	//kursi sendehan atas
	glVertex3f(-143, -98, -40);
	glVertex3f(-143, -98, -70);
	glVertex3f(-141, -98, -70);
	glVertex3f(-141, -98, -40);
	//kursi sendehan bawah
	glVertex3f(-143, -105, -40);
	glVertex3f(-143, -105, -70);
	glVertex3f(-141, -105, -70);
	glVertex3f(-141, -105, -40);
	
	//kursi alas bawah
	glVertex3f(-141, -105, -40);
	glVertex3f(-136, -105, -40);
	glVertex3f(-136, -105, -70);
	glVertex3f(-141, -105, -70);
	
	//kursi alas atas
	glVertex3f(-141, -103, -40);
	glVertex3f(-136, -103, -40);
	glVertex3f(-136, -103, -70);
	glVertex3f(-141, -103, -70);
	
	//kursi alas depan
	glVertex3f(-136, -103, -40);
	glVertex3f(-136, -105, -40);
	glVertex3f(-136, -105, -70);
	glVertex3f(-136, -103, -70);
	
	//kursi alas kiri
	glVertex3f(-141, -103, -40);
	glVertex3f(-141, -105, -40);
	glVertex3f(-136, -105, -40);
	glVertex3f(-136, -103, -40);
	
	//kursi alas kanan
	glVertex3f(-141, -103, -70);
	glVertex3f(-141, -105, -70);
	glVertex3f(-136, -105, -70);
	glVertex3f(-136, -103, -70);

	//kaki kursi kiri#1 
	glVertex3f(-143, -105, -41);
	glVertex3f(-143, -110, -41);
	glVertex3f(-142, -110, -41);
	glVertex3f(-142, -105, -41);

	//kaki kursi kanan#1 
	glVertex3f(-143, -105, -42);
	glVertex3f(-143, -110, -42);
	glVertex3f(-142, -110, -42);
	glVertex3f(-142, -105, -42);

	//kaki kursi depan#1 
	glVertex3f(-142, -105, -41);
	glVertex3f(-142, -110, -41);
	glVertex3f(-142, -110, -42);
	glVertex3f(-142, -105, -42);

	//kaki kursi belakang#1 
	glVertex3f(-143, -105, -41);
	glVertex3f(-143, -110, -41);
	glVertex3f(-143, -110, -42);
	glVertex3f(-143, -105, -42);

	//kaki kursi kiri#2 
	glVertex3f(-143, -105, -68);
	glVertex3f(-143, -110, -68);
	glVertex3f(-142, -110, -68);
	glVertex3f(-142, -105, -68);

	//kaki kursi kanan#2 
	glVertex3f(-143, -105, -69);
	glVertex3f(-143, -110, -69);
	glVertex3f(-142, -110, -69);
	glVertex3f(-142, -105, -69);

	//kaki kursi depan#2 
	glVertex3f(-142, -105, -68);
	glVertex3f(-142, -110, -68);
	glVertex3f(-142, -110, -69);
	glVertex3f(-142, -105, -69);

	//kaki kursi belakang#2 
	glVertex3f(-143, -105, -68);
	glVertex3f(-143, -110, -68);
	glVertex3f(-143, -110, -69);
	glVertex3f(-143, -105, -69);

	//kaki kursi kiri#3 
	glVertex3f(-137, -105, -68);
	glVertex3f(-137, -110, -68);
	glVertex3f(-136, -110, -68);
	glVertex3f(-136, -105, -68);

	//kaki kursi depan#3 
	glVertex3f(-136, -105, -68);
	glVertex3f(-136, -110, -68);
	glVertex3f(-136, -110, -69);
	glVertex3f(-136, -105, -69);

	//kaki kursi belakang#3 
	glVertex3f(-137, -105, -68);
	glVertex3f(-137, -110, -68);
	glVertex3f(-137, -110, -69);
	glVertex3f(-137, -105, -69);

	//kaki kursi kanan#3 
	glVertex3f(-137, -105, -69);
	glVertex3f(-137, -110, -69);
	glVertex3f(-136, -110, -69);
	glVertex3f(-136, -105, -69);

	//kaki kursi kiri#4 
	glVertex3f(-137, -105, -41);
	glVertex3f(-137, -110, -41);
	glVertex3f(-136, -110, -41);
	glVertex3f(-136, -105, -41);

	//kaki kursi kanan#4 
	glVertex3f(-137, -105, -42);
	glVertex3f(-137, -110, -42);
	glVertex3f(-136, -110, -42);
	glVertex3f(-136, -105, -42);

	//kaki kursi belakang#4 
	glVertex3f(-137, -105, -41);
	glVertex3f(-137, -110, -41);
	glVertex3f(-137, -110, -42);
	glVertex3f(-137, -105, -42);

	//kaki kursi depan#4 
	glVertex3f(-136, -105, -41);
	glVertex3f(-136, -110, -41);
	glVertex3f(-136, -110, -42);
	glVertex3f(-136, -105, -42);


	//gedung2 kanan
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-75, 101,-80);
	glVertex3f(-75,-110,-80);
	glVertex3f(-75,-110,-25);
	glVertex3f(-75, 101,-25);

	glColor3f(100/255.f,100/255.f,100/255.f);
	glVertex3f(-76, 101,-80);
	glVertex3f(-76,-110,-80);
	glVertex3f(-76,-110,-25);
	glVertex3f(-76, 101,-25);

	//gedung2 belakang
	glVertex3f(-145,-110,-80);
	glVertex3f(-145, 101,-80);
	glVertex3f(-75, 101,-80);
	glVertex3f(-75,-110,-80);
	//tembok gedung2 belakang
	glColor3f(100/255.f,100/255.f,100/255.f);
	glVertex3f(-145,-110,-79);
	glVertex3f(-145, 101,-79);
	glVertex3f(-75, 101,-79);
	glVertex3f(-75,-110,-79);
	
	//meja gedung2 kiri
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-125,-95,-79);
	glVertex3f(-125,-110,-79);
	glVertex3f(-125,-110,-70);
	glVertex3f(-125,-95,-70);

	//meja gedung2 kanan
	glVertex3f(-100,-95,-79);
	glVertex3f(-100,-110,-79);
	glVertex3f(-100,-110,-70);
	glVertex3f(-100,-95,-70);

	//meja gedung2 samping kiri
	glVertex3f(-125,-95,-70);
	glVertex3f(-125,-110,-70);
	glVertex3f(-120,-110,-65);
	glVertex3f(-120,-95,-65);

	//meja gedung2 samping kanan
	glVertex3f(-100,-95,-70);
	glVertex3f(-100,-110,-70);
	glVertex3f(-105,-110,-65);
	glVertex3f(-105,-95,-65);

	//meja gedung2 depan
	glVertex3f(-120,-95,-65);
	glVertex3f(-120,-110,-65);
	glVertex3f(-105,-110,-65);
	glVertex3f(-105,-95,-65);



	//gedung2 atap1 bawah
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-150,101,-85);
	glVertex3f(-70 ,101,-85);
	glVertex3f(-70, 101, 0);
	glVertex3f(-150,101, 0);
	
	//gedung2 atap1 atas
	glVertex3f(-150,107,-85);
	glVertex3f(-70 ,107,-85);
	glVertex3f(-70, 107, 0);
	glVertex3f(-150,107, 0);

	//gedung2 atap1 depan
	glVertex3f(-150,107, 0);
	glVertex3f(-150 ,101, 0);
	glVertex3f(-70, 101, 0);
	glVertex3f(-70,107, 0);
	
	//gedung2 atap1 belakang
	glVertex3f(-150,107, -85);
	glVertex3f(-150 ,101,-85);
	glVertex3f(-70, 101,-85);
	glVertex3f(-70,107,-85);

	//gedung2 atap1 kiri
	glVertex3f(-150,107,-85);
	glVertex3f(-150,101,-85);
	glVertex3f(-150,101, 0);
	glVertex3f(-150,107, 0);
	
	//gedung2 atap1 kanan
	glVertex3f(-70,107,-85);
	glVertex3f(-70,101,-85);
	glVertex3f(-70,101, 0);
	glVertex3f(-70,107, 0);

	//gedung 2 atap2 bawah
	glVertex3f(-150,111,-85);
	glVertex3f(-70 ,111,-85);
	glVertex3f(-70, 111, 0);
	glVertex3f(-150,111, 0);

	//gedung 2 atap2 atas
	glColor3f(0,0,0);
	glVertex3f(-155,115,-90);
	glVertex3f(-65 ,115,-90);
	glVertex3f(-65, 115, 5);
	glVertex3f(-155,115, 5);
	
	//gedung2 atap2 belakang
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-155,115,-90);
	glVertex3f(-150,111,-85);
	glVertex3f(-70,111,-85);
	glVertex3f(-65,115,-90);

	//gedung2 atap2 depan
	glVertex3f(-155,115,5);
	glVertex3f(-150,111, 0);
	glVertex3f(-70,111,0);
	glVertex3f(-65,115,5);

	//gedung2 atap2 kiri
	glVertex3f(-155,115,-90);
	glVertex3f(-150,111,-85);
	glVertex3f(-150,111,0);
	glVertex3f(-155,115,5);
	
	//gedung2 atap2 kanan
	glVertex3f(-65,115,-90);
	glVertex3f(-70,111,-85);
	glVertex3f(-70,111,0);
	glVertex3f(-65,115,5);
	
	//gedung3 depan
	glColor3f(39/255.f, 116/255.f, 87/255.f);
	glVertex3f(110,-110,-5);
	glVertex3f(110, 101,-5);
	glVertex3f(150, 101,-5);
	glVertex3f(150,-110,-5);
		
	//gedung3 belakang
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(100,-110,-80);
	glVertex3f(100, 101,-80);
	glVertex3f(165, 101,-80);
	glVertex3f(165,-110,-80);

	//tembok gedung3 belakang
	glColor3f(100/255.f, 100/255.f,100/255.f);
	glVertex3f(100,-110,-79);
	glVertex3f(100, 101,-79);
	glVertex3f(165, 101,-79);
	glVertex3f(165,-110,-79);
	
	//meja gedung3 kiri 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 120,-95,-79);
	glVertex3f( 120,-110,-79);
	glVertex3f( 120,-110,-70);
	glVertex3f( 120,-95,-70);

	//meja gedung3 kanan
	glVertex3f( 145,-95,-79);
	glVertex3f( 145,-110,-79);
	glVertex3f( 145,-110,-70);
	glVertex3f( 145,-95,-70);

	//kursi sendehan belakang 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 102, -98, -40);
	glVertex3f( 102, -105, -40);
	glVertex3f( 102, -105, -70);
	glVertex3f( 102, -98, -70);
	//kursi sendehan depan
	glVertex3f( 104, -98, -40);
	glVertex3f( 104, -105, -40);
	glVertex3f( 104, -105, -70);
	glVertex3f( 104, -98, -70);
	//kursi sendehan kanan
	glVertex3f( 102, -98, -70);
	glVertex3f( 102, -105, -70);
	glVertex3f( 104, -105, -70);
	glVertex3f( 104, -98, -70);
	//kursi sendehan kiri
	glVertex3f( 102, -98, -40);
	glVertex3f( 102, -105, -40);
	glVertex3f( 104, -105, -40);
	glVertex3f( 104, -98, -40);
	//kursi sendehan atas
	glVertex3f( 102, -98, -40);
	glVertex3f( 102, -98, -70);
	glVertex3f( 104, -98, -70);
	glVertex3f( 104, -98, -40);
	//kursi sendehan bawah
	glVertex3f( 102, -105, -40);
	glVertex3f( 102, -105, -70);
	glVertex3f( 104, -105, -70);
	glVertex3f( 104, -105, -40);

	//kursi alas bawah
	glVertex3f( 104, -105, -40);
	glVertex3f( 109, -105, -40);
	glVertex3f( 109, -105, -70);
	glVertex3f( 104, -105, -70);
	
	//kursi alas atas
	glVertex3f( 104, -103, -40);
	glVertex3f( 109, -103, -40);
	glVertex3f( 109, -103, -70);
	glVertex3f( 104, -103, -70);
	
	//kursi alas depan
	glVertex3f( 109, -103, -40);
	glVertex3f( 109, -105, -40);
	glVertex3f( 109, -105, -70);
	glVertex3f( 109, -103, -70);
	
	//kursi alas kiri
	glVertex3f( 104, -103, -40);
	glVertex3f( 104, -105, -40);
	glVertex3f( 109, -105, -40);
	glVertex3f( 109, -103, -40);
	
	//kursi alas kanan
	glVertex3f( 104, -103, -70);
	glVertex3f( 104, -105, -70);
	glVertex3f( 109, -105, -70);
	glVertex3f( 109, -103, -70);

	//kaki kursi kiri#1 
	glVertex3f( 102, -105, -41);
	glVertex3f( 102, -110, -41);
	glVertex3f( 103, -110, -41);
	glVertex3f( 103, -105, -41);

	//kaki kursi kanan#1 
	glVertex3f( 102, -105, -42);
	glVertex3f( 102, -110, -42);
	glVertex3f( 103, -110, -42);
	glVertex3f( 103, -105, -42);

	//kaki kursi depan#1 
	glVertex3f( 103, -105, -41);
	glVertex3f( 103, -110, -41);
	glVertex3f( 103, -110, -42);
	glVertex3f( 103, -105, -42);

	//kaki kursi belakang#1 
	glVertex3f( 102, -105, -41);
	glVertex3f( 102, -110, -41);
	glVertex3f( 102, -110, -42);
	glVertex3f( 102, -105, -42);

	//kaki kursi kiri#2 
	glVertex3f( 102, -105, -68);
	glVertex3f( 102, -110, -68);
	glVertex3f( 103, -110, -68);
	glVertex3f( 103, -105, -68);

	//kaki kursi kanan#2 
	glVertex3f( 102, -105, -69);
	glVertex3f( 102, -110, -69);
	glVertex3f( 103, -110, -69);
	glVertex3f( 103, -105, -69);

	//kaki kursi depan#2 
	glVertex3f( 103, -105, -68);
	glVertex3f( 103, -110, -68);
	glVertex3f( 103, -110, -69);
	glVertex3f( 103, -105, -69);

	//kaki kursi belakang#2 
	glVertex3f( 102, -105, -68);
	glVertex3f( 102, -110, -68);
	glVertex3f( 102, -110, -69);
	glVertex3f( 102, -105, -69);

	//kaki kursi kiri#3 
	glVertex3f( 108, -105, -68);
	glVertex3f( 108, -110, -68);
	glVertex3f( 109, -110, -68);
	glVertex3f( 109, -105, -68);

	//kaki kursi depan#3 
	glVertex3f( 109, -105, -68);
	glVertex3f( 109, -110, -68);
	glVertex3f( 109, -110, -69);
	glVertex3f( 109, -105, -69);

	//kaki kursi belakang#3 
	glVertex3f( 108, -105, -68);
	glVertex3f( 108, -110, -68);
	glVertex3f( 108, -110, -69);
	glVertex3f( 108, -105, -69);

	//kaki kursi kanan#3 
	glVertex3f( 108, -105, -69);
	glVertex3f( 108, -110, -69);
	glVertex3f( 109, -110, -69);
	glVertex3f( 109, -105, -69);

	//kaki kursi kiri#4 
	glVertex3f( 108, -105, -41);
	glVertex3f( 108, -110, -41);
	glVertex3f (109, -110, -41);
	glVertex3f( 109, -105, -41);

	//kaki kursi kanan#4 
	glVertex3f( 108, -105, -42);
	glVertex3f( 108, -110, -42);
	glVertex3f( 109, -110, -42);
	glVertex3f( 109, -105, -42);

	//kaki kursi belakang#4 
	glVertex3f( 108, -105, -41);
	glVertex3f( 108, -110, -41);
	glVertex3f( 108, -110, -42);
	glVertex3f( 108, -105, -42);

	//kaki kursi depan#4 
	glVertex3f( 109, -105, -41);
	glVertex3f( 109, -110, -41);
	glVertex3f( 109, -110, -42);
	glVertex3f( 109, -105, -42);



	//meja gedung3 samping kiri
	glVertex3f( 120,-95,-70);
	glVertex3f( 120,-110,-70);
	glVertex3f( 125,-110,-65);
	glVertex3f( 125,-95,-65);

	//meja gedung3 samping kanan
	glVertex3f( 145,-95,-70);
	glVertex3f( 145,-110,-70);
	glVertex3f( 140,-110,-65);
	glVertex3f( 140,-95,-65);

	//meja gedung3 depan
	glVertex3f( 125,-95,-65);
	glVertex3f( 125,-110,-65);
	glVertex3f( 140,-110,-65);
	glVertex3f( 140,-95,-65);

	//gedung3 kiri 
	glColor3f(111/255.f,111/255.f,0);
	glVertex3f(	110,-110,-5);
	glVertex3f(	110,101,-5);
	glVertex3f(	100, 101,-25);
	glVertex3f(	100,-110,-25);

	glVertex3f( 100,101,-25);
	glVertex3f( 100,-110,-25);
	glVertex3f( 100,-110,-80);
	glVertex3f( 100, 101,-80); 

	//gedung3 kanan
	glVertex3f(150,-110,-5);
	glVertex3f(150,101,-5);
	glVertex3f(165, 101,-25);
	glVertex3f(165,-110,-25);
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(165,-110,-25);
	glVertex3f(165, 101,-25);
	glVertex3f(165, 101,-80);
	glVertex3f(165,-110,-80);

	//gedung3 atap1 bawah
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f( 95, 101, 0);
	glVertex3f( 170,101, 0);
	glVertex3f( 170,101,-85);
	glVertex3f( 95, 101,-85);
	
	//gedung3 atap1 atas
	glVertex3f( 95, 107, 0);
	glVertex3f( 170,107, 0);
	glVertex3f( 170,107,-85);
	glVertex3f( 95, 107,-85);
	
	//gedung3 atap1 depan
	glVertex3f( 95, 107, 0);
	glVertex3f( 95, 101, 0);
	glVertex3f( 170,101, 0);
	glVertex3f( 170,107, 0);
	
	//gedung3 atap1 belakang
	glVertex3f( 95, 107, -85);
	glVertex3f( 95, 101, -85);
	glVertex3f( 170,101, -85);
	glVertex3f( 170,107, -85);
	
	//gedung3 atap1 kanan
	glVertex3f( 170, 107, 0);
	glVertex3f( 170, 101, 0);
	glVertex3f( 170, 101,-85);
	glVertex3f( 170, 107,-85);
	
	//gedung3 atap1 kiri
	glVertex3f( 95, 107, 0);
	glVertex3f( 95, 101, 0);
	glVertex3f( 95, 101,-85);
	glVertex3f( 95, 107,-85);
	
	//gedung3 atap2 bawah
	glVertex3f( 95,111,-85);
	glVertex3f( 170 ,111,-85);
	glVertex3f( 170, 111, 0);
	glVertex3f( 95,111, 0);

	//gedung3 atap2 atas
	glColor3f(0,0,0);
	glVertex3f( 90,115,-90);
	glVertex3f( 175 ,115,-90);
	glVertex3f( 175, 115, 5);
	glVertex3f( 90,115, 5);

	//gedung3 atap2 depan
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f( 90,115,5);
	glVertex3f( 95 ,111,0);
	glVertex3f( 170, 111, 0);
	glVertex3f( 175,115,5);

	//gedung3 atap2 belakang
	glVertex3f( 90,115,-90);
	glVertex3f( 95 ,111,-85);
	glVertex3f( 170, 111,-85);
	glVertex3f( 175,115,-90);

	//gedung3 atap2 kiri
	glVertex3f( 90,115,-90);
	glVertex3f( 95 ,111,-85);
	glVertex3f( 95, 111, 0);
	glVertex3f( 90,115,5);

	//gedung3 atap2 kanan
	glVertex3f( 175,115,-90);
	glVertex3f( 170 ,111,-85);
	glVertex3f( 170, 111, 0);
	glVertex3f( 175,115,5);

	//gedung4 depan
	glColor3f(39/255.f, 116/255.f, 87/255.f);
	glVertex3f(-49,-50,-10);
	glVertex3f(-24,-50,-10);
	glVertex3f(-24, 115,-10);
	glVertex3f(-49, 115,-10);
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-49,-50,-10);
	glVertex3f(-62,-50,-27);
	glVertex3f(-62, 115,-27);
	glVertex3f(-49, 115,-10);
	
	//gedung4 kiri
	glVertex3f(-62, 115,-27);
	glVertex3f(-62,-50,-27);
	glVertex3f(-62,-50,-75);
	glVertex3f(-62, 115,-75);
	
	//gedung4 belakang
	glVertex3f(-62, 115,-75);
	glVertex3f(-62,-50,-75);
	glVertex3f(-24,-50,-75);
	glVertex3f(-24, 115,-75);

	//gedung4 kanan
	glVertex3f(-24, 115,-75);
	glVertex3f(-24,-50,-75);
	glVertex3f(-24,-50,-10);
	glVertex3f(-24, 115,-10);

	//gedung4 atap1 bawah
	glColor3f(0,0,0);
	glVertex3f(-51, 115,-7);
	glVertex3f(-21, 115,-7);
	glVertex3f(-21, 115,-78);
	glVertex3f(-51, 115,-78);

	glVertex3f(-51, 115,-78);
	glVertex3f(-65, 115,-78);
	glVertex3f(-65, 115,-26);
	glVertex3f(-51, 115,-7);

	//gedung4 atap1 atas
	glVertex3f(-51, 119,-7);
	glVertex3f(-21, 119,-7);
	glVertex3f(-21, 119,-78);
	glVertex3f(-51, 119,-78);

	glVertex3f(-51, 119,-78);
	glVertex3f(-65, 119,-78);
	glVertex3f(-65, 119,-26);
	glVertex3f(-51, 119,-7);

	//gedung4 atap1 depan
	glVertex3f(-51, 119,-7);
	glVertex3f(-51, 115,-7);
	glVertex3f(-21, 115,-7);
	glVertex3f(-21, 119,-7);

	//gedung4 atap1 belakang
	glVertex3f(-65, 119,-78);
	glVertex3f(-65, 115,-78);
	glVertex3f(-21, 115,-78);
	glVertex3f(-21, 119,-78);
	
	//gedung4 atap1 kanan
	glVertex3f(-21, 119,-7);
	glVertex3f(-21, 115,-7);
	glVertex3f(-21, 115,-78);
	glVertex3f(-21, 119,-78);

	//gedung4 atap1 kiri
	glVertex3f(-65, 119,-78);
	glVertex3f(-65, 115,-78);
	glVertex3f(-65, 115,-26);
	glVertex3f(-65, 119,-26);

	glVertex3f(-65, 119,-26);
	glVertex3f(-65, 115,-26);
	glVertex3f(-51, 115,-7);
	glVertex3f(-51, 119,-7);

	
	//gedung4 atap2 bawah
	glVertex3f(-51, 127,-7);
	glVertex3f(-21, 127,-7);
	glVertex3f(-21, 127,-78);
	glVertex3f(-51, 127,-78);

	glVertex3f(-51, 127,-78);
	glVertex3f(-65, 127,-78);
	glVertex3f(-65, 127,-26);
	glVertex3f(-51, 127,-7);

	//gedung4 atap2 depan
	glColor3f(0,0,0);
	glVertex3f(-51, 132,-7);
	glVertex3f(-51, 127,-7);
	glVertex3f(-21, 127,-7);
	glVertex3f(-21, 132,-7);

	//gedung4 atap2 belakang
	glVertex3f(-65, 132,-78);
	glVertex3f(-65, 127,-78);
	glVertex3f(-21, 127,-78);
	glVertex3f(-21, 132,-78);

	//gedung4 atap2 kanan
	glVertex3f(-21, 132,-7);
	glVertex3f(-21, 127,-7);
	glVertex3f(-21, 127,-78);
	glVertex3f(-21, 132,-78);

	//gedung4 atap2 kiri
	glVertex3f(-65, 132,-78);
	glVertex3f(-65, 127,-78);
	glVertex3f(-65, 127,-26);
	glVertex3f(-65, 132,-26);

	//gedung4 atap2 kiri depan
	glVertex3f(-65, 132,-26);
	glVertex3f(-65, 127,-26);
	glVertex3f(-51, 127,-7);
	glVertex3f(-51, 132,-7);


	//gedung4 tiang1 depan
	glColor3f(0,0,0);
	glVertex3f(-50,	127,-10);
	glVertex3f(-50,	119,-10);
	glVertex3f(-48, 119,-10);
	glVertex3f(-48, 127,-10);
	
	//gedung4 tiang1 belakang
	glVertex3f(-50,	127,-12);
	glVertex3f(-50,	119,-12);
	glVertex3f(-48, 119,-12);
	glVertex3f(-48, 127,-12);
	
	//gedung4 tiang1 kiri
	glVertex3f(-50, 127,-10);
	glVertex3f(-50, 119,-10);
	glVertex3f(-50, 119,-12);
	glVertex3f(-50, 127,-12);
	
	//gedung4 tiang1 kanan
	glVertex3f(-48, 127,-10);
	glVertex3f(-48, 119,-10);
	glVertex3f(-48, 119,-12);
	glVertex3f(-48, 127,-12);
	
	//gedung4 tiang2 depan
	glVertex3f(-24,	127,-10);
	glVertex3f(-24,	119,-10);
	glVertex3f(-26, 119,-10);
	glVertex3f(-26, 127,-10);
	
	//gedung4 tiang2 belakang
	glVertex3f(-24,	127,-12);
	glVertex3f(-24,	119,-12);
	glVertex3f(-26, 119,-12);
	glVertex3f(-26, 127,-12);

	//gedung4 tiang2 kiri
	glVertex3f(-24, 127,-10);
	glVertex3f(-24, 119,-10);
	glVertex3f(-24, 119,-12);
	glVertex3f(-24, 127,-12);
	
	//gedung4 tiang2 kanan
	glVertex3f(-26, 127,-10);
	glVertex3f(-26, 119,-10);
	glVertex3f(-26, 119,-12);
	glVertex3f(-26, 127,-12);
	
	//gedung4 tiang3 depan
	glVertex3f(-24, 127,-73);
	glVertex3f(-24, 119,-73);
	glVertex3f(-26, 119,-73);
	glVertex3f(-26, 127,-73);
	
	//gedung4 tiang3 belakang
	glVertex3f(-24, 127,-75);
	glVertex3f(-24, 119,-75);
	glVertex3f(-26, 119,-75);
	glVertex3f(-26, 127,-75);
	
	//gedung4 tiang3 kiri
	glVertex3f(-24, 127,-73);
	glVertex3f(-24, 119,-73);
	glVertex3f(-24, 119,-75);
	glVertex3f(-24, 127,-75);

	//gedung4 tiang3 kanan
	glVertex3f(-26, 127,-73);
	glVertex3f(-26, 119,-73);
	glVertex3f(-26, 119,-75);
	glVertex3f(-26, 127,-75);

	//gedung4 tiang4 depan
	
	glVertex3f(-63,	127,-73);
	glVertex3f(-63,	119,-73);
	glVertex3f(-61, 119,-73);
	glVertex3f(-61, 127,-73);
	
	//gedung4 tiang4 belakang
	glVertex3f(-63,	127,-75);
	glVertex3f(-63,	119,-75);
	glVertex3f(-61, 119,-75);
	glVertex3f(-61, 127,-75);
	
	//gedung4 tiang4 kiri
	glVertex3f(-63,	127,-73);
	glVertex3f(-63,	119,-73);
	glVertex3f(-63, 119,-75);
	glVertex3f(-63, 127,-75);
	
	//gedung4 tiang4 kanan
	glVertex3f(-61,	127,-73);
	glVertex3f(-61,	119,-73);
	glVertex3f(-61, 119,-75);
	glVertex3f(-61, 127,-75);
	
	//gedung4 tiang5 depan
	
	glVertex3f(-63,	127,-27);
	glVertex3f(-63,	119,-27);
	glVertex3f(-61, 119,-27);
	glVertex3f(-61, 127,-27);
	
	//gedung4 tiang5 belakang
	glVertex3f(-63,	127,-27);
	glVertex3f(-63,	119,-27);
	glVertex3f(-61, 119,-27);
	glVertex3f(-61, 127,-27);
	
	//gedung4 tiang5 kiri
	glVertex3f(-63,	127,-29);
	glVertex3f(-63,	119,-29);
	glVertex3f(-63, 119,-29);
	glVertex3f(-63, 127,-29);
	
	//gedung4 tiang5 kanan
	glVertex3f(-61,	127,-27);
	glVertex3f(-61,	119,-27);
	glVertex3f(-61, 119,-29);
	glVertex3f(-61, 127,-29);

	//gedung5 depan
	glColor3f(39/255.f, 116/255.f, 87/255.f);
	glVertex3f( 49,-50,-10);
	glVertex3f( 74,-50,-10);
	glVertex3f( 74, 115,-10);
	glVertex3f( 49, 115,-10);
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f( 74,-50,-10);
	glVertex3f( 87,-50,-27);
	glVertex3f( 87, 115,-27);
	glVertex3f( 74, 115,-10);

	//gedung5 belakang
	glVertex3f( 87, 115,-75);
	glVertex3f( 87, -50,-75);
	glVertex3f( 49, -50,-75);
	glVertex3f( 49, 115,-75);

	//gedung5 kanan
	glVertex3f( 87, 115,-27);
	glVertex3f( 87,-50,-27);
	glVertex3f( 87,-50,-75);
	glVertex3f( 87, 115,-75);
	
	//gedung5 kiri
	glVertex3f( 49, 115,-75);
	glVertex3f( 49,-50,-75);
	glVertex3f( 49,-50,-10);
	glVertex3f( 49, 115,-10);

	//gedung5 atap1 bawah
	glColor3f(0,0,0);
	glVertex3f( 46, 115,-7);
	glVertex3f( 46, 115,-78);
	glVertex3f( 74, 115,-78);
	glVertex3f( 74, 115,-7);

	glVertex3f( 74, 115,-7);
	glVertex3f( 90, 115,-26);
	glVertex3f( 90, 115,-78);
	glVertex3f( 74, 115,-78);
	
	//gedung5 atap1 atas
	glColor3f(0,0,0);
	glVertex3f( 46, 119,-7);
	glVertex3f( 46, 119,-78);
	glVertex3f( 74, 119,-78);
	glVertex3f( 74, 119,-7);

	glVertex3f( 74, 119,-7);
	glVertex3f( 90, 119,-26);
	glVertex3f( 90, 119,-78);
	glVertex3f( 74, 119,-78);

	//gedung5 atap1 depan
	glVertex3f( 46, 119,-7);
	glVertex3f( 46, 115,-7);
	glVertex3f( 74, 115,-7);
	glVertex3f( 74, 119,-7);

	glVertex3f( 74, 119,-7);
	glVertex3f( 74, 115,-7);
	glVertex3f( 90, 115,-26);
	glVertex3f( 90, 119,-26);

	//gedung5 atap1 belakang
	glVertex3f( 46, 119,-78);
	glVertex3f( 46, 115,-78);
	glVertex3f( 90, 115,-78);
	glVertex3f( 90, 119,-78);

	//gedung5 atap1 kanan
	glVertex3f( 90, 119,-26);
	glVertex3f( 90, 115,-26);
	glVertex3f( 90, 115,-78);
	glVertex3f( 90, 119,-78);

	//gedung5 atap1 kiri
	glVertex3f( 46, 119,-78);
	glVertex3f( 46, 115,-78);
	glVertex3f( 46, 115,-7);
	glVertex3f( 46, 119,-7);

	//gedung5 atap2 bawah
	glVertex3f( 46, 127,-7);
	glVertex3f( 46, 127,-78);
	glVertex3f( 74, 127,-78);
	glVertex3f( 74, 127,-7);

	glVertex3f( 74, 127,-7);
	glVertex3f( 90, 127,-26);
	glVertex3f( 90, 127,-78);
	glVertex3f( 74, 127,-78);

	//gedung5 atap2 atas
	glVertex3f( 46, 132,-7);
	glVertex3f( 46, 132,-78);
	glVertex3f( 74, 132,-78);
	glVertex3f( 74, 132,-7);

	glVertex3f( 74, 132,-7);
	glVertex3f( 90, 132,-26);
	glVertex3f( 90, 132,-78);
	glVertex3f( 74, 132,-78);

	//gedung5 atap2 depan
	glVertex3f( 46, 132,-7);
	glVertex3f( 46, 127,-7);
	glVertex3f( 74, 127,-7);
	glVertex3f( 74, 132,-7);

	//gedung5 atap2 belakang
	glVertex3f( 46, 132,-78);
	glVertex3f( 46, 127,-78);
	glVertex3f( 90, 127,-78);
	glVertex3f( 90, 132,-78);

	//gedung5 atap2 kiri
	glVertex3f( 46, 132,-78);
	glVertex3f( 46, 127,-78);
	glVertex3f( 46, 127,-7);
	glVertex3f( 46, 132,-7);

	//gedung5 atap2 samping kanan
	glVertex3f( 74, 132,-7);
	glVertex3f( 74, 127,-7);
	glVertex3f( 90, 127,-26);
	glVertex3f( 90, 132,-26);
	
	//gedung5 atap2 kanan
	glVertex3f( 90, 132,-26);
	glVertex3f( 90, 127,-26);
	glVertex3f( 90, 127,-78);
	glVertex3f( 90, 132,-78);

	//gedung5 tiang1 depan
	glVertex3f( 50,	127,-10);
	glVertex3f( 50,	119,-10);
	glVertex3f( 48, 119,-10);
	glVertex3f( 48, 127,-10);
	
	//gedung5 tiang1 belakang
	glVertex3f( 50,	127,-12);
	glVertex3f( 50,	119,-12);
	glVertex3f( 48, 119,-12);
	glVertex3f( 48, 127,-12);
	
	//gedung5 tiang1 kiri
	glVertex3f( 50, 127,-10);
	glVertex3f( 50, 119,-10);
	glVertex3f( 50, 119,-12);
	glVertex3f( 50, 127,-12);
	
	//gedung5 tiang1 kanan
	glVertex3f( 48, 127,-10);
	glVertex3f( 48, 119,-10);
	glVertex3f( 48, 119,-12);
	glVertex3f( 48, 127,-12);
	
	//gedung5 tiang2 depan
	glVertex3f( 73,	127,-10);
	glVertex3f( 73,	119,-10);
	glVertex3f( 75, 119,-10);
	glVertex3f( 75, 127,-10);
	
	//gedung5 tiang2 belakang
	glVertex3f( 73,	127,-12);
	glVertex3f( 73,	119,-12);
	glVertex3f( 75, 119,-12);
	glVertex3f( 75, 127,-12);

	//gedung5 tiang2 kiri
	glVertex3f( 73, 127,-10);
	glVertex3f( 73, 119,-10);
	glVertex3f( 73, 119,-12);
	glVertex3f( 73, 127,-12);
	
	//gedung5 tiang2 kanan
	glVertex3f( 75, 127,-10);
	glVertex3f( 75, 119,-10);
	glVertex3f( 75, 119,-12);
	glVertex3f( 75, 127,-12);

	//gedung5 tiang3 depan
	glVertex3f( 85,	127,-73);
	glVertex3f( 85,	119,-73);
	glVertex3f( 87, 119,-73);
	glVertex3f( 87, 127,-73);
	
	//gedung5 tiang3 belakang
	glVertex3f( 85,	127,-75);
	glVertex3f( 85,	119,-75);
	glVertex3f( 87, 119,-75);
	glVertex3f( 87, 127,-75);

	//gedung5 tiang3 kiri
	glVertex3f( 85, 127,-73);
	glVertex3f( 85, 119,-73);
	glVertex3f( 85, 119,-75);
	glVertex3f( 85, 127,-75);

	//gedung5 tiang3 kanan
	glVertex3f( 87, 127,-73);
	glVertex3f( 87, 119,-73);
	glVertex3f( 87, 119,-75);
	glVertex3f( 87, 127,-75);

	//gedung5 tiang4 depan
	glVertex3f( 85,	127,-27);
	glVertex3f( 85,	119,-27);
	glVertex3f( 87, 119,-27);
	glVertex3f( 87, 127,-27);
	
	//gedung5 tiang4 belakang
	glVertex3f( 85,	127,-29);
	glVertex3f( 85,	119,-29);
	glVertex3f( 87, 119,-29);
	glVertex3f( 87, 127,-29);

	//gedung5 tiang4 kiri
	glVertex3f( 85, 127,-27);
	glVertex3f( 85, 119,-27);
	glVertex3f( 85, 119,-29);
	glVertex3f( 85, 127,-29);

	//gedung5 tiang4 kanan
	glVertex3f( 87, 127,-27);
	glVertex3f( 87, 119,-27);
	glVertex3f( 87, 119,-29);
	glVertex3f( 87, 127,-29);
	
	//gedung5 tiang5 depan
	glVertex3f( 50,	127,-73);
	glVertex3f( 50,	119,-73);
	glVertex3f( 48, 119,-73);
	glVertex3f( 48, 127,-73);
	
	//gedung5 tiang5 belakang
	glVertex3f( 50,	127,-75);
	glVertex3f( 50,	119,-75);
	glVertex3f( 48, 119,-75);
	glVertex3f( 48, 127,-75);
	
	//gedung5 tiang5 kiri
	glVertex3f( 50, 127,-73);
	glVertex3f( 50, 119,-73);
	glVertex3f( 50, 119,-75);
	glVertex3f( 50, 127,-75);
	
	//gedung5 tiang5 kanan
	glVertex3f( 48, 127,-73);
	glVertex3f( 48, 119,-73);
	glVertex3f( 48, 119,-75);
	glVertex3f( 48, 127,-75);
	glEnd();

	
	//gedung6 depan ijo
	glBegin(GL_QUADS);
	glColor3f(39/255.f, 116/255.f, 87/255.f);
	glVertex3f(-14,-50,-9);
	glVertex3f(39,-50,-9);
	glVertex3f(39,250,-9);
	glVertex3f(-14,250,-9);

	//gedung6 atas
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-19,300,-10);
	glVertex3f(44,300,-10);
	glVertex3f(44,300,-75);
	glVertex3f(-19,300,-75);

	//pucuk gedung6 depan
	glColor3f(111/255.f, 111/255.f,0);
	glVertex3f(-14,330,-15);
	glVertex3f(39,330,-15);
	glVertex3f(39,300,-15);
	glVertex3f(-14,300,-15);

	//pucuk gedung6 belakang
	glVertex3f(-14,330,-70);
	glVertex3f(39,330,-70);
	glVertex3f(39,300,-70);
	glVertex3f(-14,300,-70);

	//pucuk gedung6 kanan
	glVertex3f(39,330,-15);
	glVertex3f(39,330,-70);
	glVertex3f(39,300,-70);
	glVertex3f(39,300,-15);

	//pucuk gedung6 kiri
	glVertex3f(-14,330,-15);
	glVertex3f(-14,330,-70);
	glVertex3f(-14,300,-70);
	glVertex3f(-14,300,-15);

	//pucuk gedung6 atas
	glVertex3f(-14,330,-15);
	glVertex3f(39,330,-15);
	glVertex3f(39,330,-70);
	glVertex3f(-14,330,-70);

	//kotak depan belakang segitiga
	glColor3f(100/255.f,100/255.f,100/255.f);
	glVertex3f(-9,330,-30);
	glVertex3f(-9,370,-30);
	glVertex3f(34,370,-30);
	glVertex3f(34,330,-30);
	
	//kotak belakang belakang segitiga
	glVertex3f(-9,330,-65);
	glVertex3f(-9,370,-65);
	glVertex3f(34,370,-65);
	glVertex3f(34,330,-65);

	//kotak kiri belakang segitiga
	glVertex3f(-9,330,-30);
	glVertex3f(-9,370,-30);
	glVertex3f(-9,370,-65);
	glVertex3f(-9,330,-65);
	
	//kotak kanan belakang segitiga
	glVertex3f(34,330,-30);
	glVertex3f(34,370,-30);
	glVertex3f(34,370,-65);
	glVertex3f(34,330,-65);
	
	//kotak atas belakang segitiga
	glVertex3f(-9,370,-30);
	glVertex3f(-9,370,-65);
	glVertex3f(34,370,-65);
	glVertex3f(34,370,-30);

	//kotak bawah segitiga gedung6 depan
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-9,330,-20);
	glVertex3f(-9,335,-20);
	glVertex3f(34,335,-20);
	glVertex3f(34,330,-20);
	
	//kotak bawah segitiga gedung6 belakang
	glVertex3f(-9,330,-25);
	glVertex3f(-9,335,-25);
	glVertex3f(34,335,-25);
	glVertex3f(34,330,-25);

	//kotak bawah segitiga gedung6 kiri
	glVertex3f(-9,330,-25);
	glVertex3f(-9,335,-25);
	glVertex3f(-9,335,-20);
	glVertex3f(-9,330,-20);
	
	//kotak bawah segitiga gedung6 kanan
	glVertex3f(34,330,-25);
	glVertex3f(34,335,-25);
	glVertex3f(34,335,-20);
	glVertex3f(34,330,-20);

	//kaki segitiga gedung6 depan
	glColor3f(100/255.f,100/255.f,100/255.f);
	glVertex3f(-9,335,-20);
	glVertex3f(-9,338,-20);
	glVertex3f(34,338,-20);
	glVertex3f(34,335,-20);

	//kaki segitiga gedung6 belakang
	glVertex3f(-9,335,-25);
	glVertex3f(-9,338,-25);
	glVertex3f(34,338,-25);
	glVertex3f(34,335,-25);
	glEnd();

	//segitiga gedung6 depan
	glColor3f(100/255.f,100/255.f,100/255.f);
	glBegin(GL_POLYGON);
	glVertex3f(-9,338,-20);
	glVertex3f(12,360,-22.5);
	glVertex3f(34,338,-20);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-9,338,-25);
	glVertex3f(12,360,-22.5);
	glVertex3f(34,338,-25);
	glEnd();
	//garis mendatar
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(2,350,-21);
	glVertex3f(2,349,-21);
	glVertex3f(23,349,-21);
	glVertex3f(23,350,-21);
	glEnd();
	//garis menurun
	glBegin(GL_POLYGON);
	glVertex3f( 11.5,360,-21.5);
	glVertex3f( 11.5,335,-19);
	glVertex3f(12.5,335,-19);
	glVertex3f(12.5,360,-21.5);
	glEnd();

	//gedung6 depan
	glBegin(GL_QUADS);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-19,-50,-10);
	glVertex3f(44,-50,-10);
	glVertex3f(44, 300,-10);
	glVertex3f(-19,300,-10);
	
	//gedung6 belakang
	glVertex3f(-19,-50,-75);
	glVertex3f(44,-50,-75);
	glVertex3f(44, 300,-75);
	glVertex3f(-19,300,-75);

	//gedung6 kanan
	glVertex3f(44,-50,-10);
	glVertex3f(44,-50,-75);
	glVertex3f(44, 300,-75);
	glVertex3f(44, 300,-10);

	//gedung6 kiri
	glVertex3f(-19,-50,-10);
	glVertex3f(-19,-50,-75);
	glVertex3f(-19, 300,-75);
	glVertex3f(-19, 300,-10);
	glEnd();

	//garis gedung 6 coklat atas #1
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-9, 300, -8);
	glVertex3f(-9, 250, -8);
	glVertex3f(-4, 250, -8);
	glVertex3f(-4, 300, -8);
	glEnd();

	//garis gedung 6 coklat atas #2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 1, 300, -8);
	glVertex3f( 1, 250, -8);
	glVertex3f( 6, 250, -8);
	glVertex3f( 6, 300, -8);
	glEnd();

	//garis gedung 6 coklat atas #3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 11, 300, -8);
	glVertex3f( 11, 250, -8);
	glVertex3f( 16, 250, -8);
	glVertex3f( 16, 300, -8);
	glEnd();


	//garis gedung 6 coklat atas #4
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 21, 300, -8);
	glVertex3f( 21, 250, -8);
	glVertex3f( 26, 250, -8);
	glVertex3f( 26, 300, -8);
	glEnd();

	//garis gedung 6 coklat atas #5
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 31, 300, -8);
	glVertex3f( 31, 250, -8);
	glVertex3f( 36, 250, -8);
	glVertex3f( 36, 300, -8);
	glEnd();
	
	//garis gedung 6 #1
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-9, 250, -8);
	glVertex3f(-9, -50, -8);
	glVertex3f(-4, -50, -8);
	glVertex3f(-4, 250, -8);
	glEnd();

	//garis gedung 6 #2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 1, 250, -8);
	glVertex3f( 1, -50, -8);
	glVertex3f( 6, -50, -8);
	glVertex3f( 6, 250, -8);
	glEnd();

	//garis gedung 6 #3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 11, 250, -8);
	glVertex3f( 11, -50, -8);
	glVertex3f( 16, -50, -8);
	glVertex3f( 16, 250, -8);
	glEnd();


	//garis gedung 6 #4
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 21, 250, -8);
	glVertex3f( 21, -50, -8);
	glVertex3f( 26, -50, -8);
	glVertex3f( 26, 250, -8);
	glEnd();

	//garis gedung 6 #5
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 31, 250, -8);
	glVertex3f( 31, -50, -8);
	glVertex3f( 36, -50, -8);
	glVertex3f( 36, 250, -8);
	glEnd();

	//garis gedung6 mendatar #1
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,225,-7);
	glVertex3f(39,225,-7);
	glVertex3f(39,215,-7);
	glVertex3f(-14,215,-7);
	glEnd();


	//garis gedung6 mendatar #2
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,190,-7);
	glVertex3f(39,190,-7);
	glVertex3f(39,180,-7);
	glVertex3f(-14,180,-7);
	glEnd();

	//garis gedung6 mendatar #3
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,165,-7);
	glVertex3f(39,165,-7);
	glVertex3f(39,155,-7);
	glVertex3f(-14,155,-7);
	glEnd();


	//garis gedung6 mendatar #4
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,130,-7);
	glVertex3f(39,130,-7);
	glVertex3f(39,120,-7);
	glVertex3f(-14,120,-7);
	glEnd();

	//garis gedung6 mendatar #5
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,95,-7);
	glVertex3f(39,95,-7);
	glVertex3f(39,85,-7);
	glVertex3f(-14,85,-7);
	glEnd();


	//garis gedung6 mendatar #6
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,60,-7);
	glVertex3f(39,60,-7);
	glVertex3f(39,50,-7);
	glVertex3f(-14,50,-7);
	glEnd();


	//garis gedung6 mendatar #7
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,25,-7);
	glVertex3f(39,25,-7);
	glVertex3f(39,15,-7);
	glVertex3f(-14,15,-7);
	glEnd();

	//garis gedung6 mendatar #8
	glBegin(GL_POLYGON); 
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-14,-10,-7);
	glVertex3f(39,-10,-7);
	glVertex3f(39,-20,-7);
	glVertex3f(-14,-20,-7);
	glEnd();

	






	//garis gedung2 atap1 depan
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(-147,107,0);
	glVertex3f(-147,111,0);
	glVertex3f(-144,107,0);
	glVertex3f(-144,111,0);
	glVertex3f(-141,107,0);
	glVertex3f(-141,111,0);
	glVertex3f(-138,107,0);
	glVertex3f(-138,111,0);
	glVertex3f(-135,107,0);
	glVertex3f(-135,111,0);
	glVertex3f(-132,107,0);
	glVertex3f(-132,111,0);
	glVertex3f(-129,107,0);
	glVertex3f(-129,111,0);
	glVertex3f(-126,107,0);
	glVertex3f(-126,111,0);
	glVertex3f(-123,107,0);
	glVertex3f(-123,111,0);
	glVertex3f(-120,107,0);
	glVertex3f(-120,111,0);
	glVertex3f(-117,107,0);
	glVertex3f(-117,111,0);
	glVertex3f(-114,107,0);
	glVertex3f(-114,111,0);
	glVertex3f(-111,107,0);
	glVertex3f(-111,111,0);
	glVertex3f(-108,107,0);
	glVertex3f(-108,111,0);
	glVertex3f(-105,107,0);
	glVertex3f(-105,111,0);
	glVertex3f(-102,107,0);
	glVertex3f(-102,111,0);
	glVertex3f(-99,107,0);
	glVertex3f(-99,111,0);
	glVertex3f(-96,107,0);
	glVertex3f(-96,111,0);
	glVertex3f(-93,107,0);
	glVertex3f(-93,111,0);
	glVertex3f(-90,107,0);
	glVertex3f(-90,111,0);
	glVertex3f(-87,107,0);
	glVertex3f(-87,111,0);
	glVertex3f(-84,107,0);
	glVertex3f(-84,111,0);
	glVertex3f(-81,107,0);
	glVertex3f(-81,111,0);
	glVertex3f(-78,107,0);
	glVertex3f(-78,111,0);
	glVertex3f(-75,107,0);
	glVertex3f(-75,111,0);
	glVertex3f(-72,107,0);
	glVertex3f(-72,111,0);
	//belakang
	glVertex3f(-147,107,-85);
	glVertex3f(-147,111,-85);
	glVertex3f(-144,107,-85);
	glVertex3f(-144,111,-85);
	glVertex3f(-141,107,-85);
	glVertex3f(-141,111,-85);
	glVertex3f(-138,107,-85);
	glVertex3f(-138,111,-85);
	glVertex3f(-135,107,-85);
	glVertex3f(-135,111,-85);
	glVertex3f(-132,107,-85);
	glVertex3f(-132,111,-85);
	glVertex3f(-129,107,-85);
	glVertex3f(-129,111,-85);
	glVertex3f(-126,107,-85);
	glVertex3f(-126,111,-85);
	glVertex3f(-123,107,-85);
	glVertex3f(-123,111,-85);
	glVertex3f(-120,107,-85);
	glVertex3f(-120,111,-85);
	glVertex3f(-117,107,-85);
	glVertex3f(-117,111,-85);
	glVertex3f(-114,107,-85);
	glVertex3f(-114,111,-85);
	glVertex3f(-111,107,-85);
	glVertex3f(-111,111,-85);
	glVertex3f(-108,107,-85);
	glVertex3f(-108,111,-85);
	glVertex3f(-105,107,-85);
	glVertex3f(-105,111,-85);
	glVertex3f(-102,107,-85);
	glVertex3f(-102,111,-85);
	glVertex3f(-99,107,-85);
	glVertex3f(-99,111,-85);
	glVertex3f(-96,107,-85);
	glVertex3f(-96,111,-85);
	glVertex3f(-93,107,-85);
	glVertex3f(-93,111,-85);
	glVertex3f(-90,107,-85);
	glVertex3f(-90,111,-85);
	glVertex3f(-87,107,-85);
	glVertex3f(-87,111,-85);
	glVertex3f(-84,107,-85);
	glVertex3f(-84,111,-85);
	glVertex3f(-81,107,-85);
	glVertex3f(-81,111,-85);
	glVertex3f(-78,107,-85);
	glVertex3f(-78,111,-85);
	glVertex3f(-75,107,-85);
	glVertex3f(-75,111,-85);
	glVertex3f(-72,107,-85);
	glVertex3f(-72,111,-85);
	//kiri
	glVertex3f(-150,107,-3);
	glVertex3f(-150,111,-3);
	glVertex3f(-150,107,-6);
	glVertex3f(-150,111,-6);
	glVertex3f(-150,107,-9);
	glVertex3f(-150,111,-9);
	glVertex3f(-150,107,-12);
	glVertex3f(-150,111,-12);
	glVertex3f(-150,107,-15);
	glVertex3f(-150,111,-15);
	glVertex3f(-150,107,-18);
	glVertex3f(-150,111,-18);
	glVertex3f(-150,107,-21);
	glVertex3f(-150,111,-21);
	glVertex3f(-150,107,-24);
	glVertex3f(-150,111,-24);
	glVertex3f(-150,107,-27);
	glVertex3f(-150,111,-27);
	glVertex3f(-150,107,-30);
	glVertex3f(-150,111,-30);
	glVertex3f(-150,107,-33);
	glVertex3f(-150,111,-33);
	glVertex3f(-150,107,-36);
	glVertex3f(-150,111,-36);
	glVertex3f(-150,107,-39);
	glVertex3f(-150,111,-39);
	glVertex3f(-150,107,-42);
	glVertex3f(-150,111,-42);
	glVertex3f(-150,107,-45);
	glVertex3f(-150,111,-45);
	glVertex3f(-150,107,-48);
	glVertex3f(-150,111,-48);
	glVertex3f(-150,107,-51);
	glVertex3f(-150,111,-51);
	glVertex3f(-150,107,-54);
	glVertex3f(-150,111,-54);
	glVertex3f(-150,107,-57);
	glVertex3f(-150,111,-57);
	glVertex3f(-150,107,-60);
	glVertex3f(-150,111,-60);
	glVertex3f(-150,107,-63);
	glVertex3f(-150,111,-63);
	glVertex3f(-150,107,-66);
	glVertex3f(-150,111,-66);
	glVertex3f(-150,107,-69);
	glVertex3f(-150,111,-69);
	glVertex3f(-150,107,-72);
	glVertex3f(-150,111,-72);
	glVertex3f(-150,107,-75);
	glVertex3f(-150,111,-75);
	glVertex3f(-150,107,-78);
	glVertex3f(-150,111,-78);
	glVertex3f(-150,107,-81);
	glVertex3f(-150,111,-81);
	// kanan
	glVertex3f(-70,107,-3);
	glVertex3f(-70,111,-3);
	glVertex3f(-70,107,-6);
	glVertex3f(-70,111,-6);
	glVertex3f(-70,107,-9);
	glVertex3f(-70,111,-9);
	glVertex3f(-70,107,-12);
	glVertex3f(-70,111,-12);
	glVertex3f(-70,107,-15);
	glVertex3f(-70,111,-15);
	glVertex3f(-70,107,-18);
	glVertex3f(-70,111,-18);
	glVertex3f(-70,107,-21);
	glVertex3f(-70,111,-21);
	glVertex3f(-70,107,-24);
	glVertex3f(-70,111,-24);
	glVertex3f(-70,107,-27);
	glVertex3f(-70,111,-27);
	glVertex3f(-70,107,-30);
	glVertex3f(-70,111,-30);
	glVertex3f(-70,107,-33);
	glVertex3f(-70,111,-33);
	glVertex3f(-70,107,-36);
	glVertex3f(-70,111,-36);
	glVertex3f(-70,107,-39);
	glVertex3f(-70,111,-39);
	glVertex3f(-70,107,-42);
	glVertex3f(-70,111,-42);
	glVertex3f(-70,107,-45);
	glVertex3f(-70,111,-45);
	glVertex3f(-70,107,-48);
	glVertex3f(-70,111,-48);
	glVertex3f(-70,107,-51);
	glVertex3f(-70,111,-51);
	glVertex3f(-70,107,-54);
	glVertex3f(-70,111,-54);
	glVertex3f(-70,107,-57);
	glVertex3f(-70,111,-57);
	glVertex3f(-70,107,-60);
	glVertex3f(-70,111,-60);
	glVertex3f(-70,107,-63);
	glVertex3f(-70,111,-63);
	glVertex3f(-70,107,-66);
	glVertex3f(-70,111,-66);
	glVertex3f(-70,107,-69);
	glVertex3f(-70,111,-69);
	glVertex3f(-70,107,-72);
	glVertex3f(-70,111,-72);
	glVertex3f(-70,107,-75);
	glVertex3f(-70,111,-75);
	glVertex3f(-70,107,-78);
	glVertex3f(-70,111,-78);
	glVertex3f(-70,107,-81);
	glVertex3f(-70,111,-81);

	//garis gedung3 atap1 depan
	
	glVertex3f( 98,107,0);
	glVertex3f( 98,111,0);
	glVertex3f( 101,107,0);
	glVertex3f( 101,111,0);
	glVertex3f( 104,107,0);
	glVertex3f( 104,111,0);
	glVertex3f( 107,107,0);
	glVertex3f( 107,111,0);
	glVertex3f( 110,107,0);
	glVertex3f( 110,111,0);
	glVertex3f( 113,107,0);
	glVertex3f( 113,111,0);
	glVertex3f( 116,107,0);
	glVertex3f( 116,111,0);
	glVertex3f( 119,107,0);
	glVertex3f( 119,111,0);
	glVertex3f( 122,107,0);
	glVertex3f( 122,111,0);
	glVertex3f( 125,107,0);
	glVertex3f( 125,111,0);
	glVertex3f( 128,107,0);
	glVertex3f( 128,111,0);
	glVertex3f( 131,107,0);
	glVertex3f( 131,111,0);
	glVertex3f( 134,107,0);
	glVertex3f( 134,111,0);
	glVertex3f( 137,107,0);
	glVertex3f( 137,111,0);
	glVertex3f( 140,107,0);
	glVertex3f( 140,111,0);
	glVertex3f( 143,107,0);
	glVertex3f( 143,111,0);
	glVertex3f( 146,107,0);
	glVertex3f( 146,111,0);
	glVertex3f( 149,107,0);
	glVertex3f( 149,111,0);
	glVertex3f( 152,107,0);
	glVertex3f( 152,111,0);
	glVertex3f( 155,107,0);
	glVertex3f( 155,111,0);
	glVertex3f( 158,107,0);
	glVertex3f( 158,111,0);
	glVertex3f( 161,107,0);
	glVertex3f( 161,111,0);
	glVertex3f( 164,107,0);
	glVertex3f( 164,111,0);
	glVertex3f( 167,107,0);
	glVertex3f( 167,111,0);

	//garis gedung3 atap1 belakang
	
	glVertex3f( 98,107,-85);
	glVertex3f( 98,111,-85);
	glVertex3f( 101,107,-85);
	glVertex3f( 101,111,-85);
	glVertex3f( 104,107,-85);
	glVertex3f( 104,111,-85);
	glVertex3f( 107,107,-85);
	glVertex3f( 107,111,-85);
	glVertex3f( 110,107,-85);
	glVertex3f( 110,111,-85);
	glVertex3f( 113,107,-85);
	glVertex3f( 113,111,-85);
	glVertex3f( 116,107,-85);
	glVertex3f( 116,111,-85);
	glVertex3f( 119,107,-85);
	glVertex3f( 119,111,-85);
	glVertex3f( 122,107,-85);
	glVertex3f( 122,111,-85);
	glVertex3f( 125,107,-85);
	glVertex3f( 125,111,-85);
	glVertex3f( 128,107,-85);
	glVertex3f( 128,111,-85);
	glVertex3f( 131,107,-85);
	glVertex3f( 131,111,-85);
	glVertex3f( 134,107,-85);
	glVertex3f( 134,111,-85);
	glVertex3f( 137,107,-85);
	glVertex3f( 137,111,-85);
	glVertex3f( 140,107,-85);
	glVertex3f( 140,111,-85);
	glVertex3f( 143,107,-85);
	glVertex3f( 143,111,-85);
	glVertex3f( 146,107,-85);
	glVertex3f( 146,111,-85);
	glVertex3f( 149,107,-85);
	glVertex3f( 149,111,-85);
	glVertex3f( 152,107,-85);
	glVertex3f( 152,111,-85);
	glVertex3f( 155,107,-85);
	glVertex3f( 155,111,-85);
	glVertex3f( 158,107,-85);
	glVertex3f( 158,111,-85);
	glVertex3f( 161,107,-85);
	glVertex3f( 161,111,-85);
	glVertex3f( 164,107,-85);
	glVertex3f( 164,111,-85);
	glVertex3f( 167,107,-85);
	glVertex3f( 167,111,-85);

	//garis gedung3 atap1 kanan
	glVertex3f( 170,107,-3);
	glVertex3f( 170,111,-3);
	glVertex3f( 170,107,-6);
	glVertex3f( 170,111,-6);
	glVertex3f( 170,107,-9);
	glVertex3f( 170,111,-9);
	glVertex3f( 170,107,-12);
	glVertex3f( 170,111,-12);
	glVertex3f( 170,107,-12);
	glVertex3f( 170,111,-12);
	glVertex3f( 170,107,-15);
	glVertex3f( 170,111,-15);
	glVertex3f( 170,107,-18);
	glVertex3f( 170,111,-18);
	glVertex3f( 170,107,-21);
	glVertex3f( 170,111,-21);
	glVertex3f( 170,107,-24);
	glVertex3f( 170,111,-24);
	glVertex3f( 170,107,-27);
	glVertex3f( 170,111,-27);
	glVertex3f( 170,107,-30);
	glVertex3f( 170,111,-30);
	glVertex3f( 170,107,-33);
	glVertex3f( 170,111,-33);
	glVertex3f( 170,107,-36);
	glVertex3f( 170,111,-36);
	glVertex3f( 170,107,-39);
	glVertex3f( 170,111,-39);
	glVertex3f( 170,107,-42);
	glVertex3f( 170,111,-42);
	glVertex3f( 170,107,-45);
	glVertex3f( 170,111,-45);
	glVertex3f( 170,107,-48);
	glVertex3f( 170,111,-48);
	glVertex3f( 170,107,-51);
	glVertex3f( 170,111,-51);
	glVertex3f( 170,107,-54);
	glVertex3f( 170,111,-54);
	glVertex3f( 170,107,-57);
	glVertex3f( 170,111,-57);
	glVertex3f( 170,107,-60);
	glVertex3f( 170,111,-60);
	glVertex3f( 170,107,-63);
	glVertex3f( 170,111,-63);
	glVertex3f( 170,107,-66);
	glVertex3f( 170,111,-66);
	glVertex3f( 170,107,-69);
	glVertex3f( 170,111,-69);
	glVertex3f( 170,107,-72);
	glVertex3f( 170,111,-72);
	glVertex3f( 170,107,-75);
	glVertex3f( 170,111,-75);
	glVertex3f( 170,107,-78);
	glVertex3f( 170,111,-78);
	glVertex3f( 170,107,-81);
	glVertex3f( 170,111,-81);

	//garis gedung3 atap1 kiri
	glVertex3f( 95,107,-3);
	glVertex3f( 95,111,-3);
	glVertex3f( 95,107,-6);
	glVertex3f( 95,111,-6);
	glVertex3f( 95,107,-9);
	glVertex3f( 95,111,-9);
	glVertex3f( 95,107,-12);
	glVertex3f( 95,111,-12);
	glVertex3f( 95,107,-15);
	glVertex3f( 95,111,-15);
	glVertex3f( 95,107,-18);
	glVertex3f( 95,111,-18);
	glVertex3f( 95,107,-21);
	glVertex3f( 95,111,-21);
	glVertex3f( 95,107,-24);
	glVertex3f( 95,111,-24);
	glVertex3f( 95,107,-27);
	glVertex3f( 95,111,-27);
	glVertex3f( 95,107,-30);
	glVertex3f( 95,111,-30);
	glVertex3f( 95,107,-33);
	glVertex3f( 95,111,-33);
	glVertex3f( 95,107,-36);
	glVertex3f( 95,111,-36);
	glVertex3f( 95,107,-39);
	glVertex3f( 95,111,-39);
	glVertex3f( 95,107,-42);
	glVertex3f( 95,111,-42);
	glVertex3f( 95,107,-45);
	glVertex3f( 95,111,-45);
	glVertex3f( 95,107,-48);
	glVertex3f( 95,111,-48);
	glVertex3f( 95,107,-51);
	glVertex3f( 95,111,-51);
	glVertex3f( 95,107,-54);
	glVertex3f( 95,111,-54);
	glVertex3f( 95,107,-57);
	glVertex3f( 95,111,-57);
	glVertex3f( 95,107,-60);
	glVertex3f( 95,111,-60);
	glVertex3f( 95,107,-63);
	glVertex3f( 95,111,-63);
	glVertex3f( 95,107,-66);
	glVertex3f( 95,111,-66);
	glVertex3f( 95,107,-69);
	glVertex3f( 95,111,-69);
	glVertex3f( 95,107,-72);
	glVertex3f( 95,111,-72);
	glVertex3f( 95,107,-75);
	glVertex3f( 95,111,-75);
	glVertex3f( 95,107,-78);
	glVertex3f( 95,111,-78);
	glVertex3f( 95,107,-81);
	glVertex3f( 95,111,-81);
	glEnd();
	
	//atap segitiga gedung4
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-51,132,-7);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-21,132,-7);
	glVertex3f(-36,150,-35.5);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-65,132,-78);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-21,132,-78);
	glVertex3f(-36,150,-35.5);
	glEnd();
	//samping kiri
	glBegin(GL_POLYGON);
	glVertex3f(-65,132,-26);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-51,132,-7);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-21,132,-7);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-21,132,-78);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-65,132,-78);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-65,132,-26);
	glEnd();

	//atap segitiga gedung5 depan
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(46,132,-7);
	glVertex3f(60,150,-35.5);
	glVertex3f(74,132,-7);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(46,132,-78);
	glVertex3f(60,150,-35.5);
	glVertex3f(90,132,-78);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(46,132,-78);
	glVertex3f(60,150,-35.5);
	glVertex3f(46,132,-7);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(90,132,-78);
	glVertex3f(60,150,-35.5);
	glVertex3f(90,132,-26);
	glEnd();
	//kanan samping
	glBegin(GL_POLYGON);
	glVertex3f(74,132,-7);
	glVertex3f(60,150,-35.5);
	glVertex3f(90,132,-26);
	glEnd();

	
	//garis mendatar atas gedung2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-130,47,-4);
	glVertex3f(-95, 47,-4);
	glVertex3f(-95, 53,-4);
	glVertex3f(-130,53,-4);
	
	glEnd();

	//garis tengah gedung2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-130,-7,-4);
	glVertex3f(-95, -7,-4);
	glVertex3f(-95, -13,-4);
	glVertex3f(-130,-13,-4);
	
	glEnd();

	//garis bawah gedung2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-130,-47,-4);
	glVertex3f(-95, -47,-4);
	glVertex3f(-95, -53,-4);
	glVertex3f(-130,-53,-4);
	glEnd();

		
	//garis tegak kiri gedung2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-120, 101,-4);
	glVertex3f(-120,-110,-4);
	glVertex3f(-125,-110,-4);
	glVertex3f(-125, 101,-4);
	glEnd();

	//garis tegak kanan gedung2
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-107, 101,-4);
	glVertex3f(-107, -110,-4);
	glVertex3f(-102,-110,-4);
	glVertex3f(-102, 101,-4);
	glEnd();

	//garis mendatar atas gedung3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(110,47,-4);
	glVertex3f(150, 47,-4);
	glVertex3f(150, 53,-4);
	glVertex3f(110,53,-4);
	
	glEnd();

	//garis tengah gedung3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(110,-7,-4);
	glVertex3f(150, -7,-4);
	glVertex3f(150, -13,-4);
	glVertex3f(110,-13,-4);
	
	glEnd();

	//garis bawah gedung3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(110,-47,-4);
	glVertex3f(150, -47,-4);
	glVertex3f(150, -53,-4);
	glVertex3f(110,-53,-4);
	glEnd();

	//garis tegak kiri gedung3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 120, 101,-4);
	glVertex3f( 120,-110,-4);
	glVertex3f( 125,-110,-4);
	glVertex3f( 125, 101,-4);
	glEnd();

	//garis tegak kanan gedung3
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 133, 101,-4);
	glVertex3f( 133, -110,-4);
	glVertex3f( 138,-110,-4);
	glVertex3f( 138, 101,-4);
	glEnd();

	//garis mendatar atas gedung4
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-49,47,-9);
	glVertex3f(-24, 47,-9);
	glVertex3f(-24, 53,-9);
	glVertex3f(-49,53,-9);
	
	glEnd();

	//garis bawah gedung4
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(-49,-7,-9);
	glVertex3f(-24, -7,-9);
	glVertex3f(-24, -13,-9);
	glVertex3f(-49,-13,-9);
	glEnd();

	//garis tegak kiri gedung4
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( -44, 115,-9);
	glVertex3f( -44,-50,-9);
	glVertex3f( -39,-50,-9);
	glVertex3f( -39, 115,-9);
	glEnd();

	//garis tegak kanan gedung4
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( -34, 115,-9);
	glVertex3f( -34, -50,-9);
	glVertex3f( -29,-50,-9);
	glVertex3f( -29, 115,-9);
	glEnd();

	//garis mendatar atas gedung5
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 49,47,-9);
	glVertex3f( 74, 47,-9);
	glVertex3f( 74, 53,-9);
	glVertex3f( 49,53,-9);
	
	glEnd();

	//garis bawah gedung5
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( 49,-7,-9);
	glVertex3f( 74, -7,-9);
	glVertex3f( 74, -13,-9);
	glVertex3f( 49,-13,-9);
	
	glEnd();

	//garis tegak kiri gedung5
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(  54, 115,-9);
	glVertex3f(  54,-50,-9);
	glVertex3f(  59,-50,-9);
	glVertex3f(  59, 115,-9);
	glEnd();

	//garis tegak kanan gedung5
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(  64, 115,-9);
	glVertex3f(  64, -50,-9);
	glVertex3f(  69,-50,-9);
	glVertex3f(  69, 115,-9);
	glEnd();

	//garis tegak kiri gedung1
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( -45, -50,-4);
	glVertex3f( -45,-110,-4);
	glVertex3f( -40,-110,-4);
	glVertex3f( -40, -50,-4);
	glEnd();

	//garis tegak kanan gedung1
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( -35, -50,-4);
	glVertex3f( -35,-110,-4);
	glVertex3f( -30,-110,-4);
	glVertex3f( -30, -50,-4);
	glEnd();

	//garis mendatar atas gedung1
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( -50,-60,-4);
	glVertex3f( -24,-60,-4);
	glVertex3f( -24,-66,-4);
	glVertex3f( -50,-66,-4);
	
	glEnd();

	//garis mendatar bawah gedung1
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f( -50,-80,-4);
	glVertex3f( -24,-80,-4);
	glVertex3f( -24,-86,-4);
	glVertex3f( -50,-86,-4);
	
	glEnd();

	//garis mendatar atas gedung1 kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(  41,-60,-4);
	glVertex3f(  75,-60,-4);
	glVertex3f(  75,-66,-4);
	glVertex3f(  41,-66,-4);
	
	glEnd();

	//garis mendatar bawah gedung1 kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(  41,-80,-4);
	glVertex3f(  75,-80,-4);
	glVertex3f(  75,-86,-4);
	glVertex3f(  41,-86,-4);
	
	glEnd();

	//garis tegak kiri gedung1 kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(  54, -50,-4);
	glVertex3f(  54,-110,-4);
	glVertex3f(  59,-110,-4);
	glVertex3f(  59, -50,-4);
	glEnd();

	//garis tegak kanan gedung1 kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(87/255.f, 44/255.f, 0);
	glVertex3f(  64, -50,-4);
	glVertex3f(  64,-110,-4);
	glVertex3f(  69,-110,-4);
	glVertex3f(  69, -50,-4);
	glEnd();


	//lineloop alas1 depan
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	glVertex3f(-210,-130,60);
	glVertex3f(-210,-120,60);
	glVertex3f(210,-120,60);
	glVertex3f(210,-130,60);
	glEnd();

	//lineloop alas1 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-210,-130,-210);
	glVertex3f(-210,-120,-210);
	glVertex3f(210,-120,-210);
	glVertex3f(210,-130,-210);
	glEnd();

	//lineloop alas1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(210,-130,60);
	glVertex3f(210,-120,60);
	glVertex3f(210,-120,-210);
	glVertex3f(210,-130,-210);
	glEnd();

	//lineloop alas1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-210,-130,60);
	glVertex3f(-210,-120,60);
	glVertex3f(-210,-120,-210);
	glVertex3f(-210,-130,-210);
	glEnd();

	//lineloop alas 2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-210,-120,60);
	glVertex3f(-200,-110,50);
	glVertex3f(200,-110,50);
	glVertex3f(210,-120,60);
	glEnd();
	
	//lineloop alas2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-210,-120,-210);
	glVertex3f(-200,-110,-200);
	glVertex3f(200,-110,-200);
	glVertex3f(210,-120,-210);
	glEnd();

	//lineloop alas2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(210,-120,60);
	glVertex3f(200,-110,50);
	glVertex3f(200,-110,-200);
	glVertex3f(210,-120,-210);
	glEnd();

	//lineloop alas2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-210,-120,60);
	glVertex3f(-200,-110,50);
	glVertex3f(-200,-110,-200);
	glVertex3f(-210,-120,-210);
	glEnd();

	//lineloop gedung1 depan
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3f(-50,-110,-5);
	glVertex3f(-50,-50,-5);
	glVertex3f(75,-50,-5);
	glVertex3f(75,-110,-5);
	glEnd();

	//lineloop gedung1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-50,-50,-5);
	glVertex3f(-50,-110,-5);
	glVertex3f(-65,-110,-25);
	glVertex3f(-65,-50,-25);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65,-50,-25);
	glVertex3f(-65,-110,-25);
	glVertex3f(-65,-110,-80);
	glVertex3f(-65,-50,-80);
	glEnd();
	
	//lineloop gedung1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(75,-50,-5);
	glVertex3f(75,-110,-5);
	glVertex3f(90,-110,-25);
	glVertex3f(90,-50,-25);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(90,-50,-25);
	glVertex3f(90,-110,-25);
	glVertex3f(90,-110,-80);
	glVertex3f(90,-50,-80);

	glEnd();

	//lineloop gedung2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-130,-110,-5);
	glVertex3f(-130,101,-5);
	glVertex3f(-95, 101,-5);
	glVertex3f(-95,-110,-5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-95,-110,-5);
	glVertex3f(-95, 101,-5);
	glVertex3f(-75, 101,-25);
	glVertex3f(-75,-110,-25);
	glEnd();

	//lineloop gedung2 kiri 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-130,-110,-5);
	glVertex3f(-130, 101,-5);
	glVertex3f(-145, 101,-25);
	glVertex3f(-145,-110,-25);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-145,-110,-25);
	glVertex3f(-145, 101,-25);
	glVertex3f(-145, 101,-80);
	glVertex3f(-145,-110,-80);
	glEnd();

	//lineloop gedung2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-75, 101,-80);
	glVertex3f(-75,-110,-80);
	glVertex3f(-75,-110,-25);
	glVertex3f(-75, 101,-25);
	glEnd();

	//lineloop gedung2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-145,-110,-80);
	glVertex3f(-145, 101,-80);
	glVertex3f(-75, 101,-80);
	glVertex3f(-75,-110,-80);
	glEnd();

	//lineloop gedung3 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(110,-110,-5);
	glVertex3f(110, 101,-5);
	glVertex3f(150, 101,-5);
	glVertex3f(150,-110,-5);
	glEnd();
	
	//lineloop gedung3 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(100,-110,-80);
	glVertex3f(100, 101,-80);
	glVertex3f(165, 101,-80);
	glVertex3f(165,-110,-80);
	glEnd();

	//lineloop gedung3 kiri 
	glBegin(GL_LINE_LOOP);
	glVertex3f(	110,-110,-5);
	glVertex3f(	110,101,-5);
	glVertex3f(	100, 101,-25);
	glVertex3f(	100,-110,-25);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f( 100,101,-25);
	glVertex3f( 100,-110,-25);
	glVertex3f( 100,-110,-80);
	glVertex3f( 100, 101,-80);

	glEnd();


	//lineloop gedung3 kanan 
	glBegin(GL_LINE_LOOP);
	glVertex3f(150,-110,-5);
	glVertex3f(150,101,-5);
	glVertex3f(165, 101,-25);
	glVertex3f(165,-110,-25);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(165,-110,-25);
	glVertex3f(165, 101,-25);
	glVertex3f(165, 101,-80);
	glVertex3f(165,-110,-80);


	glEnd();

	//lineloop gedung4 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-49,-50,-10);
	glVertex3f(-24,-50,-10);
	glVertex3f(-24, 115,-10);
	glVertex3f(-49, 115,-10);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-49,-50,-10);
	glVertex3f(-62,-50,-27);
	glVertex3f(-62, 115,-27);
	glVertex3f(-49, 115,-10);
	glEnd();

	//lineloop gedung4 kiri
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-62, 115,-27);
	glVertex3f(-62,-50,-27);
	glVertex3f(-62,-50,-75);
	glVertex3f(-62, 115,-75);
	glEnd();

	//lineloop gedung4 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-62, 115,-75);
	glVertex3f(-62,-50,-75);
	glVertex3f(-24,-50,-75);
	glVertex3f(-24, 115,-75);
	glEnd();

	//lineloop gedung4 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24, 115,-75);
	glVertex3f(-24,-50,-75);
	glVertex3f(-24,-50,-10);
	glVertex3f(-24, 115,-10);
	glEnd();

	//lineloop gedung4 atap depan
	
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-51, 119,-7);
	glVertex3f(-51, 115,-7);
	glVertex3f(-21, 115,-7);
	glVertex3f(-21, 119,-7);
	glEnd();

	//lineloop gedung4 atap belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65, 119,-78);
	glVertex3f(-65, 115,-78);
	glVertex3f(-21, 115,-78);
	glVertex3f(-21, 119,-78);
	glEnd();

	//lineloop gedung4 atap kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-21, 119,-7);
	glVertex3f(-21, 115,-7);
	glVertex3f(-21, 115,-78);
	glVertex3f(-21, 119,-78);
	glEnd();

	//lineloop gedung4 atap kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65, 119,-78);
	glVertex3f(-65, 115,-78);
	glVertex3f(-65, 115,-26);
	glVertex3f(-65, 119,-26);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-65, 119,-26);
	glVertex3f(-65, 115,-26);
	glVertex3f(-51, 115,-7);
	glVertex3f(-51, 119,-7);
	glEnd();

	//lineloop gedung4 tiang1 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-50,	127,-10);
	glVertex3f(-50,	119,-10);
	glVertex3f(-48, 119,-10);
	glVertex3f(-48, 127,-10);
	glEnd();

	//lineloop gedung4 tiang1 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-50,	127,-12);
	glVertex3f(-50,	119,-12);
	glVertex3f(-48, 119,-12);
	glVertex3f(-48, 127,-12);
	glEnd();

	//lineloop gedung4 tiang1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-50, 127,-10);
	glVertex3f(-50, 119,-10);
	glVertex3f(-50, 119,-12);
	glVertex3f(-50, 127,-12);
	glEnd();

	//lineloop gedung4 tiang1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-48, 127,-10);
	glVertex3f(-48, 119,-10);
	glVertex3f(-48, 119,-12);
	glVertex3f(-48, 127,-12);
	glEnd();

	//lineloop gedung4 tiang2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24,	127,-10);
	glVertex3f(-24,	119,-10);
	glVertex3f(-26, 119,-10);
	glVertex3f(-26, 127,-10);
	glEnd();

	//lineloop gedung4 tiang2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24,	127,-12);
	glVertex3f(-24,	119,-12);
	glVertex3f(-26, 119,-12);
	glVertex3f(-26, 127,-12);
	glEnd();

	//lineloop gedung4 tiang2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24, 127,-10);
	glVertex3f(-24, 119,-10);
	glVertex3f(-24, 119,-12);
	glVertex3f(-24, 127,-12);
	glEnd();

	//lineloop gedung4 tiang2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-26, 127,-10);
	glVertex3f(-26, 119,-10);
	glVertex3f(-26, 119,-12);
	glVertex3f(-26, 127,-12);
	glEnd();

	//lineloop gedung4 tiang3 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24, 127,-73);
	glVertex3f(-24, 119,-73);
	glVertex3f(-26, 119,-73);
	glVertex3f(-26, 127,-73);
	glEnd();

	//lineloop gedung4 tiang3 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24, 127,-75);
	glVertex3f(-24, 119,-75);
	glVertex3f(-26, 119,-75);
	glVertex3f(-26, 127,-75);
	glEnd();

	//lineloop gedung4 tiang3 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24, 127,-73);
	glVertex3f(-24, 119,-73);
	glVertex3f(-24, 119,-75);
	glVertex3f(-24, 127,-75);
	glEnd();

	//lineloop gedung4 tiang2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-26, 127,-73);
	glVertex3f(-26, 119,-73);
	glVertex3f(-26, 119,-75);
	glVertex3f(-26, 127,-75);
	glEnd();

	//lineloop gedung4 tiang4 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-63,	127,-73);
	glVertex3f(-63,	119,-73);
	glVertex3f(-61, 119,-73);
	glVertex3f(-61, 127,-73);
	glEnd();

	//lineloop gedung4 tiang4 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-63,	127,-75);
	glVertex3f(-63,	119,-75);
	glVertex3f(-61, 119,-75);
	glVertex3f(-61, 127,-75);
	glEnd();

	//gedung4 tiang4 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-63,	127,-73);
	glVertex3f(-63,	119,-73);
	glVertex3f(-63, 119,-75);
	glVertex3f(-63, 127,-75);
	glEnd();

	//gedung4 tiang4 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-61,	127,-73);
	glVertex3f(-61,	119,-73);
	glVertex3f(-61, 119,-75);
	glVertex3f(-61, 127,-75);
	glEnd();
	
	//lineloop gedung4 tiang5 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-63,	127,-27);
	glVertex3f(-63,	119,-27);
	glVertex3f(-61, 119,-27);
	glVertex3f(-61, 127,-27);
	glEnd();

	//lineloop gedung4 tiang5 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-63,	127,-27);
	glVertex3f(-63,	119,-27);
	glVertex3f(-61, 119,-27);
	glVertex3f(-61, 127,-27);
	glEnd();

	//lineloop gedung4 tiang5 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-63,	127,-27);
	glVertex3f(-63,	119,-27);
	glVertex3f(-63, 119,-27);
	glVertex3f(-63, 127,-27);
	glEnd();

	//lineloop gedung4 tiang5 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-61,	127,-27);
	glVertex3f(-61,	119,-27);
	glVertex3f(-61, 119,-29);
	glVertex3f(-61, 127,-29);
	glEnd();

	//lineloop gedung5 depan
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex3f( 49,-50,-10);
	glVertex3f( 74,-50,-10);
	glVertex3f( 74, 115,-10);
	glVertex3f( 49, 115,-10);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f( 74,-50,-10);
	glVertex3f( 87,-50,-27);
	glVertex3f( 87, 115,-27);
	glVertex3f( 74, 115,-10);
	glEnd();

	//lineloop gedung5 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 87, 115,-75);
	glVertex3f( 87, -50,-75);
	glVertex3f( 49, -50,-75);
	glVertex3f( 49, 115,-75);
	glEnd();

	//lineloop gedung5 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 87, 115,-27);
	glVertex3f( 87,-50,-27);
	glVertex3f( 87,-50,-75);
	glVertex3f( 87, 115,-75);
	glEnd();

	//lineloop gedung5 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 49, 115,-75);
	glVertex3f( 49,-50,-75);
	glVertex3f( 49,-50,-10);
	glVertex3f( 49, 115,-10);
	glEnd();

	//lineloop gedung5 atap1 depan
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	glVertex3f( 46, 119,-7);
	glVertex3f( 46, 115,-7);
	glVertex3f( 74, 115,-7);
	glVertex3f( 74, 119,-7);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f( 74, 119,-7);
	glVertex3f( 74, 115,-7);
	glVertex3f( 90, 115,-26);
	glVertex3f( 90, 119,-26);
	glEnd();

	//lineloop gedung5 atap1 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 46, 119,-78);
	glVertex3f( 46, 115,-78);
	glVertex3f( 90, 115,-78);
	glVertex3f( 90, 119,-78);
	glEnd();

	//lineloop gedung5 atap1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 90, 119,-26);
	glVertex3f( 90, 115,-26);
	glVertex3f( 90, 115,-78);
	glVertex3f( 90, 119,-78);
	glEnd();

	//lineloop gedung5 atap1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 46, 119,-78);
	glVertex3f( 46, 115,-78);
	glVertex3f( 46, 115,-7);
	glVertex3f( 46, 119,-7);
	glEnd();

	//lineloop gedung5 tiang1 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 50,	127,-10);
	glVertex3f( 50,	119,-10);
	glVertex3f( 48, 119,-10);
	glVertex3f( 48, 127,-10);
	glEnd();
	
	//lineloop gedung5 tiang1 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 50,	127,-12);
	glVertex3f( 50,	119,-12);
	glVertex3f( 48, 119,-12);
	glVertex3f( 48, 127,-12);
	glEnd();

	//lineloop gedung5 tiang1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 50, 127,-10);
	glVertex3f( 50, 119,-10);
	glVertex3f( 50, 119,-12);
	glVertex3f( 50, 127,-12);
	glEnd();

	//lineloop gedung5 tiang1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 48, 127,-10);
	glVertex3f( 48, 119,-10);
	glVertex3f( 48, 119,-12);
	glVertex3f( 48, 127,-12);
	glEnd();

	//lineloop gedung5 tiang2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 73,	127,-10);
	glVertex3f( 73,	119,-10);
	glVertex3f( 75, 119,-10);
	glVertex3f( 75, 127,-10);
	glEnd();

	//lineloop gedung5 tiang2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 73,	127,-12);
	glVertex3f( 73,	119,-12);
	glVertex3f( 75, 119,-12);
	glVertex3f( 75, 127,-12);
	glEnd();

	//lineloop gedung5 tiang2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 73, 127,-10);
	glVertex3f( 73, 119,-10);
	glVertex3f( 73, 119,-12);
	glVertex3f( 73, 127,-12);
	glEnd();

	//lineloop gedung5 tiang2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 75, 127,-10);
	glVertex3f( 75, 119,-10);
	glVertex3f( 75, 119,-12);
	glVertex3f( 75, 127,-12);
	glEnd();

	//lineloop gedung5 tiang3 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 85,	127,-73);
	glVertex3f( 85,	119,-73);
	glVertex3f( 87, 119,-73);
	glVertex3f( 87, 127,-73);
	glEnd();
	
	//lineloop gedung5 tiang3 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 85,	127,-75);
	glVertex3f( 85,	119,-75);
	glVertex3f( 87, 119,-75);
	glVertex3f( 87, 127,-75);
	glEnd();

	//lineloop gedung5 tiang3 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 85, 127,-73);
	glVertex3f( 85, 119,-73);
	glVertex3f( 85, 119,-75);
	glVertex3f( 85, 127,-75);
	glEnd();

	//lineloop gedung5 tiang3 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 87, 127,-73);
	glVertex3f( 87, 119,-73);
	glVertex3f( 87, 119,-75);
	glVertex3f( 87, 127,-75);
	glEnd();

	//lineloop gedung5 tiang4 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 85,	127,-27);
	glVertex3f( 85,	119,-27);
	glVertex3f( 87, 119,-27);
	glVertex3f( 87, 127,-27);
	glEnd();
	
	//lineloop gedung5 tiang4 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 85,	127,-29);
	glVertex3f( 85,	119,-29);
	glVertex3f( 87, 119,-29);
	glVertex3f( 87, 127,-29);
	glEnd();

	//lineloop gedung5 tiang4 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 85, 127,-27);
	glVertex3f( 85, 119,-27);
	glVertex3f( 85, 119,-29);
	glVertex3f( 85, 127,-29);
	glEnd();

	//lineloop gedung5 tiang4 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 87, 127,-27);
	glVertex3f( 87, 119,-27);
	glVertex3f( 87, 119,-29);
	glVertex3f( 87, 127,-29);
	glEnd();

	//lineloop gedung5 tiang5 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 50,	127,-73);
	glVertex3f( 50,	119,-73);
	glVertex3f( 48, 119,-73);
	glVertex3f( 48, 127,-73);
	glEnd();

	//lineloop gedung5 tiang5 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 50,	127,-75);
	glVertex3f( 50,	119,-75);
	glVertex3f( 48, 119,-75);
	glVertex3f( 48, 127,-75);
	glEnd();

	//lineloop gedung5 tiang5 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 50, 127,-73);
	glVertex3f( 50, 119,-73);
	glVertex3f( 50, 119,-75);
	glVertex3f( 50, 127,-75);
	glEnd();

	//lineloop gedung5 tiang5 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 48, 127,-73);
	glVertex3f( 48, 119,-73);
	glVertex3f( 48, 119,-75);
	glVertex3f( 48, 127,-75);
	glEnd();

	//lineloop gedung2 atap1 depan
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3f(-150,107, 0);
	glVertex3f(-150 ,101, 0);
	glVertex3f(-70, 101, 0);
	glVertex3f(-70,107, 0);
	glEnd();
	
	//lineloop gedung2 atap1 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-150,107, -85);
	glVertex3f(-150 ,101,-85);
	glVertex3f(-70, 101,-85);
	glVertex3f(-70,107,-85);
	glEnd();

	//lineloop gedung2 atap1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-150,107,-85);
	glVertex3f(-150,101,-85);
	glVertex3f(-150,101, 0);
	glVertex3f(-150,107, 0);
	glEnd();

	//lineloop gedung2 atap1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-70,107,-85);
	glVertex3f(-70,101,-85);
	glVertex3f(-70,101, 0);
	glVertex3f(-70,107, 0);
	glEnd();

	//lineloop gedung2 atap2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-155,115,-90);
	glVertex3f(-150,111,-85);
	glVertex3f(-70,111,-85);
	glVertex3f(-65,115,-90);
	glEnd();

	//lineloop gedung2 atap2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-155,115,5);
	glVertex3f(-150,111, 0);
	glVertex3f(-70,111,0);
	glVertex3f(-65,115,5);
	glEnd();

	//lineloop gedung2 atap2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-155,115,-90);
	glVertex3f(-150,111,-85);
	glVertex3f(-150,111,0);
	glVertex3f(-155,115,5);
	glEnd();
	
	//lineloop gedung2 atap2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65,115,-90);
	glVertex3f(-70,111,-85);
	glVertex3f(-70,111,0);
	glVertex3f(-65,115,5);
	glEnd();

	//lineloop gedung3 atap1 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 95, 107, 0);
	glVertex3f( 95, 101, 0);
	glVertex3f( 170,101, 0);
	glVertex3f( 170,107, 0);
	glEnd();
	
	//lineloop gedung3 atap1 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 95, 107, -85);
	glVertex3f( 95, 101, -85);
	glVertex3f( 170,101, -85);
	glVertex3f( 170,107, -85);
	glEnd();

	//lineloop gedung3 atap1 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 170, 107, 0);
	glVertex3f( 170, 101, 0);
	glVertex3f( 170, 101,-85);
	glVertex3f( 170, 107,-85);
	glEnd();

	//lineloop gedung3 atap1 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 95, 107, 0);
	glVertex3f( 95, 101, 0);
	glVertex3f( 95, 101,-85);
	glVertex3f( 95, 107,-85);
	glEnd();

	//lineloop gedung3 atap2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 90,115,5);
	glVertex3f( 95 ,111,0);
	glVertex3f( 170, 111, 0);
	glVertex3f( 175,115,5);
	glEnd();

	//lineloop gedung3 atap2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 90,115,-90);
	glVertex3f( 95 ,111,-85);
	glVertex3f( 170, 111,-85);
	glVertex3f( 175,115,-90);
	glEnd();

	//lineloop gedung3 atap2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 90,115,-90);
	glVertex3f( 95 ,111,-85);
	glVertex3f( 95, 111, 0);
	glVertex3f( 90,115,5);
	glEnd();

	//lineloop gedung3 atap2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 175,115,-90);
	glVertex3f( 170 ,111,-85);
	glVertex3f( 170, 111, 0);
	glVertex3f( 175,115,5);
	glEnd();

	//lineloop gedung4 atap2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-51, 132,-7);
	glVertex3f(-51, 127,-7);
	glVertex3f(-21, 127,-7);
	glVertex3f(-21, 132,-7);
	glEnd();

	//lineloop gedung4 atap2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65, 132,-78);
	glVertex3f(-65, 127,-78);
	glVertex3f(-21, 127,-78);
	glVertex3f(-21, 132,-78);
	glEnd();

	//lineloop gedung4 atap2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-21, 132,-7);
	glVertex3f(-21, 127,-7);
	glVertex3f(-21, 127,-78);
	glVertex3f(-21, 132,-78);
	glEnd();

	//lineloop gedung4 atap2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65, 132,-78);
	glVertex3f(-65, 127,-78);
	glVertex3f(-65, 127,-26);
	glVertex3f(-65, 132,-26);
	glEnd();

	//lineloop gedung4 atap2 kiri depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65, 132,-26);
	glVertex3f(-65, 127,-26);
	glVertex3f(-51, 127,-7);
	glVertex3f(-51, 132,-7);
	glEnd();

	//lineloop atap segitiga gedung4
	//depan
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-51,132,-7);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-21,132,-7);
	glVertex3f(-36,150,-35.5);
	glEnd();
	//belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65,132,-78);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-21,132,-78);
	glVertex3f(-36,150,-35.5);
	glEnd();
	//samping kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65,132,-26);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-51,132,-7);
	glEnd();
	//kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-21,132,-7);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-21,132,-78);
	glEnd();
	//kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-65,132,-78);
	glVertex3f(-36,150,-35.5);
	glVertex3f(-65,132,-26);
	glEnd();

	//lineloop gedung5 atap2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 46, 132,-7);
	glVertex3f( 46, 127,-7);
	glVertex3f( 74, 127,-7);
	glVertex3f( 74, 132,-7);
	glEnd();

	//lineloop gedung5 atap2 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f( 46, 132,-78);
	glVertex3f( 46, 127,-78);
	glVertex3f( 90, 127,-78);
	glVertex3f( 90, 132,-78);
	glEnd();

	//lineloop gedung5 atap2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 46, 132,-78);
	glVertex3f( 46, 127,-78);
	glVertex3f( 46, 127,-7);
	glVertex3f( 46, 132,-7);
	glEnd();

	//lineloop gedung5 atap2 samping kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 74, 132,-7);
	glVertex3f( 74, 127,-7);
	glVertex3f( 90, 127,-26);
	glVertex3f( 90, 132,-26);
	glEnd();
	
	//lineloop gedung5 atap2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 90, 132,-26);
	glVertex3f( 90, 127,-26);
	glVertex3f( 90, 127,-78);
	glVertex3f( 90, 132,-78);
	glEnd();

	//lineloop atap segitiga gedung5 depan
	//depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(46,132,-7);
	glVertex3f(60,150,-35.5);
	glVertex3f(74,132,-7);
	glEnd();
	//belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(46,132,-78);
	glVertex3f(60,150,-35.5);
	glVertex3f(90,132,-78);
	glEnd();
	//kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(46,132,-78);
	glVertex3f(60,150,-35.5);
	glVertex3f(46,132,-7);
	glEnd();
	//kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(90,132,-78);
	glVertex3f(60,150,-35.5);
	glVertex3f(90,132,-26);
	glEnd();
	//kanan samping
	glBegin(GL_LINE_LOOP);
	glVertex3f(74,132,-7);
	glVertex3f(60,150,-35.5);
	glVertex3f(90,132,-26);
	glEnd();

	//lineloop garis atas gedung2
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3f(-130,47,-4);
	glVertex3f(-95, 47,-4);
	glVertex3f(-95, 53,-4);
	glVertex3f(-130,53,-4);
	
	glEnd();

	//lineloop garis tengah gedung2
	glBegin(GL_LINE_LOOP);
	glVertex3f(-130,-7,-4);
	glVertex3f(-95, -7,-4);
	glVertex3f(-95, -13,-4);
	glVertex3f(-130,-13,-4);
	
	glEnd();

	//lineloop garis bawah gedung2
	glBegin(GL_LINE_LOOP);
	glVertex3f(-130,-47,-4);
	glVertex3f(-95, -47,-4);
	glVertex3f(-95, -53,-4);
	glVertex3f(-130,-53,-4);
	glEnd();

	
	//lineloop garis tegak kiri gedung2
	glBegin(GL_LINE_LOOP);
	glVertex3f(-120, 101,-4);
	glVertex3f(-120,-110,-4);
	glVertex3f(-125,-110,-4);
	glVertex3f(-125, 101,-4);
	glEnd();

	//lineloop garis tegak kanan gedung2
	glBegin(GL_LINE_LOOP);
	glVertex3f(-107, 101,-4);
	glVertex3f(-107, -110,-4);
	glVertex3f(-102,-110,-4);
	glVertex3f(-102, 101,-4);
	glEnd();

	//lineloop garis mendatar atas gedung3
	glBegin(GL_LINE_LOOP);
	glVertex3f(110,47,-4);
	glVertex3f(150, 47,-4);
	glVertex3f(150, 53,-4);
	glVertex3f(110,53,-4);
	
	glEnd();

	//lineloop garis tengah gedung3
	glBegin(GL_LINE_LOOP);
	glVertex3f(110,-7,-4);
	glVertex3f(150, -7,-4);
	glVertex3f(150, -13,-4);
	glVertex3f(110,-13,-4);
	
	glEnd();

	//lineloop garis bawah gedung3
	glBegin(GL_LINE_LOOP);
	glVertex3f(110,-47,-4);
	glVertex3f(150, -47,-4);
	glVertex3f(150, -53,-4);
	glVertex3f(110,-53,-4);
	glEnd();

	//lineloop garis tegak kiri gedung3
	glBegin(GL_LINE_LOOP);
	glVertex3f( 120, 101,-4);
	glVertex3f( 120,-110,-4);
	glVertex3f( 125,-110,-4);
	glVertex3f( 125, 101,-4);
	glEnd();

	//lineloop garis tegak kanan gedung3
	glBegin(GL_LINE_LOOP);
	glVertex3f( 133, 101,-4);
	glVertex3f( 133, -110,-4);
	glVertex3f( 138,-110,-4);
	glVertex3f( 138, 101,-4);
	glEnd();

	//lineloop garis mendatar atas gedung5
	glBegin(GL_LINE_LOOP);
	glVertex3f( 49,47,-9);
	glVertex3f( 74, 47,-9);
	glVertex3f( 74, 53,-9);
	glVertex3f( 49,53,-9);
	
	glEnd();

	//lineloop garis bawah gedung5
	glBegin(GL_LINE_LOOP);
	glVertex3f( 49,-7,-9);
	glVertex3f( 74, -7,-9);
	glVertex3f( 74, -13,-9);
	glVertex3f( 49,-13,-9);
	glEnd();

	//lineloop garis tegak kiri gedung4
	glBegin(GL_LINE_LOOP);
	glVertex3f( -44, 115,-9);
	glVertex3f( -44,-50,-9);
	glVertex3f( -39,-50,-9);
	glVertex3f( -39, 115,-9);
	glEnd();

	//lineloop garis tegak kanan gedung4
	glBegin(GL_LINE_LOOP);
	glVertex3f( -34, 115,-9);
	glVertex3f( -34, -50,-9);
	glVertex3f( -29,-50,-9);
	glVertex3f( -29, 115,-9);
	glEnd();

	//lineloop garis tegak kiri gedung5
	glBegin(GL_LINE_LOOP);
	glVertex3f(  54, 115,-9);
	glVertex3f(  54,-50,-9);
	glVertex3f(  59,-50,-9);
	glVertex3f(  59, 115,-9);
	glEnd();

	//lineloop garis tegak kanan gedung4
	glBegin(GL_LINE_LOOP);
	glVertex3f(  64, 115,-9);
	glVertex3f(  64, -50,-9);
	glVertex3f(  69,-50,-9);
	glVertex3f(  69, 115,-9);
	glEnd();

	//lineloop pintu gedung1 depan
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-24,-110,-4);
	glVertex3f(-24,-60,-4);
	glVertex3f( 41,-60,-4);
	glVertex3f( 41,-110,-4);
	glEnd();

	//lineloop garis tegak kiri gedung1
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex3f( -45, -50,-4);
	glVertex3f( -45,-110,-4);
	glVertex3f( -40,-110,-4);
	glVertex3f( -40, -50,-4);
	glEnd();

	//garis tegak kanan gedung1
	glBegin(GL_LINE_LOOP);
	glVertex3f( -35, -50,-4);
	glVertex3f( -35,-110,-4);
	glVertex3f( -30,-110,-4);
	glVertex3f( -30, -50,-4);
	glEnd();

	//garis mendatar atas gedung1
	glBegin(GL_LINE_LOOP);
	glVertex3f( -50,-60,-4);
	glVertex3f( -24,-60,-4);
	glVertex3f( -24,-66,-4);
	glVertex3f( -50,-66,-4);
	
	glEnd();

	//garis mendatar bawah gedung1
	glBegin(GL_LINE_LOOP);
	glVertex3f( -50,-80,-4);
	glVertex3f( -24,-80,-4);
	glVertex3f( -24,-86,-4);
	glVertex3f( -50,-86,-4);
	
	glEnd();

	//lineloop garis mendatar atas gedung1 kanan pintu
	glBegin(GL_LINE_LOOP);
	glVertex3f(  41,-60,-4);
	glVertex3f(  75,-60,-4);
	glVertex3f(  75,-66,-4);
	glVertex3f(  41,-66,-4);
	
	glEnd();

	//lineloop garis mendatar bawah gedung1 kanan pintu
	glBegin(GL_LINE_LOOP);
	glVertex3f(  41,-80,-4);
	glVertex3f(  75,-80,-4);
	glVertex3f(  75,-86,-4);
	glVertex3f(  41,-86,-4);
	
	glEnd();

	//lineloop garis tegak kiri gedung1 kanan pintu
	glBegin(GL_LINE_LOOP);
	glVertex3f(  54, -50,-4);
	glVertex3f(  54,-110,-4);
	glVertex3f(  59,-110,-4);
	glVertex3f(  59, -50,-4);
	glEnd();

	//lineloop garis tegak kanan gedung1 kanan pintu
	glBegin(GL_LINE_LOOP);
	glVertex3f(  64, -50,-4);
	glVertex3f(  64,-110,-4);
	glVertex3f(  69,-110,-4);
	glVertex3f(  69, -50,-4);
	glEnd();

	//lineloop gedung6 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-19,-50,-10);
	glVertex3f(44,-50,-10);
	glVertex3f(44, 300,-10);
	glVertex3f(-19,300,-10);
	glEnd();

	//lineloop gedung6 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-19,-50,-75);
	glVertex3f(44,-50,-75);
	glVertex3f(44, 300,-75);
	glVertex3f(-19,300,-75);
	glEnd();

	//lineloop gedung6 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(44,-50,-10);
	glVertex3f(44,-50,-75);
	glVertex3f(44, 300,-75);
	glVertex3f(44, 300,-10);
	glEnd();

	//lineloop gedung6 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-19,-50,-10);
	glVertex3f(-19,-50,-75);
	glVertex3f(-19, 300,-75);
	glVertex3f(-19, 300,-10);
	glEnd();

	//lineloop garis gedung 6 #1
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3f(-9, 250, -8);
	glVertex3f(-9, -50, -8);
	glVertex3f(-4, -50, -8);
	glVertex3f(-4, 250, -8);
	glEnd();

	//lineloop garis gedung 6 #2
	glBegin(GL_LINE_LOOP);
	glVertex3f( 1, 250, -8);
	glVertex3f( 1, -50, -8);
	glVertex3f( 6, -50, -8);
	glVertex3f( 6, 250, -8);
	glEnd();

	//lineloop garis gedung 6 #3
	glBegin(GL_LINE_LOOP);
	glVertex3f( 11, 250, -8);
	glVertex3f( 11, -50, -8);
	glVertex3f( 16, -50, -8);
	glVertex3f( 16, 250, -8);
	glEnd();


	//lineloop garis gedung 6 #4
	glBegin(GL_LINE_LOOP);
	glVertex3f( 21, 250, -8);
	glVertex3f( 21, -50, -8);
	glVertex3f( 26, -50, -8);
	glVertex3f( 26, 250, -8);
	glEnd();

	//lineloop garis gedung 6 #5
	glBegin(GL_LINE_LOOP);
	glVertex3f( 31, 250, -8);
	glVertex3f( 31, -50, -8);
	glVertex3f( 36, -50, -8);
	glVertex3f( 36, 250, -8);
	glEnd();

	//lineloop garis gedung6 mendatar #1
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,225,-7);
	glVertex3f(39,225,-7);
	glVertex3f(39,215,-7);
	glVertex3f(-14,215,-7);
	glEnd();


	//lineloop garis gedung6 mendatar #2
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,190,-7);
	glVertex3f(39,190,-7);
	glVertex3f(39,180,-7);
	glVertex3f(-14,180,-7);
	glEnd();

	//lineloop garis gedung6 mendatar #3
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,165,-7);
	glVertex3f(39,165,-7);
	glVertex3f(39,155,-7);
	glVertex3f(-14,155,-7);
	glEnd();


	//lineloop garis gedung6 mendatar #4
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,130,-7);
	glVertex3f(39,130,-7);
	glVertex3f(39,120,-7);
	glVertex3f(-14,120,-7);
	glEnd();

	//lineloop garis gedung6 mendatar #5
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,95,-7);
	glVertex3f(39,95,-7);
	glVertex3f(39,85,-7);
	glVertex3f(-14,85,-7);
	glEnd();


	//lineloop garis gedung6 mendatar #6
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,60,-7);
	glVertex3f(39,60,-7);
	glVertex3f(39,50,-7);
	glVertex3f(-14,50,-7);
	glEnd();


	//lineloop garis gedung6 mendatar #7
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,25,-7);
	glVertex3f(39,25,-7);
	glVertex3f(39,15,-7);
	glVertex3f(-14,15,-7);
	glEnd();

	//lineloop garis gedung6 mendatar #8
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,-10,-7);
	glVertex3f(39,-10,-7);
	glVertex3f(39,-20,-7);
	glVertex3f(-14,-20,-7);
	glEnd();

	//lineloop garis gedung 6 coklat atas #1
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9, 300, -8);
	glVertex3f(-9, 250, -8);
	glVertex3f(-4, 250, -8);
	glVertex3f(-4, 300, -8);
	glEnd();

	//lineloop garis gedung 6 coklat atas #2
	glBegin(GL_LINE_LOOP);
	glVertex3f( 1, 300, -8);
	glVertex3f( 1, 250, -8);
	glVertex3f( 6, 250, -8);
	glVertex3f( 6, 300, -8);
	glEnd();

	//lineloop garis gedung 6 coklat atas #3
	glBegin(GL_LINE_LOOP);
	glVertex3f( 11, 300, -8);
	glVertex3f( 11, 250, -8);
	glVertex3f( 16, 250, -8);
	glVertex3f( 16, 300, -8);
	glEnd();


	//lineloop garis gedung 6 coklat atas #4
	glBegin(GL_LINE_LOOP);
	glVertex3f( 21, 300, -8);
	glVertex3f( 21, 250, -8);
	glVertex3f( 26, 250, -8);
	glVertex3f( 26, 300, -8);
	glEnd();

	//lineloop garis gedung 6 coklat atas #5
	glBegin(GL_LINE_LOOP);
	glVertex3f( 31, 300, -8);
	glVertex3f( 31, 250, -8);
	glVertex3f( 36, 250, -8);
	glVertex3f( 36, 300, -8);
	glEnd();

	//lineloop pucuk gedung6 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,330,-15);
	glVertex3f(39,330,-15);
	glVertex3f(39,300,-15);
	glVertex3f(-14,300,-15);
	glEnd();

	//lineloop pucuk gedung6 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,330,-70);
	glVertex3f(39,330,-70);
	glVertex3f(39,300,-70);
	glVertex3f(-14,300,-70);
	glEnd();

	//lineloop pucuk gedung6 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(39,330,-15);
	glVertex3f(39,330,-70);
	glVertex3f(39,300,-70);
	glVertex3f(39,300,-15);
	glEnd();

	//lineloop pucuk gedung6 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-14,330,-15);
	glVertex3f(-14,330,-70);
	glVertex3f(-14,300,-70);
	glVertex3f(-14,300,-15);
	glEnd();

	//lineloop segitiga atas gedung6 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,330,-20);
	glVertex3f(-9,335,-20);
	glVertex3f(34,335,-20);
	glVertex3f(34,330,-20);
	glEnd();
	
	//lineloop segitiga atas gedung6 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,330,-25);
	glVertex3f(-9,335,-25);
	glVertex3f(34,335,-25);
	glVertex3f(34,330,-25);
	glEnd();

	//lineloop segitiga atas gedung6 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,330,-25);
	glVertex3f(-9,335,-25);
	glVertex3f(-9,335,-20);
	glVertex3f(-9,330,-20);
	glEnd();

	//lineloop segitiga atas gedung6 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(34,330,-25);
	glVertex3f(34,335,-25);
	glVertex3f(34,335,-20);
	glVertex3f(34,330,-20);
	glEnd();

	//lineloop segitiga gedung6 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,338,-20);
	glVertex3f(12,360,-22.5);
	glVertex3f(34,338,-20);
	glEnd();

	//lineloop segitiga gedung6 belakang
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,338,-25);
	glVertex3f(12,360,-22.5);
	glVertex3f(34,338,-25);
	
	glEnd();

	//lineloop kotak depan belakang segitiga
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,330,-30);
	glVertex3f(-9,370,-30);
	glVertex3f(34,370,-30);
	glVertex3f(34,330,-30);
	glEnd();
	
	//lineloop kotak belakang belakang segitiga
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,330,-65);
	glVertex3f(-9,370,-65);
	glVertex3f(34,370,-65);
	glVertex3f(34,330,-65);
	glEnd();

	//lineloop kotak depan kiri segitiga
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,330,-30);
	glVertex3f(-9,370,-30);
	glVertex3f(-9,370,-65);
	glVertex3f(-9,330,-65);
	glEnd();

	//lineloop kotak depan kanan segitiga
	glBegin(GL_LINE_LOOP);
	glVertex3f(34,330,-30);
	glVertex3f(34,370,-30);
	glVertex3f(34,370,-65);
	glVertex3f(34,330,-65);
	glEnd();

	//lineloop penutup tembok2 lift sisi kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,-70,-69);
	glVertex3f(-9,-70,-79);
	glVertex3f(-9,-110,-79);
	glVertex3f(-9,-110,-69);
	glEnd();

	//lineloop penutup tembok2 lift sisi kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(26,-70,-69);
	glVertex3f(26,-70,-79);
	glVertex3f(26,-110,-79);
	glVertex3f(26,-110,-69);
	glEnd();

	//lineloop penutup tembok2 lift sisi atas
	glBegin(GL_LINE_LOOP);
	glVertex3f(-9,-70,-69);
	glVertex3f(-9,-70,-79);
	glVertex3f(26,-70,-79);
	glVertex3f(26,-70,-69);
	glEnd();

	//lineloop meja gedung2 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-125,-95,-79);
	glVertex3f(-125,-110,-79);
	glVertex3f(-125,-110,-70);
	glVertex3f(-125,-95,-70);
	glEnd();

	//lineloop meja gedung2 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-100,-95,-79);
	glVertex3f(-100,-110,-79);
	glVertex3f(-100,-110,-70);
	glVertex3f(-100,-95,-70);
	glEnd();

	//lineloop meja gedung2 samping kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-125,-95,-70);
	glVertex3f(-125,-110,-70);
	glVertex3f(-120,-110,-65);
	glVertex3f(-120,-95,-65);
	glEnd();

	//lineloop meja gedung2 samping kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-100,-95,-70);
	glVertex3f(-100,-110,-70);
	glVertex3f(-105,-110,-65);
	glVertex3f(-105,-95,-65);
	glEnd();

	//lineloop meja gedung2 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-120,-95,-65);
	glVertex3f(-120,-110,-65);
	glVertex3f(-105,-110,-65);
	glVertex3f(-105,-95,-65);
	glEnd();

	//lineloop meja gedung3 kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 120,-95,-79);
	glVertex3f( 120,-110,-79);
	glVertex3f( 120,-110,-70);
	glVertex3f( 120,-95,-70);
	glEnd();

	//lineloop meja gedung3 kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 145,-95,-79);
	glVertex3f( 145,-110,-79);
	glVertex3f( 145,-110,-70);
	glVertex3f( 145,-95,-70);
	glEnd();

	//lineloop meja gedung3 samping kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 120,-95,-70);
	glVertex3f( 120,-110,-70);
	glVertex3f( 125,-110,-65);
	glVertex3f( 125,-95,-65);
	glEnd();

	//lineloop meja gedung3 samping kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 145,-95,-70);
	glVertex3f( 145,-110,-70);
	glVertex3f( 140,-110,-65);
	glVertex3f( 140,-95,-65);
	glEnd();

	//lineloop meja gedung3 depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 125,-95,-65);
	glVertex3f( 125,-110,-65);
	glVertex3f( 140,-110,-65);
	glVertex3f( 140,-95,-65);
	glEnd();

	//lineloop kursi sendehan belakang 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -98, -40);
	glVertex3f(-143, -105, -40);
	glVertex3f(-143, -105, -70);
	glVertex3f(-143, -98, -70);
	glEnd();

	//lineloop kursi sendehan depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-141, -98, -40);
	glVertex3f(-141, -105, -40);
	glVertex3f(-141, -105, -70);
	glVertex3f(-141, -98, -70);
	glEnd();

	//lineloop kursi sendehan kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -98, -70);
	glVertex3f(-143, -105, -70);
	glVertex3f(-141, -105, -70);
	glVertex3f(-141, -98, -70);
	glEnd();

	//lineloop kursi sendehan kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -98, -40);
	glVertex3f(-143, -105, -40);
	glVertex3f(-141, -105, -40);
	glVertex3f(-141, -98, -40);
	glEnd();

	//lineloop kursi sendehan atas
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -98, -40);
	glVertex3f(-143, -98, -70);
	glVertex3f(-141, -98, -70);
	glVertex3f(-141, -98, -40);
	glEnd();

	//lineloop kursi sendehan bawah
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -40);
	glVertex3f(-143, -105, -70);
	glVertex3f(-141, -105, -70);
	glVertex3f(-141, -105, -40);
	glEnd();

	//lineloop kursi alas bawah
	glBegin(GL_LINE_LOOP);
	glVertex3f(-141, -105, -40);
	glVertex3f(-136, -105, -40);
	glVertex3f(-136, -105, -70);
	glVertex3f(-141, -105, -70);
	glEnd();

	//lineloop kursi alas atas
	glBegin(GL_LINE_LOOP);
	glVertex3f(-141, -103, -40);
	glVertex3f(-136, -103, -40);
	glVertex3f(-136, -103, -70);
	glVertex3f(-141, -103, -70);
	glEnd();

	//lineloop kursi alas depan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-136, -103, -40);
	glVertex3f(-136, -105, -40);
	glVertex3f(-136, -105, -70);
	glVertex3f(-136, -103, -70);
	glEnd();

	//lineloop kursi alas kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f(-141, -103, -40);
	glVertex3f(-141, -105, -40);
	glVertex3f(-136, -105, -40);
	glVertex3f(-136, -103, -40);
	glEnd();

	//lineloop kursi alas kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f(-141, -103, -70);
	glVertex3f(-141, -105, -70);
	glVertex3f(-136, -105, -70);
	glVertex3f(-136, -103, -70);
	glEnd();
	
	//lineloop kaki kursi kiri#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -41);
	glVertex3f(-143, -110, -41);
	glVertex3f(-142, -110, -41);
	glVertex3f(-142, -105, -41);
	glEnd();

	//lineloop kaki kursi kanan#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -42);
	glVertex3f(-143, -110, -42);
	glVertex3f(-142, -110, -42);
	glVertex3f(-142, -105, -42);
	glEnd();

	//lineloop kaki kursi depan#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-142, -105, -41);
	glVertex3f(-142, -110, -41);
	glVertex3f(-142, -110, -42);
	glVertex3f(-142, -105, -42);
	glEnd();

	//lineloop kaki kursi belakang#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -41);
	glVertex3f(-143, -110, -41);
	glVertex3f(-143, -110, -42);
	glVertex3f(-143, -105, -42);
	glEnd();

	//lineloop kaki kursi kiri#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -68);
	glVertex3f(-143, -110, -68);
	glVertex3f(-142, -110, -68);
	glVertex3f(-142, -105, -68);
	glEnd();

	//lineloop kaki kursi kanan#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -69);
	glVertex3f(-143, -110, -69);
	glVertex3f(-142, -110, -69);
	glVertex3f(-142, -105, -69);
	glEnd();

	//lineloop kaki kursi depan#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-142, -105, -68);
	glVertex3f(-142, -110, -68);
	glVertex3f(-142, -110, -69);
	glVertex3f(-142, -105, -69);
	glEnd();

	//lineloop kaki kursi belakang#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-143, -105, -68);
	glVertex3f(-143, -110, -68);
	glVertex3f(-143, -110, -69);
	glVertex3f(-143, -105, -69);
	glEnd();

	//lineloop kaki kursi kiri#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-137, -105, -68);
	glVertex3f(-137, -110, -68);
	glVertex3f(-136, -110, -68);
	glVertex3f(-136, -105, -68);
	glEnd();

	//lineloop kaki kursi depan#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-136, -105, -68);
	glVertex3f(-136, -110, -68);
	glVertex3f(-136, -110, -69);
	glVertex3f(-136, -105, -69);
	glEnd();

	//lineloop kaki kursi belakang#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-137, -105, -68);
	glVertex3f(-137, -110, -68);
	glVertex3f(-137, -110, -69);
	glVertex3f(-137, -105, -69);
	glEnd();

	//lineloop kaki kursi kanan#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-137, -105, -69);
	glVertex3f(-137, -110, -69);
	glVertex3f(-136, -110, -69);
	glVertex3f(-136, -105, -69);
	glEnd();

	//lineloop kaki kursi kiri#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-137, -105, -41);
	glVertex3f(-137, -110, -41);
	glVertex3f(-136, -110, -41);
	glVertex3f(-136, -105, -41);
	glEnd();

	//lineloop kaki kursi kanan#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-137, -105, -42);
	glVertex3f(-137, -110, -42);
	glVertex3f(-136, -110, -42);
	glVertex3f(-136, -105, -42);
	glEnd();

	//lineloop kaki kursi belakang#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-137, -105, -41);
	glVertex3f(-137, -110, -41);
	glVertex3f(-137, -110, -42);
	glVertex3f(-137, -105, -42);
	glEnd();

	//lineloop kaki kursi depan#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f(-136, -105, -41);
	glVertex3f(-136, -110, -41);
	glVertex3f(-136, -110, -42);
	glVertex3f(-136, -105, -42);
	glEnd();

	//lineloop kursi sendehan belakang 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -98, -40);
	glVertex3f( 102, -105, -40);
	glVertex3f( 102, -105, -70);
	glVertex3f( 102, -98, -70);
	glEnd();

	//lineloop kursi sendehan depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 104, -98, -40);
	glVertex3f( 104, -105, -40);
	glVertex3f( 104, -105, -70);
	glVertex3f( 104, -98, -70);
	glEnd();

	//lineloop kursi sendehan kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -98, -70);
	glVertex3f( 102, -105, -70);
	glVertex3f( 104, -105, -70);
	glVertex3f( 104, -98, -70);
	glEnd();

	//lineloop kursi sendehan kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -98, -40);
	glVertex3f( 102, -105, -40);
	glVertex3f( 104, -105, -40);
	glVertex3f( 104, -98, -40);
	glEnd();

	//lineloop kursi sendehan atas
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -98, -40);
	glVertex3f( 102, -98, -70);
	glVertex3f( 104, -98, -70);
	glVertex3f( 104, -98, -40);
	glEnd();

	//lineloop kursi sendehan bawah
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -40);
	glVertex3f( 102, -105, -70);
	glVertex3f( 104, -105, -70);
	glVertex3f( 104, -105, -40);
	glEnd();

	//lineloop kursi alas bawah
	glBegin(GL_LINE_LOOP);
	glVertex3f( 104, -105, -40);
	glVertex3f( 109, -105, -40);
	glVertex3f( 109, -105, -70);
	glVertex3f( 104, -105, -70);
	glEnd();

	//lineloop kursi alas atas
	glBegin(GL_LINE_LOOP);
	glVertex3f( 104, -103, -40);
	glVertex3f( 109, -103, -40);
	glVertex3f( 109, -103, -70);
	glVertex3f( 104, -103, -70);
	glEnd();

	//lineloop kursi alas depan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 109, -103, -40);
	glVertex3f( 109, -105, -40);
	glVertex3f( 109, -105, -70);
	glVertex3f( 109, -103, -70);
	glEnd();

	//lineloop kursi alas kiri
	glBegin(GL_LINE_LOOP);
	glVertex3f( 104, -103, -40);
	glVertex3f( 104, -105, -40);
	glVertex3f( 109, -105, -40);
	glVertex3f( 109, -103, -40);
	glEnd();

	//lineloop kursi alas kanan
	glBegin(GL_LINE_LOOP);
	glVertex3f( 104, -103, -70);
	glVertex3f( 104, -105, -70);
	glVertex3f( 109, -105, -70);
	glVertex3f( 109, -103, -70);
	glEnd();

	//lineloop kaki kursi kiri#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -41);
	glVertex3f( 102, -110, -41);
	glVertex3f( 103, -110, -41);
	glVertex3f( 103, -105, -41);
	glEnd();

	//lineloop kaki kursi kanan#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -42);
	glVertex3f( 102, -110, -42);
	glVertex3f( 103, -110, -42);
	glVertex3f( 103, -105, -42);
	glEnd();

	//lineloop kaki kursi depan#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 103, -105, -41);
	glVertex3f( 103, -110, -41);
	glVertex3f( 103, -110, -42);
	glVertex3f( 103, -105, -42);
	glEnd();

	//lineloop kaki kursi belakang#1 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -41);
	glVertex3f( 102, -110, -41);
	glVertex3f( 102, -110, -42);
	glVertex3f( 102, -105, -42);
	glEnd();

	//lineloop kaki kursi kiri#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -68);
	glVertex3f( 102, -110, -68);
	glVertex3f( 103, -110, -68);
	glVertex3f( 103, -105, -68);
	glEnd();

	//lineloop kaki kursi kanan#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -69);
	glVertex3f( 102, -110, -69);
	glVertex3f( 103, -110, -69);
	glVertex3f( 103, -105, -69);
	glEnd();

	//lineloop kaki kursi depan#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 103, -105, -68);
	glVertex3f( 103, -110, -68);
	glVertex3f( 103, -110, -69);
	glVertex3f( 103, -105, -69);
	glEnd();

	//lineloop kaki kursi belakang#2 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 102, -105, -68);
	glVertex3f( 102, -110, -68);
	glVertex3f( 102, -110, -69);
	glVertex3f( 102, -105, -69);
	glEnd();

	//lineloop kaki kursi kiri#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 108, -105, -68);
	glVertex3f( 108, -110, -68);
	glVertex3f( 109, -110, -68);
	glVertex3f( 109, -105, -68);
	glEnd();

	//lineloop kaki kursi depan#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 109, -105, -68);
	glVertex3f( 109, -110, -68);
	glVertex3f( 109, -110, -69);
	glVertex3f( 109, -105, -69);
	glEnd();

	//lineloop kaki kursi belakang#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 108, -105, -68);
	glVertex3f( 108, -110, -68);
	glVertex3f( 108, -110, -69);
	glVertex3f( 108, -105, -69);
	glEnd();

	//lineloop kaki kursi kanan#3 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 108, -105, -69);
	glVertex3f( 108, -110, -69);
	glVertex3f( 109, -110, -69);
	glVertex3f( 109, -105, -69);
	glEnd();

	//lineloop kaki kursi kiri#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 108, -105, -41);
	glVertex3f( 108, -110, -41);
	glVertex3f (109, -110, -41);
	glVertex3f( 109, -105, -41);
	glEnd();

	//lineloop kaki kursi kanan#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 108, -105, -42);
	glVertex3f( 108, -110, -42);
	glVertex3f( 109, -110, -42);
	glVertex3f( 109, -105, -42);
	glEnd();

	//lineloop kaki kursi belakang#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 108, -105, -41);
	glVertex3f( 108, -110, -41);
	glVertex3f( 108, -110, -42);
	glVertex3f( 108, -105, -42);
	glEnd();

	//lineloop kaki kursi depan#4 
	glBegin(GL_LINE_LOOP);
	glVertex3f( 109, -105, -41);
	glVertex3f( 109, -110, -41);
	glVertex3f( 109, -110, -42);
	glVertex3f( 109, -105, -42);
	glEnd();



	glFlush();
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{	
		//zoom in
		case 'w':
		case 'W':
		zpos += 2.0;
		glTranslatef(0.0, 0.0, 2.0);
		break;
		//gerak kiri
		case 'a':
		case 'A':
		xpos += -2.0;
		glTranslatef(-2.0, 0.0, 0.0);
		break;
		//zoom out
		case 's':
		case 'S':
		zpos += -2.0;
		glTranslatef(0.0, 0.0, -2.0);
		break;
		//gerak kanan
		case 'd':
		case 'D':
		xpos += 2.0;
		glTranslatef(2.0, 0.0, 0.0);
		break;
		//gerak ke atas
		case 'q':
		case 'Q':
			glTranslatef(0.0, 2.0, 0.0);
			ypos += 2.0;
			break;
		//gerak bawah
		case 'E':
		case 'e':
		
			glTranslatef(0.0,-2.0,0.0);
			ypos += -2.0;
			break;

		//rotate ke kanan
		case 'l':
		case 'L':
			glRotatef(1.0, 0.0, 4.0, 0.0);
			yrot += 4.0;
			break;

		//rotate ke kiri
		case 'j' :
		case 'J' :
			glRotatef(1.0, 0.0, -4.0, 0.0);
			yrot += -4.0;
			break;

		case 'f':
		if (is_depth)
		{
			is_depth =0;
			glDisable(GL_DEPTH_TEST);
		} else
		{
			is_depth=1;
			glEnable(GL_DEPTH_TEST);
		}
		break;
	}
	tampil();
}

void idle()
{

	if (!mouseDown)
	{
		xrot += 0.1f;
		yrot += 0.2f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{

	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

	glutPostRedisplay();

	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glViewport(0, 0, lebar, tinggi);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 900.0);
	glTranslatef(0.0, -50.0, -300.0);
	glMatrixMode(GL_MODELVIEW);
}
