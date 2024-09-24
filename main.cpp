#include <iostream>
#include <string>

// Assigning Attributes
struct Task {
    int id;                     // Task ID
    std::string description;    // Task description
    int priority;               // Task priority
    Task* next;                 // Pointer to the next task
};

// Addition of a new task based on its priority
void addTask(Task*& head, int id, const std::string& description, int priority) {
    Task* newTask = new Task{id, description, priority, nullptr};

    // If list is empty or new task has a higher priority than the head
    if (!head || head->priority < priority) {
        newTask->next = head;
        head = newTask;
    } else {
        Task* current = head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
    std::cout << "Addition Done successfully!\n";
}

// Function to view all tasks
void viewTasks(Task* head) {
    if (!head) {
        std::cout << "Empty\n";
        return;
    }

    std::cout << "List of Tasks:\n";
    Task* current = head;
    while (current) {
        std::cout << "ID: " << current->id
                  << ", Description: " << current->description
                  << ", Priority: " << current->priority << "\n";
        current = current->next;
    }
}

// remove the task with the highest priority
void removeHighestPriorityTask(Task*& head) {
    if (!head) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    Task* temp = head;
    head = head->next;
    std::cout << "Removed task with ID: " << temp->id << "\n";
    delete temp;
}

// remove a task by its ID
void removeTaskById(Task*& head, int id) {
    if (!head) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    if (head->id == id) {
        Task* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Removed task with ID: " << id << "\n";
        return;
    }

    Task* current = head;
    while (current->next && current->next->id != id) {
        current = current->next;
    }

    if (current->next) {
        Task* temp = current->next;
        current->next = current->next->next;
        delete temp;
        std::cout << "Removed task with ID: " << id << "\n";
    } else {
        std::cout << "Task with ID: " << id << " not found.\n";
    }
}

// deletion all tasks
void deleteAllTasks(Task*& head) {
    while (head) {
        Task* temp = head;
        head = head->next;
        delete temp;
    }
}

// Design of task manager System
void showMenu() {
    std::cout << "\n### Task Management System ###\n";
    std::cout << "1. Add task\n";
    std::cout << "2. See all tasks\n";
    std::cout << "3. Delete highest priority task\n";
    std::cout << "4. Delete task by ID\n";
}

int main() {
    Task* head = nullptr;
    int choice, id, priority;
    std::string description;

    while (true) {
        showMenu();
        std::cout << "Enter choice by Number: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Task ID: ";
                std::cin >> id;
                 // Clear the newline character
                std::cin.ignore();
                std::cout << "Enter Task Description: ";
                std::getline(std::cin, description);
                std::cout << "Enter Task Priority: ";
                std::cin >> priority;
                addTask(head, id, description, priority);
                break;

            case 2:
                viewTasks(head);
                break;

            case 3:
                removeHighestPriorityTask(head);
                break;

            case 4:
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                removeTaskById(head, id);
                break;
            // if user enter invalid number
            default:
                std::cout << "Invalid choice. try again.\n";
                break;
        }
    }

    return 0;
}
