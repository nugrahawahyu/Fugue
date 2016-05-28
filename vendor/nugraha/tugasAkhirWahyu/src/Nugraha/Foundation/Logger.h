namespace Nugraha { namespace Foundation {
using Nugraha::Contracts::Foundation::LoggerContract;

class Logger : public LoggerContract {
protected:
    DynamicJsonBuffer* jsonBuffer = new DynamicJsonBuffer();
    JsonObject* root = &jsonBuffer->createObject();
    JsonArray* notifications = &root->createNestedArray("notifications");
    JsonArray* measurements = &root->createNestedArray("measurements");
    JsonArray* connectionInfos = &root->createNestedArray("connectionInfos");

    bool sendBoardInfo = true;

    void clean()
    {
        delete jsonBuffer;
        jsonBuffer = NULL;
    }

    void reInitializeJsonBuffer()
    {
        jsonBuffer = new DynamicJsonBuffer();
        root = &jsonBuffer->createObject();
        notifications = &root->createNestedArray("notifications");
        measurements = &root->createNestedArray("measurements");
        connectionInfos = &root->createNestedArray("connectionInfos");
    }

    void addBoardInfoToRecord()
    {
        JsonObject& boardInfo = root->createNestedObject("boardInfo");
        boardInfo["chipId"] = ESP.getChipId();
        boardInfo["cpuFreqMHz"] = ESP.getCpuFreqMHz();
        boardInfo["sdkVersion"] = ESP.getSdkVersion();
        boardInfo["bootVersion"] = ESP.getBootVersion();
        boardInfo["bootMode"] = ESP.getBootMode();
        boardInfo["cycleCount"] = ESP.getCycleCount();
        boardInfo["freeHeap"] = ESP.getFreeHeap();
        boardInfo["sketchSize"] = ESP.getSketchSize();
        boardInfo["freeSketchSpace"] = ESP.getFreeSketchSpace();
    }

public:
    void addNotification(int code, String message)
    {
        if(jsonBuffer == NULL)
            reInitializeJsonBuffer();
        
        String state;
        switch(code) {
        case 0 : 
            state = "off";
            break;
        case 1 : 
            state = "on";
            break;
        default : 
            break;
        }
        JsonObject& notification = notifications->createNestedObject();
        notification["pin"] = message;
        notification["state"] = state;
    }

    void addConnectionInfo(String parameter, String value)
    {
        if(jsonBuffer == NULL)
            reInitializeJsonBuffer();

        JsonObject& connectionInfo = connectionInfos->createNestedObject();
        connectionInfo["parameter"] = parameter;
        connectionInfo["value"] = value;
    }

    void addSensorMeasurement(String sensorName, String measurementValue)
    {
        if(jsonBuffer == NULL)
            reInitializeJsonBuffer();

        JsonObject& measurement = measurements->createNestedObject();
        measurement["sensor"] = sensorName;
        measurement["value"] = measurementValue;
    }

    String getLogMessage()
    {
        if(jsonBuffer != NULL) {
            if(sendBoardInfo) {
                addBoardInfoToRecord();
            }
            String logMessages;
            root->printTo(logMessages);
            clean();
            reInitializeJsonBuffer();
            return logMessages;
        } else {
            return "{\"records\":[]}";
        }
    }

    void printToSerial()
    {
        if(jsonBuffer != NULL) {
            if(sendBoardInfo) {
                addBoardInfoToRecord();
            }
            root->prettyPrintTo(Serial);
        }
        else
            Serial.println("NULL");
    }

};

}}