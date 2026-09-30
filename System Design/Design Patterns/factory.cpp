// ----------------------------------------- Creational Design Pattern : Factory Pattern ---------------------------------------------------------------------------->
// Factory Design Pattern : A creational design pattern that provides an interface or dedicated method for creating objects, hiding the instantiation logic from the client and allowing subclasses or factory methods to determine the exact class to instantiate.
// Problem It Solves : Suppose your client code needs to instantiate different objects based on runtime inputs, configurations, or strings (e.g., creating a specific payment gateway or report formatter).
//                   : Using the 'new' keyword directly alongside massive 'if-else' or 'switch-case' blocks scatters object creation logic everywhere.
//                   : Problem Arrives : Tight coupling between client code and concrete classes
//                                     : Growing conditional logic for object creation
//                                     : Violates Open/Closed Principle (adding a new product type forces modification of creation code)
//                                     : Harder unit testing and code reuse
// Idea : Centralize object creation by extracting it into a dedicated Factory class or method, separating the "what to create" decision from "how to use it".
// Steps for Implementation : Create a common Product Interface
//                          : Create Concrete Product classes implementing the interface
//                          : Create the Factory Class / Method with conditional logic to instantiate products
//                          : Client requests the product from the factory without knowing concrete class names
// Trade Offs : Adds extra classes and indirection, can increase boilerplate code, and factory logic can grow large if not managed (though can be scaled with registry/map patterns).

// Simulated Example 1 : Object Creation via 'new' and Strings
//                     : Hardcoding 'new' inside client code tightly couples the client to specific headers and classes.
//                     : Adding a new product requires modifying client code, violating the Open/Closed Principle.

// Problem :
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
        cout << "Performing Merge Sort" << endl;
    }
};

class QuickSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout << "Performing Quick Sort" << endl;
    }
};

class BubbleSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout << "Performing Bubble Sort" << endl;
    }
};

class InsertionSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout << "Performing Insertion Sort" << endl;
    }
};

class SelectionSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout << "Performing Selection Sort" << endl;
    }
};

class RadixSort : public SortingStrategy {
    public:
    void sort(vector<int> &v) override {
        cout << "Performing Radix Sort" << endl;
    }
};

class SortingFactory {
    public:
    static SortingStrategy* createStrategy(const string& type) {
        if (type == "Merge") return new MergeSort();
        else if (type == "Quick") return new QuickSort();
        else if (type == "Bubble") return new BubbleSort();
        else if (type == "Insertion") return new InsertionSort();
        else if (type == "Selection") return new SelectionSort();
        else return new RadixSort();
    }
};

class SortingService { 
    private:
    SortingStrategy* sortingStrategy;

    public:
    SortingService(SortingStrategy* strategy) {
        this->sortingStrategy = strategy;
    }
    
    ~SortingService() {
        delete sortingStrategy;
    }
    
    void setStrategy(SortingStrategy* newStrategy) {
        delete this->sortingStrategy;
        this->sortingStrategy = newStrategy;
    }

    SortingService(const SortingService &other) = delete;
    SortingService& operator=(const SortingService &other) = delete;
    
    void sort(vector<int>& arr) {
        sortingStrategy->sort(arr);
    }
};

int main() {
    vector<int> numbers = {5, 2, 8, 1, 3};
    string userChoice = "Quick";

    SortingStrategy* strategy = SortingFactory::createStrategy(userChoice);
    SortingService* service = new SortingService(strategy);    
    service->sort(numbers);
    delete service;
}

// ----------------------------------------------- More Problems -------------------------------------------------------------------->
// P1 : Enterprise Multi-Format Document Report Generator
//    : An enterprise reporting dashboard allows managers to download business analytics reports in multiple formats: PDF, Excel, CSV, Markdown & HTML

#include<iostream>
#include<vector>
#include<string>
#include <memory>
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
        cout<<"Formatting the content in PDF Format..."<<endl;
    }

    void save() override {
        cout<<"Saving the content in PDF Format..."<<endl;
    }
};

class ExcelFormat : public FormatStrategy {
    public:    
    void format() override {
        cout<<"Formatting the content in Excel Format..."<<endl;
    }

    void save() override {
        cout<<"Saving the content in Excel Format..."<<endl;
    }
};

class CSVFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in CSV Format..."<<endl;
    }

    void save() override {
        cout<<"Saving the content in CSV Format..."<<endl;
    }
};

class MarkdownFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in Markdown Format..."<<endl;
    }

    void save() override {
        cout<<"Saving the content in Markdown Format..."<<endl;
    }
};

class HTMLFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"Formatting the content in HTML Format..."<<endl;
    }

    void save() override {
        cout<<"Saving the content in HTML Format..."<<endl;
    }
};

class InvalidFormat : public FormatStrategy {
    public:
    void format() override {
        cout<<"The format is invalid... hence cannot format"<<endl;
    }

