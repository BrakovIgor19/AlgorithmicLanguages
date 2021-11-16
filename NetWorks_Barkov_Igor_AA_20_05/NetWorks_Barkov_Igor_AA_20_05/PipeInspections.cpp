#include "PipeInspections.h"

string PipeInspections::CheckId(short xError, short yError, bool showError, bool flag, string str)
{
	return to_string(CheckingInput::Input<int>(xError, yError, showError, flag));
}

string PipeInspections::CheckLenght(short xError, short yError, bool showError, bool flag, string str)
{
	return to_string(CheckingInput::Input<float>(xError, yError, showError, flag));
}

string PipeInspections::CheckDiameter(short xError, short yError, bool showError, bool flag, string str)
{
	return to_string(CheckingInput::Input<int>(xError, yError, showError, flag));
}

string PipeInspections::CheckSignRepair(short xError, short yError, bool showError, bool flag, string str)
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
				return "Исправна";
			}
			case DOWN:
			{
				PlaySoundA("ui_repairweapon_02.wav", NULL, SND_ASYNC);
				return "В ремонте";
			}
		}
		
	}
	return "-1";
}

vector<function<string(short, short, bool, bool, string)>> PipeInspections::pipeInspections = {
																						CheckId,
																						CheckLenght,
																						CheckDiameter,
																						CheckSignRepair
};