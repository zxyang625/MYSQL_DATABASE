#include "childwin.h"
#include"mainwindow.h"
#pragma execution_character_set("utf-8")
childwin::childwin(int n, int option, MYSQL_RES* res, QWidget* parent)
	: QMainWindow(parent)
{
	tmp_mysql = mysql.mysql_connect("yzx", "123456");
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setAutoFillBackground(true);

	this->setObjectName("mainWindow"); 
	this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix1/33.jpg);}");

	back_btn = new QPushButton("返回主菜单", this);
	back_btn->move(180, 325);
	tableWidget = new QTableWidget(this);
	connect(back_btn, &QPushButton::clicked, this, &childwin::slot_back_to_main);
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setStyleSheet("background-color:rgba(0,0,0,0)");

	this->resize(480, 360);
	int row = 0;
	if (option == 1)
	{
		tableWidget->setRowCount(20);
		tableWidget->setColumnCount(n);
		tableWidget->move(25, 0);
		tableWidget->resize(430, 320);
		header << "航班序号" << "票价" << "总座位数" << "可定座位数" << "始发地" << "目的地";
		tableWidget->setHorizontalHeaderLabels(header);
		while (rows = mysql_fetch_row(res))
		{
			tableWidget->setItem(row, 0, new QTableWidgetItem(rows[0]));
			tableWidget->setItem(row, 1, new QTableWidgetItem(rows[1]));
			tableWidget->setItem(row, 2, new QTableWidgetItem(rows[2]));
			tableWidget->setItem(row, 3, new QTableWidgetItem(rows[3]));
			tableWidget->setItem(row, 4, new QTableWidgetItem(rows[4]));
			tableWidget->setItem(row, 5, new QTableWidgetItem(rows[5]));
			row++;
		}
	}
	if (option == 2)
	{
		tableWidget->setRowCount(10);
		tableWidget->setColumnCount(n);
		tableWidget->move(25, 0);
		tableWidget->resize(430, 320);
		header << "旅店所在城市" << "住宿价格" << "总客房数" << "可预订客房数";
		tableWidget->setHorizontalHeaderLabels(header);
		while (rows = mysql_fetch_row(res))
		{
			tableWidget->setItem(row, 0, new QTableWidgetItem(rows[0]));
			tableWidget->setItem(row, 1, new QTableWidgetItem(rows[1]));
			tableWidget->setItem(row, 2, new QTableWidgetItem(rows[2]));
			tableWidget->setItem(row, 3, new QTableWidgetItem(rows[3]));
			row++;
		}
	}
	if(option == 3)
	{
		tableWidget->setRowCount(10);
		tableWidget->setColumnCount(n);
		tableWidget->move(25, 0);
		tableWidget->resize(430, 320);
		header << "公交所在城市" << "票价" << "总座位数" << "可预订座位数";
		tableWidget->setHorizontalHeaderLabels(header);
		while (rows = mysql_fetch_row(res))
		{
			tableWidget->setItem(row, 0, new QTableWidgetItem(rows[0]));
			tableWidget->setItem(row, 1, new QTableWidgetItem(rows[1]));
			tableWidget->setItem(row, 2, new QTableWidgetItem(rows[2]));
			tableWidget->setItem(row, 3, new QTableWidgetItem(rows[3]));
			row++;
		}
	}
	if (option == 4)
	{
		int type[100],i=0,sum=0,flag=0;
		char cmd[100];
		//MYSQL_RES* tmp_res=NULL;
		//MYSQL_ROW tmp_row;
		string resvname[50];
		string flight[50];
		tableWidget->setRowCount(30);
		tableWidget->setColumnCount(n+2);
		tableWidget->move(25, 0);
		tableWidget->resize(430, 320);
		header << "乘客姓名" << "预订类型" << "订单号" << "订单编号"<<"始发地"<<"目的地";
		tableWidget->setHorizontalHeaderLabels(header);
		while (rows = mysql_fetch_row(res))
		{
			tableWidget->setItem(row, 0, new QTableWidgetItem(rows[0]));
			tableWidget->setItem(row, 1, new QTableWidgetItem(rows[1]));
			tableWidget->setItem(row, 2, new QTableWidgetItem(rows[2]));
			tableWidget->setItem(row, 3, new QTableWidgetItem(rows[3]));
			
			if (atoi(rows[1]) == 1)
			{
				mysql_free_result(tmp_res);
				sprintf(cmd, "select FromCity,ArivCity from flights where flightNum='%s'", rows[3]);
				mysql_query(tmp_mysql, cmd);
				tmp_res = mysql_store_result(tmp_mysql);
				tmp_row = mysql_fetch_row(tmp_res);
				if (tmp_row[0] != NULL && tmp_row[1] != NULL) {
					tableWidget->setItem(row, 4, new QTableWidgetItem(tmp_row[0]));
					tableWidget->setItem(row, 5, new QTableWidgetItem(tmp_row[1]));
					flight[flag++] = tmp_row[0];
					flight[flag++] = tmp_row[1];
				}
				
			}
			type[i] = atoi(rows[1]);
			resvname[i] = rows[3];
			i++;
			row++;
		}
		while (i--)
		{
			sum += mysql.sum(tmp_mysql, type[i], resvname[i].c_str());
		}

		QLabel* tip1 = new QLabel("线路是否完整:",this);
		QLabel* tip3 = new QLabel(this);
		QLabel* tip2 = new QLabel("总金额:", this);
		tip1->move(20,325);
		tip2->move(320, 325);
		tip3->move(120, 325);
		QLineEdit* sum_line = new QLineEdit(this);
		sum_line->move(380,325);
		sum_line->resize(50, 30);
		sum_line->setText(QString::number(sum,10));
		sum_line->isReadOnly();

		if ((flag == 4 && (flight[1] == flight[2])||(flight[0] == flight[3])) || flag == 2 || (flag == 6 && flight[1] == flight[2] && flight[3] == flight[4]))
		{
			tip3->setText("是");
		}
		else
			tip3->setText("否");
		
	}
	if(option == 5)
	{
		tableWidget->setRowCount(10);
		tableWidget->setColumnCount(n);
		tableWidget->move(25, 0);
		tableWidget->resize(430, 320);
		header << "乘客姓名" << "乘客编号";
		tableWidget->setHorizontalHeaderLabels(header);
		while (rows = mysql_fetch_row(res))
		{
			tableWidget->setItem(row, 0, new QTableWidgetItem(rows[0]));
			tableWidget->setItem(row, 1, new QTableWidgetItem(rows[1]));
			row++;
		}
	}
	tableWidget->resizeColumnsToContents();
	tableWidget->resizeRowsToContents();
}

