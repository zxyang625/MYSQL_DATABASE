#pragma once
#include<mysql.h>
#include<iostream>
#include<Qstring.h>
#include<QMessageBox>
#pragma execution_character_set("utf-8")
using namespace std;
class Mysql:public QWidget
{
	Q_OBJECT;
public:
		char* host = "localhost";//连接数据库的信息
		char user[20];
		char password[20];
		char* db="travel_system";

public:
	MYSQL* mysql_connect(const char* usr,const char* pwd); //连接数据库
	MYSQL_RES* show(MYSQL* mysql, const char* op, MYSQL_RES* res);//展示数据库
	MYSQL_RES* select(MYSQL* mysql, const char* op, MYSQL_RES* res);//通过op进行选择
	MYSQL_RES* select_all(MYSQL* mysql, const char* op, MYSQL_RES* res);//通过op进行所有选择
	bool resv_sql(MYSQL* mysql,const char* custname,int type ,const char* resvname);//订单增加
	bool delete_sql(MYSQL* mysql, const char* custname, int type, const char* resvname);//订单删除
	bool identify(QString,QString);//数据库身份验证
	int sum(MYSQL* mysql, int type, const char* resvname);//求所有订单价格总和
private:
	MYSQL_RES* res = NULL;
	MYSQL_RES* tmp_res = NULL;
	MYSQL_ROW row=NULL;
	string customer[9][2] = {//储存的数据库用户
		{"钱一", "123456"},
		{"刘二", "123456"},
		{"张三", "123456"},
		{"李四", "123456"},
		{"王五", "123456"},
		{"赵六", "123456"},
	    {"黄七", "123456"},
		{"柳八", "123456"},
		{"杨九", "123456"}	};
};

