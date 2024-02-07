# dbus-system-share

## Зависимости

Библиотеки:
> Qt Core; Qt DBus; Qt Widgets; Qt GUI

Для установки:
> sudo apt install qtbase5-dev libqt5dbus5 libqt5widgets5 libqt5gui5

## Сборка и запуск

Для сборки и запуска проекта вам потребуется компилятор g++ и Qt 5.

1. Клонируйте репозиторий: `git clone https://github.com/dolphinBinary/dbus-system-share`
2. Перейдите в директорию проекта: `cd dbus-system-share`
3. Регистрация сервиса dbus
    > а. Скопируйте файл с описанием сервиса DBus, из папки dbus:
    ```cpp
    [Desktop Entry]
    Name=SystemShare
    Exec=/path/to/your/executable
    ```

    б. Скопируйте файл .service в директорию /usr/share/dbus-1/services/. Если у вас нет прав на запись в эту директорию, вы можете скопировать файл в директорию ~/.local/share/dbus-1/services/ для регистрации сервиса только для текущего пользователя.

    в. Перезапустите службу DBus, чтобы она обнаружила ваш сервис. Вы можете выполнить следующую команду в терминале:
    ``` bash
    sudo systemctl restart dbus
    ```

4. Теперь ваш сервис DBus должен быть зарегистрирован и доступен для других приложений.
3. Соберите проект с помощью сmake: `сmake`
4. Соберите проект с помощью make: `make`
5. Запустите приложение: `./dbus-system-share`

##  Примеры команд запуска и работы с приложением

* Команда qdbus*, которая может быть использована для вызова метода getRegisteredApplications:
> qdbus org.freedesktop.DBus / GetRegisteredApplications text/plain

Здесь "org.freedesktop.DBus" - это имя вашего сервиса D-Bus, "/" - путь к объекту, "GetRegisteredApplications" - имя метода, а "text/plain" - аргумент метода, представляющий формат файла.

*установить qdbus можно с помощью команды:
> sudo apt install qttools5-dev-tools

## Обзор

Простая реализация приложения на С++| QT | Dbus
для system wide share

## Компоненты

Проект состоит из нескольких компонентов:

* DBusInterface: Этот класс предоставляет интерфейс к
  системе D-Bus. Он позволяет приложению получить
  список зарегистрированных приложений для определенного
  формата файла и открыть файл с помощью определенного приложения.


* FileFormatRegistry: Этот класс предоставляет реестр приложений
  и форматов файлов, с которыми они могут работать.
  Приложения могут регистрировать себя в реестре,
  указывая форматы файлов, которые они могут открывать.
  Реестр также может возвращать список приложений,
  которые могут работать с определенным форматом файлов.


* FileOpenListener: Этот класс прослушивает события
  открытия файлов. Когда файл открыт, он издает сигнал
  с указанием пути и формата файла.


* main.cpp: Это основная точка входа в приложение.
  В нем настраивается интерфейс D-Bus, слушатель
  открытия файлов и реестр форматов файлов.
  При открытии файла он получает список приложений,
  которые могут работать с форматом файла,
  предлагает пользователю выбрать приложение,
  а затем открывает файл с помощью выбранного приложения.

## Использование

Чтобы использовать это приложение, вам необходимо
установить среду Qt. Затем вы можете скомпилировать
и запустить приложение с помощью системы сборки Qt.

Когда вы запустите приложение, оно начнет
прослушивать события открытия файлов. Когда
файл будет открыт, оно предложит вам выбрать
приложение для открытия файла. Список приложений
извлекается из системы D-Bus и включает в себя
все приложения, которые зарегистрировались в
качестве обработчиков формата файла.

