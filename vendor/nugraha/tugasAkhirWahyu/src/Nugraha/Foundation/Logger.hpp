namespace Nugraha { namespace Foundation {
using Nugraha::Contracts::Foundation::LoggerContract;

class Logger : public LoggerContract {
protected:
    DynamicJsonBuffer* jsonBuffer;
    JsonObject* root;
    JsonArray* data;
    int count = 0;
    std::map<String, JsonArray*> dataTypeContents;

    template<typename KeyType, typename ValueType>
    void addRecord(String type, KeyType key, ValueType value)
    {
        JsonArray* contents;

        if(!isContentTypeExists(type)) {
            JsonObject& contentRoot = data->createNestedObject();
            contentRoot["type"] = type;
            contents = &contentRoot.createNestedArray("contents");
            dataTypeContents.insert(std::make_pair(type, contents));
        } else {
            contents = dataTypeContents[type];
        }

        JsonObject& item = contents->createNestedObject();
        item["key"] = key;
        item["value"] = value;
        (*root)["count"] = ++count;
    }

    void initializeJsonBuffer()
    {
        jsonBuffer = new DynamicJsonBuffer();
        root = &jsonBuffer->createObject();
        (*root)["count"] = 0;
        data = &root->createNestedArray("data");
    }

    void clean()
    {
        delete [] jsonBuffer;
        jsonBuffer = NULL;
    }

    bool isContentTypeExists(String type)
    {
        if ( dataTypeContents.find(type) == dataTypeContents.end() ) {
          return false;
        } 
        return true;
    }

public:
    Logger()
    {
        initializeJsonBuffer();
    }

    void addNotification(int pin, bool state)
    {
        if(jsonBuffer == NULL)
            initializeJsonBuffer();
        addRecord("Notification", pin, state);
    }

    void addConnectionInfo(String parameter, String value)
    {
        if(jsonBuffer == NULL)
            initializeJsonBuffer();
        addRecord("ConnectionInfo", parameter, value);
    }

    void addSensorMeasurement(String sensorName, double measurementValue)
    {
        if(jsonBuffer == NULL)
            initializeJsonBuffer();
        addRecord("Measurement", sensorName, measurementValue);
    }

    String getLogMessage()
    {
        if(jsonBuffer != NULL) {
            String logMessages;
            root->printTo(logMessages);
            clean();
            initializeJsonBuffer();
            return logMessages;
        } else {
            return "{\"records\":[]}";
        }
    }

    void printToSerial()
    {
        if(jsonBuffer != NULL) {
            root->prettyPrintTo(Serial);
        }
        else
            Serial.println("NULL");
    }
};

}}