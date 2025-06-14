#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class SmartAssistant {
private:
    string userName;
    
    void say(const string& text) {
        cout << " 🤖 " << text << endl;
        string command = "espeak \"" + text + "\"";
        system(command.c_str());
    }

    void openWebsite(const string& url) {
        string action;
        if(url.find("youtube") != string::npos) {
            action = "Opening YouTube";
        } else if(url.find("google") != string::npos) {
            action = "Opening Google";
        } else if(url.find("brave") != string::npos) {
            action = "Opening Brave";
        } else if(url.find("maps") != string::npos) {
            action = "Opening Google Maps";
        } else if(url.find("weather") != string::npos) {
            action = "Opening Weather Map";
        } else if(url.find("vegamovies") != string::npos) {
            action = "Opening Vegamovies";
        } else {
            action = "Opening url";
        }
        
        say(action);
        string cmd;
        
        #ifdef _WIN32
            cmd = "start " + url;
        #elif __linux__
            cmd = "xdg-open " + url;
        #elif __APPLE__
            cmd = "open " + url;
        #endif
        
        system(cmd.c_str());
    }

    void openProgram(const string& program) {
        say("Opening " + program);
        string cmd;
        
        if(program == "task manager") {
            #ifdef _WIN32
                cmd = "taskmgr";
            #elif __linux__
                cmd = "gnome-system-monitor";
            #elif __APPLE__
                cmd = "open /Applications/Utilities/Activity\\ Monitor.app";
            #endif
        }
        else if(program == "calculator") {
            #ifdef _WIN32
                cmd = "calc";
            #elif __linux__
                cmd = "gnome-calculator";
            #elif __APPLE__
                cmd = "open /Applications/Calculator.app";
            #endif
        }
        else if(program == "notepad") {
            #ifdef _WIN32
                cmd = "notepad";
            #elif __linux__
                cmd = "gedit";
            #elif __APPLE__
                cmd = "open -a TextEdit";
            #endif
        }
        else if(program == "wordpad") {
            #ifdef _WIN32
                cmd = "write";
            #elif __linux__
                cmd = "libreoffice --writer";
            #elif __APPLE__
                cmd = "open -a 'Microsoft Word'";
            #endif
        }
        else if(program == "powerpoint") {
            #ifdef _WIN32
                cmd = "powerpnt";
            #elif __linux__
                cmd = "libreoffice --impress";
            #elif __APPLE__
                cmd = "open -a 'Microsoft PowerPoint'";
            #endif
        }
        
        system(cmd.c_str());
    }

    void openFolder(const string& folder) {
        say("Opening " + folder + " folder");
        string cmd;
        
        if(folder == "pictures") {
            #ifdef _WIN32
                cmd = "explorer %USERPROFILE%\\Pictures";
            #elif __linux__
                cmd = "xdg-open ~/Pictures";
            #elif __APPLE__
                cmd = "open ~/Pictures";
            #endif
        }
        else if(folder == "music") {
            #ifdef _WIN32
                cmd = "explorer %USERPROFILE%\\Music";
            #elif __linux__
                cmd = "xdg-open ~/Music";
            #elif __APPLE__
                cmd = "open ~/Music";
            #endif
        }
        else if(folder == "downloads") {
            #ifdef _WIN32
                cmd = "explorer %USERPROFILE%\\Downloads";
            #elif __linux__
                cmd = "xdg-open ~/Downloads";
            #elif __APPLE__
                cmd = "open ~/Downloads";
            #endif
        }
        
        system(cmd.c_str());
    }

public:
    void start() {
        say("Hello! I'm your smart assistant. What's your name?");
        cout << "You: ";
        getline(cin, userName);
        say("Welcome " + userName + "! How can I help you today?");
        
        while(true) {
            cout << "\nOptions:\n"
                 << "1. Open YouTube\n"
                 << "2. Open Google\n"
                 << "3. Open Task Manager\n"
                 << "4. Open Calculator\n"
                 << "5. Open Pictures Folder\n"
                 << "6. Open Music Folder\n"
                 << "7. Open Downloads Folder\n"
                 << "8. Open Notepad\n"
                 << "9. Open WordPad\n"
                 << "10. Open PowerPoint\n"
                 << "11. Open Google Maps\n"
                 << "12. Open Weather Map\n"
                 << "13. Open Vegamovies\n"
                 << "14. Custom Website\n"
                 << "15. Exit\n"
                 << "Your choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore();
            
            switch(choice) {
                case 1:
                    openWebsite("https://youtube.com");
                    break;
                case 2:
                    openWebsite("https://google.com");
                    break;
                case 3:
                    openProgram("task manager");
                    break;
                case 4:
                    openProgram("calculator");
                    break;
                case 5:
                    openFolder("pictures");
                    break;
                case 6:
                    openFolder("music");
                    break;
                case 7:
                    openFolder("downloads");
                    break;
                case 8:
                    openProgram("notepad");
                    break;
                case 9:
                    openProgram("wordpad");
                    break;
                case 10:
                    openProgram("powerpoint");
                    break;
                case 11:
                    openWebsite("https://maps.google.com");
                    break;
                case 12:
                    openWebsite("https://www.windy.com");
                    break;
                case 13:
                    openWebsite("https://vegamovies.com");
                    break;
                case 14: {
                    string url="https://";
                    cout << "Enter website URL (without https://): ";
                    string x;
                    getline(cin, x);
                    url += x;
                    openWebsite(url);
                    break;
                }
                case 15:
                    say("Goodbye " + userName + "!");
                    exit(0);
                default:
                    say("Invalid choice. Please try again.");
            }
        }
    }
};

int main() {
    SmartAssistant assistant;
    assistant.start();
    return 0;
}