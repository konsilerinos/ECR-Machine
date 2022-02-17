#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QChar>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QSet>
#include <QTime>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this); // Интерфейс пользователя

    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(OnEnterButtonClicked()));         // enterButton, нажатие
    connect(ui->developerButton, SIGNAL(clicked()), this, SLOT(OnDeveloperButtonClicked())); // developerButton, нажатие

    ui->logTextEdit->setText("[Debug(), MainQMW]\n"); // Заголовок для лога
    ui->logTextEdit->setReadOnly(true);               // Заблокировать редактирование

    // Сохранение пояснений в текстовые поля ввода
    ui->file1NameText->setPlaceholderText("File1");
    ui->file2NameText->setPlaceholderText("File2");
    ui->keyFileNameText->setPlaceholderText("KeyFile");

    // Сохранение пояснений в лог
    Debug("[Справка] File1 - объект шифрования и справки");
    Debug("[Справка] File2 - выход шифрования");
    Debug("[Справка] KeyFile - запись/чтение ключа\n");

    developerQW = new DeveloperQW(); // Форма, разработчик
}

MainWindow::~MainWindow() {

    delete ui; // Интерфейс пользователя
}

// enterButton, нажатие
void MainWindow::OnEnterButtonClicked() {

    FileInfoRBCheckedLogics(); // Обработчики нажатий: infoRB

    // Не выбран механизм шифрования
    if (!((ui->easyReplacementRB->isChecked()) || (ui->verticalPermutationRB->isChecked()))) {

        Debug("[Не выбран режим шифрования/расшифрования]"); // Отладочное сообщение
        return;
    }

    EncryptionRBCheckedLogics();    // Обработчик нажатий: encryptionRB
    DecryptionRBCkechedLogics();    // Обработчик нажатий: decryptionRB
    KeyGenerationRBCkeckedLogics(); // Обработчики нажатий: keyGeneration

    CloseFiles(); // Закрытие файлов
}

// developerButton, нажатие
void MainWindow::OnDeveloperButtonClicked() {

    developerQW->setWindowModality(Qt::ApplicationModal); // Режим открытия
    developerQW->show();                                  // Окно, разработчик
}

// Обработчики нажатий: infoRB
void MainWindow::FileInfoRBCheckedLogics() {

    // Режим информации
    if (ui->fileInfoRB->isChecked()) {

        Debug("\n[Информация для файла]");
        if (OpenFileForInfo()) {

            // Вывод информации о файле
            PrintSize();                   // Размер
            PrintBytesFrequency();         // Сохранение информации о файле: частота
            PrintBytesRelativeFrequency(); // Сохранение информации о файле: относительная частота
        }
    }
}

// Обработчики выбора для радио кнопок: encryptionRB
void MainWindow::EncryptionRBCheckedLogics() {

    // Режим шифрования
    if (ui->encryptionRB->isChecked()) {

        Debug("\n[Шифрование]");

        if (OpenFilesForEDcryption()) {

            EncryptFile(); // Шифрование
        }
    }
}

// Обработчики выбора для радио кнопок: decryptionRB
void MainWindow::DecryptionRBCkechedLogics() {

    // Режим шифрования
    if (ui->decryptionRB->isChecked()) {

        Debug("\n[Шифрование]");

        if (OpenFilesForEDcryption()) {

            DecryptFile(); // Расшифрование
        }
    }
}

// Обработчики выбора для радио кнопок: keyGeneration
void MainWindow::KeyGenerationRBCkeckedLogics() {

    // Режим шифрования
    if (ui->keyGenerationRB->isChecked()) {

        Debug("\n[Генерация ключа]");

        if (OpenFileForKeyGeneration()) {

            GenerateKey(); // Генерация ключа
        }
    }
}

// Открытие файла
bool MainWindow::OpenFile(QTextEdit* textEdit, QFile& file, QString& fileName) {

    fileName = textEdit->toPlainText(); // Сохранение имени
    file.setFileName(fileName);         // Присвоение имени файлу

    if (fileName != "") {

        file.open(QFile::ReadWrite); // Открытие файла на чтение и запись

        if (file.isOpen()) {

            Debug("[Файл открыт] \"" + fileName + "\""); // Отладочное сообщение

            return true;
        }
    }

    Debug("[Файл не открыт] \"" + fileName + "\""); // Отладочное сообщение

    return false;
}

