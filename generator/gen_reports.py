import random
from datetime import datetime, timedelta

# --- Настройки пропорций ---
# Количество следствий сделаем чуть меньше или равным количеству заявлений,
# чтобы при сжатом пуле ID они гарантированно пересекались и дублировались.
PERCENTAGE_FOR_INVESTIGATIONS = 0.25  # 25% от общего пула заявлений

# --- Справочники данных ---
MALE_SURNAMES = ["Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов", "Попов", "Васильев", 
                 "Соколов", "Михайлов", "Новиков", "Федоров", "Морозов", "Волков", "Алексеев"]
MALE_NAMES = ["Иван", "Петр", "Сергей", "Михаил", "Алексей", "Дмитрий", "Андрей", 
              "Артем", "Николай", "Владимир", "Александр", "Евгений", "Антон", "Игорь"]
MALE_PATRONYMICS = ["Иванович", "Петрович", "Сергеевич", "Михайлович", "Алексеевич", "Дмитриевич", 
                    "Андреевич", "Николаевич", "Владимирович", "Александрович", "Евгеньевич"]

FEMALE_SURNAMES = ["Иванова", "Петрова", "Сидорова", "Смирнова", "Кузнецова", "Попова", "Васильева", 
                   "Соколова", "Михайлова", "Новикова", "Федорова", "Морозова", "Волкова", "Алексеева"]
FEMALE_NAMES = ["Анна", "Мария", "Елена", "Ольга", "Наталья", "Екатерина", "Татьяна", 
                "Ирина", "Светлана", "Юлия", "Анастасия", "Ксения", "Евгения", "Дарья"]
FEMALE_PATRONYMICS = ["Ивановна", "Петровна", "Сергеевна", "Михайловна", "Алексеевна", "Дмитриевна", 
                      "Андреевна", "Николаевна", "Владимировна", "Александровна", "Евгеньевна"]

STATUSES = ["возбуждено", "приостановлено", "на рассмотрении", "закрыто"]
MONTHS = ["янв", "фев", "мар", "апр", "май", "июн", "июл", "авг", "сен", "окт", "ноя", "дек"]

DESCRIPTIONS = [
    "Кража велосипеда со двора дома.",
    "Потеря кошелька в общественном транспорте.",
    "Мелкое хулиганство на автобусной остановке.",
    "Незаконное проникновение на дачный участок.",
    "ДТП во дворе без пострадавших.",
    "Нарушение тишины в ночное время суток.",
    "Подозрение на мошенничество по телефону.",
    "Утеря документов, удостоверяющих личность.",
    "Кража хлеба из магазина.",
    "Поджог государственного имущества.",
    "Убийство по неосторожности.",
    "Кража телевизора из магазина.",
    "Мошенничество в крупном масштабе."
]

def generate_random_fio():
    if random.choice([True, False]):
        return random.choice(MALE_SURNAMES), random.choice(MALE_NAMES), random.choice(MALE_PATRONYMICS)
    else:
        return random.choice(FEMALE_SURNAMES), random.choice(FEMALE_NAMES), random.choice(FEMALE_PATRONYMICS)

def generate_random_date():
    start_date = datetime(2024, 1, 1)
    end_date = datetime(2026, 6, 1)
    delta_days = (end_date - start_date).days
    random_days = random.randint(0, delta_days)
    random_date = start_date + timedelta(days=random_days)
    return f"{random_date.day} {MONTHS[random_date.month - 1]} {random_date.year}"


def main():
    # 1. Запрашиваем общее количество заявлений через консоль
    while True:
        try:
            count_reports = int(input("Введите количество заявлений для генерации (от 1 до 10000): "))
            if 1 <= count_reports <= 10000:
                break
            print("Пожалуйста, введите число в диапазоне от 1 до 10000.")
        except ValueError:
            print("Ошибка ввода. Нужно ввести целое число.")
            return

    # Динамически рассчитываем количество строк следствий (например, 70% от числа заявлений)
    count_investigations = int(count_reports * 0.7)
    if count_investigations < 1:
        count_investigations = 1

    # Генерируем уникальные ID в диапазоне 1..10000
    all_possible_ids = range(1, 10001)
    report_ids = random.sample(all_possible_ids, count_reports)
    
    # --- ГЕНЕРАТОР 1: ЗАЯВЛЕНИЯ (reports.txt) ---
    with open("reports.txt", "w", encoding="utf-8") as f_reports:
        # Первая строка — точное количество записей
        f_reports.write(f"{count_reports}\n")
        
        for report_id in report_ids:
            surname, name, patronymic = generate_random_fio()
            desc = random.choice(DESCRIPTIONS)
            f_reports.txt_format = f"{report_id} {surname} {name} {patronymic} {desc}\n"
            f_reports.write(f_reports.txt_format)
            
    print(f"\n[Успех] Файл reports.txt создан. Строк с данными: {count_reports} (все ID уникальны).")

    # --- ГЕНЕРАТОР 2: СЛЕДСТВИЯ (investigations.txt) ---
    # Вычисляем размер сжатого пула (строго 25% от сгенерированных заявлений)
    pool_size = max(1, int(count_reports * PERCENTAGE_FOR_INVESTIGATIONS))
    
    # Берем случайные 25% ID из тех, что РЕАЛЬНО ушли в файл заявлений
    sub_pool_ids = random.sample(report_ids, pool_size)
    
    # Заполняем следствия С ПОВТОРЕНИЯМИ (choices) строго из этого усеченного пула
    investigation_ids = random.choices(sub_pool_ids, k=count_investigations)
    
    with open("investigations.txt", "w", encoding="utf-8") as f_inv:
        # Первая строка — точное количество записей следствий
        f_inv.write(f"{count_investigations}\n")
        
        for report_id in investigation_ids:
            surname, name, patronymic = generate_random_fio()
            status = random.choice(STATUSES)
            date_str = generate_random_date()
            f_inv.write(f"{report_id} {surname} {name} {patronymic} {status} {date_str}\n")
            
    print(f"[Успех] Файл investigations.txt создан. Строк с данными: {count_investigations}.")
    print(f"-> Из {count_reports} заявлений следствия затронули только {pool_size} шт. (25%).")
    print(f"-> Это гарантирует высокую плотность дубликатов ID в файле расследований.")


if __name__ == "__main__":
    main()