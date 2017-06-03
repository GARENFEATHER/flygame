//#include "global.h"
//void display()//显示回调函数。描述绘制的对象。
//{
//	glClear(GL_COLOR_BUFFER_BIT);//CLear缓存 接受GLbirdield参数来指示。GL_COLOR_BUFFER_BIT指示颜色缓存。
//
//	glBegin(GL_POLYGON);                        //多边形填充
//	glVertex2f(-0.5, 0.5);
//	glVertex2f(-0.7, 0.0);
//	glVertex2f(-0.5, -0.5);
//	glVertex2f(0.0, -0.7);
//	glVertex2f(0.5, -0.5);
//	glVertex2f(0.7, 0.0);
//	glVertex2f(0.5, 0.5);
//	glVertex2f(0.0, 0.7);;
//	glEnd();
//	glFlush();                              //强制执行之前缓存的所有OpenGL命令
//											glutSwapBuffers();                            //切换双缓存
//}
//
//void moveDisplay(int value)
//{
//	glutPostRedisplay();//强制重绘
//	glutTimerFunc(25, moveDisplay, 1);
//}
//
//void init()
//{//状态变量的初始化工作
//	glClearColor(0.0, 0.0, 0.0, 0.0);//设置清屏颜色，模式必须是RGBA
//	glColor3f(1.0, 1.0, 1.0);//设置绘制颜色
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//(x,y,width,height)左下角(x,y)宽width高height。规定画布区域。
//
//	glMatrixMode(GL_PROJECTION);//指定哪个矩阵会受后续变换函数的影响
//	glLoadIdentity();//将当前矩阵设置为单位矩阵
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//	gluOrtho2D(-2.0, 2.0, -2.0, 2.0); //指定一个二维可视裁剪区域(Left,Right,Bottom,Top)左下(Left,Bottom)右上(Right,Top)
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void mouseClick(int button, int state, int x, int y)
//{//鼠标单击事件
//	switch (button)                                 //glutIdleFunc当循环队列为空时则触发该事件。
//	{                                               //问题：循环过快。
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) {
//			moveDisplay(1);
//		}
//		break;
//	case GLUT_MIDDLE_BUTTON:
//	case GLUT_RIGHT_BUTTON:
//		if (state == GLUT_DOWN)
//		{
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//void mouseMotion(int x, int y)
//{//鼠标按下后拖动时不断调用函数，基于左上角为原点的坐标系
//	cout << x << " " << y << endl;
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);//初始化
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//设置颜色模式（RGB/RGBA/INDEX）和缓存模式（单/双）
//	glutInitWindowSize(500, 500);//设置窗口大小
//	glutInitWindowPosition(400, 180);//设置窗口位置
//	glutCreateWindow("sample");//创建窗口。默认左上角和300*300。
//	init();//如上init函数进行设置
//
//	glutDisplayFunc(display);//回调函数display。每次窗口重绘时调用的函数。
//	glutReshapeFunc(reshape);//规定窗口
//	glutMouseFunc(mouseClick);  //鼠标单击事件
//	glutMotionFunc(mouseMotion);//鼠标移动时间
//
//	glutMainLoop();//进入无限事件循环
//}