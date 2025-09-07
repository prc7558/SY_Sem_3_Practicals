#include<iostream>
using namespace std;

//~~~CLASS for nodes of LINKED LISTS~~~
class task {
public:
    int prio, time, num;
    task *next;

    task(int p, int e, int n) {
        prio = p;
        time = e;
        num = n;
        next = NULL;
    } 
};

//~~~DEFINE 2 global HEADS~~~
task *headPrio=NULL, *headExec=NULL;

//~~~DISPLAY LINKED LIST by PRIORITY~~~
void displayTasksPrio() {
    cout << "\n---Scheduled Tasks (Highest Priority First)---";
    for (task* temp=headPrio; temp!=NULL; temp=temp->next) {
        cout << "\nTask: T" << temp->num; 
        cout << " |  Priority: " << temp->prio;
        cout << " | Execution Time: " << temp->time << " ms";
    }
}

//~~~DISPLAY by EXECUTION TIME~~~
void displayTasksExec() {
    cout << "\n\n-Executing Tasks (Lowest Execution Time First)-";
    for (task* temp=headExec; temp!=NULL; temp=temp->next) {
        cout << "\nTask: T" << temp->num; 
        cout << " |  Priority: " << temp->prio;
        cout << " | Execution Time: " << temp->time << " ms";
    }
    cout << "\n\n All tasks executed!!";
}

//~~~INSERT in LINKED LIST by PRIORITY~~~
void insertByPriority(task* newnode) {
    if (headPrio==NULL || newnode->prio > headPrio->prio) {
        newnode->next = headPrio;
        headPrio = newnode;
    } else {
        task* temp=headPrio;
        while (temp->next!=NULL && temp->next->prio >= newnode->prio)
            temp=temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

//~~~INSERT by EXECUTION TIME~~~
void insertByExecTime(task* newnode) {
    if (headExec==NULL || newnode->time < headExec->time) {
        newnode->next = headExec;
        headExec = newnode;
    } else {
        task* temp=headExec;
        while (temp->next!=NULL && temp->next->time <= newnode->time)
            temp=temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

//~~~CALL 2 INSERT TASKS~~~ 
void insertTask(int p, int e, int n) {
    task* node1 = new task(p, e, n);
    task* node2 = new task(p, e, n);

    insertByPriority(node1);
    insertByExecTime(node2);
}

//~~~INPUT NODES of LINKED LISTS~~~
int main() {
    int i=0, p, e, n;
    cout << "Enter number of tasks to schedule: ";
    cin >> n;
    
    while (i<n) {
        cout << "\n Priority (higher=important) for Task T" << i+1 << ": ";
        cin >> p;
        cout << " Enter Execution Time (ms) for Task T" << i+1 << ": ";
        cin >> e;
        insertTask(p, e, ++i);
    }

    displayTasksPrio();
    displayTasksExec();
    
    return 0;
}
