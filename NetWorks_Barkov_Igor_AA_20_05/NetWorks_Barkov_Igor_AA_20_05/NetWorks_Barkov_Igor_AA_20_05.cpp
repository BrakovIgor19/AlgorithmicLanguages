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

int main()
{

	NetWorks Networks;

	StartParameters::SetStartParameters();

	Animation::Loading("Загрузка", 5000);

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
				
				Table tablePipes(6, 4, { 5 }, { 10, 15, 15, 15 }, '#', { TextDate::pipeFields }, PipeInspections::pipeInspections);
				Table tableKCs(6, 4, { 5 }, { 10, 15, 20, 18, 18 }, '#', {TextDate::KCFields}, KCInspections::kcInspections);
				
				Animation::Loading("Загрузка", 2000);
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
//				// Объявляем сеть
//				NetWorks oldNetWorks;
//				// Спрашиваем имя сети
//				ConsoleFormatOutIn::WriteTextCenterThisCoord(Console::GetWidthWindow() / 2, Console::GetHeightWindow() / 2, "Название сети: ");
//				oldNetWorks.name = CheckingInput::Input<string>(Console::GetWidthWindow() / 2, Console::GetHeightWindow() * 3 / 4, false, true);
//				// Резервируем место под пустые поля
//				SaveDownload::DownloadNetWorks(oldNetWorks);
//
//				// Создаем пустые таблицы 
//				Table tablePipes(6, 4, { 5 }, { 10, 15, 15, 15 }, '#', { TextDate::pipeFields }, PipeInspections::pipeInspections);
//				Table tableKCs(6, 4, { 5 }, { 10, 15, 20, 18, 18 }, '#', { TextDate::KCFields }, KCInspections::kcInspections);
//// Нормально тащим			
//
//				// Передаем данные в таблицы
//				tablePipes.date = Cast::ToVectorVectorsString(oldNetWorks.pipes)
//
//				// Меню сети				
//				while (page2)
//				{
//					switch (Menu::ShowMenuCenter(TextDate::NetworkMenu))
//					{
//					case -1:
//					{
//						page2 = false;
//						break;
//					}
//					case 0:
//					{
//						tablePipes.Draw(tablePipes.filterDateIndex);
//						while (page3)
//						{
//							switch (Menu::ActiveMenuAlignedRight(tablePipes.GetRightX() + 20, tablePipes.GetRightY(), TextDate::modeMenu))
//							{
//							case -1:
//							{
//								page3 = false;
//								break;
//							}
//							case 0:
//							{
//								tablePipes.Add();
//								break;
//							}
//							case 1:
//							{
//								tablePipes.Edit();
//								break;
//							}
//							case 2:
//							{
//								tablePipes.Delete();
//								break;
//							}
//							}
//						}
//						page3 = true;
//						break;
//					}
//					case 1:
//					{
//						tableKCs.Draw(tableKCs.filterDateIndex);
//						while (page3)
//						{
//							switch (Menu::ActiveMenuAlignedRight(tableKCs.GetRightX() + 20, tableKCs.GetRightY(), TextDate::modeMenu))
//							{
//							case -1:
//							{
//								page3 = false;
//								break;
//							}
//							case 0:
//							{
//								tableKCs.Add();
//								break;
//							}
//							case 1:
//							{
//								tableKCs.Edit();
//								break;
//							}
//							case 2:
//							{
//								tableKCs.Delete();
//								break;
//							}
//							}
//						}
//						page3 = true;
//						break;
//					}
//					}
//				}
//
//				newNetWorks.pipes = Cast::ToVectorObject<Pipe>(tablePipes.date);
//				newNetWorks.KCs = Cast::ToVectorObject<KC>(tableKCs.date);
//				SaveDownload::SaveNetWorks(newNetWorks);
//				page2 = true;
//				break;
			}
		}
		
	}
	page1 = true;
	return 0;
}


