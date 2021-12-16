#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MultiWindowWaterMark.h"

class MultiWindowWaterMark : public QMainWindow
{
    Q_OBJECT

public:
    MultiWindowWaterMark(QWidget *parent = Q_NULLPTR);
	void afterWidgetShow();
	void setFather();

private:
    Ui::MultiWindowWaterMarkClass ui;

private:
	void InitWidget();
};
