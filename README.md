# Graph Algorithms Visualizer

A desktop application built with Qt for visualizing graph algorithms, managing user accounts, and interacting with graph structures in real-time.

![Demo Preview](![alt text](image.png))  
_Replace this placeholder with an actual screenshot of your application._

---

## Features

### **Graph Operations**

- Add/delete nodes (cities) and edges with weights
- Visualize graph traversal (DFS, BFS) with step-by-step color highlighting
- Compute shortest paths using **Dijkstra's algorithm** and **Floyd-Warshall algorithm**
- Display results in tables (Floyd-Warshall matrix) and path sequences
- Interactive node dragging with real-time edge updates

### **User Management**

- Secure registration/login system with input validation
- Persistent JSON storage for:
  - User credentials
  - Graph states
  - Algorithm results
- Session management with logout/exit functionality

### **UI/UX**

- Responsive full-screen mode (press `ESC` to exit)
- Clear error messages for invalid inputs (red-bordered fields)
- Color-coded node highlighting during algorithm execution
- Scrollable table view for large datasets (Floyd-Warshall)
- Clean input field reset after operations
