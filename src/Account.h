#pragma once
#include <string>
#include <vector>
#include <deque>
#include <shared_mutex>

// Account class declaration
class Account {
private:
    int id_;                              // unique account identifier
    std::string name_;                    // account holder name
    double balance_;                      // current balance
    mutable std::shared_mutex mtx_;       // per-account mutex for thread safety
    std::deque<std::string> history_;     // transaction history

public:
    Account();
    Account(int id, const std::string& name);
    Account(const Account& other);
    Account& operator=(const Account& other);
    
    int getId() const;
    std::string getName() const;
    double getBalance() const;
    bool withdraw(double amount);
    void deposit(double amount);
    void addHistory(const std::string& record);
    std::vector<std::string> getHistory() const;
};