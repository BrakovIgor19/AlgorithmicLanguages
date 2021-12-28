#include "TextDate.h"

const vector<string> TextDate::bootMenu = { "Создать новую сеть",
											"Загрузить сеть"
};

const vector<string> TextDate::NetworkMenu = {       "Трубы",
											         "Компрессорные станции",
											         "Карта"
							
};

const vector<string> TextDate::pipeFields =  {        "id",
													  "Длина",
													  "Диаметр",
													  "Состояние"}
;

const vector<string> TextDate::KCFields =  {          "id",
													  "Название",
													  "Кол-во цехов",
													  "Рабочих цехов",
													  "Эффективность"
};

const vector<string> TextDate::modeMenu = {
												"Добавить",
												"Редактировать",
												"Удалить"
};

const vector<string> TextDate::mapMenu = {
													  "Добавить КC",
													  "Добавить трубу",
													  "Удалить КС",
													  "Удалить трубу",
													  "Провести т.с",
													  "Кр. путь",
													  "Макс. поток"
};
