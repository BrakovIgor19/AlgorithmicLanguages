#include "TextDate.h"

const vector<string> TextDate::bootMenu = { "Создать новую сеть",
											"Загрузить сеть"
};

const vector<string> TextDate::NetworkMenu = { "Трубы",
											   "Компрессорные станции"

};

const vector<vector<string>> TextDate::pipeFields = { {"id",
													  "Длина",
													  "Диаметр",
													  "Состояние"}
};

const vector<vector<string>> TextDate::KCFields = { {"id",
													  "Название",
													  "Кол-во цехов",
													  "Рабочих цехов",
													  "Эффективность"}
};

const vector<string> TextDate::modeMenu = {
												"Добавить",
												"Редактировать",
												"Удалить"
};