    void save() override {
        cout<<"The format is invalid... hence cannot save"<<endl;
    }
};

class FormatFactory { // Simple Factory
    public:
    static unique_ptr<FormatStrategy> createStrategy(string &format) {
        if(format == "PDF") return make_unique<PDFFormat>();
        else if(format == "HTML") return make_unique<HTMLFormat>();
        else if(format == "Excel") return make_unique<ExcelFormat>();
        else if(format == "CSV") return make_unique<CSVFormat>();
        else if(format == "Markdown") return make_unique<MarkdownFormat>();
        else return make_unique<InvalidFormat>();
    }
};

class FormatService {
    private:
    unique_ptr<FormatStrategy> formatStrategy;

    public:
    FormatService(unique_ptr<FormatStrategy> format) {
        this->formatStrategy = move(format);
    }

    void setFormatStrategy(unique_ptr<FormatStrategy> newFormat) {
        this->formatStrategy = move(newFormat);
    }

    FormatService(const FormatService &other) = delete;
    FormatService& operator=(const FormatService &other) = delete;

    void workerService() {
        formatStrategy->format();
        formatStrategy->save();
    }
};

int main() {
    string format = "PDF";
    unique_ptr<FormatStrategy> strategy = FormatFactory::createStrategy(format);
    FormatService service(move(strategy));
    service.workerService();
}

// P2 : Enterprise Authentication Provider Service - Simple Factory
//    : OAuth, JWT, Basic, LDAP, Cookies, OIDC

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

class LDAPAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing LDAP Authentication..."<<endl;
    }
};

class InvalidAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Cannot Process Authentication... Invalid Auth Method"<<endl;
    }
};

class AuthFactory {
    public:
    static AuthStrategy* createStrategy(string &method) {
        if(method == "OAuth") return new OAuth();
        else if(method == "BasicAuth") return new BasicAuth();
        else if(method == "JWTAuth") return new JWTAuth();
        else if(method == "CookiesAuth") return new CookiesAuth();
        else if(method == "OIDCAuth") return new OIDCAuth();
        else if(method == "LDAPAuth") return new LDAPAuth();
        else return new InvalidAuth();
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

    void setAuthService(AuthStrategy* newStrategy) {
        delete this->strategy;
        this->strategy = newStrategy;
    }

    AuthService(const AuthService &other) = delete;
    AuthService& operator=(const AuthService &other) = delete;

    void processAuth() {
        strategy->processAuthentication();
    }
};

int main() {
    string method;
    cout<<"Enter auth method : ";
    cin>>method;

    AuthService* service = new AuthService(AuthFactory::createStrategy(method));
    service->processAuth();
    delete service;
}

// P2 : Enterprise Multi-Tenant Security Gateway - Abstract Factory
//    : OAuth, JWT, Basic, LDAP, Cookies, OIDC

#include<iostream>
#include<unordered_map>
using namespace std;

class AuthStrategy {
    public:
    virtual void processAuthentication() = 0;
    virtual ~AuthStrategy() = default;
};

class TokenValidatorStrategy {
    public:
    virtual void validateToken() = 0;
    virtual ~TokenValidatorStrategy() = default;
};

class GoogleOAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing OAuth Authentication..."<<endl;
    }
};

class GoogleOIDCAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing OIDC Authentication..."<<endl;
    }
};

class GoogleLDAPAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing LDAP Authentication..."<<endl;
    }
};

class GoogleInvalidAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Cannot Process Authentication... Invalid Auth Method"<<endl;
    }
};

class MicrosoftAzureADAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing Azure AD Authentication..."<<endl;
    }
};

class MicrosoftOIDCAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Processing Microsoft OIDC Authentication..."<<endl;
    }
};

class MicrosoftInvalidAuth : public AuthStrategy {
    public:
    void processAuthentication() override {
        cout<<"Cannot Process Authentication... Invalid Auth Method"<<endl;
    }
};

class GoogleCryptographicValidation : public TokenValidatorStrategy {
    public:
    void validateToken() override {
        cout<<"Performing Cryptographic Validation of token..."<<endl;
    }
};

class GoogleTokenInfoEndpointValidation : public TokenValidatorStrategy {
    public:
    void validateToken() override {
        cout<<"Performing Token Info Endpoint Validation of token..."<<endl;
    }
};

class GoogleAPIClientValidation : public TokenValidatorStrategy {
    public:
    void validateToken() override {
        cout<<"Performing API Client Validation of token..."<<endl;
    }
};

class GoogleInvalidTokenValidation : public TokenValidatorStrategy {
    public:
    void validateToken() override {
        cout<<"Cannot Process Validation... Invalid Validation Method"<<endl;
    }
};

class MicrosoftAzureTokenvalidator : public TokenValidatorStrategy {
    public:
    void validateToken() override {
        cout<<"Performing Azure Token Validation of token..."<<endl;
    }
};

