#include "Obj.h"

GLfloat center[2] = { 50,40 };
GLfloat scale = 24;
GLfloat c1[2] = { center[0],center[1] + scale };
GLfloat c2[2] = { center[0] + scale,center[1] };
GLfloat c3[2] = { center[0],center[1] - scale };
GLfloat c4[2] = { center[0] - scale,center[1] };
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
void gameSet() {
	onlyPlane = new Plane(50);
}
GLfloat randomNum(int type) {
	srand((int)time(0));
	switch (type)
	{
	case 0://scale:3-16
		return rand() % 13 + 3;
	case 1://speed:4-12
		return rand() % 8 + 4;
	case 2:
		int half = 20;
		return rand() % (winsize[1] - 2 * half) + half;
	default:
		break;
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	onlyPlane->selfDraw();
	for (set<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
		if ((*it)->isOutside()) bullets.erase(it);
		else (*it)->selfDraw();
	}
	for (set<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
		if ((*it)->isOutside()) enemies.erase(it);
		else (*it)->selfDraw();
	}
	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, (GLdouble) h, 0.0);
}
void timeFunc(int value) {
	glutTimerFunc(40, timeFunc, 1);
	int len = bullets.size();
	for (set<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
		(*it)->move();
		(*it)->caculate();
	}
	for (set<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
		(*it)->move();
		(*it)->caculate();
		set<Enemy*>* es = gridEnemies[(*it)->getOccupied()];
		if (es != NULL && es->size() != 0) {
			(*it)->boom();
			for (set<Enemy*>::iterator i = enemies.begin(); i != enemies.end(); i++) {
				enemies.erase(*i);
			}
			bullets.erase(*it);
		}
	}
	
	glutPostRedisplay();//强制重绘
}
void mouseClick(int button, int state, int x, int y) {
	switch (button)                                 //glutIdleFunc当循环队列为空时则触发该事件。
	{                                               //问题：循环过快。
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			float hx = onlyPlane->getHeadX(), hy = onlyPlane->getHeadY();
			float direct = (y - hy) / (x - hx), speed = randomNum(1), scale = randomNum(0);
			Bullet *bullet = new Bullet(hx, hy, speed, scale, direct);
			bullets.insert(bullet);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			timeFunc(1);
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();//强制重绘

}
void passiveMove(int x, int y) {
	onlyPlane->move(y);
	glutPostRedisplay();//强制重绘
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(winsize[0], winsize[1]);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	gameSet();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc(passiveMove);
	glutMainLoop();
	return 0;
}