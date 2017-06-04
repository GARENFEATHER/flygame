#include "Obj.h"
class pic {
	GLfloat v1[2] = { 200,400 }, v2[2] = { 300,500 }, v3[2] = { 250,100 };
public:
	void selfDraw() {
		glBegin(GL_POLYGON);
		glEdgeFlag(GL_TRUE);
		glVertex2fv(v1);
		glEdgeFlag(GL_FALSE);
		glVertex2fv(v2);
		glEdgeFlag(GL_TRUE);
		glVertex2fv(v3);
		glEnd();
	}
};
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); 
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLineWidth(2);
}
void display() {
	pic p;
	glClear(GL_COLOR_BUFFER_BIT);
	p.selfDraw();
	GLfloat center[2] = { 50,40 };
	GLfloat scale = 24;
	GLfloat c1[2] = { center[0],center[1] + scale };
	GLfloat c2[2] = { center[0] + scale,center[1] };
	GLfloat c3[2] = { center[0],center[1] - scale };
	GLfloat c4[2] = { center[0] - scale,center[1] };
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2fv(center);
	glVertex2fv(c1);
	glVertex2fv(c2);
	glVertex2fv(c3);
	glVertex2fv(c4);
	glEnd();
	glLineWidth(1.4);
	glBegin(GL_LINE_STRIP);
	glVertex2fv(c1);
	glVertex2fv(c2);
	glVertex2fv(c3);
	glVertex2fv(c4);
	glVertex2fv(c1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2fv(c1);
	glVertex2fv(center);
	glVertex2fv(c2);
	glVertex2fv(center);
	glVertex2fv(c3);
	glVertex2fv(center);
	glVertex2fv(c4);
	glVertex2fv(center);
	glEnd();

	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, (GLdouble) h, 0.0);
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(winsize[0], winsize[1]);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}