#include <Windows.h>
#include "report_directory.h"
#include "investigation_directory.h"
#include "DataService.h"
#include <QApplication>
void prepare_ui(const QApplication& a){
    // Сбрасываем системный стиль (опционально, помогает на Windows 11)
    a.setStyle("Fusion");

    // Создаем принудительно светлую палитру
    QPalette lightPalette;

    // Задаем базовые цвета: белый фон, черный текст
    lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));      // Фон окон
    lightPalette.setColor(QPalette::WindowText, QColor(0, 0, 0));        // Текст на окнах
    lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));        // Фон полей ввода и таблиц
    lightPalette.setColor(QPalette::AlternateBase, QColor(245, 245, 245));// Альтернативный фон строк таблицы
    lightPalette.setColor(QPalette::ToolTipBase, QColor(255, 255, 225));
    lightPalette.setColor(QPalette::ToolTipText, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::Text, QColor(0, 0, 0));              // Текст в таблицах/вводах
    lightPalette.setColor(QPalette::Button, QColor(240, 240, 240));      // Фон кнопок
    lightPalette.setColor(QPalette::ButtonText, QColor(0, 0, 0));        // Текст на кнопках

    // Если кнопка или элемент заблокированы (disabled)
    lightPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(120, 120, 120));
    lightPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(120, 120, 120));
    lightPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(120, 120, 120));

    // Применяем палитру ко ВСЕМУ приложению жестко
    a.setPalette(lightPalette);

}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    QApplication a(argc, argv);
    prepare_ui(a);

    DataService& data_service = DataService::get_instance();
    InvestigationDirectory window2;
    ReportDirectory window;
    window.ptr_investigation_directory = &window2; //Привязываем ссылку 2 окна для обновлений

    window.setWindowTitle("Справочник заявлений");
    window2.setWindowTitle("Справочник следствий");
    window.show();
    window2.show();
    return QApplication::exec();
}

