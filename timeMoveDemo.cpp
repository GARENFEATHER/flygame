//#include "global.h"
//void display()//��ʾ�ص��������������ƵĶ���
//{
//	glClear(GL_COLOR_BUFFER_BIT);//CLear���� ����GLbirdield������ָʾ��GL_COLOR_BUFFER_BITָʾ��ɫ���档
//
//	glBegin(GL_POLYGON);                        //��������
//	glVertex2f(-0.5, 0.5);
//	glVertex2f(-0.7, 0.0);
//	glVertex2f(-0.5, -0.5);
//	glVertex2f(0.0, -0.7);
//	glVertex2f(0.5, -0.5);
//	glVertex2f(0.7, 0.0);
//	glVertex2f(0.5, 0.5);
//	glVertex2f(0.0, 0.7);;
//	glEnd();
//	glFlush();                              //ǿ��ִ��֮ǰ���������OpenGL����
//											glutSwapBuffers();                            //�л�˫����
//}
//
//void moveDisplay(int value)
//{
//	glutPostRedisplay();//ǿ���ػ�
//	glutTimerFunc(25, moveDisplay, 1);
//}
//
//void init()
//{//״̬�����ĳ�ʼ������
//	glClearColor(0.0, 0.0, 0.0, 0.0);//����������ɫ��ģʽ������RGBA
//	glColor3f(1.0, 1.0, 1.0);//���û�����ɫ
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//(x,y,width,height)���½�(x,y)��width��height���涨��������
//
//	glMatrixMode(GL_PROJECTION);//ָ���ĸ�������ܺ����任������Ӱ��
//	glLoadIdentity();//����ǰ��������Ϊ��λ����
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//	gluOrtho2D(-2.0, 2.0, -2.0, 2.0); //ָ��һ����ά���Ӳü�����(Left,Right,Bottom,Top)����(Left,Bottom)����(Right,Top)
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void mouseClick(int button, int state, int x, int y)
//{//��굥���¼�
//	switch (button)                                 //glutIdleFunc��ѭ������Ϊ��ʱ�򴥷����¼���
//	{                                               //���⣺ѭ�����졣
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
//{//��갴�º��϶�ʱ���ϵ��ú������������Ͻ�Ϊԭ�������ϵ
//	cout << x << " " << y << endl;
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);//��ʼ��
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//������ɫģʽ��RGB/RGBA/INDEX���ͻ���ģʽ����/˫��
//	glutInitWindowSize(500, 500);//���ô��ڴ�С
//	glutInitWindowPosition(400, 180);//���ô���λ��
//	glutCreateWindow("sample");//�������ڡ�Ĭ�����ϽǺ�300*300��
//	init();//����init������������
//
//	glutDisplayFunc(display);//�ص�����display��ÿ�δ����ػ�ʱ���õĺ�����
//	glutReshapeFunc(reshape);//�涨����
//	glutMouseFunc(mouseClick);  //��굥���¼�
//	glutMotionFunc(mouseMotion);//����ƶ�ʱ��
//
//	glutMainLoop();//���������¼�ѭ��
//}