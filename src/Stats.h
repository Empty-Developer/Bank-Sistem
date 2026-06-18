#pragma once

// Stats class declaration
class Stats {
private:
    int totalBalance_;      // sum of all account balances
    int successCount_;      // number of successful transfers
    int failedCount_;       // number of failed transfers
    int activeThreads_;     // currently active client threads

public:
    Stats();
    Stats(int totalBalance, int successCount, int failedCount, int activeThreads);
    
    int getTotalBalance() const;
    int getSuccessCount() const;
    int getFailedCount() const;
    int getActiveThreads() const;
};