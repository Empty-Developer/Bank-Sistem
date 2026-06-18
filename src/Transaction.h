#pragma once
#include <string>
#include <chrono>

// Transaction class declaration
class Transaction {
private:
    int fromId_;                                        // source account ID
    int toId_;                                          // destination account ID
    double amount_;                                     // transfer amount
    std::chrono::system_clock::time_point timestamp_;   // when transaction occurred
    bool completed_;                                    // transaction status

public:
    Transaction();
    Transaction(int from, int to, double amount);

    int getFromId() const;
    int getToId() const;
    double getAmount() const;
    std::chrono::system_clock::time_point getTimestamp() const;
    bool isCompleted() const;
    void setCompleted(bool status);
    std::string toString() const;
};