childwin::childwin(MYSQL* conn,int option, const char* custname, QWidget* parent) : QMainWindow(parent)
{//管理系统的子界面
	tmp_mysql = mysql.mysql_connect("yzx", "123456");
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->resize(480, 360);

	this->setObjectName("mainWindow");
	this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix1/22.jpg);}");

	strcpy(customer_name, custname);
	back_btn = new QPushButton("返回主菜单", this);
	back_btn->move(320, 325);
	connect(back_btn, &QPushButton::clicked, this, &childwin::slot_back_to_main);
	if (option == 1)
	{
		setWindowTitle("订单管理");
		submit_btn = new QPushButton("提交", this);
		submit_btn->move(80, 325);
		connect(submit_btn, &QPushButton::clicked, this, &childwin::slot_resv);

		delete_btn = new QPushButton("删除", this);
		delete_btn->move(200, 325);
		connect(delete_btn, &QPushButton::clicked, this, &childwin::slot_delete);
		if (option == 2)
			delete_btn->hide();

		line = new QLineEdit(this);
		line->move(130, 250);
		line->resize(240, 30);

		flight = new QRadioButton("航班", this);
		flight->move(200, 50);
		hotel = new QRadioButton("旅馆", this);
		hotel->move(200, 100);
		bus = new QRadioButton("公交车", this);
		bus->move(200, 150);

		group = new QButtonGroup(this);
		group->addButton(flight, 1);
		group->addButton(hotel, 2);
		group->addButton(bus, 3);
		line->setPlaceholderText("请输入想预订的航班/旅馆/公交");
	}
	if (option == 2)
	{
		setWindowTitle("系统管理");
		back_btn->move(180,325);
		admin_line = new QLineEdit(this);
		admin_line->setPlaceholderText("请输入操作命令");
		admin_line->move(30, 10);
		admin_line->resize(380,30);
		output_text = new QTextEdit(this);
		output_text->isReadOnly();

		admin_line->setStyleSheet("background-color:rgba(0,0,0,0)");
		output_text->setStyleSheet("background-color:rgba(0,0,0,0)");

		QPushButton* admin_btn = new QPushButton("提交", this);
		admin_btn->move(420, 10);
		admin_btn->resize(40,30);
		connect(admin_btn, &QPushButton::clicked, this, &childwin::slot_system_option);

		output_text->move(30, 50);
		output_text->resize(420,270);

	}
}

