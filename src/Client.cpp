#include "Bank.cpp"
#include "Logger.h"

#include <iostream>
#include <vector>
#include <string>
#include <atomic>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

class ClientModule {
  public:
    int clientId;
    Bank& bank;
    Logger& logger;
    atomic<bool>& stopFlag;

    ClientModule(int id, Bank& b, Logger& l, atomic<bool>& stop)
        : clientId(id), bank(b), logger(l), stopFlag(stop) {}

    void run() {
        srand(clientId); // Each client has its own seed in the mine
        logger.log("INFORMATION", "Client #" + to_string(clientId) + " He's already here.");

        while (!stopFlag) {
            vector<int> ids = bank.getAccountIds();

            // transfer (minimum 2 accounts)
            if (ids.size() < 2) {
                this_thread::sleep_for(chrono::milliseconds(50));
                continue;
            }

            // select a random sender and recipient
            int from = ids[rand() % ids.size()];
            int to   = ids[rand() % ids.size()];
            if (from == to) continue;

            
            double amount = rand() % 500 + 1;

            bool ok = bank.transfer(from, to, amount);

            // log
            string result = ok ? " sent " : " failed ";
            logger.log(ok ? "INFO" : "WARN",
                "Client #" + to_string(clientId) +
                result + to_string((int)amount) +
                " from " + to_string(from) +
                " to " + to_string(to));
            this_thread::sleep_for(chrono::milliseconds(1000));  // one second delay
        }

        logger.log("INFORMATION", "Client #" + to_string(clientId) + " he's gone");
    }
};