class MicrosoftInvalidvalidator : public TokenValidatorStrategy {
    public:
    void validateToken() override {
        cout<<"Cannot Process Validation... Invalid Validation Method"<<endl;
    }
};

class EnterpriseSecurityFactory {
    public:
    virtual AuthStrategy* createAuthStrategy(string &method) = 0;
    virtual TokenValidatorStrategy* createTokenValidatorStrategy(string &method) = 0;
    ~EnterpriseSecurityFactory() = default;
};

class GoogleSecurityFactory : public EnterpriseSecurityFactory {
    public:
    AuthStrategy* createAuthStrategy(string &method) {
        if(method == "OAuth") return new GoogleOAuth();
        else if(method == "OIDC") return new GoogleOIDCAuth();
        else if(method == "LDAP") return new GoogleLDAPAuth();
        else return new GoogleInvalidAuth();
    }

    TokenValidatorStrategy* createTokenValidatorStrategy(string &method) {
        if(method == "Crypto") return new GoogleCryptographicValidation();
        else if(method == "TokenInfo") return new GoogleTokenInfoEndpointValidation();
        else if(method == "APIClient") return new GoogleAPIClientValidation();
        else return new GoogleInvalidTokenValidation();
    }
};

class MicrosoftSecurityFactory : public EnterpriseSecurityFactory {
    public:
    AuthStrategy* createAuthStrategy(string &method) {
        if(method == "AzureAD") return new MicrosoftAzureADAuth();
        else if(method == "OIDC") return new MicrosoftOIDCAuth();
        else return new MicrosoftInvalidAuth();
    }

    TokenValidatorStrategy* createTokenValidatorStrategy(string &method) {
        if(method == "AzureToken") return new MicrosoftAzureTokenvalidator();
        else return new MicrosoftInvalidvalidator();
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

class TokenvalidationService {
    private:
    TokenValidatorStrategy* strategy;

    public:
    TokenvalidationService(TokenValidatorStrategy* strategy) {
        this->strategy = strategy;
    }

    ~TokenvalidationService() {
        delete strategy;
    }

    void setTokenvalidationService(TokenValidatorStrategy* strategy) {
        this->strategy = strategy;
    }

    void processValidation() {
        strategy->validateToken();
    }
};

int main() {
    string client;
    cout<<"Enter client (Google / Microsoft) : ";
    cin>>client;

    string authMethod;
    cout<<"Enter Authentication method : ";
    cin>>authMethod;

    string validationMethod;
    cout<<"Enter Validation method : "<<endl;
    cin>>validationMethod;

    EnterpriseSecurityFactory* factory = NULL;

    if(client == "Google") factory = new GoogleSecurityFactory();
    else if (client == "Microsoft") factory = new MicrosoftSecurityFactory();
    else {
        cout<<"Invalid Client / Tenant"<<endl;
        return 1;
    }

    AuthStrategy* authStrategy = factory->createAuthStrategy(authMethod);
    TokenValidatorStrategy* valStrategy = factory->createTokenValidatorStrategy(validationMethod);
    AuthService authService(authStrategy);
    TokenvalidationService valService(valStrategy);
    authService.processAuth();
    valService.processValidation();

    delete factory;
}

// Introduction to Factory Registry Pattern - Improvement Over Simple & Abstract Factory Pattern
// Can use Unique Pointer & move() for more automated & efficient memory management, withut performance issues.
class SecurityFactoryRegistry {
    private:
    unordered_map<string, EnterpriseSecurityFactory*> registry;

    public:
    void registerFactory(const string &clientName, EnterpriseSecurityFactory* factory) {
        registry[clientName] = factory;
    }

    EnterpriseSecurityFactory* getFactory(string &clientName) {
        auto it = registry.find(clientName);
        if(it != registry.end()) {
            return it->second;
        }
        return nullptr;
    }

    ~SecurityFactoryRegistry() {
        for(auto& pair : registry) {
            delete pair.second;
        }
    }
};

int main() {
    SecurityFactoryRegistry factoryRegistry;
    factoryRegistry.registerFactory("Google", new GoogleSecurityFactory);
    factoryRegistry.registerFactory("Microsoft", new MicrosoftSecurityFactory);

    string client, authMethod, validationMethod;
    cout<<"Enter client (Google / Microsoft) : ";
    cin>>client;
    cout<<"Enter Authentication method : ";
    cin>>authMethod;
    cout<<"Enter Validation method : "<<endl;
    cin>>validationMethod;

    EnterpriseSecurityFactory* factory = factoryRegistry.getFactory(client);
    if(factory == NULL) {
        cout<<"Invalid Tenant / Client"<<endl;
        return 1;
    }

    AuthStrategy* authStrategy = factory->createAuthStrategy(authMethod);
    TokenValidatorStrategy* valStrategy = factory->createTokenValidatorStrategy(validationMethod);
    AuthService authService(authStrategy);
    TokenvalidationService valService(valStrategy);
    authService.processAuth();
    valService.processValidation();
}