// Открытие файлов для отображения информации
bool MainWindow::OpenFileForInfo() {

    if (OpenFile(ui->file1NameText, file1, fileName1)) {

        return true; // Файл открыт
    }

    CloseFiles(); // Закрытие ранее открытых файлов
    return false; // Файл не открыт
}

// Открытие файлов для шифрования
bool MainWindow::OpenFilesForEDcryption() {

    bool openCondition = OpenFile(ui->file1NameText, file1, fileName1);
    openCondition = openCondition && OpenFile(ui->file2NameText, file2, fileName2);
    openCondition = openCondition && OpenFile(ui->keyFileNameText, keyFile, keyFileName);

    if (openCondition) {

        return true; // Файлы открыты
    }

    CloseFiles(); // Закрытие ранее открытых файлов
    return false; // Файлы не открыты
}

// Открытие файлов для генерации ключа
bool MainWindow::OpenFileForKeyGeneration() {

    if (OpenFile(ui->keyFileNameText, keyFile, keyFileName)) {

        return true; // Файл открыт
    }

    CloseFiles(); // Закрытие ранее открытых файлов
    return false; // Файл не открыт
}

// Закрытие файлов
void MainWindow::CloseFiles() {

    // Закрыть file1
    if (file1.isOpen())
        file1.close();

    // Закрыть file2
    if (file2.isOpen())
        file2.close();

    // Закрыть keyFile
    if (keyFile.isOpen())
        keyFile.close();
}

// Сохранение отладочного сообщения в лог
void MainWindow::Debug(QString message) {

    ui->logTextEdit->setText(ui->logTextEdit->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logTextEdit->moveCursor(QTextCursor::End);                             // Прокрутка блока текста с логом вниз
}

// Сохранение информации о файле: размер
void MainWindow::PrintSize() {

    QString message = "[Информация] Размер \"%1\": %2 байт";
    message = message.arg(fileName1).arg(QString::number(file1.size()));

    Debug(message); // Сохранение отладочного сообщения в лог
}

// Сохранение информации о файле: частота
void MainWindow::PrintBytesFrequency() {

    byteArray = file1.readAll(); // Сохранение байт в byteArray

    if (byteArray.size() == 0) {

        Debug("[Частота байт] Файл пустой"); // Отладочное сообщение
        return;
    }

    Debug("[Частоты]");

    // Запись множества байт
    for (int i = 0; i < byteArray.size(); i++) {

        byteSet.insert(byteArray.at(i));
    }
    byteList = byteSet.toList(); // Конвертирование в список

    qSort(byteList.begin(), byteList.end());

    // Подсчёт частот
    for (int i = 0; i < byteList.size(); i++) {

        Debug("count(" + QString(byteList.at(i)) + ") = " + QString::number(byteArray.count(byteList.at(i))));
    }
}

// Сохранение информации о файле: относительная частота
void MainWindow::PrintBytesRelativeFrequency() {

    // В byteArray уже сохранены байты

    if (byteArray.size() == 0) {

        Debug("[Относительная частота байт] Файл пустой"); // Отладочное сообщение
        return;
    }

    Debug("[Относительные частоты]");

    // Запись множества байт
    for (int i = 0; i < byteArray.size(); i++) {

        byteSet.insert(byteArray.at(i));
    }
    byteList = byteSet.toList(); // Конвертирование в список

    qSort(byteList.begin(), byteList.end());

    // Подсчёт частот
    for (int i = 0; i < byteList.size(); i++) {

        double relativeFrequency = (double)byteArray.count(byteList.at(i)) / byteArray.size() * 100; // Относительная частота
        Debug("ОЧ(" + QString(byteList.at(i)) + ") = " + QString::number(relativeFrequency) + "%");  // Отладочное сообщение
    }
}

// Сохранение ключа шифрования
void MainWindow::SaveEnDecKey() {

    keyListString.clear();
    keyListInt.clear();

    QByteArray keyByteArray = keyFile.readAll(); // Чтение keyFile

    QString str = keyByteArray;     // Ключ, строка
    keyListString = str.split(' '); // Ключ, строки

    for (int i = 0; i < keyListString.size(); i++) {

        keyListInt.append(keyListString.at(i).toInt()); // Ключ, числа
    }
}

// Генерация ключа шифрования
void MainWindow::GenerateKey() {

    // Генерация ключа для шифра простой замены
    if (ui->easyReplacementRB->isChecked()) {

        Debug("[Шифр простой замены]");
        GenerateKeyForEasyReplacement();
    }
    // Генерация ключа для шифра вертикальной перестановки
    else if (ui->verticalPermutationRB->isChecked()) {

        Debug("[Шифр вертикальной перестановки]");
        GenerateKeyForVerticalPermutation();
    }

    keyFile.resize(0);        // Очистка файла
    keyFile.write(byteArray); // Запись ключа в файл

    Debug("[Генерация ключа завершена]");
}

// Генерирование ключа для шифра простой замены
void MainWindow::GenerateKeyForEasyReplacement() {

    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime())); // Рандом

    byteArray.clear();

    for (int i = 0; i < 1000; i++) {

        char c = qrand() % 256;
        byteArray.append(c);
    }
}

