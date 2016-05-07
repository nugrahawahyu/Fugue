namespace Nugraha { namespace TugasAkhirWahyu { namespace Support { namespace Facades {

class Debug 
{
public:
    static bool isDebugMode;
    static int lastFreeMemory;

    static void printFreeMemory()
    {
        if(Debug::isDebugMode) {
            int currentFreeMemory = freeMemory();
            Serial.print(F("freeMemory()="));
            Serial.print(currentFreeMemory);

            Serial.print(F(" ["));
            if(currentFreeMemory > Debug::lastFreeMemory)
                Serial.print(F("+"));
            Serial.print(currentFreeMemory - Debug::lastFreeMemory);
            Serial.println(F("]"));

            Debug::lastFreeMemory = currentFreeMemory;
        }
    }

    static void println(const __FlashStringHelper* message)
    {
        if(Debug::isDebugMode) {
            Serial.println(message);
        }
    }

    static void println(char* message)
    {
        if(Debug::isDebugMode) {
            Serial.println(message);
        }
    }

    static void println(int message)
    {
        if(Debug::isDebugMode) {
            Serial.println(String(message));
        }
    }

    static void print(const __FlashStringHelper* message)
    {
        if(Debug::isDebugMode) {
            Serial.print(message);
        }
    }

    static void print(char* message)
    {
        if(Debug::isDebugMode) {
            Serial.print(message);
        }
    }

    static void print(int message)
    {
        if(Debug::isDebugMode) {
            Serial.print(String(message));
        }
    }
};
}}}}
bool Nugraha::TugasAkhirWahyu::Support::Facades::Debug::isDebugMode = true;
int Nugraha::TugasAkhirWahyu::Support::Facades::Debug::lastFreeMemory = 0;