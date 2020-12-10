#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDialog>
#include<QMainWindow>
#include<QLabel>
#include <QTextEdit>
#include<QPushButton>
#include"childwin.h"
#include"mymysql.h"
#include"LoginDialog.h"
using namespace std;
class mainwindow :public QMainWindow//主窗口
{
	Q_OBJECT;
public:
	explicit mainwindow(string,string,QWidget* parent = 0);
	~mainwindow();
	void tomain();//槽函数——接收子界面的信号返回主界面
	void slot_flight_show();//槽函数——展示航班
	void slot_hotel_show();//槽函数——展示旅馆
	void slot_bus_show();//槽函数——展示公交
	void slot_resv_show();//槽函数——展示订单
	void slot_cust_show();//槽函数——展示顾客
	void slot_resv();//槽函数——预订管理
	void slot_option();//槽函数——系统管理
	QPushButton* exit_btn;

private:
	QLabel* tiplbl;
	QPushButton* flight_show_btn;
	QPushButton* hotel_show_btn;
	QPushButton* bus_show_btn;
	QPushButton* resv_show_btn;
	QPushButton* cust_show_btn;
	QPushButton* option_btn;
	QPushButton* resv_btn;

	MYSQL* conn;
	Mysql mysql;
	MYSQL_RES* res = NULL;
};

#endif // !MAINWINDOW_H