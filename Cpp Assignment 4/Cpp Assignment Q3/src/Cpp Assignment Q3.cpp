#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

class DataProcessor {
public:

    // Pure virtual functions
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    // Normal virtual function — base class gives default implementation
    virtual void printSummary() const {
        cout << "Processor: " << processorType()
             << ", Records: " << recordCount() << endl;
    }

    // Virtual destructor
    virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor {

private:
    vector<string> records;

public:

    void loadData(const string& source) override {

        // Simulating CSV loading
        records = {
            "hello world",
            "cpp programming",
            "data processing",
            "abstract class",
            "generic buffer"
        };

        cout << "Loading CSV from: " << source << endl;
    }

    void processData() override {

        // Convert every record to uppercase
        for (string& record : records) {

            for (char& ch : record) {
                ch = toupper(static_cast<unsigned char>(ch));
            }
        }
    }

    void exportResult(const string& destination) override {

        cout << "[CSV EXPORT -> " << destination << "]" << endl;

        for (const string& record : records) {
            cout << record << endl;
        }
    }

    string processorType() const override {
        return "CSV Processor";
    }

    int recordCount() const override {
        return records.size();
    }
};




class SensorStreamProcessor : public DataProcessor {

private:
    vector<double> readings;

    double mean = 0;
    double minimum = 0;
    double maximum = 0;

public:

    void loadData(const string& source) override {

        readings = {
            23.4, 21.8, 25.1, 24.3,
            22.7, 26.2, 23.9, 24.8
        };

        cout << "Loading sensor data from: " << source << endl;
    }

    void processData() override {

        if (readings.empty())
            return;

        double sum = 0;

        minimum = readings[0];
        maximum = readings[0];

        for (double value : readings) {

            sum += value;

            if (value < minimum)
                minimum = value;

            if (value > maximum)
                maximum = value;
        }

        mean = sum / readings.size();
    }

    void exportResult(const string& destination) override {

        cout << "[SENSOR EXPORT -> " << destination << "]" << endl;

        cout << "Mean: " << mean << endl;
        cout << "Min: " << minimum << endl;
        cout << "Max: " << maximum << endl;
    }

    string processorType() const override {
        return "Sensor Stream Processor";
    }

    int recordCount() const override {
        return readings.size();
    }

    double getMean() const {
        return mean;
    }
};


template <typename T>
class DataBuffer {

private:

    T* data;       // Heap allocated array
    int capacity;  // Maximum elements
    int head;      // Index of oldest element
    int tail;      // Index where next element is written
    int count;     // Current number of elements

public:

    DataBuffer(int capacity) {

        this->capacity = capacity;

        data = new T[capacity];

        head = 0;
        tail = 0;
        count = 0;
    }

    ~DataBuffer() {
        delete[] data;
    }


    // Add element
    // If full, overwrite the oldest element
    void push(const T& value) {

        data[tail] = value;

        // Move tail circularly
        tail = (tail + 1) % capacity;

        if (count < capacity) {

            count++;

        } else {

            // Buffer was full,
            // so oldest element is overwritten.
            head = (head + 1) % capacity;
        }
    }


    // Remove oldest element
    T pop() {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }


    // View oldest element without removing
    T peek() const {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        return data[head];
    }


    bool isEmpty() const {
        return count == 0;
    }


    bool isFull() const {
        return count == capacity;
    }


    int size() const {
        return count;
    }


    // Friend template operator
    template <typename U>
    friend ostream& operator<<(ostream& out,
                               const DataBuffer<U>& buf);
};



template <typename U>
ostream& operator<<(ostream& out,
                    const DataBuffer<U>& buf) {

    out << "[";

    for (int i = 0; i < buf.count; i++) {

        int index = (buf.head + i) % buf.capacity;

        if (i > 0)
            out << ", ";

        // Strings need quotes in expected output
        if constexpr (is_same<U, string>::value)
            out << "\"" << buf.data[index] << "\"";
        else
            out << buf.data[index];
    }

    out << "]";

    return out;
}


/*
IMPORTANT TEMPLATE NOTE:

Template definitions are generally kept in the header (.h) file
or in the same file because the compiler needs the complete
template definition when it generates code for DataBuffer<int>,
DataBuffer<double>, DataBuffer<string>, etc.

If the template implementation is placed only in a separate
.cpp file, the compiler may not see the definition when it needs
to instantiate the template.
*/




int main() {


    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for (auto* p : pipeline) {

        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // DataProcessor is an ABSTRACT class.
    // Therefore this gives compile error:
    //
    // DataProcessor dp;

    DataBuffer<int> tickBuffer(5);

    for (int i = 1; i <= 7; i++) {
        tickBuffer.push(i * 10);
    }

    cout << "Tick Buffer: " << tickBuffer << endl;



    DataBuffer<double> tempBuffer(4);

    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);

    cout << "Before pop: " << tempBuffer << endl;

    cout << "Popped: " << tempBuffer.pop() << endl;

    cout << "After pop:  " << tempBuffer << endl;



    DataBuffer<string> logBuffer(3);

    logBuffer.push("INFO: Server started");
    logBuffer.push("WARN: High memory usage");
    logBuffer.push("ERROR: DB connection timeout");
    logBuffer.push("INFO: Retry successful");

    cout << "Log Buffer: " << logBuffer << endl;


    // ------------ BONUS — dynamic_cast ----------------


    for (auto* p : pipeline) {

        if (auto* csv = dynamic_cast<CSVProcessor*>(p)) {

            cout << "Found CSV Processor with "
                 << csv->recordCount()
                 << " records." << endl;

        }
        else if (auto* sensor =
                     dynamic_cast<SensorStreamProcessor*>(p)) {

            cout << "Found Sensor Processor - Mean: "
                 << sensor->getMean()
                 << endl;
        }
    }


    for (auto* p : pipeline) {
        delete p;
    }

    return 0;
}
