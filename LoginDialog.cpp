#include "LoginDialog.h"
#pragma execution_character_set("utf-8")
LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("登录界面");
    usrLabel = new QLabel(this);
    usrLabel->move(70, 85);
    usrLabel->setText("用户名:");
    usrLineEdit = new QLineEdit(this);
    usrLineEdit->move(140, 80);
    usrLineEdit->setPlaceholderText("请输入用户名:");
    usrLineEdit->setClearButtonEnabled(1);

    pwdLabel = new QLabel(this);
    pwdLabel->move(70, 135);
    pwdLabel->setText("密码:");
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140, 130);
    pwdLineEdit->setPlaceholderText("请输入密码:");
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    pwdLineEdit->setClearButtonEnabled(1);

    loginBtn = new QPushButton(this);
    loginBtn->move(50, 200);
    loginBtn->setText("登录");
    exitBtn = new QPushButton(this);
    exitBtn->move(210, 200);
    exitBtn->setText("退出");
    connect(loginBtn,&QPushButton::clicked, this, &LoginDialog::login);
    connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);

    group = new QButtonGroup(this);//将用户选项和管理员选项添加一个Group中
    user = new QRadioButton(tr("用户登录"), this);
    admin = new QRadioButton(tr("管理员登录"), this);
    group->addButton(user, 1);
    group->addButton(admin, 2);
    user->move(30, 30);
    admin->move(200, 30);

    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix1/44.jpg);}");//设置背景图片
}
void LoginDialog::login()//槽函数——登录
{
    if ((sql_tmp.identify(usrLineEdit->text().trimmed(),pwdLineEdit->text().trimmed()) && group->checkedId() == 1)||(usrLineEdit->text().trimmed() == "yzx" && pwdLineEdit->text().trimmed() == "123456" && group->checkedId() == 2))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, "警告!", "用户名和密码错误!", QMessageBox::Yes);
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}

LoginDialog::~LoginDialog()
{
}
string LoginDialog::getusr()//返回输入的用户名
{
    string usr = usrLineEdit->text().toStdString();
    return usr;
}
string LoginDialog::getpwd()//返回输入的密码
{
    string pwd = pwdLineEdit->text().toStdString();
    return pwd;
}
