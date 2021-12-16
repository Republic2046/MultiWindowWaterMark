#include "MultiWindowWaterMark.h"

#include <windows.h>
#include <tchar.h>

HWND hwnd;

MultiWindowWaterMark::MultiWindowWaterMark(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	hwnd = (HWND)winId();
	InitWidget();
}

void MultiWindowWaterMark::InitWidget()
{
	setWindowOpacity(0.5);

	LONG widgetStyle = WS_EX_COMPOSITED | WS_EX_LAYERED | WS_EX_NOACTIVATE | WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_APPWINDOW;
	SetWindowLong(hwnd, GWL_EXSTYLE, widgetStyle);

	setAttribute(Qt::WA_TransparentForMouseEvents, true);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Popup | Qt::Tool);
}

void MultiWindowWaterMark::afterWidgetShow()
{
	setWindowState(Qt::WindowMaximized);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	//SetFather();
}

void MultiWindowWaterMark::setFather()
{
	//HWND hWndProgram = FindWindow(_T("Progman"),_T("Program Manager"));
	//HWND hWndShellDll = FindWindowEx(hWndProgram, NULL, _T("SHELLDLL_DefView"),NULL);
	//SetWindowLong(hwnd,GWL_HWNDPARENT,(LONG)hWndShellDll);
}