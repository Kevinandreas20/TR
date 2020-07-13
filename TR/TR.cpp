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
int is_depth,x,y,z;
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
	glutCreateWindow("TUGAS AKHIR - GRAFIKA KOMPUTER");
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
	
	//alas bawah
	glColor3f(79/255.f,189/255.f,4/255.f);
	glVertex3f(-200,-110,50);
	glVertex3f(-200,-110,-200);
	glVertex3f(200,-110,-200);
	glVertex3f(200,-110,50);
	
	//gedung1 depan
	glColor3f(1,0,0);
	glVertex3f(-50,-110,-5);
	glVertex3f(-50,-50,-5);
	glVertex3f(75,-50,-5);
	glVertex3f(75,-110,-5);
	
	//gedung1 atas
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
	
	//gedung2 depan
	glVertex3f(-130,-110,-5);
	glVertex3f(-130,101,-5);
	glVertex3f(-95, 101,-5);
	glVertex3f(-95,-110,-5);
	
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

	//gedung2 kanan
	glVertex3f(-75, 101,-80);
	glVertex3f(-75,-110,-80);
	glVertex3f(-75,-110,-25);
	glVertex3f(-75, 101,-25);

	//gedung2 belakang
	glVertex3f(-145,-110,-80);
	glVertex3f(-145, 101,-80);
	glVertex3f(-75, 101,-80);
	glVertex3f(-75,-110,-80);
	
	//gedung2 atap1 bawah
	glColor3f(0,0,0);
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

	//gedung2();
	
	//gedung3 depan
	glColor3f(0,1,0);
	glVertex3f(110,-110,-5);
	glVertex3f(110, 101,-5);
	glVertex3f(150, 101,-5);
	glVertex3f(150,-110,-5);
		
	//gedung3 belakang
	glVertex3f(100,-110,-80);
	glVertex3f(100, 101,-80);
	glVertex3f(165, 101,-80);
	glVertex3f(165,-110,-80);

	//gedung3 kiri 
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
	
	glVertex3f(165,-110,-25);
	glVertex3f(165, 101,-25);
	glVertex3f(165, 101,-80);
	glVertex3f(165,-110,-80);

	//gedung3 atap1 bawah
	glColor3f(0,0,0);
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


	//gedung4 depan
	glColor3f(0,1,0);
	glVertex3f(-49,-50,-10);
	glVertex3f(-24,-50,-10);
	glVertex3f(-24, 115,-10);
	glVertex3f(-49, 115,-10);
	
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

	//gedung4 tiang1 depan
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
	glColor3f(0,1,0);
	glVertex3f( 49,-50,-10);
	glVertex3f( 74,-50,-10);
	glVertex3f( 74, 115,-10);
	glVertex3f( 49, 115,-10);

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
	glTranslatef(0.0, -50.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}