/*
* OGL01Shape3D.cpp: 3D Shapes
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

bool mouseDown = false;

void Inisialisasi(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glLoadIdentity();
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glScalef(20, 20, 20);

	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	glColor4f(1.0f, 1.0f, 0.0f, 0.5f);     // Red
	glVertex3f(1.0f, 1.0f, 1.5f);
	glVertex3f(-1.0f, 1.0f, 1.5f);
	glVertex3f(-1.0f, -1.0f, 1.5f);
	glVertex3f(1.0f, -1.0f, 1.5f);

	// Back face (z = -1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(1.0f, -1.0f, -1.5f);
	glVertex3f(-1.0f, -1.0f, -1.5f);
	glVertex3f(-1.0f, 1.0f, -1.5f);
	glVertex3f(1.0f, 1.0f, -1.5f);

	// Left face (x = -1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);     // Blue
	glVertex3f(-1.0f, 1.0f, 1.5f);
	glVertex3f(-1.0f, 1.0f, -1.5f);
	glVertex3f(-1.0f, -1.0f, -1.5f);
	glVertex3f(-1.0f, -1.0f, 1.5f);

	// Right face (x = 1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);     // Magenta
	glVertex3f(1.0f, 1.0f, -1.5f);
	glVertex3f(1.0f, 1.0f, 1.5f);
	glVertex3f(1.0f, -1.0f, 1.5f);
	glVertex3f(1.0f, -1.0f, -1.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);     // pagar depan 
	glVertex3f(2.0f, -1.0f, 3.0f);
	glVertex3f(2.0f, 0.5f, 3.0f);
	glVertex3f(-0.6f, 0.5f, 3.0f);
	glVertex3f(-0.6f, -1.0f, 3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // pagar depan kecil
	glVertex3f(-2.0f, -1.0f, 3.0f);
	glVertex3f(-2.0f, 0.05f, 3.0f);
	glVertex3f(-0.6f, 0.05f, 3.0f);
	glVertex3f(-0.6f, -1.0f, 3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);     // pagar depan kecil
	glVertex3f(-1.6f, -1.0f, 3.01f);
	glVertex3f(-1.5f, -1.0f, 3.01f);
	glVertex3f(-1.5f, 0.05f, 3.01f);
	glVertex3f(-1.6f, 0.05f, 3.01f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);     // pagar depan kecil
	glVertex3f(-1.6f, -1.0f, 2.99f);
	glVertex3f(-1.5f, -1.0f, 2.99f);
	glVertex3f(-1.5f, 0.05f, 2.99f);
	glVertex3f(-1.6f, 0.05f, 2.99f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);     // pegangan kiri pagar depan kecil
	glVertex3f(-1.65f, -0.6f, 3.01f);
	glVertex3f(-1.7f, -0.6f, 3.01f);
	glVertex3f(-1.7f, -0.4f, 3.01f);
	glVertex3f(-1.65f, -0.4f, 3.01f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);     // pegangan kiri pagar depan kecil
	glVertex3f(-1.65f, -0.6f, 2.99f);
	glVertex3f(-1.7f, -0.6f, 2.99f);
	glVertex3f(-1.7f, -0.4f, 2.99f);
	glVertex3f(-1.65f, -0.4f, 2.99f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);     // pegangan kiri pagar depan kecil
	glVertex3f(-1.45f, -0.6f, 3.01f);
	glVertex3f(-1.4f, -0.6f, 3.01f);
	glVertex3f(-1.4f, -0.4f, 3.01f);
	glVertex3f(-1.45f, -0.4f, 3.01f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);     // pegangan kiri pagar depan kecil
	glVertex3f(-1.45f, -0.6f, 2.99f);
	glVertex3f(-1.4f, -0.6f, 2.99f);
	glVertex3f(-1.4f, -0.4f, 2.99f);
	glVertex3f(-1.45f, -0.4f, 2.99f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);     // pagar belakang 
	glVertex3f(2.0f, -1.0f, -3.0f);
	glVertex3f(2.0f, 0.5f, -3.0f);
	glVertex3f(-2.0f, 0.5f, -3.0f);
	glVertex3f(-2.0f, -1.0f, -3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);     // pagar kanan 
	glVertex3f(2.0f, -1.0f, -3.0f);
	glVertex3f(2.0f, 0.5f, -3.0f);
	glVertex3f(2.0f, 0.5f, 3.0f);
	glVertex3f(2.0f, -1.0f, 3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);     // pagar kiri 
	glVertex3f(-2.0f, -1.0f, -3.0f);
	glVertex3f(-2.0f, 0.5f, -3.0f);
	glVertex3f(-2.0f, 0.5f, 3.0f);
	glVertex3f(-2.0f, -1.0f, 3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);     // bawah 
	glVertex3f(2.0f, -1.0f, 3.0f);
	glVertex3f(2.0f, -1.0f, -3.0f);
	glVertex3f(-2.0f, -1.0f, -3.0f);
	glVertex3f(-2.0f, -1.0f, 3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, 1.5f);
	glVertex3f(1.0f, -0.999f, -1.5f);
	glVertex3f(-1.0f, -0.999f, -1.5f);
	glVertex3f(-1.0f, -0.999f, 1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, 1.5f);
	glVertex3f(-1.0f, -0.999f, 1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, 1.0f);
	glVertex3f(-1.0f, -0.999f, 1.0f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, 0.5f);
	glVertex3f(-1.0f, -0.999f, 0.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, 0.0f);
	glVertex3f(-1.0f, -0.999f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, -0.5f);
	glVertex3f(-1.0f, -0.999f, -0.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah 
	glVertex3f(1.0f, -0.999f, -1.0f);
	glVertex3f(-1.0f, -0.999f, -1.0f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah horizontal
	glVertex3f(1.0f, -0.999f, -1.5f);
	glVertex3f(-1.0f, -0.999f, -1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah vertikal
	glVertex3f(1.0f, -0.999f, 1.5f);
	glVertex3f(1.0f, -0.999f, -1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah vertikal
	glVertex3f(0.5f, -0.999f, 1.5f);
	glVertex3f(0.5f, -0.999f, -1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah vertikal
	glVertex3f(0.0f, -0.999f, 1.5f);
	glVertex3f(0.0f, -0.999f, -1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah vertikal
	glVertex3f(-0.5f, -0.999f, 1.5f);
	glVertex3f(-0.5f, -0.999f, -1.5f);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);     // lantai bawah vertikal
	glVertex3f(-1.0f, -0.999f, 1.5f);
	glVertex3f(-1.0f, -0.999f, -1.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -1.0f, -1.3f);
	glVertex3f(-0.9f, -0.2f, -1.3f);
	glVertex3f(-0.9f, -0.2f, -1.2f);
	glVertex3f(-0.9f, -1.0f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.996f, -1.3f);
	glVertex3f(-0.9f, -0.2f, -1.3f);
	glVertex3f(-0.9f, -0.2f, -1.2f);
	glVertex3f(-0.9f, -0.996f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.8f, -1.0f, -1.3f);
	glVertex3f(-0.8f, -0.2f, -1.3f);
	glVertex3f(-0.8f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -1.0f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.8f, -0.996f, -1.3f);
	glVertex3f(-0.8f, -0.2f, -1.3f);
	glVertex3f(-0.8f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.996f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -1.0f, -1.2f);
	glVertex3f(-0.9f, -1.0f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.996f, -1.2f);
	glVertex3f(-0.9f, -0.996f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.2f, -1.3f);
	glVertex3f(-0.8f, -0.2f, -1.3f);
	glVertex3f(-0.8f, -1.0f, -1.3f);
	glVertex3f(-0.9f, -1.0f, -1.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.2f, -1.3f);
	glVertex3f(-0.8f, -0.2f, -1.3f);
	glVertex3f(-0.8f, -0.996f, -1.3f);
	glVertex3f(-0.9f, -0.996f, -1.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.2f, -1.3f);
	glVertex3f(-0.9f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.2f, -1.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.9f, -0.2f, -1.3f);
	glVertex3f(-0.9f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.2f, -1.2f);
	glVertex3f(-0.8f, -0.2f, -1.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.8f, -0.3f, -1.3f);
	glVertex3f(-0.8f, -0.3f, -1.2f);
	glVertex3f(0.0f, -0.3f, -1.2f);
	glVertex3f(0.0f, -0.3f, -1.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.8f, -0.3f, -1.3f);
	glVertex3f(-0.8f, -0.3f, -1.2f);
	glVertex3f(0.0f, -0.3f, -1.2f);
	glVertex3f(0.0f, -0.3f, -1.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.8f, -0.3f, -1.2f);
	glVertex3f(-0.8f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.3f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur
	glVertex3f(-0.8f, -0.3f, -1.2f);
	glVertex3f(-0.8f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.3f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur 
	glVertex3f(-0.8f, -0.8f, -1.3f);
	glVertex3f(-0.8f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.8f, -1.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur 
	glVertex3f(-0.8f, -0.8f, -1.3f);
	glVertex3f(-0.8f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.8f, -1.2f);
	glVertex3f(0.0f, -0.8f, -1.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur belakang
	glVertex3f(-0.8f, -0.8f, -1.3f);
	glVertex3f(-0.8f, -0.3f, -1.3f);
	glVertex3f(0.0f, -0.3f, -1.3f);
	glVertex3f(0.0f, -0.8f, -1.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur belakang
	glVertex3f(-0.8f, -0.8f, -1.3f);
	glVertex3f(-0.8f, -0.3f, -1.3f);
	glVertex3f(0.0f, -0.3f, -1.3f);
	glVertex3f(0.0f, -0.8f, -1.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -1.0f, -1.3f);
	glVertex3f(0.0f, -0.2f, -1.3f);
	glVertex3f(0.0f, -0.2f, -1.2f);
	glVertex3f(0.0f, -1.0f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -0.996f, -1.3f);
	glVertex3f(0.0f, -0.2f, -1.3f);
	glVertex3f(0.0f, -0.2f, -1.2f);
	glVertex3f(0.0f, -0.996f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.1f, -1.0f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.2f);
	glVertex3f(0.1f, -1.0f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.1f, -0.996f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.2f);
	glVertex3f(0.1f, -0.996f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -1.0f, -1.3f);
	glVertex3f(0.0f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.3f);
	glVertex3f(0.1f, -1.0f, -1.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -0.996f, -1.3f);
	glVertex3f(0.0f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.996f, -1.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -1.0f, -1.2f);
	glVertex3f(0.0f, -0.2f, -1.2f);
	glVertex3f(0.1f, -0.2f, -1.2f);
	glVertex3f(0.1f, -1.0f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -0.996f, -1.2f);
	glVertex3f(0.0f, -0.2f, -1.2f);
	glVertex3f(0.1f, -0.2f, -1.2f);
	glVertex3f(0.1f, -0.996f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.2f);
	glVertex3f(0.0f, -0.2f, -1.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur kanan
	glVertex3f(0.0f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.3f);
	glVertex3f(0.1f, -0.2f, -1.2f);
	glVertex3f(0.0f, -0.2f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);     // kasur tengah
	glVertex3f(0.05f, -0.55f, -1.2f);
	glVertex3f(-0.85f, -0.55f, -1.2f);
	glVertex3f(-0.85f, -0.55f, 0.2f);
	glVertex3f(0.05f, -0.55f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);     // kasur tengah
	glVertex3f(-0.85f, -0.65f, -1.2f);
	glVertex3f(-0.85f, -0.55f, -1.2f);
	glVertex3f(-0.85f, -0.55f, 0.2f);
	glVertex3f(-0.85f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur tengah
	glVertex3f(-0.85f, -0.65f, -1.2f);
	glVertex3f(-0.85f, -0.55f, -1.2f);
	glVertex3f(-0.85f, -0.55f, 0.2f);
	glVertex3f(-0.85f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur tengah
	glVertex3f(-0.85f, -0.65f, -1.2f);
	glVertex3f(-0.85f, -0.8f, -1.2f);
	glVertex3f(-0.85f, -0.8f, 0.2f);
	glVertex3f(-0.85f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur tengah
	glVertex3f(-0.85f, -0.65f, -1.2f);
	glVertex3f(-0.85f, -0.8f, -1.2f);
	glVertex3f(-0.85f, -0.8f, 0.2f);
	glVertex3f(-0.85f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);     // kasur tengah
	glVertex3f(0.05f, -0.65f, -1.2f);
	glVertex3f(0.05f, -0.55f, -1.2f);
	glVertex3f(0.05f, -0.55f, 0.2f);
	glVertex3f(0.05f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur tengah
	glVertex3f(0.05f, -0.65f, -1.2f);
	glVertex3f(0.05f, -0.55f, -1.2f);
	glVertex3f(0.05f, -0.55f, 0.2f);
	glVertex3f(0.05f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur tengah
	glVertex3f(0.05f, -0.65f, -1.2f);
	glVertex3f(0.05f, -0.8f, -1.2f);
	glVertex3f(0.05f, -0.8f, 0.2f);
	glVertex3f(0.05f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur tengah
	glVertex3f(0.05f, -0.65f, -1.2f);
	glVertex3f(0.05f, -0.8f, -1.2f);
	glVertex3f(0.05f, -0.8f, 0.2f);
	glVertex3f(0.05f, -0.65f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.1f, -1.0f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.3f);
	glVertex3f(0.1f, -1.0f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.1f, -0.996f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.3f);
	glVertex3f(0.1f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.1f, -0.996f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.2f);
	glVertex3f(0.0f, -0.2f, 0.2f);
	glVertex3f(0.0f, -0.996f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.1f, -0.996f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.2f);
	glVertex3f(0.0f, -0.2f, 0.2f);
	glVertex3f(0.0f, -0.996f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.0f, -0.996f, 0.2f);
	glVertex3f(0.0f, -0.2f, 0.2f);
	glVertex3f(0.0f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.0f, -0.996f, 0.2f);
	glVertex3f(0.0f, -0.2f, 0.2f);
	glVertex3f(0.0f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.1f, -0.996f, 0.3f);
	glVertex3f(0.1f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kanan
	glVertex3f(0.1f, -0.996f, 0.3f);
	glVertex3f(0.1f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kanan atas
	glVertex3f(0.1f, -0.2f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.2f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kanan atas
	glVertex3f(0.1f, -0.2f, 0.2f);
	glVertex3f(0.1f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.2f, 0.3f);
	glVertex3f(0.0f, -0.2f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur belakang
	glVertex3f(-0.8f, -0.8f, 0.2f);
	glVertex3f(-0.8f, -0.3f, 0.2f);
	glVertex3f(0.0f, -0.3f, 0.2f);
	glVertex3f(0.0f, -0.8f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur belakang
	glVertex3f(-0.8f, -0.8f, 0.2f);
	glVertex3f(-0.8f, -0.3f, 0.2f);
	glVertex3f(0.0f, -0.3f, 0.2f);
	glVertex3f(0.0f, -0.8f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur belakang atas
	glVertex3f(-0.8f, -0.3f, 0.2f);
	glVertex3f(-0.8f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.3f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur belakang atas
	glVertex3f(-0.8f, -0.3f, 0.2f);
	glVertex3f(-0.8f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.3f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // kasur belakang
	glVertex3f(-0.8f, -0.8f, 0.3f);
	glVertex3f(-0.8f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.8f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kasur belakang
	glVertex3f(-0.8f, -0.8f, 0.3f);
	glVertex3f(-0.8f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.3f, 0.3f);
	glVertex3f(0.0f, -0.8f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.996f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.3f);
	glVertex3f(-0.9f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.996f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.3f);
	glVertex3f(-0.9f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.996f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.2f);
	glVertex3f(-0.8f, -0.2f, 0.2f);
	glVertex3f(-0.8f, -0.996f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.996f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.2f);
	glVertex3f(-0.8f, -0.2f, 0.2f);
	glVertex3f(-0.8f, -0.996f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.996f, 0.3f);
	glVertex3f(-0.9f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.996f, 0.3f);
	glVertex3f(-0.9f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.2f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.2f, 0.2f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.9f, -0.2f, 0.2f);
	glVertex3f(-0.9f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.2f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.8f, -0.996f, 0.2f);
	glVertex3f(-0.8f, -0.2f, 0.2f);
	glVertex3f(-0.8f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // tiang kasur kiri
	glVertex3f(-0.8f, -0.996f, 0.2f);
	glVertex3f(-0.8f, -0.2f, 0.2f);
	glVertex3f(-0.8f, -0.2f, 0.3f);
	glVertex3f(-0.8f, -0.996f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);     // bantal
	glVertex3f(-0.65f, -0.50f, -1.1f);
	glVertex3f(-0.65f, -0.50f, -0.8f);
	glVertex3f(-0.15f, -0.50f, -0.8f);
	glVertex3f(-0.15f, -0.50f, -1.1f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);     // bantal belakang
	glVertex3f(-0.65f, -0.50f, -1.1f);
	glVertex3f(-0.65f, -0.55f, -1.1f);
	glVertex3f(-0.15f, -0.55f, -1.1f);
	glVertex3f(-0.15f, -0.50f, -1.1f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);     // bantal depan
	glVertex3f(-0.65f, -0.50f, -0.8f);
	glVertex3f(-0.65f, -0.55f, -0.8f);
	glVertex3f(-0.15f, -0.55f, -0.8f);
	glVertex3f(-0.15f, -0.50f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);     // bantal kiri
	glVertex3f(-0.65f, -0.50f, -1.1f);
	glVertex3f(-0.65f, -0.55f, -1.1f);
	glVertex3f(-0.65f, -0.55f, -0.8f);
	glVertex3f(-0.65f, -0.50f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);     // bantal kanan
	glVertex3f(-0.15f, -0.50f, -1.1f);
	glVertex3f(-0.15f, -0.55f, -1.1f);
	glVertex3f(-0.15f, -0.55f, -0.8f);
	glVertex3f(-0.15f, -0.50f, -0.8f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);     // selimut
	glVertex3f(-0.86f, -0.54f, -0.7f);
	glVertex3f(-0.86f, -0.54f, 0.2f);
	glVertex3f(0.051f, -0.54f, 0.2f);
	glVertex3f(0.051f, -0.54f, -0.7f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);     // selimut kiri
	glVertex3f(-0.86f, -0.54f, -0.7f);
	glVertex3f(-0.86f, -0.65f, -0.7f);
	glVertex3f(-0.86f, -0.65f, 0.2f);
	glVertex3f(-0.86f, -0.54f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);     // selimut kanan
	glVertex3f(0.051f, -0.54f, -0.7f);
	glVertex3f(0.051f, -0.65f, -0.7f);
	glVertex3f(0.051f, -0.65f, 0.2f);
	glVertex3f(0.051f, -0.54f, 0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.0f);     // lemari belakang
	glVertex3f(0.95f, -1.0f, -1.4f);
	glVertex3f(0.95f, 0.4f, -1.4f);
	glVertex3f(0.95f, 0.4f, 0.0f);
	glVertex3f(0.95f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.0f);     // lemari kanan
	glVertex3f(0.6f, -1.0f, -1.4f);
	glVertex3f(0.6f, 0.4f, -1.4f);
	glVertex3f(0.95f, 0.4f, -1.4f);
	glVertex3f(0.95f, -1.0f, -1.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.0f);     // lemari kiri
	glVertex3f(0.6f, -1.0f, 0.0f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.95f, 0.4f, 0.0f);
	glVertex3f(0.95f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.0f);     // lemari depan
	glVertex3f(0.6f, -1.0f, -1.4f);
	glVertex3f(0.6f, 0.4f, -1.4f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.6f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.0f);     // lemari atas
	glVertex3f(0.6f, 0.4f, -1.4f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.95f, 0.4f, 0.0f);
	glVertex3f(0.95f, 0.4f, -1.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);     // kotak lemari 
	glVertex3f(0.59f, -0.9f, -1.35f);
	glVertex3f(0.59f, 0.3f, -1.35f);
	glVertex3f(0.59f, 0.3f, -0.75f);
	glVertex3f(0.59f, -0.9f, -0.75f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kotak lemari 
	glVertex3f(0.59f, -0.9f, -1.35f);
	glVertex3f(0.59f, 0.3f, -1.35f);
	glVertex3f(0.59f, 0.3f, -0.75f);
	glVertex3f(0.59f, -0.9f, -0.75f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);     // kotak lemari 
	glVertex3f(0.59f, -0.9f, -0.65f);
	glVertex3f(0.59f, 0.3f, -0.65f);
	glVertex3f(0.59f, 0.3f, -0.05f);
	glVertex3f(0.59f, -0.9f, -0.05f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kotak lemari 
	glVertex3f(0.59f, -0.9f, -0.65f);
	glVertex3f(0.59f, 0.3f, -0.65f);
	glVertex3f(0.59f, 0.3f, -0.05f);
	glVertex3f(0.59f, -0.9f, -0.05f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.2f, -0.85f);
	glVertex3f(0.55f, -0.5f, -0.85f);
	glVertex3f(0.55f, -0.5f, -0.9f);
	glVertex3f(0.55f, -0.2f, -0.9f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.2f, -0.85f);
	glVertex3f(0.55f, -0.5f, -0.85f);
	glVertex3f(0.55f, -0.5f, -0.9f);
	glVertex3f(0.55f, -0.2f, -0.9f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.35f, -0.85f);
	glVertex3f(0.55f, -0.35f, -0.85f);
	glVertex3f(0.59f, -0.35f, -0.9f);
	glVertex3f(0.59f, -0.35f, -0.9f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.35f, -0.85f);
	glVertex3f(0.55f, -0.35f, -0.85f);
	glVertex3f(0.59f, -0.35f, -0.9f);
	glVertex3f(0.59f, -0.35f, -0.9f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.2f, -0.55f);
	glVertex3f(0.55f, -0.5f, -0.55f);
	glVertex3f(0.55f, -0.5f, -0.5f);
	glVertex3f(0.55f, -0.2f, -0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.2f, -0.55f);
	glVertex3f(0.55f, -0.5f, -0.55f);
	glVertex3f(0.55f, -0.5f, -0.5f);
	glVertex3f(0.55f, -0.2f, -0.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.35f, -0.55f);
	glVertex3f(0.55f, -0.35f, -0.55f);
	glVertex3f(0.55f, -0.35f, -0.5f);
	glVertex3f(0.55f, -0.35f, -0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // pegangan kotak lemari 
	glVertex3f(0.55f, -0.35f, -0.55f);
	glVertex3f(0.55f, -0.35f, -0.55f);
	glVertex3f(0.55f, -0.35f, -0.5f);
	glVertex3f(0.55f, -0.35f, -0.5f);
	glEnd();
	

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // border lemari atas
	glVertex3f(0.6f, 0.4f, -1.4f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.95f, 0.4f, 0.0f);
	glVertex3f(0.95f, 0.4f, -1.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // border lemari depan
	glVertex3f(0.6f, -0.996f, -1.4f);
	glVertex3f(0.6f, 0.4f, -1.4f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.6f, -0.996f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // border lemari kanan
	glVertex3f(0.6f, -0.996f, -1.4f);
	glVertex3f(0.6f, 0.4f, -1.4f);
	glVertex3f(0.95f, 0.4f, -1.4f);
	glVertex3f(0.95f, -0.996f, -1.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // border lemari kiri
	glVertex3f(0.6f, -0.996f, 0.0f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.95f, 0.4f, 0.0f);
	glVertex3f(0.95f, -0.996f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // border lemari belakang
	glVertex3f(0.95f, -0.996f, -1.4f);
	glVertex3f(0.95f, 0.4f, -1.4f);
	glVertex3f(0.95f, 0.4f, 0.0f);
	glVertex3f(0.95f, -0.996f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // meja atas
	glVertex3f(0.5f, -0.4f, 0.4f);
	glVertex3f(0.5f, -0.4f, 1.1f);
	glVertex3f(0.95f, -0.4f, 1.1f);
	glVertex3f(0.95f, -0.4f, 0.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // meja atas
	glVertex3f(0.5f, -0.4f, 0.4f);
	glVertex3f(0.5f, -0.4f, 1.1f);
	glVertex3f(0.95f, -0.4f, 1.1f);
	glVertex3f(0.95f, -0.4f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // meja bawah
	glVertex3f(0.5f, -0.48f, 0.4f);
	glVertex3f(0.5f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.48f, 0.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // meja bawah
	glVertex3f(0.5f, -0.48f, 0.4f);
	glVertex3f(0.5f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.48f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // meja kiri 
	glVertex3f(0.5f, -0.48f, 0.4f);
	glVertex3f(0.95f, -0.48f, 0.4f);
	glVertex3f(0.95f, -0.4f, 0.4f);
	glVertex3f(0.5f, -0.4f, 0.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // meja kiri 
	glVertex3f(0.5f, -0.48f, 0.4f);
	glVertex3f(0.95f, -0.48f, 0.4f);
	glVertex3f(0.95f, -0.4f, 0.4f);
	glVertex3f(0.5f, -0.4f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // meja kanan 
	glVertex3f(0.5f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.4f, 1.1f);
	glVertex3f(0.5f, -0.4f, 1.1f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // meja kanan 
	glVertex3f(0.5f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.4f, 1.1f);
	glVertex3f(0.5f, -0.4f, 1.1f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // meja depan 
	glVertex3f(0.5f, -0.48f, 1.1f);
	glVertex3f(0.5f, -0.4f, 1.1f);
	glVertex3f(0.5f, -0.4f, 0.4f);
	glVertex3f(0.5f, -0.48f, 0.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // meja depan 
	glVertex3f(0.5f, -0.48f, 1.1f);
	glVertex3f(0.5f, -0.4f, 1.1f);
	glVertex3f(0.5f, -0.4f, 0.4f);
	glVertex3f(0.5f, -0.48f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // meja belakang 
	glVertex3f(0.95f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.4f, 1.1f);
	glVertex3f(0.95f, -0.4f, 0.4f);
	glVertex3f(0.95f, -0.48f, 0.4f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // meja belakang 
	glVertex3f(0.95f, -0.48f, 1.1f);
	glVertex3f(0.95f, -0.4f, 1.1f);
	glVertex3f(0.95f, -0.4f, 0.4f);
	glVertex3f(0.95f, -0.48f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.92f, -0.48f, 1.08f);
	glVertex3f(0.85f, -0.48f, 1.08f);
	glVertex3f(0.85f, -0.999f,  1.08f);
	glVertex3f(0.92f, -0.999f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.92f, -0.48f, 1.08f);
	glVertex3f(0.85f, -0.48f, 1.08f);
	glVertex3f(0.85f, -0.999f, 1.08f);
	glVertex3f(0.92f, -0.999f, 1.08f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.92f, -0.48f, 1.03f);
	glVertex3f(0.85f, -0.48f, 1.03f);
	glVertex3f(0.85f, -0.999f, 1.03f);
	glVertex3f(0.92f, -0.999f, 1.03f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.92f, -0.48f, 1.03f);
	glVertex3f(0.85f, -0.48f, 1.03f);
	glVertex3f(0.85f, -0.999f, 1.03f);
	glVertex3f(0.92f, -0.999f, 1.03f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.92f, -0.48f, 1.03f);
	glVertex3f(0.92f, -0.999f, 1.03f);
	glVertex3f(0.92f, -0.999f, 1.08f);
	glVertex3f(0.92f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.92f, -0.48f, 1.03f);
	glVertex3f(0.92f, -0.999f, 1.03f);
	glVertex3f(0.92f, -0.999f, 1.08f);
	glVertex3f(0.92f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.85f, -0.48f, 1.03f);
	glVertex3f(0.85f, -0.999f, 1.03f);
	glVertex3f(0.85f, -0.999f, 1.08f);
	glVertex3f(0.85f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.85f, -0.48f, 1.03f);
	glVertex3f(0.85f, -0.999f, 1.03f);
	glVertex3f(0.85f, -0.999f, 1.08f);
	glVertex3f(0.85f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja depan kanan depan 
	glVertex3f(0.53f, -0.48f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.08f);
	glVertex3f(0.53f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja depan kanan depan 
	glVertex3f(0.53f, -0.48f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.08f);
	glVertex3f(0.53f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.6f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.08f);
	glVertex3f(0.6f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.6f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.08f);
	glVertex3f(0.6f, -0.48f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.53f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.03f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.53f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.03f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.53f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.48f, 1.03f);
	glVertex3f(0.6f, -0.999f, 1.03f);
	glVertex3f(0.53f, -0.999f, 1.03f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kanan 
	glVertex3f(0.53f, -0.48f, 1.08f);
	glVertex3f(0.6f, -0.48f, 1.08f);
	glVertex3f(0.6f, -0.999f, 1.08f);
	glVertex3f(0.53f, -0.999f, 1.08f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kanan 
	glVertex3f(0.53f, -0.48f, 1.08f);
	glVertex3f(0.6f, -0.48f, 1.08f);
	glVertex3f(0.6f, -0.999f, 1.08f);
	glVertex3f(0.53f, -0.999f, 1.08f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja depan kiri 
	glVertex3f(0.53f, -0.48f, 0.43f);
	glVertex3f(0.6f, -0.48f, 0.43f);
	glVertex3f(0.6f, -0.999f, 0.43f);
	glVertex3f(0.53f, -0.999f, 0.43f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja depan kiri 
	glVertex3f(0.53f, -0.48f, 0.43f);
	glVertex3f(0.6f, -0.48f, 0.43f);
	glVertex3f(0.6f, -0.999f, 0.43f);
	glVertex3f(0.53f, -0.999f, 0.43f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja depan kiri 
	glVertex3f(0.53f, -0.48f, 0.48f);
	glVertex3f(0.6f, -0.48f, 0.48f);
	glVertex3f(0.6f, -0.999f, 0.48f);
	glVertex3f(0.53f, -0.999f, 0.48f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja depan kiri 
	glVertex3f(0.53f, -0.48f, 0.48f);
	glVertex3f(0.6f, -0.48f, 0.48f);
	glVertex3f(0.6f, -0.999f, 0.48f);
	glVertex3f(0.53f, -0.999f, 0.48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja depan kiri 
	glVertex3f(0.6f, -0.48f, 0.43f);
	glVertex3f(0.6f, -0.999f, 0.43f);
	glVertex3f(0.6f, -0.999f, 0.48f);
	glVertex3f(0.6f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja depan kiri 
	glVertex3f(0.6f, -0.48f, 0.43f);
	glVertex3f(0.6f, -0.999f, 0.43f);
	glVertex3f(0.6f, -0.999f, 0.48f);
	glVertex3f(0.6f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja depan kiri depan 
	glVertex3f(0.53f, -0.48f, 0.43f);
	glVertex3f(0.53f, -0.999f, 0.43f);
	glVertex3f(0.53f, -0.999f, 0.48f);
	glVertex3f(0.53f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja depan kiri depan 
	glVertex3f(0.53f, -0.48f, 0.43f);
	glVertex3f(0.53f, -0.999f, 0.43f);
	glVertex3f(0.53f, -0.999f, 0.48f);
	glVertex3f(0.53f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kiri 
	glVertex3f(0.92f, -0.48f, 0.48f);
	glVertex3f(0.85f, -0.48f, 0.48f);
	glVertex3f(0.85f, -0.999f, 0.48f);
	glVertex3f(0.92f, -0.999f, 0.48f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kiri 
	glVertex3f(0.92f, -0.48f, 0.48f);
	glVertex3f(0.85f, -0.48f, 0.48f);
	glVertex3f(0.85f, -0.999f, 0.48f);
	glVertex3f(0.92f, -0.999f, 0.48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kiri 
	glVertex3f(0.92f, -0.48f, 0.43f);
	glVertex3f(0.85f, -0.48f, 0.43f);
	glVertex3f(0.85f, -0.999f, 0.43f);
	glVertex3f(0.92f, -0.999f, 0.43f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kiri 
	glVertex3f(0.92f, -0.48f, 0.43f);
	glVertex3f(0.85f, -0.48f, 0.43f);
	glVertex3f(0.85f, -0.999f, 0.43f);
	glVertex3f(0.92f, -0.999f, 0.43f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kiri 
	glVertex3f(0.92f, -0.48f, 0.43f);
	glVertex3f(0.92f, -0.999f, 0.43f);
	glVertex3f(0.92f, -0.999f, 0.48f);
	glVertex3f(0.92f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kiri 
	glVertex3f(0.92f, -0.48f, 0.43f);
	glVertex3f(0.92f, -0.999f, 0.43f);
	glVertex3f(0.92f, -0.999f, 0.48f);
	glVertex3f(0.92f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);     // kaki meja belakang kiri 
	glVertex3f(0.85f, -0.48f, 0.43f);
	glVertex3f(0.85f, -0.999f, 0.43f);
	glVertex3f(0.85f, -0.999f, 0.48f);
	glVertex3f(0.85f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki meja belakang kiri 
	glVertex3f(0.85f, -0.48f, 0.43f);
	glVertex3f(0.85f, -0.999f, 0.43f);
	glVertex3f(0.85f, -0.999f, 0.48f);
	glVertex3f(0.85f, -0.48f, 0.48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kursi atas
	glVertex3f(0.2f, -0.65f, 0.55f);
	glVertex3f(0.2f, -0.65f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.55f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kursi atas
	glVertex3f(0.2f, -0.65f, 0.55f);
	glVertex3f(0.2f, -0.65f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.55f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kursi bawah
	glVertex3f(0.2f, -0.73f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.73f, 0.55f);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kursi bawah
	glVertex3f(0.2f, -0.73f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.73f, 0.55f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kursi kiri
	glVertex3f(0.2f, -0.65f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.55f);
	glVertex3f(0.55f, -0.73f, 0.55f);
	glVertex3f(0.55f, -0.65f, 0.55f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kursi kiri
	glVertex3f(0.2f, -0.65f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.55f);
	glVertex3f(0.55f, -0.73f, 0.55f);
	glVertex3f(0.55f, -0.65f, 0.55f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kursi kanan
	glVertex3f(0.2f, -0.65f, 0.95f);
	glVertex3f(0.2f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.95f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kursi kanan
	glVertex3f(0.2f, -0.65f, 0.95f);
	glVertex3f(0.2f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.73f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.95f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kursi depan
	glVertex3f(0.2f, -0.65f, 0.95f);
	glVertex3f(0.2f, -0.65f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.95f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kursi depan
	glVertex3f(0.2f, -0.65f, 0.95f);
	glVertex3f(0.2f, -0.65f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.55f);
	glVertex3f(0.2f, -0.73f, 0.95f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kursi depan
	glVertex3f(0.55f, -0.65f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.55f);
	glVertex3f(0.55f, -0.73f, 0.55f);
	glVertex3f(0.55f, -0.73f, 0.95f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kursi depan
	glVertex3f(0.55f, -0.65f, 0.95f);
	glVertex3f(0.55f, -0.65f, 0.55f);
	glVertex3f(0.55f, -0.73f, 0.55f);
	glVertex3f(0.55f, -0.73f, 0.95f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi depan kanan
	glVertex3f(0.53f, -0.65f, 0.57f);
	glVertex3f(0.53f, -0.999f, 0.57f);
	glVertex3f(0.53f, -0.999f, 0.62f);
	glVertex3f(0.53f, -0.65f, 0.62f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi depan kanan
	glVertex3f(0.53f, -0.65f, 0.57f);
	glVertex3f(0.53f, -0.999f, 0.57f);
	glVertex3f(0.53f, -0.999f, 0.62f);
	glVertex3f(0.53f, -0.65f, 0.62f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.57f);
	glVertex3f(0.48f, -0.999f, 0.57f);
	glVertex3f(0.48f, -0.999f, 0.62f);
	glVertex3f(0.48f, -0.65f, 0.62f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.57f);
	glVertex3f(0.48f, -0.999f, 0.57f);
	glVertex3f(0.48f, -0.999f, 0.62f);
	glVertex3f(0.48f, -0.65f, 0.62f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.62f);
	glVertex3f(0.48f, -0.999f, 0.62f);
	glVertex3f(0.53f, -0.999f, 0.62f);
	glVertex3f(0.53f, -0.65f, 0.62f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.62f);
	glVertex3f(0.48f, -0.999f, 0.62f);
	glVertex3f(0.53f, -0.999f, 0.62f);
	glVertex3f(0.53f, -0.65f, 0.62f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.57f);
	glVertex3f(0.48f, -0.999f, 0.57f);
	glVertex3f(0.53f, -0.999f, 0.57f);
	glVertex3f(0.53f, -0.65f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.57f);
	glVertex3f(0.48f, -0.999f, 0.57f);
	glVertex3f(0.53f, -0.999f, 0.57f);
	glVertex3f(0.53f, -0.65f, 0.57f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri
	glVertex3f(0.48f, -0.65f, 0.88f);
	glVertex3f(0.48f, -0.999f, 0.88f);
	glVertex3f(0.53f, -0.999f, 0.88f);
	glVertex3f(0.53f, -0.65f, 0.88f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri
	glVertex3f(0.48f, -0.65f, 0.88f);
	glVertex3f(0.48f, -0.999f, 0.88f);
	glVertex3f(0.53f, -0.999f, 0.88f);
	glVertex3f(0.53f, -0.65f, 0.88f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri
	glVertex3f(0.48f, -0.65f, 0.93f);
	glVertex3f(0.48f, -0.999f, 0.93f);
	glVertex3f(0.53f, -0.999f, 0.93f);
	glVertex3f(0.53f, -0.65f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri
	glVertex3f(0.48f, -0.65f, 0.93f);
	glVertex3f(0.48f, -0.999f, 0.93f);
	glVertex3f(0.53f, -0.999f, 0.93f);
	glVertex3f(0.53f, -0.65f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.88f);
	glVertex3f(0.48f, -0.999f, 0.88f);
	glVertex3f(0.48f, -0.999f, 0.93f);
	glVertex3f(0.48f, -0.65f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.48f, -0.65f, 0.88f);
	glVertex3f(0.48f, -0.999f, 0.88f);
	glVertex3f(0.48f, -0.999f, 0.93f);
	glVertex3f(0.48f, -0.65f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.53f, -0.65f, 0.88f);
	glVertex3f(0.53f, -0.999f, 0.88f);
	glVertex3f(0.53f, -0.999f, 0.93f);
	glVertex3f(0.53f, -0.65f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.53f, -0.65f, 0.88f);
	glVertex3f(0.53f, -0.999f, 0.88f);
	glVertex3f(0.53f, -0.999f, 0.93f);
	glVertex3f(0.53f, -0.65f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.22f, -0.1f, 0.88f);
	glVertex3f(0.22f, -0.999f, 0.88f);
	glVertex3f(0.22f, -0.999f, 0.93f);
	glVertex3f(0.22f, -0.1f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.22f, -0.1f, 0.88f);
	glVertex3f(0.22f, -0.999f, 0.88f);
	glVertex3f(0.22f, -0.999f, 0.93f);
	glVertex3f(0.22f, -0.1f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.999f, 0.88f);
	glVertex3f(0.27f, -0.999f, 0.93f);
	glVertex3f(0.27f, -0.1f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.999f, 0.88f);
	glVertex3f(0.27f, -0.999f, 0.93f);
	glVertex3f(0.27f, -0.1f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.88f);
	glVertex3f(0.22f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.999f, 0.88f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.88f);
	glVertex3f(0.22f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.999f, 0.88f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.93f);
	glVertex3f(0.22f, -0.1f, 0.93f);
	glVertex3f(0.27f, -0.1f, 0.93f);
	glVertex3f(0.27f, -0.999f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.93f);
	glVertex3f(0.22f, -0.1f, 0.93f);
	glVertex3f(0.27f, -0.1f, 0.93f);
	glVertex3f(0.27f, -0.999f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri atas
	glVertex3f(0.22f, -0.1f, 0.93f);
	glVertex3f(0.22f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.1f, 0.93f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri atas
	glVertex3f(0.22f, -0.1f, 0.93f);
	glVertex3f(0.22f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.1f, 0.88f);
	glVertex3f(0.27f, -0.1f, 0.93f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.57f);
	glVertex3f(0.22f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.999f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.57f);
	glVertex3f(0.22f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.999f, 0.57f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.62f);
	glVertex3f(0.27f, -0.1f, 0.62f);
	glVertex3f(0.27f, -0.999f, 0.62f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kiri
	glVertex3f(0.22f, -0.999f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.62f);
	glVertex3f(0.27f, -0.1f, 0.62f);
	glVertex3f(0.27f, -0.999f, 0.62f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.22f, -0.1f, 0.57f);
	glVertex3f(0.22f, -0.999f, 0.57f);
	glVertex3f(0.22f, -0.999f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.62f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.22f, -0.1f, 0.57f);
	glVertex3f(0.22f, -0.999f, 0.57f);
	glVertex3f(0.22f, -0.999f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.62f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.999f, 0.57f);
	glVertex3f(0.27f, -0.999f, 0.62f);
	glVertex3f(0.27f, -0.1f, 0.62f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.999f, 0.57f);
	glVertex3f(0.27f, -0.999f, 0.62f);
	glVertex3f(0.27f, -0.1f, 0.62f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.1f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.1f, 0.57f);
	glVertex3f(0.27f, -0.1f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.62f);
	glVertex3f(0.22f, -0.1f, 0.57f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.2f, 0.57f);
	glVertex3f(0.27f, -0.2f, 0.93f);
	glVertex3f(0.22f, -0.2f, 0.93f);
	glVertex3f(0.22f, -0.2f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.2f, 0.57f);
	glVertex3f(0.27f, -0.2f, 0.93f);
	glVertex3f(0.22f, -0.2f, 0.93f);
	glVertex3f(0.22f, -0.2f, 0.57f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.4f, 0.57f);
	glVertex3f(0.27f, -0.4f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.4f, 0.57f);
	glVertex3f(0.27f, -0.4f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.57f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.22f, -0.2f, 0.57f);
	glVertex3f(0.22f, -0.2f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.22f, -0.2f, 0.57f);
	glVertex3f(0.22f, -0.2f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.93f);
	glVertex3f(0.22f, -0.4f, 0.57f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.5f, 0.3f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.2f, 0.57f);
	glVertex3f(0.27f, -0.2f, 0.93f);
	glVertex3f(0.27f, -0.4f, 0.93f);
	glVertex3f(0.27f, -0.4f, 0.57f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // kaki kursi kanan
	glVertex3f(0.27f, -0.2f, 0.57f);
	glVertex3f(0.27f, -0.2f, 0.93f);
	glVertex3f(0.27f, -0.4f, 0.93f);
	glVertex3f(0.27f, -0.4f, 0.57f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);     // atas segitiga depan
	glVertex3f(-1.0f, 1.0f, 1.5f);
	glVertex3f(1.0f, 1.0f, 1.5f);
	glVertex3f(0.0f, 2.0f, 1.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);     // atas segitiga belakang
	glVertex3f(-1.0f, 1.0f, -1.5f);
	glVertex3f(1.0f, 1.0f, -1.5f);
	glVertex3f(0.0f, 2.0f, -1.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // atap kanan
	glVertex3f(1.1f, 1.0f, 1.7f);
	glVertex3f(1.1f, 1.0f, -1.7f);
	glVertex3f(0.0f, 2.1f, -1.7f);
	glVertex3f(0.0f, 2.1f, 1.7f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // atap kanan
	glVertex3f(1.0f, 1.0f, 1.7f);
	glVertex3f(1.1f, 1.0f, 1.7f);
	glVertex3f(0.0f, 2.1f, 1.7f);
	glVertex3f(0.0f, 2.0f, 1.7f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // atap kiri
	glVertex3f(-1.1f, 1.0f, 1.7f);
	glVertex3f(-1.1f, 1.0f, -1.7f);
	glVertex3f(0.0f, 2.1f, -1.7f);
	glVertex3f(0.0f, 2.1f, 1.7f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // atap kiri depan
	glVertex3f(-1.0f, 1.0f, 1.7f);
	glVertex3f(-1.1f, 1.0f, 1.7f);
	glVertex3f(0.0f, 2.1f, 1.7f);
	glVertex3f(0.0f, 2.0f, 1.7f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // atap kiri belakang
	glVertex3f(-1.0f, 1.0f, -1.7f);
	glVertex3f(-1.1f, 1.0f, -1.7f);
	glVertex3f(0.0f, 2.1f, -1.7f);
	glVertex3f(0.0f, 2.0f, -1.7f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // atap kanan belakang
	glVertex3f(1.0f, 1.0f, -1.7f);
	glVertex3f(1.1f, 1.0f, -1.7f);
	glVertex3f(0.0f, 2.1f, -1.7f);
	glVertex3f(0.0f, 2.0f, -1.7f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // pintu depan
	glVertex3f(-0.3f, -1.0f, 1.501f);
	glVertex3f(-0.3f, 0.1f, 1.501f);
	glVertex3f(0.3f, 0.1f, 1.501f);
	glVertex3f(0.3f, -1.0f, 1.501f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // pintu depan
	glVertex3f(-0.3f, -1.0f, 1.501f);
	glVertex3f(-0.3f, 0.1f, 1.501f);
	glVertex3f(0.3f, 0.1f, 1.501f);
	glVertex3f(0.3f, -1.0f, 1.501f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);     // gagang pintu depan
	glVertex3f(-0.2f, -0.4f, 1.502f);
	glVertex3f(-0.2f, -0.5f, 1.502f);
	glVertex3f(-0.1f, -0.5f, 1.502f);
	glVertex3f(-0.1f, -0.4f, 1.502f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // jendela depan kanan border
	glVertex3f(0.2f, 0.3f, 1.501f);
	glVertex3f(0.2f, 0.8f, 1.501f);
	glVertex3f(0.8f, 0.8f, 1.501f);
	glVertex3f(0.8f, 0.3f, 1.501f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // jendela depan kanan border
	glVertex3f(0.2f, 0.3f, 1.501f);
	glVertex3f(0.2f, 0.8f, 1.501f);
	glVertex3f(0.8f, 0.8f, 1.501f);
	glVertex3f(0.8f, 0.3f, 1.501f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);     // jendela depan kanan  
	glVertex3f(0.3f, 0.4f, 1.502f);
	glVertex3f(0.3f, 0.7f, 1.502f);
	glVertex3f(0.7f, 0.7f, 1.502f);
	glVertex3f(0.7f, 0.4f, 1.502f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // jendela depan kiri border
	glVertex3f(-0.2f, 0.3f, 1.501f);
	glVertex3f(-0.2f, 0.8f, 1.501f);
	glVertex3f(-0.8f, 0.8f, 1.501f);
	glVertex3f(-0.8f, 0.3f, 1.501f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // jendela depan kiri border
	glVertex3f(-0.2f, 0.3f, 1.501f);
	glVertex3f(-0.2f, 0.8f, 1.501f);
	glVertex3f(-0.8f, 0.8f, 1.501f);
	glVertex3f(-0.8f, 0.3f, 1.501f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);     // jendela depan kiri
	glVertex3f(-0.3f, 0.4f, 1.502f);
	glVertex3f(-0.3f, 0.7f, 1.502f);
	glVertex3f(-0.7f, 0.7f, 1.502f);
	glVertex3f(-0.7f, 0.4f, 1.502f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);     // jendela belakang border
	glVertex3f(-0.7f, 0.3f, -1.501f);
	glVertex3f(-0.7f, 0.8f, -1.501f);
	glVertex3f(0.7f, 0.8f, -1.501f);
	glVertex3f(0.7f, 0.3f, -1.501f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);     // jendela belakang border
	glVertex3f(-0.7f, 0.3f, -1.501f);
	glVertex3f(-0.7f, 0.8f, -1.501f);
	glVertex3f(0.7f, 0.8f, -1.501f);
	glVertex3f(0.7f, 0.3f, -1.501f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);     // jendela belakang
	glVertex3f(-0.6f, 0.4f, -1.502f);
	glVertex3f(-0.6f, 0.7f, -1.502f);
	glVertex3f(0.6f, 0.7f, -1.502f);
	glVertex3f(0.6f, 0.4f, -1.502f);
	glEnd();



	glPopMatrix();
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, lebar, tinggi);
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(900, 700);   // Set the window's initial width & height
	glutInitWindowPosition(210, 30);// Position the window's initial top-left corner
	glutCreateWindow("Adrian Priyanto - 672017338");          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(ukuran);       // Register callback handler for window re-size event
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(display);
	Inisialisasi();// Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}