#ifndef OBJ_H
#define OBJ_H

#include "global.h"

GLint grid = 10;
GLint winsize[2] = { 960,640 };

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
	Plane(float x):GObject(x,winsize[1]/2,1,1) {
		halfHeight = 60.0;
	}
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
		GLfloat hfh = 12, hfw = 20, sml = 5;
		GLfloat c0[2] = { center[0] - hfw - sml,center[1] };
		GLfloat c01[2] = { c0[0] - hfw,c0[1] + hfw + sml };
		GLfloat c1[2] = { center[0] - hfw,center[1] + hfh };
		GLfloat c2[2] = { c1[0] + hfw,c1[1] };
		GLfloat c3[2] = { c2[0],c2[1] + 1.6 * hfw };
		GLfloat c4[2] = { c2[0] + hfw,c2[1] };
		GLfloat c5[2] = { c4[0] + hfw,c4[1] };
		GLfloat c6[2] = { c5[0] + hfw,c5[1] - hfh };
		glBegin(GL_POLYGON);

		glVertex2fv(c0);

		glVertex2fv(c01);
		glVertex2fv(c1);
		glVertex2fv(c2);
		glVertex2fv(c3);
		glVertex2fv(c4);
		glVertex2fv(c5);

		glVertex2fv(c6);

		glVertex2f(c5[0], c5[1] - 2 * (c5[1] - center[1]));
		glVertex2f(c4[0], c4[1] - 2 * (c4[1] - center[1]));
		glVertex2f(c3[0], c3[1] - 2 * (c3[1] - center[1]));
		glVertex2f(c2[0], c2[1] - 2 * (c2[1] - center[1]));
		glVertex2f(c1[0], c1[1] - 2 * (c1[1] - center[1]));
		glVertex2f(c01[0], c01[1] - 2 * (c01[1] - center[1]));

		glEnd();
	}
};
class Enemy:public GObject {
protected:
	vector<GLfloat*> limit;
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
class TrianStrip :public Enemy {
public:
	TrianStrip(float x, float y, float speed, float scale) :Enemy(x, y, speed, scale) {
		GLfloat *c1 = new GLfloat[2], *c2 = new GLfloat[2], *c3 = new GLfloat[2];
		c1[0] = center[0];
		c1[1] = center[1] + scale;
		c2[0] = center[0] - 0.5*sqrt(3)*scale;
		c2[1] = center[1] - 0.5*scale;
		c3[0] = center[0] + 0.5*sqrt(3)*scale;
		c3[1] = center[1] - 0.5*scale;
		limit.push_back(c1);
		limit.push_back(c2);
		limit.push_back(c3);
	}
	void selfDraw() {
		GLfloat c1[2] = { limit[0][0],limit[0][1] };
		GLfloat c2[2] = { limit[1][0],limit[1][1] };
		GLfloat c3[2] = { limit[2][0],limit[2][1] };
		glPointSize(12);
		glBegin(GL_POINTS);
		glVertex2fv(center);
		glVertex2fv(c1);
		glVertex2fv(c2);
		glVertex2fv(c3);
		glPointSize(10);
		glEnd();
		glLineWidth(2);
		glBegin(GL_LINE_STRIP);
		glVertex2fv(c1);
		glVertex2fv(center);
		glVertex2fv(c2);
		glVertex2fv(center);
		glVertex2fv(c3);
		glVertex2fv(center);
		glEnd();
	}
};
class Diamond :public Enemy {
public:
	Diamond(float x, float y, float speed, float scale):Enemy(x,y,speed,scale) {
		GLfloat *c1 = new GLfloat[2], *c2 = new GLfloat[2], 
			*c3 = new GLfloat[2], *c4 = new GLfloat[2], 
			*c11 = new GLfloat[2], *c12 = new GLfloat[2], 
			*c21 = new GLfloat[2], *c22 = new GLfloat[2], 
			*c31 = new GLfloat[2], *c32 = new GLfloat[2], 
			*c41 = new GLfloat[2], *c42 = new GLfloat[2];
		c1[0] = center[0];
		c1[0] = center[1] + scale;
		c2[0] = center[0] - scale;
		c2[0] = center[1];
		c3[0] = center[0] + scale;
		c3[0] = center[1];
		c4[0] = center[0];
		c4[0] = center[1] - scale;
		c11[0] = center[0] - 0.5*scale / sqrt(3);
		c11[0] = center[1] + 0.5*scale;
		c12[0] = center[0] + 0.5*scale / sqrt(3);
		c12[0] = center[1] + 0.5*scale;
		c21[0] = center[0] - 0.5*scale;
		c21[0] = center[1] + 0.5*scale / sqrt(3);
		c22[0] = center[0] - 0.5*scale;
		c22[0] = center[1] - 0.5*scale / sqrt(3);
		c31[0] = center[0] + 0.5*scale;
		c31[0] = center[1] + 0.5*scale / sqrt(3);
		c32[0] = center[0] + 0.5*scale;
		c32[0] = center[1] - 0.5*scale / sqrt(3);
		c41[0] = center[0] - 0.5*scale / sqrt(3);
		c41[0] = center[1] - 0.5*scale;
		c42[0] = center[0] + 0.5*scale / sqrt(3);
		c42[0] = center[1] - 0.5*scale;
		limit.push_back(c1);
		limit.push_back(c2);
		limit.push_back(c3);
		limit.push_back(c4);
		limit.push_back(c11);
		limit.push_back(c12);
		limit.push_back(c21);
		limit.push_back(c22);
		limit.push_back(c31);
		limit.push_back(c32);
		limit.push_back(c41);
		limit.push_back(c42);
	}
	void selfDraw() {
		GLfloat c1[2] = { limit[0][0],limit[0][1] };
		GLfloat c2[2] = { limit[1][0],limit[1][1] };
		GLfloat c3[2] = { limit[2][0],limit[2][1] };
		GLfloat c4[2] = { limit[3][0],limit[3][1] };
		GLfloat c11[2] = { limit[4][0],limit[4][1] };
		GLfloat c12[2] = { limit[5][0],limit[5][1] };
		GLfloat c21[2] = { limit[6][0],limit[6][1] };
		GLfloat c22[2] = { limit[7][0],limit[7][1] };
		GLfloat c31[2] = { limit[8][0],limit[8][1] };
		GLfloat c32[2] = { limit[9][0],limit[9][1] };
		GLfloat c41[2] = { limit[10][0],limit[10][1] };
		GLfloat c42[2] = { limit[11][0],limit[11][1] };
		glPointSize(8);
		glBegin(GL_POINTS);
		glVertex2fv(center);
		glVertex2fv(c1);
		glVertex2fv(c2);
		glVertex2fv(c3);
		glVertex2fv(c4);
		glEnd();
		glLineWidth(1.5);
		glBegin(GL_LINE_STRIP);
		glVertex2fv(center);
		glVertex2fv(c11);
		glVertex2fv(c1);
		glVertex2fv(c12);
		glVertex2fv(center);
		glVertex2fv(c31);
		glVertex2fv(c3);
		glVertex2fv(c32);
		glVertex2fv(center);
		glVertex2fv(c41);
		glVertex2fv(c4);
		glVertex2fv(c42);
		glVertex2fv(center);
		glVertex2fv(c21);
		glVertex2fv(c2);
		glVertex2fv(c22);
		glVertex2fv(center);
		glEnd();
	}
};
class RectLine :public Enemy {
public:
	RectLine(float x, float y, float speed, float scale) :Enemy(x, y, speed, scale) {
		GLfloat *c1 = new GLfloat[2], *c2 = new GLfloat[2],
			*c3 = new GLfloat[2], *c4 = new GLfloat[2];
		c1[0] = center[0];
		c1[1] = center[1] + scale;
		c2[0] = center[0]+ scale;
		c2[1] = center[1];
		c3[0] = center[0];
		c3[1] = center[1] - scale;
		c4[0] = center[0] - scale;
		c4[1] = center[1];
		limit.push_back(c1);
		limit.push_back(c2);
		limit.push_back(c3);
		limit.push_back(c4);
	}
	void selfDraw() {
		GLfloat c1[2] = { limit[0][0],limit[0][1] };
		GLfloat c2[2] = { limit[1][0],limit[1][1] };
		GLfloat c3[2] = { limit[2][0],limit[2][1] };
		GLfloat c4[2] = { limit[3][0],limit[3][1] };
		glPointSize(7.8);
		glBegin(GL_POINTS);
		glVertex2fv(center);
		glVertex2fv(c1);
		glVertex2fv(c2);
		glVertex2fv(c3);
		glVertex2fv(c4);
		glEnd();
		glLineWidth(1.2);
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
	}
};

set<Bullet*> bullets;
map<GLint, set<Enemy*>*> gridEnemies;
set<Enemy*> enemies;

#endif