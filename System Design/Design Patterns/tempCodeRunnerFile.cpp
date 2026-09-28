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

    void setAuthService(AuthStrategy* strategy) {
        this->strategy = strategy;
    }

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