#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                std::cout << " (Completed)";
            }
            std::cout << "\n";
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDesc;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore newline character from previous input
                std::getline(std::cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

