#ifndef EX_H
#define EX_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <stdlib.h>
class ex : public QWidget
{
    Q_OBJECT
public:
    void wifi_clearLineEdit();
    ex(QWidget *parent = 0);
    ~ex();
private:
    QWidget *wifi;
    QLabel *wifi_name_Label;
    QLabel *wifi_password_Label;
    QLabel *wifi_progOwner_Label;
    QLineEdit *wifi_name_LineEdit;
    QLineEdit *wifi_password_LineEdit;
    QPushButton *wifi_create_PushButton;
    QPushButton *wifi_clear_PushButton;
    QVBoxLayout *wifi_vb_VBoxLayout;
    QHBoxLayout *wifi_hb_HBoxLayout;
private slots:
    void wifi_create_PushButtonSlot();
    void wifi_clear_PushButtonSlot();
};

#endif // EX_H
