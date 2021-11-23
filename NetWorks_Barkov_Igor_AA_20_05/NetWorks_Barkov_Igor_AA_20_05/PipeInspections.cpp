#include "PipeInspections.h"

string PipeInspections::CheckId(Logger &log, bool correctInput, string &str)
{
    string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode; string bufEmptyStr = "";

	do {
		Console::SetColor(Black, LightGreen);
		Console::ShowCursor(true);
		getline(cin, strBuf);
		Console::ShowCursor(false);
		errorCode = CheckingInput::CheckError<int>(strBuf);
		if (errorCode == 0)
		{
			PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
			log.Update(CheckingInput::arrayErrors[errorCode]);
			return strBuf;
		}
		else
		{
			PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
			log.Update(CheckingInput::arrayErrors[errorCode]);
			Console::SetColor(Black, LightGreen);
			Console::gotoxy(bufX, bufY);
			for (int i = 0; i < strBuf.size(); ++i)
			{
				cout << " ";
			}
			Console::gotoxy(bufX, bufY);
			strBuf = "-1";
		}
	}
    while (correctInput);
    return strBuf;
}

string PipeInspections::CheckLenght(Logger &log, bool correctInput, string &str)
{
	string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode; string bufEmptyStr = "";
	
	do {
		Console::SetColor(Black, LightGreen);
		Console::ShowCursor(true);
		getline(cin, strBuf);
		Console::ShowCursor(false);
		errorCode = CheckingInput::CheckError<float>(strBuf);
		if (errorCode == 0)
		{
			PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
			log.Update(CheckingInput::arrayErrors[errorCode]);
			return strBuf;
		}
		else
		{
			PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
			log.Update(CheckingInput::arrayErrors[errorCode]);
			Console::SetColor(Black, LightGreen);
			Console::gotoxy(bufX, bufY);
			for (int i = 0; i < strBuf.size(); ++i)
			{
				cout << " ";
			}
			Console::gotoxy(bufX, bufY);
			strBuf = "-1.000000";
		}
	} while (correctInput);
	return strBuf;
}

string PipeInspections::CheckDiameter(Logger &log, bool correctInput, string &str)
{
	string strBuf;  int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode; string bufEmptyStr = "";
	do {
		Console::SetColor(Black, LightGreen);
		Console::ShowCursor(true);
		getline(cin, strBuf);
		Console::ShowCursor(false);
		errorCode = CheckingInput::CheckError<int>(strBuf);
		if (errorCode == 0)
		{
			PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
			log.Update(CheckingInput::arrayErrors[errorCode]);
			return strBuf;
		}
		else
		{
			PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
			log.Update(CheckingInput::arrayErrors[errorCode]);
			Console::SetColor(Black, LightGreen);
			Console::gotoxy(bufX, bufY);
			for (int i = 0; i < strBuf.size(); ++i)
			{
				cout << " ";
			}
			Console::gotoxy(bufX, bufY);
			strBuf = "-1";
		}
	} while (correctInput);
	return strBuf;
}

string PipeInspections::CheckSignRepair(Logger &log, bool correctInput, string &str)
{
	for (int i = 0; i < 2; ++i)
	{
		int key = _getch();
		if (key == -32)
		{
			key = _getch();
		}
		switch (key)
		{
			case UP:
			{
				PlaySoundA("ui_repairweapon_02.wav", NULL, SND_ASYNC);
				log.Update(CheckingInput::arrayErrors[0]);
				return "Исправна";
			}
			case DOWN:
			{
				PlaySoundA("ui_repairweapon_02.wav", NULL, SND_ASYNC);
				log.Update(CheckingInput::arrayErrors[0]);
				return "В ремонте";
			}
		}
		
	}
	return "-1";
}

vector<function<string(Logger &log, bool correctInput, string &str)>> PipeInspections::pipeInspections = {
																						CheckId,
																						CheckLenght,
																						CheckDiameter,
																						CheckSignRepair
};