#include "KCInspections.h"

string KCInspections::CheckId(short xError, short yError, bool showError, bool flag, string str)
{
	return to_string(CheckingInput::Input<int>(xError, yError, showError, flag));
}

string KCInspections::CheckName(short xError, short yError, bool showError, bool flag, string str)
{
	return CheckingInput::Input<string>(xError, yError, showError, flag);
}

string KCInspections::CheckNumberWorkshops(short xError, short yError, bool showError, bool flag, string str)
{

	return to_string(CheckingInput::Input<int>(xError, yError, showError, flag));
}

string KCInspections::ChecknumberWorkshopsOperation(short xError, short yError, bool showError, bool flag, string str)
{
    int errorCode; string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(); string bufEmptyStr;	
    do
    {
        int bufInt = CheckingInput::Input<int>(xError, yError, showError, flag);
        bufEmptyStr = "";
        if (bufInt <= stoi(str))
        {
            return to_string(bufInt);
        }
        else
        {
            PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
            ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, CheckingInput::arrayErrors[4]);

            if (showError == false)
            {
                Sleep(1000);
                for (int i = 0; i < CheckingInput::arrayErrors[4].size(); ++i)
                {
                    bufEmptyStr += " ";
                }
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
            }

            strBuf = to_string(bufInt);
            Console::gotoxy(bufX, bufY);
            for (int i = 0; i < strBuf.size(); ++i)
            {
                cout << " ";
            }
            Console::gotoxy(bufX, bufY);

            strBuf = "-1";
        }
    } while (flag);

    return strBuf;
}

string KCInspections::CheckEffectiveness(short xError, short yError, bool showError, bool flag, string str)
{
    int errorCode; string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(); string bufEmptyStr;
    do
    {
        int bufInt = CheckingInput::Input<int>(xError, yError, showError, flag);
        bufEmptyStr = "";
        if ((bufInt >= 0) && (bufInt <= 100))
        {
            return to_string(bufInt);
        }
        else
        {
            PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
            ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, CheckingInput::arrayErrors[5]);

            if (showError == false)
            {
                Sleep(1000);
                for (int i = 0; i < CheckingInput::arrayErrors[5].size(); ++i)
                {
                    bufEmptyStr += " ";
                }
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
            }

            strBuf = to_string(bufInt);
            Console::gotoxy(bufX, bufY);
            for (int i = 0; i < strBuf.size(); ++i)
            {
                cout << " ";
            }
            Console::gotoxy(bufX, bufY);

            strBuf = "-1";
        }
    } while (flag);

    return strBuf;
}

vector<function<string(short, short, bool, bool, string)>> KCInspections::kcInspections = {
                                                                                        CheckId,
                                                                                        CheckName,
                                                                                        CheckNumberWorkshops,
                                                                                        ChecknumberWorkshopsOperation,
                                                                                        CheckEffectiveness
};


