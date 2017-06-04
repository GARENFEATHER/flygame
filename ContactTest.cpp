//#include "Obj.h"
////a:left,b:right
////x轴向右，y轴向下，不允许斜率为正无限
//void Contact(GLfloat p[2], GLfloat q[2],GLfloat k) {
//	set<int> result;
//	int ai[2], bi[2],
//		colCount = winsize[0] / grid, rowCount = winsize[1] / grid;
//	GLfloat b = (p[0] * q[1] - q[0] * p[1]) / (p[0] - q[0]);
//	ai[0] = p[0] / grid;
//	ai[1] = p[1] / grid;
//	bi[0] = q[0] / grid;
//	bi[1] = q[1] / grid;
//	result.insert(ai[0] + ai[1] * colCount);
//	result.insert(bi[0] + bi[1] * colCount);
//	//列
//	for (int i = ai[0] + 1; i < bi[0] + 1; i++) {
//		int x = i*grid;
//		GLfloat r = k*x + b;
//		int num = r / grid;
//		num = num*colCount;
//		result.insert(num + i);
//		result.insert(num + i - 1);
//	}
//	int low = ai[1] > bi[1] ? bi[1] : ai[1], high = ai[1] > bi[1] ? ai[1] : bi[1];
//	//行
//	for (int i = low + 1; i < high + 1; i++) {
//		int y = i*grid;
//		GLfloat r = (y - b) / k;
//		int num = r / grid;
//		result.insert(i*colCount + num);
//		result.insert((i - 1)*colCount + num);
//	}
//	for (set<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
//		cout << *iter << " ";
//	}
//	cout << endl;
//}