// Генерирования ключа для шифра вертикальной перестановки
void MainWindow::GenerateKeyForVerticalPermutation() {

    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime())); // Рандом

    keyListInt.clear();

    // Сохранение значений в массив байт
    for (int i = 0; i < 250; i++) {

        keyListInt.append(i + 1);
    }

    // Перемешивание массива байт
    for (int i = keyListInt.size() - 1; i >= 1; i--) {

        int j = rand() % (i + 1);

        int temp = keyListInt[j];
        keyListInt[j] = keyListInt[i];
        keyListInt[i] = temp;
    }

    // Перевод списка чисел с список строк
    QStringList strList;
    for (int i = 0; i < keyListInt.size(); i++) {

        strList.append(QString::number(keyListInt.at(i)));
    }

    byteArray.clear();

    QString str = strList.join(" "); // Объединение строк
    byteArray = str.toUtf8().data(); // Сохранение строки в массив байт
}

// Зашифровать file1 в file2
void MainWindow::EncryptFile() {

    byteArray = file1.readAll(); // Чтение файла

    // Простая замена
    if (ui->easyReplacementRB->isChecked()) {

        Debug("[Начало шифрования простой заменой]"); // Отладочное сообщение
        EasyReplacementEncryptByteArray();            // Расшифровка, простая замена
    }
    // Вертикальная перестановка
    else if (ui->verticalPermutationRB->isChecked()) {

        Debug("[Начало шифрования вертикальной перестановкой]"); // Отладочное сообщение
        VerticalPermutationEncryptByteArray();                   // Шифровка, вертикальная перестановка
    }

    byteArray.reserve(byteArray.size()); // Резервирование места

    file2.resize(0);        // Очистка файла
    file2.write(byteArray); // Запись зашифрованной последовательности байт

    Debug("[Шифрование завершено]");
}

// Дешифровать file1 в file2
void MainWindow::DecryptFile() {

    Debug("[Начало дешифрования]");

    byteArray = file1.readAll(); // Чтение файла

    // Простая замена
    if (ui->easyReplacementRB->isChecked()) {

        Debug("[Начато дешифрование простой заменой]"); // Отладочное сообщение
        EasyReplacementDecryptByteArray();              // Расшифровка, простая замена
    }
    // Вертикальная перестановка
    else if (ui->verticalPermutationRB->isChecked()) {

        Debug("[Начато дешифрование вертикальной перестановкой]"); // Отладочное сообщение
        VerticalPermutationDecryptByteArray();                     // Расшифровка, вертикальная перестановка
    }

    byteArray.reserve(byteArray.size()); // Резервирование места

    file2.resize(0);        // Очистка файла
    file2.write(byteArray); // Запись расшифрованной последовательности байт

    Debug("[Дешифрование завершено]");
}

// Зашифровать последовательность байт
void MainWindow::EasyReplacementEncryptByteArray() {

    QByteArray keyByteArray = keyFile.readAll(); // Чтение keyFile
    key = keyByteArray.data();                   // Сохранение массива байт в строеу key

    // Алгоритм шифрования
    for (int i = 0; i < byteArray.size(); i++) {

        int size = key.size();                                    // Размер ключа
        byteArray[i] = byteArray[i] + key.at(i % size).unicode(); // Шифровка
    }
}

// Расшифровать последовательность байт
void MainWindow::EasyReplacementDecryptByteArray() {

    QByteArray keyByteArray = keyFile.readAll(); // Чтение keyFile
    key = keyByteArray.data();                   // Сохранение массива байт в строеу key

    // Алгоритм расшифрования
    for (int i = 0; i < byteArray.size(); i++) {

        int size = key.size();                                    // Размер ключа
        byteArray[i] = byteArray[i] - key.at(i % size).unicode(); // Расшифровка
    }
}

