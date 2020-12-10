#include "mymysql.h"
#pragma execution_character_set("utf-8")
MYSQL* Mysql::mysql_connect(const char* usr,const char* pwd)
	{
		MYSQL* mysql = mysql_init(NULL);
		if (mysql_real_connect(mysql, host, usr, pwd, db, 3306, NULL, 0))
		{
			return mysql;
		}
		else
		{
			QMessageBox::warning(this, "警告!", "连接数据库失败", QMessageBox::Yes);
			exit(1);
		}
	}
MYSQL_RES* Mysql::show(MYSQL* mysql, const char* op, MYSQL_RES* res)
{
	mysql_free_result(res);
	char cmd[50];
	strcpy(cmd, "select * from ");
	strcat(cmd, op);
	mysql_query(mysql, cmd);
	return mysql_store_result(mysql);
}
MYSQL_RES* Mysql::select(MYSQL* mysql, const char* op, MYSQL_RES* res)
{
	mysql_free_result(res);
	char cmd[100];
	sprintf(cmd, "select * from reservations where custName='%s'",op);//选择指定顾客的所有订单
	mysql_query(mysql, cmd);
	return mysql_store_result(mysql);
}

MYSQL_RES* Mysql::select_all(MYSQL* mysql, const char* op, MYSQL_RES* res)
{
	mysql_free_result(res);
	char cmd[100];
	sprintf(cmd, "select * from %s order by custName", op);//管理员模式（选择所有订单）
	mysql_query(mysql, cmd);
	return mysql_store_result(mysql);
}
bool Mysql::resv_sql(MYSQL* mysql, const char* custname, int type,const char* resvname)
{
	mysql_free_result(res);
	char cmd[100];
	char check[100];
	srand((int)time(0));
	int key = rand();
	sprintf(cmd, "insert into reservations (custName, resvType, resvKey, resvName) values ('%s',%d,%d,'%s')", custname, type, key, resvname);
	switch (type)//通过resvtype查找票价
	{
	case 1:sprintf(check, "select COUNT('%s') as amount from flights where flightNum = '%s';", resvname, resvname); break;
	case 2:sprintf(check, "select COUNT('%s') as amount from hotels where location = '%s';", resvname, resvname); break;
	case 3:sprintf(check, "select COUNT('%s') as amount from buses where location = '%s';", resvname, resvname); break;
	}
	mysql_query(mysql, check);
	res = mysql_store_result(mysql);
	row = mysql_fetch_row(res);
	if (atoi(row[0]) == 1) {//如果查找结果存在，那么返回求值
		return(mysql_query(mysql, cmd));
	}
	else
		return 1;
}
bool Mysql::delete_sql(MYSQL* mysql, const char* custname, int type, const char* resvname)
{
	mysql_free_result(res);
	char cmd[100];
	char check[100];
	sprintf(cmd, "delete from reservations where custName='%s' and resvType=%d and resvName='%s'",custname,type,resvname);
	switch (type)
	{
	case 1:sprintf(check, "select COUNT('%s') as amount from flights where flightNum = '%s';", resvname, resvname); break;
	case 2:sprintf(check, "select COUNT('%s') as amount from hotels where location = '%s';", resvname, resvname); break;
	case 3:sprintf(check, "select COUNT('%s') as amount from buses where location = '%s';", resvname, resvname); break;
	}
	mysql_query(mysql, check);
	res = mysql_store_result(mysql);
	row = mysql_fetch_row(res);
	if (atoi(row[0]) == 1) {//订单存在才能删除
		return(mysql_query(mysql, cmd));
	}
	else
		return 1;
}
bool Mysql::identify(QString str1,QString str2)
{//用户的身份验证
	int check=0;
	for (int i = 0; i < 9; i++)
	{
		if (str1.toStdString() == customer[i][0] && str2.toStdString() == customer[i][1])
		{
			check = 1;
			break;
		}
	}
	return check;
}
int Mysql::sum(MYSQL* mysql,int type,const char* resvname)
{//求和
	int value = 0;
	char cmd[100];
	if (type == 1)
	{
		sprintf(cmd, "select price from flights where flightNum='%s'", resvname);//航班价格
		mysql_query(mysql, cmd);
	}
	else if (type == 2)
	{
		sprintf(cmd, "select price from hotels where location='%s'", resvname);//旅馆价格
		mysql_query(mysql, cmd);
	}
	else
	{
		sprintf(cmd, "select price from buses where location='%s'", resvname);//公交价格
		mysql_query(mysql, cmd);
	}

	tmp_res = mysql_store_result(mysql);
	row = mysql_fetch_row(tmp_res);
	value = atoi(row[0]);
	return value;
}
