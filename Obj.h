#include "global.h"

GLint grid = 10;
GLint winsize[2] = { 720,640 };

class GObject {
protected:
	GLfloat center[2];
	GLfloat scale, speed;
public:
	GObject(float x, float y, float speed, float scale) :
		speed((GLfloat)speed), scale((GLfloat)scale) {
		center[0] = (GLfloat)x;
		center[1] = (GLfloat)y;
	}
	virtual void selfDraw() = 0;
	virtual void move() = 0;
};
class Plane :public GObject {
	GLfloat halfHeight;
public:
	Plane(float x):GObject(x,winsize[1]/2,1,1) {}
	void setPosition(GLfloat y) {
		if (y > winsize[1] - halfHeight) {
			center[1] = winsize[1] - halfHeight;
		} else if (y < halfHeight) {
			center[1] = halfHeight;
		} else {
			center[1] = y;
		}
	}
	void selfDraw() {

	}
};
class Enemy:public GObject {
protected:
	vector<GLfloat[2]> limit;
public:
	Enemy(float x, float y, float speed, float scale) :GObject(x, y, speed, scale) {
		speed = -speed;
	}
	void move() {
		center[0] += speed;
	}
};
class Bullet :public GObject {
	GLfloat limit[2];
	GLfloat direct;
public:
	Bullet(float x, float y, float speed, float scale, float direct) :
		GObject(x, y, speed, scale), direct((GLfloat)direct) {
		limit[0] = x + scale;
		limit[1] = y + scale*direct;
	}
	void move() {
		center[0] += speed;
		center[1] += speed*direct;
		limit[0] += speed;
		limit[1] += speed*direct;
	}
	void selfDraw() {

	}
};
class trian :public Enemy {
public:
	void selfDraw() {

	}
};

set<Bullet*> bullets;
map<GLint, set<Enemy*>*> gridEnemies;
set<Enemy*> enemies;