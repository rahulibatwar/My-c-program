#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Server ke task ko represent karne ke liye ek Structure banaya
struct ServerTask {
    int priority;
    string taskName;

    // Priority Queue ko yeh batane ke liye ki kaun sa task bada hai, hum '<' operator ko overload karte hain
    bool operator<(const ServerTask& other) const {
        return priority < other.priority; // Jiski priority value zyada, woh queue mein upar aayega
    }
};

int main() {
    cout << "=== ENTERPRISE SERVER TASK SCHEDULER (Priority Queue) ===" << endl;

    // ServerTask store karne ke liye Priority Queue banayi
    priority_queue<ServerTask> taskQueue;

    // 1. Queue mein alag-alag priority ke tasks insert (push) karna
    taskQueue.push({2, "Run Periodic Database Backup"});
    taskQueue.push({5, "CRITICAL: Fix CPU Overheating / Throttle Traffic"});
    taskQueue.push({1, "Generate Weekly Analytics Report"});
    taskQueue.push({4, "Process User Online Payment Requests"});

    cout << "[SYSTEM] " << taskQueue.size() << " tasks successfully queued based on system priority.\n\n";

    // 2. High priority ke hissaab se ek-ek karke tasks process karna
    cout << "Executing Tasks in Order of Highest Priority:\n";
    while (!taskQueue.empty()) {
        // .top() humesha sabse highest priority waala element nikal kar dega
        ServerTask currentTask = taskQueue.top(); 
        
        cout << "  [PROCESSING] Priority Level " << currentTask.priority 
             << " -> Executing: " << currentTask.taskName << "\n";
        
        // Task process hone ke baad use queue se hata (pop) dete hain
        taskQueue.pop(); 
    }

    cout << "---------------------------------------------------------\n";
    cout << "[SUCCESS] All urgent server infrastructure tasks completed safely!\n";

    return 0;
}