void childwin::slot_resv()
{
	if (group->checkedId()==1) {
		if(!mysql.resv_sql(tmp_mysql, customer_name, 1, line->text().toStdString().c_str()))
			QMessageBox::warning(this, "提示", "订购成功!", QMessageBox::Yes);
		else
			QMessageBox::warning(this, "提示", "输入信息有误!", QMessageBox::Yes);
		}
	if(group->checkedId()==2){
		if (!mysql.resv_sql(tmp_mysql, customer_name, 2,  line->text().toStdString().c_str()))
			QMessageBox::warning(this, "提示", "订购成功!", QMessageBox::Yes);
		else
			QMessageBox::warning(this, "提示", "输入信息有误!", QMessageBox::Yes);
		}
	if(group->checkedId()==3) {
		if (!mysql.resv_sql(tmp_mysql, customer_name, 3, line->text().toStdString().c_str()))
			QMessageBox::warning(this, "提示", "订购成功!", QMessageBox::Yes);
		else
			QMessageBox::warning(this, "提示", "输入信息有误!", QMessageBox::Yes);
	}
	line->clear();
}
void childwin::slot_delete()
{
	if (group->checkedId() == 1) {
		if (!mysql.delete_sql(tmp_mysql, customer_name, 1, line->text().toStdString().c_str()))
			QMessageBox::warning(this, "提示", "删除成功!", QMessageBox::Yes);
		else
			QMessageBox::warning(this, "提示", "输入信息有误!", QMessageBox::Yes);
	}
	if (group->checkedId() == 2) {
		if (!mysql.delete_sql(tmp_mysql, customer_name, 2, line->text().toStdString().c_str()))
			QMessageBox::warning(this, "提示", "删除成功!", QMessageBox::Yes);
		else
			QMessageBox::warning(this, "提示", "输入信息有误!", QMessageBox::Yes);
	}
	if (group->checkedId() == 3) {
		if (!mysql.delete_sql(tmp_mysql, customer_name, 3, line->text().toStdString().c_str()))
			QMessageBox::warning(this, "提示", "删除成功!", QMessageBox::Yes);
		else
			QMessageBox::warning(this, "提示", "输入信息有误!", QMessageBox::Yes);
	}
	line->clear();
}
void childwin::slot_system_option()
{
	string tmp;
	QString qstr;
	char cmd[100];
	tmp = admin_line->text().toStdString();
	strcpy(cmd, tmp.c_str());
	if (mysql_query(tmp_mysql, cmd))
	{
		output_text->append("mysql query error:");
		output_text->append(mysql_error(tmp_mysql));
		admin_line->clear();
	}
	else
	{
		output_text->append("operated successfully");
		mysql_free_result(res);
		res = mysql_store_result(tmp_mysql);
		unsigned int column = mysql_num_fields(res);
		while (rows = mysql_fetch_row(res))
		{
			tmp = "";
			for (int i = 0; i < column; i++)
			{
				tmp = tmp + "  " + rows[i]+"  ";
			}
			output_text->append(QString::fromStdString(tmp));
		}
		admin_line->clear();
	}
}
childwin::~childwin()
{
	mysql_close(tmp_mysql);
}
void childwin::slot_back_to_main()
{
	this->close();
	emit sendsignal();
}