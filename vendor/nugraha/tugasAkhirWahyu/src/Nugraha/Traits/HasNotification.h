namespace Nugraha { namespace Traits {

class HasNotification
{
protected:
    String notification = "";
    int notificationCode = -1;

public:
    void setNotification(int code, String notification)
    {
        this->notificationCode = code;
        this->notification = notification;
    }

    String getNotification()
    {
        this->notificationCode = -1;
        return this->notification;
    }

    int getNotificationCode()
    {
        return this->notificationCode;
    }
};

}}