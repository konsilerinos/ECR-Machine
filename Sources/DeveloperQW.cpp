#include "DeveloperQW.h"
#include "ui_DeveloperQW.h"

DeveloperQW::DeveloperQW(QWidget* parent) : QWidget(parent), ui(new Ui::DeveloperQW) {

    ui->setupUi(this); // Интерфейс пользователя

    // Обработчик события: нажатие
    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(onEnterButtonClicked())); // enterButton

    // Сохранение текста
    ui->fioLineEdit->setText("Слесарев Николай Сергеевич"); // fioLineEdit
    ui->gitHubLineEdit->setText("konsilerinos");            // gitHubLineEdit
    ui->mailLineEdit->setText("n_slesarev@mail.ru");        // mailLineEdit

    // Блокировка
    ui->fioLineEdit->setReadOnly(true);    // fioLineEdit
    ui->gitHubLineEdit->setReadOnly(true); // gitHubLineEdit
    ui->mailLineEdit->setReadOnly(true);   // mailLineEdit
}

DeveloperQW::~DeveloperQW() {
    delete ui; // Интерфейс пользователя
}

// enterButton, нажатие
void DeveloperQW::onEnterButtonClicked() {

    this->close(); // Закрытие формы информации о разработчике
}
