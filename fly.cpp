//#include "Obj.h"
//class pic {
//	GLfloat v1[2] = { 200,400 }, v2[2] = { 300,500 }, v3[2] = { 250,100 };
//public:
//	void selfDraw() {
//		glBegin(GL_POLYGON);
//		glEdgeFlag(GL_TRUE);
//		glVertex2fv(v1);
//		glEdgeFlag(GL_FALSE);
//		glVertex2fv(v2);
//		glEdgeFlag(GL_TRUE);
//		glVertex2fv(v3);
//		glEnd();
//	}
//};
//void init() {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_POINT_SMOOTH);
//	glEnable(GL_LINE_SMOOTH);
//	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); 
//	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glLineWidth(2);
//}
//void display() {
//	pic p;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	p.selfDraw();
//	GLfloat hfh = 12, hfw = 20, sml = 5;
//	GLfloat center[2] = { 60,60 };
//	GLfloat c0[2] = { center[0] - hfw - sml,center[1] };
//	GLfloat c01[2] = { c0[0] - hfw,c0[1] + hfw + sml };
//	GLfloat c1[2] = { center[0] - hfw,center[1] + hfh };
//	GLfloat c2[2] = { c1[0] + hfw,c1[1] };
//	GLfloat c3[2] = { c2[0],c2[1] + 1.6 * hfw };
//	GLfloat c4[2] = { c2[0] + hfw,c2[1] };
//	GLfloat c5[2] = { c4[0] + hfw,c4[1] };
//	GLfloat c6[2] = { c5[0]+hfw,c5[1] - hfh };
//	glBegin(GL_POLYGON);
//
//	glVertex2fv(c0);
//
//	glVertex2fv(c01);
//	glVertex2fv(c1);
//	glVertex2fv(c2);
//	glVertex2fv(c3);
//	glVertex2fv(c4);
//	glVertex2fv(c5);
//
//	glVertex2fv(c6);
//
//	glVertex2f(c5[0], c5[1] - 2 * (c5[1] - center[1]));
//	glVertex2f(c4[0], c4[1] - 2 * (c4[1] - center[1]));
//	glVertex2f(c3[0], c3[1] - 2 * (c3[1] - center[1]));
//	glVertex2f(c2[0], c2[1] - 2 * (c2[1] - center[1]));
//	glVertex2f(c1[0], c1[1] - 2 * (c1[1] - center[1]));
//	glVertex2f(c01[0], c01[1] - 2 * (c01[1] - center[1]));
//
//	glEnd();
//	glFlush();
//}
//void reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble) w, (GLdouble) h, 0.0);
//}
//int main(int argc, char **argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(winsize[0], winsize[1]);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	//glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;
//}