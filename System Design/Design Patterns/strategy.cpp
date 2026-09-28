// ----------------------------------------- Behavioural Design Pattern : Strategy Pattern ---------------------------------------------------------------------------->
// Strategy Design Pattern : Strategy Pattern is about taking a family of interchangeable algorithms/behaviors, putting each one behind a common interface, and allowing the behavior to be selected independently from the object that uses it.
// Problem It Solves : Suppose you're building a payment system & using if-else block based on what type of payment service is requested at the runtime.
//                   : Adding another payment service will require modification in the same class, which breaks the Open/Closed Principle.
//                   : Problem Arrives : Too Much Responsibility
//                                     : Growing conditional logic
//                                     : Poor extensibility
//                                     : Testing becomes harder
//                                     : Tight coupling
// Idea : Instead of putting all algorithms inside one class, extract each algorithm & provide a separate implementation classes for them.
// Steps for Implementation : Create the Strategy Interface
//                          : Create Concrete Strategies
//                          : Create the Context
//                          : Use it at the runtime
// Trade Offs : More classes, More interfaces, More indirection, More object creation/configuration, Can be overkill for simple logic.

// Simulated Example 1 : Sorting Algorithms
//                     : Every addition in the functionality will require changing the Sorting class. Breaks OCP
//                     : The single Sorting class is holding too much responsibility for sorting. Breaks SRP
// Problem :
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sorting {
    private:
    void mergeSort(vector<int>& v) {
        cout << "Performing Merge Sort\n";
        // merge sort implementation
    }
    
    void quickSort(vector<int>& v) {
        cout << "Performing Quick Sort\n";
        // quick sort implementation
    }
    
    void bubbleSort(vector<int>& v) {
        cout << "Performing Bubble Sort\n";
        // bubble sort implementation
    }
    
    void insertionSort(vector<int>& v) {
        cout << "Performing Insertion Sort\n";
        // insertion sort implementation
    }
    
    void selectionSort(vector<int>& v) {
        cout << "Performing Selection Sort\n";
        // selection sort implementation
    }
    
    void radixSort(vector<int>& v) {
        cout << "Performing Radix Sort\n";
        // radix sort implementation
    }

    public:
    void sort(vector<int>& v, string type) {
        if(type == "Merge") mergeSort(v);
        else if(type == "Quick") quickSort(v);
        else if(type == "Bubble") bubbleSort(v);
        else if(type == "Insertion") insertionSort(v);
        else if(type == "Selection") selectionSort(v);
        else radixSort(v);
    }
};

int main() {
    vector<int> numbers = {5, 2, 8, 1, 3};
    Sorting sorting;
    sorting.sort(numbers, "Merge");
}

// Solution :
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SortingStrategy {
    public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~SortingStrategy() = default;
};

class MergeSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout<<"Performing Merge Sort"<<endl;
        // Implementation Details
    }
};

class QuickSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout<<"Performing Quick Sort"<<endl;
        // Implementation Details
    }
};

class BubbleSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout<<"Performing Bubble Sort"<<endl;
        // Implementation Details
    }
};

class InsertionSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout<<"Performing Insertion Sort"<<endl;
        // Implementation Details
    }
};

class SelectionSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout<<"Performing Selection Sort"<<endl;
        // Implementation Details
    }
};

class RadixSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout<<"Performing Radix Sort"<<endl;
        // Implementation Details
    }
};

class SortingService {
    private:
    SortingStrategy* sortingStrategy;
    
    public:
    SortingService(SortingStrategy* sortingStrategy) {
        this->sortingStrategy = sortingStrategy;
    }
    
    ~SortingService() {
        delete sortingStrategy;
    }
    
    void setStrategy(SortingStrategy* sortingStrategy) {
        this->sortingStrategy = sortingStrategy;
    }
    
    void sort(vector<int>& arr) {
        sortingStrategy->sort(arr);
    }
};

int main() {
    vector<int> v = {5,4,3,2,1};
    SortingService* sort = new SortingService(new MergeSort()); // Dynamicallly allocated memory needs to be cleaned using delete keyword.
    sort->sort(v);
    
    delete sort;
    
    vector<int> v2 = {5,4,3,2,1};
    MergeSort mergeSort;
    SortingService* sort2 = new SortingService(&mergeSort); // Statically allocated memory automatically gets cleaned up.
    sort2->sort(v);
}

// ----------------------------------------------- More Problems -------------------------------------------------------------------->
// P1 : Enterprise Multi-Format Document Report Generator
//    : An enterprise reporting dashboard allows managers to download business analytics reports in multiple formats: PDF, Excel, CSV, Markdown & HTML

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class FormatStrategy {
    public:
    virtual void format() = 0;
    virtual void save() = 0;
    virtual ~FormatStrategy() = default;
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

    delete strategy;
    delete service;
}

