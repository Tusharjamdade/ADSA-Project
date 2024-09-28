# Music Player in C++

## Overview

This Music Player application is a console-based program developed in C++ that allows users to manage a playlist of songs. The application utilizes various data structures, including **stack**, **graph**, **queue**, and **tree**, to provide efficient operations for adding, deleting, searching, and playing songs. Additionally, it supports song recommendations based on a graph structure.

## Features

- **Add Songs**: Add new songs to the playlist.
- **Delete Songs**: Remove songs from the playlist either by name or position.
- **Display Playlist**: View the current playlist of songs.
- **Count Songs**: Get the total number of songs in the playlist.
- **Search for Songs**: Find a specific song in the playlist.
- **Play Songs**: Play a song and maintain a history of recently played songs using a stack.
- **Sort Songs**: View songs in sorted order using a binary search tree.
- **Recommend Songs**: Get song recommendations based on connected songs in a graph.
- **Load Playlist from File**: Import a playlist from a text file.

## Data Structures Used

1. **Linked List**: Used for managing the playlist.
2. **Binary Search Tree (BST)**: Used to store songs in sorted order and allow efficient searching.
3. **Graph**: Used to represent connections between songs for recommendations.
4. **Stack**: Used to keep track of recently played songs.
5. **Queue**: (Optional) Can be implemented for managing songs in a play queue.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Basic knowledge of C++ programming and data structures

### Installation

1. Clone the repository or download the source code.
   ```bash
   git clone https://github.com/yourusername/music-player-cpp.git
   cd music-player-cpp
