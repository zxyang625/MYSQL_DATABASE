#include"mainwindow.h"
#pragma execution_character_set("utf-8")
mainwindow::mainwindow(string usr,string pwd,QWidget* parent):QMainWindow(parent)
{
	this->setAttribute(Qt::WA_DeleteOnClose);
	conn=mysql.mysql_connect("yzx","123456");
	strcpy(mysql.user,usr.c_str());//接收登录界面的账号和密码
	strcpy(mysql.password, pwd.c_str());
	char tmp1[50];//欢迎提示
	strcpy(tmp1, usr.c_str());
	tiplbl = new QLabel(strcat(tmp1,",欢迎登录旅行管理系统"), this);
	tiplbl->move(100, 5);
	tiplbl->resize(300, 50);
	QFont ft;//设置字体
	ft.setPointSize(14);
	tiplbl->setFont(ft);
	this->resize(480, 390);

	flight_show_btn = new QPushButton("航班查询",this);
	flight_show_btn->move(180, 50);
	hotel_show_btn = new QPushButton("旅店查询", this);
	hotel_show_btn->move(180, 100);
	bus_show_btn = new QPushButton("公交查询", this);
	bus_show_btn->move(180, 150);
	resv_show_btn = new QPushButton("订单查询", this);
	resv_show_btn->move(180, 200);
	cust_show_btn = new QPushButton("乘客查询", this);
	cust_show_btn->move(180, 250);
	option_btn = new QPushButton("系统管理", this);
	option_btn->move(180, 300);
	resv_btn = new QPushButton("预订通道", this);
	resv_btn->move(180,250);
	exit_btn = new QPushButton("退出", this);
	exit_btn->move(180, 350);
	string tmp2 = mysql.user;
	if (tmp2 == "yzx")//对于管理员，隐藏订单预订的按钮,显示乘客查询和系统管理
	{
		resv_btn->hide();
		cust_show_btn->show();
		option_btn->show();
	}
	else//对于用户，显示订单管理，但是隐藏乘客查询和系统管理
	{
		option_btn->hide();
		cust_show_btn->hide();
		resv_btn->show();
	}

	this->setObjectName("mainWindow");
	this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix1/11.jpg);}");

	connect(flight_show_btn, &QPushButton::clicked, this, &mainwindow::slot_flight_show);
	connect(hotel_show_btn, &QPushButton::clicked, this, &mainwindow::slot_hotel_show);
	connect(bus_show_btn, &QPushButton::clicked, this, &mainwindow::slot_bus_show);
	connect(resv_show_btn, &QPushButton::clicked, this, &mainwindow::slot_resv_show);
	connect(cust_show_btn, &QPushButton::clicked, this, &mainwindow::slot_cust_show);
	connect(option_btn, &QPushButton::clicked, this, &mainwindow::slot_option);
	connect(resv_btn, &QPushButton::clicked, this, &mainwindow::slot_resv);
	connect(exit_btn, &QPushButton::clicked, this, &mainwindow::close);

}
mainwindow::~mainwindow()
{
	mysql_close(conn);
}

void mainwindow::tomain() {
	this->show();
}
void mainwindow::slot_flight_show()//查询的子界面生成，下面旅馆，公交，乘客类似
{
	res=mysql.show(conn, "flights",res);// 将数据库得到的结果传入子界面
	unsigned int column = mysql_num_fields(res);//传列数
	this->hide();//隐藏主界面
	childwin* chwin = new childwin(column , 1 , res ,this);//参数为列数，子窗口选项为1
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("航班查询");
	chwin->show();//显示子界面
}
void mainwindow::slot_hotel_show()
{
	res = mysql.show(conn, "hotels", res);
	unsigned int column = mysql_num_fields(res);
	this->hide();
	childwin* chwin = new childwin(column, 2 , res, this);
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("旅馆查询");
	chwin->show();
}
void mainwindow::slot_bus_show()
{
	res = mysql.show(conn, "buses", res);
	unsigned int column = mysql_num_fields(res);
	this->hide();
	childwin* chwin = new childwin(column, 3, res, this);
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("公交查询");
	chwin->show();
}
void mainwindow::slot_resv_show()//对于用户，用户只能查看自己的订单。管理员可以查看所有乘客的订单
{
	string tmp = mysql.user;
	if (tmp == "yzx")
		res = mysql.select_all(conn, "reservations", res);
	else
		res = mysql.select(conn, mysql.user, res);
	unsigned int column = mysql_num_fields(res);
	childwin* chwin = new childwin(column, 4, res, this);
	this->hide();
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("订单查询");
	chwin->show();
}
void mainwindow::slot_cust_show()
{
	res = mysql.select_all(conn, "customers", res);
	unsigned int column = mysql_num_fields(res);
	this->hide();
	childwin* chwin = new childwin(column, 5, res, this);
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("乘客查询");
	chwin->show();
}
void mainwindow::slot_resv()
{
	childwin* chwin = new childwin(conn, 1, mysql.user, this);
	this->hide();
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("订单管理");
	chwin->show();
}
void mainwindow::slot_option()
{
	childwin* chwin = new childwin(conn, 2, mysql.user, this);
	this->hide();
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("系统管理");
	chwin->show();
}

