#include "NetWorks.h"
#include "Menu.h"
#include "TextDate.h"
#include "CheckingInput.h"
#include "Table.h"
#include "StartParameters.h"
#include "PipeInspections.h"
#include "KCInspections.h"
#include "Cast.h"
#include "SaveDownload.h"
#include "Logger.h"
#include "Animation.h"
#include "Map.h"

int main()
{

	NetWorks Networks;

	StartParameters::SetStartParameters();

	Animation::Loading("Запуск терминала", 2500);

	// Загрузочное меню
	bool page1 = true; bool page2 = true; bool page3 = true;
	while (page1)
	{
		switch (Menu::ShowMenuCenter(TextDate::bootMenu))
		{
			case -1:
			{
				page1 = false;
				break;
			}
			case 0:
			{
				// Создаем Новую сеть
				NetWorks newNetWorks;
				// Создаем имя сети
				ConsoleFormatOutIn::WriteTextCenterThisCoord(Console::GetWidthWindow() / 2, Console::GetHeightWindow() / 2, "Название сети: ");
				cin >> newNetWorks.name;
				// Резервируем место под пустые поля
				newNetWorks.pipes.reserve(10); newNetWorks.KCs.reserve(10);

				// Создаем пустые таблицы 

				Table tablePipes(6, 4, { 5 }, { 10, 15, 15, 15 }, '#', {TextDate::pipeFields}, PipeInspections::pipeInspections);
				Table tableKCs(6, 4, { 5 }, { 10, 15, 20, 18, 18 }, '#', {TextDate::KCFields}, KCInspections::kcInspections);
				
				Animation::Loading("Создание: " + newNetWorks.name, 2000);
				// Меню сети				
				while (page2)
				{
					switch (Menu::ShowMenuCenter(TextDate::NetworkMenu))
					{
						case -1:
						{
							page2 = false;
							break;
						}
						case 0:
						{
							Logger log(75, 20, 145, 35, '\xDB', LightGreen, LightGreen, Black);
							tablePipes.ConnectLogger(log);
							tablePipes.Draw(tablePipes.filterDateIndex);													
							while (page3)
							{
								switch (Menu::ActiveMenuAlignedRight(tablePipes.GetRightX() + 20, tablePipes.GetRightY(), TextDate::modeMenu))
								{
									case -1:
									{
										page3 = false;
										break;
									}
									case 0:
									{
										tablePipes.Add();
										break;
									}
									case 1:
									{
										tablePipes.Edit();
										break;
									}
									case 2:
									{
										tablePipes.Delete();
										break;
									}
								}
							}
							page3 = true;
							break;							
						}
						case 1:
						{
							Logger log(85, 20, 145, 35, '\xDB', LightGreen, LightGreen, Black);
							tableKCs.ConnectLogger(log);
							tableKCs.Draw(tableKCs.filterDateIndex);
							while (page3)
							{
								switch (Menu::ActiveMenuAlignedRight(tableKCs.GetRightX() + 20, tableKCs.GetRightY(), TextDate::modeMenu))
								{
									case -1:
									{
										page3 = false;
										break;
									}
									case 0:
									{
										tableKCs.Add();
										break;
									}
									case 1:
									{
										tableKCs.Edit();
										break;
									}
									case 2:
									{
										tableKCs.Delete();
										break;
									}
								}
							}
							page3 = true;
							break;
						}
					}
				}

				newNetWorks.pipes = Cast::ToVectorObject<Pipe>(tablePipes.date);
				newNetWorks.KCs = Cast::ToVectorObject<KC>(tableKCs.date);
				SaveDownload::SaveNetWorks(newNetWorks);
				page2 = true;
				break;
			}
			case 1:
			{
				// Объявляем сеть
				NetWorks oldNetWorks;
				// Спрашиваем имя сети
				ConsoleFormatOutIn::WriteTextCenterThisCoord(Console::GetWidthWindow() / 2, Console::GetHeightWindow() / 2, "Название сети: ");
				cin >> oldNetWorks.name;
				// Загружаем сеть
				SaveDownload::DownloadNetWorks(oldNetWorks);
				// Перегоняем данные для таблицы
				vector<int> bufIntVector1, bufIntVector2; bufIntVector1.reserve(oldNetWorks.pipes.size()); bufIntVector2.reserve(oldNetWorks.KCs.size());
				for (int i = 0; i < oldNetWorks.pipes.size() + 1; ++i)
				{
					bufIntVector1.push_back(5);
				}
				for (int i = 0; i < oldNetWorks.KCs.size() + 1; ++i)
				{
					bufIntVector2.push_back(5);
				}
				//Переводим данные для таблицы
				vector<vector<string>> bufStrVector1, bufStrVector2; bufStrVector1.resize(1); bufStrVector2.resize(1); bufStrVector1[0] = TextDate::pipeFields; bufStrVector2[0] = TextDate::KCFields;
				vector<vector<string>> bufStrVector12 = Cast::ToVectorVectorsString(oldNetWorks.pipes), bufStrVector22 = Cast::ToVectorVectorsString(oldNetWorks.KCs);
				bufStrVector1.insert(bufStrVector1.end(), bufStrVector12.begin(), bufStrVector12.end()); bufStrVector2.insert(bufStrVector2.end(), bufStrVector22.begin(), bufStrVector22.end());

				// Создаем  таблицы 
				Table tablePipes(6, 4, bufIntVector1, { 10, 15, 15, 15 }, '#', bufStrVector1, PipeInspections::pipeInspections);
				Table tableKCs(6, 4, bufIntVector2, { 10, 15, 20, 18, 18 }, '#', bufStrVector2, KCInspections::kcInspections);

				
				// Меню сети				
				while (page2)
				{
					switch (Menu::ShowMenuCenter(TextDate::NetworkMenu))
					{
					case -1:
					{
						page2 = false;
						break;
					}
					case 0:
					{
						Logger log(75, 20, 145, 35, '\xDB', LightGreen, LightGreen, Black);
						tablePipes.ConnectLogger(log);
						tablePipes.Draw(tablePipes.filterDateIndex);
						while (page3)
						{
							switch (Menu::ActiveMenuAlignedRight(tablePipes.GetRightX() + 20, tablePipes.GetRightY(), TextDate::modeMenu))
							{
							case -1:
							{
								page3 = false;
								break;
							}
							case 0:
							{
								tablePipes.Add();
								break;
							}
							case 1:
							{
								tablePipes.Edit();
								break;
							}
							case 2:
							{
								tablePipes.Delete();
								break;
							}
							}
						}
						page3 = true;
						break;
					}
					case 1:
					{
						Logger log(85, 20, 145, 35, '\xDB', LightGreen, LightGreen, Black);
						tableKCs.ConnectLogger(log);
						tableKCs.Draw(tableKCs.filterDateIndex);
						while (page3)
						{
							switch (Menu::ActiveMenuAlignedRight(tableKCs.GetRightX() + 20, tableKCs.GetRightY(), TextDate::modeMenu))
							{
							case -1:
							{
								page3 = false;
								break;
							}
							case 0:
							{
								tableKCs.Add();
								break;
							}
							case 1:
							{
								tableKCs.Edit();
								break;
							}
							case 2:
							{
								tableKCs.Delete();
								break;
							}
							}
						}
						page3 = true;
						break;
					}
					case 2:
					{
						Map map = Map();
						map.ConnectTable(oldNetWorks);
						SaveDownload::DownloadMap(map);
						map.Open();
						SaveDownload::SaveMap(map);
					}
					}
				}
				oldNetWorks.pipes = Cast::ToVectorObject<Pipe>(tablePipes.date);
				oldNetWorks.KCs = Cast::ToVectorObject<KC>(tableKCs.date);
				SaveDownload::SaveNetWorks(oldNetWorks);
				page2 = true;

				break;
			}

		}		
	}
	page1 = true;
	return 0;
}


