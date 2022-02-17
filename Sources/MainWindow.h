#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DeveloperQW.h"
#include <QFile>
#include <QMainWindow>
#include <QSet>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  private slots:
    void OnEnterButtonClicked();     // enterButton, нажатие
    void OnDeveloperButtonClicked(); // developerButton, нажатие

  private:
    Ui::MainWindow* ui; // Интерфейс пользователя

    QFile file1;
    QFile file2;
    QFile keyFile;

    QString fileName1;   // Имя для file2
    QString fileName2;   // Имя для file2
    QString keyFileName; // Имя для keyFile

    // Хранилище для байт
    QByteArray byteArray; // Массив байт
    QSet<char> byteSet;   // Множество байт
    QList<char> byteList; // Список байт

    // Хранилище информации для ключа
    QString key;                  // Ключ шифровки-расшифровки
    QList<QString> keyListString; // Список значений ключа, строки
    QList<int> keyListInt;        // Список значений ключа, числа

    DeveloperQW* developerQW; // Форма, разработчик

    // Обработчики выбора для радио кнопок
    void FileInfoRBCheckedLogics();      // infoRB
    void EncryptionRBCheckedLogics();    // encryptionRB
    void DecryptionRBCkechedLogics();    // decryptionRB
    void KeyGenerationRBCkeckedLogics(); // keyGenerationRB

    bool OpenFile(QTextEdit* textEdit, QFile& file, QString& fileName); // Открытие файла

    bool OpenFileForInfo();          // Открытие файлов для отображения информации
    bool OpenFilesForEDcryption();   // Открытие файлов для шифрования
    bool OpenFileForKeyGeneration(); // Открытие файлов для генерации ключа

    void CloseFiles(); // Закрытие файлов

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    // Сохранение информации о файле
    void PrintSize();                   // Размер
    void PrintBytesFrequency();         // Байты, частота
    void PrintBytesRelativeFrequency(); // Байты, относительная частота

    void SaveEnDecKey(); // Сохранение ключа шифрования
    void GenerateKey();  // Генерация ключа шифрования

    void GenerateKeyForEasyReplacement();     // Генерирование ключа для шифра простой замены
    void GenerateKeyForVerticalPermutation(); // Генерирования ключа для шифра вертикальной перестановки

    void EncryptFile(); // Зашифровать file1 в file2
    void DecryptFile(); // Дешифровать file1 в file2

    void EasyReplacementEncryptByteArray(); // Зашифровать последовательность байт, простая замена
    void EasyReplacementDecryptByteArray(); // Расшифровать последовательность байт, простая замена

    void VerticalPermutationEncryptByteArray(); // Зашифровать последовательность байт, вертикальная перестановка
    void VerticalPermutationDecryptByteArray(); // Расшифровать последовательность байт, вертикальная перестановка
};
#endif // MAINWINDOW_H
