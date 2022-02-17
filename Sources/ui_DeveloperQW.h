/********************************************************************************
** Form generated from reading UI file 'DeveloperQW.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOPERQW_H
#define UI_DEVELOPERQW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeveloperQW
{
public:
    QLineEdit *gitHubLineEdit;
    QLabel *text1;
    QLineEdit *mailLineEdit;
    QPushButton *enterButton;
    QLabel *text3;
    QLineEdit *fioLineEdit;
    QLabel *helpHead;
    QLabel *text2;

    void setupUi(QWidget *DeveloperQW)
    {
        if (DeveloperQW->objectName().isEmpty())
            DeveloperQW->setObjectName(QString::fromUtf8("DeveloperQW"));
        DeveloperQW->resize(571, 261);
        DeveloperQW->setMinimumSize(QSize(571, 261));
        DeveloperQW->setMaximumSize(QSize(571, 261));
        gitHubLineEdit = new QLineEdit(DeveloperQW);
        gitHubLineEdit->setObjectName(QString::fromUtf8("gitHubLineEdit"));
        gitHubLineEdit->setGeometry(QRect(110, 110, 451, 41));
        QFont font;
        font.setPointSize(14);
        gitHubLineEdit->setFont(font);
        gitHubLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit#gitHubLineEdit {\n"
"\n"
"	border: 2px solid #333533;\n"
"}"));
        text1 = new QLabel(DeveloperQW);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 91, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	border: 2px solid #242423;\n"
"	color: #242423;\n"
"}"));
        mailLineEdit = new QLineEdit(DeveloperQW);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));
        mailLineEdit->setGeometry(QRect(110, 160, 451, 41));
        mailLineEdit->setFont(font);
        mailLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit#mailLineEdit {\n"
"\n"
"	border: 2px solid #333533;\n"
"}"));
        enterButton = new QPushButton(DeveloperQW);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(10, 210, 551, 41));
        QFont font2;
        font2.setPointSize(12);
        enterButton->setFont(font2);
        enterButton->setStyleSheet(QString::fromUtf8("QPushButton#enterButton {\n"
"\n"
"	background-color: #284B63;\n"
"	border: 2px solid #333533;\n"
"	color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton#enterButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #333533;\n"
"}\n"
"\n"
"QPushButton#enterButton:pressed {\n"
"\n"
"	background-color: #F5CB5C;\n"
"}\n"
""));
        text3 = new QLabel(DeveloperQW);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 91, 41));
        text3->setFont(font1);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	border: 2px solid #242423;\n"
"	color: #242423;\n"
"}"));
        fioLineEdit = new QLineEdit(DeveloperQW);
        fioLineEdit->setObjectName(QString::fromUtf8("fioLineEdit"));
        fioLineEdit->setGeometry(QRect(110, 60, 451, 41));
        fioLineEdit->setFont(font);
        fioLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit#fioLineEdit {\n"
"\n"
"	border: 2px solid #333533;\n"
"}"));
        helpHead = new QLabel(DeveloperQW);
        helpHead->setObjectName(QString::fromUtf8("helpHead"));
        helpHead->setGeometry(QRect(10, 10, 551, 41));
        helpHead->setFont(font1);
        helpHead->setStyleSheet(QString::fromUtf8("QLabel#helpHead {\n"
"\n"
"	background-color: #F5CB5C;\n"
"	border: 2px solid #242423;\n"
"	color: #242423;\n"
"}"));
        helpHead->setAlignment(Qt::AlignCenter);
        text2 = new QLabel(DeveloperQW);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 91, 41));
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	border: 2px solid #242423;\n"
"	color: #242423;\n"
"}"));

        retranslateUi(DeveloperQW);

        QMetaObject::connectSlotsByName(DeveloperQW);
    } // setupUi

    void retranslateUi(QWidget *DeveloperQW)
    {
        DeveloperQW->setWindowTitle(QApplication::translate("DeveloperQW", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272", nullptr));
        text1->setText(QApplication::translate("DeveloperQW", "\320\244\320\230\320\236", nullptr));
        enterButton->setText(QApplication::translate("DeveloperQW", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        text3->setText(QApplication::translate("DeveloperQW", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        helpHead->setText(QApplication::translate("DeveloperQW", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272", nullptr));
        text2->setText(QApplication::translate("DeveloperQW", "GitHub", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeveloperQW: public Ui_DeveloperQW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPERQW_H
