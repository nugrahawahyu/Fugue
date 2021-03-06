namespace Nugraha { namespace Support { namespace Facades {

class Debug 
{
public:
    static bool isDebugMode;
    static int lastFreeMemory;

    static void printFreeMemory()
    {
        if(Debug::isDebugMode) {
            int currentFreeMemory = ESP.getFreeHeap();
            Serial.print(("Free heap="));
            Serial.print(currentFreeMemory);

            Serial.print((" ["));
            if(currentFreeMemory > Debug::lastFreeMemory)
                Serial.print(("+"));
            Serial.print(currentFreeMemory - Debug::lastFreeMemory);
            Serial.println(("]"));

            Debug::lastFreeMemory = currentFreeMemory;
        }
    }

    template<typename Type>
    static void println(Type message)
    {
        if(Debug::isDebugMode) {
            Serial.println(message);
        }
    }

    template<typename Type>
    static void print(Type message)
    {
        if(Debug::isDebugMode) {
            Serial.print(message);
        }
    }
};
}}}
bool Nugraha::Support::Facades::Debug::isDebugMode = true;
int Nugraha::Support::Facades::Debug::lastFreeMemory = 0;