// P2 : Payment System
//    : Payment providers are : UPI, Card, Cash, Wallet, Crypto, NetBanking
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class PaymentStrategy {
    public:
    virtual void processPayment() = 0;
    virtual ~PaymentStrategy() = default;
};

class UPIPayment : public PaymentStrategy {
    public:
    void processPayment() {
        cout<<"Paying via UPI..."<<endl;
    }
};

class CardPayment : public PaymentStrategy {
    public:
    void processPayment() {
        cout<<"Paying via Card..."<<endl;
    }
};

class CashPayment : public PaymentStrategy {
    public:
    void processPayment() {
        cout<<"Paying via Cash..."<<endl;
    }
};

class WalletPayment : public PaymentStrategy {
    public:
    void processPayment() {
        cout<<"Paying via Wallet..."<<endl;
    }
};

class CryptoPayment : public PaymentStrategy {
    public:
    void processPayment() {
        cout<<"Paying via Crypto..."<<endl;
    }
};

class NetBankingPayment : public PaymentStrategy {
    public:
    void processPayment() {
        cout<<"Paying via NetBanking..."<<endl;
    }
};

class PaymentService {
    private:
    PaymentStrategy* strategy;

    public:
    PaymentService(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void setPaymentService(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void processPayment() {
        cout<<"Processing Payment..."<<endl;
        strategy->processPayment();
    }
};

enum class PaymentMethod {
    UPI,
    Card,
    Cash,
    Wallet,
    Crypto,
    NetBanking,
    Invalid
};

int main() {
    string paymentType;
    cout << "Enter your payment type : " << endl;
    cin >> paymentType;

    // The below code initiates the need of some creational design pattern like Factory Pattern.
    unordered_map<string, PaymentMethod> hash = {
        {"UPI", PaymentMethod::UPI},
        {"Card", PaymentMethod::Card},
        {"Cash", PaymentMethod::Cash},
        {"Wallet", PaymentMethod::Wallet},
        {"Crypto", PaymentMethod::Crypto},
        {"NetBanking", PaymentMethod::NetBanking},
        {"Invalid", PaymentMethod::Invalid}
    };

    PaymentMethod method = PaymentMethod::Invalid;
    auto it = hash.find(paymentType);
    if (it != hash.end()) {
        method = it->second;
    }

    PaymentStrategy* selectedStrategy = nullptr;
    switch (method) {
        case PaymentMethod::UPI:
            selectedStrategy = new UPIPayment();
            break;
        case PaymentMethod::Card:
            selectedStrategy = new CardPayment();
            break;
        case PaymentMethod::Cash:
            selectedStrategy = new CashPayment();
            break;
        case PaymentMethod::Wallet:
            selectedStrategy = new WalletPayment();
            break;
        case PaymentMethod::Crypto:
            selectedStrategy = new CryptoPayment();
            break;
        case PaymentMethod::NetBanking:
            selectedStrategy = new NetBankingPayment();
            break;
        default:
            cout << "Invalid payment type entered!" << endl;
            return 1;
    }

    PaymentService service(selectedStrategy);
    service.processPayment();

    delete selectedStrategy;
}

// P2 : Enterprise Authentication Provider Service
//    : OAuth, JWT, Basic, LDAP, Cookies

#include<iostream>
using namespace std;

class AuthStrategy {
    public:
    virtual void processAuthentication() = 0;
    virtual ~AuthStrategy() = default;
};

class OAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing OAuth Authentication..."<<endl;
    }
};

class BasicAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing Basic Authentication..."<<endl;
    }
};

class JWTAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing JWT Authentication..."<<endl;
    }
};

class CookiesAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing Cookies Authentication..."<<endl;
    }
};

class OIDCAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing OIDC Authentication..."<<endl;
    }
};

class AuthService {
    private:
    AuthStrategy* strategy;

    public:
    AuthService(AuthStrategy* strategy) {
        this->strategy = strategy;
    }

    ~AuthService() {
        delete strategy;
    }

    void setAuthService(AuthStrategy* strategy) {
        this->strategy = strategy;
    }

    void processAuth() {
        strategy->processAuthentication();
    }
};

int main() {
    // Do either one thing, either stack or heap allocation & choose whether to use destructor or not, as destrutor is strictly for heap allocation deletion, and program might crash if you will allocate stack memory as well.
    // Either use destructor & heap memory allocation
    // Or no destructor & stack memory allocation

    OAuth oauth;
    AuthService service(&oauth);
    service.processAuth();

    AuthService* service2 = new AuthService(new OAuth());
    service2->processAuth();

    delete service2;
}