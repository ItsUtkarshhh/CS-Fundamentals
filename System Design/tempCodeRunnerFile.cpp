#include<iostream>
#include<vector>
#include<string>
using namespace std;

class FormatStrategy {
    public:
    virtual void format() = 0;
    virtual void save() = 0;
};

class PDFFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in PDF Format...";
    }

    void save() override {
        cout<<"Saving the content in PDF Format...";
    }
};

class ExcelFormat : public FormatStrategy {
    public:    
    void format() override {
        cout<<"Formatting the content in Excel Format...";
    }

    void save() override {
        cout<<"Saving the content in Excel Format...";
    }
};

class CSVFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in CSV Format...";
    }

    void save() override {
        cout<<"Saving the content in CSV Format...";
    }
};

class MarkdownFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in Markdown Format...";
    }

    void save() override {
        cout<<"Saving the content in Markdown Format...";
    }
};

class HTMLFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in HTML Format...";
    }

    void save() override {
        cout<<"Saving the content in HTML Format...";
    }
};

class FormatService {
    private:
    FormatStrategy* formatStrategy;

    public:
    FormatService(FormatStrategy* format) {
        this->formatStrategy = format;
    }

    void setFormatStrategy(FormatStrategy* format) {
        this->formatStrategy = format;
    }

    void workerService() {
        formatStrategy->format();
        formatStrategy->save();
    }
};

int main() {
    FormatStrategy* strategy = new PDFFormat();
    FormatService* service = new FormatService(strategy);
    service->workerService();
}