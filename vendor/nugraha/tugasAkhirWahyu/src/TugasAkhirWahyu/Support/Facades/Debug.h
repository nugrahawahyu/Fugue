class Debug {

public:
    static bool isDebugMode;

    static void printFreeMemory()
    {
        if(Debug::isDebugMode) {
            Serial.print(F("freeMemory()="));
            Serial.println(freeMemory());
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
};

bool Debug::isDebugMode = true;