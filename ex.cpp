#include "ex.h"


ex::ex(QWidget *parent)
    : QWidget(parent)
{
    wifi = new QWidget;
    wifi_name_Label = new QLabel("Ady",wifi);
    wifi_password_Label = new QLabel("Parol",wifi);
    wifi_progOwner_Label = new QLabel("©M.E",wifi);
    wifi_name_LineEdit = new QLineEdit(wifi);
    wifi_password_LineEdit = new QLineEdit(wifi);
    wifi_create_PushButton = new QPushButton("Doret",wifi);
    wifi_clear_PushButton = new QPushButton("Arassala",wifi);
    wifi_vb_VBoxLayout = new QVBoxLayout;
    wifi_hb_HBoxLayout = new QHBoxLayout;
    wifi_vb_VBoxLayout->addWidget(wifi_name_Label);
    wifi_vb_VBoxLayout->addWidget(wifi_name_LineEdit);
    wifi_vb_VBoxLayout->addWidget(wifi_password_Label);
    wifi_vb_VBoxLayout->addWidget(wifi_password_LineEdit);
    wifi_hb_HBoxLayout->addWidget(wifi_create_PushButton);
    wifi_hb_HBoxLayout->addWidget(wifi_clear_PushButton);
    wifi_vb_VBoxLayout->addLayout(wifi_hb_HBoxLayout);
    wifi_vb_VBoxLayout->addWidget(wifi_progOwner_Label);
    wifi->setLayout(wifi_vb_VBoxLayout);
    wifi->setFixedSize(350,150);
    wifi->setWindowTitle("WiFi Nokat Dorediji");
    wifi->show();
    connect(wifi_create_PushButton,SIGNAL(clicked()),SLOT(wifi_create_PushButtonSlot()));
    connect(wifi_clear_PushButton,SIGNAL(clicked()),SLOT(wifi_clear_PushButtonSlot()));
}

ex::~ex()
{
}
//functions
void ex::wifi_clearLineEdit()
{
    wifi_name_LineEdit->clear();
    wifi_password_LineEdit->clear();
}
//slots
void ex::wifi_create_PushButtonSlot()
{
    if(wifi_name_LineEdit->text().isEmpty() || wifi_password_LineEdit->text().isEmpty())
    {
        QMessageBox::about(this,"Yalnyshlyk","Yerleri doldur!");
        wifi_clearLineEdit();
    }
    else if(wifi_password_LineEdit->text().size()<8)
    {
        QMessageBox::about(this,"Yalnyshlyk","Parolynyzy uzaldyn!");
        wifi_password_LineEdit->clear();
    }
    else
    {
        QString comd;
        comd = "netsh wlan set hostednetwork mode=allow ssid="+wifi_name_LineEdit->text()+" key="+wifi_password_LineEdit->text()+"";
        system(comd.toLocal8Bit());
        system("netsh wlan start hostednetwork");
        system("echo HotSpot created");
        system("exit");
        QMessageBox::about(this,"Jogap","WiFi nokat doredildi!");
    }
}
void ex::wifi_clear_PushButtonSlot()
{
    wifi_clearLineEdit();
}
