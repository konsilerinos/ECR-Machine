/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *logLabel;
    QLabel *instructionLabel;
    QPushButton *developerButton;
    QPushButton *enterButton;
    QTextEdit *logTextEdit;
    QGroupBox *encryptionBox;
    QRadioButton *encryptionRB;
    QRadioButton *decryptionRB;
    QRadioButton *fileInfoRB;
    QRadioButton *keyGenerationRB;
    QGroupBox *groupBox_2;
    QTextEdit *file1NameText;
    QTextEdit *file2NameText;
    QTextEdit *keyFileNameText;
    QGroupBox *groupBox_3;
    QRadioButton *easyReplacementRB;
    QRadioButton *verticalPermutationRB;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1091, 641);
        MainWindow->setMinimumSize(QSize(1091, 641));
        MainWindow->setMaximumSize(QSize(1091, 641));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        logLabel = new QLabel(centralwidget);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));
        logLabel->setGeometry(QRect(260, 10, 821, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        logLabel->setFont(font);
        logLabel->setStyleSheet(QString::fromUtf8("QLabel#logLabel {\n"
"\n"
"	background-color: #F5CB5C;\n"
"	border: 2px solid #242423;\n"
"	color: #242423;\n"
"}"));
        logLabel->setAlignment(Qt::AlignCenter);
        instructionLabel = new QLabel(centralwidget);
        instructionLabel->setObjectName(QString::fromUtf8("instructionLabel"));
        instructionLabel->setGeometry(QRect(10, 10, 241, 41));
        instructionLabel->setFont(font);
        instructionLabel->setStyleSheet(QString::fromUtf8("QLabel#instructionLabel {\n"
"\n"
"	background-color: #F5CB5C;\n"
"	border: 2px solid #242423;\n"
"	color: #242423;\n"
"}"));
        instructionLabel->setAlignment(Qt::AlignCenter);
        developerButton = new QPushButton(centralwidget);
        developerButton->setObjectName(QString::fromUtf8("developerButton"));
        developerButton->setGeometry(QRect(10, 460, 241, 171));
        QFont font1;
        font1.setPointSize(12);
        developerButton->setFont(font1);
        developerButton->setStyleSheet(QString::fromUtf8("QPushButton#developerButton {\n"
"\n"
"	border: 2px solid #242423;\n"
"	background-image: url(:/Resources/DeveloperButton.png);\n"
"}\n"
"\n"
"QPushButton#developerButton:hover {\n"
"\n"
"	border: 2px solid #242423;\n"
"}\n"
"\n"
"QPushButton#developerButton:pressed {\n"
"\n"
"	border: 2px solid #242423;\n"
"}\n"
""));
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(10, 410, 241, 41));
        enterButton->setFont(font1);
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
        logTextEdit = new QTextEdit(centralwidget);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setGeometry(QRect(260, 60, 821, 571));
        logTextEdit->setFont(font1);
        logTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit#logTextEdit {\n"
"\n"
"	border: 2px solid #1A3344;\n"
"}"));
        encryptionBox = new QGroupBox(centralwidget);
        encryptionBox->setObjectName(QString::fromUtf8("encryptionBox"));
        encryptionBox->setGeometry(QRect(10, 210, 241, 111));
        encryptionRB = new QRadioButton(encryptionBox);
        encryptionRB->setObjectName(QString::fromUtf8("encryptionRB"));
        encryptionRB->setGeometry(QRect(10, 20, 221, 21));
        encryptionRB->setStyleSheet(QString::fromUtf8(""));
        decryptionRB = new QRadioButton(encryptionBox);
        decryptionRB->setObjectName(QString::fromUtf8("decryptionRB"));
        decryptionRB->setGeometry(QRect(10, 40, 221, 21));
        fileInfoRB = new QRadioButton(encryptionBox);
        fileInfoRB->setObjectName(QString::fromUtf8("fileInfoRB"));
        fileInfoRB->setGeometry(QRect(10, 60, 221, 21));
        keyGenerationRB = new QRadioButton(encryptionBox);
        keyGenerationRB->setObjectName(QString::fromUtf8("keyGenerationRB"));
        keyGenerationRB->setGeometry(QRect(10, 80, 221, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 60, 241, 141));
        file1NameText = new QTextEdit(groupBox_2);
        file1NameText->setObjectName(QString::fromUtf8("file1NameText"));
        file1NameText->setGeometry(QRect(10, 20, 221, 31));
        file1NameText->setFont(font1);
        file1NameText->setStyleSheet(QString::fromUtf8("QTextEdit#file1NameText {\n"
"\n"
"	border: 2px solid #1A3344;\n"
"}"));
        file2NameText = new QTextEdit(groupBox_2);
        file2NameText->setObjectName(QString::fromUtf8("file2NameText"));
        file2NameText->setGeometry(QRect(10, 60, 221, 31));
        file2NameText->setFont(font1);
        file2NameText->setStyleSheet(QString::fromUtf8("QTextEdit#file2NameText {\n"
"\n"
"	border: 2px solid #1A3344;\n"
"}"));
        keyFileNameText = new QTextEdit(groupBox_2);
        keyFileNameText->setObjectName(QString::fromUtf8("keyFileNameText"));
        keyFileNameText->setGeometry(QRect(10, 100, 221, 31));
        keyFileNameText->setFont(font1);
        keyFileNameText->setStyleSheet(QString::fromUtf8("QTextEdit#keyFileNameText {\n"
"\n"
"	border: 2px solid #1A3344;\n"
"}"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 330, 241, 71));
        easyReplacementRB = new QRadioButton(groupBox_3);
        easyReplacementRB->setObjectName(QString::fromUtf8("easyReplacementRB"));
        easyReplacementRB->setGeometry(QRect(10, 20, 221, 21));
        easyReplacementRB->setStyleSheet(QString::fromUtf8(""));
        verticalPermutationRB = new QRadioButton(groupBox_3);
        verticalPermutationRB->setObjectName(QString::fromUtf8("verticalPermutationRB"));
        verticalPermutationRB->setGeometry(QRect(10, 40, 221, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\273\321\214\320\275\320\260\321\217 \320\274\320\260\321\210\320\270\320\275\320\260", nullptr));
        logLabel->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\263", nullptr));
        instructionLabel->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\320\270", nullptr));
        developerButton->setText(QString());
        enterButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", nullptr));
        encryptionBox->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274", nullptr));
        encryptionRB->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        decryptionRB->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        fileInfoRB->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\264\320\273\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
        keyGenerationRB->setText(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\217 \320\272\320\273\321\216\321\207\320\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273\321\213", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        easyReplacementRB->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\321\202\320\260\321\217 \320\267\320\260\320\274\320\265\320\275\320\260", nullptr));
        verticalPermutationRB->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\265\321\200\320\265\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
