#ifndef DEVELOPERQW_H
#define DEVELOPERQW_H

#include <QWidget>

namespace Ui {
class DeveloperQW;
}

class DeveloperQW : public QWidget {
    Q_OBJECT

  public:
    explicit DeveloperQW(QWidget* parent = nullptr);
    ~DeveloperQW();

  private slots: // Обработчики событий

    void onEnterButtonClicked(); // enterButton, нажатие

  private:
    Ui::DeveloperQW* ui; // Интерфейс пользователя
};

#endif // DEVELOPERQW_H
