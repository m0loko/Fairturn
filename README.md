<div align="center">

#  **FAIRTURN**
  
  ![Badge Language Count](https://img.shields.io/github/languages/count/artaka/Fairturn)
  ![Badge Language](https://img.shields.io/github/languages/top/artaka/Fairturn)
  ![GitHub stars](https://img.shields.io/github/stars/artaka/Fairturn?style=social)


  <br>

  <a id="link-wiki" href="https://github.com/artaka/Fairturn/blob/master/techDocumentation.docx">📘 Исследуйте документацию</a>
  <br>

  **[<kbd> <br> Описание <br> </kbd>](#описание)** 
  **[<kbd> <br> Архитектура проекта <br> </kbd>](#архитектура-проекта)** 
  **[<kbd> <br> Лицензия <br> </kbd>](#лицензия)** 

  <br>
</div>


> [!CAUTION]
> Проект находится в стадии разработки и предназначен для образовательных целей.
>
---

## Описание

**Fairturn** — это приложение, созданное для справедливого распределения очередности сдачи лабораторных работ. Оно устраняет субъективность при распределении приоритетов, предоставляя возможность автоматического управления очередью на основе объективных критериев.  

Приложение идеально подходит для преподавателей и студентов, помогая сделать процесс сдачи лабораторных работ максимально прозрачным и удобным.  

### Основные цели
- Упрощение процесса сдачи лабораторных работ.  
- Обеспечение равенства участников.  
- Исключение субъективных факторов при определении очередности.  

---

## Основные функции

- **Импорт данных** из веб-таблиц для автоматизации ввода.  
- **Ручной ввод данных** для более гибкого управления.  
- **Сортировка участников** по количеству выполненных лабораторных работ.  
- **Чтение и запись данных** в файлы для удобного хранения и обмена.  
- **Интеграция с Google Sheets** через Python-скрипты.  
- **Простое меню** для быстрого доступа к функциональности.  

---

## Архитектура проекта

Проект состоит из нескольких независимых модулей, что позволяет легко изменять или добавлять новый функционал.  

### Основные модули
- **parserIN**: Извлечение данных из веб-таблиц.  
- **parserOUT**: Запись данных из файла в веб-таблицу.  
- **ranging**: Сортировка участников по заданным критериям.  
- **input**: Модуль для ручного ввода данных.  
- **writeToFile**: Сохранение данных в файл.  
- **inputFromFile**: Чтение данных из файла.  
- **logo**: Отображение логотипа программы.  
- **menu**: Основное меню программы.  
- **sorting**: Вывод отсортированных данных.  

---

## Тестирование

Каждый модуль протестирован на различных сценариях ввода и вывода данных.  

### Результаты тестов
- Корректное выполнение всех функций.  
- Работа с большими объёмами данных.  
- Полная совместимость с Python 3.10+ и компиляторами C++ (GCC, Clang, MSVC).  

---

## Лицензия

Этот проект распространяется под лицензией **Apache License 2.0**.  
Подробнее можно ознакомиться с лицензией по следующей ссылке: [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0).