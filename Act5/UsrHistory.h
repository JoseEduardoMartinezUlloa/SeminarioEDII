#ifndef USRHISTORY_H
#define USRHISTORY_H
class UsrHistory{
    public:
    char username[20], activity[20], act_time[24];
    void Add();
    void Modify();
    void Show();
    void Delete();
    void Search();
    void Menu();
    void Read();
    void Decompress();
};

#endif