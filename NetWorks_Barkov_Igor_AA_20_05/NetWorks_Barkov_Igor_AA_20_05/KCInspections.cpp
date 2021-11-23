#include "KCInspections.h"

string KCInspections::CheckId(Logger& log, bool correctInput, string& str)
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
    } while (correctInput);
    return strBuf;
}

string KCInspections::CheckName(Logger& log, bool correctInput, string& str)
{
    string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode; string bufEmptyStr = "";

    do {
        Console::SetColor(Black, LightGreen);
        Console::ShowCursor(true);
        getline(cin, strBuf);
        Console::ShowCursor(false);
        errorCode = CheckingInput::CheckError<string>(strBuf);
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

string KCInspections::CheckNumberWorkshops(Logger& log, bool correctInput, string& str)
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
    } while (correctInput);
    return strBuf;
}

string KCInspections::ChecknumberWorkshopsOperation(Logger& log, bool correctInput, string& str)
{
    string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode; string bufEmptyStr = "";

    do {
        Console::SetColor(Black, LightGreen);
        Console::ShowCursor(true);
        getline(cin, strBuf);
        Console::ShowCursor(false);
        errorCode = CheckingInput::CheckError<string>(strBuf);
        if (errorCode == 0)
        {
            if (stoi(strBuf) <= stoi(str))
            {
                PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
                log.Update(CheckingInput::arrayErrors[errorCode]);
                return strBuf;
            }
            else
            {
                PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                log.Update(CheckingInput::arrayErrors[4]);
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

string KCInspections::CheckEffectiveness(Logger& log, bool correctInput, string& str)
{
    string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode; string bufEmptyStr = "";

    do {
        Console::SetColor(Black, LightGreen);
        Console::ShowCursor(true);
        getline(cin, strBuf);
        Console::ShowCursor(false);
        errorCode = CheckingInput::CheckError<string>(strBuf);
        if (errorCode == 0)
        {
            if ((stoi(strBuf) >= 0) && (stoi(strBuf) <= 100))
            {
                PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
                log.Update(CheckingInput::arrayErrors[errorCode]);
                return strBuf;
            }
            else
            {
                PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                log.Update(CheckingInput::arrayErrors[5]);
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

vector<function<string(Logger&, bool, string&)>> KCInspections::kcInspections = {
                                                                                        CheckId,
                                                                                        CheckName,
                                                                                        CheckNumberWorkshops,
                                                                                        ChecknumberWorkshopsOperation,
                                                                                        CheckEffectiveness
};


