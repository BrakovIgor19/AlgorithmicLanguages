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

int main()
{
	NetWorks Networks;

	StartParameters::SetStartParameters();
	
	// Загрузочное меню
	bool flag1 = true; bool flag2 = true; bool flag3 = true;
	while (flag1)
	{
		switch (Menu::ShowMenuCenter(TextDate::bootMenu))
		{
			case -1:
			{
				flag1 = false;
				break;
			}
			case 0:
			{
				// Создаем Новую сеть
				NetWorks newNetWorks;
				// Создаем имя сети
				ConsoleFormatOutIn::WriteTextCenterThisCoord(Console::GetWidthWindow() / 2, Console::GetHeightWindow() / 2, "Название сети: ");
				newNetWorks.name = CheckingInput::Input<string>(Console::GetWidthWindow() / 2, Console::GetHeightWindow() * 3 / 4, false, true);
				// Резервируем место под пустые поля
				newNetWorks.pipes.reserve(10); newNetWorks.KCs.reserve(10);

				// Создаем пустые таблицы 

				Table tablePipes(6, 4, { 5 }, { 10, 15, 15, 15 }, '#', { TextDate::pipeFields }, PipeInspections::pipeInspections);
				Table tableKCs(6, 4, { 5 }, { 10, 15, 20, 18, 18 }, '#', {TextDate::KCFields}, KCInspections::kcInspections);
				

				// Меню сети				
				while (flag2)
				{
					switch (Menu::ShowMenuCenter(TextDate::NetworkMenu))
					{
						case -1:
						{
							flag2 = false;
							break;
						}
						case 0:
						{							
							tablePipes.Draw(tablePipes.filterDateIndex);
							while (flag3)
							{
								switch (Menu::ActiveMenuAlignedRight(tablePipes.GetRightX() + 20, tablePipes.GetRightY(), TextDate::modeMenu))
								{
									case -1:
									{
										flag3 = false;
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
							flag3 = true;
							break;							
						}
						case 1:
						{
							tableKCs.Draw(tableKCs.filterDateIndex);
							while (flag3)
							{
								switch (Menu::ActiveMenuAlignedRight(tableKCs.GetRightX() + 20, tableKCs.GetRightY(), TextDate::modeMenu))
								{
									case -1:
									{
										flag3 = false;
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
							flag3 = true;
							break;
						}
					}
				}

				newNetWorks.pipes = Cast::ToVectorObject<Pipe>(tablePipes.date);
				newNetWorks.KCs = Cast::ToVectorObject<KC>(tableKCs.date);
				SaveDownload::SaveNetWorks(newNetWorks);
				flag2 = true;
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
//				while (flag2)
//				{
//					switch (Menu::ShowMenuCenter(TextDate::NetworkMenu))
//					{
//					case -1:
//					{
//						flag2 = false;
//						break;
//					}
//					case 0:
//					{
//						tablePipes.Draw(tablePipes.filterDateIndex);
//						while (flag3)
//						{
//							switch (Menu::ActiveMenuAlignedRight(tablePipes.GetRightX() + 20, tablePipes.GetRightY(), TextDate::modeMenu))
//							{
//							case -1:
//							{
//								flag3 = false;
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
//						flag3 = true;
//						break;
//					}
//					case 1:
//					{
//						tableKCs.Draw(tableKCs.filterDateIndex);
//						while (flag3)
//						{
//							switch (Menu::ActiveMenuAlignedRight(tableKCs.GetRightX() + 20, tableKCs.GetRightY(), TextDate::modeMenu))
//							{
//							case -1:
//							{
//								flag3 = false;
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
//						flag3 = true;
//						break;
//					}
//					}
//				}
//
//				newNetWorks.pipes = Cast::ToVectorObject<Pipe>(tablePipes.date);
//				newNetWorks.KCs = Cast::ToVectorObject<KC>(tableKCs.date);
//				SaveDownload::SaveNetWorks(newNetWorks);
//				flag2 = true;
//				break;
			}
		}
		
	}
	flag1 = true;
	return 0;
}


