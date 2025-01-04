#include <iostream>
#include <string>
#include <fstream>

#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;

string get_token()
{
    string s="";
    char c;
    fstream in("config.txt");
        if (in.is_open())
            while (!in.eof())
            {
                c=in.get();
                s+=c;
            }
    in.close();
    s.pop_back();
    return s;
}

class ViewBot
{
private:
    string s;
    void init()
    {
        s=get_token();
    }
public:
    void activate()
    {
        Bot bot(this->s);

        bot.getEvents().onCommand("start", [&bot](Message::Ptr message) 
        {
            bot.getApi().sendMessage(message->chat->id, "Hi!");
        });

        bot.getEvents().onCommand("end", [&bot](Message::Ptr message) 
        {
            bot.getApi().sendMessage(message->chat->id, "Bye!");
        });


        bot.getEvents().onAnyMessage([&bot](Message::Ptr message) 
        {
            printf("User wrote %s\n", message->text.c_str());
            if 
            (
                (StringTools::startsWith(message->text, "/start"))
                    or
                (StringTools::startsWith(message->text, "/end"))
            )
            
            {
                return;
            }
            bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });

        try 
        {
            printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
            TgLongPoll longPoll(bot);
            while (true) 
            {
                printf("Long poll started\n");
                longPoll.start();
            }
        } 
        catch (TgException& e) 
        {
            printf("error: %s\n", e.what());
        }
    }
    
};