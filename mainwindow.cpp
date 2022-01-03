#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <tchar.h>

HWND hwnd;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hwnd = (HWND)this->winId();
    InitWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitWidget()
{
    LONG widgetStyle = WS_EX_COMPOSITED | WS_EX_LAYERED |WS_EX_NOACTIVATE | WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_APPWINDOW;
    SetWindowLong(hwnd, GWL_EXSTYLE, widgetStyle);
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Popup | Qt::Tool);
}

void MainWindow::AfterWidgetShow()
{
    this->setWindowState(Qt::WindowMaximized);
    SetWindowPos(hwnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE );
    //SetFather();
}

void MainWindow::SetFather()
{
    //HWND hWndProgram = FindWindow(_T("Progman"),_T("Program Manager"));
    //HWND hWndShellDll = FindWindowEx(hWndProgram, NULL, _T("SHELLDLL_DefView"),NULL);
    //SetWindowLong(hwnd,GWL_HWNDPARENT,(LONG)hWndShellDll);
}
