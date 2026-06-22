# Bank System Simulator

Console-based C++ application simulating a multi-threaded banking system with concurrent client operations.

## Requirements

- C++17 compatible compiler
- Thread support (pthread for Linux/Mac, native for Windows)
- CMake 3.10+ (optional)

## Commands

| Command | Description |
|---------|-------------|
| `top N` | Show top N accounts by balance |
| `stats` | Show system statistics |
| `history ID` | Show transaction history for account |
| `balance ID` | Show account balance |
| `deposit ID amount` | Deposit money to account |
| `quit` | Stop system and exit |

## Architecture

The project follows a **modular monolith** design with **4 core modules**:

| Module | Responsibility |
|--------|----------------|
| **Account** | Single account management (balance, history, per-account mutex) |
| **Bank** | Account registry, transfers, statistics, top-N queries |
| **Client** | Thread client performing random operations |
| **Logger** | Thread-safe console/file output |


## Algorithms

| Feature | Implementation | Complexity |
|---------|---------------|------------|
| Top-N Accounts | `std::partial_sort` | O(k log N) |
| Transaction History | `std::deque` with 50 entry limit | O(1) push/pop |
| Account Lookup | `std::unordered_map` | O(1) average |
| History Sorting | `std::sort` by timestamp | O(n log n) |

## Design Patterns

| Pattern | Application |
|---------|-------------|
| **Dependency Injection** | Logger injected into Bank via constructor |
| **Facade** | Bank hides synchronization complexity from Client |
| **RAII** | Automatic mutex management via `lock_guard` / `unique_lock` |
| **Single Responsibility** | Each class has one clear responsibility |
| **Ordered Locking** | Mutexes always acquired in ID order to prevent deadlocks |

## Thread Safety

- **Per-account mutex** - each account has its own mutex
- **Shared mutex** - accounts map with multiple readers, single writer
- **Ordered locking** - always lock smaller ID first (deadlock prevention)
- **Atomic counters** - lock-free statistics increments
- **Atomic stop flag** - safe thread termination


## Example Output

```
[09:39:30] [INFO] Created account #1001 for Alice
[09:39:30] [INFO] Deposited 1000.000000 to account #1001
[09:39:30] [INFO] Created account #1002 for Bob
[09:39:30] [INFO] Deposited 1000.000000 to account #1002

Bank System Started
Active clients: 4
Commands: top N, stats, history ID, balance ID, deposit ID amount, quit

[09:39:30] [INFO] Client started
[09:39:30] [INFO] Transfer 294.045240 from #1001 to #1002
[09:39:30] [INFO] Balance check: account #1002 = 1294.045240
```