// Зашифровать последовательность байт, вертикальная перестановка
void MainWindow::VerticalPermutationEncryptByteArray() {

    // Сохранение ключа дешифровки
    keyListString.clear();
    keyListInt.clear();

    QByteArray keyByteArray = keyFile.readAll(); // Чтение keyFile

    QString str = keyByteArray;     // Ключ, строка
    keyListString = str.split(' '); // Ключ, строки

    for (int i = 0; i < keyListString.size(); i++)
        keyListInt.append(keyListString.at(i).toInt()); // Ключ, числа

    // Алгоритм шифрования
    int rowSize = keyListInt.size();                // Размер строки
    int columnsCount = rowSize;                     // Число столбцов
    int rowsCount = byteArray.size() / rowSize + 1; // Число строк

    // Выделение памяти
    int** matrix = new int*[rowsCount];
    for (int i = 0; i < rowsCount; i++) {

        matrix[i] = new int[columnsCount];
    }

    // Выделение памяти
    int** newMatrix = new int*[rowsCount];
    for (int i = 0; i < rowsCount; i++)
        newMatrix[i] = new int[columnsCount];

    // Заполнение нулями
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            matrix[i][j] = 'z';

    // Заполнение матрицы
    int byteArrayIndex = 0;
    for (int i = 0; i < columnsCount; i++)
        for (int j = 0; j < rowsCount; j++) {

            matrix[j][i] = byteArray.at(byteArrayIndex);
            byteArrayIndex++;

            if (byteArrayIndex == byteArray.size()) {

                i = columnsCount;
                j = rowsCount;
            }
        }

    // Добавление числа оставшихся нулей
    int bytesCount = columnsCount * rowsCount - byteArray.size() - 1;
    matrix[rowsCount - 1][columnsCount - 1] = bytesCount;

    // Матрица: перестановка столбцов, шифровка
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            newMatrix[i][j] = matrix[i][keyListInt[j] - 1];

    // Зашифрованный список
    QByteArray newByteArray;

    // Запись матрицы в список
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            newByteArray.append(newMatrix[i][j]);

    byteArray.clear();
    byteArray = newByteArray;
}

// Расшифровать последовательность байт, вертикальная перестановка
void MainWindow::VerticalPermutationDecryptByteArray() {

    // Сохранение ключа дешифровки
    keyListString.clear();
    keyListInt.clear();

    QByteArray keyByteArray = keyFile.readAll(); // Чтение keyFile

    QString str = keyByteArray;     // Ключ, строка
    keyListString = str.split(' '); // Ключ, строки

    for (int i = 0; i < keyListString.size(); i++)
        keyListInt.append(keyListString.at(i).toInt()); // Ключ, числа

    // Запись нового списка в матрицу
    int rowSize = keyListInt.size();
    int columnsCount = rowSize;
    int rowsCount = byteArray.size() / rowSize;

    // Выделение памяти
    int** matrix = new int*[rowsCount];
    for (int i = 0; i < rowsCount; i++)
        matrix[i] = new int[columnsCount];

    // Выделение памяти
    int** newMatrix = new int*[rowsCount];
    for (int i = 0; i < rowsCount; i++)
        newMatrix[i] = new int[columnsCount];

    // Заполнение матрицы нулями
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            matrix[i][j] = 'z';

    // Сохранение списка в массив
    int byteArrayIndex = 0;
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++) {

            matrix[i][j] = byteArray.at(byteArrayIndex);
            byteArrayIndex++;

            if (byteArrayIndex == byteArray.size()) {

                i = rowsCount;
                j = columnsCount;
            }
        }

    // Матрица: перестановка столбцов, расшифровка
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            newMatrix[i][keyListInt[j] - 1] = matrix[i][j];

    QByteArray newByteArray; // Новый список

    // Сохранениие массива в новый список
    for (int i = 0; i < columnsCount; i++)
        for (int j = 0; j < rowsCount; j++)
            newByteArray.append(newMatrix[j][i]);

    // Удаление пробелов
    uchar e = newByteArray.back() + 1;

    // return;
    for (int i = 0; i < e; i++)
        newByteArray.remove(newByteArray.size() - 1, 1);

    byteArray.clear();
    byteArray = newByteArray;
}
