# SY Semester 3 Practicals

A comprehensive collection of practical programs for Second Year (3rd Semester) covering **Data Structures & Algorithms (DSA)**, **Object-Oriented Programming (OOP)** & **Mathematical Foundation for GenAI (MFG)**.

## 📚 Course Contents

### 🔗 Data Structures & Algorithms (DSA)

| Program | Description |
|---------|-------------|
| `dsa_1_rainfall.cpp` | Track and analyze rainfall data for multiple cities using 2D arrays |
| `dsa_1_temperature.cpp` | Temperature data tracking and analysis |
| `dsa_2_bubble_sort.cpp` | Interactive game-based implementation of Bubble Sort algorithm |
| `dsa_2_insertion_sort.cpp` | Insertion Sort algorithm implementation |
| `dsa_3_linear_probing.cpp` | Hash table implementation using Linear Probing collision resolution |
| `dsa_4_linked_list.cpp` | Singly Linked List operations (insert, delete, display, search) |
| `dsa_5_inf_to_post.cpp` | Infix to Postfix expression conversion with evaluation |
| `dsa_5_parenthesis.cpp` | Parenthesis matching using Stack |
| `dsa_6_circ_queue.cpp` | Circular Queue implementation |
| `dsa_6_coffee_queue.cpp` | Coffee shop queue simulation using Queue data structure |
| `dsa_7_bfs.cpp` | Breadth-First Search (BFS) graph traversal algorithm |
| `dsa_7_dfs.cpp` | Depth-First Search (DFS) graph traversal algorithm |
| `detect_remove_loop.cpp` | Detect and remove loops in a linked list (Floyd's Cycle Detection) |
| `minstack_getmin.cpp` | Special stack implementation with getMin() operation in O(1) time |
| `dsa_mini_project.cpp` | **Mini Project**: Smart Multi-Elevator Scheduling System with SSTF algorithm and animated visualization |

**Key Concepts Covered:**
- Arrays and 2D Arrays
- Sorting Algorithms (Bubble Sort, Insertion Sort)
- Hashing Techniques
- Linked Lists (Custom Implementation)
- Stack Applications
- Queue Implementations (Custom Queue using Linked List)
- Graph Traversal Algorithms
- Advanced Data Structure Problems
- Real-world Application: Elevator Scheduling (SSTF Algorithm)

---

### 💻 Object-Oriented Programming (OOP)

| Program | Description |
|---------|-------------|
| `oop_1_bank.cpp` | Bank Account Management System (deposit, withdraw, account details) |
| `oop_2_employee.cpp` | Employee database management with classes and objects |
| `oop_3_institution.cpp` | Educational institution management system |
| `oop_4_complex.cpp` | Complex number operations using operator overloading |
| `oop_5_shapes.cpp` | Polymorphism demonstration with abstract Shape class (Triangle, Rectangle, Circle) |
| `oop_6_exception.cpp` | Exception handling mechanisms in C++ |
| `oop_7_file_op.cpp` | File input/output operations |
| `oop_8_template.cpp` | Generic programming using Templates |
| `oop_9_stl.cpp` | Standard Template Library (STL) containers and algorithms |
| `oop_mini_project.cpp` | **Mini Project**: Student Result Management System with CSV parsing, file I/O, and Map-based search |

**Key Concepts Covered:**
- Classes and Objects
- Encapsulation and Data Abstraction
- Inheritance and Polymorphism
- Virtual Functions and Abstract Classes
- Operator Overloading
- Exception Handling
- File Handling (Read/Write/Append modes)
- Templates (Function and Class Templates)
- STL Components (Vectors, Maps, Sets, Algorithms)
- Real-world Application: Student Result Management with CSV integration

---

### 📊 Mathematical Foundation for GenAI (MFG)

| Program | Description |
|---------|-------------|
| `mfg_1_set_operations.cpp` | Set operations (Union, Intersection, Difference) - Student club membership analysis |
| `mfg_2_inclusion_exclusion.cpp` | Inclusion-Exclusion Principle application |
| `mfg_3_permutations.cpp` | Generate and compute permutations |
| `mfg_4_combinations.cpp` | Generate and compute combinations |
| `mfg_5_warshall.cpp` | Warshall's Algorithm for finding shortest paths (All-Pairs Shortest Path) |
| `mfg_6_central.cpp` | Central measures and graph theory applications |
| `mfg_7_dispersion.cpp` | Statistical measures of dispersion (Range, Variance, Standard Deviation) |
| `mfg_8_hypothesis.cpp` | Hypothesis testing - Z-test for population mean with significance level |

**Key Concepts Covered:**
- Set Theory and Operations
- Combinatorics (Permutations & Combinations)
- Graph Theory
- Shortest Path Algorithms
- Statistical Analysis (Dispersion Measures)
- Hypothesis Testing and Statistical Inference
- Mathematical Problem Solving
- Discrete Mathematics Applications

---

## 🌟 Featured Mini Projects

The repository includes two comprehensive mini projects that demonstrate real-world applications:

### 🏢 **DSA Mini Project: Smart Multi-Elevator Scheduling System**
**File:** `dsa_mini_project.cpp`

**Features:**
- Custom Queue implementation using Linked List (no STL)
- SSTF (Shortest Seek Time First) scheduling algorithm
- 4 elevators managing 20 floors
- Real-time animated visualization of elevator movement
- Priority-based elevator selection system
- Comprehensive statistics tracking (distance, requests, efficiency)
- Interactive menu with multiple simulation modes

**Concepts Demonstrated:**
- Template-based custom data structures
- Queue operations with linked lists
- Algorithm optimization (scheduling)
- System simulation and animation
- Multi-object coordination

---

### 📚 **OOP Mini Project: Student Result Management System**
**File:** `oop_mini_project.cpp`

**Features:**
- Complete inheritance hierarchy (Person → Student)
- CSV file parsing for classmate data import
- Map-based fast PRN search (O(log n))
- File I/O with append mode (data preservation)
- Automatic percentage and grade calculation
- JSON export for web integration
- Report card generation and storage

**Concepts Demonstrated:**
- Inheritance and Polymorphism
- File Handling (Text files & CSV)
- STL Map for efficient searching
- Encapsulation and data abstraction
- Real-world database operations
- Data format conversion (JSON)

---

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (GCC, MinGW, or any standard C++ compiler)
- Basic understanding of C++ programming
- Code editor or IDE (VS Code, Code::Blocks, Dev C++, etc.)

### Compilation and Execution

**Using g++ compiler:**
```bash
# Compile a program
g++ program_name.cpp -o output_name

# Run the compiled program
./output_name
```

**Example:**
```bash
g++ dsa_2_bubble_sort.cpp -o bubble_sort
./bubble_sort
```

**For Windows (MinGW):**
```bash
g++ program_name.cpp -o output_name.exe
output_name.exe
```

---

## 📁 Project Structure

```
SY_Sem_3_Practicals-main/
│
├── DSA/                    # Data Structures and Algorithms
│   ├── dsa_1_rainfall.cpp
│   ├── dsa_2_bubble_sort.cpp
│   ├── dsa_3_linear_probing.cpp
│   ├── dsa_4_linked_list.cpp
│   ├── dsa_5_inf_to_post.cpp
│   ├── dsa_6_circ_queue.cpp
│   ├── dsa_7_bfs.cpp
│   └── ... (more DSA programs)
│
├── OOP/                    # Object-Oriented Programming
│   ├── oop_1_bank.cpp
│   ├── oop_2_employee.cpp
│   ├── oop_4_complex.cpp
│   ├── oop_5_shapes.cpp
│   └── ... (more OOP programs)
│
├── MFG/                    # Mathematics for Graphing
│   ├── mfg_1_set_operations.cpp
│   ├── mfg_3_permutations.cpp
│   ├── mfg_5_warshall.cpp
│   └── ... (more MFG programs)
│
└── README.md
```

---

## 🎯 Learning Outcomes

After completing these practicals, students will be able to:

1. **Implement and analyze** fundamental data structures (Arrays, Linked Lists, Stacks, Queues, Graphs)
2. **Apply** various sorting and searching algorithms
3. **Design** object-oriented solutions using C++ features
4. **Utilize** polymorphism, inheritance, and encapsulation effectively
5. **Solve** mathematical and combinatorial problems programmatically
6. **Work** with file I/O, CSV parsing, and exception handling
7. **Understand** graph algorithms and their applications
8. **Use** STL containers and generic programming
9. **Build** real-world applications combining multiple concepts
10. **Implement** custom data structures without relying on STL
11. **Develop** scheduling algorithms and system simulations
12. **Create** database-like systems with efficient search mechanisms

---

## 💡 Tips for Students

- **Understand Before You Code**: Read through the problem statement carefully
- **Start Simple**: Begin with basic programs and gradually move to complex ones
- **Test Thoroughly**: Try different inputs to verify your program works correctly
- **Comment Your Code**: Add meaningful comments for better understanding
- **Debug Systematically**: Use print statements or debuggers to trace issues
- **Practice Regularly**: Consistent practice is key to mastering programming

---

## 🤝 Contributing

If you find any bugs, errors, or have suggestions for improvement:
1. Fork the repository
2. Create a new branch for your changes
3. Submit a pull request with a clear description

---

## 📝 License

This project is created for educational purposes. Feel free to use and modify the code for learning.

---

## 👨‍💻 Author

**Second Year Engineering Students**  
Semester 3 Practical Programs Collection

---

## 📞 Support

For queries or discussions:
- Review the code comments within each program
- Refer to your course material and textbooks
- Discuss with classmates & instructors

---

**Happy Coding! 🚀**

*Remember: The best way to learn programming is by writing code yourself. Use these programs as reference, but try to solve problems independently first.*
