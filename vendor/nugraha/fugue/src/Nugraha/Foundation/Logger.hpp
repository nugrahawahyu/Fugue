namespace Nugraha { namespace Foundation {
using Nugraha::Contracts::Foundation::LoggerContract;

class Logger : public LoggerContract {
protected:
    DynamicJsonBuffer* jsonBuffer;
    JsonObject* root;
    JsonArray* data;
    int count = 0;
    std::map<String, JsonArray*> dataTypeContents;

    void initializeJsonBuffer()
    {
        jsonBuffer = new DynamicJsonBuffer();
        root = &jsonBuffer->createObject();
        (*root)["count"] = 0;
        data = &root->createNestedArray("data");
    }

    void clean()
    {
        dataTypeContents.clear();
        delete jsonBuffer;
        jsonBuffer = NULL;
    }

    bool isContentTypeExists(String type)
    {
        if ( dataTypeContents.find(type) == dataTypeContents.end() ) {
          return false;
        } 
        return true;
    }

    void createNewContent(String type, JsonArray** contents)
    {
        JsonObject& contentRoot = data->createNestedObject();
        contentRoot["type"] = type;
        *contents = &contentRoot.createNestedArray("contents");
        dataTypeContents.insert(std::make_pair(type, *contents));
    }

public:
    Logger()
    {
        initializeJsonBuffer();
    }

    template<typename KeyType, typename ValueType>
    void addRecord(String type, String keyName, KeyType key, String valueName, ValueType value)
    {
        JsonArray* contents = NULL;

        if(!isContentTypeExists(type)) {
            createNewContent(type, &contents);
        } else {
            contents = dataTypeContents[type];
        }

        JsonObject& item = contents->createNestedObject();
        item["keyName"] = keyName;
        item["key"] = key;
        item["valueName"] = valueName;
        item["value"] = value;
        (*root)["count"] = ++count;
    }

    void addNotification(int pin, bool state)
    {
        if(jsonBuffer == NULL)
            initializeJsonBuffer();
        addRecord("Notification", "pin", pin, "state", state);
    }

    void addConnectionInfo(String parameter, String value)
    {
        if(jsonBuffer == NULL)
            initializeJsonBuffer();
        addRecord("ConnectionInfo", "parameter", parameter, "value", value);
    }

    void addSensorMeasurement(String sensorName, double measurementValue)
    {
        if(jsonBuffer == NULL)
            initializeJsonBuffer();
        addRecord("Measurement", "sensor", sensorName, "value", measurementValue);
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
            clean();
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