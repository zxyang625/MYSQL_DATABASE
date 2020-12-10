#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include"mymysql.h"
#include <QDialog>
#include<Qstring.h>
#include<QButtonGroup>
#include<QRadioButton>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QMessageBox>
#pragma execution_character_set("utf-8")
class QLabel;    
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    LoginDialog(QWidget* parent = 0);
    ~LoginDialog();
private:
    Mysql sql_tmp;
    QLineEdit* usrLineEdit;//用户名
    QLineEdit* pwdLineEdit;//密码
    QButtonGroup* group;
    QLabel* usrLabel;
    QLabel* pwdLabel;
    QPushButton* loginBtn;//登录按钮
    QPushButton* exitBtn;//退出按钮
    QRadioButton* user;//用户选项
    QRadioButton* admin;//管理员选项

public:
    string getusr();//返回输入的用户名
    string getpwd();//返回输入的密码
    void login();//槽函数——登录
};
#endif // LOGINDIALOG_H