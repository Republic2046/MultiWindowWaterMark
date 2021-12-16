#include "MultiWindowWaterMark.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cstdio>


typedef struct {
	int screenNumber;
	QRect rect;
}SCREEN;

SCREEN screens[10];

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QDesktopWidget* desktop = QApplication::desktop();

	int screenCount = desktop->screenCount();
	int primScreen = desktop->primaryScreen();
	char warning[100], * index = warning;
	for (int i = 0; i < screenCount; i++) {
		screens[i].screenNumber = primScreen + i;
		screens[i].rect = desktop->screenGeometry(primScreen + i);
		sprintf(index, "screen%d w[%d], h[%d] ", i, screens[i].rect.width(), screens[i].rect.height());
		index += strlen(index);
	}
	sprintf(index, "total width[%d] , total height[%d] \n", desktop->width(), desktop->height());

	MultiWindowWaterMark window[5];
	for (int i = 0; i < screenCount; i++) {
		window[i].resize(screens[i].rect.width(), screens[i].rect.height());
		if (i == 0)
			window[i].move(0, 0);
		else
			window[i].move(i * screens[i - 1].rect.width(), 0);
		window[i].show();
	}
	return app.exec();
}
