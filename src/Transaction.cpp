#include "Transaction.h"
#include <iostream>

// STUB: Transaction implementation with logging only
// No real transaction logic, only console output for demonstration

// constructors
Transaction::Transaction() : fromId_(0), toId_(0), amount_(0.0), completed_(false) {
    timestamp_ = std::chrono::system_clock::now();
    std::cout << "[Transaction] Default constructor" << std::endl;
}

Transaction::Transaction(int from, int to, double amount) 
    : fromId_(from), toId_(to), amount_(amount), completed_(false) {
    timestamp_ = std::chrono::system_clock::now();
    std::cout << "[Transaction] Constructor: from=" << from 
              << ", to=" << to << ", amount=" << amount << std::endl;
}

// getters (stub)
int Transaction::getFromId() const {
    std::cout << "[Transaction] getFromId() -> " << fromId_ << std::endl;
    return fromId_;
}

int Transaction::getToId() const {
    std::cout << "[Transaction] getToId() -> " << toId_ << std::endl;
    return toId_;
}

double Transaction::getAmount() const {
    std::cout << "[Transaction] getAmount() -> " << amount_ << std::endl;
    return amount_;
}

std::chrono::system_clock::time_point Transaction::getTimestamp() const {
    return timestamp_;
}

// status management (stub)
bool Transaction::isCompleted() const {
    std::cout << "[Transaction] isCompleted() -> " << (completed_ ? "true" : "false") << std::endl;
    return completed_;
}

void Transaction::setCompleted(bool status) {
    completed_ = status;
    std::cout << "[Transaction] setCompleted(" << (status ? "true" : "false") << ")" << std::endl;
}

// utility (stub)
std::string Transaction::toString() const {
    std::string result = "Transaction: " + std::to_string(fromId_) + 
                         " -> " + std::to_string(toId_) + 
                         " $" + std::to_string(amount_);
    std::cout << "[Transaction] toString() -> " << result << std::endl;
    return result;
}